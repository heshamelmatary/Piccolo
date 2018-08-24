/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:11:17 BST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "mkRISCV_MBox.h"


/* String declarations */
static std::string const __str_literal_1("    RISCV_MBox.rl_mul", 21u);
static std::string const __str_literal_3("    f3 0x%0h  v1 0x%0h  v2 0x%0h", 32u);
static std::string const __str_literal_2("%0d: ERROR: RISCV_MBox.rl_mul: illegal f3.", 42u);


/* Constructor */
MOD_mkRISCV_MBox::MOD_mkRISCV_MBox(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cfg_verbosity(simHdl, "cfg_verbosity", this, 4u, (tUInt8)0u, (tUInt8)0u),
    INST_dw_result(simHdl, "dw_result", this, 64u, (tUInt8)0u),
    INST_dw_valid(simHdl, "dw_valid", this, 1u, (tUInt8)0u),
    INST_intDiv_rg_denom2(simHdl, "intDiv_rg_denom2", this, 64u),
    INST_intDiv_rg_denom_is_signed(simHdl, "intDiv_rg_denom_is_signed", this, 1u),
    INST_intDiv_rg_n(simHdl, "intDiv_rg_n", this, 64u),
    INST_intDiv_rg_numer_is_signed(simHdl, "intDiv_rg_numer_is_signed", this, 1u),
    INST_intDiv_rg_quo(simHdl, "intDiv_rg_quo", this, 64u),
    INST_intDiv_rg_quoIsNeg(simHdl, "intDiv_rg_quoIsNeg", this, 1u),
    INST_intDiv_rg_remIsNeg(simHdl, "intDiv_rg_remIsNeg", this, 1u),
    INST_intDiv_rg_state(simHdl, "intDiv_rg_state", this, 3u, (tUInt8)0u, (tUInt8)0u),
    INST_rg_f3(simHdl, "rg_f3", this, 3u),
    INST_rg_is_OP_not_OP_32(simHdl, "rg_is_OP_not_OP_32", this, 1u),
    INST_rg_state(simHdl, "rg_state", this, 2u),
    INST_rg_v1(simHdl, "rg_v1", this, 64u),
    INST_rg_v2(simHdl, "rg_v2", this, 64u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h4706(2863311530u),
    DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118(256u),
    DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110(256u),
    DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115(256u),
    DEF_rg_v1_MUL_rg_v2___d105(128u),
    DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125(128u),
    DEF_SEXT_rg_v2____d109(128u),
    DEF_SEXT_rg_v1____d108(128u),
    DEF__0_CONCAT_rg_v2___d114(128u),
    DEF_v1__h4494(128u)
{
  symbol_count = 28u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkRISCV_MBox::init_symbols_0()
{
  init_symbol(&symbols[0u], "b__h5003", SYM_DEF, &DEF_b__h5003, 64u);
  init_symbol(&symbols[1u], "cfg_verbosity", SYM_MODULE, &INST_cfg_verbosity);
  init_symbol(&symbols[2u], "dw_result", SYM_MODULE, &INST_dw_result);
  init_symbol(&symbols[3u], "dw_valid", SYM_MODULE, &INST_dw_valid);
  init_symbol(&symbols[4u], "intDiv_rg_denom2", SYM_MODULE, &INST_intDiv_rg_denom2);
  init_symbol(&symbols[5u], "intDiv_rg_denom_is_signed", SYM_MODULE, &INST_intDiv_rg_denom_is_signed);
  init_symbol(&symbols[6u],
	      "intDiv_rg_denom_is_signed__h611",
	      SYM_DEF,
	      &DEF_intDiv_rg_denom_is_signed__h611,
	      1u);
  init_symbol(&symbols[7u], "intDiv_rg_n", SYM_MODULE, &INST_intDiv_rg_n);
  init_symbol(&symbols[8u], "intDiv_rg_numer_is_signed", SYM_MODULE, &INST_intDiv_rg_numer_is_signed);
  init_symbol(&symbols[9u],
	      "intDiv_rg_numer_is_signed__h590",
	      SYM_DEF,
	      &DEF_intDiv_rg_numer_is_signed__h590,
	      1u);
  init_symbol(&symbols[10u], "intDiv_rg_quo", SYM_MODULE, &INST_intDiv_rg_quo);
  init_symbol(&symbols[11u], "intDiv_rg_quoIsNeg", SYM_MODULE, &INST_intDiv_rg_quoIsNeg);
  init_symbol(&symbols[12u], "intDiv_rg_remIsNeg", SYM_MODULE, &INST_intDiv_rg_remIsNeg);
  init_symbol(&symbols[13u], "intDiv_rg_state", SYM_MODULE, &INST_intDiv_rg_state);
  init_symbol(&symbols[14u], "RL_intDiv_rl_loop1", SYM_RULE);
  init_symbol(&symbols[15u], "RL_intDiv_rl_loop2", SYM_RULE);
  init_symbol(&symbols[16u], "RL_intDiv_rl_start_div_by_zero", SYM_RULE);
  init_symbol(&symbols[17u], "RL_intDiv_rl_start_overflow", SYM_RULE);
  init_symbol(&symbols[18u], "RL_intDiv_rl_start_s", SYM_RULE);
  init_symbol(&symbols[19u], "RL_rg_div_rem", SYM_RULE);
  init_symbol(&symbols[20u], "RL_rl_mul", SYM_RULE);
  init_symbol(&symbols[21u], "RL_rl_mul2", SYM_RULE);
  init_symbol(&symbols[22u], "rg_f3", SYM_MODULE, &INST_rg_f3);
  init_symbol(&symbols[23u], "rg_is_OP_not_OP_32", SYM_MODULE, &INST_rg_is_OP_not_OP_32);
  init_symbol(&symbols[24u], "rg_state", SYM_MODULE, &INST_rg_state);
  init_symbol(&symbols[25u], "rg_v1", SYM_MODULE, &INST_rg_v1);
  init_symbol(&symbols[26u], "rg_v2", SYM_MODULE, &INST_rg_v2);
  init_symbol(&symbols[27u], "rg_v2__h4680", SYM_DEF, &DEF_rg_v2__h4680, 64u);
}


/* Rule actions */

void MOD_mkRISCV_MBox::RL_intDiv_rl_start_div_by_zero()
{
  INST_intDiv_rg_quo.METH_write(18446744073709551615llu);
  INST_intDiv_rg_state.METH_write((tUInt8)4u);
}

void MOD_mkRISCV_MBox::RL_intDiv_rl_start_overflow()
{
  DEF_b__h5003 = INST_rg_v1.METH_read();
  INST_intDiv_rg_quo.METH_write(DEF_b__h5003);
  INST_rg_v1.METH_write(0llu);
  INST_intDiv_rg_state.METH_write((tUInt8)4u);
}

void MOD_mkRISCV_MBox::RL_intDiv_rl_start_s()
{
  tUInt8 DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d42;
  tUInt8 DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d40;
  tUInt64 DEF_x__h707;
  tUInt64 DEF__theResult___fst__h787;
  tUInt64 DEF_numer___1__h728;
  tUInt64 DEF__theResult___snd_fst__h782;
  tUInt64 DEF_denom___1__h729;
  tUInt64 DEF_denom__h695;
  tUInt8 DEF_intDiv_rg_numer_is_signed_AND_intDiv_rg_denom__ETC___d29;
  tUInt8 DEF_rg_v2_BIT_63___h792;
  tUInt8 DEF_rg_v1_BIT_63___h750;
  DEF_intDiv_rg_numer_is_signed__h590 = INST_intDiv_rg_numer_is_signed.METH_read();
  DEF_intDiv_rg_denom_is_signed__h611 = INST_intDiv_rg_denom_is_signed.METH_read();
  DEF_intDiv_rg_numer_is_signed_AND_intDiv_rg_denom__ETC___d29 = DEF_intDiv_rg_numer_is_signed__h590 && DEF_intDiv_rg_denom_is_signed__h611;
  DEF_rg_v2__h4680 = INST_rg_v2.METH_read();
  DEF_rg_v2_BIT_63___h792 = (tUInt8)(DEF_rg_v2__h4680 >> 63u);
  DEF_b__h5003 = INST_rg_v1.METH_read();
  DEF_rg_v1_BIT_63___h750 = (tUInt8)(DEF_b__h5003 >> 63u);
  DEF_x__h4111 = -DEF_b__h5003;
  DEF_denom___1__h729 = DEF_rg_v2_BIT_63___h792 ? -DEF_rg_v2__h4680 : DEF_rg_v2__h4680;
  DEF_numer___1__h728 = DEF_rg_v1_BIT_63___h750 ? DEF_x__h4111 : DEF_b__h5003;
  DEF__theResult___fst__h787 = DEF_intDiv_rg_denom_is_signed__h611 ? DEF_denom___1__h729 : DEF_rg_v2__h4680;
  DEF__theResult___snd_fst__h782 = DEF_intDiv_rg_numer_is_signed__h590 ? DEF_rg_v2__h4680 : DEF__theResult___fst__h787;
  DEF_denom__h695 = DEF_intDiv_rg_numer_is_signed_AND_intDiv_rg_denom__ETC___d29 ? DEF_denom___1__h729 : DEF__theResult___snd_fst__h782;
  DEF_x__h707 = DEF_intDiv_rg_numer_is_signed__h590 ? DEF_numer___1__h728 : DEF_b__h5003;
  DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d40 = DEF_intDiv_rg_numer_is_signed_AND_intDiv_rg_denom__ETC___d29 ? !(DEF_rg_v1_BIT_63___h750 == DEF_rg_v2_BIT_63___h792) : (DEF_intDiv_rg_numer_is_signed__h590 ? DEF_rg_v1_BIT_63___h750 : DEF_intDiv_rg_denom_is_signed__h611 && DEF_rg_v2_BIT_63___h792);
  DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d42 = DEF_intDiv_rg_numer_is_signed_AND_intDiv_rg_denom__ETC___d29 ? DEF_rg_v1_BIT_63___h750 : DEF_intDiv_rg_numer_is_signed__h590 && DEF_rg_v1_BIT_63___h750;
  INST_rg_v1.METH_write(DEF_x__h707);
  INST_rg_v2.METH_write(DEF_denom__h695);
  INST_intDiv_rg_denom2.METH_write(DEF_denom__h695);
  INST_intDiv_rg_quoIsNeg.METH_write(DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d40);
  INST_intDiv_rg_remIsNeg.METH_write(DEF_IF_intDiv_rg_numer_is_signed_AND_intDiv_rg_den_ETC___d42);
  INST_intDiv_rg_quo.METH_write(0llu);
  INST_intDiv_rg_state.METH_write((tUInt8)2u);
  INST_intDiv_rg_n.METH_write(1llu);
}

void MOD_mkRISCV_MBox::RL_intDiv_rl_loop1()
{
  tUInt64 DEF_x__h3887;
  tUInt64 DEF_x__h3869;
  tUInt64 DEF_y__h3834;
  tUInt8 DEF_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_63__ETC___d47;
  tUInt8 DEF_NOT_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_ETC___d53;
  tUInt64 DEF_rg_v1_BITS_63_TO_1___h3849;
  tUInt64 DEF_intDiv_rg_denom2_BITS_62_TO_0___h3882;
  tUInt64 DEF_intDiv_rg_n_BITS_62_TO_0___h3895;
  DEF_y__h4131 = INST_intDiv_rg_n.METH_read();
  DEF_y__h3981 = INST_intDiv_rg_denom2.METH_read();
  DEF_b__h5003 = INST_rg_v1.METH_read();
  DEF_intDiv_rg_n_BITS_62_TO_0___h3895 = (tUInt64)(9223372036854775807llu & DEF_y__h4131);
  DEF_intDiv_rg_denom2_BITS_62_TO_0___h3882 = (tUInt64)(9223372036854775807llu & DEF_y__h3981);
  DEF_rg_v1_BITS_63_TO_1___h3849 = (tUInt64)(DEF_b__h5003 >> 1u);
  DEF_y__h3834 = (((tUInt64)((tUInt8)0u)) << 63u) | DEF_rg_v1_BITS_63_TO_1___h3849;
  DEF_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_63__ETC___d47 = DEF_y__h3981 <= DEF_y__h3834;
  DEF_NOT_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_ETC___d53 = !DEF_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_63__ETC___d47;
  DEF_x__h3869 = (DEF_intDiv_rg_denom2_BITS_62_TO_0___h3882 << 1u) | (tUInt64)((tUInt8)0u);
  DEF_x__h3887 = (DEF_intDiv_rg_n_BITS_62_TO_0___h3895 << 1u) | (tUInt64)((tUInt8)0u);
  if (DEF_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_63__ETC___d47)
    INST_intDiv_rg_denom2.METH_write(DEF_x__h3869);
  if (DEF_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_63__ETC___d47)
    INST_intDiv_rg_n.METH_write(DEF_x__h3887);
  if (DEF_NOT_intDiv_rg_denom2_4_ULE_0_CONCAT_rg_v1_BITS_ETC___d53)
    INST_intDiv_rg_state.METH_write((tUInt8)3u);
}

void MOD_mkRISCV_MBox::RL_intDiv_rl_loop2()
{
  tUInt64 DEF_x__h3988;
  tUInt64 DEF_x__h4134;
  tUInt8 DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_rg_v1_ULT_intDiv_r_ETC___d72;
  tUInt8 DEF_NOT_rg_v1_ULT_rg_v2_5___d58;
  tUInt8 DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_NOT_rg_v1_ULT_intD_ETC___d61;
  tUInt64 DEF_x__h3955;
  tUInt64 DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_rg_v1_6_ELSE_rg__ETC___d71;
  tUInt64 DEF_x__h4126;
  tUInt64 DEF_x__h4041;
  tUInt8 DEF_rg_v1_ULT_rg_v2___d55;
  tUInt64 DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_intDiv_rg_quo_3__ETC___d66;
  tUInt64 DEF_intDiv_rg_denom2_BITS_63_TO_1___h4001;
  tUInt64 DEF_intDiv_rg_n_BITS_63_TO_1___h4141;
  tUInt8 DEF_intDiv_rg_quoIsNeg__h4017;
  tUInt8 DEF_intDiv_rg_remIsNeg__h4109;
  tUInt8 DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_remIsNeg_7_8_O_ETC___d69;
  tUInt8 DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_quoIsNeg_6_7_O_ETC___d62;
  tUInt8 DEF_rg_v1_ULT_intDiv_rg_denom2_4___d59;
  DEF_intDiv_rg_remIsNeg__h4109 = INST_intDiv_rg_remIsNeg.METH_read();
  DEF_intDiv_rg_quoIsNeg__h4017 = INST_intDiv_rg_quoIsNeg.METH_read();
  DEF_a__h5002 = INST_intDiv_rg_quo.METH_read();
  DEF_y__h4131 = INST_intDiv_rg_n.METH_read();
  DEF_y__h3981 = INST_intDiv_rg_denom2.METH_read();
  DEF_rg_v2__h4680 = INST_rg_v2.METH_read();
  DEF_b__h5003 = INST_rg_v1.METH_read();
  DEF_rg_v1_ULT_intDiv_rg_denom2_4___d59 = DEF_b__h5003 < DEF_y__h3981;
  DEF_intDiv_rg_n_BITS_63_TO_1___h4141 = (tUInt64)(DEF_y__h4131 >> 1u);
  DEF_intDiv_rg_denom2_BITS_63_TO_1___h4001 = (tUInt64)(DEF_y__h3981 >> 1u);
  DEF_rg_v1_ULT_rg_v2___d55 = DEF_b__h5003 < DEF_rg_v2__h4680;
  DEF_x__h4041 = -DEF_a__h5002;
  DEF_x__h4126 = DEF_a__h5002 + DEF_y__h4131;
  DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_intDiv_rg_quo_3__ETC___d66 = DEF_rg_v1_ULT_rg_v2___d55 ? DEF_x__h4041 : DEF_x__h4126;
  DEF_x__h4111 = -DEF_b__h5003;
  DEF_x__h3955 = DEF_b__h5003 - DEF_y__h3981;
  DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_rg_v1_6_ELSE_rg__ETC___d71 = DEF_rg_v1_ULT_rg_v2___d55 ? DEF_x__h4111 : DEF_x__h3955;
  DEF_NOT_rg_v1_ULT_rg_v2_5___d58 = !DEF_rg_v1_ULT_rg_v2___d55;
  DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_NOT_rg_v1_ULT_intD_ETC___d61 = DEF_NOT_rg_v1_ULT_rg_v2_5___d58 && !DEF_rg_v1_ULT_intDiv_rg_denom2_4___d59;
  DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_quoIsNeg_6_7_O_ETC___d62 = (DEF_rg_v1_ULT_rg_v2___d55 && DEF_intDiv_rg_quoIsNeg__h4017) || DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_NOT_rg_v1_ULT_intD_ETC___d61;
  DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_remIsNeg_7_8_O_ETC___d69 = (DEF_rg_v1_ULT_rg_v2___d55 && DEF_intDiv_rg_remIsNeg__h4109) || DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_NOT_rg_v1_ULT_intD_ETC___d61;
  DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_rg_v1_ULT_intDiv_r_ETC___d72 = DEF_NOT_rg_v1_ULT_rg_v2_5___d58 && DEF_rg_v1_ULT_intDiv_rg_denom2_4___d59;
  DEF_x__h4134 = (((tUInt64)((tUInt8)0u)) << 63u) | DEF_intDiv_rg_n_BITS_63_TO_1___h4141;
  DEF_x__h3988 = (((tUInt64)((tUInt8)0u)) << 63u) | DEF_intDiv_rg_denom2_BITS_63_TO_1___h4001;
  if (DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_quoIsNeg_6_7_O_ETC___d62)
    INST_intDiv_rg_quo.METH_write(DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_intDiv_rg_quo_3__ETC___d66);
  if (DEF_rg_v1_ULT_rg_v2_5_AND_intDiv_rg_remIsNeg_7_8_O_ETC___d69)
    INST_rg_v1.METH_write(DEF_IF_rg_v1_ULT_rg_v2_5_THEN_NEG_rg_v1_6_ELSE_rg__ETC___d71);
  if (DEF_rg_v1_ULT_rg_v2___d55)
    INST_intDiv_rg_state.METH_write((tUInt8)4u);
  if (DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_rg_v1_ULT_intDiv_r_ETC___d72)
    INST_intDiv_rg_n.METH_write(DEF_x__h4134);
  if (DEF_NOT_rg_v1_ULT_rg_v2_5_8_AND_rg_v1_ULT_intDiv_r_ETC___d72)
    INST_intDiv_rg_denom2.METH_write(DEF_x__h3988);
}

void MOD_mkRISCV_MBox::RL_rl_mul()
{
  tUInt32 DEF_v__h4700;
  tUInt8 DEF_NOT_cfg_verbosity_read__9_ULE_1_0___d81;
  tUInt8 DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101;
  tUInt8 DEF_rg_f3_4_EQ_0b0___d85;
  tUInt8 DEF_rg_f3_4_EQ_0b1___d88;
  tUInt8 DEF_rg_f3_4_EQ_0b10___d94;
  tUInt8 DEF_rg_f3_4_EQ_0b11___d91;
  tUInt64 DEF_v__h4600;
  tUInt64 DEF_v__h4583;
  tUInt64 DEF_v__h4527;
  tUInt64 DEF_v__h4476;
  tUInt64 DEF_v__h4418;
  tUInt64 DEF_v__h4384;
  tUInt32 DEF_x__h4636;
  tUInt32 DEF_x__h4660;
  tUInt32 DEF_x__h4612;
  tUInt64 DEF_v__h4404;
  tUInt64 DEF_v__h4489;
  tUInt64 DEF_v__h4431;
  tUInt64 DEF_v__h4540;
  tUInt8 DEF__read__h49;
  tUInt8 DEF_NOT_rg_is_OP_not_OP_32_2___d83;
  tUInt8 DEF_NOT_rg_f3_4_EQ_0b0_5___d86;
  DEF_rg_is_OP_not_OP_32__h4388 = INST_rg_is_OP_not_OP_32.METH_read();
  DEF_x__h4587 = INST_rg_f3.METH_read();
  DEF_NOT_rg_is_OP_not_OP_32_2___d83 = !DEF_rg_is_OP_not_OP_32__h4388;
  DEF_rg_v2__h4680 = INST_rg_v2.METH_read();
  DEF_b__h5003 = INST_rg_v1.METH_read();
  DEF__read__h49 = INST_cfg_verbosity.METH_read();
  wop_mul(WideData(64u, DEF_b__h5003), WideData(64u, DEF_rg_v2__h4680), DEF_rg_v1_MUL_rg_v2___d105);
  DEF_v__h4404 = primExtract64(64u, 128u, DEF_rg_v1_MUL_rg_v2___d105, 32u, 63u, 32u, 0u);
  DEF_x__h4660 = (tUInt32)(DEF_rg_v2__h4680);
  DEF_x__h4636 = (tUInt32)(DEF_b__h5003);
  wop_mul(WideData(64u, primSignExt64(64u, 32u, (tUInt32)(DEF_x__h4636))),
	  WideData(64u, primSignExt64(64u, 32u, (tUInt32)(DEF_x__h4660))),
	  DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125);
  DEF_x__h4612 = DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125.get_whole_word(0u);
  DEF_v__h4600 = primSignExt64(64u, 32u, (tUInt32)(DEF_x__h4612));
  DEF_rg_f3_4_EQ_0b11___d91 = DEF_x__h4587 == (tUInt8)3u;
  DEF_rg_f3_4_EQ_0b10___d94 = DEF_x__h4587 == (tUInt8)2u;
  DEF_rg_f3_4_EQ_0b1___d88 = DEF_x__h4587 == (tUInt8)1u;
  DEF_rg_f3_4_EQ_0b0___d85 = DEF_x__h4587 == (tUInt8)0u;
  DEF_NOT_rg_f3_4_EQ_0b0_5___d86 = !DEF_rg_f3_4_EQ_0b0___d85;
  DEF_v__h4583 = DEF_NOT_rg_is_OP_not_OP_32_2___d83 && DEF_rg_f3_4_EQ_0b0___d85 ? DEF_v__h4600 : 18446744073709551615llu;
  DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101 = (DEF_NOT_rg_is_OP_not_OP_32_2___d83 || DEF_NOT_rg_f3_4_EQ_0b0_5___d86) && ((DEF_NOT_rg_is_OP_not_OP_32_2___d83 || !DEF_rg_f3_4_EQ_0b1___d88) && ((DEF_NOT_rg_is_OP_not_OP_32_2___d83 || !DEF_rg_f3_4_EQ_0b11___d91) && ((DEF_NOT_rg_is_OP_not_OP_32_2___d83 || !DEF_rg_f3_4_EQ_0b10___d94) && (DEF_rg_is_OP_not_OP_32__h4388 || DEF_NOT_rg_f3_4_EQ_0b0_5___d86))));
  DEF_NOT_cfg_verbosity_read__9_ULE_1_0___d81 = !(DEF__read__h49 <= (tUInt8)1u);
  wop_primSignExtWide(128u, 64u, (tUInt64)(DEF_rg_v2__h4680), DEF_SEXT_rg_v2____d109);
  wop_primSignExtWide(128u, 64u, (tUInt64)(DEF_b__h5003), DEF_SEXT_rg_v1____d108);
  wop_mul(DEF_SEXT_rg_v1____d108,
	  DEF_SEXT_rg_v2____d109,
	  DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110);
  DEF_v__h4431 = primExtract64(64u,
			       256u,
			       DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110,
			       32u,
			       127u,
			       32u,
			       64u);
  DEF__0_CONCAT_rg_v2___d114.set_whole_word((tUInt32)(0llu),
					    3u).build_concat((((tUInt64)((tUInt32)(0llu))) << 32u) | (tUInt64)((tUInt32)(DEF_rg_v2__h4680 >> 32u)),
							     32u,
							     64u).set_whole_word((tUInt32)(DEF_rg_v2__h4680), 0u);
  wop_mul(DEF_SEXT_rg_v1____d108,
	  DEF__0_CONCAT_rg_v2___d114,
	  DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118);
  DEF_v__h4540 = primExtract64(64u,
			       256u,
			       DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118,
			       32u,
			       127u,
			       32u,
			       64u);
  DEF_v__h4527 = DEF_rg_is_OP_not_OP_32__h4388 && DEF_rg_f3_4_EQ_0b10___d94 ? DEF_v__h4540 : DEF_v__h4583;
  DEF_v1__h4494.set_whole_word((tUInt32)(0llu),
			       3u).build_concat((((tUInt64)((tUInt32)(0llu))) << 32u) | (tUInt64)((tUInt32)(DEF_b__h5003 >> 32u)),
						32u,
						64u).set_whole_word((tUInt32)(DEF_b__h5003), 0u);
  wop_mul(DEF_v1__h4494,
	  DEF__0_CONCAT_rg_v2___d114,
	  DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115);
  DEF_v__h4489 = primExtract64(64u,
			       256u,
			       DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115,
			       32u,
			       127u,
			       32u,
			       64u);
  DEF_v__h4476 = DEF_rg_is_OP_not_OP_32__h4388 && DEF_rg_f3_4_EQ_0b11___d91 ? DEF_v__h4489 : DEF_v__h4527;
  DEF_v__h4418 = DEF_rg_is_OP_not_OP_32__h4388 && DEF_rg_f3_4_EQ_0b1___d88 ? DEF_v__h4431 : DEF_v__h4476;
  DEF_v__h4384 = DEF_rg_is_OP_not_OP_32__h4388 && DEF_rg_f3_4_EQ_0b0___d85 ? DEF_v__h4404 : DEF_v__h4418;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_NOT_cfg_verbosity_read__9_ULE_1_0___d81)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
    if (DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101)
      DEF_v__h4706 = dollar_stime(sim_hdl);
  }
  DEF_v__h4700 = DEF_v__h4706 / 10u;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101)
      dollar_display(sim_hdl, this, "s,32", &__str_literal_2, DEF_v__h4700);
    if (DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101)
      dollar_display(sim_hdl,
		     this,
		     "s,3,64,64",
		     &__str_literal_3,
		     DEF_x__h4587,
		     DEF_b__h5003,
		     DEF_rg_v2__h4680);
    if (DEF_NOT_rg_is_OP_not_OP_32_2_3_OR_NOT_rg_f3_4_EQ_0_ETC___d101)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_rg_v1.METH_write(DEF_v__h4384);
  INST_rg_state.METH_write((tUInt8)1u);
}

