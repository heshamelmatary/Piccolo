/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkBRVF_Core_h__
#define __mkBRVF_Core_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkCPU.h"


/* Class declaration for the mkBRVF_Core module */
class MOD_mkBRVF_Core : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
  tUInt64 const PARAM_pc_reset_value;
 
 /* Module state */
 public:
  MOD_mkCPU INST_cpu_core;
  MOD_Fifo<tUInt8> INST_f_reset_client;
  MOD_Fifo<tUInt8> INST_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_f_reset_rsps;
 
 /* Constructor */
 public:
  MOD_mkBRVF_Core(tSimStateHdl simHdl, char const *name, Module *parent, tUInt64 ARG_pc_reset_value);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_cpu_imem_master_awvalid;
  tUInt64 PORT_cpu_imem_master_awaddr;
  tUInt8 PORT_cpu_imem_master_awprot;
  tUInt8 PORT_cpu_imem_master_awuser;
  tUInt8 PORT_cpu_imem_master_wvalid;
  tUInt64 PORT_cpu_imem_master_wdata;
  tUInt8 PORT_cpu_imem_master_wstrb;
  tUInt8 PORT_cpu_imem_master_bready;
  tUInt8 PORT_cpu_imem_master_arvalid;
  tUInt64 PORT_cpu_imem_master_araddr;
  tUInt8 PORT_cpu_imem_master_arprot;
  tUInt8 PORT_cpu_imem_master_aruser;
  tUInt8 PORT_cpu_imem_master_rready;
  tUInt8 PORT_cpu_dmem_master_awvalid;
  tUInt64 PORT_cpu_dmem_master_awaddr;
  tUInt8 PORT_cpu_dmem_master_awprot;
  tUInt8 PORT_cpu_dmem_master_awuser;
  tUInt8 PORT_cpu_dmem_master_wvalid;
  tUInt64 PORT_cpu_dmem_master_wdata;
  tUInt8 PORT_cpu_dmem_master_wstrb;
  tUInt8 PORT_cpu_dmem_master_bready;
  tUInt8 PORT_cpu_dmem_master_arvalid;
  tUInt64 PORT_cpu_dmem_master_araddr;
  tUInt8 PORT_cpu_dmem_master_arprot;
  tUInt8 PORT_cpu_dmem_master_aruser;
  tUInt8 PORT_cpu_dmem_master_rready;
  tUInt8 PORT_cpu_slave_awready;
  tUInt8 PORT_cpu_slave_wready;
  tUInt8 PORT_cpu_slave_bvalid;
  tUInt8 PORT_cpu_slave_bresp;
  tUInt8 PORT_cpu_slave_buser;
  tUInt8 PORT_cpu_slave_arready;
  tUInt8 PORT_cpu_slave_rvalid;
  tUInt8 PORT_cpu_slave_rresp;
  tUInt64 PORT_cpu_slave_rdata;
  tUInt8 PORT_cpu_slave_ruser;
  tUInt8 PORT_RDY_cpu_imem_master_m_awready;
  tUInt8 PORT_RDY_cpu_imem_master_m_wready;
  tUInt8 PORT_RDY_cpu_imem_master_m_bvalid;
  tUInt8 PORT_RDY_cpu_imem_master_m_arready;
  tUInt8 PORT_RDY_cpu_imem_master_m_rvalid;
  tUInt8 PORT_RDY_cpu_dmem_master_m_awready;
  tUInt8 PORT_RDY_cpu_dmem_master_m_wready;
  tUInt8 PORT_RDY_cpu_dmem_master_m_bvalid;
  tUInt8 PORT_RDY_cpu_dmem_master_m_arready;
  tUInt8 PORT_RDY_cpu_dmem_master_m_rvalid;
  tUInt8 PORT_RDY_cpu_slave_m_awvalid;
  tUInt8 PORT_RDY_cpu_slave_m_wvalid;
  tUInt8 PORT_RDY_cpu_slave_m_bready;
  tUInt8 PORT_RDY_cpu_slave_m_arvalid;
  tUInt8 PORT_RDY_cpu_slave_m_rready;
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
  tUWide DEF_cpu_core_to_verifier_get___d2;
  std::string DEF_IF_cpu_core_to_verifier_get_BIT_577_THEN_STR___ETC___d5;
  std::string DEF_IF_cpu_core_to_verifier_get_BIT_576_THEN_STR___ETC___d7;
 
 /* Rules */
 public:
  void RL_cpu_displayData();
  void RL_rl_cpu_hart0_reset_from_soc_start();
  void RL_rl_cpu_hart0_reset_from_cpu_complete();
 
 /* Methods */
 public:
  tUInt8 METH_cpu_imem_master_m_awuser();
  tUInt8 METH_RDY_cpu_imem_master_m_awuser();
  tUInt8 METH_cpu_imem_master_m_aruser();
  tUInt8 METH_RDY_cpu_imem_master_m_aruser();
  tUInt8 METH_cpu_dmem_master_m_awuser();
  tUInt8 METH_RDY_cpu_dmem_master_m_awuser();
  tUInt8 METH_cpu_dmem_master_m_aruser();
  tUInt8 METH_RDY_cpu_dmem_master_m_aruser();
  tUInt8 METH_cpu_slave_m_awready();
  tUInt8 METH_RDY_cpu_slave_m_awready();
  tUInt8 METH_cpu_slave_m_wready();
  tUInt8 METH_RDY_cpu_slave_m_wready();
  tUInt8 METH_cpu_slave_m_bvalid();
  tUInt8 METH_RDY_cpu_slave_m_bvalid();
  tUInt8 METH_cpu_slave_m_bresp();
  tUInt8 METH_RDY_cpu_slave_m_bresp();
  tUInt8 METH_cpu_slave_m_buser();
  tUInt8 METH_RDY_cpu_slave_m_buser();
  tUInt8 METH_cpu_slave_m_arready();
  tUInt8 METH_RDY_cpu_slave_m_arready();
  tUInt8 METH_cpu_slave_m_rvalid();
  tUInt8 METH_RDY_cpu_slave_m_rvalid();
  tUInt8 METH_cpu_slave_m_rresp();
  tUInt8 METH_RDY_cpu_slave_m_rresp();
  tUInt64 METH_cpu_slave_m_rdata();
  tUInt8 METH_RDY_cpu_slave_m_rdata();
  tUInt8 METH_cpu_slave_m_ruser();
  tUInt8 METH_RDY_cpu_slave_m_ruser();
  void METH_cpu_reset_server_request_put(tUInt8 ARG_cpu_reset_server_request_put);
  tUInt8 METH_RDY_cpu_reset_server_request_put();
  void METH_cpu_reset_server_response_get();
  tUInt8 METH_RDY_cpu_reset_server_response_get();
  tUInt8 METH_cpu_imem_master_m_awvalid();
  tUInt8 METH_RDY_cpu_imem_master_m_awvalid();
  tUInt64 METH_cpu_imem_master_m_awaddr();
  tUInt8 METH_RDY_cpu_imem_master_m_awaddr();
  tUInt8 METH_cpu_imem_master_m_awprot();
  tUInt8 METH_RDY_cpu_imem_master_m_awprot();
  void METH_cpu_imem_master_m_awready(tUInt8 ARG_cpu_imem_master_awready);
  tUInt8 METH_RDY_cpu_imem_master_m_awready();
  tUInt8 METH_cpu_imem_master_m_wvalid();
  tUInt8 METH_RDY_cpu_imem_master_m_wvalid();
  tUInt64 METH_cpu_imem_master_m_wdata();
  tUInt8 METH_RDY_cpu_imem_master_m_wdata();
  tUInt8 METH_cpu_imem_master_m_wstrb();
  tUInt8 METH_RDY_cpu_imem_master_m_wstrb();
  void METH_cpu_imem_master_m_wready(tUInt8 ARG_cpu_imem_master_wready);
  tUInt8 METH_RDY_cpu_imem_master_m_wready();
  void METH_cpu_imem_master_m_bvalid(tUInt8 ARG_cpu_imem_master_bvalid,
				     tUInt8 ARG_cpu_imem_master_bresp,
				     tUInt8 ARG_cpu_imem_master_buser);
  tUInt8 METH_RDY_cpu_imem_master_m_bvalid();
  tUInt8 METH_cpu_imem_master_m_bready();
  tUInt8 METH_RDY_cpu_imem_master_m_bready();
  tUInt8 METH_cpu_imem_master_m_arvalid();
  tUInt8 METH_RDY_cpu_imem_master_m_arvalid();
  tUInt64 METH_cpu_imem_master_m_araddr();
  tUInt8 METH_RDY_cpu_imem_master_m_araddr();
  tUInt8 METH_cpu_imem_master_m_arprot();
  tUInt8 METH_RDY_cpu_imem_master_m_arprot();
  void METH_cpu_imem_master_m_arready(tUInt8 ARG_cpu_imem_master_arready);
  tUInt8 METH_RDY_cpu_imem_master_m_arready();
  void METH_cpu_imem_master_m_rvalid(tUInt8 ARG_cpu_imem_master_rvalid,
				     tUInt8 ARG_cpu_imem_master_rresp,
				     tUInt64 ARG_cpu_imem_master_rdata,
				     tUInt8 ARG_cpu_imem_master_ruser);
  tUInt8 METH_RDY_cpu_imem_master_m_rvalid();
  tUInt8 METH_cpu_imem_master_m_rready();
  tUInt8 METH_RDY_cpu_imem_master_m_rready();
  tUInt8 METH_cpu_dmem_master_m_awvalid();
  tUInt8 METH_RDY_cpu_dmem_master_m_awvalid();
  tUInt64 METH_cpu_dmem_master_m_awaddr();
  tUInt8 METH_RDY_cpu_dmem_master_m_awaddr();
  tUInt8 METH_cpu_dmem_master_m_awprot();
  tUInt8 METH_RDY_cpu_dmem_master_m_awprot();
  void METH_cpu_dmem_master_m_awready(tUInt8 ARG_cpu_dmem_master_awready);
  tUInt8 METH_RDY_cpu_dmem_master_m_awready();
  tUInt8 METH_cpu_dmem_master_m_wvalid();
  tUInt8 METH_RDY_cpu_dmem_master_m_wvalid();
  tUInt64 METH_cpu_dmem_master_m_wdata();
  tUInt8 METH_RDY_cpu_dmem_master_m_wdata();
  tUInt8 METH_cpu_dmem_master_m_wstrb();
  tUInt8 METH_RDY_cpu_dmem_master_m_wstrb();
  void METH_cpu_dmem_master_m_wready(tUInt8 ARG_cpu_dmem_master_wready);
  tUInt8 METH_RDY_cpu_dmem_master_m_wready();
  void METH_cpu_dmem_master_m_bvalid(tUInt8 ARG_cpu_dmem_master_bvalid,
				     tUInt8 ARG_cpu_dmem_master_bresp,
				     tUInt8 ARG_cpu_dmem_master_buser);
  tUInt8 METH_RDY_cpu_dmem_master_m_bvalid();
  tUInt8 METH_cpu_dmem_master_m_bready();
  tUInt8 METH_RDY_cpu_dmem_master_m_bready();
  tUInt8 METH_cpu_dmem_master_m_arvalid();
  tUInt8 METH_RDY_cpu_dmem_master_m_arvalid();
  tUInt64 METH_cpu_dmem_master_m_araddr();
  tUInt8 METH_RDY_cpu_dmem_master_m_araddr();
  tUInt8 METH_cpu_dmem_master_m_arprot();
  tUInt8 METH_RDY_cpu_dmem_master_m_arprot();
  void METH_cpu_dmem_master_m_arready(tUInt8 ARG_cpu_dmem_master_arready);
  tUInt8 METH_RDY_cpu_dmem_master_m_arready();
  void METH_cpu_dmem_master_m_rvalid(tUInt8 ARG_cpu_dmem_master_rvalid,
				     tUInt8 ARG_cpu_dmem_master_rresp,
				     tUInt64 ARG_cpu_dmem_master_rdata,
				     tUInt8 ARG_cpu_dmem_master_ruser);
  tUInt8 METH_RDY_cpu_dmem_master_m_rvalid();
  tUInt8 METH_cpu_dmem_master_m_rready();
  tUInt8 METH_RDY_cpu_dmem_master_m_rready();
  void METH_cpu_slave_m_awvalid(tUInt8 ARG_cpu_slave_awvalid,
				tUInt64 ARG_cpu_slave_awaddr,
				tUInt8 ARG_cpu_slave_awprot,
				tUInt8 ARG_cpu_slave_awuser);
  tUInt8 METH_RDY_cpu_slave_m_awvalid();
  void METH_cpu_slave_m_wvalid(tUInt8 ARG_cpu_slave_wvalid,
			       tUInt64 ARG_cpu_slave_wdata,
			       tUInt8 ARG_cpu_slave_wstrb);
  tUInt8 METH_RDY_cpu_slave_m_wvalid();
  void METH_cpu_slave_m_bready(tUInt8 ARG_cpu_slave_bready);
  tUInt8 METH_RDY_cpu_slave_m_bready();
  void METH_cpu_slave_m_arvalid(tUInt8 ARG_cpu_slave_arvalid,
				tUInt64 ARG_cpu_slave_araddr,
				tUInt8 ARG_cpu_slave_arprot,
				tUInt8 ARG_cpu_slave_aruser);
  tUInt8 METH_RDY_cpu_slave_m_arvalid();
  void METH_cpu_slave_m_rready(tUInt8 ARG_cpu_slave_rready);
  tUInt8 METH_RDY_cpu_slave_m_rready();
  void METH_cpu_external_interrupt_req();
  tUInt8 METH_RDY_cpu_external_interrupt_req();
  void METH_cpu_software_interrupt_req();
  tUInt8 METH_RDY_cpu_software_interrupt_req();
  void METH_cpu_timer_interrupt_req(tUInt8 ARG_cpu_timer_interrupt_req_set_not_clear);
  tUInt8 METH_RDY_cpu_timer_interrupt_req();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkBRVF_Core &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkBRVF_Core &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkBRVF_Core &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkBRVF_Core &backing);
};

#endif /* ifndef __mkBRVF_Core_h__ */
