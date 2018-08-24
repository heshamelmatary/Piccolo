/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Wed Aug 15 16:00:33 BST 2018
 * 
 */

/* Generation options: */
#ifndef __model_mkTop_HW_Side_h__
#define __model_mkTop_HW_Side_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTop_HW_Side.h"

/* Class declaration for a model of mkTop_HW_Side */
class MODEL_mkTop_HW_Side : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTop_HW_Side *mkTop_HW_Side_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTop_HW_Side();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(unsigned int *year,
		   unsigned int *month,
		   char const **annotation,
		   char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
  tUInt64 skip_license_check();
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTop_HW_Side();
}

#endif /* ifndef __model_mkTop_HW_Side_h__ */
