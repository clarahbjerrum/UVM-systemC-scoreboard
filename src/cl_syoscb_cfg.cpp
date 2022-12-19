#include <systemc>
#include <uvm>

#include "cl_syoscb_cfg.h"

// Change the number of queues in configuration
void cl_syoscb_cfg::set_number_of_queues(int n){
    this->num_of_queues = n;
} 

// Set the max number of items int queue
void cl_syoscb_cfg::set_queue_size(int n){
    this->max_queue_size = n;
} 

// Set the compare type for scoreboard
// 1 = compare in order
void cl_syoscb_cfg::set_compare_type(scb_compare_type n){
    this->compare_strategy = n;
}