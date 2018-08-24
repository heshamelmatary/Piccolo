/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:11:17 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkMem_Controller_h__
#define __mkMem_Controller_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkMem_Controller module */
class MOD_mkMem_Controller : public Module {
 
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
  MOD_CReg<tUWide> INST_f_raw_mem_reqs_rv;
  MOD_CReg<tUWide> INST_f_raw_mem_rsps_rv;
  MOD_CReg<tUWide> INST_f_reqs_rv;
  MOD_Fifo<tUInt8> INST_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_f_reset_rsps;
  MOD_Reg<tUInt64> INST_rg_addr_base;
  MOD_Reg<tUInt64> INST_rg_addr_lim;
  MOD_Reg<tUInt8> INST_rg_cached_clean;
  MOD_Reg<tUInt64> INST_rg_cached_raw_mem_addr;
  MOD_Reg<tUWide> INST_rg_cached_raw_mem_word;
  MOD_Reg<tUInt8> INST_rg_state;
  MOD_Fifo<tUWide> INST_slave_xactor_f_rd_addr;
  MOD_Fifo<tUWide> INST_slave_xactor_f_rd_data;
  MOD_Fifo<tUWide> INST_slave_xactor_f_wr_addr;
  MOD_Fifo<tUWide> INST_slave_xactor_f_wr_data;
  MOD_Fifo<tUInt8> INST_slave_xactor_f_wr_resp;
 
