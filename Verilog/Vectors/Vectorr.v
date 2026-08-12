// Given an 8-bit input vector [7:0], reverse its bit ordering. 

module top_module(input [7:0] in, output [7:0] out);

wire [7:0]in2 = {in[0], in[1], in[2], in[3], in[4], in[5], in[6], in[7]};

assign out = in2;

endmodule

/*
// Could have done this using a for loop
// A generate loop tells the compiler to automatically calculate/ 
// generate the connections before the code runs

module top_module (
    input [7:0] in,
    output [7:0] out
);

    // We use a generate block to dynamically wire the bits backward
    genvar i;
    generate
        for (i = 0; i < 8; i = i + 1) begin : bit_reverse
            assign out[i] = in[7-i];
        end
    endgenerate

endmodule

*/