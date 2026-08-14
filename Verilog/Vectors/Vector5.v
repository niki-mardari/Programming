module top_module (
    input a, b, c, d, e,
    output [24:0] out 
);

    // Group 1: Comparing 'a' with a, b, c, d, e
    assign out[24] = ~a ^ a;
    assign out[23] = ~a ^ b;
    assign out[22] = ~a ^ c;
    assign out[21] = ~a ^ d;
    assign out[20] = ~a ^ e;

    // Group 2: Comparing 'b' with a, b, c, d, e
    assign out[19] = ~b ^ a;
    assign out[18] = ~b ^ b;
    assign out[17] = ~b ^ c;
    assign out[16] = ~b ^ d;
    assign out[15] = ~b ^ e;

    // Group 3: Comparing 'c' with a, b, c, d, e
    assign out[14] = ~c ^ a;
    assign out[13] = ~c ^ b;
    assign out[12] = ~c ^ c;
    assign out[11] = ~c ^ d;
    assign out[10] = ~c ^ e;

    // Group 4: Comparing 'd' with a, b, c, d, e
    assign out[9]  = ~d ^ a;
    assign out[8]  = ~d ^ b;
    assign out[7]  = ~d ^ c;
    assign out[6]  = ~d ^ d;
    assign out[5]  = ~d ^ e;

    // Group 5: Comparing 'e' with a, b, c, d, e
    assign out[4]  = ~e ^ a;
    assign out[3]  = ~e ^ b;
    assign out[2]  = ~e ^ c;
    assign out[1]  = ~e ^ d;
    assign out[0]  = ~e ^ e;

endmodule

/* 
// Or just do this:

module top_module ( 
    input a, b, c, d, e, 
    output [24:0] out 
);

    // Vector 1: aaaaa_bbbbb_ccccc_ddddd_eeeee (NOTS)
    // Vector 2: abcde_abcde_abcde_abcde_abcde
    assign out = ~{ {5{a}}, {5{b}}, {5{c}}, {5{d}}, {5{e}} } ^ { 5{a,b,c,d,e} };

endmodule

*/

// Or like this:
/*
	wire [24:0] top, bottom;
	assign top    = { {5{a}}, {5{b}}, {5{c}}, {5{d}}, {5{e}} };
	assign bottom = {5{a,b,c,d,e}};
	assign out = ~top ^ bottom;	// Bitwise XNOR

*/