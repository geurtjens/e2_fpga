// ─────────────────────────────────────────────────────────────
// Brendan3_Load
//
//! Loads the initial game state for the Brendan3 puzzle (3x3).
//!
//! N=3, borderColours=2, innerColours=2, CC=5, V=9
//!
//! No inputs, no parameters — all sizes are hardcoded.
//! Pure combinational — all outputs are constant wires.
// ─────────────────────────────────────────────────────────────
module Brendan3_Load (

    // ── Initial domains ───────────────────────────────────────
    output logic [8:0][8:0]  out_domain_r0,            //! initial domain bitmask rotation 0 for each variable.
    output logic [8:0][8:0]  out_domain_r1,            //! initial domain bitmask rotation 1 for each variable.
    output logic [8:0][8:0]  out_domain_r2,            //! initial domain bitmask rotation 2 for each variable.
    output logic [8:0][8:0]  out_domain_r3,            //! initial domain bitmask rotation 3 for each variable.

    // ── Initial colours ───────────────────────────────────────
    output logic [8:0][4:0]  out_colours_top,          //! initial top colour mask for each variable.
    output logic [8:0][4:0]  out_colours_right,        //! initial right colour mask for each variable.
    output logic [8:0][4:0]  out_colours_bottom,       //! initial bottom colour mask for each variable.
    output logic [8:0][4:0]  out_colours_left,         //! initial left colour mask for each variable.

    // ── Availability masks ────────────────────────────────────
    output logic [8:0]       out_unassigned_variables, //! 1=variable position available.
    output logic [8:0]       out_unassigned_tiles      //! 1=tile available.
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N                   = 3;  //! int. grid size.
    localparam int BORDER_COLOUR_COUNT = 2;  //! int. number of border colours.
    localparam int INNER_COLOUR_COUNT  = 2;  //! int. number of inner colours.
    
    // ── CreateInitialGame ─────────────────────────────────────
    //! Assigns initial colour masks and domain bitmasks to each
    //! variable based on its position in the grid (corner, edge or inner).
    CreateInitialGame #(
        .N                   (N),
        .BORDER_COLOUR_COUNT (BORDER_COLOUR_COUNT),
        .INNER_COLOUR_COUNT  (INNER_COLOUR_COUNT)
    ) initial_game (
        .out_colours_top         (out_colours_top),
        .out_colours_right       (out_colours_right),
        .out_colours_bottom      (out_colours_bottom),
        .out_colours_left        (out_colours_left),
        .out_domain_r0           (out_domain_r0),
        .out_domain_r1           (out_domain_r1),
        .out_domain_r2           (out_domain_r2),
        .out_domain_r3           (out_domain_r3),
        .out_unassignedVariables (out_unassigned_variables),
        .out_unassignedTiles     (out_unassigned_tiles)
    );

endmodule
