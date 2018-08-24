/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkCPU_h__
#define __mkCPU_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkCSR_RegFile.h"
#include "mkGPR_RegFile.h"
#include "mkNear_Mem.h"
#include "mkRISCV_MBox.h"


/* Class declaration for the mkCPU module */
class MOD_mkCPU : public Module {
 
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
  MOD_ConfigReg<tUInt64> INST_cfg_logdelay;
  MOD_ConfigReg<tUInt8> INST_cfg_verbosity;
  MOD_mkCSR_RegFile INST_csr_regfile;
  MOD_Fifo<tUInt8> INST_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_f_reset_rsps;
  MOD_Fifo<tUWide> INST_f_to_verifier;
  MOD_mkGPR_RegFile INST_gpr_regfile;
  MOD_mkNear_Mem INST_near_mem;
  MOD_Reg<tUInt8> INST_rg_cur_priv;
  MOD_Reg<tUInt8> INST_rg_donehalt;
  MOD_Reg<tUInt8> INST_rg_halt;
  MOD_Reg<tUInt8> INST_rg_handler;
  MOD_Reg<tUInt64> INST_rg_inum;
  MOD_Reg<tUInt64> INST_rg_start_CPI_cycles;
  MOD_Reg<tUInt64> INST_rg_start_CPI_instrs;
  MOD_Reg<tUInt8> INST_rg_state;
  MOD_Fifo<tUInt8> INST_stage1_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_stage1_f_reset_rsps;
  MOD_Reg<tUInt8> INST_stage1_rg_full;
  MOD_Reg<tUInt8> INST_stage1_rg_run_state;
  MOD_Fifo<tUInt8> INST_stage2_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_stage2_f_reset_rsps;
  MOD_mkRISCV_MBox INST_stage2_mbox;
  MOD_Reg<tUInt8> INST_stage2_rg_f5;
  MOD_Reg<tUInt8> INST_stage2_rg_full;
  MOD_Reg<tUInt8> INST_stage2_rg_run_state;
  MOD_Reg<tUWide> INST_stage2_rg_stage2;
  MOD_Fifo<tUInt8> INST_stage3_f_reset_reqs;
  MOD_Fifo<tUInt8> INST_stage3_f_reset_rsps;
  MOD_Reg<tUInt8> INST_stage3_rg_full;
  MOD_Reg<tUInt8> INST_stage3_rg_run_state;
  MOD_Reg<tUWide> INST_stage3_rg_stage3;
 
