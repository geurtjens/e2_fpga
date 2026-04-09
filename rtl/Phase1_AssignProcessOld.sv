// ─────────────────────────────────────────────────────────────
// Phase1_AssignProcess
//
//! Assigns a tile to a variable then runs initial constraint
//! propagation matching the C++ Phase1_AssignProcess:
//!
//! Step 1 — Assignment:
//!   Lock domain, set colours, propagate to neighbours,
//!   update availability masks.
//!
//! Step 2 & 3 — AllDifferentProcess (DEPTH iterations):
//!   Each iteration runs AllDifferent_Simple then
//!   SingletonDetection_WithoutDeadend — removing placed tiles
//!   from domains and locking any newly forced singletons.
//!
//! Step 4 — DomainToColour:
//!   Recompute colour masks for every variable from the
//!   settled domains.
//!
//! Parameters
//!   N     — board side length (board is N x N)
//!   CC    — total colour bits per edge
//!   V     — N * N
//!   DEPTH — number of AllDifferent/Singleton iterations
// ─────────────────────────────────────────────────────────────
module Phase1_AssignProcess #(
    parameter int N     = 4,
    parameter int CC    = 6,
    parameter int V     = N * N
)(
    // ── Assignment inputs ──────────────────────────────────────
    input  logic [$clog2(V)-1:0] in_variableId,
    input  logic [$clog2(V)-1:0] in_tileId,
    input  logic [1:0]           in_rotation,

    // ── Availability mask inputs ───────────────────────────────
    input  logic [V-1:0] in_unassigned_variables,
    input  logic [V-1:0] in_unassigned_tiles,

    // ── Colour inputs ─────────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,
    input  logic [V-1:0][CC-1:0] in_colours_right,
    input  logic [V-1:0][CC-1:0] in_colours_bottom,
    input  logic [V-1:0][CC-1:0] in_colours_left,

    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0,
    input  logic [V-1:0][V-1:0] in_domain_r1,
    input  logic [V-1:0][V-1:0] in_domain_r2,
    input  logic [V-1:0][V-1:0] in_domain_r3,

    // ── Tile element inputs ────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_elements_top,
    input  logic [V-1:0][CC-1:0] in_elements_right,
    input  logic [V-1:0][CC-1:0] in_elements_bottom,
    input  logic [V-1:0][CC-1:0] in_elements_left,

    // ── Colour outputs ────────────────────────────────────────
    output logic [V-1:0][CC-1:0] out_colours_top,
    output logic [V-1:0][CC-1:0] out_colours_right,
    output logic [V-1:0][CC-1:0] out_colours_bottom,
    output logic [V-1:0][CC-1:0] out_colours_left,

    // ── Domain outputs ────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0,
    output logic [V-1:0][V-1:0] out_domain_r1,
    output logic [V-1:0][V-1:0] out_domain_r2,
    output logic [V-1:0][V-1:0] out_domain_r3,

    // ── Availability mask outputs ─────────────────────────────
    output logic [V-1:0] out_unassigned_variables,
    output logic [V-1:0] out_unassigned_tiles
);

    // ── Step 1 — Assignment ───────────────────────────────────
    logic [V-1:0][CC-1:0] after_assign_colours_top;
    logic [V-1:0][CC-1:0] after_assign_colours_right;
    logic [V-1:0][CC-1:0] after_assign_colours_bottom;
    logic [V-1:0][CC-1:0] after_assign_colours_left;
    logic [V-1:0][V-1:0]  after_assign_domain_r0;
    logic [V-1:0][V-1:0]  after_assign_domain_r1;
    logic [V-1:0][V-1:0]  after_assign_domain_r2;
    logic [V-1:0][V-1:0]  after_assign_domain_r3;
    logic [V-1:0]          after_assign_uv;
    logic [V-1:0]          after_assign_ut;

    Assignment #(.N(N), .CC(CC), .V(V)) assignment (
        .in_variableId           (in_variableId),
        .in_tileId               (in_tileId),
        .in_rotation             (in_rotation),
        .in_unassigned_variables (in_unassigned_variables),
        .in_unassigned_tiles     (in_unassigned_tiles),
        .in_colours_top          (in_colours_top),
        .in_colours_right        (in_colours_right),
        .in_colours_bottom       (in_colours_bottom),
        .in_colours_left         (in_colours_left),
        .in_domain_r0            (in_domain_r0),
        .in_domain_r1            (in_domain_r1),
        .in_domain_r2            (in_domain_r2),
        .in_domain_r3            (in_domain_r3),
        .in_elements_top         (in_elements_top),
        .in_elements_right       (in_elements_right),
        .in_elements_bottom      (in_elements_bottom),
        .in_elements_left        (in_elements_left),
        .out_colours_top         (after_assign_colours_top),
        .out_colours_right       (after_assign_colours_right),
        .out_colours_bottom      (after_assign_colours_bottom),
        .out_colours_left        (after_assign_colours_left),
        .out_domain_r0           (after_assign_domain_r0),
        .out_domain_r1           (after_assign_domain_r1),
        .out_domain_r2           (after_assign_domain_r2),
        .out_domain_r3           (after_assign_domain_r3),
        .out_unassigned_variables(after_assign_uv),
        .out_unassigned_tiles    (after_assign_ut)
    );

    // ── Steps 2 & 3 — AllDifferentProcess ────────────────────
    logic [V-1:0][V-1:0] after_adp_r0;
    logic [V-1:0][V-1:0] after_adp_r1;
    logic [V-1:0][V-1:0] after_adp_r2;
    logic [V-1:0][V-1:0] after_adp_r3;
    logic [V-1:0]        after_adp_uv;
    logic [V-1:0]        after_adp_ut;

    AllDifferentProcess #(.N(N), .V(V)) all_different_process (
        .in_domain_r0            (after_assign_domain_r0),
        .in_domain_r1            (after_assign_domain_r1),
        .in_domain_r2            (after_assign_domain_r2),
        .in_domain_r3            (after_assign_domain_r3),
        .in_unassigned_variables (after_assign_uv),
        .in_unassigned_tiles     (after_assign_ut),
        .out_domain_r0           (after_adp_r0),
        .out_domain_r1           (after_adp_r1),
        .out_domain_r2           (after_adp_r2),
        .out_domain_r3           (after_adp_r3),
        .out_unassigned_variables(after_adp_uv),
        .out_unassigned_tiles    (after_adp_ut)
    );

    assign out_unassigned_variables = after_adp_uv;
    assign out_unassigned_tiles     = after_adp_ut;

    // ── Step 4 — DomainToColour ───────────────────────────────
    DomainToColour #(.N(N), .CC(CC), .V(V)) domain_to_colour (
        .in_domain_r0       (after_adp_r0),
        .in_domain_r1       (after_adp_r1),
        .in_domain_r2       (after_adp_r2),
        .in_domain_r3       (after_adp_r3),
        .in_colours_top     (after_assign_colours_top),
        .in_colours_right   (after_assign_colours_right),
        .in_colours_bottom  (after_assign_colours_bottom),
        .in_colours_left    (after_assign_colours_left),
        .in_elements_top    (in_elements_top),
        .in_elements_right  (in_elements_right),
        .in_elements_bottom (in_elements_bottom),
        .in_elements_left   (in_elements_left),
        .out_colours_top    (out_colours_top),
        .out_colours_right  (out_colours_right),
        .out_colours_bottom (out_colours_bottom),
        .out_colours_left   (out_colours_left)
    );

    // ── Domain outputs pass through from AllDifferentProcess ──
    assign out_domain_r0 = after_adp_r0;
    assign out_domain_r1 = after_adp_r1;
    assign out_domain_r2 = after_adp_r2;
    assign out_domain_r3 = after_adp_r3;


endmodule
