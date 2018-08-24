/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:11:17 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkNear_Mem_h__
#define __mkNear_Mem_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkMMU_Cache.h"


/* Class declaration for the mkNear_Mem module */
class MOD_mkNear_Mem : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_ConfigReg<tUInt8> INST_cfg_verbosity;
  MOD_mkMMU_Cache INST_dcache;
  MOD_Fifo<tUInt8> INST_f_reset_rsps;
  MOD_mkMMU_Cache INST_icache;
  MOD_Reg<tUInt8> INST_rg_state;
 
 /* Constructor */
 public:
  MOD_mkNear_Mem(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_EN_server_fence_i_request_put;
  tUInt8 PORT_EN_server_fence_request_put;
  tUInt8 PORT_dmem_master_rready;
  tUInt8 PORT_dmem_master_arvalid;
  tUInt8 PORT_dmem_master_bready;
  tUInt8 PORT_dmem_master_wvalid;
  tUInt8 PORT_dmem_master_awvalid;
  tUInt8 PORT_imem_master_rready;
  tUInt8 PORT_imem_master_arvalid;
  tUInt8 PORT_imem_master_bready;
  tUInt8 PORT_imem_master_wvalid;
  tUInt8 PORT_imem_master_awvalid;
  tUInt64 PORT_imem_master_awaddr;
  tUInt8 PORT_imem_master_awprot;
  tUInt8 PORT_imem_master_awuser;
  tUInt64 PORT_imem_master_wdata;
  tUInt8 PORT_imem_master_wstrb;
  tUInt64 PORT_imem_master_araddr;
  tUInt8 PORT_imem_master_arprot;
  tUInt8 PORT_imem_master_aruser;
  tUInt64 PORT_dmem_master_awaddr;
  tUInt8 PORT_dmem_master_awprot;
  tUInt8 PORT_dmem_master_awuser;
  tUInt64 PORT_dmem_master_wdata;
  tUInt8 PORT_dmem_master_wstrb;
  tUInt64 PORT_dmem_master_araddr;
  tUInt8 PORT_dmem_master_arprot;
  tUInt8 PORT_dmem_master_aruser;
  tUInt8 PORT_near_mem_slave_awready;
  tUInt8 PORT_near_mem_slave_wready;
  tUInt8 PORT_near_mem_slave_bvalid;
  tUInt8 PORT_near_mem_slave_bresp;
  tUInt8 PORT_near_mem_slave_buser;
  tUInt8 PORT_near_mem_slave_arready;
  tUInt8 PORT_near_mem_slave_rvalid;
  tUInt8 PORT_near_mem_slave_rresp;
  tUInt64 PORT_near_mem_slave_rdata;
  tUInt8 PORT_near_mem_slave_ruser;
  tUInt8 PORT_RDY_imem_master_m_awready;
  tUInt8 PORT_RDY_imem_master_m_wready;
  tUInt8 PORT_RDY_imem_master_m_bvalid;
  tUInt8 PORT_RDY_imem_master_m_arready;
  tUInt8 PORT_RDY_imem_master_m_rvalid;
  tUInt8 PORT_RDY_dmem_master_m_awready;
  tUInt8 PORT_RDY_dmem_master_m_wready;
  tUInt8 PORT_RDY_dmem_master_m_bvalid;
  tUInt8 PORT_RDY_dmem_master_m_arready;
  tUInt8 PORT_RDY_dmem_master_m_rvalid;
  tUInt8 PORT_RDY_near_mem_slave_m_awvalid;
  tUInt8 PORT_RDY_near_mem_slave_m_wvalid;
  tUInt8 PORT_RDY_near_mem_slave_m_bready;
  tUInt8 PORT_RDY_near_mem_slave_m_arvalid;
  tUInt8 PORT_RDY_near_mem_slave_m_rready;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_server_fence_request_put;
  tUInt8 DEF_WILL_FIRE_server_fence_i_request_put;
  tUInt8 DEF_dcache_RDY_server_flush_response_get____d25;
  tUInt8 DEF_dcache_RDY_server_flush_request_put____d23;
  tUInt8 DEF_rg_state__h929;
 
 /* Local definitions */
 private:
  tUInt32 DEF_v__h1217;
  tUInt32 DEF_v__h1066;
  tUInt8 DEF_x__h1198;
  tUInt8 DEF_NOT_cfg_verbosity_read_ULE_1___d9;
 
 /* Rules */
 public:
  void RL_rl_reset();
  void RL_rl_reset_complete();
 
 /* Methods */
 public:
  tUInt8 METH_imem_master_m_awuser();
  tUInt8 METH_RDY_imem_master_m_awuser();
  tUInt8 METH_imem_master_m_aruser();
  tUInt8 METH_RDY_imem_master_m_aruser();
  tUInt8 METH_dmem_master_m_awuser();
  tUInt8 METH_RDY_dmem_master_m_awuser();
  tUInt8 METH_dmem_master_m_aruser();
  tUInt8 METH_RDY_dmem_master_m_aruser();
  tUInt8 METH_near_mem_slave_m_awready();
  tUInt8 METH_RDY_near_mem_slave_m_awready();
  tUInt8 METH_near_mem_slave_m_wready();
  tUInt8 METH_RDY_near_mem_slave_m_wready();
  tUInt8 METH_near_mem_slave_m_bvalid();
  tUInt8 METH_RDY_near_mem_slave_m_bvalid();
  tUInt8 METH_near_mem_slave_m_bresp();
  tUInt8 METH_RDY_near_mem_slave_m_bresp();
  tUInt8 METH_near_mem_slave_m_buser();
  tUInt8 METH_RDY_near_mem_slave_m_buser();
  tUInt8 METH_near_mem_slave_m_arready();
  tUInt8 METH_RDY_near_mem_slave_m_arready();
  tUInt8 METH_near_mem_slave_m_rvalid();
  tUInt8 METH_RDY_near_mem_slave_m_rvalid();
  tUInt8 METH_near_mem_slave_m_rresp();
  tUInt8 METH_RDY_near_mem_slave_m_rresp();
  tUInt64 METH_near_mem_slave_m_rdata();
  tUInt8 METH_RDY_near_mem_slave_m_rdata();
  tUInt8 METH_near_mem_slave_m_ruser();
  tUInt8 METH_RDY_near_mem_slave_m_ruser();
  void METH_server_reset_request_put(tUInt8 ARG_server_reset_request_put);
  tUInt8 METH_RDY_server_reset_request_put();
  void METH_server_reset_response_get();
  tUInt8 METH_RDY_server_reset_response_get();
  void METH_imem_req(tUInt8 ARG_imem_req_f3,
		     tUInt64 ARG_imem_req_addr,
		     tUInt8 ARG_imem_req_priv,
		     tUInt8 ARG_imem_req_sstatus_SUM,
		     tUInt8 ARG_imem_req_mstatus_MXR,
		     tUInt64 ARG_imem_req_satp);
  tUInt8 METH_RDY_imem_req();
  tUInt8 METH_imem_valid();
  tUInt8 METH_RDY_imem_valid();
  tUInt64 METH_imem_pc();
  tUInt8 METH_RDY_imem_pc();
  tUInt32 METH_imem_instr();
  tUInt8 METH_RDY_imem_instr();
  tUInt8 METH_imem_exc();
  tUInt8 METH_RDY_imem_exc();
  tUInt8 METH_imem_exc_code();
  tUInt8 METH_RDY_imem_exc_code();
  tUInt8 METH_imem_master_m_awvalid();
  tUInt8 METH_RDY_imem_master_m_awvalid();
  tUInt64 METH_imem_master_m_awaddr();
  tUInt8 METH_RDY_imem_master_m_awaddr();
  tUInt8 METH_imem_master_m_awprot();
  tUInt8 METH_RDY_imem_master_m_awprot();
  void METH_imem_master_m_awready(tUInt8 ARG_imem_master_awready);
  tUInt8 METH_RDY_imem_master_m_awready();
  tUInt8 METH_imem_master_m_wvalid();
  tUInt8 METH_RDY_imem_master_m_wvalid();
  tUInt64 METH_imem_master_m_wdata();
  tUInt8 METH_RDY_imem_master_m_wdata();
  tUInt8 METH_imem_master_m_wstrb();
  tUInt8 METH_RDY_imem_master_m_wstrb();
  void METH_imem_master_m_wready(tUInt8 ARG_imem_master_wready);
  tUInt8 METH_RDY_imem_master_m_wready();
  void METH_imem_master_m_bvalid(tUInt8 ARG_imem_master_bvalid,
				 tUInt8 ARG_imem_master_bresp,
				 tUInt8 ARG_imem_master_buser);
  tUInt8 METH_RDY_imem_master_m_bvalid();
  tUInt8 METH_imem_master_m_bready();
  tUInt8 METH_RDY_imem_master_m_bready();
  tUInt8 METH_imem_master_m_arvalid();
  tUInt8 METH_RDY_imem_master_m_arvalid();
  tUInt64 METH_imem_master_m_araddr();
  tUInt8 METH_RDY_imem_master_m_araddr();
  tUInt8 METH_imem_master_m_arprot();
  tUInt8 METH_RDY_imem_master_m_arprot();
  void METH_imem_master_m_arready(tUInt8 ARG_imem_master_arready);
  tUInt8 METH_RDY_imem_master_m_arready();
  void METH_imem_master_m_rvalid(tUInt8 ARG_imem_master_rvalid,
				 tUInt8 ARG_imem_master_rresp,
				 tUInt64 ARG_imem_master_rdata,
				 tUInt8 ARG_imem_master_ruser);
  tUInt8 METH_RDY_imem_master_m_rvalid();
  tUInt8 METH_imem_master_m_rready();
  tUInt8 METH_RDY_imem_master_m_rready();
  void METH_dmem_req(tUInt8 ARG_dmem_req_op,
		     tUInt8 ARG_dmem_req_f3,
		     tUInt8 ARG_dmem_req_amo_funct7,
		     tUInt64 ARG_dmem_req_addr,
		     tUInt64 ARG_dmem_req_store_value,
		     tUInt8 ARG_dmem_req_priv,
		     tUInt8 ARG_dmem_req_sstatus_SUM,
		     tUInt8 ARG_dmem_req_mstatus_MXR,
		     tUInt64 ARG_dmem_req_satp);
  tUInt8 METH_RDY_dmem_req();
  tUInt8 METH_dmem_valid();
  tUInt8 METH_RDY_dmem_valid();
  tUInt64 METH_dmem_word64();
  tUInt8 METH_RDY_dmem_word64();
  tUInt64 METH_dmem_st_amo_val();
  tUInt8 METH_RDY_dmem_st_amo_val();
  tUInt8 METH_dmem_exc();
  tUInt8 METH_RDY_dmem_exc();
  tUInt8 METH_dmem_exc_code();
  tUInt8 METH_RDY_dmem_exc_code();
  tUInt8 METH_dmem_master_m_awvalid();
  tUInt8 METH_RDY_dmem_master_m_awvalid();
  tUInt64 METH_dmem_master_m_awaddr();
  tUInt8 METH_RDY_dmem_master_m_awaddr();
  tUInt8 METH_dmem_master_m_awprot();
  tUInt8 METH_RDY_dmem_master_m_awprot();
  void METH_dmem_master_m_awready(tUInt8 ARG_dmem_master_awready);
  tUInt8 METH_RDY_dmem_master_m_awready();
  tUInt8 METH_dmem_master_m_wvalid();
  tUInt8 METH_RDY_dmem_master_m_wvalid();
  tUInt64 METH_dmem_master_m_wdata();
  tUInt8 METH_RDY_dmem_master_m_wdata();
  tUInt8 METH_dmem_master_m_wstrb();
  tUInt8 METH_RDY_dmem_master_m_wstrb();
  void METH_dmem_master_m_wready(tUInt8 ARG_dmem_master_wready);
  tUInt8 METH_RDY_dmem_master_m_wready();
  void METH_dmem_master_m_bvalid(tUInt8 ARG_dmem_master_bvalid,
				 tUInt8 ARG_dmem_master_bresp,
				 tUInt8 ARG_dmem_master_buser);
  tUInt8 METH_RDY_dmem_master_m_bvalid();
  tUInt8 METH_dmem_master_m_bready();
  tUInt8 METH_RDY_dmem_master_m_bready();
  tUInt8 METH_dmem_master_m_arvalid();
  tUInt8 METH_RDY_dmem_master_m_arvalid();
  tUInt64 METH_dmem_master_m_araddr();
  tUInt8 METH_RDY_dmem_master_m_araddr();
  tUInt8 METH_dmem_master_m_arprot();
  tUInt8 METH_RDY_dmem_master_m_arprot();
  void METH_dmem_master_m_arready(tUInt8 ARG_dmem_master_arready);
  tUInt8 METH_RDY_dmem_master_m_arready();
  void METH_dmem_master_m_rvalid(tUInt8 ARG_dmem_master_rvalid,
				 tUInt8 ARG_dmem_master_rresp,
				 tUInt64 ARG_dmem_master_rdata,
				 tUInt8 ARG_dmem_master_ruser);
  tUInt8 METH_RDY_dmem_master_m_rvalid();
  tUInt8 METH_dmem_master_m_rready();
  tUInt8 METH_RDY_dmem_master_m_rready();
  void METH_server_fence_i_request_put(tUInt8 ARG_server_fence_i_request_put);
  tUInt8 METH_RDY_server_fence_i_request_put();
  void METH_server_fence_i_response_get();
  tUInt8 METH_RDY_server_fence_i_response_get();
  void METH_server_fence_request_put(tUInt8 ARG_server_fence_request_put);
  tUInt8 METH_RDY_server_fence_request_put();
  void METH_server_fence_response_get();
  tUInt8 METH_RDY_server_fence_response_get();
  void METH_sfence_vma();
  tUInt8 METH_RDY_sfence_vma();
  void METH_near_mem_slave_m_awvalid(tUInt8 ARG_near_mem_slave_awvalid,
				     tUInt64 ARG_near_mem_slave_awaddr,
				     tUInt8 ARG_near_mem_slave_awprot,
				     tUInt8 ARG_near_mem_slave_awuser);
  tUInt8 METH_RDY_near_mem_slave_m_awvalid();
  void METH_near_mem_slave_m_wvalid(tUInt8 ARG_near_mem_slave_wvalid,
				    tUInt64 ARG_near_mem_slave_wdata,
				    tUInt8 ARG_near_mem_slave_wstrb);
  tUInt8 METH_RDY_near_mem_slave_m_wvalid();
  void METH_near_mem_slave_m_bready(tUInt8 ARG_near_mem_slave_bready);
  tUInt8 METH_RDY_near_mem_slave_m_bready();
  void METH_near_mem_slave_m_arvalid(tUInt8 ARG_near_mem_slave_arvalid,
				     tUInt64 ARG_near_mem_slave_araddr,
				     tUInt8 ARG_near_mem_slave_arprot,
				     tUInt8 ARG_near_mem_slave_aruser);
  tUInt8 METH_RDY_near_mem_slave_m_arvalid();
  void METH_near_mem_slave_m_rready(tUInt8 ARG_near_mem_slave_rready);
  tUInt8 METH_RDY_near_mem_slave_m_rready();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkNear_Mem &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkNear_Mem &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkNear_Mem &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkNear_Mem &backing);
};

#endif /* ifndef __mkNear_Mem_h__ */
