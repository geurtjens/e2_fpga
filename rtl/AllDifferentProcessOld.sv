// ─────────────────────────────────────────────────────────────
// AllDifferentProcess
//
//! Runs a cascade of AllDifferent_Simple followed by
//! SingletonDetection_WithoutDeadend, repeated DEPTH times.
//!
//! Each iteration:
//!   1. AllDifferent_Simple — remove placed tiles from all
//!      remaining active variables' domains.
//!   2. SingletonDetection_WithoutDeadend — detect and lock any
//!      variable with only one tile remaining, updating the
//!      unassigned masks accordingly.
//!
//! Multiple iterations allow cascading — a singleton detected in
//! iteration 1 may enable further AllDifferent pruning in
//! iteration 2.
//!
//! Parameters
//!   N     — board side length (board is N x N)
//!   V     — N * N
//!   DEPTH — number of AllDifferent/Singleton iterations
// ─────────────────────────────────────────────────────────────
module AllDifferentProcess #(
    parameter int N     = 4,
    parameter int V     = N * N,
    parameter int DEPTH = 3
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,            //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! rotation 3 domain bitmask for each variable.
    input  logic [V-1:0]        in_unassigned_variables,  //! 1=unassigned, 0=placed.
    input  logic [V-1:0]        in_unassigned_tiles,      //! 1=available, 0=placed.

    output logic [V-1:0][V-1:0] out_domain_r0,            //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,            //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,            //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3,            //! updated rotation 3 domain bitmask for each variable.
    output logic [V-1:0]        out_unassigned_variables,  //! updated 1=unassigned, 0=placed.
    output logic [V-1:0]        out_unassigned_tiles       //! updated 1=available, 0=placed.
);

    // ── Inter-stage wires ─────────────────────────────────────
    logic [V-1:0][V-1:0] iter_domain_r0 [DEPTH:0];
    logic [V-1:0][V-1:0] iter_domain_r1 [DEPTH:0];
    logic [V-1:0][V-1:0] iter_domain_r2 [DEPTH:0];
    logic [V-1:0][V-1:0] iter_domain_r3 [DEPTH:0];
    logic [V-1:0]        iter_uv        [DEPTH:0];
    logic [V-1:0]        iter_ut        [DEPTH:0];

    assign iter_domain_r0[0] = in_domain_r0;
    assign iter_domain_r1[0] = in_domain_r1;
    assign iter_domain_r2[0] = in_domain_r2;
    assign iter_domain_r3[0] = in_domain_r3;
    assign iter_uv[0]        = in_unassigned_variables;
    assign iter_ut[0]        = in_unassigned_tiles;

    // ── DEPTH iterations of AllDifferent then Singleton ───────
    
/* The warnings are all UNOPTFLAT — Verilator detected circular combinational logic in AllDifferentProcess. The issue is in the generate loop — Verilator can't prove the loop is acyclic because iter_uv is both read and written inside the same generate block, and SingletonDetection_WithoutDeadend uses in_unassignedVariables inside an always_comb that also drives out_unassignedVariables which feeds back into iter_uv.
The fix is to suppress the warning since the loop is genuinely acyclic (each iteration i only reads [i] and writes [i+1]), and also to add -Wno-UNOPTFLAT to the build args:
pythonbuild_args=["--public-flat-rw", "-Wno-WIDTHEXPAND", "-Wno-WIDTHTRUNC", "-Wno-UNOPTFLAT"], */


    /* verilator lint_off UNOPTFLAT */
    
    genvar i;
    generate
        for (i = 0; i < DEPTH; i++) begin : gen_iter

            // ── AllDifferent_Simple ───────────────────────────
            logic [V-1:0][V-1:0] ad_r0, ad_r1, ad_r2, ad_r3;

            AllDifferent_Simple #(.N(N), .V(V)) all_different (
                .in_domain_r0           (iter_domain_r0[i]),
                .in_domain_r1           (iter_domain_r1[i]),
                .in_domain_r2           (iter_domain_r2[i]),
                .in_domain_r3           (iter_domain_r3[i]),
                .in_unassignedVariables (iter_uv[i]),
                .in_unassignedTiles     (iter_ut[i]),
                .out_domain_r0          (ad_r0),
                .out_domain_r1          (ad_r1),
                .out_domain_r2          (ad_r2),
                .out_domain_r3          (ad_r3)
            );

            // ── SingletonDetection_WithoutDeadend ─────────────
            SingletonDetection_WithoutDeadend #(.N(N), .V(V)) singleton_det (
                .in_unassignedVariables  (iter_uv[i]),
                .in_unassignedTiles      (iter_ut[i]),
                .in_domain_r0            (ad_r0),
                .in_domain_r1            (ad_r1),
                .in_domain_r2            (ad_r2),
                .in_domain_r3            (ad_r3),
                .out_unassignedVariables (iter_uv[i+1]),
                .out_unassignedTiles     (iter_ut[i+1]),
                .out_domain_r0           (iter_domain_r0[i+1]),
                .out_domain_r1           (iter_domain_r1[i+1]),
                .out_domain_r2           (iter_domain_r2[i+1]),
                .out_domain_r3           (iter_domain_r3[i+1])
            );
        end
    endgenerate
    /* verilator lint_on UNOPTFLAT */
    // ── Final outputs ─────────────────────────────────────────
    assign out_domain_r0           = iter_domain_r0[DEPTH];
    assign out_domain_r1           = iter_domain_r1[DEPTH];
    assign out_domain_r2           = iter_domain_r2[DEPTH];
    assign out_domain_r3           = iter_domain_r3[DEPTH];
    assign out_unassigned_variables = iter_uv[DEPTH];
    assign out_unassigned_tiles     = iter_ut[DEPTH];

endmodule
