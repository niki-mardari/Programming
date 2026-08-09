// Vectors are used to group related signals using one name to make it more convenient to manipulate. For example, 
// wire [7:0] w; declares an 8-bit vector named w that is equivalent to having 8 separate wires.

// Build a combinational circuit that splits an input half-word (16 bits, [15:0] ) into lower [7:0] and upper [15:8] bytes.

// Implicit nets bug:
// assign a = 3'b101;  // a = 101
// assign b = a;       // b =   1  implicitly-created wire
// assign c = b;       // c = 001  <-- bug

// Adding `default_nettype none would make the third line of code an error, which makes the bug more visible.
// default_nettype none
// Put this at the top of the code so that it doesnt allow create implicit nets 

// Packed/ Unpacked arrays 
// bit [3:0][7:0] packed_array; // 4 elements, each 8 bits wide
// bit [7:0] unpacked_array; // 4 separate elements, each 8 bits wide

module top_module(
    input wire [15:0] in,
    output wire [7:0] out_hi,
    output wire [7:0] out_lo 
    );

    assign out_hi = in[15:8];
    assign out_lo = in[7:0];

endmodule