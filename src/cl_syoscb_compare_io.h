#ifndef CL_SYOSCB_COMPARE_IO_H_
#define CL_SYOSCB_COMPARE_IO_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_compare_base.h"

class cl_syoscb_compare_io: public cl_syoscb_compare_base {
    public:
    
        // The queue handels
        cl_syoscb_queue_std* primary_queue;
        cl_syoscb_queue_std** secondary_queues;

        // Constructor 
        UVM_OBJECT_UTILS(cl_syoscb_compare_io);

        cl_syoscb_compare_io(const std::string& name)
        : cl_syoscb_compare_base(name)
        {}

        // Functions for IO compare
        void primary_loop_do(cl_syoscb_queue_std** queues);
        
};


#endif