// Concatenating Vectors 

// Given several input vectors, concatenate them together then split them up into several output vectors. There are six 5-bit input vectors: a, b, c, d, e, and f, for a total of 30 bits of input. There are four 8-bit output vectors: w, x, y, and z, for 32 bits of output. The output should be a concatenation of the input vectors followed by two 1 bits:

module top_module (
    input [4:0] a, b, c, d, e, f,
    output [7:0] w, x, y, z );

    assign w[7:0] = {a[4:0], b[4:2]};
    assign x[7:0] = {b[1:0], c[4:0], d[4]};
    assign y[7:0] = {d[3:0], e[4:1]};
    assign z[7:0] = {e[0], f[4:0], 2'b11};

    endmodule

/*
// Or could do this:

module top_module (
    input [4:0] a, b, c, d, e, f,
    output [7:0] w, x, y, z );

    wire[31:0] ts = {a,b,c,d,e,f,2'b11};
    // 00000 00000 00000 00000 00000 00000 11
    assign w = ts[31:24];
    assign x = ts[23:16];
    assign y = ts[15:8];
    assign z = ts[7:0];

    endmodule