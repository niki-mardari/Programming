// Modules connected via name

module mod_a(input a, input b, input c_in, output sum, output c_out);

assign sum = (a ^ b ^ c_in);
assign c_out = (a & b) | (b & c_in) | (a & c_in);

endmodule

module top_module(input a, input b, input c, output out1, output out2);

mod_a full_adder(.a(a), .b(b), .c_in(c), .sum(out1), .c_out(out2));

endmodule

/*
// Lab example:
module mod_a(input in1, input in2, input in3, input in4, output out1, output out2);
assign out1 = in1 & in2;
assign out2 = in3 & in4;
endmodule

module top_module(input a, input b, input c, intput d, output out1, output out2);

mod_a name(.in1(a), .in2(b), .in3(c), .in4(d), .out1(out1), .out2(out2));

endmodule
*/