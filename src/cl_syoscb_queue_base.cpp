#include <systemc>
#include <uvm>

#include "cl_syoscb_queue_base.h"

// Adds item to the given queue
// Must be implemented in a subclass
void cl_syoscb_queue_base::add_item(const cl_syoscb_item item){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_queue_base::add_item *MUST* be overwritten");
}

// Deletes item from the fron of the queue
// Must be implemented in a subclass
void cl_syoscb_queue_base::delete_item(){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_queue_base::delete_item *MUST* be overwritten");
}

// Return item at index n
// Must be implemented in a subclass
cl_syoscb_item cl_syoscb_queue_base::get_item_at(int n){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_queue_base::get_item_at *MUST* be overwritten");
    return *(new cl_syoscb_item("item0"));
} 

// Return size of queue
// Must be implemented in a subclass
int cl_syoscb_queue_base::get_size(){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_queue_base::get_size *MUST* be overwritten");
    return -1;
}    

// Returns true if queue is empty otherwise false
// Must be implemented in a subclass
bool cl_syoscb_queue_base::empty(){
    UVM_FATAL("IMPL_ERROR", "cl_syoscb_queue_base::empty *MUST* be overwritten");
    return true;
}