// Create a 16-bit wide, 9-to-1 multiplexer.
// sel=0 chooses a, sel=1 chooses b, etc. 
// For the unused cases (sel=9 to 15), 
// set all output bits to '1'.

module top_module( 
    input [15:0] a, b, c, d, e, f, g, h, i,
    input [3:0] sel,
    output [15:0] out );

always @(*) begin // Required for sequential/procedural logic
    case (sel)
        4'b0000 : out = a;
        4'b0001 : out = b;
        4'b0010 : out = c;
        4'b0011 : out = d;
        4'b0100 : out = e;
        4'b0101 : out = f;
        4'b0110 : out = g;
        4'b0111 : out = h;
        4'b1000 : out = i;
        default : out = 16'b11111111111111111;
    endcase
end

endmodule

