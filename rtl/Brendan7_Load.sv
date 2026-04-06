// ─────────────────────────────────────────────────────────────
// Brendan7_Load
//
//! Loads the initial game state for the Brendan7 puzzle (7x7).
//!
//! N=7, borderColours=3, innerColours=6, CC=10, V=49
//!
//! No inputs, no parameters — all sizes are hardcoded.
//! Pure combinational — all outputs are constant wires.
// ─────────────────────────────────────────────────────────────
module Brendan7_Load (
    
    // ── Initial domains ───────────────────────────────────────
    output logic [48:0][48:0] out_domain_r0,            //! initial domain bitmask rotation 0 for each variable.
    output logic [48:0][48:0] out_domain_r1,            //! initial domain bitmask rotation 1 for each variable.
    output logic [48:0][48:0] out_domain_r2,            //! initial domain bitmask rotation 2 for each variable.
    output logic [48:0][48:0] out_domain_r3,            //! initial domain bitmask rotation 3 for each variable.

    // ── Initial colours ───────────────────────────────────────
    output logic [48:0][9:0]  out_colours_top,          //! initial top colour mask for each variable.
    output logic [48:0][9:0]  out_colours_right,        //! initial right colour mask for each variable.
    output logic [48:0][9:0]  out_colours_bottom,       //! initial bottom colour mask for each variable.
    output logic [48:0][9:0]  out_colours_left,         //! initial left colour mask for each variable.

    // ── Availability masks ────────────────────────────────────
    output logic [48:0]       out_unassigned_variables, //! 1=variable position available.
    output logic [48:0]       out_unassigned_tiles      //! 1=tile available.
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N                   = 7;  //! int. grid size.
    localparam int BORDER_COLOUR_COUNT = 3;  //! int. number of border colours.
    localparam int INNER_COLOUR_COUNT  = 6;  //! int. number of inner colours.

    // ── CreateInitialGame ─────────────────────────────────────
    //! Assigns initial colour masks and domain bitmasks to each
    //! variable based on its position in the grid (corner, edge
    //! or inner), and fixes tile 0 at the top-left corner.
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
