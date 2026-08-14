// What are modules? 
// A circuit that interacts with its outside through inputs and outputs 
// Can build larger modules out of smaller modules 

module mod_a(input in1, input in2, output out);
// Module body
assign out = ~(in1 & in2);
endmodule

module top_module(input a, input b, output out);

mod_a instance1 ( .in1(a), .in2(b), .out(out));

endmodule

/*
// In lab:

module mod_a(input in1, input in2, output out);
// Module body
endmodule

module top_module ( input a, input b, output out );
	
    mod_a instance1 (a, b, out);
    //mod_a instance2 ( .out(out), .in1(a), .in2(b) );
    
endmodule


*/