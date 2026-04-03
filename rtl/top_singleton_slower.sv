// ─────────────────────────────────────────────────────────────
// top_singleton_slower
//
// Minimal wrapper around SingletonDetectionSlower for timing
// comparison in Quartus Timing Analyzer.

//Steps in Quartus:

//Add both wrapper files and both implementation files to your project
//Assignments → Settings → General → Top-level entity → set to top_singleton_fast
//Processing → Start Compilation
//Note Flow Summary — ALMs used and Fmax
//Change top-level to top_singleton_slower
//Recompile and compare

//The .* port connection syntax automatically connects all ports by name so no manual wiring needed.

//In Quartus there are several stages:

//Analysis & Synthesis — parses RTL, infers logic
//Fitter/Place & Route — places logic into FPGA fabric, routes connections
//Timing Analysis — calculates actual path delays

//For a timing comparison you need all three — a full compile. The Fmax number only comes from the Timing Analyzer which runs after Place & Route.
//However — for a quick comparison of logic complexity you can just run Analysis & Synthesis alone:

//Much faster (seconds vs minutes)
//Gives you LUT count
//Does NOT give you Fmax (no placement/routing yet)

//My recommendation:

//Run full compile on both — you want the real Fmax number
//For N=4 the compile will be fast anyway since it's a small module
//The full compile is what matters for real hardware

//To run full compile:

//Processing → Start Compilation (Ctrl+L)

//To run synthesis only:

//Processing → Start → Start Analysis & Synthesis

//For your comparison purpose use the full compile so you get the definitive Fmax number from the Timing Analyzer.

// ─────────────────────────────────────────────────────────────
module top_singleton_slower #(
    parameter int N         = 4,
    parameter int VARIABLES = N * N
)(
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r3,
    input  logic [VARIABLES-1:0]                in_variablesIncludedMask,
    input  logic [VARIABLES-1:0]                in_unassignedTiles,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r0,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r1,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r2,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r3,
    output logic [VARIABLES-1:0]                out_variablesIncludedMask,
    output logic [VARIABLES-1:0]                out_unassignedTiles,
    output logic                                singleton_found,
    output logic                                deadend
);
    SingletonDetectionSlower #(.N(N)) dut (.*);
endmodule