#include <systemc>
#include <uvm>

#include "cl_syoscb_item.h"

// Setting value of item
void cl_syoscb_item::set_value(int n){
    value = n;
}

// Returning value of item
int cl_syoscb_item::get_value(){
    return value;
}
