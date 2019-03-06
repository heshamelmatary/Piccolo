// Copyright (c) 2016-2019 Bluespec, Inc. All Rights Reserved

package CPU;

// ================================================================
// This is the "Piccolo_V3" CPU, implementing the RISC-V ISA.
// - RV32/64, ACDFIMSU, 3-stage in order pipeline
// - Optional Debug Module connection
// - Optional Tandem Verification connection.

`ifdef EXTERNAL_DEBUG_MODULE
`undef INCLUDE_GDB_CONTROL
`endif

// ================================================================
// Exports

export mkCPU;

// ================================================================
// BSV library imports

import Memory       :: *;
import FIFOF        :: *;
import SpecialFIFOs :: *;
import GetPut       :: *;
import ClientServer :: *;
import Connectable  :: *;
import ConfigReg    :: *;

// ----------------
// BSV additional libs

import GetPut_Aux :: *;
import Semi_FIFOF :: *;

// ================================================================
// Project imports

import AXI4 :: *;

import ISA_Decls :: *;

import TV_Info   :: *;

import GPR_RegFile :: *;
`ifdef ISA_F
import FPR_RegFile :: *;
`endif
import CSR_RegFile :: *;
import CPU_Globals :: *;
import CPU_IFC     :: *;

`ifdef ISA_C
// 'C' extension (16b compressed instructions)
import CPU_Fetch_C  :: *;
`endif

import CPU_Stage1 :: *;    // Fetch and Execute
import CPU_Stage2 :: *;    // Memory and long-latency ops
import CPU_Stage3 :: *;    // Writeback

import Near_Mem_IFC :: *;    // Caches or TCM

`ifdef Near_Mem_Caches
import Near_Mem_Caches :: *;
`endif

`ifdef Near_Mem_TCM
import Near_Mem_TCM :: *;
`endif

`ifdef INCLUDE_GDB_CONTROL
import Debug_Module :: *;
`endif

// System address map and pc_reset value
import SoC_Map :: *;

// ================================================================
// Major States of CPU

typedef enum {CPU_RESET1,
	      CPU_RESET2,

`ifdef INCLUDE_GDB_CONTROL
	      CPU_GDB_PAUSING,      // On GDB breakpoint, while waiting for fence completion
	      CPU_DEBUG_MODE,       // Stopped for debugger
`endif
	      CPU_RUNNING,          // Normal operation
	      CPU_TRAP,
	      CPU_CSRRX_RESTART,    // Restart pipe after a CSRRX instruction
	      CPU_FENCE_I,          // While waiting for FENCE.I to complete in Near_Mem
	      CPU_FENCE,            // While waiting for FENCE to complete in Near_Mem
	      CPU_SFENCE_VMA,       // While waiting for FENCE.VMA to complete in Near_Mem

	      CPU_WFI_PAUSED        // On WFI pause
   } CPU_State
deriving (Eq, Bits, FShow);

function Bool fn_is_running (CPU_State  cpu_state);
   return (   (cpu_state != CPU_RESET1)
	   && (cpu_state != CPU_RESET2)
`ifdef INCLUDE_GDB_CONTROL
	   && (cpu_state != CPU_GDB_PAUSING)
	   && (cpu_state != CPU_DEBUG_MODE)
`endif
	   );
endfunction

// ================================================================

(* synthesize *)
module mkCPU (CPU_IFC);

   // ----------------
   // System address map and pc reset value
   SoC_Map_IFC  soc_map  <- mkSoC_Map;

   // ----------------
   // General purpose registers and CSRs
   GPR_RegFile_IFC  gpr_regfile  <- mkGPR_RegFile;
`ifdef ISA_F
   FPR_RegFile_IFC  fpr_regfile  <- mkFPR_RegFile;
`endif

   CSR_RegFile_IFC  csr_regfile  <- mkCSR_RegFile;
   let mcycle   = csr_regfile.read_csr_mcycle;
   let mstatus  = csr_regfile.read_mstatus;
   let misa     = csr_regfile.read_misa;
   let minstret = csr_regfile.read_csr_minstret;

   // Near mem (caches or TCM, for example)
   Near_Mem_IFC  near_mem <- mkNear_Mem;

   // Take imem as is from near_mem, or use wrapper for 'C' extension
`ifdef ISA_C
   IMem_IFC imem <- mkCPU_Fetch_C (near_mem.imem);
`else
   IMem_IFC imem = near_mem.imem;
`endif

   // ----------------
   // For debugging

   // Verbosity: 0=quiet; 1=instruction trace; 2=more detail
   Reg #(Bit #(4))  cfg_verbosity <- mkConfigReg (0);

   // Verbosity is 0 as long as # of instrs retired is <= cfg_logdelay
   Reg #(Bit #(64))  cfg_logdelay <- mkConfigReg (0);

   // Current verbosity, taking into account log delay
   Bit #(4)  cur_verbosity = ((minstret < cfg_logdelay) ? 0 : cfg_verbosity);

   // ----------------
   // Major CPU states
   Reg #(CPU_State)  rg_state    <- mkReg (CPU_RESET1);
   Reg #(Priv_Mode)  rg_cur_priv <- mkReg (m_Priv_Mode);

   // Save next_pc across split-phase FENCE.I and other split-phase ops
   Reg #(WordXL) rg_next_pc <- mkRegU;

   // ----------------
   // Pipeline stages

   CPU_Stage3_IFC stage3 <- mkCPU_Stage3 (cur_verbosity,
					  gpr_regfile,
`ifdef ISA_F
					  fpr_regfile,
`endif
					  csr_regfile);

   CPU_Stage2_IFC stage2 <- mkCPU_Stage2 (cur_verbosity, csr_regfile, near_mem.dmem);

   CPU_Stage1_IFC  stage1 <- mkCPU_Stage1 (cur_verbosity,
					   gpr_regfile,
					   stage2.out.bypass,
					   stage3.out.bypass,
`ifdef ISA_F
					   fpr_regfile,
					   stage2.out.fbypass,
					   stage3.out.fbypass,
`endif
					   csr_regfile,
					   imem,
					   rg_cur_priv);

   // ----------------
   // Halt requests (interrupts, debugger stop-request, or dcsr.step step-request).
   // We set this flag on an instruction Fetch and handle it on the next instruction-fetch.
   // When this flag is set, Stage1 is "frozen", i.e., its instruction
   // is not moved forward.  Once Stage2 and Stage3 have drained
   // (OSTATUS_EMPTY), the halt-request is handled.

   Reg #(Bool)  rg_halt <- mkReg (False);

   // Interrupt pending based on current priv, mstatus.ie, mie and mip registers
   Bool interrupt_pending = isValid (csr_regfile.interrupt_pending (rg_cur_priv));

   // ----------------
   // Reset requests and responses

   FIFOF #(Token)  f_reset_reqs <- mkFIFOF;
   FIFOF #(Token)  f_reset_rsps <- mkFIFOF;

   // ----------------
   // Communication to/from External debug module