 /* Constructor */
 public:
  MOD_mkCPU(tSimStateHdl simHdl, char const *name, Module *parent, tUInt64 ARG_pc_reset_value);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
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
  tUWide PORT_to_verifier_get;
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
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_ETC___d279;
  tUInt8 DEF_cur_verbosity__h1247;
  tUInt8 DEF_stage2_rg_full__h4635;
  tUInt8 DEF_stage3_rg_stage3_8_BIT_658___d49;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d462;
  tUInt8 DEF_near_mem_imem_valid____d176;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d553;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d474;
  tUInt8 DEF_stage1_rg_full___d174;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_31_TO_20_94_E_ETC___d515;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_0b_ETC___d511;
  tUInt8 DEF_csr_regfile_read_csr_near_mem_imem_instr__78_B_ETC___d354;
  tUInt8 DEF_csr_regfile_interrupt_pending_rg_cur_priv_7_02_ETC___d1024;
  tUInt8 DEF_stage3_rg_full__h12559;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d112;
  tUInt8 DEF_NOT_near_mem_imem_valid__76_77_OR_IF_stage2_rg_ETC___d1043;
  tUInt8 DEF_near_mem_imem_exc__87_OR_IF_near_mem_imem_inst_ETC___d448;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d446;
  tUInt8 DEF_rg_cur_priv_7_ULT_near_mem_imem_instr__78_BITS_ETC___d200;
  tUInt8 DEF_rg_halt__h10629;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d180;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d211;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d182;
  tUInt8 DEF_stage2_rg_stage2_6_BITS_696_TO_694___d57;
  tUInt8 DEF_NOT_near_mem_imem_valid__76_77_OR_IF_stage2_rg_ETC___d185;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d75;
  tUInt8 DEF_near_mem_dmem_exc____d63;
  tUInt8 DEF_NOT_stage3_rg_full_6___d47;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d552;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d236;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d459;
  tUInt8 DEF_x__h5937;
  tUInt32 DEF_near_mem_imem_instr__78_BITS_31_TO_20___d194;
  tUInt8 DEF_priv__h19202;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d220;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12___d190;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b10_ETC___d480;
  tUInt8 DEF_NOT_rg_cur_priv_7_ULT_near_mem_imem_instr__78__ETC___d452;
  tUInt8 DEF_x__h6203;
  tUInt8 DEF_NOT_csr_regfile_read_csr_near_mem_imem_instr___ETC___d355;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_13_TO_12_90_E_ETC___d357;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_0x_ETC___d360;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d482;
  tUInt8 DEF_funct3__h5836;
  tUInt8 DEF_rg_cur_priv_7_EQ_0b11_70_OR_rg_cur_priv_7_EQ_0_ETC___d573;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25___d285;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_11_TO_7_68_EQ_0_6_ETC___d576;
  tUInt8 DEF_near_mem_imem_pc__23_PLUS_SEXT_near_mem_imem_i_ETC___d422;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d424;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d251;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_ETC___d430;
  tUInt8 DEF_NOT_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stag_ETC___d85;
  tUInt8 DEF_near_mem_imem_exc__87_OR_IF_near_mem_imem_inst_ETC___d221;
  tUInt8 DEF_x__h6210;
  tUInt8 DEF_shamt__h6023;
  tUInt8 DEF_near_mem_imem_exc____d187;
  tUInt8 DEF_NOT_stage1_rg_full_74___d175;
  tUWide DEF_stage2_rg_stage2___d56;
  tUWide DEF_stage3_rg_stage3___d48;
  tUWide DEF_csr_regfile_read_csr_near_mem_imem_instr__78_B_ETC___d353;
  tUInt64 DEF_output_stage2___1_data_to_stage3_rd_val__h4951;
  tUInt64 DEF__read__h1246;
  tUInt64 DEF_near_mem_imem_pc____d223;
  tUInt64 DEF_output_stage2___1_data_to_stage3_rd_val__h4931;
  tUInt64 DEF_csr_regfile_read_mstatus____d28;
  tUInt64 DEF_x__h10510;
  tUInt64 DEF_rs2_val__h5339;
  tUInt64 DEF_rs1_val__h5333;
  tUInt32 DEF_near_mem_imem_instr____d178;
  tUInt8 DEF_csr_regfile_interrupt_pending_rg_cur_priv_7___d1023;
  tUInt8 DEF__read__h1213;
  tUInt8 DEF_csr_regfile_read_csr_mcounteren____d201;
  tUInt8 DEF_stage2_mbox_valid____d69;
  tUInt8 DEF_near_mem_dmem_valid____d62;
  tUInt64 DEF_output_stage2___1_bypass_rd_val__h4752;
  tUInt64 DEF__read_rd_val__h4517;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_ETC___d442;
  tUInt64 DEF_near_mem_imem_pc__23_PLUS_SEXT_near_mem_imem_i_ETC___d438;
  tUInt64 DEF_rs2_val_bypassed__h5343;
  tUInt64 DEF_rs1_val_bypassed__h5337;
  tUInt8 DEF_output_stage2___1_bypass_rd__h4751;
  tUInt8 DEF__read_rd__h4516;
  tUInt8 DEF_funct5__h6363;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_ETC___d443;
  tUInt8 DEF_near_mem_imem_pc__23_PLUS_SEXT_near_mem_imem_i_ETC___d439;
  tUInt64 DEF_branch_target__h5833;
  tUInt8 DEF_ms_tsr__h3229;
  tUInt8 DEF_ms_tw__h3230;
  tUInt8 DEF_ms_tvm__h3231;
  tUInt8 DEF_near_mem_imem_instr__78_BIT_31___d414;
  tUInt8 DEF_near_mem_imem_instr__78_BIT_30___d300;
  tUInt8 DEF_near_mem_imem_instr__78_BIT_25___d316;
  tUInt8 DEF_csr_regfile_read_csr_mcounteren__01_BIT_2___d205;
  tUInt8 DEF_csr_regfile_read_csr_mcounteren__01_BIT_0___d202;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d233;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_11_TO_7_68_EQ_0___d569;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d491;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d483;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d484;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d281;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d282;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b10111___d338;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d336;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_CONCA_ETC___d328;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_CONCA_ETC___d326;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_CONCA_ETC___d324;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_CONCA_ETC___d322;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b11___d308;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b10___d306;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b10011___d292;
  tUInt64 DEF_SEXT_near_mem_imem_instr__78_BITS_31_TO_20_94___d441;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d289;
  tUInt64 DEF_val__h5439;
  tUInt64 DEF_x_out_bypass_rd_val__h4766;
  tUInt64 DEF_rd_val__h5437;
  tUInt64 DEF_val__h5379;
  tUInt64 DEF_rd_val__h5377;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b110___d243;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b100___d239;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b1___d237;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b0___d235;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_0b1___d212;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_0___d213;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d189;
  tUInt64 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d93;
  tUInt64 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_3_8_ETC___d90;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d82;
  tUInt8 DEF_x_out_bypass_rd__h4765;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_3_8_ETC___d80;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_11_TO_7_68_EQ_0_6_ETC___d577;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_ETC___d598;
  tUInt8 DEF_rg_cur_priv_7_EQ_0b1___d571;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d530;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d616;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d351;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d347;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_31_TO_25_85_C_ETC___d335;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d320;
  tUInt8 DEF_IF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_3_ETC___d561;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d314;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d620;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b1111___d352;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_ETC___d567;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b10_ETC___d364;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d622;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d647;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d643;
  tUInt8 DEF_IF_near_mem_dmem_valid__2_THEN_IF_near_mem_dme_ETC___d109;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_3_8_ETC___d71;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d111;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d74;
  tUInt8 DEF_IF_near_mem_dmem_valid__2_AND_NOT_near_mem_dme_ETC___d66;
  tUInt8 DEF_near_mem_dmem_valid__2_AND_NOT_near_mem_dmem_e_ETC___d65;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_19_TO_15_79_E_ETC___d214;
  tUInt8 DEF_NOT_rg_cur_priv_7_ULT_near_mem_imem_instr__78__ETC___d458;
  tUInt8 DEF_rg_cur_priv_7_ULT_near_mem_imem_instr__78_BITS_ETC___d209;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d539;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d489;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d409;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d535;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d405;
  tUInt8 DEF_NOT_IF_near_mem_imem_instr__78_BITS_19_TO_15_7_ETC___d273;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_ETC___d272;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b101___d241;
  tUInt8 DEF_NOT_IF_near_mem_imem_instr__78_BITS_19_TO_15_7_ETC___d271;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_ETC___d270;
  tUInt8 DEF_NOT_IF_near_mem_imem_instr__78_BITS_19_TO_15_7_ETC___d269;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_19_TO_15_79_EQ_ETC___d268;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d198;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_0xB02___d196;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_0xB00___d195;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_0x180___d359;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_CONCA_ETC___d330;
  tUInt32 DEF_funct10__h6046;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_EQ_0b_ETC___d575;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_25_85_EQ_0b1___d286;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d283;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d396;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d390;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d393;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d387;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d378;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b_ETC___d381;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b100___d384;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b11___d369;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b10___d367;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b1___d375;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_27_66_EQ_0b0___d372;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d655;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d651;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d639;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d635;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d631;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b111___d245;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_30_17_EQ_0b11___d218;
  tUInt8 DEF_rg_cur_priv_7_EQ_0b11___d570;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_0b0___d191;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d115;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1027;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d113;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d252;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d84;
  tUInt8 DEF_NOT_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stag_ETC___d116;
  tUInt8 DEF_NOT_rg_halt_041___d1042;
  tUInt8 DEF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_imem__ETC___d1044;
  tUInt8 DEF_NOT_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stag_ETC___d1028;
  tUInt8 DEF_NOT_csr_regfile_read_mstatus__8_BIT_20_2___d514;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_31_TO_30_17_E_ETC___d466;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d460;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_13_TO_12_90_E_ETC___d464;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d440;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_31_TO_25_85_E_ETC___d287;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d304;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d284;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d246;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d301;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d238;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d242;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_14_TO_12_34_EQ_0b_ETC___d470;
  tUInt8 DEF_NOT_near_mem_imem_exc__87_51_AND_IF_near_mem_i_ETC___d554;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_0b_ETC___d215;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_0x_ETC___d197;
  tUInt8 DEF_NOT_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stag_ETC___d118;
  tUInt8 DEF_stage1_rg_full_74_AND_near_mem_imem_valid__76__ETC___d450;
  tUInt8 DEF_NOT_IF_csr_regfile_read_csr_minstret__0_ULT_cf_ETC___d16;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ__ETC___d476;
  tUInt8 DEF_NOT_near_mem_imem_exc__87___d451;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_13_TO_12_90_E_ETC___d463;
  tUInt8 DEF_near_mem_imem_valid__76_AND_NOT_IF_stage2_rg_f_ETC___d232;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d309;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d307;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d244;
  tUInt8 DEF_stage3_rg_full_6_AND_stage3_rg_stage3_8_BIT_658_9___d52;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d240;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_14_TO_12_34_E_ETC___d247;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BIT_25_16___d490;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d193;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_13_TO_12_90_E_ETC___d192;
 
