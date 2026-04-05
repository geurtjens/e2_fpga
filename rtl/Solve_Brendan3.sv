// ─────────────────────────────────────────────────────────────
// Solve_Brendan3
//
//! Solver for the Brendan3 puzzle (3x3).
//!
//! Receives the initial game state from Load_Brendan3 and
//! runs the constraint propagation and search algorithm.
//!
//! N=3, V=9, CC=5, VAR_BIT_SIZE=4
// ─────────────────────────────────────────────────────────────
module Solve_Brendan3 (
    input  logic        clk,

    // ── Tile elements ─────────────────────────────────────────
    input  logic [8:0][4:0]  in_elements_top,          //! top colour for each tile.
    input  logic [8:0][4:0]  in_elements_right,        //! right colour for each tile.
    input  logic [8:0][4:0]  in_elements_bottom,       //! bottom colour for each tile.
    input  logic [8:0][4:0]  in_elements_left,         //! left colour for each tile.

    // ── Initial colours ───────────────────────────────────────
    input  logic [8:0][4:0]  in_colours_top,           //! initial top colour mask for each variable.
    input  logic [8:0][4:0]  in_colours_right,         //! initial right colour mask for each variable.
    input  logic [8:0][4:0]  in_colours_bottom,        //! initial bottom colour mask for each variable.
    input  logic [8:0][4:0]  in_colours_left,          //! initial left colour mask for each variable.

    // ── Initial domains ───────────────────────────────────────
    input  logic [8:0][8:0]  in_domain_r0,             //! initial domain bitmask rotation 0 for each variable.
    input  logic [8:0][8:0]  in_domain_r1,             //! initial domain bitmask rotation 1 for each variable.
    input  logic [8:0][8:0]  in_domain_r2,             //! initial domain bitmask rotation 2 for each variable.
    input  logic [8:0][8:0]  in_domain_r3,             //! initial domain bitmask rotation 3 for each variable.

    // ── Availability masks ────────────────────────────────────
    input  logic [8:0]       in_unassigned_variables,  //! 1=variable position available.
    input  logic [8:0]       in_unassigned_tiles,      //! 1=tile available.

    // ── Result ────────────────────────────────────────────────
    output logic [12:0]      out_solution_count        //! number of solutions found.
);

    // ── Puzzle constants ──────────────────────────────────────
    localparam int N           = 3;
    localparam int V           = 9;  // N * N
    localparam int CC          = 5;  // 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT
    localparam int VAR_BIT_SIZE = 4; // $clog2(V)

    // ── Algorithm pipeline ────────────────────────────────────
    // TODO: instantiate constraint propagation pipeline here
    // e.g. DomainToColour, CascadeColours, AllDifferent,
    //      SingletonDetection, search/backtrack state machine

endmodule
