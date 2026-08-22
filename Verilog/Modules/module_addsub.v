// Problen found here: https://hdlbits.01xz.net/wiki/Module_addsub

module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
    wire cout1;
    wire[31:0] b_xor;
    
    assign b_xor = b ^ {32{sub}};
    
    add16 instance1 ( .a(a[15:0]), .b(b_xor[15:0]), .cin(sub), .sum(sum[15:0]), .cout(cout1));
    add16 instance2 ( .a(a[31:16]), .b(b_xor[31:16]), .cin(cout1), .sum(sum[31:16]), .cout(0));

endmodule


module add16 ( input[15:0] a, 
               input[15:0] b, 
               input cin, 
               output[15:0] sum, 
               output cout 
             );

assign {sum, cout} = a + b + cin;

endmodule 
