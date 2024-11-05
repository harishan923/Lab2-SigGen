module sigdelay #(
    parameter A_WIDTH = 8,
              D_WIDTH = 8
)(
    //interface signals
    input logic clk,
    input logic rst,
    input logic en,
    input logic wr,
    input logic rd,
    input logic [D_WIDTH-1:0] offset,
    input logic [D_WIDTH-1:0] din,
    output logic [D_WIDTH-1:0] dout
);

    logic [A_WIDTH-1:0] wr_addr;
    logic [A_WIDTH-1:0] rd_addr;
    
    
counter addrCounter (
    .clk (clk),
    .rst (rst),
    .en (en),
    .offset (offset),
    .addr1 (wr_addr),
    .addr2 (rd_addr)
);

ram dualRam (
    .clk (clk),
    .wr_en(wr),
    .rd_en(rd),
    .addr1 (wr_addr),
    .addr2 (rd_addr),
    .din (din),
    .dout (dout)
);
endmodule
