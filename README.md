# UVM-systemC-scoreboard

This is a scoreboard for UVM-SystemC created as part of my bachelor project at DTU.

This UVM-SystemC scoreboard has been compiled using [SystemC 2.3.3](https://www.accellera.org/downloads/standards/systemc), [UVM-SystemC 1.0.4-beta](https://www.accellera.org/downloads/drafts-review) and GNU GCC 9.3.3

The installation files should be added to be LD_LIBRARY_PATH: 
```
setenv LD_LIBRARY_PATH /home/clara/Programs/systemc-2.3.3/lib-linux64:/home/clara/Programs/uvm-systemc-1.0-beta4/lib-linux64
```


The scoreboard application and its test can be run by `make`, which run the first test: cl_uvm_test_2qs_all_matches. 

To see all available tests and how to run them use: `make info`