`ifdef INCLUDE_GDB_CONTROL

   // Debugger run-control
   FIFOF #(Bool)  f_run_halt_reqs <- mkFIFOF;
   FIFOF #(Bool)  f_run_halt_rsps <- mkFIFOF;

   Reg #(Bool)  rg_stop_req      <- mkReg (False);    // stop-request from debugger
   Reg #(Bool)  rg_step_req      <- mkReg (False);    // step-request from dcsr.step

   // Debugger GPR read/write request/response
   FIFOF #(MemoryRequest  #(5,  XLEN)) f_gpr_reqs <- mkFIFOF1;
   FIFOF #(MemoryResponse #(    XLEN)) f_gpr_rsps <- mkFIFOF1;

`ifdef ISA_F
   // Debugger FPR read/write request/response
   FIFOF #(MemoryRequest  #(5,  FLEN)) f_fpr_reqs <- mkFIFOF1;
   FIFOF #(MemoryResponse #(    FLEN)) f_fpr_rsps <- mkFIFOF1;
`endif

   // Debugger CSR read/write request/response
   FIFOF #(MemoryRequest  #(12, XLEN)) f_csr_reqs <- mkFIFOF1;
   FIFOF #(MemoryResponse #(    XLEN)) f_csr_rsps <- mkFIFOF1;

`endif

   // ----------------
   // Tandem Verification

`ifdef INCLUDE_TANDEM_VERIF
   FIFOF #(Trace_Data) f_trace_data  <- mkFIFOF;

   // State for deciding if a MIP update needs to be sent into the trace file
   Reg #(WordXL) rg_prev_mip <- mkReg (0);
`endif

   function Bool mip_cmd_needed ();
`ifdef INCLUDE_TANDEM_VERIF
      // If the MTIP, MSIP, or xEIP bits of MIP have changed, then send a MIP update
      WordXL new_mip = csr_regfile.csr_mip_read;
      Bool mip_has_changed = (new_mip != rg_prev_mip);
      return mip_has_changed;
`else
      return False;
`endif
   endfunction: mip_cmd_needed

   // ================================================================
   // Debugging: print instruction trace info

   function fa_emit_instr_trace (instret, pc, instr, priv);
      action
	 if (cur_verbosity == 1)
	    $display ("instret:%0d  PC:0x%0h  instr:0x%0h  priv:%0d", instret, pc, instr, priv);
      endaction
   endfunction

   // ================================================================
   // CPI measurement in each 'run' (from Debug Mode pause to Debug Mode pause)

   Reg #(Bit #(64))  rg_start_CPI_cycles <- mkRegU;
   Reg #(Bit #(64))  rg_start_CPI_instrs <- mkRegU;

   function Action fa_report_CPI;
      action
	 Bit #(64) delta_CPI_cycles = mcycle - rg_start_CPI_cycles;
	 Bit #(64) delta_CPI_instrs = minstret - rg_start_CPI_instrs;

	 // Make delta_CPI_instrs at least 1, to avoid divide-by-zero
	 if (delta_CPI_instrs == 0)
	    delta_CPI_instrs = delta_CPI_instrs + 1;

	 // Report CPI to 1 decimal place.
	 let x = (delta_CPI_cycles * 10) / delta_CPI_instrs;
	 let cpi     = x / 10;
	 let cpifrac = x % 10;
	 $display ("CPI: %0d.%0d = (%0d/%0d) since last 'continue'",
		   cpi, cpifrac, delta_CPI_cycles, delta_CPI_instrs);
      endaction
   endfunction

   // ================================================================
   // Feed a new PC into IMem (instruction fetch).
   // Set rg_halt on debugger stop request or dcsr.step step request

   function Action fa_start_ifetch (Word next_pc, Priv_Mode priv);
      action
	 // Initiate the fetch
`ifdef ISA_PRIV_S
	 Bit #(1) sstatus_SUM = (csr_regfile.read_sstatus) [18];
`else
	 Bit #(1) sstatus_SUM = 0;
`endif
	 Bit #(1) mstatus_MXR = mstatus [19];
	 stage1.enq (next_pc,
		     priv,
		     sstatus_SUM,
		     mstatus_MXR,
		     csr_regfile.read_satp);

	 // Set rg_halt if requested by GDB (stop req, step req)
	 Bool do_halt = False;

`ifdef INCLUDE_GDB_CONTROL
	 // Debugger stop-request
	 if ((! do_halt) && rg_stop_req && (cur_verbosity != 0))
	    $display ("    CPU.fa_start_ifetch: halting due to stop_req: PC = 0x%08h", next_pc);

	 do_halt = (do_halt || rg_stop_req);

	 // dcsr.step step-request
	 if ((! do_halt) && rg_step_req && (cur_verbosity != 0))
	    $display (" CPU.fa_start_ifetch: halting due to step req: PC = 0x%08h",
		      next_pc);
	 do_halt = (do_halt || rg_step_req);

	 // If not halting now, and dcsr.step=1, set rg_step_req to cause a stop at next fetch
	 if ((! do_halt) && (csr_regfile.read_dcsr_step)) begin
	    rg_step_req <= True;
	    if (cur_verbosity != 0)
	       $display ("    CPU.fa_start_ifetch: dcsr.step=1; will stop at next fetch");
	 end
`endif

	 if (do_halt) begin
	    rg_halt <= True;
	    if (cur_verbosity > 1)
	       $display ("    CPU.fa_start_ifetch: rg_halt <= True");
	 end
      endaction
   endfunction

   // ================================================================
   // Actions to restart from Debug Mode (e.g., GDB 'continue' after a breakpoint)
   // We re-initialize CPI_instrs and CPI_cycles.

   function Action fa_restart (Addr resume_pc);
      action
	 fa_start_ifetch (resume_pc, rg_cur_priv);
	 stage1.set_full (True);
	 rg_state <= CPU_RUNNING;

`ifdef INCLUDE_GDB_CONTROL
	 // Notify debugger that we've started running
	 f_run_halt_rsps.enq (True);
`endif

	 rg_start_CPI_cycles <= mcycle;
	 rg_start_CPI_instrs <= minstret;

	 if (cur_verbosity != 0)
	    $display ("    fa_restart: RUNNING with PC = 0x%0h", resume_pc);
      endaction
   endfunction

   // ================================================================
   // Debug tracing: show pipe state

   (* no_implicit_conditions, fire_when_enabled *)
   rule rl_show_pipe (   (cur_verbosity > 1)
		      && fn_is_running (rg_state)
		      && (rg_state != CPU_WFI_PAUSED));
      $display ("================================================================");
      $display ("%0d: Pipeline State:  minstret:%0d  cur_priv:%0d  mstatus:%0x",
		mcycle, minstret, rg_cur_priv, mstatus);
      $display ("    ", fshow_mstatus (misa, mstatus));

      $display ("    Stage3: ", fshow (stage3.out));
      $display ("        Bypass  to Stage1: ", fshow (stage3.out.bypass));
`ifdef ISA_F
      $display ("        FBypass to Stage1: ", fshow (stage3.out.fbypass));
`endif
      $display ("    Stage2: pc 0x%08h instr 0x%08h priv %0d",
		stage2.out.data_to_stage3.pc,
		stage2.out.data_to_stage3.instr,
		stage2.out.data_to_stage3.priv);
      $display ("        ", fshow (stage2.out));
      $display ("        Bypass  to Stage1: ", fshow (stage2.out.bypass));
