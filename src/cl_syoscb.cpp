#include <systemc>
#include <uvm>

#include "cl_syoscb.h"


void cl_syoscb::build_phase(uvm::uvm_phase& phase){
    if(!uvm::uvm_config_db<cl_syoscb_cfg*>::get(this,"scb","cfg",this->cfg)){
        UVM_ERROR("CFG_ERROR", "No configuration from env");
    }

    // Instantiating the number of queues defined in cfg
    this->number_of_queues = this->cfg->num_of_queues;
    this->queues = new cl_syoscb_queue_std*[this->number_of_queues];

    // Reporting info on number of queues
    UVM_INFO("QUEUE", "Creating " + std::to_string(this->number_of_queues) + " queues in scoreboard",uvm::UVM_MEDIUM);

    // Creating and adding each queue of unique name to queues[]
    char buffer [10];
    for(int n=0; n<this->number_of_queues; n++){
        sprintf (buffer, "queue%d", n);
        this->queues[n] = cl_syoscb_queue_std::type_id::create(buffer,this);
    }

    // Instantiating compare strategy
    this->compare_strategy = cl_syoscb_compare::type_id::create("compare_strategy",this);
}

// Adding an item "item" to queue n
void cl_syoscb::add_item(int n, cl_syoscb_item* item){
    // Checking if max queue size is reached, default 0 means unlimited queue size
    if(this->cfg->max_queue_size > 0 && this->queues[n]->get_size() == this->cfg->max_queue_size){
        UVM_FATAL("QUEUE_ERROR", "Reached limit for queue size");
    }
    // Adding item to given queue
    this->queues[n]->add_item(*item);

    // Calling compare trigger to compare elements
    this->compare_trigger();
}

int cl_syoscb::queue_size(int n){
    // Returning size of queue n
    return this->queues[n]->get_size();
}


void cl_syoscb::compare_trigger(){
    bool flag = true;

    // Determing if all queues have items
    for(int n=0; n<this->number_of_queues; n++){
        if(this->queues[n]->get_size() < 1){
            flag = false;
            break;
        }
    }
    
    // If all queues contain items compare strategy is called
    if(flag){
        this->compare_strategy->compare_trigger(queues);
    }
}