 /* Local definitions */
 private:
  tUInt8 DEF_rg_donehalt__h12202;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d154;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d149;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_stage2_rg_stage2_6_BI_ETC___d135;
  tUInt8 DEF_IF_stage2_rg_full_5_THEN_NOT_stage2_rg_stage2__ETC___d128;
  tUInt8 DEF_ms_mprv__h3234;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_0b_ETC___d759;
  tUInt8 DEF_NOT_stage2_rg_f5_068_EQ_0b11_069___d1070;
  tUInt8 DEF__read__h2072;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d695;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0b11_ETC___d682;
  tUInt32 DEF_v__h19248;
  tUInt32 DEF_v__h18868;
  tUInt32 DEF_v__h18661;
  tUInt32 DEF_v__h16795;
  tUInt32 DEF_v__h16109;
  tUInt32 DEF_v__h15360;
  tUInt32 DEF_v__h9822;
  tUInt32 DEF_v__h3164;
  tUInt8 DEF_TASK_testplusargs___d997;
  tUInt8 DEF_TASK_testplusargs___d998;
  tUWide DEF_ab__h18961;
  tUWide DEF_ab__h14680;
  tUInt64 DEF_inum__h19201;
  tUInt64 DEF_satp__h19050;
  tUInt64 DEF_x__h10483;
  tUInt8 DEF_x_imem_exc_code__h5366;
  tUInt8 DEF_trap_info_dmem_exc_code__h5153;
  tUInt8 DEF_rg_handler__h12256;
  tUWide DEF_stage2_rg_stage2_6_BITS_495_TO_0___d1066;
  tUInt64 DEF_output_stage2___1_data_to_stage3_pc__h4916;
  tUInt64 DEF_trap_info_dmem_badaddr__h5154;
  tUInt64 DEF_output_stage2___1_data_to_stage3_csr_val__h4924;
  tUInt64 DEF__read_wolf_info_s1_rs1_data__h11171;
  tUInt64 DEF__read_wolf_info_s1_rs2_data__h11172;
  tUInt64 DEF__read_wolf_info_s1_pc_wdata__h11174;
  tUInt64 DEF__read_wolf_info_s1_mem_wdata__h11175;
  tUInt64 DEF__read_wolf_info_s1_mem_addr__h11179;
  tUInt64 DEF_next_pc__h19000;
  tUInt64 DEF_new_mstatus__h19002;
  tUInt64 DEF_mcause__h18089;
  tUWide DEF_csr_regfile_read_csr_mcycle__026_MINUS_rg_star_ETC___d1360;
  tUInt32 DEF_output_stage2___1_data_to_stage3_instr__h4917;
  tUInt32 DEF_x__h8482;
  tUInt32 DEF_rs2_val__h6043;
  tUInt32 DEF_tmp__h8509;
  tUInt32 DEF_decoded_instr_imm20_U__h5398;
  tUInt32 DEF_output_stage2___1_data_to_stage3_csr__h4923;
  tUInt64 DEF_fv_out_data_to_stage2_addr__h5772;
  tUInt64 DEF_csr_val__h6343;
  tUInt64 DEF_fv_out_data_to_stage2_val1__h5773;
  tUInt32 DEF_fv_out_data_to_stage2_instr__h5768;
  tUInt8 DEF_rs2_val_BITS_5_TO_0___h8363;
  tUInt8 DEF__read_wolf_info_s1_rs1_addr__h11169;
  tUInt8 DEF__read_wolf_info_s1_rs2_addr__h11170;
  tUInt8 DEF_x__h8705;
  tUInt8 DEF_f3__h11318;
  tUInt8 DEF_addr_lsbs__h11321;
  tUInt8 DEF_output_stage2___1_data_to_stage3_priv__h4918;
  tUInt8 DEF_new_priv__h19003;
  tUInt8 DEF_mpp__h8935;
  tUInt8 DEF_mem_priv___1__h13020;
  tUInt8 DEF_stage2_rg_stage2_6_BIT_688___d146;
  tUInt8 DEF_sstatus_SUM__h18135;
  tUInt8 DEF_mstatus_MXR__h18136;
  tUInt8 DEF_IF_near_mem_imem_exc__87_THEN_near_mem_imem_ex_ETC___d959;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1132;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1131;
  tUWide DEF_IF_near_mem_imem_exc__87_OR_IF_near_mem_imem_i_ETC___d1228;
  tUWide DEF_near_mem_imem_instr__78_CONCAT_near_mem_imem_i_ETC___d1227;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1067;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1179;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1178;
  tUWide DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d1222;
  tUWide DEF__0_CONCAT_IF_IF_near_mem_imem_instr__78_BITS_14_ETC___d1220;
  tUWide DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d1221;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1177;
  tUInt8 DEF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0___d58;
  tUWide DEF__0_CONCAT_stage2_rg_stage2_6_BITS_623_TO_560_7___d1169;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_1_9_ETC___d1170;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_2_7_ETC___d1175;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_2_7_ETC___d1174;
  tUInt8 DEF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_2___d67;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_711_TO_709_073_EQ_0_ETC___d1171;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_3_8_ETC___d1173;
  tUWide DEF__0_CONCAT_stage2_mbox_word__9___d1172;
  tUInt64 DEF_x__h12269;
  tUInt64 DEF_x_out_data_to_stage3_rd_val__h4974;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d977;
  tUInt64 DEF_csr_val___1__h8940;
  tUInt64 DEF_rs1_val__h6338;
  tUInt64 DEF_rd_val___1__h7143;
  tUInt64 DEF_rd_val___1__h7136;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_2___d742;
  tUInt64 DEF_csr_val__h8290;
  tUInt8 DEF_near_mem_imem_instr__78_BITS_13_TO_12_90_EQ_3___d743;
  tUInt64 DEF_csr_val__h8295;
  tUInt64 DEF_csr_val__h6337;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d904;
  tUInt64 DEF_data_to_stage2_addr__h5761;
  tUInt64 DEF_ret_pc__h5857;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d867;
  tUInt64 DEF_rd_val__h6339;
  tUInt64 DEF_next_pc__h5700;
  tUInt64 DEF_alu_outputs___1_val1__h5981;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d865;
  tUInt64 DEF_alu_outputs___1_val2__h6359;
  tUInt64 DEF_alu_outputs___1_val1__h6358;
  tUInt64 DEF_alu_outputs___1_addr__h6357;
  tUInt64 DEF_alu_outputs_addr__h7545;
  tUInt64 DEF__theResult___fst__h7245;
  tUInt64 DEF__theResult___fst__h7238;
  tUInt64 DEF_rd_val___1__h8510;
  tUInt64 DEF_alu_outputs___1_val1__h6017;
  tUInt64 DEF_rd_val___1__h7121;
  tUInt64 DEF__theResult_____1_fst__h7133;
  tUInt64 DEF_rd_val___1__h7129;
  tUInt64 DEF__theResult_____1_fst__h7140;
  tUInt64 DEF_alu_outputs___1_addr__h5851;
  tUInt64 DEF_data_to_stage2_val1__h5762;
  tUInt64 DEF_data_to_stage2_val2__h5763;
  tUInt64 DEF_alu_outputs___1_addr__h5869;
  tUInt64 DEF_alu_outputs___1_addr__h5891;
  tUInt64 DEF_alu_outputs___1_val1__h6038;
  tUInt64 DEF_alu_outputs___1_addr__h6122;
  tUInt64 DEF_alu_outputs___1_val1__h6377;
  tUInt64 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d783;
  tUInt64 DEF_rd_val__h6079;
  tUInt64 DEF_rd_val__h6065;
  tUInt64 DEF__theResult___fst__h7345;
  tUInt64 DEF_rd_val___1__h8789;
  tUInt64 DEF_rd_val___1__h8744;
  tUInt64 DEF_rd_val___1__h8699;
  tUInt64 DEF_rd_val___1__h8693;
  tUInt64 DEF_alu_outputs___1_val1__h6059;
  tUInt64 DEF_rd_val___1__h8645;
  tUInt64 DEF_rd_val__h8420;
  tUInt64 DEF_rd_val__h8398;
  tUInt64 DEF_rd_val___1__h8593;
  tUInt64 DEF_rd_val___1__h8564;
  tUInt64 DEF__theResult___snd__h8450;
  tUInt64 DEF__theResult_____1_fst__h7168;
  tUInt64 DEF_rd_val___1__h7164;
  tUInt64 DEF_rd_val___1__h7157;
  tUInt64 DEF_rd_val___1__h7150;
  tUInt64 DEF_rd_val__h8346;
  tUInt64 DEF_rd_val___1__h8479;
  tUInt64 DEF_fv_out_next_pc__h5715;
  tUInt64 DEF_fv_out_data_to_stage2_val2__h5774;
  tUInt64 DEF_fv_out_data_to_stage2_pc__h5767;
  tUInt64 DEF_x__h15086;
  tUInt64 DEF_x__h15085;
  tUInt64 DEF_value__h7957;
  tUInt64 DEF_value__h7898;
  tUInt64 DEF_value__h5136;
  tUInt64 DEF_value__h5189;
  tUInt64 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d162;
  tUInt64 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d99;
  tUInt64 DEF_x__h12267;
  tUInt64 DEF_x__h12266;
  tUInt64 DEF_x__h12264;
  tUInt64 DEF_x__h12263;
  tUInt64 DEF_x_out_data_to_stage3_csr_val__h4977;
  tUInt64 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d144;
  tUInt64 DEF_x_out_data_to_stage3_pc__h4969;
  tUInt32 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d102;
  tUInt32 DEF_x_out_data_to_stage3_instr__h4970;
  tUInt32 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d159;
  tUInt32 DEF_x_out_data_to_stage3_csr__h4976;
  tUInt8 DEF_output_stage2___1_data_to_stage3_wolf_info_s2_mem_wmask__h11126;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_711_TO_709_073_EQ_0_ETC___d1111;
  tUInt8 DEF_output_stage2___1_data_to_stage3_wolf_info_s2_mem_rmask__h11125;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_626_TO_624_077_EQ_0_ETC___d1093;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_626_TO_624_077_EQ_0_ETC___d1100;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_626_TO_624_077_EQ_0_ETC___d1105;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_2_7_ETC___d1121;
  tUInt8 DEF_shamt__h5967;
  tUInt8 DEF_alu_outputs___1_rd__h6355;
  tUInt8 DEF_data_to_stage2_rd__h5759;
  tUInt8 DEF_fv_out_data_to_stage2_rd__h5770;
  tUInt8 DEF_x__h15083;
  tUInt8 DEF_x__h15084;
  tUInt8 DEF_x__h12268;
  tUInt8 DEF_x_out_data_to_stage3_rd__h4973;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d140;
  tUInt8 DEF_x__h12260;
  tUInt8 DEF_x__h12259;
  tUInt8 DEF_IF_rg_cur_priv_7_EQ_0b0_47_THEN_8_ELSE_IF_rg_c_ETC___d949;
  tUInt8 DEF_alu_outputs_exc_code__h6396;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_31_TO_20_94_EQ_ETC___d951;
  tUInt8 DEF_alu_outputs___1_exc_code__h6353;
  tUInt8 DEF_fv_out_trap_info_exc_code__h7911;
  tUInt8 DEF_x_out_trap_info_exc_code__h5169;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d694;
  tUInt8 DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d692;
  tUInt8 DEF_fv_out_data_to_stage2_priv__h5766;
  tUInt8 DEF_spliced_bits__h8988;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d704;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d700;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d105;
  tUInt8 DEF_x_out_data_to_stage3_priv__h4971;
  tUInt8 DEF_NOT_near_mem_imem_instr__78_BITS_13_TO_12_90_E_ETC___d736;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_1_9_ETC___d126;
  tUInt8 DEF_NOT_near_mem_dmem_valid__2_22_OR_near_mem_dmem_ETC___d123;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_1_9_ETC___d133;
  tUInt8 DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d153;
  tUInt8 DEF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_OR_ETC___d134;
  tUInt8 DEF_IF_csr_regfile_read_csr_minstret__0_ULT_cfg_lo_ETC___d1188;
  tUInt8 DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d708;
  tUInt8 DEF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_4___d60;
  tUInt8 DEF_rg_donehalt_142_OR_IF_stage2_rg_full_5_THEN_IF_ETC___d1144;
  tUInt8 DEF_rg_donehalt_142_OR_IF_NOT_stage1_rg_full_74_75_ETC___d1306;
  tUInt8 DEF_csr_regfile_interrupt_pending_rg_cur_priv_7_02_ETC___d1025;
  tUInt8 DEF_stage1_rg_full_74_AND_near_mem_imem_valid__76__ETC___d556;
  tUInt8 DEF_near_mem_imem_valid__76_AND_NOT_IF_stage2_rg_f_ETC___d555;
  tUInt8 DEF_NOT_IF_csr_regfile_read_csr_minstret__0_ULT_cf_ETC___d1002;
  tUInt32 DEF_v32__h6063;
  tUInt32 DEF_x__h8747;
  tUInt32 DEF_x__h8702;
  tUInt32 DEF_x__h8567;
  tUInt32 DEF_tmp__h8592;
  tUInt32 DEF_x__h8513;
  tUInt64 DEF_y__h9074;
  tUInt64 DEF_x__h18604;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1233;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1232;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1130;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1231;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1230;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1229;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1129;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1128;
  tUWide DEF_rg_inum_6_CONCAT_1_CONCAT_rg_donehalt_142_OR_I_ETC___d1290;
  tUWide DEF_rg_donehalt_142_OR_IF_stage2_rg_full_5_THEN_IF_ETC___d1185;
  tUWide DEF_rg_inum_6_CONCAT_0_CONCAT_rg_donehalt_142_OR_I_ETC___d1186;
  tUWide DEF_rg_inum_6_CONCAT_0_CONCAT_rg_donehalt_142_OR_I_ETC___d1317;
  tUWide DEF_rg_donehalt_142_OR_IF_NOT_stage1_rg_full_74_75_ETC___d1316;
  tUWide DEF_rg_inum_6_CONCAT_NOT_IF_near_mem_imem_exc__87__ETC___d1354;
  tUWide DEF_IF_stage2_rg_stage2_6_BITS_696_TO_694_7_EQ_0_8_ETC___d1127;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1184;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1315;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1183;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1314;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1182;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1313;
  tUWide DEF_gpr_regfile_read_rs1_near_mem_imem_instr__78_B_ETC___d1226;
  tUWide DEF_IF_stage2_rg_full_5_THEN_IF_stage2_rg_stage2_6_ETC___d1181;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1312;
  tUWide DEF_near_mem_imem_pc__23_CONCAT_IF_IF_near_mem_ime_ETC___d1225;
  tUWide DEF_IF_IF_stage2_rg_full_5_THEN_stage2_rg_stage2_6_ETC___d1180;
  tUWide DEF_IF_NOT_stage1_rg_full_74_75_OR_NOT_near_mem_im_ETC___d1311;
  tUWide DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d1224;
  tUWide DEF_IF_near_mem_imem_instr__78_BITS_6_TO_0_88_EQ_0_ETC___d1223;
  tUWide DEF_to_verifier_get__avValue1;
 
