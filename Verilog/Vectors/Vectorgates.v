// Build a circuit that has two 3-bit inputs that computes the bitwise-OR of the two vectors, 
// the logical-OR of the two vectors, and the inverse (NOT) of both vectors. 
// Place the inverse of b in the upper half of out_not (i.e., bits [5:3]), 
// and the inverse of a in the lower half.

module top_module( 
    input [2:0] a,
    input [2:0] b,
    output [2:0] out_or_bitwise,
    output out_or_logical,
    output [5:0] out_not
);
    // Bitwise or (|)
    assign out_or_bitwise[0] = ( a[0] | b[0] );
    assign out_or_bitwise[1] = ( a[1] | b[1] );
    assign out_or_bitwise[2] = ( a[2] | b[2] );
    
    // Logical or (||)
    assign out_or_logical = ( a || b );
    
    assign out_not = {~b, ~a};
    // Or do this: 
    // 	assign out_not[2:0] = ~a;	// Part-select on left side is o.
	// assign out_not[5:3] = ~b;	//Assigning to [5:3] does not conflict with [2:0]

endmodule