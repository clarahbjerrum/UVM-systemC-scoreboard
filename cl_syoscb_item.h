#ifndef CL_SYOSCB_ITEM_H_
#define CL_SYOSCB_ITEM_H_

#include <systemc>
#include <uvm>

// This is a simplification of the uvm_sequence item as it only stores an integer value
// A comparison of two items will be a comparison of the values, not the actual items
class cl_syoscb_item: public uvm::uvm_sequence_item{
    public:
        
        // Constructor 
        UVM_OBJECT_UTILS(cl_syoscb_item);

        cl_syoscb_item(const std::string& name)
        : uvm::uvm_sequence_item(name)
        {};

        // Value 
        int value;

        // Functions
        void set_value(int n);
        int get_value();
};

#endif