void MOD_mkRISCV_MBox::RL_rl_mul2()
{
  DEF_b__h5003 = INST_rg_v1.METH_read();
  INST_dw_valid.METH_wset((tUInt8)1u);
  INST_dw_result.METH_wset(DEF_b__h5003);
}

void MOD_mkRISCV_MBox::RL_rg_div_rem()
{
  tUInt64 DEF_result___1__h4957;
  tUInt64 DEF_new_value__h4951;
  tUInt64 DEF_IF_rg_f3_4_BIT_1_37_THEN_rg_v1_ELSE_intDiv_rg__ETC___d138;
  tUInt32 DEF_x__h4960;
  DEF_rg_is_OP_not_OP_32__h4388 = INST_rg_is_OP_not_OP_32.METH_read();
  DEF_x__h4587 = INST_rg_f3.METH_read();
  DEF_a__h5002 = INST_intDiv_rg_quo.METH_read();
  DEF_b__h5003 = INST_rg_v1.METH_read();
  DEF_IF_rg_f3_4_BIT_1_37_THEN_rg_v1_ELSE_intDiv_rg__ETC___d138 = (tUInt8)((tUInt8)1u & (DEF_x__h4587 >> 1u)) ? DEF_b__h5003 : DEF_a__h5002;
  DEF_x__h4960 = (tUInt32)(DEF_IF_rg_f3_4_BIT_1_37_THEN_rg_v1_ELSE_intDiv_rg__ETC___d138);
  DEF_result___1__h4957 = primSignExt64(64u, 32u, (tUInt32)(DEF_x__h4960));
  DEF_new_value__h4951 = DEF_rg_is_OP_not_OP_32__h4388 ? DEF_IF_rg_f3_4_BIT_1_37_THEN_rg_v1_ELSE_intDiv_rg__ETC___d138 : DEF_result___1__h4957;
  INST_dw_valid.METH_wset((tUInt8)1u);
  INST_dw_result.METH_wset(DEF_new_value__h4951);
}


