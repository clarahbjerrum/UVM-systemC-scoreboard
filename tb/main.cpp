#include <systemc>
#include <uvm>


#include "cl_uvm_test_2qs_all_matches.h"
#include "cl_uvm_test_2qs_1mismatch.h"
#include "cl_uvm_test_2qs_5unmatched.h"
#include "cl_uvm_test_nqs_all_matches.h"
#include "cl_uvm_test_nqs_5mismatches.h"
#include "cl_uvm_test_nqs_max_items.h"

using namespace sc_core;

int sc_main(int, char* argv[]){
    std::string test_name = argv[1];

    // Running test
    uvm::run_test(test_name);

    return 0;
}