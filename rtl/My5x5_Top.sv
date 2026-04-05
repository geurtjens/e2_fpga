// ─────────────────────────────────────────────────────────────
// My5x5_Top
//
//! Top-level module for the My5x5 puzzle (5x5).
//!
//! Wires together My5x5_Load and My5x5_Solve.
//! Returns solution count as an 8-bit value.
//!
//! Target: DE10-Standard (Cyclone V)
//! Clock:  50 MHz
// ─────────────────────────────────────────────────────────────
module My5x5_Top (
    input  logic       clk,               //! 50 MHz clock.
    output logic [7:0] out_solution_count //! number of solutions found.
);

    // ── Wires from My5x5_Load ──────────────────────────────
    logic [24:0][22:0]  w_elements_top;         //! top colour for each tile.
    logic [24:0][22:0]  w_elements_right;       //! right colour for each tile.
    logic [24:0][22:0]  w_elements_bottom;      //! bottom colour for each tile.
    logic [24:0][22:0]  w_elements_left;        //! left colour for each tile.

    logic [24:0][22:0]  w_colours_top;          //! initial top colour mask for each variable.
    logic [24:0][22:0]  w_colours_right;        //! initial right colour mask for each variable.
    logic [24:0][22:0]  w_colours_bottom;       //! initial bottom colour mask for each variable.
    logic [24:0][22:0]  w_colours_left;         //! initial left colour mask for each variable.

    logic [24:0][24:0]   w_domain_r0;            //! initial domain bitmask rotation 0 for each variable.
    logic [24:0][24:0]   w_domain_r1;            //! initial domain bitmask rotation 1 for each variable.
    logic [24:0][24:0]   w_domain_r2;            //! initial domain bitmask rotation 2 for each variable.
    logic [24:0][24:0]   w_domain_r3;            //! initial domain bitmask rotation 3 for each variable.

    logic [24:0]               w_unassigned_variables; //! 1=variable position available.
    logic [24:0]               w_unassigned_tiles;     //! 1=tile available.

    // ── My5x5_Load ─────────────────────────────────────────────
    //! Loads the initial puzzle state — tile elements, colour masks
    //! and domain bitmasks. Pure combinational, no clock required.
    My5x5_Load loader (
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

    // ── My5x5_Solve ────────────────────────────────────────────
    //! Runs the constraint propagation and search algorithm,
    //! counting all solutions found and returning the total.
    My5x5_Solve solver (
        .clk                     (clk),
        .in_elements_top         (w_elements_top),
        .in_elements_right       (w_elements_right),
        .in_elements_bottom      (w_elements_bottom),
        .in_elements_left        (w_elements_left),
        .in_colours_top          (w_colours_top),
        .in_colours_right        (w_colours_right),
        .in_colours_bottom       (w_colours_bottom),
        .in_colours_left         (w_colours_left),
        .in_domain_r0            (w_domain_r0),
        .in_domain_r1            (w_domain_r1),
        .in_domain_r2            (w_domain_r2),
        .in_domain_r3            (w_domain_r3),
        .in_unassigned_variables (w_unassigned_variables),
        .in_unassigned_tiles     (w_unassigned_tiles),
        .out_solution_count      (out_solution_count)
    );

endmodule