/* Methods */

void MOD_mkRISCV_MBox::METH_set_verbosity(tUInt8 ARG_set_verbosity_verbosity)
{
  INST_cfg_verbosity.METH_write(ARG_set_verbosity_verbosity);
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_set_verbosity()
{
  tUInt8 DEF_CAN_FIRE_set_verbosity;
  tUInt8 PORT_RDY_set_verbosity;
  DEF_CAN_FIRE_set_verbosity = (tUInt8)1u;
  PORT_RDY_set_verbosity = DEF_CAN_FIRE_set_verbosity;
  return PORT_RDY_set_verbosity;
}

void MOD_mkRISCV_MBox::METH_req_reset()
{
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_req_reset()
{
  tUInt8 DEF_CAN_FIRE_req_reset;
  tUInt8 PORT_RDY_req_reset;
  DEF_CAN_FIRE_req_reset = (tUInt8)1u;
  PORT_RDY_req_reset = DEF_CAN_FIRE_req_reset;
  return PORT_RDY_req_reset;
}

void MOD_mkRISCV_MBox::METH_rsp_reset()
{
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_rsp_reset()
{
  tUInt8 DEF_CAN_FIRE_rsp_reset;
  tUInt8 PORT_RDY_rsp_reset;
  DEF_CAN_FIRE_rsp_reset = (tUInt8)1u;
  PORT_RDY_rsp_reset = DEF_CAN_FIRE_rsp_reset;
  return PORT_RDY_rsp_reset;
}

void MOD_mkRISCV_MBox::METH_req(tUInt8 ARG_req_is_OP_not_OP_32,
				tUInt8 ARG_req_f3,
				tUInt64 ARG_req_v1,
				tUInt64 ARG_req_v2)
{
  tUInt8 DEF_NOT_req_f3_BIT_0_42___d155;
  tUInt8 DEF_IF_req_f3_BIT_2_53_THEN_2_ELSE_0___d154;
  tUInt64 DEF_x__h5145;
  tUInt64 DEF_x__h5255;
  tUInt64 DEF__theResult___snd__h5193;
  tUInt64 DEF__theResult___snd__h5219;
  tUInt64 DEF__theResult___snd__h5163;
  tUInt64 DEF__theResult___fst__h5192;
  tUInt64 DEF__theResult___fst__h5218;
  tUInt64 DEF__theResult___fst__h5162;
  tUInt8 DEF_req_f3_BIT_0___d142;
  tUInt8 DEF_req_f3_BIT_2___d153;
  tUInt32 DEF_x__h5222;
  tUInt32 DEF_x__h5289;
  DEF_x__h5289 = (tUInt32)(ARG_req_v2);
  DEF_x__h5222 = (tUInt32)(ARG_req_v1);
  DEF_req_f3_BIT_2___d153 = (tUInt8)(ARG_req_f3 >> 2u);
  DEF_req_f3_BIT_0___d142 = (tUInt8)((tUInt8)1u & ARG_req_f3);
  DEF__theResult___fst__h5218 = (((tUInt64)(0u)) << 32u) | (tUInt64)(DEF_x__h5222);
  DEF__theResult___fst__h5192 = primSignExt64(64u, 32u, (tUInt32)(DEF_x__h5222));
  DEF__theResult___fst__h5162 = DEF_req_f3_BIT_0___d142 ? DEF__theResult___fst__h5218 : DEF__theResult___fst__h5192;
  DEF__theResult___snd__h5193 = primSignExt64(64u, 32u, (tUInt32)(DEF_x__h5289));
  DEF__theResult___snd__h5219 = (((tUInt64)(0u)) << 32u) | (tUInt64)(DEF_x__h5289);
  DEF__theResult___snd__h5163 = DEF_req_f3_BIT_0___d142 ? DEF__theResult___snd__h5219 : DEF__theResult___snd__h5193;
  DEF_x__h5255 = ARG_req_is_OP_not_OP_32 ? ARG_req_v2 : DEF__theResult___snd__h5163;
  DEF_x__h5145 = ARG_req_is_OP_not_OP_32 ? ARG_req_v1 : DEF__theResult___fst__h5162;
  DEF_NOT_req_f3_BIT_0_42___d155 = !DEF_req_f3_BIT_0___d142;
  DEF_IF_req_f3_BIT_2_53_THEN_2_ELSE_0___d154 = DEF_req_f3_BIT_2___d153 ? (tUInt8)2u : (tUInt8)0u;
  INST_rg_is_OP_not_OP_32.METH_write(ARG_req_is_OP_not_OP_32);
  INST_rg_v1.METH_write(DEF_x__h5145);
  INST_rg_f3.METH_write(ARG_req_f3);
  INST_rg_v2.METH_write(DEF_x__h5255);
  INST_rg_state.METH_write(DEF_IF_req_f3_BIT_2_53_THEN_2_ELSE_0___d154);
  if (DEF_req_f3_BIT_2___d153)
    INST_intDiv_rg_numer_is_signed.METH_write(DEF_NOT_req_f3_BIT_0_42___d155);
  if (DEF_req_f3_BIT_2___d153)
    INST_intDiv_rg_denom_is_signed.METH_write(DEF_NOT_req_f3_BIT_0_42___d155);
  if (DEF_req_f3_BIT_2___d153)
    INST_intDiv_rg_state.METH_write((tUInt8)1u);
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_req()
{
  tUInt8 PORT_RDY_req;
  tUInt8 DEF_CAN_FIRE_req;
  DEF_CAN_FIRE_req = (tUInt8)1u;
  PORT_RDY_req = DEF_CAN_FIRE_req;
  return PORT_RDY_req;
}

tUInt8 MOD_mkRISCV_MBox::METH_valid()
{
  tUInt8 DEF_dw_valid_wget____d157;
  tUInt8 DEF_dw_valid_whas____d156;
  tUInt8 PORT_valid;
  DEF_dw_valid_whas____d156 = INST_dw_valid.METH_whas();
  DEF_dw_valid_wget____d157 = INST_dw_valid.METH_wget();
  PORT_valid = DEF_dw_valid_whas____d156 && DEF_dw_valid_wget____d157;
  return PORT_valid;
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_valid()
{
  tUInt8 PORT_RDY_valid;
  tUInt8 DEF_CAN_FIRE_valid;
  DEF_CAN_FIRE_valid = (tUInt8)1u;
  PORT_RDY_valid = DEF_CAN_FIRE_valid;
  return PORT_RDY_valid;
}

tUInt64 MOD_mkRISCV_MBox::METH_word()
{
  tUInt64 DEF_x_wget__h4283;
  tUInt64 PORT_word;
  DEF_x_wget__h4283 = INST_dw_result.METH_wget();
  PORT_word = DEF_x_wget__h4283;
  return PORT_word;
}

tUInt8 MOD_mkRISCV_MBox::METH_RDY_word()
{
  tUInt8 PORT_RDY_word;
  tUInt8 DEF_CAN_FIRE_word;
  DEF_CAN_FIRE_word = (tUInt8)1u;
  PORT_RDY_word = DEF_CAN_FIRE_word;
  return PORT_RDY_word;
}


/* Reset routines */

void MOD_mkRISCV_MBox::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_intDiv_rg_state.reset_RST(ARG_rst_in);
  INST_cfg_verbosity.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkRISCV_MBox::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkRISCV_MBox::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cfg_verbosity.dump_state(indent + 2u);
  INST_dw_result.dump_state(indent + 2u);
  INST_dw_valid.dump_state(indent + 2u);
  INST_intDiv_rg_denom2.dump_state(indent + 2u);
  INST_intDiv_rg_denom_is_signed.dump_state(indent + 2u);
  INST_intDiv_rg_n.dump_state(indent + 2u);
  INST_intDiv_rg_numer_is_signed.dump_state(indent + 2u);
  INST_intDiv_rg_quo.dump_state(indent + 2u);
  INST_intDiv_rg_quoIsNeg.dump_state(indent + 2u);
  INST_intDiv_rg_remIsNeg.dump_state(indent + 2u);
  INST_intDiv_rg_state.dump_state(indent + 2u);
  INST_rg_f3.dump_state(indent + 2u);
  INST_rg_is_OP_not_OP_32.dump_state(indent + 2u);
  INST_rg_state.dump_state(indent + 2u);
  INST_rg_v1.dump_state(indent + 2u);
  INST_rg_v2.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkRISCV_MBox::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 37u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118", 256u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110", 256u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "SEXT_rg_v1____d108", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "SEXT_rg_v2____d109", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "_0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115", 256u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "_0_CONCAT_rg_v2___d114", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "a__h5002", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "b__h5003", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "intDiv_rg_denom_is_signed__h611", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "intDiv_rg_numer_is_signed__h590", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "rg_is_OP_not_OP_32__h4388", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "rg_v1_MUL_rg_v2___d105", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "rg_v2__h4680", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v1__h4494", 128u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h4706", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h4111", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h4587", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "y__h3981", 64u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "y__h4131", 64u);
  num = INST_cfg_verbosity.dump_VCD_defs(num);
  num = INST_dw_result.dump_VCD_defs(num);
  num = INST_dw_valid.dump_VCD_defs(num);
  num = INST_intDiv_rg_denom2.dump_VCD_defs(num);
  num = INST_intDiv_rg_denom_is_signed.dump_VCD_defs(num);
  num = INST_intDiv_rg_n.dump_VCD_defs(num);
  num = INST_intDiv_rg_numer_is_signed.dump_VCD_defs(num);
  num = INST_intDiv_rg_quo.dump_VCD_defs(num);
  num = INST_intDiv_rg_quoIsNeg.dump_VCD_defs(num);
  num = INST_intDiv_rg_remIsNeg.dump_VCD_defs(num);
  num = INST_intDiv_rg_state.dump_VCD_defs(num);
  num = INST_rg_f3.dump_VCD_defs(num);
  num = INST_rg_is_OP_not_OP_32.dump_VCD_defs(num);
  num = INST_rg_state.dump_VCD_defs(num);
  num = INST_rg_v1.dump_VCD_defs(num);
  num = INST_rg_v2.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkRISCV_MBox::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkRISCV_MBox &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkRISCV_MBox::vcd_defs(tVCDDumpType dt, MOD_mkRISCV_MBox &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 256u);
    vcd_write_x(sim_hdl, num++, 256u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 256u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 128u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 64u);
    vcd_write_x(sim_hdl, num++, 64u);
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
      if ((backing.DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125) != DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125)
      {
	vcd_write_val(sim_hdl, num, DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125, 128u);
	backing.DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125 = DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125;
      }
      ++num;
      if ((backing.DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118) != DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118)
      {
	vcd_write_val(sim_hdl, num, DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118, 256u);
	backing.DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118 = DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118;
      }
      ++num;
      if ((backing.DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110) != DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110)
      {
	vcd_write_val(sim_hdl, num, DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110, 256u);
	backing.DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110 = DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110;
      }
      ++num;
      if ((backing.DEF_SEXT_rg_v1____d108) != DEF_SEXT_rg_v1____d108)
      {
	vcd_write_val(sim_hdl, num, DEF_SEXT_rg_v1____d108, 128u);
	backing.DEF_SEXT_rg_v1____d108 = DEF_SEXT_rg_v1____d108;
      }
      ++num;
      if ((backing.DEF_SEXT_rg_v2____d109) != DEF_SEXT_rg_v2____d109)
      {
	vcd_write_val(sim_hdl, num, DEF_SEXT_rg_v2____d109, 128u);
	backing.DEF_SEXT_rg_v2____d109 = DEF_SEXT_rg_v2____d109;
      }
      ++num;
      if ((backing.DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115) != DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115)
      {
	vcd_write_val(sim_hdl, num, DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115, 256u);
	backing.DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115 = DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115;
      }
      ++num;
      if ((backing.DEF__0_CONCAT_rg_v2___d114) != DEF__0_CONCAT_rg_v2___d114)
      {
	vcd_write_val(sim_hdl, num, DEF__0_CONCAT_rg_v2___d114, 128u);
	backing.DEF__0_CONCAT_rg_v2___d114 = DEF__0_CONCAT_rg_v2___d114;
      }
      ++num;
      if ((backing.DEF_a__h5002) != DEF_a__h5002)
      {
	vcd_write_val(sim_hdl, num, DEF_a__h5002, 64u);
	backing.DEF_a__h5002 = DEF_a__h5002;
      }
      ++num;
      if ((backing.DEF_b__h5003) != DEF_b__h5003)
      {
	vcd_write_val(sim_hdl, num, DEF_b__h5003, 64u);
	backing.DEF_b__h5003 = DEF_b__h5003;
      }
      ++num;
      if ((backing.DEF_intDiv_rg_denom_is_signed__h611) != DEF_intDiv_rg_denom_is_signed__h611)
      {
	vcd_write_val(sim_hdl, num, DEF_intDiv_rg_denom_is_signed__h611, 1u);
	backing.DEF_intDiv_rg_denom_is_signed__h611 = DEF_intDiv_rg_denom_is_signed__h611;
      }
      ++num;
      if ((backing.DEF_intDiv_rg_numer_is_signed__h590) != DEF_intDiv_rg_numer_is_signed__h590)
      {
	vcd_write_val(sim_hdl, num, DEF_intDiv_rg_numer_is_signed__h590, 1u);
	backing.DEF_intDiv_rg_numer_is_signed__h590 = DEF_intDiv_rg_numer_is_signed__h590;
      }
      ++num;
      if ((backing.DEF_rg_is_OP_not_OP_32__h4388) != DEF_rg_is_OP_not_OP_32__h4388)
      {
	vcd_write_val(sim_hdl, num, DEF_rg_is_OP_not_OP_32__h4388, 1u);
	backing.DEF_rg_is_OP_not_OP_32__h4388 = DEF_rg_is_OP_not_OP_32__h4388;
      }
      ++num;
      if ((backing.DEF_rg_v1_MUL_rg_v2___d105) != DEF_rg_v1_MUL_rg_v2___d105)
      {
	vcd_write_val(sim_hdl, num, DEF_rg_v1_MUL_rg_v2___d105, 128u);
	backing.DEF_rg_v1_MUL_rg_v2___d105 = DEF_rg_v1_MUL_rg_v2___d105;
      }
      ++num;
      if ((backing.DEF_rg_v2__h4680) != DEF_rg_v2__h4680)
      {
	vcd_write_val(sim_hdl, num, DEF_rg_v2__h4680, 64u);
	backing.DEF_rg_v2__h4680 = DEF_rg_v2__h4680;
      }
      ++num;
      if ((backing.DEF_v1__h4494) != DEF_v1__h4494)
      {
	vcd_write_val(sim_hdl, num, DEF_v1__h4494, 128u);
	backing.DEF_v1__h4494 = DEF_v1__h4494;
      }
      ++num;
      if ((backing.DEF_v__h4706) != DEF_v__h4706)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h4706, 32u);
	backing.DEF_v__h4706 = DEF_v__h4706;
      }
      ++num;
      if ((backing.DEF_x__h4111) != DEF_x__h4111)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h4111, 64u);
	backing.DEF_x__h4111 = DEF_x__h4111;
      }
      ++num;
      if ((backing.DEF_x__h4587) != DEF_x__h4587)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h4587, 3u);
	backing.DEF_x__h4587 = DEF_x__h4587;
      }
      ++num;
      if ((backing.DEF_y__h3981) != DEF_y__h3981)
      {
	vcd_write_val(sim_hdl, num, DEF_y__h3981, 64u);
	backing.DEF_y__h3981 = DEF_y__h3981;
      }
      ++num;
      if ((backing.DEF_y__h4131) != DEF_y__h4131)
      {
	vcd_write_val(sim_hdl, num, DEF_y__h4131, 64u);
	backing.DEF_y__h4131 = DEF_y__h4131;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125, 128u);
      backing.DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125 = DEF_SEXT_rg_v1_BITS_31_TO_0_21_22_MUL_SEXT_rg_v2_B_ETC___d125;
      vcd_write_val(sim_hdl, num++, DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118, 256u);
      backing.DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118 = DEF_SEXT_rg_v1__08_MUL_0_CONCAT_rg_v2_14___d118;
      vcd_write_val(sim_hdl, num++, DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110, 256u);
      backing.DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110 = DEF_SEXT_rg_v1__08_MUL_SEXT_rg_v2__09___d110;
      vcd_write_val(sim_hdl, num++, DEF_SEXT_rg_v1____d108, 128u);
      backing.DEF_SEXT_rg_v1____d108 = DEF_SEXT_rg_v1____d108;
      vcd_write_val(sim_hdl, num++, DEF_SEXT_rg_v2____d109, 128u);
      backing.DEF_SEXT_rg_v2____d109 = DEF_SEXT_rg_v2____d109;
      vcd_write_val(sim_hdl, num++, DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115, 256u);
      backing.DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115 = DEF__0_CONCAT_rg_v1_13_MUL_0_CONCAT_rg_v2_14___d115;
      vcd_write_val(sim_hdl, num++, DEF__0_CONCAT_rg_v2___d114, 128u);
      backing.DEF__0_CONCAT_rg_v2___d114 = DEF__0_CONCAT_rg_v2___d114;
      vcd_write_val(sim_hdl, num++, DEF_a__h5002, 64u);
      backing.DEF_a__h5002 = DEF_a__h5002;
      vcd_write_val(sim_hdl, num++, DEF_b__h5003, 64u);
      backing.DEF_b__h5003 = DEF_b__h5003;
      vcd_write_val(sim_hdl, num++, DEF_intDiv_rg_denom_is_signed__h611, 1u);
      backing.DEF_intDiv_rg_denom_is_signed__h611 = DEF_intDiv_rg_denom_is_signed__h611;
      vcd_write_val(sim_hdl, num++, DEF_intDiv_rg_numer_is_signed__h590, 1u);
      backing.DEF_intDiv_rg_numer_is_signed__h590 = DEF_intDiv_rg_numer_is_signed__h590;
      vcd_write_val(sim_hdl, num++, DEF_rg_is_OP_not_OP_32__h4388, 1u);
      backing.DEF_rg_is_OP_not_OP_32__h4388 = DEF_rg_is_OP_not_OP_32__h4388;
      vcd_write_val(sim_hdl, num++, DEF_rg_v1_MUL_rg_v2___d105, 128u);
      backing.DEF_rg_v1_MUL_rg_v2___d105 = DEF_rg_v1_MUL_rg_v2___d105;
      vcd_write_val(sim_hdl, num++, DEF_rg_v2__h4680, 64u);
      backing.DEF_rg_v2__h4680 = DEF_rg_v2__h4680;
      vcd_write_val(sim_hdl, num++, DEF_v1__h4494, 128u);
      backing.DEF_v1__h4494 = DEF_v1__h4494;
      vcd_write_val(sim_hdl, num++, DEF_v__h4706, 32u);
      backing.DEF_v__h4706 = DEF_v__h4706;
      vcd_write_val(sim_hdl, num++, DEF_x__h4111, 64u);
      backing.DEF_x__h4111 = DEF_x__h4111;
      vcd_write_val(sim_hdl, num++, DEF_x__h4587, 3u);
      backing.DEF_x__h4587 = DEF_x__h4587;
      vcd_write_val(sim_hdl, num++, DEF_y__h3981, 64u);
      backing.DEF_y__h3981 = DEF_y__h3981;
      vcd_write_val(sim_hdl, num++, DEF_y__h4131, 64u);
      backing.DEF_y__h4131 = DEF_y__h4131;
    }
}

