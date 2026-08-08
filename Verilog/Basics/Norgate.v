// Create a module that implements a NOR gate. A NOR gate is an OR gate with its output inverted. A NOR function needs two operators when written in Verilog.

module top_module(input a, b, output out);

assign out = ~(a | b);

endmodule