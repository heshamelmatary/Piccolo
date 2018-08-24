/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */

/* Generation options: */
#ifndef __mkTLB_h__
#define __mkTLB_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTLB module */
class MOD_mkTLB : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
  tUInt8 const PARAM_dmem_not_imem;
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_rg_flushing;
  MOD_RegFile<tUInt8,tUWide> INST_tlb0_entries;
  MOD_Reg<tUInt8> INST_tlb0_valids_0;
  MOD_Reg<tUInt8> INST_tlb0_valids_1;
  MOD_Reg<tUInt8> INST_tlb0_valids_2;
  MOD_Reg<tUInt8> INST_tlb0_valids_3;
  MOD_RegFile<tUInt8,tUWide> INST_tlb1_entries;
  MOD_Reg<tUInt8> INST_tlb1_valids_0;
  MOD_Reg<tUInt8> INST_tlb1_valids_1;
  MOD_Reg<tUInt8> INST_tlb1_valids_2;
  MOD_Reg<tUInt8> INST_tlb1_valids_3;
  MOD_RegFile<tUInt8,tUWide> INST_tlb2_entries;
  MOD_Reg<tUInt8> INST_tlb2_valids_0;
  MOD_Reg<tUInt8> INST_tlb2_valids_1;
  MOD_Reg<tUInt8> INST_tlb2_valids_2;
  MOD_Reg<tUInt8> INST_tlb2_valids_3;
 
 /* Constructor */
 public:
  MOD_mkTLB(tSimStateHdl simHdl, char const *name, Module *parent, tUInt8 ARG_dmem_not_imem);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_lookup;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_NOT_rg_flushing___d94;
  tUInt8 DEF_rg_flushing__h1437;
 
 /* Local definitions */
 private:
  tUWide DEF_tlb0_entries_sub_lookup_vpn_BITS_1_TO_0_0___d52;
  tUWide DEF_tlb1_entries_sub_lookup_vpn_BITS_10_TO_9_8___d31;
  tUWide DEF_tlb2_entries_sub_lookup_vpn_BITS_19_TO_18___d10;
  tUWide DEF_IF_SEL_ARR_tlb2_valids_0_tlb2_valids_1_tlb2_va_ETC___d91;
  tUWide DEF_tlb2_entries_sub_lookup_vpn_BITS_19_TO_18_0_BI_ETC___d90;
  tUWide DEF_IF_NOT_SEL_ARR_tlb2_valids_0_tlb2_valids_1_tlb_ETC___d93;
  tUWide DEF_tlb0_entries_sub_lookup_vpn_BITS_1_TO_0_0_2_BI_ETC___d84;
  tUWide DEF_IF_NOT_SEL_ARR_tlb2_valids_0_tlb2_valids_1_tlb_ETC___d92;
  tUWide DEF_tlb1_entries_sub_lookup_vpn_BITS_10_TO_9_8_1_B_ETC___d87;
  tUWide DEF_insert_asid_CONCAT_insert_vpn_BITS_26_TO_2_05__ETC___d107;
  tUWide DEF_insert_pte_CONCAT_insert_pte_pa___d106;
  tUWide DEF_insert_asid_CONCAT_insert_vpn_BITS_26_TO_11_18_ETC___d119;
  tUWide DEF_insert_asid_CONCAT_insert_vpn_BITS_26_TO_20_32_ETC___d133;
 
 /* Rules */
 public:
  void RL_rl_initialize();
 
 /* Methods */
 public:
  void METH_flush();
  tUInt8 METH_RDY_flush();
  tUWide METH_lookup(tUInt32 ARG_lookup_asid, tUInt32 ARG_lookup_vpn);
  tUInt8 METH_RDY_lookup();
  void METH_insert(tUInt32 ARG_insert_asid,
		   tUInt32 ARG_insert_vpn,
		   tUInt64 ARG_insert_pte,
		   tUInt8 ARG_insert_level,
		   tUInt64 ARG_insert_pte_pa);
  tUInt8 METH_RDY_insert();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTLB &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTLB &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTLB &backing);
};

#endif /* ifndef __mkTLB_h__ */
