// Copyright (c) 2013-2019 Bluespec, Inc. All Rights Reserved

package SoC_Map;

// ================================================================
// This module defines the overall 'address map' of the SoC, showing
// the addresses serviced by each slave IP, and which addresses are
// memory vs. I/O.

// ***** WARNING! WARNING! WARNING! *****

// During system integration, this address map should be identical to
// the system interconnect settings (e.g., routing of requests between
// masters and slaves).  This map is also needed by software so that
// it knows how to address various IPs.

// This module contains no state; it just has constants, and so can be
// freely instantiated at multiple places in the SoC module hierarchy
// at no hardware cost.  It allows this map to be defined in one
// place and shared across the SoC.

// ================================================================
// Exports

export  SoC_Map_IFC (..), mkSoC_Map;

// export  fn_addr_in_range;

export  debug_module_master_num;
export  imem_master_num;
export  dmem_master_num;

export  boot_rom_slave_num;
export  tcm_back_door_slave_num;
export  mem0_controller_slave_num;
export  uart0_slave_num;

// ================================================================
// Bluespec library imports

// None

// ================================================================
// Project imports

import Fabric_Defs :: *;    // Only for type Fabric_Addr
import Routable :: *;

// ================================================================
// Interface and module for the address map

interface SoC_Map_IFC;
   (* always_ready *)   method  Range#(Wd_Addr)  m_uart0_addr_range;

   (* always_ready *)   method  Range#(Wd_Addr)  m_near_mem_io_addr_range;

   (* always_ready *)   method  Range#(Wd_Addr)  m_boot_rom_addr_range;

   (* always_ready *)   method  Range#(Wd_Addr)  m_mem0_controller_addr_range;

   (* always_ready *)   method  Range#(Wd_Addr)  m_tcm_addr_range;

   (* always_ready *)
   method  Bool  m_is_mem_addr (Fabric_Addr addr);

   (* always_ready *)
   method  Bool  m_is_IO_addr (Fabric_Addr addr);

   (* always_ready *)
   method  Bool  m_is_near_mem_IO_addr (Fabric_Addr addr);

   (* always_ready *)   method  Bit #(64)    m_pc_reset_value;
endinterface

// ================================================================

(* synthesize *)
module mkSoC_Map (SoC_Map_IFC);

   // ----------------------------------------------------------------
   // UART 0

   let uart0_addr_range = Range {
      base: 'hC000_0000,
      size: 'h0000_0080     // 128
   };

   // ----------------------------------------------------------------
   // Near_Mem_IO (including CLINT, the core-local interruptor)

   let near_mem_io_addr_range = Range {
      base: 'h_0200_0000,
      size: 'h_0000_C000    // 48K
   };

   // ----------------------------------------------------------------
   // Boot ROM

   let boot_rom_addr_range = Range {
      base: 'h_0000_1000,
      size: 'h_0000_1000    // 4K
   };

   // ----------------------------------------------------------------
   // Main Mem Controller 0

   let mem0_controller_addr_range = Range {
      base: 'h_8000_0000,
      size: 'h_0FFF_FFFF    // 256 MB
   };

   // ----------------------------------------------------------------
   // Tightly-coupled memory ('TCM'; optional)

`ifdef Near_Mem_TCM
// Integer kB_per_TCM = 'h4;         // 4KB
// Integer kB_per_TCM = 'h40;     // 64KB
// Integer kB_per_TCM = 'h80;     // 128KB
// Integer kB_per_TCM = 'h400;    // 1 MB
   Integer kB_per_TCM = 'h4000;    // 16 MB
`else
   Integer kB_per_TCM = 0;
`endif
   Integer bytes_per_TCM = kB_per_TCM * 'h400;

   let tcm_addr_range = Range {
      base: 'h_0000_0000,
      size: fromInteger (bytes_per_TCM)
   };

   // ----------------------------------------------------------------
   // Memory address predicate
   // Identifies memory addresses in the Fabric.
   // (Caches need this information to cache these addresses.)

   function Bool fn_is_mem_addr (Fabric_Addr addr);
       return (  inRange(boot_rom_addr_range, addr)
	      || inRange(mem0_controller_addr_range, addr)
	      || inRange(tcm_addr_range, addr)
	      );
   endfunction

   // ----------------------------------------------------------------
   // I/O address predicate
   // Identifies I/O addresses in the Fabric.
   // (Caches need this information to avoid cacheing these addresses.)

   function Bool fn_is_IO_addr (Fabric_Addr addr);
      return (   inRange  (uart0_addr_range, addr)
	      || inRange(near_mem_io_addr_range, addr)
	      );
   endfunction

   // ----------------------------------------------------------------
   // PC reset value

   Bit #(64) pc_reset_value = boot_rom_addr_range.base;

   // ================================================================
   // INTERFACE

   method  Range#(Wd_Addr)  m_uart0_addr_range = uart0_addr_range;

   method  Range#(Wd_Addr)  m_near_mem_io_addr_range = near_mem_io_addr_range;

   method  Range#(Wd_Addr)  m_boot_rom_addr_range = boot_rom_addr_range;

   method  Range#(Wd_Addr)  m_mem0_controller_addr_range = mem0_controller_addr_range;

   method  Range#(Wd_Addr)  m_tcm_addr_range = tcm_addr_range;

   method  Bool  m_is_mem_addr (Fabric_Addr addr) = fn_is_mem_addr (addr);

   method  Bool  m_is_IO_addr (Fabric_Addr addr) = fn_is_IO_addr (addr);

   method  Bool  m_is_near_mem_IO_addr (Fabric_Addr addr) = inRange (near_mem_io_addr_range, addr);

   method  Bit #(64)    m_pc_reset_value = pc_reset_value;
endmodule

// ================================================================
// Count and master-numbers of masters in the fabric.

Integer debug_module_master_num = 0;
Integer imem_master_num         = 1;
Integer dmem_master_num         = 2;

// ================================================================
// Count and slave-numbers of slaves in the fabric.

Integer tcm_back_door_slave_num   = 0;
Integer boot_rom_slave_num        = 1;
Integer mem0_controller_slave_num = 2;
Integer uart0_slave_num           = 3;

// ================================================================

endpackage
