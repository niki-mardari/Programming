// Implementing three 16 bit adder modules
// the second module is two 16 bit addders 
// So in total there are two 16 bit modules 
// The second 16 bit module consists of duplicate 16 bit adders 
// Carry into the 16 bit module can have a massive delay when going into the carry in 
// This is Read After Write (RAW) Hazard 
// Essentially we solve this by duplicating the two modules and using a 2-to-1 mux 
// To allow both possible options to calculate and select the correct result 

// carry-select adder

module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
    wire cout1;
    wire[15:0] sum0, sum1;
    
    add16 instance1 ( .a(a[15:0]),  .b(b[15:0]), .cin(0), .sum(sum[15:0]), .cout(cout1) );
    
    add16 instance2 ( .a(a[31:16]),  .b(b[31:16]), .cin(1'b0), .sum(sum0[15:0]), .cout(0) );
    add16 instance3 ( .a(a[31:16]),  .b(b[31:16]), .cin(1'b1), .sum(sum1[15:0]), .cout(0) );
	
    assign sum[31:16] = cout1 ? sum1 : sum0;

endmodule


// Simple 2 bit adder 
module add1 ( input a, input b, input cin,   output sum, output cout );

// Full adder module here
    assign {cout, sum} = a + b + cin; 

endmodule

// Previous add16 module I created:
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

module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);

add16 instance1 ( input[15:0] a, input[15:0] b, input cin, output[15:0] sum, .cout(cout) );

endmodule


/* 
// Apparently could have used a Switch case option:
// Lesson learned, can't have wire or instances of a mdoule inside an always block 
// This causes a multi driver conflict 
// Instead use a temporary register which holds the upper 16 bits 
// When deciding 
// This way many things are not changing sum1 or sum0 which hold the final decided values

module top_module( 
    input [31:0] a, 
    input [31:0] b, 
    output [31:0] sum 
);

    wire cout1; 
    wire [15:0] sum0; 
    wire [15:0] sum1;
    
    // 1. Create a 16-bit register to hold the chosen upper half
    reg [15:0] selected_upper_sum;

    // Lower 16-bit adder
    add16 instance1 ( 
        .a(a[15:0]), 
        .b(b[15:0]), 
        .cin(1'b0), 
        .sum(sum[15:0]), // Directly drives the lower half of the output
        .cout(cout1) 
    );

    // Upper 16-bit adder (assuming carry is 0)
    add16 instance2 ( 
        .a(a[31:16]), 
        .b(b[31:16]), 
        .cin(1'b0), 
        .sum(sum0),      
        .cout()          
    );

    // Upper 16-bit adder (assuming carry is 1)
    add16 instance3 ( 
        .a(a[31:16]), 
        .b(b[31:16]), 
        .cin(1'b1), 
        .sum(sum1),      
        .cout()          
    );

    // 2. The switch case block to choose the upper half
    always @(*) begin
        case(cout1)
            1'b0: selected_upper_sum = sum0; // If carry is 0, choose sum0
            1'b1: selected_upper_sum = sum1; // If carry is 1, choose sum1
            default: selected_upper_sum = sum0; // Safe backup
        endcase
    end

    // 3. Connect the chosen upper half to the final output wire
    assign sum[31:16] = selected_upper_sum;

endmodule


*/