// A * A' = 0

module top_module(
    output zero, input one
);// Module body starts after semicolon

    assign zero = one & ~one;

endmodule
