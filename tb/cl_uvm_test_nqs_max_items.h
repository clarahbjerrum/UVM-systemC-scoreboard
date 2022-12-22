#ifndef cl_uvm_test_nqs_max_items_
#define cl_uvm_test_nqs_max_items_

#include <systemc>
#include <uvm>

#include "cl_uvm_test_base.h"
#include "../src/cl_syoscb_item.h"

class cl_uvm_test_nqs_max_items: public cl_uvm_test_base{
    public:

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_nqs_max_items);

        cl_uvm_test_nqs_max_items(uvm::uvm_component_name name="cl_uvm_test_nqs_max_items")
        : cl_uvm_test_base(name)
        {};

        void run_phase(uvm::uvm_phase& phase){
            UVM_INFO("TEST_INFO","Running test for reaching max number of items",uvm::UVM_MEDIUM);
            phase.raise_objection(this);

            // Setting max queue size to 150
            this->cfg->set_queue_size(150);
            
            // creating pointer to item
            cl_syoscb_item* item = new cl_syoscb_item("item");

            // creating 10 elements with value n
            for(int n = 0; n<200; n++){
                item->set_value(n);
                // insert items in queue 0
                env->scb->add_item(0,item);
            }
            phase.drop_objection(this);
        }

};

#endif