`ifdef ISA_F
      $display ("        FBypass to Stage1: ", fshow (stage2.out.fbypass));
`endif

      $display ("    Stage1: pc 0x%08h instr 0x%08h priv %0d",
		stage1.out.data_to_stage2.pc,
		stage1.out.data_to_stage2.instr,
		stage1.out.data_to_stage2.priv);
      $display ("        ", fshow (stage1.out));
      $display ("----------------");
   endrule

   // ================================================================
   // Reset

   rule rl_reset_start (rg_state == CPU_RESET1);
      let req <- pop (f_reset_reqs);

      $display ("================================================================");
      $write   ("CPU: Bluespec  RISC-V  Piccolo  v3.0");
      if (rv_version == RV32)
	 $display (" (RV32)");
      else
	 $display (" (RV64)");
      $display ("Copyright (c) 2016-2019 Bluespec, Inc. All Rights Reserved.");
      $display ("================================================================");

      gpr_regfile.server_reset.request.put (?);
`ifdef ISA_F
      fpr_regfile.server_reset.request.put (?);
`endif
      csr_regfile.server_reset.request.put (?);
      near_mem.server_reset.request.put (?);

      stage1.server_reset.request.put (?);
      stage2.server_reset.request.put (?);
      stage3.server_reset.request.put (?);

      rg_cur_priv <= m_Priv_Mode;
      rg_halt     <= False;
      rg_state    <= CPU_RESET2;

      if (cur_verbosity != 0)
	 $display ("%0d: CPU.rl_reset_start", mcycle);

`ifdef INCLUDE_GDB_CONTROL
      rg_stop_req <= False;
      rg_step_req <= False;
`endif

`ifdef INCLUDE_TANDEM_VERIF
      let trace_data = mkTrace_RESET;
      f_trace_data.enq (trace_data);

      rg_prev_mip <= 0;
`endif
   endrule: rl_reset_start

   // ----------------

   rule rl_reset_complete (rg_state == CPU_RESET2);
      let ack_gpr <- gpr_regfile.server_reset.response.get;
`ifdef ISA_F
      let ack_fpr <- fpr_regfile.server_reset.response.get;
`endif
      let ack_csr <- csr_regfile.server_reset.response.get;
      let ack_nm  <- near_mem.server_reset.response.get;

      let ack1 <- stage1.server_reset.response.get;
      let ack2 <- stage2.server_reset.response.get;
      let ack3 <- stage3.server_reset.response.get;

      f_reset_rsps.enq (?);

      if (cur_verbosity != 0)
	 $display ("%0d: CPU.reset_complete", mcycle);

`ifdef INCLUDE_GDB_CONTROL
      csr_regfile.write_dcsr_cause_priv (DCSR_CAUSE_HALTREQ, m_Priv_Mode);
      rg_state <= CPU_DEBUG_MODE;

      if (cur_verbosity != 0)
	 $display ("    CPU entering DEBUG_MODE");
`else
      WordXL dpc = truncate (soc_map.m_pc_reset_value);
      fa_restart (dpc);
`endif
   endrule: rl_reset_complete

   // ================================================================
   // Various conditions on the pipe

   Bool pipe_is_empty = (   (stage3.out.ostatus == OSTATUS_EMPTY)
			 && (stage2.out.ostatus == OSTATUS_EMPTY)
			 && (stage1.out.ostatus == OSTATUS_EMPTY));

   // The pipe is ready to execute a non-pipe if any stage has NONPIPE
   // and all stages downstream of that stage are EMPTY
   Bool pipe_has_nonpipe = (   (stage3.out.ostatus == OSTATUS_NONPIPE)
			    || (   (stage3.out.ostatus == OSTATUS_EMPTY)
				&& (stage2.out.ostatus == OSTATUS_NONPIPE))
			    || (   (stage3.out.ostatus == OSTATUS_EMPTY)
				&& (stage2.out.ostatus == OSTATUS_EMPTY)
				&& (stage1.out.ostatus == OSTATUS_NONPIPE)));

   Bool halting = (rg_halt || mip_cmd_needed || interrupt_pending);
   Bool stage1_halted = (   halting
			 && (   (stage1.out.ostatus == OSTATUS_PIPE)
			     || (stage1.out.ostatus == OSTATUS_NONPIPE))
			 && (stage2.out.ostatus == OSTATUS_EMPTY)
			 && (stage3.out.ostatus == OSTATUS_EMPTY));
   Bool stage1_send_mip_cmd = stage1_halted && mip_cmd_needed;
   Bool stage1_take_interrupt = stage1_halted && (! mip_cmd_needed) && interrupt_pending;
   Bool stage1_stop = stage1_halted && (! mip_cmd_needed) && (! interrupt_pending);

   // ================================================================

`ifdef INCLUDE_TANDEM_VERIF
   rule rl_stage1_mip_cmd (   (rg_state == CPU_RUNNING)
			   && stage1_send_mip_cmd);
      WordXL new_mip = csr_regfile.csr_mip_read;
      rg_prev_mip <= new_mip;

      let trace_data = mkTrace_CSR_WRITE (csr_addr_mip, new_mip);
      f_trace_data.enq (trace_data);

      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_stage1_mip_cmd: MIP new 0x%0h, old 0x%0h", mcycle, new_mip, rg_prev_mip);
   endrule
`endif

   // ================================================================
   // PIPELINE BEHAVIOR (excluding nonpipe special instructions and exceptions)

   // We do not attempt to manage CSR values in the pipeline like GPRs
   // (read reg, writeback, bypassing) because of complexity: too many
   // CSRs can change simultaneously.  A CSRRx instruction in stage1
   // is stalled until downstream stages are empty. Then, we delay for
   // a cycle before restarting the pipe by re-fetching the next
   // instr, since the fetch may need the just-written CSR value.

`ifdef ISA_C
   // TODO: analyze this carefully; added to resolve a blockage
   (* descending_urgency = "imem_rl_fetch_next_32b, rl_pipe" *)
`endif

   rule rl_pipe (   (rg_state == CPU_RUNNING)
		 && (! pipe_is_empty)
		 && (! pipe_has_nonpipe)
		 && (! stage1_halted));

      if (cur_verbosity > 1) $display ("%0d: CPU.rl_pipe", mcycle);

      Bool stage3_full = (stage3.out.ostatus != OSTATUS_EMPTY);
      Bool stage2_full = (stage2.out.ostatus != OSTATUS_EMPTY);
      Bool stage1_full = (stage1.out.ostatus != OSTATUS_EMPTY);

      // ----------------
      // Stage3 sink (does regfile writebacks)

      if (stage3.out.ostatus == OSTATUS_PIPE) begin
	 stage3.deq; stage3_full = False;
      end

      // ----------------
      // Move instruction from Stage2 to Stage3

      if ((! stage3_full) && (stage2.out.ostatus == OSTATUS_PIPE)) begin
	 stage2.deq;                              stage2_full = False;
	 stage3.enq (stage2.out.data_to_stage3);  stage3_full = True;

`ifdef INCLUDE_TANDEM_VERIF
	 // To Verifier
	 let trace_data = stage2.out.trace_data;
	 f_trace_data.enq (trace_data);
