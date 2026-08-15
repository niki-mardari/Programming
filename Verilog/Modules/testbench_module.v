// Making a simple testbench to simulate in iVerilog and GTKwave for module.v

`timescale 1ns/1ns

module tb_top_module;
    // 1. Create registers for inputs and a wire for the output
    reg a;
    reg b;
    wire out;

    // 2. Connect to your top_module
    top_module uut (
        .a(a),
        .b(b),
        .out(out)
    );

    // 3. Apply test signals over time
    initial begin
        // Tell the simulator to save the waveform data
        $dumpfile("waveform.vcd");
        $dumpvars(0, tb_top_module);

        // Test Case 1: a=0, b=0 (Outputs should be 1 because they match)
        a = 0; b = 0;
        #10; // Wait 10 nanoseconds

        // Test Case 2: a=0, b=1 (Outputs should be 0 because they mismatch)
        a = 0; b = 1;
        #10;

        // Test Case 3: a=1, b=1 (Outputs should be 1 because they match)
        a = 1; b = 1;
        #10;

        $finish; // End the simulation
    end
endmodule
