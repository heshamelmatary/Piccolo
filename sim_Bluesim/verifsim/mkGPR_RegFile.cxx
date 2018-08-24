/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "mkGPR_RegFile.h"


/* Constructor */
MOD_mkGPR_RegFile::MOD_mkGPR_RegFile(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_f_reset_rsps(simHdl, "f_reset_rsps", this, 0u, 2u, 1u, 0u),
    INST_regfile(simHdl, "regfile", this, 5u, 64u, (tUInt8)0u, (tUInt8)31u),
    INST_rg_j(simHdl, "rg_j", this, 5u),
    INST_rg_state(simHdl, "rg_state", this, 2u, (tUInt8)0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  PORT_EN_write_rd = false;
  symbol_count = 9u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkGPR_RegFile::init_symbols_0()
{
  init_symbol(&symbols[0u], "EN_write_rd", SYM_PORT, &PORT_EN_write_rd, 1u);
  init_symbol(&symbols[1u], "f_reset_rsps", SYM_MODULE, &INST_f_reset_rsps);
  init_symbol(&symbols[2u], "RL_rl_reset_loop", SYM_RULE);
  init_symbol(&symbols[3u], "RL_rl_reset_start", SYM_RULE);
  init_symbol(&symbols[4u], "regfile", SYM_MODULE, &INST_regfile);
  init_symbol(&symbols[5u], "rg_j", SYM_MODULE, &INST_rg_j);
  init_symbol(&symbols[6u], "rg_state", SYM_MODULE, &INST_rg_state);
  init_symbol(&symbols[7u], "rg_state__h365", SYM_DEF, &DEF_rg_state__h365, 2u);
  init_symbol(&symbols[8u], "WILL_FIRE_write_rd", SYM_DEF, &DEF_WILL_FIRE_write_rd, 1u);
}


/* Rule actions */

void MOD_mkGPR_RegFile::RL_rl_reset_start()
{
  INST_rg_state.METH_write((tUInt8)1u);
  INST_rg_j.METH_write((tUInt8)1u);
}

void MOD_mkGPR_RegFile::RL_rl_reset_loop()
{
  tUInt8 DEF_x__h442;
  tUInt8 DEF_rg_j_EQ_31___d6;
  tUInt8 DEF_i__h417;
  DEF_i__h417 = INST_rg_j.METH_read();
  DEF_rg_j_EQ_31___d6 = DEF_i__h417 == (tUInt8)31u;
  DEF_x__h442 = (tUInt8)31u & (DEF_i__h417 + (tUInt8)1u);
  INST_regfile.METH_upd(DEF_i__h417, 0llu);
  INST_rg_j.METH_write(DEF_x__h442);
  if (DEF_rg_j_EQ_31___d6)
    INST_rg_state.METH_write((tUInt8)2u);
}


/* Methods */

void MOD_mkGPR_RegFile::METH_server_reset_request_put(tUInt8 ARG_server_reset_request_put)
{
  INST_rg_state.METH_write((tUInt8)0u);
  INST_f_reset_rsps.METH_enq();
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_server_reset_request_put()
{
  tUInt8 DEF_CAN_FIRE_server_reset_request_put;
  tUInt8 PORT_RDY_server_reset_request_put;
  DEF_CAN_FIRE_server_reset_request_put = INST_f_reset_rsps.METH_i_notFull();
  PORT_RDY_server_reset_request_put = DEF_CAN_FIRE_server_reset_request_put;
  return PORT_RDY_server_reset_request_put;
}

void MOD_mkGPR_RegFile::METH_server_reset_response_get()
{
  INST_f_reset_rsps.METH_deq();
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_server_reset_response_get()
{
  tUInt8 DEF_CAN_FIRE_server_reset_response_get;
  tUInt8 PORT_RDY_server_reset_response_get;
  DEF_rg_state__h365 = INST_rg_state.METH_read();
  DEF_CAN_FIRE_server_reset_response_get = DEF_rg_state__h365 == (tUInt8)2u && INST_f_reset_rsps.METH_i_notEmpty();
  PORT_RDY_server_reset_response_get = DEF_CAN_FIRE_server_reset_response_get;
  return PORT_RDY_server_reset_response_get;
}

tUInt64 MOD_mkGPR_RegFile::METH_read_rs1(tUInt8 ARG_read_rs1_rs1)
{
  tUInt8 DEF_read_rs1_rs1_EQ_0___d9;
  tUInt64 DEF_x__h603;
  tUInt64 PORT_read_rs1;
  DEF_x__h603 = INST_regfile.METH_sub(ARG_read_rs1_rs1);
  DEF_read_rs1_rs1_EQ_0___d9 = ARG_read_rs1_rs1 == (tUInt8)0u;
  PORT_read_rs1 = DEF_read_rs1_rs1_EQ_0___d9 ? 0llu : DEF_x__h603;
  return PORT_read_rs1;
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_read_rs1()
{
  tUInt8 PORT_RDY_read_rs1;
  tUInt8 DEF_CAN_FIRE_read_rs1;
  DEF_CAN_FIRE_read_rs1 = (tUInt8)1u;
  PORT_RDY_read_rs1 = DEF_CAN_FIRE_read_rs1;
  return PORT_RDY_read_rs1;
}

tUInt64 MOD_mkGPR_RegFile::METH_read_rs1_port2(tUInt8 ARG_read_rs1_port2_rs1)
{
  tUInt8 DEF_read_rs1_port2_rs1_EQ_0___d11;
  tUInt64 DEF_x__h606;
  tUInt64 PORT_read_rs1_port2;
  DEF_x__h606 = INST_regfile.METH_sub(ARG_read_rs1_port2_rs1);
  DEF_read_rs1_port2_rs1_EQ_0___d11 = ARG_read_rs1_port2_rs1 == (tUInt8)0u;
  PORT_read_rs1_port2 = DEF_read_rs1_port2_rs1_EQ_0___d11 ? 0llu : DEF_x__h606;
  return PORT_read_rs1_port2;
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_read_rs1_port2()
{
  tUInt8 PORT_RDY_read_rs1_port2;
  tUInt8 DEF_CAN_FIRE_read_rs1_port2;
  DEF_CAN_FIRE_read_rs1_port2 = (tUInt8)1u;
  PORT_RDY_read_rs1_port2 = DEF_CAN_FIRE_read_rs1_port2;
  return PORT_RDY_read_rs1_port2;
}

tUInt64 MOD_mkGPR_RegFile::METH_read_rs2(tUInt8 ARG_read_rs2_rs2)
{
  tUInt8 DEF_read_rs2_rs2_EQ_0___d13;
  tUInt64 DEF_x__h609;
  tUInt64 PORT_read_rs2;
  DEF_x__h609 = INST_regfile.METH_sub(ARG_read_rs2_rs2);
  DEF_read_rs2_rs2_EQ_0___d13 = ARG_read_rs2_rs2 == (tUInt8)0u;
  PORT_read_rs2 = DEF_read_rs2_rs2_EQ_0___d13 ? 0llu : DEF_x__h609;
  return PORT_read_rs2;
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_read_rs2()
{
  tUInt8 PORT_RDY_read_rs2;
  tUInt8 DEF_CAN_FIRE_read_rs2;
  DEF_CAN_FIRE_read_rs2 = (tUInt8)1u;
  PORT_RDY_read_rs2 = DEF_CAN_FIRE_read_rs2;
  return PORT_RDY_read_rs2;
}

void MOD_mkGPR_RegFile::METH_write_rd(tUInt8 ARG_write_rd_rd, tUInt64 ARG_write_rd_rd_val)
{
  tUInt8 DEF_NOT_write_rd_rd_EQ_0_5___d16;
  PORT_EN_write_rd = (tUInt8)1u;
  DEF_WILL_FIRE_write_rd = (tUInt8)1u;
  DEF_NOT_write_rd_rd_EQ_0_5___d16 = !(ARG_write_rd_rd == (tUInt8)0u);
  if (DEF_NOT_write_rd_rd_EQ_0_5___d16)
    INST_regfile.METH_upd(ARG_write_rd_rd, ARG_write_rd_rd_val);
}

tUInt8 MOD_mkGPR_RegFile::METH_RDY_write_rd()
{
  tUInt8 PORT_RDY_write_rd;
  tUInt8 DEF_CAN_FIRE_write_rd;
  DEF_CAN_FIRE_write_rd = (tUInt8)1u;
  PORT_RDY_write_rd = DEF_CAN_FIRE_write_rd;
  return PORT_RDY_write_rd;
}


/* Reset routines */

void MOD_mkGPR_RegFile::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_rg_state.reset_RST(ARG_rst_in);
  INST_f_reset_rsps.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkGPR_RegFile::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkGPR_RegFile::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_f_reset_rsps.dump_state(indent + 2u);
  INST_regfile.dump_state(indent + 2u);
  INST_rg_j.dump_state(indent + 2u);
  INST_rg_state.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkGPR_RegFile::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 8u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "WILL_FIRE_write_rd", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "rg_state__h365", 2u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "EN_write_rd", 1u);
  num = INST_f_reset_rsps.dump_VCD_defs(num);
  num = INST_regfile.dump_VCD_defs(num);
  num = INST_rg_j.dump_VCD_defs(num);
  num = INST_rg_state.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkGPR_RegFile::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkGPR_RegFile &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkGPR_RegFile::vcd_defs(tVCDDumpType dt, MOD_mkGPR_RegFile &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 2u);
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
      if ((backing.DEF_WILL_FIRE_write_rd) != DEF_WILL_FIRE_write_rd)
      {
	vcd_write_val(sim_hdl, num, DEF_WILL_FIRE_write_rd, 1u);
	backing.DEF_WILL_FIRE_write_rd = DEF_WILL_FIRE_write_rd;
      }
      ++num;
      if ((backing.DEF_rg_state__h365) != DEF_rg_state__h365)
      {
	vcd_write_val(sim_hdl, num, DEF_rg_state__h365, 2u);
	backing.DEF_rg_state__h365 = DEF_rg_state__h365;
      }
      ++num;
      if ((backing.PORT_EN_write_rd) != PORT_EN_write_rd)
      {
	vcd_write_val(sim_hdl, num, PORT_EN_write_rd, 1u);
	backing.PORT_EN_write_rd = PORT_EN_write_rd;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_WILL_FIRE_write_rd, 1u);
      backing.DEF_WILL_FIRE_write_rd = DEF_WILL_FIRE_write_rd;
      vcd_write_val(sim_hdl, num++, DEF_rg_state__h365, 2u);
      backing.DEF_rg_state__h365 = DEF_rg_state__h365;
      vcd_write_val(sim_hdl, num++, PORT_EN_write_rd, 1u);
      backing.PORT_EN_write_rd = PORT_EN_write_rd;
    }
}

void MOD_mkGPR_RegFile::vcd_prims(tVCDDumpType dt, MOD_mkGPR_RegFile &backing)
{
  INST_f_reset_rsps.dump_VCD(dt, backing.INST_f_reset_rsps);
  INST_regfile.dump_VCD(dt, backing.INST_regfile);
  INST_rg_j.dump_VCD(dt, backing.INST_rg_j);
  INST_rg_state.dump_VCD(dt, backing.INST_rg_state);
}