`endif

	 // Increment csr_INSTRET.
	 // Note: this instr cannot be a CSRRx updating INSTRET, since
	 // CSRRx is done off-pipe
	 csr_regfile.csr_minstret_incr;
	 fa_emit_instr_trace (minstret, stage2.out.data_to_stage3.pc, stage2.out.data_to_stage3.instr, rg_cur_priv);
      end

      // ----------------
      // Move instruction from Stage1 to Stage2

      if (   (! halting)
	  && (! stage2_full)
	  && (stage1.out.ostatus == OSTATUS_PIPE))
	 begin
	    stage1.deq;                              stage1_full = False;
	    stage2.enq (stage1.out.data_to_stage2);  stage2_full = True;
	 end

      // ----------------
      // Feed Stage 1

      if (   (! halting)
	  && (! stage1_full))
	 begin
	    fa_start_ifetch (stage1.out.next_pc, rg_cur_priv);
	    stage1_full = True;
	 end

      stage3.set_full (stage3_full);
      stage2.set_full (stage2_full);
      stage1.set_full (stage1_full);
   endrule: rl_pipe

   // ================================================================
   // Stage2: nonpipe special: all stage2 nonpipe behaviors are traps

   rule rl_stage2_nonpipe (   (rg_state == CPU_RUNNING)
			   && (stage3.out.ostatus == OSTATUS_EMPTY)
			   && (stage2.out.ostatus == OSTATUS_NONPIPE));
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_stage2_nonpipe", mcycle);

      let epc      = stage2.out.trap_info.epc;
      let exc_code = stage2.out.trap_info.exc_code;
      let tval     = stage2.out.trap_info.tval;
      let instr    = stage2.out.data_to_stage3.instr;

      // Take trap
      let trap_info <- csr_regfile.csr_trap_actions (rg_cur_priv,    // from priv
						     epc,
						     False,          // interrupt_req
						     exc_code,
						     tval);

      let next_pc    = trap_info.pc;
      let new_mstatus= trap_info.mstatus;
      let mcause     = trap_info.mcause;
      let new_priv   = trap_info.priv;

      // Save new privilege and pc for ifetch
      rg_cur_priv <= new_priv;

      fa_start_ifetch (next_pc, new_priv);
      stage1.set_full (True);
      stage2.set_full (False);

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace Data
      let trace_data = stage2.out.trace_data;
      trace_data.op = TRACE_TRAP;
      trace_data.pc = next_pc;
      // trace_data.instr_sz    should already be set
      // trace_data.instr       should already be set
      trace_data.rd    = zeroExtend (new_priv);
      trace_data.word1 = new_mstatus;
      trace_data.word2 = mcause;
      trace_data.word3 = zeroExtend (epc);
      trace_data.word4 = tval;
      f_trace_data.enq (trace_data);
`endif

      fa_emit_instr_trace (minstret, epc, instr, rg_cur_priv);

      // Debug
      if (cur_verbosity != 0)
	 $display ("    mcause:0x%0h  epc 0x%0h  tval:0x%0h  new pc 0x%0h, new mstatus 0x%0h",
		   mcause, epc, tval, next_pc, new_mstatus);
   endrule: rl_stage2_nonpipe

   // ================================================================
   // Stage1: nonpipe special: CSRRW and CSRRWI

   rule rl_stage1_CSRR_W (   (rg_state == CPU_RUNNING)
			  && (! halting)
			  && (stage3.out.ostatus == OSTATUS_EMPTY)
			  && (stage2.out.ostatus == OSTATUS_EMPTY)
			  && (stage1.out.ostatus == OSTATUS_NONPIPE)
			  && (stage1.out.control == CONTROL_CSRR_W));

      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_CSRR_W", mcycle);

      let instr    = stage1.out.data_to_stage2.instr;
      let csr_addr = instr_csr    (instr);
      let rs1      = instr_rs1    (instr);
      let funct3   = instr_funct3 (instr);
      let rd       = instr_rd     (instr);

`ifdef ISA_F
      // With FP, the val is always Bit #(64)
      // TODO: is this ifdef necessary? Can't we always use 'truncate'?
      WordXL stage2_val1= truncate (stage1.out.data_to_stage2.val1);
`else
      WordXL stage2_val1= stage1.out.data_to_stage2.val1;
`endif

      let rs1_val  = (  (funct3 == f3_CSRRW)
		      ? stage2_val1                       // CSRRW
		      : extend (rs1));                    // CSRRWI

      Bool read_not_write = False;    // CSRRW always writes the CSR
      Bool permitted = csr_regfile.access_permitted_1 (rg_cur_priv, csr_addr, read_not_write);

      if (! permitted) begin
	 rg_state <= CPU_TRAP;
	 // Debug
	 fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, instr, rg_cur_priv);
	 if (cur_verbosity > 1) begin
	    $display ("    rl_stage1_CSRR_W: Trap on CSR permissions: Rs1 %0d Rs1_val 0x%0h csr 0x%0h Rd %0d",
		      rs1, rs1_val, csr_addr, rd);
	 end
      end
      else begin
	 // Read the CSR only if Rd is not 0
	 WordXL csr_val = ?;
	 if (rd != 0) begin
	    // TODO: csr_regfile.read should become ActionValue (it may have side effects)
	    let m_csr_val = csr_regfile.read_csr (csr_addr);
	    csr_val   = fromMaybe (?, m_csr_val);
	 end

	 // Writeback to GPR file
	 let new_rd_val = csr_val;
	 gpr_regfile.write_rd (rd, new_rd_val);

	 // Writeback to CSR file
	 let new_csr_val <- csr_regfile.mav_csr_write (csr_addr, rs1_val);

	 // Accounting
	 csr_regfile.csr_minstret_incr;

	 // Restart the pipe
	 rg_state <= CPU_CSRRX_RESTART;

`ifdef INCLUDE_TANDEM_VERIF
	 // Trace data
	 let trace_data = stage1.out.data_to_stage2.trace_data;
	 trace_data.op = TRACE_CSRRX;
	 // trace_data.pc, instr_sz and instr    should already be set
	 trace_data.rd = rd;
	 trace_data.word1 = new_rd_val;
	 trace_data.word2 = 1;                        // whether we've written csr or not
	 trace_data.word3 = zeroExtend (csr_addr);
	 trace_data.word4 = new_csr_val;
	 f_trace_data.enq (trace_data);
`endif

	 // Debug
	 fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, instr, rg_cur_priv);
	 if (cur_verbosity > 1) begin
	    $display ("    S1: write CSRRW/CSRRWI Rs1 %0d Rs1_val 0x%0h csr 0x%0h csr_val 0x%0h Rd %0d",
		      rs1, rs1_val, csr_addr, csr_val, rd);
	 end
      end
   endrule: rl_stage1_CSRR_W

   // ================================================================
   // Stage1: nonpipe special: CSRRS, CSRRSI, CSRRC, CSRRCI

   rule rl_stage1_CSRR_S_or_C (   (rg_state == CPU_RUNNING)
			       && (! halting)
			       && (stage3.out.ostatus == OSTATUS_EMPTY)
			       && (stage2.out.ostatus == OSTATUS_EMPTY)
			       && (stage1.out.ostatus == OSTATUS_NONPIPE)
			       && (stage1.out.control == CONTROL_CSRR_S_or_C));

      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_CSRR_S_or_C", mcycle);

      let instr    = stage1.out.data_to_stage2.instr;
      let csr_addr = instr_csr    (instr);
      let rs1      = instr_rs1    (instr);
      let funct3   = instr_funct3 (instr);
      let rd       = instr_rd     (instr);

`ifdef ISA_F
      // With FP, the val is always Bit #(64)
      WordXL stage2_val1= truncate (stage1.out.data_to_stage2.val1);
