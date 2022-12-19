#include <systemc>
#include <uvm>

#include "cl_syoscb_compare_base.h"

// Defines primary and secondary queue and passes items for comparison
// Must be implemented in a subclass
void cl_syoscb_compare_base::primary_loop_do(cl_syoscb_queue_std** queues){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_compare_base::primary_loop_do *MUST* be overwritten");
}

// Comparing of two given items
bool cl_syoscb_compare_base::compare_do(cl_syoscb_item primary_item, cl_syoscb_item secondary_item){
    if(primary_item.get_value() == secondary_item.get_value()){
        return true;
    } else {
        std::string out = "values are not a match: " + std::to_string(primary_item.get_value()) + " & " + std::to_string(secondary_item.get_value());
        UVM_ERROR("COMPARE_ERROR",out); 
        return false;
    }
}