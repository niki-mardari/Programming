// Making an 8 bit shift register 
// and implementing a multiplexer to select the output 

module my_diff8(input clk, input [7:0] d, output [7:0] q);

    always @(posedge clk) begin
        q <= d; // Simple D-FF without reset (matches standard HDLBits style)
    end 

endmodule

module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);

wire [7:0] q1, q2, q3;

    my_dff8 shift1( .clk(clk), .d(d), .q(q1) );
    my_dff8 shift2( .clk(clk), .d(q1), .q(q2) );
    my_dff8 shift3( .clk(clk), .d(q2), .q(q3) ); // shift3 now outputs to q3 instead of overriding q

	always @(*)		// Combinational always block    
    case (sel)
        2'b00 : q = d;
        2'b01 : q = q1;
        2'b10 : q = q2;
        2'b11 : q = q3;
        default : q = 8'b0;
    endcase

endmodule