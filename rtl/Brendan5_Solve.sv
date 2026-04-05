// ─────────────────────────────────────────────────────────────
// Brendan5_Solve
//
//! Solver for the Brendan5 puzzle (5x5).
//!
//! Receives the initial game state from Brendan5_Load and
//! runs the constraint propagation and search algorithm.
//!
//! N=5, V=25, CC=8, VAR_BIT_SIZE=5
// ─────────────────────────────────────────────────────────────
module Brendan5_Solve (
    input  logic        clk,                            //! 50 MHz clock.

    // ── Tile elements ─────────────────────────────────────────
    input  logic [24:0][7:0]  in_elements_top,      //! top colour for each tile.
    input  logic [24:0][7:0]  in_elements_right,    //! right colour for each tile.
    input  logic [24:0][7:0]  in_elements_bottom,   //! bottom colour for each tile.
    input  logic [24:0][7:0]  in_elements_left,     //! left colour for each tile.

    // ── Initial colours ───────────────────────────────────────
    input  logic [24:0][7:0]  in_colours_top,       //! initial top colour mask for each variable.
    input  logic [24:0][7:0]  in_colours_right,     //! initial right colour mask for each variable.
    input  logic [24:0][7:0]  in_colours_bottom,    //! initial bottom colour mask for each variable.
    input  logic [24:0][7:0]  in_colours_left,      //! initial left colour mask for each variable.

    // ── Initial domains ───────────────────────────────────────
    input  logic [24:0][24:0]   in_domain_r0,         //! initial domain bitmask rotation 0 for each variable.
    input  logic [24:0][24:0]   in_domain_r1,         //! initial domain bitmask rotation 1 for each variable.
    input  logic [24:0][24:0]   in_domain_r2,         //! initial domain bitmask rotation 2 for each variable.
    input  logic [24:0][24:0]   in_domain_r3,         //! initial domain bitmask rotation 3 for each variable.

    // ── Availability masks ────────────────────────────────────
    input  logic [24:0]               in_unassigned_variables, //! 1=variable position available.
    input  logic [24:0]               in_unassigned_tiles,     //! 1=tile available.

    // ── Result ────────────────────────────────────────────────
    output logic [7:0]                      out_solution_count    //! number of solutions found (max 255).
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N            = 5;    //! int. grid size.
    localparam int V            = 25;   //! int. number of variables (N*N).
    localparam int CC           = 8;   //! int. total colour count (1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT).
    localparam int VAR_BIT_SIZE = 5;    //! int. bits needed to index a variable ($clog2(V)).

    // ── Algorithm pipeline ────────────────────────────────────
    // TODO: instantiate constraint propagation pipeline here
    // e.g. DomainToColour, CascadeColours, AllDifferent,
    //      SingletonDetection, search/backtrack state machine

endmodule
