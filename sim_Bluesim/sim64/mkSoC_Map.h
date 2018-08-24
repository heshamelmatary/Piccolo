/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:11:17 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkSoC_Map_h__
#define __mkSoC_Map_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkSoC_Map module */
class MOD_mkSoC_Map : public Module {
 
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
 
 /* Constructor */
 public:
  MOD_mkSoC_Map(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
 
 /* Rules */
 public:
 
 /* Methods */
 public:
  tUInt64 METH_m_boot_rom_addr_size();
  tUInt8 METH_RDY_m_boot_rom_addr_size();
  tUInt64 METH_m_boot_rom_addr_base();
  tUInt8 METH_RDY_m_boot_rom_addr_base();
  tUInt64 METH_m_boot_rom_addr_lim();
  tUInt8 METH_RDY_m_boot_rom_addr_lim();
  tUInt64 METH_m_tcm_addr_size();
  tUInt8 METH_RDY_m_tcm_addr_size();
  tUInt64 METH_m_tcm_addr_base();
  tUInt8 METH_RDY_m_tcm_addr_base();
  tUInt64 METH_m_tcm_addr_lim();
  tUInt8 METH_RDY_m_tcm_addr_lim();
  tUInt64 METH_m_mem0_controller_addr_size();
  tUInt8 METH_RDY_m_mem0_controller_addr_size();
  tUInt64 METH_m_mem0_controller_addr_base();
  tUInt8 METH_RDY_m_mem0_controller_addr_base();
  tUInt64 METH_m_mem0_controller_addr_lim();
  tUInt8 METH_RDY_m_mem0_controller_addr_lim();
  tUInt64 METH_m_uart0_addr_size();
  tUInt8 METH_RDY_m_uart0_addr_size();
  tUInt64 METH_m_uart0_addr_base();
  tUInt8 METH_RDY_m_uart0_addr_base();
  tUInt64 METH_m_uart0_addr_lim();
  tUInt8 METH_RDY_m_uart0_addr_lim();
  tUInt64 METH_m_timer0_addr_size();
  tUInt8 METH_RDY_m_timer0_addr_size();
  tUInt64 METH_m_timer0_addr_base();
  tUInt8 METH_RDY_m_timer0_addr_base();
  tUInt64 METH_m_timer0_addr_lim();
  tUInt8 METH_RDY_m_timer0_addr_lim();
  tUInt8 METH_m_is_IO_addr(tUInt64 ARG_m_is_IO_addr_addr);
  tUInt8 METH_RDY_m_is_IO_addr();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkSoC_Map &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkSoC_Map &backing);
};

#endif /* ifndef __mkSoC_Map_h__ */
