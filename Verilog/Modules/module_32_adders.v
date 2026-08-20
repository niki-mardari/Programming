// These are two 16 bit modules that combine 16 adders each 
// https://hdlbits.01xz.net/wiki/Module_fadd

module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//
    wire cout1;
    
    add16 instance1 ( .a(a[15:0]), .b(b[15:0]), .cin(0), .sum(sum[15:0]), .cout(cout1) );
    add16 instance2 ( .a(a[31:16]), .b(b[31:16]), .cin(cout1), .sum(sum[31:16]), .cout(0) );
    
endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );

// Full adder module here
    assign {cout, sum} = a + b + cin; 

endmodule

// Sample add16 module  (Not entirely the same as HDL bits problem "Module Fadd")
module add16 ( input[15:0] a, input[15:0] b, input cin, output[15:0] sum, output cout );

    wire [16:0] total;
    assign total[0] = cin;
    assign cout = total[16]; 
    genvar i; // 1. Declare the loop variable first

    generate
        // 2. Setup the loop inside a procedural block
        for (i = 0; i < 16; i = i + 1) begin : adder_loop
            // Your code here
            add1 instance1 (.a(a[i]), .b(b[i]), .cin(total[i]), .sum(sum[i]), .cout(total[i+1]) );
        end

endmodule

