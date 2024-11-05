#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f sinegen.vcd

# run Verilator to translate Verilog into Cpp including test bench
verilator -Wall --cc --trace sinegen.sv --exe sinegen_tb.cpp

# build Cpp proj via make autogen'd by verilator
#multithreading disabled

make -C obj_dir/ -f Vsinegen.mk Vsinegen

# run executable sim file
obj_dir/Vsinegen