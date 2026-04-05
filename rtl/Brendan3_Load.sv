// ─────────────────────────────────────────────────────────────
// Brendan3_Load
//
//! Loads the initial game state for the Brendan3 puzzle (3x3).
//!
//! Instantiates Brendan3_Elements and CreateInitialGame.
//! No inputs, no parameters — all sizes are hardcoded.
//! Pure combinational — all outputs are constant wires.
//!
//! Puzzle:  aaxx abxx baxx / bbxx cbxa daxa / caxb dbxb ccdd
//! N=3, borderColours=2, innerColours=2, CC=5, V=9
// ─────────────────────────────────────────────────────────────
module Brendan3_Load (
    // ── Tile elements ─────────────────────────────────────────
    output logic [8:0][4:0]  out_elements_top,         //! top colour for each tile.
    output logic [8:0][4:0]  out_elements_right,       //! right colour for each tile.
    output logic [8:0][4:0]  out_elements_bottom,      //! bottom colour for each tile.
    output logic [8:0][4:0]  out_elements_left,        //! left colour for each tile.

    // ── Initial colours ───────────────────────────────────────
    output logic [8:0][4:0]  out_colours_top,          //! initial top colour mask for each variable.
    output logic [8:0][4:0]  out_colours_right,        //! initial right colour mask for each variable.
    output logic [8:0][4:0]  out_colours_bottom,       //! initial bottom colour mask for each variable.
    output logic [8:0][4:0]  out_colours_left,         //! initial left colour mask for each variable.

    // ── Initial domains ───────────────────────────────────────
    output logic [8:0][8:0]  out_domain_r0,            //! initial domain bitmask rotation 0 for each variable.
    output logic [8:0][8:0]  out_domain_r1,            //! initial domain bitmask rotation 1 for each variable.
    output logic [8:0][8:0]  out_domain_r2,            //! initial domain bitmask rotation 2 for each variable.
    output logic [8:0][8:0]  out_domain_r3,            //! initial domain bitmask rotation 3 for each variable.

    // ── Availability masks ────────────────────────────────────
    output logic [8:0]       out_unassigned_variables, //! 1=variable position available.
    output logic [8:0]       out_unassigned_tiles      //! 1=tile available.
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N                   = 3;  //! int. grid size.
    localparam int V                   = 9;  //! int. number of variables (N*N).
    localparam int BORDER_COLOUR_COUNT = 2;  //! int. number of border colours.
    localparam int INNER_COLOUR_COUNT  = 2;  //! int. number of inner colours.
    localparam int CC                  = 5;  //! int. total colour count (1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT).

    // ── Brendan3_Elements ─────────────────────────────────────
    //! Provides the colour masks for all 9 tiles in their base
    //! orientation. Rotation is handled downstream by DomainToColour.
    Brendan3_Elements #(
        .CC (CC),
        .V  (V)
    ) elements (
        .out_elements_top    (out_elements_top),
        .out_elements_right  (out_elements_right),
        .out_elements_bottom (out_elements_bottom),
        .out_elements_left   (out_elements_left)
    );

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
