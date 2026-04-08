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
//! Step 2 — AllDifferent_Simple:
//!   Remove placed tile from all remaining active domains.
//!
//! Step 3 — SingletonDetection loop (SINGLETON_ITERS times):
//!   Detect and lock variables with only one tile remaining.
//!   Follow each with AllDifferent_Simple to propagate.
//!
//! Step 4 — DomainToColour:
//!   Recompute colour masks for every variable from domains.
//!
//! Parameters
//!   N               — board side length (board is N x N)
//!   CC              — total colour bits per edge
//!   V               — N * N
//!   ID_BITS         — $clog2(V)
//!   SINGLETON_ITERS — number of Singleton/AllDifferent iterations
// ─────────────────────────────────────────────────────────────
module Phase1_AssignProcess #(
    parameter int N               = 4,
    parameter int CC              = 6,
    parameter int V               = N * N,
    parameter int ID_BITS         = $clog2(V),
    parameter int SINGLETON_ITERS = 3
)(
    input  logic [ID_BITS-1:0] in_variableId,
    input  logic [ID_BITS-1:0] in_tileId,
    input  logic [1:0]         in_rotation,

    input  logic [V-1:0] in_unassigned_variables,
    input  logic [V-1:0] in_unassigned_tiles,

    input  logic [V-1:0][CC-1:0] in_colours_top,
    input  logic [V-1:0][CC-1:0] in_colours_right,
    input  logic [V-1:0][CC-1:0] in_colours_bottom,
    input  logic [V-1:0][CC-1:0] in_colours_left,

    input  logic [V-1:0][V-1:0] in_domain_r0,
    input  logic [V-1:0][V-1:0] in_domain_r1,
    input  logic [V-1:0][V-1:0] in_domain_r2,
    input  logic [V-1:0][V-1:0] in_domain_r3,

    input  logic [V-1:0][CC-1:0] in_elements_top,
    input  logic [V-1:0][CC-1:0] in_elements_right,
    input  logic [V-1:0][CC-1:0] in_elements_bottom,
    input  logic [V-1:0][CC-1:0] in_elements_left,

    output logic [V-1:0][CC-1:0] out_colours_top,
    output logic [V-1:0][CC-1:0] out_colours_right,
    output logic [V-1:0][CC-1:0] out_colours_bottom,
    output logic [V-1:0][CC-1:0] out_colours_left,

    output logic [V-1:0][V-1:0] out_domain_r0,
    output logic [V-1:0][V-1:0] out_domain_r1,
    output logic [V-1:0][V-1:0] out_domain_r2,
    output logic [V-1:0][V-1:0] out_domain_r3,

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

    // ── Step 2 — AllDifferent_Simple ─────────────────────────
    logic [V-1:0][V-1:0] after_alldiff_r0;
    logic [V-1:0][V-1:0] after_alldiff_r1;
    logic [V-1:0][V-1:0] after_alldiff_r2;
    logic [V-1:0][V-1:0] after_alldiff_r3;

    AllDifferent_Simple #(.N(N), .V(V)) initial_alldiff (
        .in_domain_r0           (after_assign_domain_r0),
        .in_domain_r1           (after_assign_domain_r1),
        .in_domain_r2           (after_assign_domain_r2),
        .in_domain_r3           (after_assign_domain_r3),
        .in_unassignedVariables (after_assign_uv),
        .in_unassignedTiles     (after_assign_ut),
        .out_domain_r0          (after_alldiff_r0),
        .out_domain_r1          (after_alldiff_r1),
        .out_domain_r2          (after_alldiff_r2),
        .out_domain_r3          (after_alldiff_r3)
    );

    // ── Step 3 — Singleton/AllDifferent loop ─────────────────
    logic [V-1:0][V-1:0] sing_domain_r0 [SINGLETON_ITERS:0];
    logic [V-1:0][V-1:0] sing_domain_r1 [SINGLETON_ITERS:0];
    logic [V-1:0][V-1:0] sing_domain_r2 [SINGLETON_ITERS:0];
    logic [V-1:0][V-1:0] sing_domain_r3 [SINGLETON_ITERS:0];
    logic [V-1:0]        sing_uv        [SINGLETON_ITERS:0];
    logic [V-1:0]        sing_ut        [SINGLETON_ITERS:0];

    assign sing_domain_r0[0] = after_alldiff_r0;
    assign sing_domain_r1[0] = after_alldiff_r1;
    assign sing_domain_r2[0] = after_alldiff_r2;
    assign sing_domain_r3[0] = after_alldiff_r3;
    assign sing_uv[0]        = after_assign_uv;
    assign sing_ut[0]        = after_assign_ut;

    genvar si;
    generate
        for (si = 0; si < SINGLETON_ITERS; si++) begin : gen_singleton
            logic [V-1:0][V-1:0] sd_r0, sd_r1, sd_r2, sd_r3;
            logic [V-1:0]        sd_uv, sd_ut;

            SingletonDetection #(.N(N), .V(V)) singleton_det (
                .in_unassignedVariables  (sing_uv[si]),
                .in_unassignedTiles      (sing_ut[si]),
                .in_domain_r0            (sing_domain_r0[si]),
                .in_domain_r1            (sing_domain_r1[si]),
                .in_domain_r2            (sing_domain_r2[si]),
                .in_domain_r3            (sing_domain_r3[si]),
                .out_unassignedVariables (sd_uv),
                .out_unassignedTiles     (sd_ut),
                .out_domain_r0           (sd_r0),
                .out_domain_r1           (sd_r1),
                .out_domain_r2           (sd_r2),
                .out_domain_r3           (sd_r3),
                .out_singleton           (),
                .out_deadend             ()
            );

            AllDifferent_Simple #(.N(N), .V(V)) singleton_alldiff (
                .in_domain_r0           (sd_r0),
                .in_domain_r1           (sd_r1),
                .in_domain_r2           (sd_r2),
                .in_domain_r3           (sd_r3),
                .in_unassignedVariables (sd_uv),
                .in_unassignedTiles     (sd_ut),
                .out_domain_r0          (sing_domain_r0[si+1]),
                .out_domain_r1          (sing_domain_r1[si+1]),
                .out_domain_r2          (sing_domain_r2[si+1]),
                .out_domain_r3          (sing_domain_r3[si+1])
            );

            assign sing_uv[si+1] = sd_uv;
            assign sing_ut[si+1] = sd_ut;
        end
    endgenerate

    assign out_unassigned_variables = sing_uv[SINGLETON_ITERS];
    assign out_unassigned_tiles     = sing_ut[SINGLETON_ITERS];

    // ── Step 4 — DomainToColour ───────────────────────────────
    DomainToColour #(.N(N), .CC(CC), .V(V)) domain_to_colour (
        .in_domain_r0       (sing_domain_r0[SINGLETON_ITERS]),
        .in_domain_r1       (sing_domain_r1[SINGLETON_ITERS]),
        .in_domain_r2       (sing_domain_r2[SINGLETON_ITERS]),
        .in_domain_r3       (sing_domain_r3[SINGLETON_ITERS]),
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
        .out_colours_left   (out_colours_left),
        .out_domain_r0      (out_domain_r0),
        .out_domain_r1      (out_domain_r1),
        .out_domain_r2      (out_domain_r2),
        .out_domain_r3      (out_domain_r3),
        .out_changed        (),
        .out_deadend        ()
    );

endmodule
