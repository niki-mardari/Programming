// Implementing 2 16bit adders 
module add16 ( 
    input  [15:0] a, 
    input  [15:0] b, 
    input         cin, 
    output [15:0] sum, 
    output        cout 
);
    // Automatically handles the 16-bit sum and the 1-bit carry-out
    assign {cout, sum} = a + b + cin; 
endmodule

module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire w1;
    // module add16 ( input[15:0] a, input[15:0] b, input cin, output[15:0] sum, output cout );
    add16 add1 ( .a(a[15:0]), .b(b[15:0]), .cin(0), .sum(sum[15:0]), .cout(w1) );
    add16 add2 ( .a(a[31:16]), .b(b[31:16]), .cin(w1), .sum(sum[31:16]), .cout(0) );
    
endmodule