void MOD_mkRISCV_MBox::vcd_prims(tVCDDumpType dt, MOD_mkRISCV_MBox &backing)
{
  INST_cfg_verbosity.dump_VCD(dt, backing.INST_cfg_verbosity);
  INST_dw_result.dump_VCD(dt, backing.INST_dw_result);
  INST_dw_valid.dump_VCD(dt, backing.INST_dw_valid);
  INST_intDiv_rg_denom2.dump_VCD(dt, backing.INST_intDiv_rg_denom2);
  INST_intDiv_rg_denom_is_signed.dump_VCD(dt, backing.INST_intDiv_rg_denom_is_signed);
  INST_intDiv_rg_n.dump_VCD(dt, backing.INST_intDiv_rg_n);
  INST_intDiv_rg_numer_is_signed.dump_VCD(dt, backing.INST_intDiv_rg_numer_is_signed);
  INST_intDiv_rg_quo.dump_VCD(dt, backing.INST_intDiv_rg_quo);
  INST_intDiv_rg_quoIsNeg.dump_VCD(dt, backing.INST_intDiv_rg_quoIsNeg);
  INST_intDiv_rg_remIsNeg.dump_VCD(dt, backing.INST_intDiv_rg_remIsNeg);
  INST_intDiv_rg_state.dump_VCD(dt, backing.INST_intDiv_rg_state);
  INST_rg_f3.dump_VCD(dt, backing.INST_rg_f3);
  INST_rg_is_OP_not_OP_32.dump_VCD(dt, backing.INST_rg_is_OP_not_OP_32);
  INST_rg_state.dump_VCD(dt, backing.INST_rg_state);
  INST_rg_v1.dump_VCD(dt, backing.INST_rg_v1);
  INST_rg_v2.dump_VCD(dt, backing.INST_rg_v2);
}