 /* Constructor */
 public:
  MOD_mkMem_Controller(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_EN_set_addr_map;
  tUWide PORT_to_raw_mem_response_put;
  tUWide PORT_to_raw_mem_request_get;
  tUInt8 PORT_slave_awready;
  tUInt8 PORT_slave_wready;
  tUInt8 PORT_slave_bvalid;
  tUInt8 PORT_slave_bresp;
  tUInt8 PORT_slave_buser;
  tUInt8 PORT_slave_arready;
  tUInt8 PORT_slave_rvalid;
  tUInt8 PORT_slave_rresp;
  tUInt64 PORT_slave_rdata;
  tUInt8 PORT_slave_ruser;
  tUInt8 PORT_RDY_slave_m_awvalid;
  tUInt8 PORT_RDY_slave_m_wvalid;
  tUInt8 PORT_RDY_slave_m_bready;
  tUInt8 PORT_RDY_slave_m_arvalid;
  tUInt8 PORT_RDY_slave_m_rready;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_set_addr_map;
  tUWide DEF_f_raw_mem_reqs_rv_port0__read____d264;
  tUInt8 DEF_rg_state__h1585;
  tUWide DEF_f_raw_mem_reqs_rv_port1__read____d17;
  tUWide DEF_f_raw_mem_rsps_rv_port1__read____d266;
  tUWide DEF_f_raw_mem_rsps_rv_port0__read____d92;
  tUWide DEF_f_reqs_rv_port1__read____d26;
  tUWide DEF_f_reqs_rv_port0__read____d52;
  tUInt64 DEF_x__h6951;
  tUInt64 DEF_addr_lim__h9422;
  tUInt64 DEF_addr_base__h9420;
  tUInt64 DEF_addr__h3171;
  tUInt8 DEF_x__h3185;
  tUInt64 DEF_req_raw_mem_addr__h2965;
  tUInt8 DEF_f_reqs_rv_port0__read__2_BITS_77_TO_75_6_EQ_0b0___d67;
  tUInt8 DEF_NOT_f_reqs_rv_port0__read__2_BITS_77_TO_75_6_E_ETC___d233;
 
 /* Local definitions */
 private:
  tUInt32 DEF_v__h9952;
  tUInt32 DEF_v__h9557;
  tUInt32 DEF_v__h9199;
  tUInt32 DEF_v__h8918;
  tUInt32 DEF_v__h8724;
  tUInt32 DEF_v__h6784;
  tUInt32 DEF_v__h3861;
  tUInt32 DEF_v__h3598;
  tUInt32 DEF_v__h3375;
  tUInt32 DEF_v__h3134;
  tUInt32 DEF_v__h2883;
  tUInt32 DEF_v__h2640;
  tUInt32 DEF_v__h2398;
  tUInt32 DEF_v__h1960;
  tUInt32 DEF_v__h1638;
  tUInt8 DEF_TASK_testplusargs___d217;
  tUWide DEF_rg_cached_raw_mem_word__h7444;
  tUWide DEF_slave_xactor_f_wr_data_first____d43;
  tUWide DEF_slave_xactor_f_rd_addr_first____d30;
  tUWide DEF_slave_xactor_f_wr_addr_first____d42;
  tUWide DEF_slave_xactor_f_rd_data_first____d262;
  tUInt8 DEF_x__h8687;
  tUInt8 DEF_slave_xactor_f_rd_data_i_notEmpty____d261;
  tUInt8 DEF_slave_xactor_f_rd_addr_i_notFull____d258;
  tUInt8 DEF_slave_xactor_f_wr_resp_i_notEmpty____d256;
  tUInt8 DEF_slave_xactor_f_wr_data_i_notFull____d253;
  tUInt8 DEF_slave_xactor_f_wr_addr_i_notFull____d250;
  tUWide DEF_raw_mem_word__h3764;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_255_TO_32___d135;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_223_TO_0___d134;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_255_TO_64___d113;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_191_TO_0___d130;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_255_TO_96___d116;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_159_TO_0___d127;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_255_TO_128___d120;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_127_TO_0___d122;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_255_TO_160___d123;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_95_TO_0___d119;
  tUInt64 DEF_rg_cached_raw_mem_word_1_BITS_255_TO_192___d128;
  tUInt64 DEF_rg_cached_raw_mem_word_1_BITS_63_TO_0___d115;
  tUInt64 DEF_value__h6865;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d138;
  tUInt8 DEF_f_reqs_rv_port0__read__2_BITS_71_TO_64___d159;
  tUInt8 DEF_f_reqs_rv_port0__read__2_BITS_74_TO_72___d158;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d126;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d137;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d118;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d125;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d133;
  tUWide DEF_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0__read__2_B_ETC___d136;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_159_TO_0_27_CONC_ETC___d129;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_191_TO_0_30_CONC_ETC___d132;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_31_TO_0_12_CONCA_ETC___d114;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_63_TO_0_15_CONCA_ETC___d117;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_95_TO_0_19_CONCA_ETC___d121;
  tUWide DEF_rg_cached_raw_mem_word_1_BITS_127_TO_0_22_CONC_ETC___d124;
  tUInt8 DEF_NOT_cfg_verbosity_read_ULE_2_2___d33;
  tUInt8 DEF_NOT_cfg_verbosity_read_ULE_1___d5;
  tUWide DEF__237684487524346268706922299392_CONCAT_DONTCARE___d22;
  tUWide DEF__17179869183_CONCAT_rg_cached_raw_mem_addr_0_CO_ETC___d62;
  tUWide DEF__12884901887_CONCAT_0_CONCAT_f_reqs_rv_port0__r_ETC___d89;
  tUWide DEF__0_CONCAT_DONTCARE___d8;
  tUWide DEF__1_CONCAT_to_raw_mem_response_put___d265;
  tUWide DEF__0_CONCAT_DONTCARE___d9;
  tUWide DEF_x__h6982;
  tUWide DEF_IF_f_reqs_rv_port0__read__2_BITS_79_TO_78_65_E_ETC___d209;
  tUWide DEF__3_CONCAT_slave_xactor_f_wr_addr_first__2_CONCA_ETC___d47;
  tUWide DEF_slave_xactor_f_wr_data_first__3_BITS_7_TO_0_4__ETC___d46;
  tUWide DEF__2_CONCAT_slave_xactor_f_rd_addr_first__0_CONCA_ETC___d31;
  tUWide DEF__0_CONCAT_DONTCARE___d155;
  tUWide DEF_slave_wdata_CONCAT_slave_wstrb___d255;
  tUWide DEF_slave_araddr_CONCAT_slave_arprot___d260;
  tUWide DEF_slave_awaddr_CONCAT_slave_awprot___d252;
  tUWide DEF__2_CONCAT_f_reqs_rv_port0__read__2_BITS_138_TO__ETC___d241;
  tUWide DEF__0_CONCAT_IF_8_MINUS_0_CONCAT_f_reqs_rv_port0___ETC___d154;
 
 /* Rules */
 public:
  void RL_rl_power_on_reset();
  void RL_rl_external_reset();
  void RL_rl_reset_reload_cache();
  void RL_rl_merge_rd_req();
  void RL_rl_merge_wr_req();
  void RL_rl_writeback_dirty_idle();
  void RL_rl_writeback_dirty();
  void RL_rl_miss_clean_req();
  void RL_rl_reload();
  void RL_rl_process_rd_req();
  void RL_rl_process_wr_req();
  void RL_rl_invalid_rd_address();
  void RL_rl_invalid_wr_address();
 
 /* Methods */
 public:
  tUInt8 METH_slave_m_buser();
  tUInt8 METH_RDY_slave_m_buser();
  tUInt8 METH_slave_m_ruser();
  tUInt8 METH_RDY_slave_m_ruser();
  void METH_server_reset_request_put(tUInt8 ARG_server_reset_request_put);
  tUInt8 METH_RDY_server_reset_request_put();
  void METH_server_reset_response_get();
  tUInt8 METH_RDY_server_reset_response_get();
  void METH_set_addr_map(tUInt64 ARG_set_addr_map_addr_base, tUInt64 ARG_set_addr_map_addr_lim);
  tUInt8 METH_RDY_set_addr_map();
  void METH_slave_m_awvalid(tUInt8 ARG_slave_awvalid,
			    tUInt64 ARG_slave_awaddr,
			    tUInt8 ARG_slave_awprot,
			    tUInt8 ARG_slave_awuser);
  tUInt8 METH_RDY_slave_m_awvalid();
  tUInt8 METH_slave_m_awready();
  tUInt8 METH_RDY_slave_m_awready();
  void METH_slave_m_wvalid(tUInt8 ARG_slave_wvalid, tUInt64 ARG_slave_wdata, tUInt8 ARG_slave_wstrb);
  tUInt8 METH_RDY_slave_m_wvalid();
  tUInt8 METH_slave_m_wready();
  tUInt8 METH_RDY_slave_m_wready();
  tUInt8 METH_slave_m_bvalid();
  tUInt8 METH_RDY_slave_m_bvalid();
  tUInt8 METH_slave_m_bresp();
  tUInt8 METH_RDY_slave_m_bresp();
  void METH_slave_m_bready(tUInt8 ARG_slave_bready);
  tUInt8 METH_RDY_slave_m_bready();
  void METH_slave_m_arvalid(tUInt8 ARG_slave_arvalid,
			    tUInt64 ARG_slave_araddr,
			    tUInt8 ARG_slave_arprot,
			    tUInt8 ARG_slave_aruser);
  tUInt8 METH_RDY_slave_m_arvalid();
  tUInt8 METH_slave_m_arready();
  tUInt8 METH_RDY_slave_m_arready();
  tUInt8 METH_slave_m_rvalid();
  tUInt8 METH_RDY_slave_m_rvalid();
  tUInt8 METH_slave_m_rresp();
  tUInt8 METH_RDY_slave_m_rresp();
  tUInt64 METH_slave_m_rdata();
  tUInt8 METH_RDY_slave_m_rdata();
  void METH_slave_m_rready(tUInt8 ARG_slave_rready);
  tUInt8 METH_RDY_slave_m_rready();
  tUWide METH_to_raw_mem_request_get();
  tUInt8 METH_RDY_to_raw_mem_request_get();
  void METH_to_raw_mem_response_put(tUWide ARG_to_raw_mem_response_put);
  tUInt8 METH_RDY_to_raw_mem_response_put();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkMem_Controller &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkMem_Controller &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkMem_Controller &backing);
};

#endif /* ifndef __mkMem_Controller_h__ */
