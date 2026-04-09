// ─────────────────────────────────────────────────────────────
// AllDifferentProcess
//
//! Runs three iterations of AllDifferent_Simple followed by
//! SingletonDetection_WithoutDeadend in series.
//!
//! Each iteration:
//!   1. AllDifferent_Simple — remove placed tiles from all
//!      remaining active variables' domains.
//!   2. SingletonDetection_WithoutDeadend — detect and lock any
//!      variable with only one tile remaining, updating the
//!      unassigned masks accordingly.
//!
//! Three iterations allow cascading — a singleton detected in
//! iteration 1 may enable further AllDifferent pruning in
//! iteration 2, and so on.
//!
//! Parameters
//!   N — board side length (board is N x N)
//!   V — N * N
// ─────────────────────────────────────────────────────────────
module AllDifferentProcess #(
    parameter int N = 4,
    parameter int V = N * N
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

    // ── Iteration 0 — AllDifferent then Singleton ─────────────
    logic [V-1:0][V-1:0] ad0_r0, ad0_r1, ad0_r2, ad0_r3;

    AllDifferent #(.N(N), .V(V)) all_different_0 (
        .in_domain_r0           (in_domain_r0),
        .in_domain_r1           (in_domain_r1),
        .in_domain_r2           (in_domain_r2),
        .in_domain_r3           (in_domain_r3),
        .in_unassignedVariables (in_unassigned_variables),
        .in_unassignedTiles     (in_unassigned_tiles),
        .out_domain_r0          (ad0_r0),
        .out_domain_r1          (ad0_r1),
        .out_domain_r2          (ad0_r2),
        .out_domain_r3          (ad0_r3)
    );

    logic [V-1:0][V-1:0] sd0_r0, sd0_r1, sd0_r2, sd0_r3;
    logic [V-1:0]        sd0_uv, sd0_ut;

    SingletonAssignment #(.N(N), .V(V)) singleton_0 (
        .in_unassignedVariables  (in_unassigned_variables),
        .in_unassignedTiles      (in_unassigned_tiles),
        .in_domain_r0            (ad0_r0),
        .in_domain_r1            (ad0_r1),
        .in_domain_r2            (ad0_r2),
        .in_domain_r3            (ad0_r3),
        .out_unassignedVariables (sd0_uv),
        .out_unassignedTiles     (sd0_ut),
        .out_domain_r0           (sd0_r0),
        .out_domain_r1           (sd0_r1),
        .out_domain_r2           (sd0_r2),
        .out_domain_r3           (sd0_r3)
    );

    // ── Iteration 1 ───────────────────────────────────────────
    logic [V-1:0][V-1:0] ad1_r0, ad1_r1, ad1_r2, ad1_r3;

    AllDifferent #(.N(N), .V(V)) all_different_1 (
        .in_domain_r0           (sd0_r0),
        .in_domain_r1           (sd0_r1),
        .in_domain_r2           (sd0_r2),
        .in_domain_r3           (sd0_r3),
        .in_unassignedVariables (sd0_uv),
        .in_unassignedTiles     (sd0_ut),
        .out_domain_r0          (ad1_r0),
        .out_domain_r1          (ad1_r1),
        .out_domain_r2          (ad1_r2),
        .out_domain_r3          (ad1_r3)
    );

    logic [V-1:0][V-1:0] sd1_r0, sd1_r1, sd1_r2, sd1_r3;
    logic [V-1:0]        sd1_uv, sd1_ut;

    SingletonAssignment #(.N(N), .V(V)) singleton_1 (
        .in_unassignedVariables  (sd0_uv),
        .in_unassignedTiles      (sd0_ut),
        .in_domain_r0            (ad1_r0),
        .in_domain_r1            (ad1_r1),
        .in_domain_r2            (ad1_r2),
        .in_domain_r3            (ad1_r3),
        .out_unassignedVariables (sd1_uv),
        .out_unassignedTiles     (sd1_ut),
        .out_domain_r0           (sd1_r0),
        .out_domain_r1           (sd1_r1),
        .out_domain_r2           (sd1_r2),
        .out_domain_r3           (sd1_r3)
    );

    // ── Iteration 2 ───────────────────────────────────────────
    logic [V-1:0][V-1:0] ad2_r0, ad2_r1, ad2_r2, ad2_r3;

    AllDifferent #(.N(N), .V(V)) all_different_2 (
        .in_domain_r0           (sd1_r0),
        .in_domain_r1           (sd1_r1),
        .in_domain_r2           (sd1_r2),
        .in_domain_r3           (sd1_r3),
        .in_unassignedVariables (sd1_uv),
        .in_unassignedTiles     (sd1_ut),
        .out_domain_r0          (ad2_r0),
        .out_domain_r1          (ad2_r1),
        .out_domain_r2          (ad2_r2),
        .out_domain_r3          (ad2_r3)
    );

    logic [V-1:0][V-1:0] sd2_r0, sd2_r1, sd2_r2, sd2_r3;
    logic [V-1:0]        sd2_uv, sd2_ut;

    SingletonAssignment #(.N(N), .V(V)) singleton_2 (
        .in_unassignedVariables  (sd1_uv),
        .in_unassignedTiles      (sd1_ut),
        .in_domain_r0            (ad2_r0),
        .in_domain_r1            (ad2_r1),
        .in_domain_r2            (ad2_r2),
        .in_domain_r3            (ad2_r3),
        .out_unassignedVariables (sd2_uv),
        .out_unassignedTiles     (sd2_ut),
        .out_domain_r0           (sd2_r0),
        .out_domain_r1           (sd2_r1),
        .out_domain_r2           (sd2_r2),
        .out_domain_r3           (sd2_r3)
    );

    // ── Final outputs ─────────────────────────────────────────
    assign out_domain_r0            = sd2_r0;
    assign out_domain_r1            = sd2_r1;
    assign out_domain_r2            = sd2_r2;
    assign out_domain_r3            = sd2_r3;
    assign out_unassigned_variables = sd2_uv;
    assign out_unassigned_tiles     = sd2_ut;

endmodule
