#include <systemc>
#include <uvm>

#include "cl_syoscb_compare_io.h"

// Comparing of all queues
void cl_syoscb_compare_io::primary_loop_do(cl_syoscb_queue_std** queues){

    // Assigning queues as primary or secondary queues
    // First queue is assigned as primary
    this->primary_queue = queues[0];
    this->secondary_queues = new cl_syoscb_queue_std*[this->number_of_queues-1];
    
    // Remaining queues are assigned as secondary
    for(int n=0; n<this->number_of_queues-1; n++){
        this->secondary_queues[n] = queues[n+1];
    }

    // Looping through queues and comparing
    for(int n=0; n<this->number_of_queues-1; n++){
        if (!cl_syoscb_compare_base::compare_do(primary_queue->get_item_at(0),secondary_queues[n]->get_item_at(0))){
            break;
        }
    }

    // Removing items from queue
    for(int n=0; n<this->number_of_queues; n++){
            queues[n]->delete_item();
    }
    
}
