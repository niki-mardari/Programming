// Implementing the 7458 module in Verilog 
// https://hdlbits.01xz.net/wiki/7458

module top_module ( 
    input p1a, p1b, p1c, p1d, p1e, p1f,
    output p1y,
    input p2a, p2b, p2c, p2d,
    output p2y );

    wire and_1 = p1a & p1c & p1b;
    wire and_2 = p2a & p2b;
    wire and_3 = p1f & p1e & p1d;
    wire and_4 = p2c & p2d;

    assign p1y = and_1 | and_3;
    assign p2y = and_2 | and_4; 

endmodule