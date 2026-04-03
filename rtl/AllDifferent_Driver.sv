// ─────────────────────────────────────────────────────────────
// Driver
//
// Top level orchestrator. Computes tilesTaken once from the
// singleton variables then passes it into AllDifferent.
//
// The benefit is that tilesTaken is calculated a single time
// and can be shared with other constraint modules without
// each one recomputing it independently.
// ─────────────────────────────────────────────────────────────
module AllDifferent_Driver #(
    parameter int N = 8
)(
    input  logic [N-1:0][N-1:0] r0_in,
    input  logic [N-1:0][N-1:0] r1_in,
    input  logic [N-1:0][N-1:0] r2_in,
    input  logic [N-1:0][N-1:0] r3_in,
    input  logic [N-1:0]        variablesIncludedMask,
    output logic [N-1:0][N-1:0] r0_out,
    output logic [N-1:0][N-1:0] r1_out,
    output logic [N-1:0][N-1:0] r2_out,
    output logic [N-1:0][N-1:0] r3_out,
    output logic                changed,
    output logic                deadend
);
    logic [N-1:0] tilesTaken;

    AllDifferent_CalculateTilesTaken #(.N(N)) calc_tiles_taken (
        .r0_in                 (r0_in),
        .r1_in                 (r1_in),
        .r2_in                 (r2_in),
        .r3_in                 (r3_in),
        .variablesIncludedMask (variablesIncludedMask),
        .tilesTaken            (tilesTaken)
    );

    AllDifferent #(.N(N)) all_different (
        .r0_in                 (r0_in),
        .r1_in                 (r1_in),
        .r2_in                 (r2_in),
        .r3_in                 (r3_in),
        .variablesIncludedMask (variablesIncludedMask),
        .tilesTaken            (tilesTaken),
        .r0_out                (r0_out),
        .r1_out                (r1_out),
        .r2_out                (r2_out),
        .r3_out                (r3_out),
        .changed               (changed),
        .deadend               (deadend)
    );
endmodule
