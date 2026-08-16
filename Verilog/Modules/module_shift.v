// Module shifting. This problem combines 3 D-flip-flops modules to make a 3 bit shift register

// Verilog code for Rising edge D flip flop with Synchronous Reset input 
module my_dff ( 
    input clk, 
    input d, 
    output reg q  // Must be a 'reg' to store the value
);

    always @(posedge clk) begin
        q <= d; // Simple D-FF without reset (matches standard HDLBits style)
    end 

endmodule // End of my_dff module

endmodule

module top_module ( input clk, input d, output q );
	
    wire q1, q2, q3;
    my_dff flip1( .clk(clk), .d(d), .q(q1) );
    my_dff flip2( .clk(clk), .d(q1), .q(q2) );
    my_dff flip3( .clk(clk), .d(q2), .q(q3) );
    
    assign q = q3;
    
endmodule