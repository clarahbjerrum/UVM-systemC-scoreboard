#ifndef CL_SYOSCB_H_
#define CL_SYOSCB_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_cfg.h"
#include "cl_syoscb_queue_std.h"
#include "cl_syoscb_item.h"
#include "cl_syoscb_compare.h"

class cl_syoscb: public uvm::uvm_scoreboard{
    public:
        // Scoreboard configuration
        cl_syoscb_cfg* cfg;

        // Handle to the queues
        cl_syoscb_queue_std** queues;

        // Handle to the compare strategy
        cl_syoscb_compare* compare_strategy;

        // Number of queues
        int number_of_queues;

        // Constructor 
        UVM_COMPONENT_UTILS(cl_syoscb);
        cl_syoscb(uvm::uvm_component_name name):
        uvm::uvm_scoreboard(name)
        {}

        // UVM Phase methods 
        void build_phase(uvm::uvm_phase& phase);

        // Functions
        void add_item(int n, cl_syoscb_item* item);
        int queue_size(int n);
        void compare_trigger();
};


#endif