#ifndef CL_SYOSCB_COMPARE_H_
#define CL_SYOSCB_COMPARE_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_compare_base.h"
#include "cl_syoscb_compare_io.h"
#include "cl_syoscb_queue_std.h"
#include "cl_syoscb_cfg.h"


class cl_syoscb_compare: public uvm::uvm_component{
    public:
        // Comparing algorithm
        cl_syoscb_compare_base* compare_algo;

        // Scoreboard configuration
        cl_syoscb_cfg* cfg;

        // Constructor 
        UVM_COMPONENT_UTILS(cl_syoscb_compare);

        cl_syoscb_compare(uvm::uvm_component_name name)
        : uvm::uvm_component(name)
        {};

        // UVM Phase methods
        void build_phase(uvm::uvm_phase& phase);

        // Functions
        void compare_trigger(cl_syoscb_queue_std** queues);
      
};


#endif