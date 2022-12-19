#ifndef cl_uvm_test_nqs_all_matches_
#define cl_uvm_test_nqs_all_matches_

#include <systemc>
#include <uvm>

#include "cl_uvm_test_base.h"
#include "../src/cl_syoscb_item.h"

class cl_uvm_test_nqs_all_matches: public cl_uvm_test_base{
    public:
        int number_of_queues;

        // Register in factory
        UVM_COMPONENT_UTILS(cl_uvm_test_nqs_all_matches);

        cl_uvm_test_nqs_all_matches(uvm::uvm_component_name name="cl_uvm_test_nqs_all_matches")
        : cl_uvm_test_base(name)
        {};

        void run_phase(uvm::uvm_phase& phase){
            UVM_INFO("TEST_INFO","Running test for n queues and all matches",uvm::UVM_MEDIUM);
            phase.raise_objection(this);

            number_of_queues = cfg->num_of_queues;
            
            // creating pointer to item
            cl_syoscb_item* item;

            // creating 10 elements with value n
            for(int n = 0; n<10; n++){
                if(item == NULL){
                    UVM_FATAL("ITEM_ERROR", "Item is NULL");
                }
                item->set_value(n);
                // insert items in queue 0 .. 1
                for(int i=0; i<number_of_queues; i++){
                    env->scb->add_item(i,item);
                }
            }
            phase.drop_objection(this);
        }

};

#endif