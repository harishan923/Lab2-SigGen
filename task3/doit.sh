#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f sigdelay.vcd

# run Verilator to translate Verilog into Cpp including test bench
verilator -Wall --cc --trace sigdelay.sv --exe sigdelay_tb.cpp

# build Cpp proj via make autogen'd by verilator
#multithreading disabled

make -C obj_dir/ -f Vsigdelay.mk Vsigdelay

# run executable sim file
obj_dir/Vsigdelay