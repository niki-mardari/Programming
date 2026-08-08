// Create a module with one input and one output that behaves like a wire.

// Wires in Verilog are directional, meaning that it only flows in one direction.
// Source -> sink 
// Input is the source 
// Output is the sink

module top_module( input a, output b ); // one input and one output

assign b = a; // Assigning the input to the output, behaves like a wire

endmodule // End of module