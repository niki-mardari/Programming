// Modules connected via positioning 

module mod_a(input a, input b,  input c,  input d, output out1, output out2);

wire[19:0] top, bottom;
wire middle;

assign top = {{5{a}}, {5{b}}, {5{c}}, {5{d}}};
assign bottom = {5{~{a,b,c,d}}};
assign middle = a ^ b ^ c ^ d; 

assign out1 = ~top ^ bottom;
assign out2 = middle || ( ~top ^ bottom );

endmodule

module top_module ( 
    input a, 
    input b, 
    input c,
    input d,
    output out1,
    output out2
);
    
    mod_a example(a, b, c, d, out1, out2);

endmodule