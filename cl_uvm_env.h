#ifndef CL_UVM_ENV_H_
#define CL_UVM_ENV_H_

#include <systemc>
#include <uvm>

#include "../src/cl_syoscb.h"
#include "../src/cl_syoscb_cfg.h"

using namespace sc_core;

class cl_uvm_env: public uvm::uvm_env{
    public:
        // Obejcts
        cl_syoscb* scb;
        cl_syoscb_cfg* cfg;

        // Register to factory 
        UVM_COMPONENT_UTILS(cl_uvm_env);

        // Constructor 
        cl_uvm_env(uvm::uvm_component_name name)
        : uvm::uvm_env(name)
        {};

        void build_phase(uvm::uvm_phase& phase){
            // Checking if configuration passed from test
            if(!uvm::uvm_config_db<cl_syoscb_cfg*>::get(this,"env","cfg",cfg)){
                UVM_FATAL("CFG_ERROR", "No configuration in env");
            }

            // Building scoreboard
            scb = cl_syoscb::type_id::create("scb",this);
        }

};

#endif