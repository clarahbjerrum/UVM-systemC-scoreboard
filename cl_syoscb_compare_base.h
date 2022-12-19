#ifndef CL_SYOSCB_COMPARE_BASE_H_
#define CL_SYOSCB_COMPARE_BASE_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_cfg.h"
#include "cl_syoscb_queue_std.h"
#include "cl_syoscb_item.h"

class cl_syoscb_compare_base: public uvm::uvm_object{
    public:
        // Configuration
        cl_syoscb_cfg* cfg; 

        // Values
        int number_of_queues;

        // Constructor 
        UVM_OBJECT_UTILS(cl_syoscb_compare_base);

        cl_syoscb_compare_base(const std::string& name)
        : uvm::uvm_object(name)
        {
            // Checking for configuration element
            if(!uvm::uvm_config_db<cl_syoscb_cfg*>::get(NULL,"*","cfg",this->cfg)){
                UVM_FATAL("CFG_ERROR", "No configuration in compare io");
            }
            this->number_of_queues = this->cfg->num_of_queues; 
        };

        // Functions
        virtual void primary_loop_do(cl_syoscb_queue_std** queues);
        virtual bool compare_do(cl_syoscb_item primary_item, cl_syoscb_item secondary_item);

};

#endif