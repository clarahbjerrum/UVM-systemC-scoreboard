#ifndef cl_uvm_test_2qs_1mismatch_
#define cl_uvm_test_2qs_1mismatch_

#include <systemc>
#include <uvm>

#include "cl_uvm_test_base.h"

class cl_uvm_test_2qs_1mismatch: public cl_uvm_test_base{
    public:

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_2qs_1mismatch);

        cl_uvm_test_2qs_1mismatch(uvm::uvm_component_name name="cl_uvm_test_2qs_1mismatch")
        : cl_uvm_test_base(name)
        {};

        void run_phase(uvm::uvm_phase& phase){
            UVM_INFO("TEST_INFO","Running test for 2 queues and 1 mismatch",uvm::UVM_MEDIUM);
            phase.raise_objection(this);

            if(this->cfg->num_of_queues != 2){
                UVM_FATAL("TEST_ERROR", "The number of queues is not 2");
            }

            // creating 10 elements with value n*2
            cl_syoscb_item* item;

            for(int n = 0; n<9; n++){
                item->set_value(n);
                this->env->scb->add_item(0,item);
                this->env->scb->add_item(1,item);
            }
            // creating two mismatched items
            item->set_value(9);;
            this->env->scb->add_item(0,item);
            item->set_value(10);
            this->env->scb->add_item(1,item);

            phase.drop_objection(this);
        }

};

#endif