`else
      WordXL stage2_val1= stage1.out.data_to_stage2.val1;
`endif

      let rs1_val  = (  ((funct3 == f3_CSRRS) || (funct3 == f3_CSRRC))
		      ? stage2_val1                      // CSRRS,  CSRRC
		      : extend (rs1));                   // CSRRSI, CSRRCI

      Bool read_not_write = (rs1_val == 0);    // CSRR_S_or_C only reads, does not write CSR, if rs1_val == 0
      Bool permitted = csr_regfile.access_permitted_2 (rg_cur_priv, csr_addr, read_not_write);

      if (! permitted) begin
	 rg_state <= CPU_TRAP;
	 // Debug
	 fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, instr, rg_cur_priv);
	 if (cur_verbosity > 1) begin
	    $display ("    rl_stage1_CSRR_S_or_C: Trap on CSR permissions: Rs1 %0d Rs1_val 0x%0h csr 0x%0h Rd %0d",
		      rs1, rs1_val, csr_addr, rd);
	 end
      end
      else begin
	 // Read the CSR
	 // TODO: csr_regfile.read should become ActionValue (it may have side effects)
	 let m_csr_val  = csr_regfile.read_csr (csr_addr);
	 WordXL csr_val = fromMaybe (?, m_csr_val);

	 // Writeback to GPR file
	 let new_rd_val = csr_val;
	 gpr_regfile.write_rd (rd, new_rd_val);

	 // Writeback to CSR file, but only if rs1 != 0
	 let x = (  ((funct3 == f3_CSRRS) || (funct3 == f3_CSRRSI))
		  ? (csr_val | rs1_val)                // CSRRS, CSRRSI
		  : csr_val & (~ rs1_val));            // CSRRC, CSRRCI

	 WordXL new_csr_val = ?;
	 if (rs1 != 0) begin
	    new_csr_val <- csr_regfile.mav_csr_write (csr_addr, x);
	 end

	 // Accounting
	 csr_regfile.csr_minstret_incr;

	 // Restart the pipe
	 rg_state <= CPU_CSRRX_RESTART;

`ifdef INCLUDE_TANDEM_VERIF
	 // Trace data
	 let trace_data = stage1.out.data_to_stage2.trace_data;
	 trace_data.op = TRACE_CSRRX;
	 // trace_data.pc, instr_sz and instr    should already be set
	 trace_data.rd = rd;
	 trace_data.word1 = new_rd_val;
	 trace_data.word2 = ((rs1 != 0) ? 1 : 0);    // whether we've written csr or not
	 trace_data.word3 = zeroExtend (csr_addr);
	 trace_data.word4 = new_csr_val;
	 f_trace_data.enq (trace_data);
`endif

	 // Debug
	 fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, instr, rg_cur_priv);
	 if (cur_verbosity > 1) begin
	    $display ("    S1: write CSRR_S_or_C: Rs1 %0d Rs1_val 0x%0h csr 0x%0h csr_val 0x%0h Rd %0d",
		      rs1, rs1_val, csr_addr, csr_val, rd);
	 end
      end
   endrule: rl_stage1_CSRR_S_or_C

   // ================================================================
   // Restart the pipe after a CSRRX stall

   rule rl_stage1_restart_after_csrrx (rg_state == CPU_CSRRX_RESTART);
      fa_start_ifetch (stage1.out.next_pc, rg_cur_priv);
      stage1.set_full (True);
      rg_state <= CPU_RUNNING;
      if (cur_verbosity > 1)
	 $display ("%0d: rl_stage1_restart_after_csrrx: minstret:%0d  pc:%0x  cur_priv:%0d",
		   mcycle, minstret, stage1.out.next_pc, rg_cur_priv);
   endrule

   // ================================================================
   // Stage1: nonpipe special: MRET/SRET/URET

   rule rl_stage1_xRET (   (rg_state == CPU_RUNNING)
			&& (! halting)
			&& (stage3.out.ostatus == OSTATUS_EMPTY)
			&& (stage2.out.ostatus == OSTATUS_EMPTY)
			&& (stage1.out.ostatus == OSTATUS_NONPIPE)
			&& (   (stage1.out.control == CONTROL_MRET)
			    || (stage1.out.control == CONTROL_SRET)
			    || (stage1.out.control == CONTROL_URET)));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_xRET", mcycle);

      // Return-from-exception actions on CSRs
      Priv_Mode from_priv = ((stage1.out.control == CONTROL_MRET) ?
			     m_Priv_Mode : ((stage1.out.control == CONTROL_SRET) ?
					    s_Priv_Mode : u_Priv_Mode));
      match { .next_pc, .new_priv, .new_mstatus } <- csr_regfile.csr_ret_actions (from_priv);
      rg_cur_priv <= new_priv;

      // Redirect PC
      fa_start_ifetch (next_pc, new_priv);
      stage1.set_full (True);

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let td  = stage1.out.data_to_stage2.trace_data;
      let td1 = mkTrace_RET (next_pc, td.instr_sz, td.instr, new_priv, new_mstatus);
      f_trace_data.enq (td1);
`endif

      // Debug
      fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, stage1.out.data_to_stage2.instr, rg_cur_priv);
      if (cur_verbosity != 0)
	 $display ("    xRET: next_pc:0x%0h  new mstatus:0x%0h  new priv:%0d", next_pc, new_mstatus, new_priv);
   endrule: rl_stage1_xRET

   // ================================================================
   // Stage1: nonpipe special: FENCE.I

   rule rl_stage1_FENCE_I (   (rg_state== CPU_RUNNING)
			   && (! halting)
			   && (stage3.out.ostatus == OSTATUS_EMPTY)
			   && (stage2.out.ostatus == OSTATUS_EMPTY)
			   && (stage1.out.ostatus == OSTATUS_NONPIPE)
			   && (stage1.out.control == CONTROL_FENCE_I));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_FENCE_I", mcycle);

      // Save stage1.out.next_pc since it will be destroyed by FENCE.I op
      rg_next_pc <= stage1.out.next_pc;
      near_mem.server_fence_i.request.put (?);
      rg_state <= CPU_FENCE_I;

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = stage1.out.data_to_stage2.trace_data;
      f_trace_data.enq (trace_data);
`endif

      // Debug
      fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, stage1.out.data_to_stage2.instr, rg_cur_priv);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_stage1_FENCE_I", mcycle);
   endrule

   // ----------------
   // Finish FENCE.I

   rule rl_finish_FENCE_I (rg_state == CPU_FENCE_I);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_finish_FENCE_I", mcycle);

      // Await mem system FENCE.I completion
      let dummy <- near_mem.server_fence_i.response.get;

      // Resume pipe
      rg_state <= CPU_RUNNING;
      fa_start_ifetch (rg_next_pc, rg_cur_priv);
      stage1.set_full (True);

      if (cur_verbosity > 1)
	 $display ("    CPU.rl_finish_FENCE_I");
   endrule: rl_finish_FENCE_I

   // ================================================================
   // Stage1: nonpipe special: FENCE

   rule rl_stage1_FENCE (   (rg_state== CPU_RUNNING)
			 && (! halting)
			 && (stage3.out.ostatus == OSTATUS_EMPTY)
			 && (stage2.out.ostatus == OSTATUS_EMPTY)
			 && (stage1.out.ostatus == OSTATUS_NONPIPE)
			 && (stage1.out.control == CONTROL_FENCE));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_FENCE", mcycle);

      rg_next_pc <= stage1.out.next_pc;
      near_mem.server_fence.request.put (?);
      rg_state <= CPU_FENCE;

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = stage1.out.data_to_stage2.trace_data;
      f_trace_data.enq (trace_data);
