#ifndef cl_uvm_test_nqs_5mismatches_
#define cl_uvm_test_nqs_5mismatches_

#include <systemc>
#include <uvm>

#include "cl_uvm_test_base.h"
#include "../src/cl_syoscb_item.h"

class cl_uvm_test_nqs_5mismatches: public cl_uvm_test_base{
    public:
        int number_of_queues;

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_nqs_5mismatches);

        cl_uvm_test_nqs_5mismatches(uvm::uvm_component_name name="cl_uvm_test_nqs_5mismatches")
        : cl_uvm_test_base(name)
        {};

        void run_phase(uvm::uvm_phase& phase){
            UVM_INFO("TEST_INFO","Running test for n queues and 10 mismatches",uvm::UVM_MEDIUM);
            phase.raise_objection(this);

            this->print();
            number_of_queues = cfg->num_of_queues;
            
            // creating pointer to item
            cl_syoscb_item* item;

            // creating 10 elements with value n
            for(int n = 0; n<10; n++){
                if(item == NULL){
                    UVM_FATAL("ITEM_ERROR", "Item is NULL");
                }
                item->set_value(n);
                // insert items in queue 0 .. number_of_queues
                for(int i=0; i<number_of_queues-1; i++){
                    env->scb->add_item(i,item);
                }
                if(n%2 == 1){
                    item->set_value(n+10);
                }
                env->scb->add_item(number_of_queues-1,item);
            }
            phase.drop_objection(this);
        }

};

#endif