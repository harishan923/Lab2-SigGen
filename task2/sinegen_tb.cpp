#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#define ROM_SZ 256
#define ADDRESS_WIDTH 8

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vsinegen* top = new Vsinegen;
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top-> trace (tfp, 99);
    tfp-> open ("sinegen.vcd");

    // init vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("Lab 3: Sin + Cos");

    //initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = vbdValue();

    //run sim

    for (i=0; i<1000000; i++) {
        // dump var toggle clock
        for (clk=0; clk<2; clk++){
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }
    
    top->incr = vbdValue();
    vbdPlot(int (top->dout1), 0, 255);
    vbdPlot(int (top->dout2), 0, 255);
    vbdCycle(i);
    // end of vbud out
    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='s')) 
      exit(0);                // ... exit if finish OR 'q' pressed
    
}

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}