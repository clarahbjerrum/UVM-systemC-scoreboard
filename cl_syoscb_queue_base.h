#ifndef CL_SYOSCB_QUEUE_BASE_H_
#define CL_SYOSCB_QUEUE_BASE_H_

#include <systemc>
#include <uvm>

#include "cl_syoscb_item.h"

class cl_syoscb_queue_base: public uvm::uvm_component{
    public:

        // Constructor 
        UVM_COMPONENT_UTILS(cl_syoscb_queue_base);
        
        cl_syoscb_queue_base(uvm::uvm_component_name name)
        : uvm::uvm_component(name)
        {};

        //Functions
        virtual void add_item(const cl_syoscb_item item);
        virtual void delete_item();                
        virtual cl_syoscb_item get_item_at(int n);  
        virtual int get_size();                     
        virtual bool empty();
};

#endif