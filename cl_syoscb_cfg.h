#ifndef CL_SYOSCB_CFG_H_
#define CL_SYOSCB_CFG_H_

#include <systemc>
#include <uvm>

enum scb_compare_type{
    SYOSCB_COMPARE_IO,
    SYOSCB_COMPARE_IO2HP,
    SYOSCB_COMPARE_IOP
};

class cl_syoscb_cfg: public uvm::uvm_object{
    public:
        
        // Constructor 
        UVM_OBJECT_UTILS(cl_syoscb_cfg);

        cl_syoscb_cfg(const std::string& name):
        uvm::uvm_object(name)
        {}

        // Values
        int num_of_queues = 2;
        scb_compare_type compare_strategy = SYOSCB_COMPARE_IO;       // Default compare IO
        int max_queue_size = 0;                         // Default 0 -> unlimited items

        // Functions
        void set_number_of_queues(int n); 
        void set_queue_size(int n);
        void set_compare_type(scb_compare_type n);
};

#endif