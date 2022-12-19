#ifndef cl_uvm_test_2qs_5unmatched_
#define cl_uvm_test_2qs_5unmatched_

#include <systemc>
#include <uvm>

#include "cl_uvm_test_base.h"

class cl_uvm_test_2qs_5unmatched: public cl_uvm_test_base{
    public:

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_2qs_5unmatched);

        cl_uvm_test_2qs_5unmatched(uvm::uvm_component_name name="cl_uvm_test_2qs_5unmatched")
        : cl_uvm_test_base(name)
        {};

        void run_phase(uvm::uvm_phase& phase){
            UVM_INFO("TEST_INFO","Running test for 2 queues and 5 unmatched items",uvm::UVM_MEDIUM);
            phase.raise_objection(this);

            if(cfg->num_of_queues != 2){
                UVM_FATAL("TEST_ERROR", "The number of queues is not 2");
            }

            // creating 10 elements with value n*2
            cl_syoscb_item* item;

            for(int n = 0; n<10; n++){
                item->set_value(n);
                env->scb->add_item(0,item);
                if(n<5){   // creating only 5 items in queue 2
                env->scb->add_item(1,item);
                }
            }

            phase.drop_objection(this);
        }

};

#endif