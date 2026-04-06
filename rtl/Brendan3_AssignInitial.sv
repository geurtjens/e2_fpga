// ─────────────────────────────────────────────────────────────
// Brendan3_AssignInitial
//
// Loads the Brendan3 puzzle and makes the first hardcoded
// assignment: variable 0 (top-left corner), tile 0, rotation 1.
//
// Pure combinational — no clock, no inputs.
//
// Puzzle:  aaxx abxx baxx / bbxx cbxa daxa / caxb dbxb ccdd
// N=3, borderColours=2, innerColours=2, CC=5, V=9
// ─────────────────────────────────────────────────────────────
module Brendan3_AssignInitial (
    // ── Domains after assignment ───────────────────────────
    output logic [8:0][8:0]  out_domain_r0,            //! domain bitmask rotation 0 for each variable after assignment.
    output logic [8:0][8:0]  out_domain_r1,            //! domain bitmask rotation 1 for each variable after assignment.
    output logic [8:0][8:0]  out_domain_r2,            //! domain bitmask rotation 2 for each variable after assignment.
    output logic [8:0][8:0]  out_domain_r3,            //! domain bitmask rotation 3 for each variable after assignment.

    // ── Colours after assignment ───────────────────────────
    output logic [8:0][4:0]  out_colours_top,          //! top colour mask for each variable after assignment.
    output logic [8:0][4:0]  out_colours_right,        //! right colour mask for each variable after assignment.
    output logic [8:0][4:0]  out_colours_bottom,       //! bottom colour mask for each variable after assignment.
    output logic [8:0][4:0]  out_colours_left,         //! left colour mask for each variable after assignment.

    // ── Elements (pass-through for downstream use) ─────────
    output logic [8:0][4:0]  out_elements_top,         //! top colour for each tile in base orientation.
    output logic [8:0][4:0]  out_elements_right,       //! right colour for each tile in base orientation.
    output logic [8:0][4:0]  out_elements_bottom,      //! bottom colour for each tile in base orientation.
    output logic [8:0][4:0]  out_elements_left,        //! left colour for each tile in base orientation.

    // ── Availability masks after assignment ────────────────
    output logic [8:0]       out_unassigned_variables, //! 1=variable unassigned, 0=placed. Bit 0 cleared after assignment.
    output logic [8:0]       out_unassigned_tiles      //! 1=tile available, 0=placed. Bit 0 cleared after assignment.
);

    // ── Puzzle constants ───────────────────────────────────
    localparam int N                   = 3;
    localparam int V                   = 9;  // N * N
    localparam int CC                  = 5;  // 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT

    // ── Wires from Brendan3_Load ───────────────────────────
    logic [8:0][4:0]  w_elements_top;
    logic [8:0][4:0]  w_elements_right;
    logic [8:0][4:0]  w_elements_bottom;
    logic [8:0][4:0]  w_elements_left;

    logic [8:0][4:0]  w_colours_top;
    logic [8:0][4:0]  w_colours_right;
    logic [8:0][4:0]  w_colours_bottom;
    logic [8:0][4:0]  w_colours_left;

    logic [8:0][8:0]  w_domain_r0;
    logic [8:0][8:0]  w_domain_r1;
    logic [8:0][8:0]  w_domain_r2;
    logic [8:0][8:0]  w_domain_r3;

    logic [8:0]       w_unassigned_variables;
    logic [8:0]       w_unassigned_tiles;

    // ── Brendan3_Load ──────────────────────────────────────
    //! Loads tile elements, position colour masks and initial
    //! domains. All outputs are constant wires — pure ROM.
    Brendan3_Load load (
        .out_elements_top        (w_elements_top),
        .out_elements_right      (w_elements_right),
        .out_elements_bottom     (w_elements_bottom),
        .out_elements_left       (w_elements_left),
        .out_colours_top         (w_colours_top),
        .out_colours_right       (w_colours_right),
        .out_colours_bottom      (w_colours_bottom),
        .out_colours_left        (w_colours_left),
        .out_domain_r0           (w_domain_r0),
        .out_domain_r1           (w_domain_r1),
        .out_domain_r2           (w_domain_r2),
        .out_domain_r3           (w_domain_r3),
        .out_unassigned_variables(w_unassigned_variables),
        .out_unassigned_tiles    (w_unassigned_tiles)
    );

    // ── Assignment_Complex — var 0, tile 0, rotation 1 ─────
    //! Fixes the top-left corner: tile 0 (aaxx) at rotation 1
    //! (top=left, right=top, bottom=right, left=bottom).
    //! Locks the domain, sets colours, propagates to neighbours
    //! and clears bit 0 from both unassigned masks.
    Assignment #(
        .N  (N),
        .V  (V),
        .CC (CC)
    ) assign_inst (
        .in_variableId           (4'(0)),  //! top-left corner — variable 0
        .in_tileId               (4'(0)),  //! tile 0 — corner piece aaxx
        .in_rotation             (2'd1),   //! rotation 1: top=left, right=top, bottom=right, left=bottom
        .in_unassigned_variables (w_unassigned_variables),
        .in_unassigned_tiles     (w_unassigned_tiles),
        .in_colour_top           (w_colours_top),
        .in_colour_right         (w_colours_right),
        .in_colour_bottom        (w_colours_bottom),
        .in_colour_left          (w_colours_left),
        .in_domain_r0            (w_domain_r0),
        .in_domain_r1            (w_domain_r1),
        .in_domain_r2            (w_domain_r2),
        .in_domain_r3            (w_domain_r3),
        .in_elements_top         (w_elements_top),
        .in_elements_right       (w_elements_right),
        .in_elements_bottom      (w_elements_bottom),
        .in_elements_left        (w_elements_left),
        .out_domain_r0           (out_domain_r0),
        .out_domain_r1           (out_domain_r1),
        .out_domain_r2           (out_domain_r2),
        .out_domain_r3           (out_domain_r3),
        .out_colour_top          (out_colours_top),
        .out_colour_right        (out_colours_right),
        .out_colour_bottom       (out_colours_bottom),
        .out_colour_left         (out_colours_left),
        .out_unassigned_variables(out_unassigned_variables),
        .out_unassigned_tiles    (out_unassigned_tiles)
    );

    // ── Pass elements through ──────────────────────────────
    //! Elements are tile ROM data — unchanged by assignment.
    assign out_elements_top    = w_elements_top;
    assign out_elements_right  = w_elements_right;
    assign out_elements_bottom = w_elements_bottom;
    assign out_elements_left   = w_elements_left;

endmodule
