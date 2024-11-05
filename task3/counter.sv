module counter#(
    parameter WIDTH = 8
)(
    //interface signals
    input logic clk,
    input logic rst,
    input logic en,
    input logic [WIDTH-1:0] offset,
    output logic [WIDTH-1:0] addr1 = 1,
    output logic [WIDTH-1:0] addr2 = offset,
);

always_ff @ (posedge clk)
    if (en) begin
        addr1 <= addr1 + 3; // +3 fixes frequency
        addr2 <= addr2 + 3;
    end 
endmodule
