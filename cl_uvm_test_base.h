#ifndef CL_UVM_TEST_H_
#define CL_UVM_TEST_H_

#include <systemc>
#include <uvm>

#include "cl_uvm_env.h"
#include "../src/cl_syoscb_cfg.h"

class cl_uvm_test_base: public uvm::uvm_test{
    public:
        cl_uvm_env* env;
        cl_syoscb_cfg* cfg;

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_base);

        cl_uvm_test_base(uvm::uvm_component_name name)
        : uvm::uvm_test(name)
        {};

        // UVM Phase methods
        void build_phase(uvm::uvm_phase& phase);
        void report_phase(uvm::uvm_phase& phase);

        // functions
        void printQueues();
        void unmatchedItems();

};

void cl_uvm_test_base::build_phase(uvm::uvm_phase& phase){
    // Setting configuration for all components
    cfg = cl_syoscb_cfg::type_id::create("cfg");
    uvm::uvm_config_db<cl_syoscb_cfg*>::set(NULL,"*","cfg",cfg);

    // Creating the environment
    env = cl_uvm_env::type_id::create("env",this);
}

void cl_uvm_test_base::report_phase(uvm::uvm_phase& phase){
    printQueues();
    unmatchedItems();
}

void cl_uvm_test_base::printQueues(){

    for(int n=0; n<env->scb->number_of_queues; n++){
        UVM_INFO("QUEUE", "** Queue "+std::to_string(n)+" **",uvm::UVM_MEDIUM);
        int queue_size = env->scb->queues[n]->get_size();

        if(queue_size>0){
            for(int i = 0; i<queue_size; i++){
                cl_syoscb_item item = env->scb->queues[n]->get_item_at(i);

                std::string out = "item" + std::to_string(i) + ": " + std::to_string(item.get_value());
                UVM_INFO("QUEUE",out,uvm::UVM_MEDIUM);
            }
        } else {
            UVM_INFO("QUEUE","queue is empty",uvm::UVM_MEDIUM);
        }
    }
}

void cl_uvm_test_base::unmatchedItems(){
    for(int n=0; n<env->scb->number_of_queues; n++){
        int queue_size = env->scb->queues[n]->get_size();
        if (queue_size>0){
            std::string out = "Queue " + std::to_string(n) + " has " + std::to_string(queue_size) + " unmatched items";
            UVM_WARNING("UNMATCHED_ITEM",out);
        }
    }
}

#endif