`endif

      // Debug
      fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, stage1.out.data_to_stage2.instr, rg_cur_priv);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_stage1_FENCE", mcycle);
   endrule

   // ----------------
   // Finish FENCE

   rule rl_finish_FENCE (rg_state == CPU_FENCE);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_finish_FENCE", mcycle);

      // Await mem system FENCE completion
      let dummy <- near_mem.server_fence.response.get;

      // Resume pipe
      rg_state <= CPU_RUNNING;
      fa_start_ifetch (rg_next_pc, rg_cur_priv);
      stage1.set_full (True);

      if (cur_verbosity > 1)
	 $display ("    CPU.rl_finish_FENCE");
   endrule: rl_finish_FENCE

   // ================================================================
   // Stage1: nonpipe special: SFENCE.VMA

`ifdef ISA_C
   // TODO: analyze this carefully; added to resolve a blockage
   (* descending_urgency = "imem_rl_fetch_next_32b, rl_stage1_SFENCE_VMA" *)
`endif

   rule rl_stage1_SFENCE_VMA (   (rg_state== CPU_RUNNING)
			      && (! halting)
			      && (stage3.out.ostatus == OSTATUS_EMPTY)
			      && (stage2.out.ostatus == OSTATUS_EMPTY)
			      && (stage1.out.ostatus == OSTATUS_NONPIPE)
			      && (stage1.out.control == CONTROL_SFENCE_VMA));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_SFENCE_VMA", mcycle);

      rg_next_pc <= stage1.out.next_pc;
      // Tell Near_Mem to do its SFENCE_VMA
      near_mem.sfence_vma;
      rg_state <= CPU_SFENCE_VMA;

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = stage1.out.data_to_stage2.trace_data;
      f_trace_data.enq (trace_data);
`endif

      // Debug
      fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, stage1.out.data_to_stage2.instr, rg_cur_priv);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_stage1_SFENCE_VMA", mcycle);
   endrule: rl_stage1_SFENCE_VMA

   // ----------------
   // Finish SFENCE.VMA

   rule rl_finish_SFENCE_VMA (rg_state == CPU_SFENCE_VMA);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_finish_SFENCE_VMA", mcycle);

      // TODO: Await mem system SFENCE.VMA completion

      // Resume pipe
      rg_state <= CPU_RUNNING;
      fa_start_ifetch (rg_next_pc, rg_cur_priv);
      stage1.set_full (True);

      if (cur_verbosity > 1)
	 $display ("    CPU.rl_finish_SFENCE_VMA");
   endrule: rl_finish_SFENCE_VMA

   // ================================================================
   // Stage1: nonpipe special: WFI

   rule rl_stage1_WFI (   (rg_state== CPU_RUNNING)
		       && (! halting)
		       && (stage3.out.ostatus == OSTATUS_EMPTY)
		       && (stage2.out.ostatus == OSTATUS_EMPTY)
		       && (stage1.out.ostatus == OSTATUS_NONPIPE)
		       && (stage1.out.control == CONTROL_WFI));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_WFI", mcycle);

      rg_next_pc <= stage1.out.next_pc;
      rg_state   <= CPU_WFI_PAUSED;

      // Accounting
      csr_regfile.csr_minstret_incr;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = stage1.out.data_to_stage2.trace_data;
      f_trace_data.enq (trace_data);
`endif

      // Debug
      fa_emit_instr_trace (minstret, stage1.out.data_to_stage2.pc, stage1.out.data_to_stage2.instr, rg_cur_priv);
      if (cur_verbosity > 1)
	 $display ("    CPU.rl_stage1_WFI");
   endrule: rl_stage1_WFI

   // ----------------

   rule rl_WFI_resume (   (rg_state == CPU_WFI_PAUSED)
		       && csr_regfile.wfi_resume);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_WFI_resume", mcycle);

      // Debug
      if (cur_verbosity >= 1)
	 $display ("    WFI resume");

      // Resume pipe (it will handle the interrupt, if one is pending)
      rg_state <= CPU_RUNNING;
      fa_start_ifetch (rg_next_pc, rg_cur_priv);
      stage1.set_full (True);
   endrule: rl_WFI_resume

   // ----------------
   rule rl_reset_from_WFI (   (rg_state == CPU_WFI_PAUSED)
			   && f_reset_reqs.notEmpty);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_reset_from_WFI", mcycle);

      rg_state <= CPU_RESET1;
   endrule: rl_reset_from_WFI

   // ================================================================
   // Stage1: nonpipe traps (except BREAKs that enter Debug Mode)

`ifdef INCLUDE_GDB_CONTROL
   Bool break_into_Debug_Mode = (   (stage1.out.trap_info.exc_code == exc_code_BREAKPOINT)
				 && csr_regfile.dcsr_break_enters_debug (rg_cur_priv));
`else
   Bool break_into_Debug_Mode = False;
`endif

   rule rl_stage1_trap (   (rg_state == CPU_TRAP)
			|| (   (rg_state == CPU_RUNNING)
			    && (! halting)
			    && (stage3.out.ostatus == OSTATUS_EMPTY)
			    && (stage2.out.ostatus == OSTATUS_EMPTY)
			    && (stage1.out.ostatus == OSTATUS_NONPIPE)
			    && (stage1.out.control == CONTROL_TRAP)
			    && (! break_into_Debug_Mode)));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_trap", mcycle);

      let epc      = stage1.out.trap_info.epc;
      let exc_code = stage1.out.trap_info.exc_code;
      let tval     = stage1.out.trap_info.tval;
      let instr    = stage1.out.data_to_stage2.instr;

      // Take trap, save trap information for next phase
      let trap_info <- csr_regfile.csr_trap_actions (rg_cur_priv, // from priv
						     epc,
						     False,       // interrupt_req
						     exc_code,
						     tval);

      let next_pc    = trap_info.pc;
      let new_mstatus= trap_info.mstatus;
      let mcause     = trap_info.mcause;
      let new_priv   = trap_info.priv;

      // Save new privilege and pc for ifetch
      rg_cur_priv <= new_priv;
      fa_start_ifetch (next_pc, new_priv);
      stage1.set_full (True);
      rg_state <= CPU_RUNNING;

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = stage1.out.data_to_stage2.trace_data;
      trace_data.op = TRACE_TRAP;
      trace_data.pc = next_pc;
      // trace_data.instr_sz    should already be set
      // trace_data.instr       should already be set
      trace_data.rd    = zeroExtend (new_priv);
      trace_data.word1 = new_mstatus;
      trace_data.word2 = mcause;
      trace_data.word3 = zeroExtend (epc);
      trace_data.word4 = tval;
      f_trace_data.enq (trace_data);
`endif

      // Simulation heuristic: finish if trap back to this instr
`ifndef INCLUDE_GDB_CONTROL
      if (epc == next_pc) begin
	 $display ("%0d: CPU.rl_stage1_trap: Tight infinite trap loop: pc 0x%0x instr 0x%08x", mcycle,
		   next_pc, instr);
	 fa_report_CPI;
	 $finish (0);
      end
