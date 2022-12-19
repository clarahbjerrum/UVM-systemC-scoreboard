# module load gnu/gcc/9.3 
# setenv LD_LIBRARY_PATH /mnt/common/itd/software/install/gnu/gcc/9.3.0/lib64:/home/clara/Programs/systemc-2.3.3/lib-linux64:/home/clara/Programs/uvm-systemc-1.0-beta4/lib-linux64

SYSTEMC_HOME = /home/clara/Programs/systemc-2.3.3
UVM_SYSTEMC_HOME =  /home/clara/Programs/uvm-systemc-1.0-beta4

SYSTEMC_LIBDIR = $(SYSTEMC_HOME)/lib-linux64
UVM_SYSTEMC_LIBDIR =$(UVM_SYSTEMC_HOME)/lib-linux64

CXX = g++

CFLAGS = -g -Wall -pedantic -Wno-long-long -Wno-unused-variable -Wno-maybe-uninitialized #-Werror
LDFLAGS = -I. -I.. -I$(SYSTEMC_HOME)/include -I$(UVM_SYSTEMC_HOME)/include

OBJS = \
main.o \
cl_syoscb.o \
cl_syoscb_queue_std.o \
cl_syoscb_queue_base.o \
cl_syoscb_item.o \
cl_syoscb_compare.o \
cl_syoscb_compare_base.o \
cl_syoscb_compare_io.o \
cl_syoscb_cfg.o \

SRC = \
tb/main.cpp \
src/cl_syoscb.cpp \
src/cl_syoscb_queue_std.cpp \
src/cl_syoscb_queue_base.cpp \
src/cl_syoscb_item.cpp \
src/cl_syoscb_compare.cpp \
src/cl_syoscb_compare_base.cpp \
src/cl_syoscb_compare_io.cpp \
src/cl_syoscb_cfg.cpp \

HEADERS = \
src/cl_syoscb.h \
src/cl_syoscb_cfg.h \
src/cl_syoscb_queue_base.h \
src/cl_syoscb_queue_std.h \
src/cl_syoscb_compare.h \
src/cl_syoscb_compare_base.h \
src/cl_syoscb_compare_io.h \
src/cl_syoscb_item.h \

TESTS = \
tb/cl_uvm_test_2qs_all_matches.h \
tb/cl_uvm_test_2qs_1mismatch.h \
tb/cl_uvm_test_2qs_5unmatched.h \
tb/cl_uvm_test_nqs_all_matches.h \
tb/cl_uvm_test_nqs_5mismatches.h \
tb/cl_uvm_test_nqs_max_items.h

test_name = cl_uvm_test_2qs_all_matches

.PHONY: all link run clean info

all: build link run

build: $(OBJS)

%.o : src/%.cpp src/%.h src/cl_syoscb_cfg.h 
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $< -o $@

main.o : tb/main.cpp $(TESTS) src/cl_syoscb_cfg.h
	$(CXX) $(CFLAGS) $(LDFLAGS) -c tb/main.cpp -o main.o

link: 
	$(CXX) $(CFLAGS) -L. -L.. -L $(SYSTEMC_LIBDIR) -L $(UVM_SYSTEMC_LIBDIR) -Wl,-rpath=$(SYSTEMC_LIBDIR) \
	-o main.x $(OBJS) -luvm-systemc -lsystemc -lm  2>&1 | c++filt 


run: main.x
	./main.x $(test_name)

clean:
	@echo "Cleaning up..."
	rm *.o
	rm *.x

info: 
	@echo "Use 'make test_name=<name>' to run specific test"
	@echo "All available tests:"
	@echo "		cl_uvm_test_2qs_all_matches"
	@echo "		cl_uvm_test_2qs_1mismatch"
	@echo "		cl_uvm_test_2qs_5unmatched"
	@echo "		cl_uvm_test_nqs_all_matches"
	@echo "		cl_uvm_test_nqs_5mismatches"
	@echo "		cl_uvm_test_nqs_max_items"