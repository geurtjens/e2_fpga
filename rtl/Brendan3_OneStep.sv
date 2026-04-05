// ─────────────────────────────────────────────────────────────
// Brendan3_OneStep
//
//! Wires together one complete solver step for the Brendan3
//! puzzle (3x3). Pure combinational — no clock required.
//!
//! Pipeline:
//!   1. Brendan3_Load        — load initial puzzle state
//!   2. PropagateOnce        — initial constraint propagation
//!   3. ChooseNextVariable   — pick most constrained variable
//!   4. Assignment_Complex   — lock chosen variable to first
//!                             available tile in its domain,
//!                             update colours and masks
//!   5. PropagateOnce        — propagate after assignment
//!
//! N=3, V=9, CC=5
// ─────────────────────────────────────────────────────────────
module Brendan3_OneStep (
    // ── Final domain outputs ──────────────────────────────────
    output logic [8:0][8:0]  out_domain_r0,            //! final domain bitmask rotation 0 for each variable.
    output logic [8:0][8:0]  out_domain_r1,            //! final domain bitmask rotation 1 for each variable.
    output logic [8:0][8:0]  out_domain_r2,            //! final domain bitmask rotation 2 for each variable.
    output logic [8:0][8:0]  out_domain_r3,            //! final domain bitmask rotation 3 for each variable.

    // ── Final colour outputs ──────────────────────────────────
    output logic [8:0][4:0]  out_colours_top,          //! final top colour mask for each variable.
    output logic [8:0][4:0]  out_colours_right,        //! final right colour mask for each variable.
    output logic [8:0][4:0]  out_colours_bottom,       //! final bottom colour mask for each variable.
    output logic [8:0][4:0]  out_colours_left,         //! final left colour mask for each variable.

    // ── Final availability masks ──────────────────────────────
    output logic [8:0]       out_unassigned_variables, //! final unassigned variables bitmask.
    output logic [8:0]       out_unassigned_tiles,     //! final unassigned tiles bitmask.

    // ── Chosen variable ───────────────────────────────────────
    output logic [3:0]       out_next_var,             //! chosen variable ID from ChooseNextVariable.
    output logic             out_valid,                //! 1 if a valid variable was found.

    // ── Status ────────────────────────────────────────────────
    output logic             out_changed,              //! 1 if second PropagateOnce changed anything.
    output logic             out_deadend               //! 1 if any stage detected an impossible state.
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N  = 3;  //! int. grid size.
    localparam int V  = 9;  //! int. number of variables (N*N).
    localparam int CC = 5;  //! int. total colour count.

    // ── Wires from Brendan3_Load ──────────────────────────────
    logic [8:0][4:0]  w_elements_top;
    logic [8:0][4:0]  w_elements_right;
    logic [8:0][4:0]  w_elements_bottom;
    logic [8:0][4:0]  w_elements_left;

    logic [8:0][4:0]  w_load_colours_top;
    logic [8:0][4:0]  w_load_colours_right;
    logic [8:0][4:0]  w_load_colours_bottom;
    logic [8:0][4:0]  w_load_colours_left;

    logic [8:0][8:0]  w_load_domain_r0;
    logic [8:0][8:0]  w_load_domain_r1;
    logic [8:0][8:0]  w_load_domain_r2;
    logic [8:0][8:0]  w_load_domain_r3;

    logic [8:0]       w_load_unassigned_variables;
    logic [8:0]       w_load_unassigned_tiles;

    // ── Wires from first PropagateOnce ────────────────────────
    logic [8:0][8:0]  w_prop1_domain_r0;
    logic [8:0][8:0]  w_prop1_domain_r1;
    logic [8:0][8:0]  w_prop1_domain_r2;
    logic [8:0][8:0]  w_prop1_domain_r3;

    logic [8:0][4:0]  w_prop1_colours_top;
    logic [8:0][4:0]  w_prop1_colours_right;
    logic [8:0][4:0]  w_prop1_colours_bottom;
    logic [8:0][4:0]  w_prop1_colours_left;

    logic [8:0]       w_prop1_unassigned_variables;
    logic [8:0]       w_prop1_unassigned_tiles;

    // ── Wires from ChooseNextVariable ─────────────────────────
    logic [3:0]       w_next_var;
    logic             w_valid;

    // ── Tile and rotation selection ───────────────────────────
    //! Pick the first available tile from the chosen variable's
    //! combined domain and find which rotation contains it.
    logic [8:0]       w_combined_domain;
    logic [3:0]       w_tile_id;
    logic [1:0]       w_rotation;

    always_comb begin : select_tile_and_rotation
        w_combined_domain = w_prop1_domain_r0[w_next_var] |
                            w_prop1_domain_r1[w_next_var] |
                            w_prop1_domain_r2[w_next_var] |
                            w_prop1_domain_r3[w_next_var];

        // priority encode — pick lowest set bit
        w_tile_id = '0;
        for (int t = V-1; t >= 0; t--)
            if (w_combined_domain[t]) w_tile_id = 4'(t);

        // find which rotation contains this tile
        if      (w_prop1_domain_r0[w_next_var][w_tile_id]) w_rotation = 2'd0;
        else if (w_prop1_domain_r1[w_next_var][w_tile_id]) w_rotation = 2'd1;
        else if (w_prop1_domain_r2[w_next_var][w_tile_id]) w_rotation = 2'd2;
        else                                                w_rotation = 2'd3;
    end

    // ── Wires from Assignment_Complex ────────────────────────
    logic [8:0][8:0]  w_assign_domain_r0;
    logic [8:0][8:0]  w_assign_domain_r1;
    logic [8:0][8:0]  w_assign_domain_r2;
    logic [8:0][8:0]  w_assign_domain_r3;

    logic [8:0][4:0]  w_assign_colours_top;
    logic [8:0][4:0]  w_assign_colours_right;
    logic [8:0][4:0]  w_assign_colours_bottom;
    logic [8:0][4:0]  w_assign_colours_left;

    logic [8:0]       w_assign_unassigned_variables;
    logic [8:0]       w_assign_unassigned_tiles;

    // ── Brendan3_Load ─────────────────────────────────────────
    //! Loads the initial puzzle state — tile elements, colour
    //! masks and domain bitmasks. Pure combinational.
    Brendan3_Load loader (
        .out_elements_top        (w_elements_top),
        .out_elements_right      (w_elements_right),
        .out_elements_bottom     (w_elements_bottom),
        .out_elements_left       (w_elements_left),
        .out_colours_top         (w_load_colours_top),
        .out_colours_right       (w_load_colours_right),
        .out_colours_bottom      (w_load_colours_bottom),
        .out_colours_left        (w_load_colours_left),
        .out_domain_r0           (w_load_domain_r0),
        .out_domain_r1           (w_load_domain_r1),
        .out_domain_r2           (w_load_domain_r2),
        .out_domain_r3           (w_load_domain_r3),
        .out_unassigned_variables(w_load_unassigned_variables),
        .out_unassigned_tiles    (w_load_unassigned_tiles)
    );

    // ── PropagateOnce (first pass) ────────────────────────────
    //! Initial constraint propagation on the loaded puzzle state.
    PropagateOnce #(.N(N), .V(V), .CC(CC)) prop1 (
        .in_elements_top         (w_elements_top),
        .in_elements_right       (w_elements_right),
        .in_elements_bottom      (w_elements_bottom),
        .in_elements_left        (w_elements_left),
        .in_domain_r0            (w_load_domain_r0),
        .in_domain_r1            (w_load_domain_r1),
        .in_domain_r2            (w_load_domain_r2),
        .in_domain_r3            (w_load_domain_r3),
        .in_colours_top          (w_load_colours_top),
        .in_colours_right        (w_load_colours_right),
        .in_colours_bottom       (w_load_colours_bottom),
        .in_colours_left         (w_load_colours_left),
        .in_unassigned_variables (w_load_unassigned_variables),
        .in_unassigned_tiles     (w_load_unassigned_tiles),
        .out_domain_r0           (w_prop1_domain_r0),
        .out_domain_r1           (w_prop1_domain_r1),
        .out_domain_r2           (w_prop1_domain_r2),
        .out_domain_r3           (w_prop1_domain_r3),
        .out_colours_top         (w_prop1_colours_top),
        .out_colours_right       (w_prop1_colours_right),
        .out_colours_bottom      (w_prop1_colours_bottom),
        .out_colours_left        (w_prop1_colours_left),
        .out_unassigned_variables(w_prop1_unassigned_variables),
        .out_unassigned_tiles    (w_prop1_unassigned_tiles),
        .out_changed             (),
        .out_deadend             ()
    );

    // ── ChooseNextVariable ────────────────────────────────────
    //! Selects the most constrained unassigned variable using
    //! the MRV heuristic, expanding from placed neighbours.
    ChooseNextVariable #(.N(N)) choose (
        .in_unassignedVariables  (w_prop1_unassigned_variables),
        .in_domain_r0            (w_prop1_domain_r0),
        .in_domain_r1            (w_prop1_domain_r1),
        .in_domain_r2            (w_prop1_domain_r2),
        .in_domain_r3            (w_prop1_domain_r3),
        .out_next_var            (w_next_var),
        .out_valid               (w_valid)
    );

    // ── Assignment_Complex ────────────────────────────────────
    //! Locks the chosen variable to the first available tile,
    //! sets its colours from the element data, propagates
    //! colour constraints to neighbours, and updates masks.
    Assignment_Complex #(.N(N), .CC(CC)) assign_inst (
        .in_variableId           (w_next_var),
        .in_tileId               (w_tile_id),
        .in_rotation             (w_rotation),
        .in_unassigned_variables (w_prop1_unassigned_variables),
        .in_unassigned_tiles     (w_prop1_unassigned_tiles),
        .in_colour_top           (w_prop1_colours_top),
        .in_colour_right         (w_prop1_colours_right),
        .in_colour_bottom        (w_prop1_colours_bottom),
        .in_colour_left          (w_prop1_colours_left),
        .in_domain_r0            (w_prop1_domain_r0),
        .in_domain_r1            (w_prop1_domain_r1),
        .in_domain_r2            (w_prop1_domain_r2),
        .in_domain_r3            (w_prop1_domain_r3),
        .in_elements_top         (w_elements_top),
        .in_elements_right       (w_elements_right),
        .in_elements_bottom      (w_elements_bottom),
        .in_elements_left        (w_elements_left),
        .out_colour_top          (w_assign_colours_top),
        .out_colour_right        (w_assign_colours_right),
        .out_colour_bottom       (w_assign_colours_bottom),
        .out_colour_left         (w_assign_colours_left),
        .out_domain_r0           (w_assign_domain_r0),
        .out_domain_r1           (w_assign_domain_r1),
        .out_domain_r2           (w_assign_domain_r2),
        .out_domain_r3           (w_assign_domain_r3),
        .out_unassigned_variables(w_assign_unassigned_variables),
        .out_unassigned_tiles    (w_assign_unassigned_tiles),
        .out_colours_changed     ()
    );

    // ── PropagateOnce (second pass) ───────────────────────────
    //! Propagates constraints after the assignment, shrinking
    //! domains and updating colours and availability masks.
    PropagateOnce #(.N(N), .V(V), .CC(CC)) prop2 (
        .in_elements_top         (w_elements_top),
        .in_elements_right       (w_elements_right),
        .in_elements_bottom      (w_elements_bottom),
        .in_elements_left        (w_elements_left),
        .in_domain_r0            (w_assign_domain_r0),
        .in_domain_r1            (w_assign_domain_r1),
        .in_domain_r2            (w_assign_domain_r2),
        .in_domain_r3            (w_assign_domain_r3),
        .in_colours_top          (w_assign_colours_top),
        .in_colours_right        (w_assign_colours_right),
        .in_colours_bottom       (w_assign_colours_bottom),
        .in_colours_left         (w_assign_colours_left),
        .in_unassigned_variables (w_assign_unassigned_variables),
        .in_unassigned_tiles     (w_assign_unassigned_tiles),
        .out_domain_r0           (out_domain_r0),
        .out_domain_r1           (out_domain_r1),
        .out_domain_r2           (out_domain_r2),
        .out_domain_r3           (out_domain_r3),
        .out_colours_top         (out_colours_top),
        .out_colours_right       (out_colours_right),
        .out_colours_bottom      (out_colours_bottom),
        .out_colours_left        (out_colours_left),
        .out_unassigned_variables(out_unassigned_variables),
        .out_unassigned_tiles    (out_unassigned_tiles),
        .out_changed             (out_changed),
        .out_deadend             (out_deadend)
    );

    // ── Pass through chosen variable info ─────────────────────
    assign out_next_var = w_next_var;
    assign out_valid    = w_valid;

endmodule