`endif

      // Debug
      fa_emit_instr_trace (minstret, epc, instr, rg_cur_priv);
      if (cur_verbosity != 0) begin
	 $display ("%0d: CPU.rl_stage1_trap: priv:%0d  mcause:0x%0h  epc:0x%0h",
		   mcycle, rg_cur_priv, mcause, epc);
	 $display ("    tval:0x%0h  new pc:0x%0h  new mstatus:0x%0h", tval, next_pc, new_mstatus);
      end
   endrule: rl_stage1_trap

   // ================================================================
   // Stage1: nonpipe trap: BREAK into Debug Mode when dcsr.ebreakm/s/u is set
   // TODO: We are supposed to set mtval on a machine mode BREAK. Not doing so as we are breaking to the debugger

`ifdef INCLUDE_GDB_CONTROL
   rule rl_trap_BREAK_to_Debug_Mode (   (rg_state == CPU_RUNNING)
				     && (! halting)
				     && (stage3.out.ostatus == OSTATUS_EMPTY)
				     && (stage2.out.ostatus == OSTATUS_EMPTY)
				     && (stage1.out.ostatus == OSTATUS_NONPIPE)
				     && (stage1.out.control == CONTROL_TRAP)
				     && break_into_Debug_Mode);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_trap_BREAK_to_Debug_Mode", mcycle);

      let pc    = stage1.out.data_to_stage2.pc;
      let instr = stage1.out.data_to_stage2.instr;

      $display ("%0d: CPU.rl_trap_BREAK_to_Debug_Mode: PC 0x%08h instr 0x%08h", mcycle, pc, instr);
      if (cur_verbosity > 1)
	 $display ("    Flushing caches");

      csr_regfile.write_dcsr_cause_priv (DCSR_CAUSE_EBREAK, rg_cur_priv);
      csr_regfile.write_dpc (pc);    // Where we'll resume on 'continue'
      rg_state <= CPU_GDB_PAUSING;

      // Flush both caches -- using the same interface as that used by FENCE_I
      near_mem.server_fence_i.request.put (?);

      // Notify debugger that we've halted
      f_run_halt_rsps.enq (False);
   endrule: rl_trap_BREAK_to_Debug_Mode

   // Handle the flush responses from the caches when the flush was initiated
   // on entering CPU_GDB_PAUSING state
   rule rl_BREAK_cache_flush_finish (rg_state == CPU_GDB_PAUSING);
      let ack <- near_mem.server_fence_i.response.get;
      rg_state <= CPU_DEBUG_MODE;

      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_BREAK_cache_flush_finish", mcycle);
   endrule

   // ----------------
   // Reset while in Debug Mode

   rule rl_reset_from_Debug_Mode (   (rg_state == CPU_DEBUG_MODE)
				  && f_reset_reqs.notEmpty);
      if (cur_verbosity > 1)
	 $display ("%0d:  CPU.rl_reset_from_Debug_Mode", mcycle);

      rg_state <= CPU_RESET1;
   endrule
`endif

   // ================================================================
   // EXTERNAL and GDB INTERRUPTS while running
   // We take an interrupt when Stage1 is frozen
   // and Stage2 and Stage3 have drained,
   // encapsulated in condition 'stage1_take_interrupt'

   rule rl_stage1_interrupt (csr_regfile.interrupt_pending (rg_cur_priv) matches tagged Valid .exc_code
			     &&& (rg_state == CPU_RUNNING)
			     &&& stage1_take_interrupt);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_interrupt", mcycle);

      let epc   = stage1.out.data_to_stage2.pc;
      let instr = stage1.out.data_to_stage2.instr;

      // Take trap
      let trap_info <- csr_regfile.csr_trap_actions (rg_cur_priv,    // from priv
						     epc,
						     True,           // interrupt_req,
						     exc_code,
						     0);             // tval
      let next_pc       = trap_info.pc;
      let new_mstatus   = trap_info.mstatus;
      let mcause        = trap_info.mcause;
      let new_priv      = trap_info.priv;

      // Save new privilege
      rg_cur_priv <= new_priv;

      // Just enq the next_pc into stage1,
      // as the interrupt is taken
      Bit #(1) sstatus_SUM = new_mstatus [18];    // TODO: project new_mstatus to new_sstatus?
      Bit #(1) mstatus_MXR = new_mstatus [19];
      stage1.enq (next_pc, new_priv,
		  sstatus_SUM,
		  mstatus_MXR,
		  csr_regfile.read_satp);
      stage1.set_full (True);

      // Accounting: none (instruction is abandoned)

`ifdef INCLUDE_TANDEM_VERIF
      // Trace data
      let trace_data = mkTrace_INTR (next_pc, new_priv, new_mstatus, mcause, epc, 0);
      f_trace_data.enq (trace_data);
`endif

      // Debug
      fa_emit_instr_trace (minstret, epc, instr, rg_cur_priv);
      if (cur_verbosity > 0)
	 $display ("%0d: CPU.rl_stage1_interrupt: epc 0x%0h  next PC 0x%0h  new_priv %0d  new mstatus 0x%0h",
		   mcycle, epc, next_pc, new_priv, new_mstatus);
   endrule: rl_stage1_interrupt

   // ----------------
   // Stage1: Handle debugger stop-request and dcsr.step step-request while running
   // and no interrupt pending.
   // rg_halt should have allowed the pipeline to drain,
   // i.e., stage1 has completed its fetch,
   // and stage2 and stage3 are empty

`ifdef INCLUDE_GDB_CONTROL
   rule rl_stage1_stop (   (rg_state== CPU_RUNNING)
			&& stage1_stop
			&& (rg_stop_req || rg_step_req));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_stage1_stop", mcycle);

      let pc    = stage1.out.data_to_stage2.pc;    // We'll retry this instruction on 'continue'
      let instr = stage1.out.data_to_stage2.instr;

      // Report CPI only stop-req, but not on step-req (where it's not very useful)
      if (rg_stop_req) begin
	 $display ("%0d: CPU.rl_stop: Stop for debugger. minstret %0d priv %0d PC 0x%0h instr 0x%0h",
		   mcycle, minstret, rg_cur_priv, pc, instr);
	 fa_report_CPI;
      end
      else begin
	 $display ("%0d: CPU.rl_stop: Stop after single-step. PC = 0x%08h", mcycle, pc);
      end

      DCSR_Cause cause= (rg_stop_req ? DCSR_CAUSE_HALTREQ : DCSR_CAUSE_STEP);
      csr_regfile.write_dcsr_cause_priv (cause, rg_cur_priv);
      csr_regfile.write_dpc (pc);    // We'll retry this instruction on 'continue'
      rg_state    <= CPU_GDB_PAUSING;
      rg_halt     <= False;
      rg_stop_req <= False;
      rg_step_req <= False;

      // Notify debugger that we've halted
      f_run_halt_rsps.enq (False);

      // Flush both caches -- using the same interface as that used by FENCE_I
      near_mem.server_fence_i.request.put (?);

      // Accounting: none (instruction is abandoned)
   endrule: rl_stage1_stop
