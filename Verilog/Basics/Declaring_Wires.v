// Need wires between logic gates when need one ouput from a logic gate to connect to multiple inputs 

// in1-->*-->* x
//     |
// in2---> Y

/*
module top_module(input in, ouput out);

wire not_in;
assign out = ~not_in;
assign not_in = ~in;

endmodule
*/

module top_module(input a, b, c, d, output out, out_n);

wire out_Or = (a & b) | (c & d);
assign out = out_Or;
assign out_n = ~out_Or;

endmodule