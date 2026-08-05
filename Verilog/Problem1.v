// Build a circuit with no inputs and one output. 
//That output should always drive 1 (or logic high).

// Start container for one hardware circuit or block
module top_module( output one ); // only output is one, could have had ( output a, input b )

assign one = 1; // Assigning one as a constant high 
// Could also write 1'b1

/*
1'b1
│ │ │
│ │ └── value (1)
│ └──── base: b = binary (also: d=decimal, h=hex, o=octal)
└────── size: how many bits wide (1 bit here)
*/


endmodule // End of module