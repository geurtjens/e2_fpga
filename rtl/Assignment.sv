// ─────────────────────────────────────────────────────────────
// Assignment
//
//! Assigns a tile and rotation to a variable.
//! Part 1 — Lock domain to one tile at one rotation.
//! Part 2 — Set assigned variable's colours from element lookup.
//! Part 3 — AND piece colours into direct neighbours.
//! Part 4 — Update availability masks.
//!
//! Parameters
//!   N       — board side length (board is N x N)
//!   CC      — total colour bits per edge
//!   V       — N * N
//!   ID_BITS — $clog2(V)
// ─────────────────────────────────────────────────────────────
module Assignment #(
    parameter int N       = 4,
    parameter int CC      = 6,
    parameter int V       = N * N,
    parameter int ID_BITS = $clog2(V)
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

    logic [31:0] vid;
    logic [31:0] tid;
    assign vid = 32'(in_variableId);
    assign tid = 32'(in_tileId);

    // ── Part 1 — lock domain ──────────────────────────────────
    logic [V-1:0] tile_mask;
    always_comb begin : create_tile_mask
        tile_mask      = '0;
        tile_mask[tid] = 1'b1;
    end

    always_comb begin : lock_domain
        out_domain_r0 = in_domain_r0;
        out_domain_r1 = in_domain_r1;
        out_domain_r2 = in_domain_r2;
        out_domain_r3 = in_domain_r3;

        out_domain_r0[vid] = (in_rotation == 2'd0) ? tile_mask : '0;
        out_domain_r1[vid] = (in_rotation == 2'd1) ? tile_mask : '0;
        out_domain_r2[vid] = (in_rotation == 2'd2) ? tile_mask : '0;
        out_domain_r3[vid] = (in_rotation == 2'd3) ? tile_mask : '0;
    end

    // ── Part 2 — colour lookup ────────────────────────────────
    logic [CC-1:0] piece_top;
    logic [CC-1:0] piece_right;
    logic [CC-1:0] piece_bottom;
    logic [CC-1:0] piece_left;

    ColourLookup #(.V(V), .CC(CC)) colour_lookup (
        .in_tileId          (in_tileId),
        .in_rotation        (in_rotation),
        .in_elements_top    (in_elements_top),
        .in_elements_right  (in_elements_right),
        .in_elements_bottom (in_elements_bottom),
        .in_elements_left   (in_elements_left),
        .out_top            (piece_top),
        .out_right          (piece_right),
        .out_bottom         (piece_bottom),
        .out_left           (piece_left)
    );

    // ── Part 2 — set assigned variable's colours ──────────────
    logic [V-1:0][CC-1:0] colours_after_assignment_top;
    logic [V-1:0][CC-1:0] colours_after_assignment_right;
    logic [V-1:0][CC-1:0] colours_after_assignment_bottom;
    logic [V-1:0][CC-1:0] colours_after_assignment_left;

    ColourAssignment #(.N(N), .V(V), .CC(CC)) colour_assignment (
        .in_variableId      (in_variableId),
        .in_piece_top       (piece_top),
        .in_piece_right     (piece_right),
        .in_piece_bottom    (piece_bottom),
        .in_piece_left      (piece_left),
        .in_colours_top     (in_colours_top),
        .in_colours_right   (in_colours_right),
        .in_colours_bottom  (in_colours_bottom),
        .in_colours_left    (in_colours_left),
        .out_colours_top    (colours_after_assignment_top),
        .out_colours_right  (colours_after_assignment_right),
        .out_colours_bottom (colours_after_assignment_bottom),
        .out_colours_left   (colours_after_assignment_left)
    );

    // ── Part 3 — AND piece colours into neighbours ────────────
    ColourAssignmentNeighbours #(.N(N), .V(V), .CC(CC)) colour_assignment_neighbours (
        .in_variableId      (in_variableId),
        .in_piece_top       (piece_top),
        .in_piece_right     (piece_right),
        .in_piece_bottom    (piece_bottom),
        .in_piece_left      (piece_left),
        .in_colours_top     (colours_after_assignment_top),
        .in_colours_right   (colours_after_assignment_right),
        .in_colours_bottom  (colours_after_assignment_bottom),
        .in_colours_left    (colours_after_assignment_left),
        .out_colours_top    (out_colours_top),
        .out_colours_right  (out_colours_right),
        .out_colours_bottom (out_colours_bottom),
        .out_colours_left   (out_colours_left)
    );

    // ── Part 4 — update availability masks ───────────────────
    assign out_unassigned_variables = in_unassigned_variables & ~(V'(1) << vid);
    assign out_unassigned_tiles     = in_unassigned_tiles     & ~(V'(1) << tid);

endmodule