 /* Rules */
 public:
  void RL_stage3_rl_reset();
  void RL_stage2_rl_reset();
  void RL_stage1_rl_reset();
  void RL_rl_show_pipe();
  void RL_rl_reset_start();
  void RL_rl_reset_complete();
  void RL_rl_pipe();
  void RL_rl_stage1_csrrx();
  void RL_rl_stage2_nonpipe();
  void RL_rl_stage1_xRET();
  void RL_rl_stage1_FENCE_I();
  void RL_rl_finish_FENCE_I();
  void RL_rl_stage1_FENCE();
  void RL_rl_finish_FENCE();
  void RL_rl_stage1_SFENCE_VMA();
  void RL_rl_finish_SFENCE_VMA();
  void RL_rl_stage1_WFI();
  void RL_rl_WFI_resume();
  void RL_rl_reset_from_WFI();
  void RL_rl_stage1_trap();
  void RL_rl_stage1_interrupt();
 
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
  void METH_hart0_server_reset_request_put(tUInt8 ARG_hart0_server_reset_request_put);
  tUInt8 METH_RDY_hart0_server_reset_request_put();
  void METH_hart0_server_reset_response_get();
  tUInt8 METH_RDY_hart0_server_reset_response_get();
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
  void METH_external_interrupt_req();
  tUInt8 METH_RDY_external_interrupt_req();
  void METH_timer_interrupt_req(tUInt8 ARG_timer_interrupt_req_set_not_clear);
  tUInt8 METH_RDY_timer_interrupt_req();
  void METH_software_interrupt_req();
  tUInt8 METH_RDY_software_interrupt_req();
  tUWide METH_to_verifier_get();
  tUInt8 METH_RDY_to_verifier_get();
  tUInt8 METH_halted();
  tUInt8 METH_RDY_halted();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkCPU &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkCPU &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkCPU &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkCPU &backing);
};

#endif /* ifndef __mkCPU_h__ */