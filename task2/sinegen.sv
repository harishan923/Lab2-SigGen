module sinegen #(
    parameter A_WIDTH = 8,
              D_WIDTH = 8
)(
    //interface signals
    input logic clk,
    input logic rst,
    input logic en,
    input logic [D_WIDTH-1:0] incr,
    output logic [D_WIDTH-1:0] dout1,
    output logic [D_WIDTH-1:0] dout2
);

    logic [A_WIDTH-1:0] count1;
    logic [A_WIDTH-1:0] count2;
    logic [A_WIDTH-1:0] addr1;
    logic [A_WIDTH-1:0] addr2;// = addr1 + 7'b1000000;

counter addrCounter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .count1 (addr1),
    .count2 (addr2)
);

rom sineRom (
    .clk (clk),
    .addr1 (addr1),
    .addr2 (addr2),
    .dout1 (dout1),
    .dout2 (dout2)
);
endmodule
