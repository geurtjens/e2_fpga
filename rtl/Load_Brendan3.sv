// ─────────────────────────────────────────────────────────────
// Load_Brendan3
//
//! Loads the initial game state for the Brendan3 puzzle (3x3).
//!
//! Instantiates Elements_Brendan3 and CreateInitialGame.
//! No inputs, no parameters — all sizes are hardcoded.
//! Pure combinational — all outputs are constant wires.
//!
//! Puzzle:  aaxx abxx baxx / bbxx cbxa daxa / caxb dbxb ccdd
//! N=3, borderColours=2, innerColours=2, CC=5, V=9
// ─────────────────────────────────────────────────────────────
module Load_Brendan3 (
    // ── Puzzle identity ───────────────────────────────────────
    output logic [7:0]       out_N,                    //! grid size (3).
    output logic [7:0]       out_V,                    //! number of variables (9).
    output logic [7:0]       out_CC,                   //! total colour count (5).
    output logic [7:0]       out_BORDER_COLOURS,       //! number of border colours (2).
    output logic [7:0]       out_INNER_COLOURS,        //! number of inner colours (2).
    output logic [7:0]       out_VAR_BIT_SIZE,         //! bits needed to index a variable (4).

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
    localparam int N                   = 3;
    localparam int V                   = 9;  // N * N
    localparam int BORDER_COLOUR_COUNT = 2;
    localparam int INNER_COLOUR_COUNT  = 2;
    localparam int CC                  = 5;  // 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT
    localparam int VAR_BIT_SIZE        = 4;  // $clog2(V)

    // ── Puzzle identity outputs ───────────────────────────────
    assign out_N              = 8'(N);
    assign out_V              = 8'(V);
    assign out_CC             = 8'(CC);
    assign out_BORDER_COLOURS = 8'(BORDER_COLOUR_COUNT);
    assign out_INNER_COLOURS  = 8'(INNER_COLOUR_COUNT);
    assign out_VAR_BIT_SIZE   = 8'(VAR_BIT_SIZE);

    // ── Elements_Brendan3 ─────────────────────────────────────
    Elements_Brendan3 #(
        .CC (CC),
        .V  (V)
    ) elements (
        .out_elements_top    (out_elements_top),
        .out_elements_right  (out_elements_right),
        .out_elements_bottom (out_elements_bottom),
        .out_elements_left   (out_elements_left)
    );

    // ── CreateInitialGame ─────────────────────────────────────
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
