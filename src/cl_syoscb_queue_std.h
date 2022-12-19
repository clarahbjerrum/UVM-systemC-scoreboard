#ifndef CL_SYOSCB_QUEUE_STD_H_
#define CL_SYOSCB_QUEUE_STD_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_queue_base.h"

class cl_syoscb_queue_std: public cl_syoscb_queue_base{
    public:
    
    // The queue
    std::deque<cl_syoscb_item> items;

    // Constructor
    UVM_COMPONENT_UTILS(cl_syoscb_queue_std);

    cl_syoscb_queue_std(uvm::uvm_component_name name):
    cl_syoscb_queue_base(name)
    {};

    // Functions
    void add_item(const cl_syoscb_item item);
    void delete_item();                
    cl_syoscb_item get_item_at(int n);  
    int get_size();                     
    bool empty();
};


#endif
