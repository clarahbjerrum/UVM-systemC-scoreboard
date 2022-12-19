#include <systemc>
#include <uvm>

#include "cl_syoscb_queue_std.h"

// Adding item to queue
void cl_syoscb_queue_std::add_item(const cl_syoscb_item item){
    items.push_back(item);
}

// Delete first item from queue
void cl_syoscb_queue_std::delete_item(){
    items.pop_front();
}

// Returns item at index n
cl_syoscb_item cl_syoscb_queue_std::get_item_at(int n){
    return items[n];
}

// Return number of elements in queue
int cl_syoscb_queue_std::get_size(){
    return items.size();
}

// Returns if queue is empty or not
bool cl_syoscb_queue_std::empty(){
    return items.empty();
}