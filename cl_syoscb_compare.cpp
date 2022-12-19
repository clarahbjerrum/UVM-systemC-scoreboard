#include <systemc>
#include <uvm>

#include "cl_syoscb_compare.h"

void cl_syoscb_compare::build_phase(uvm::uvm_phase& phase){

    // Checking for configuration
    if(!uvm::uvm_config_db<cl_syoscb_cfg*>::get(this,"compare_strategy","cfg",this->cfg)){
        UVM_FATAL("CFG_ERROR", "No configuration in compare");
    }

    // Setting compare algorithm by factory override according to configuration
    switch(this->cfg->compare_strategy){
        case SYOSCB_COMPARE_IO: 
            set_type_override("cl_syoscb_compare_base","cl_syoscb_compare_io");
            break;
        default: 
            UVM_FATAL("CFG_ERROR", "No or wrong compare algorithm defined");
    }

    this->compare_algo = cl_syoscb_compare_base::type_id::create("compare_algo", this);


}

// Triggering of correct compare algorithm
void cl_syoscb_compare::compare_trigger(cl_syoscb_queue_std** queues){

    //Invoking compare algorithm according to configuration
    compare_algo->primary_loop_do(queues);

}