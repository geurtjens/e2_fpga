// ─────────────────────────────────────────────────────────────
// Phase2_ApplyColourChanges
//
//! Runs the full colour/domain propagation loop matching the
//! C++ Phase2_ApplyColourChanges:
//!
//! Step 1 — ColourToDomain/DomainToColour loop (PROPAGATION_ITERS):
//!   Filter domains against colour constraints then recompute
//!   colours from tightened domains.
//!
//! Step 2 — TileFrequency:
//!   Force any tile that can only go to one variable.
//!
//! Step 3 — DeadendOrSolutionCheck:
//!   Single combined deadend and solution check on final state.
//!
//! Parameters
//!   N                 — board side length (board is N x N)
//!   CC                — total colour bits per edge
//!   V                 — N * N
//!   PROPAGATION_ITERS — number of ColourToDomain/DomainToColour iterations
// ─────────────────────────────────────────────────────────────
module Phase2_ApplyColourChanges #(
    parameter int N                 = 4,
    parameter int CC                = 6,
    parameter int V                 = N * N,
    parameter int PROPAGATION_ITERS = 2
)(
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

    output logic out_deadend,
    output logic out_solution
);

    // ── Step 1 — ColourToDomain/DomainToColour loop ───────────
    logic [V-1:0][CC-1:0] prop_colours_top    [PROPAGATION_ITERS:0];
    logic [V-1:0][CC-1:0] prop_colours_right  [PROPAGATION_ITERS:0];
    logic [V-1:0][CC-1:0] prop_colours_bottom [PROPAGATION_ITERS:0];
    logic [V-1:0][CC-1:0] prop_colours_left   [PROPAGATION_ITERS:0];
    logic [V-1:0][V-1:0]  prop_domain_r0      [PROPAGATION_ITERS:0];
    logic [V-1:0][V-1:0]  prop_domain_r1      [PROPAGATION_ITERS:0];
    logic [V-1:0][V-1:0]  prop_domain_r2      [PROPAGATION_ITERS:0];
    logic [V-1:0][V-1:0]  prop_domain_r3      [PROPAGATION_ITERS:0];

    assign prop_colours_top[0]    = in_colours_top;
    assign prop_colours_right[0]  = in_colours_right;
    assign prop_colours_bottom[0] = in_colours_bottom;
    assign prop_colours_left[0]   = in_colours_left;
    assign prop_domain_r0[0]      = in_domain_r0;
    assign prop_domain_r1[0]      = in_domain_r1;
    assign prop_domain_r2[0]      = in_domain_r2;
    assign prop_domain_r3[0]      = in_domain_r3;

    genvar pi;
    generate
        for (pi = 0; pi < PROPAGATION_ITERS; pi++) begin : gen_propagation

            logic [V-1:0][V-1:0] c2d_r0, c2d_r1, c2d_r2, c2d_r3;

            ColourToDomain #(.N(N), .CC(CC), .V(V)) colour_to_domain (
                .in_domain_r0       (prop_domain_r0[pi]),
                .in_domain_r1       (prop_domain_r1[pi]),
                .in_domain_r2       (prop_domain_r2[pi]),
                .in_domain_r3       (prop_domain_r3[pi]),
                .in_colours_top     (prop_colours_top[pi]),
                .in_colours_right   (prop_colours_right[pi]),
                .in_colours_bottom  (prop_colours_bottom[pi]),
                .in_colours_left    (prop_colours_left[pi]),
                .in_elements_top    (in_elements_top),
                .in_elements_right  (in_elements_right),
                .in_elements_bottom (in_elements_bottom),
                .in_elements_left   (in_elements_left),
                .out_domain_r0      (c2d_r0),
                .out_domain_r1      (c2d_r1),
                .out_domain_r2      (c2d_r2),
                .out_domain_r3      (c2d_r3)
            );

            DomainToColour #(.N(N), .CC(CC), .V(V)) domain_to_colour (
                .in_domain_r0       (c2d_r0),
                .in_domain_r1       (c2d_r1),
                .in_domain_r2       (c2d_r2),
                .in_domain_r3       (c2d_r3),
                .in_colours_top     (prop_colours_top[pi]),
                .in_colours_right   (prop_colours_right[pi]),
                .in_colours_bottom  (prop_colours_bottom[pi]),
                .in_colours_left    (prop_colours_left[pi]),
                .in_elements_top    (in_elements_top),
                .in_elements_right  (in_elements_right),
                .in_elements_bottom (in_elements_bottom),
                .in_elements_left   (in_elements_left),
                .out_colours_top    (prop_colours_top[pi+1]),
                .out_colours_right  (prop_colours_right[pi+1]),
                .out_colours_bottom (prop_colours_bottom[pi+1]),
                .out_colours_left   (prop_colours_left[pi+1]),
                .out_changed        (),
                .out_deadend        ()
            );

            assign prop_domain_r0[pi+1] = c2d_r0;
            assign prop_domain_r1[pi+1] = c2d_r1;
            assign prop_domain_r2[pi+1] = c2d_r2;
            assign prop_domain_r3[pi+1] = c2d_r3;
        end
    endgenerate

    // ── Step 2 — TileFrequency ────────────────────────────────
    logic [V-1:0][V-1:0] after_tf_r0;
    logic [V-1:0][V-1:0] after_tf_r1;
    logic [V-1:0][V-1:0] after_tf_r2;
    logic [V-1:0][V-1:0] after_tf_r3;
    logic                 tf_deadend;

    TileFrequency #(.N(N), .V(V)) tile_frequency (
        .in_domain_r0            (prop_domain_r0[PROPAGATION_ITERS]),
        .in_domain_r1            (prop_domain_r1[PROPAGATION_ITERS]),
        .in_domain_r2            (prop_domain_r2[PROPAGATION_ITERS]),
        .in_domain_r3            (prop_domain_r3[PROPAGATION_ITERS]),
        .in_unassigned_variables (in_unassigned_variables),
        .in_unassigned_tiles     (in_unassigned_tiles),
        .out_domain_r0           (after_tf_r0),
        .out_domain_r1           (after_tf_r1),
        .out_domain_r2           (after_tf_r2),
        .out_domain_r3           (after_tf_r3),
        .out_deadend             (tf_deadend)
    );

    assign out_domain_r0 = after_tf_r0;
    assign out_domain_r1 = after_tf_r1;
    assign out_domain_r2 = after_tf_r2;
    assign out_domain_r3 = after_tf_r3;
    assign out_colours_top    = prop_colours_top[PROPAGATION_ITERS];
    assign out_colours_right  = prop_colours_right[PROPAGATION_ITERS];
    assign out_colours_bottom = prop_colours_bottom[PROPAGATION_ITERS];
    assign out_colours_left   = prop_colours_left[PROPAGATION_ITERS];

    // ── Step 3 — DeadendOrSolutionCheck ──────────────────────
    logic dos_deadend;

    DeadendOrSolutionCheck #(.N(N), .V(V), .CC(CC)) deadend_or_solution_check (
        .in_unassigned_variables (in_unassigned_variables),
        .in_unassigned_tiles     (in_unassigned_tiles),
        .in_domain_r0            (after_tf_r0),
        .in_domain_r1            (after_tf_r1),
        .in_domain_r2            (after_tf_r2),
        .in_domain_r3            (after_tf_r3),
        .in_colours_top          (out_colours_top),
        .in_colours_right        (out_colours_right),
        .in_colours_bottom       (out_colours_bottom),
        .in_colours_left         (out_colours_left),
        .out_deadend             (dos_deadend),
        .out_solution            (out_solution)
    );

    assign out_deadend = tf_deadend | dos_deadend;

endmodule
