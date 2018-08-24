/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "mkSoC_Map.h"


/* Constructor */
MOD_mkSoC_Map::MOD_mkSoC_Map(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent), __clk_handle_0(BAD_CLOCK_HANDLE), PORT_RST_N((tUInt8)1u)
{
  symbol_count = 0u;
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkSoC_Map::init_symbols_0()
{
}


/* Rule actions */


/* Methods */

tUInt64 MOD_mkSoC_Map::METH_m_boot_rom_addr_size()
{
  tUInt64 PORT_m_boot_rom_addr_size;
  PORT_m_boot_rom_addr_size = 4096llu;
  return PORT_m_boot_rom_addr_size;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_boot_rom_addr_size()
{
  tUInt8 PORT_RDY_m_boot_rom_addr_size;
  tUInt8 DEF_CAN_FIRE_m_boot_rom_addr_size;
  DEF_CAN_FIRE_m_boot_rom_addr_size = (tUInt8)1u;
  PORT_RDY_m_boot_rom_addr_size = DEF_CAN_FIRE_m_boot_rom_addr_size;
  return PORT_RDY_m_boot_rom_addr_size;
}

tUInt64 MOD_mkSoC_Map::METH_m_boot_rom_addr_base()
{
  tUInt64 PORT_m_boot_rom_addr_base;
  PORT_m_boot_rom_addr_base = 4096llu;
  return PORT_m_boot_rom_addr_base;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_boot_rom_addr_base()
{
  tUInt8 PORT_RDY_m_boot_rom_addr_base;
  tUInt8 DEF_CAN_FIRE_m_boot_rom_addr_base;
  DEF_CAN_FIRE_m_boot_rom_addr_base = (tUInt8)1u;
  PORT_RDY_m_boot_rom_addr_base = DEF_CAN_FIRE_m_boot_rom_addr_base;
  return PORT_RDY_m_boot_rom_addr_base;
}

tUInt64 MOD_mkSoC_Map::METH_m_boot_rom_addr_lim()
{
  tUInt64 PORT_m_boot_rom_addr_lim;
  PORT_m_boot_rom_addr_lim = 8192llu;
  return PORT_m_boot_rom_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_boot_rom_addr_lim()
{
  tUInt8 PORT_RDY_m_boot_rom_addr_lim;
  tUInt8 DEF_CAN_FIRE_m_boot_rom_addr_lim;
  DEF_CAN_FIRE_m_boot_rom_addr_lim = (tUInt8)1u;
  PORT_RDY_m_boot_rom_addr_lim = DEF_CAN_FIRE_m_boot_rom_addr_lim;
  return PORT_RDY_m_boot_rom_addr_lim;
}

tUInt64 MOD_mkSoC_Map::METH_m_tcm_addr_size()
{
  tUInt64 PORT_m_tcm_addr_size;
  PORT_m_tcm_addr_size = 0llu;
  return PORT_m_tcm_addr_size;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_tcm_addr_size()
{
  tUInt8 PORT_RDY_m_tcm_addr_size;
  tUInt8 DEF_CAN_FIRE_m_tcm_addr_size;
  DEF_CAN_FIRE_m_tcm_addr_size = (tUInt8)1u;
  PORT_RDY_m_tcm_addr_size = DEF_CAN_FIRE_m_tcm_addr_size;
  return PORT_RDY_m_tcm_addr_size;
}

tUInt64 MOD_mkSoC_Map::METH_m_tcm_addr_base()
{
  tUInt64 PORT_m_tcm_addr_base;
  PORT_m_tcm_addr_base = 0llu;
  return PORT_m_tcm_addr_base;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_tcm_addr_base()
{
  tUInt8 PORT_RDY_m_tcm_addr_base;
  tUInt8 DEF_CAN_FIRE_m_tcm_addr_base;
  DEF_CAN_FIRE_m_tcm_addr_base = (tUInt8)1u;
  PORT_RDY_m_tcm_addr_base = DEF_CAN_FIRE_m_tcm_addr_base;
  return PORT_RDY_m_tcm_addr_base;
}

tUInt64 MOD_mkSoC_Map::METH_m_tcm_addr_lim()
{
  tUInt64 PORT_m_tcm_addr_lim;
  PORT_m_tcm_addr_lim = 0llu;
  return PORT_m_tcm_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_tcm_addr_lim()
{
  tUInt8 PORT_RDY_m_tcm_addr_lim;
  tUInt8 DEF_CAN_FIRE_m_tcm_addr_lim;
  DEF_CAN_FIRE_m_tcm_addr_lim = (tUInt8)1u;
  PORT_RDY_m_tcm_addr_lim = DEF_CAN_FIRE_m_tcm_addr_lim;
  return PORT_RDY_m_tcm_addr_lim;
}

tUInt64 MOD_mkSoC_Map::METH_m_mem0_controller_addr_size()
{
  tUInt64 PORT_m_mem0_controller_addr_size;
  PORT_m_mem0_controller_addr_size = 268435456llu;
  return PORT_m_mem0_controller_addr_size;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_mem0_controller_addr_size()
{
  tUInt8 PORT_RDY_m_mem0_controller_addr_size;
  tUInt8 DEF_CAN_FIRE_m_mem0_controller_addr_size;
  DEF_CAN_FIRE_m_mem0_controller_addr_size = (tUInt8)1u;
  PORT_RDY_m_mem0_controller_addr_size = DEF_CAN_FIRE_m_mem0_controller_addr_size;
  return PORT_RDY_m_mem0_controller_addr_size;
}

tUInt64 MOD_mkSoC_Map::METH_m_mem0_controller_addr_base()
{
  tUInt64 PORT_m_mem0_controller_addr_base;
  PORT_m_mem0_controller_addr_base = 2147483648llu;
  return PORT_m_mem0_controller_addr_base;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_mem0_controller_addr_base()
{
  tUInt8 PORT_RDY_m_mem0_controller_addr_base;
  tUInt8 DEF_CAN_FIRE_m_mem0_controller_addr_base;
  DEF_CAN_FIRE_m_mem0_controller_addr_base = (tUInt8)1u;
  PORT_RDY_m_mem0_controller_addr_base = DEF_CAN_FIRE_m_mem0_controller_addr_base;
  return PORT_RDY_m_mem0_controller_addr_base;
}

tUInt64 MOD_mkSoC_Map::METH_m_mem0_controller_addr_lim()
{
  tUInt64 PORT_m_mem0_controller_addr_lim;
  PORT_m_mem0_controller_addr_lim = 2415919104llu;
  return PORT_m_mem0_controller_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_mem0_controller_addr_lim()
{
  tUInt8 PORT_RDY_m_mem0_controller_addr_lim;
  tUInt8 DEF_CAN_FIRE_m_mem0_controller_addr_lim;
  DEF_CAN_FIRE_m_mem0_controller_addr_lim = (tUInt8)1u;
  PORT_RDY_m_mem0_controller_addr_lim = DEF_CAN_FIRE_m_mem0_controller_addr_lim;
  return PORT_RDY_m_mem0_controller_addr_lim;
}

tUInt64 MOD_mkSoC_Map::METH_m_uart0_addr_size()
{
  tUInt64 PORT_m_uart0_addr_size;
  PORT_m_uart0_addr_size = 128llu;
  return PORT_m_uart0_addr_size;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_uart0_addr_size()
{
  tUInt8 PORT_RDY_m_uart0_addr_size;
  tUInt8 DEF_CAN_FIRE_m_uart0_addr_size;
  DEF_CAN_FIRE_m_uart0_addr_size = (tUInt8)1u;
  PORT_RDY_m_uart0_addr_size = DEF_CAN_FIRE_m_uart0_addr_size;
  return PORT_RDY_m_uart0_addr_size;
}

tUInt64 MOD_mkSoC_Map::METH_m_uart0_addr_base()
{
  tUInt64 PORT_m_uart0_addr_base;
  PORT_m_uart0_addr_base = 3221225472llu;
  return PORT_m_uart0_addr_base;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_uart0_addr_base()
{
  tUInt8 PORT_RDY_m_uart0_addr_base;
  tUInt8 DEF_CAN_FIRE_m_uart0_addr_base;
  DEF_CAN_FIRE_m_uart0_addr_base = (tUInt8)1u;
  PORT_RDY_m_uart0_addr_base = DEF_CAN_FIRE_m_uart0_addr_base;
  return PORT_RDY_m_uart0_addr_base;
}

tUInt64 MOD_mkSoC_Map::METH_m_uart0_addr_lim()
{
  tUInt64 PORT_m_uart0_addr_lim;
  PORT_m_uart0_addr_lim = 3221225600llu;
  return PORT_m_uart0_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_uart0_addr_lim()
{
  tUInt8 PORT_RDY_m_uart0_addr_lim;
  tUInt8 DEF_CAN_FIRE_m_uart0_addr_lim;
  DEF_CAN_FIRE_m_uart0_addr_lim = (tUInt8)1u;
  PORT_RDY_m_uart0_addr_lim = DEF_CAN_FIRE_m_uart0_addr_lim;
  return PORT_RDY_m_uart0_addr_lim;
}

tUInt64 MOD_mkSoC_Map::METH_m_timer0_addr_size()
{
  tUInt64 PORT_m_timer0_addr_size;
  PORT_m_timer0_addr_size = 49152llu;
  return PORT_m_timer0_addr_size;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_timer0_addr_size()
{
  tUInt8 PORT_RDY_m_timer0_addr_size;
  tUInt8 DEF_CAN_FIRE_m_timer0_addr_size;
  DEF_CAN_FIRE_m_timer0_addr_size = (tUInt8)1u;
  PORT_RDY_m_timer0_addr_size = DEF_CAN_FIRE_m_timer0_addr_size;
  return PORT_RDY_m_timer0_addr_size;
}

tUInt64 MOD_mkSoC_Map::METH_m_timer0_addr_base()
{
  tUInt64 PORT_m_timer0_addr_base;
  PORT_m_timer0_addr_base = 33554432llu;
  return PORT_m_timer0_addr_base;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_timer0_addr_base()
{
  tUInt8 PORT_RDY_m_timer0_addr_base;
  tUInt8 DEF_CAN_FIRE_m_timer0_addr_base;
  DEF_CAN_FIRE_m_timer0_addr_base = (tUInt8)1u;
  PORT_RDY_m_timer0_addr_base = DEF_CAN_FIRE_m_timer0_addr_base;
  return PORT_RDY_m_timer0_addr_base;
}

tUInt64 MOD_mkSoC_Map::METH_m_timer0_addr_lim()
{
  tUInt64 PORT_m_timer0_addr_lim;
  PORT_m_timer0_addr_lim = 33603584llu;
  return PORT_m_timer0_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_timer0_addr_lim()
{
  tUInt8 PORT_RDY_m_timer0_addr_lim;
  tUInt8 DEF_CAN_FIRE_m_timer0_addr_lim;
  DEF_CAN_FIRE_m_timer0_addr_lim = (tUInt8)1u;
  PORT_RDY_m_timer0_addr_lim = DEF_CAN_FIRE_m_timer0_addr_lim;
  return PORT_RDY_m_timer0_addr_lim;
}

tUInt8 MOD_mkSoC_Map::METH_m_is_IO_addr(tUInt64 ARG_m_is_IO_addr_addr)
{
  tUInt8 DEF_NOT_m_is_IO_addr_addr_ULT_0x2000000_AND_m_is_I_ETC___d8;
  tUInt8 DEF_NOT_m_is_IO_addr_addr_ULT_0xC0000000_AND_m_is__ETC___d4;
  tUInt8 PORT_m_is_IO_addr;
  DEF_NOT_m_is_IO_addr_addr_ULT_0xC0000000_AND_m_is__ETC___d4 = !(ARG_m_is_IO_addr_addr < 3221225472llu) && ARG_m_is_IO_addr_addr < 3221225600llu;
  DEF_NOT_m_is_IO_addr_addr_ULT_0x2000000_AND_m_is_I_ETC___d8 = !(ARG_m_is_IO_addr_addr < 33554432llu) && ARG_m_is_IO_addr_addr < 33603584llu;
  PORT_m_is_IO_addr = DEF_NOT_m_is_IO_addr_addr_ULT_0xC0000000_AND_m_is__ETC___d4 || DEF_NOT_m_is_IO_addr_addr_ULT_0x2000000_AND_m_is_I_ETC___d8;
  return PORT_m_is_IO_addr;
}

tUInt8 MOD_mkSoC_Map::METH_RDY_m_is_IO_addr()
{
  tUInt8 PORT_RDY_m_is_IO_addr;
  tUInt8 DEF_CAN_FIRE_m_is_IO_addr;
  DEF_CAN_FIRE_m_is_IO_addr = (tUInt8)1u;
  PORT_RDY_m_is_IO_addr = DEF_CAN_FIRE_m_is_IO_addr;
  return PORT_RDY_m_is_IO_addr;
}


/* Reset routines */

void MOD_mkSoC_Map::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkSoC_Map::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkSoC_Map::dump_state(unsigned int indent)
{
}


/* VCD dumping routines */

unsigned int MOD_mkSoC_Map::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 1u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkSoC_Map::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkSoC_Map &backing)
{
  vcd_defs(dt, backing);
}

void MOD_mkSoC_Map::vcd_defs(tVCDDumpType dt, MOD_mkSoC_Map &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
    }
}
