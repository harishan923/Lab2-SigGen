module counter#(
    parameter WIDTH = 8
)(
    //interface signals
    input logic clk,
    input logic rst,
    input logic en,
    input logic [WIDTH-1:0] incr,
    output logic [WIDTH-1:0] count1 = 1,
    output logic [WIDTH-1:0] count2 = incr,
);

always_ff @ (posedge clk)
    if (en) begin
        count1 <= count1 + 3; // +3 fixes frequency
        count2 <= count2 + 3;
    end 
endmodule