`endif

   // ================================================================
   // ================================================================
   // ================================================================
   // Connect timer and software interrupts

   rule rl_relay_sw_interrupts;
      let x <- near_mem.get_sw_interrupt_req.get;
      csr_regfile.software_interrupt_req (x);
      // $display ("%0d: CPU.rl_relay_sw_interrupts: relaying: %d", mcycle, pack (x));
   endrule

   rule rl_relay_timer_interrupts;
      let x <- near_mem.get_timer_interrupt_req.get;
      csr_regfile.timer_interrupt_req (x);
      // $display ("%0d: CPU.rl_relay_timer_interrupts: relaying: %d", mcycle, pack (x));
   endrule

   // ================================================================
   // ================================================================
   // ================================================================
   // DEBUGGER ACCESS

   // ----------------
   // Debug Module Run/Halt control

`ifdef INCLUDE_GDB_CONTROL
   rule rl_debug_run ((f_run_halt_reqs.first == True) && (rg_state == CPU_DEBUG_MODE));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_run", mcycle);

      f_run_halt_reqs.deq;

      // Debugger 'resume' request (e.g., GDB 'continue' command)
      let dpc = csr_regfile.read_dpc;
      fa_restart (dpc);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_run: 'run' from dpc 0x%0h", mcycle, dpc);
   endrule

   (* descending_urgency = "rl_debug_run_ignore, rl_pipe" *)
   rule rl_debug_run_ignore ((f_run_halt_reqs.first == True) && fn_is_running (rg_state));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_run_ignore", mcycle);

      f_run_halt_reqs.deq;
      $display ("%0d: CPU.debug_run_ignore: ignoring 'run' command (CPU is not in Debug Mode)", mcycle);
   endrule

   (* descending_urgency = "rl_debug_halt, rl_pipe" *)
   rule rl_debug_halt ((f_run_halt_reqs.first == False) && fn_is_running (rg_state));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_halt", mcycle);

      f_run_halt_reqs.deq;

      // Debugger 'halt' request (e.g., GDB '^C' command)
      rg_stop_req <= True;
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_halt", mcycle);
   endrule

   rule rl_debug_halt_ignore ((f_run_halt_reqs.first == False) && (! fn_is_running (rg_state)));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_halt_ignore", mcycle);

      f_run_halt_reqs.deq;

      $display ("%0d: CPU.rl_debug_halt_ignore: ignoring 'halt' (CPU already halted)", mcycle);
      $display ("    state = ", fshow (rg_state));
   endrule

   // ----------------
   // Debug Module GPR read/write

   rule rl_debug_read_gpr ((rg_state == CPU_DEBUG_MODE) && (! f_gpr_reqs.first.write));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_read_gpr", mcycle);

      let req <- pop (f_gpr_reqs);
      Bit #(5) regname = req.address;
      let data = gpr_regfile.read_rs1_port2 (regname);
      let rsp = MemoryResponse {data: data};
      f_gpr_rsps.enq (rsp);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_read_gpr: Read reg %0d => 0x%0h", mcycle, regname, data);
   endrule

   rule rl_debug_write_gpr ((rg_state == CPU_DEBUG_MODE) && f_gpr_reqs.first.write);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_write_gpr", mcycle);

      let req <- pop (f_gpr_reqs);
      Bit #(5) regname = req.address;
      let data = req.data;
      gpr_regfile.write_rd (regname, data);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_write_gpr: Write reg %0d => 0x%0h", mcycle, regname, data);
   endrule

`ifdef ISA_F
   // ----------------
   // Debug Module FPR read/write

   rule rl_debug_read_fpr ((rg_state == CPU_DEBUG_MODE) && (! f_fpr_reqs.first.write));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_read_fpr", mcycle);

      let req <- pop (f_fpr_reqs);
      Bit #(5) regname = req.address;
      let data = fpr_regfile.read_rs1_port2 (regname);
      let rsp = MemoryResponse {data: data};
      f_fpr_rsps.enq (rsp);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_read_fpr: Read reg %0d => 0x%0h", mcycle, regname, data);
   endrule

   rule rl_debug_write_fpr ((rg_state == CPU_DEBUG_MODE) && f_fpr_reqs.first.write);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_write_fpr", mcycle);

      let req <- pop (f_fpr_reqs);
      Bit #(5) regname = req.address;
      let data = req.data;
      fpr_regfile.write_rd (regname, data);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_write_fpr: Write reg %0d => 0x%0h", mcycle, regname, data);
   endrule
`endif

   // ----------------
   // Debug Module CSR read/write

   rule rl_debug_read_csr ((rg_state == CPU_DEBUG_MODE) && (! f_csr_reqs.first.write));
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_read_csr", mcycle);

      let req <- pop (f_csr_reqs);
      Bit #(12) csr_addr = req.address;
      let m_data = csr_regfile.read_csr_port2 (csr_addr);
      let data = fromMaybe (?, m_data);
      let rsp = MemoryResponse {data: data};
      f_csr_rsps.enq (rsp);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_read_csr: Read csr %0d => 0x%0h", mcycle, csr_addr, data);
   endrule

   rule rl_debug_write_csr ((rg_state == CPU_DEBUG_MODE) && f_csr_reqs.first.write);
      if (cur_verbosity > 1) $display ("%0d:  CPU.rl_debug_write_csr", mcycle);

      let req <- pop (f_csr_reqs);
      Bit #(12) csr_addr = req.address;
      let data = req.data;
      let new_csr_val <- csr_regfile.mav_csr_write (csr_addr, data);
      if (cur_verbosity > 1)
	 $display ("%0d: CPU.rl_debug_write_csr: Write csr 0x%0h 0x%0h => 0x%0h", mcycle, csr_addr, data, new_csr_val);
   endrule
`endif

   // ================================================================
   // ================================================================
   // ================================================================
   // INTERFACE

   // Reset
   interface Server  hart0_server_reset = toGPServer (f_reset_reqs, f_reset_rsps);

   // ----------------
   // SoC fabric connections

   // IMem to fabric master interface
   interface  imem_master = near_mem.imem_master;

   // DMem to fabric master interface
   interface  dmem_master = near_mem.dmem_master;

   // Near_Mem back door slave interface
   interface  near_mem_slave = near_mem.near_mem_slave;

   // ----------------
   // External interrupts

   method Action  external_interrupt_req (x) = csr_regfile.external_interrupt_req (x);

   // ----------------
   // For tracing

   method Action  set_verbosity (Bit #(4)  verbosity, Bit #(64)  logdelay);
      cfg_verbosity <= verbosity;
      cfg_logdelay  <= logdelay;
   endmethod

   // ----------------
   // Optional interface to Tandem Verifier

`ifdef INCLUDE_TANDEM_VERIF
   interface Get  trace_data_out = toGet (f_trace_data);
`endif

   // ----------------
   // Optional interface to Debug Module

`ifdef INCLUDE_GDB_CONTROL
   // run-control, other
   interface Server  hart0_server_run_halt = toGPServer (f_run_halt_reqs, f_run_halt_rsps);

   interface Put  hart0_put_other_req;
      method Action  put (Bit #(4) req);
	 cfg_verbosity <= req;
      endmethod
   endinterface

   // GPR access
   interface MemoryServer  hart0_gpr_mem_server = toGPServer (f_gpr_reqs, f_gpr_rsps);

`ifdef ISA_F
   // FPR access
   interface MemoryServer  hart0_fpr_mem_server = toGPServer (f_fpr_reqs, f_fpr_rsps);
`endif

   // CSR access
   interface MemoryServer  hart0_csr_mem_server = toGPServer (f_csr_reqs, f_csr_rsps);
`endif

endmodule: mkCPU

// ================================================================

endpackage
