// ─────────────────────────────────────────────────────────────
// Top_Brendan3
//
//! Top-level module for the Brendan3 puzzle (3x3).
//!
//! Wires together Load_Brendan3, Solve_Brendan3, and the
//! 7-segment display encoder to show the solution count.
//!
//! Target: DE10-Standard (Cyclone V)
//! Clock:  50 MHz (PIN_AF14)
//! Display: HEX0..HEX5 (active low 7-segment)
// ─────────────────────────────────────────────────────────────
module Top_Brendan3 (
    input  logic       clk,    //! 50 MHz clock.

    output logic [6:0] HEX0,   //! 7-segment digit 0 (ones).
    output logic [6:0] HEX1,   //! 7-segment digit 1 (tens).
    output logic [6:0] HEX2,   //! 7-segment digit 2 (hundreds).
    output logic [6:0] HEX3,   //! 7-segment digit 3 (thousands).
    output logic [6:0] HEX4,   //! 7-segment digit 4 (ten-thousands).
    output logic [6:0] HEX5    //! 7-segment digit 5 (blank/unused).
);

    // ── Wires from Load_Brendan3 ──────────────────────────────
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

    // ── Solution count ────────────────────────────────────────
    logic [12:0]      w_solution_count;

    // ── Load_Brendan3 ─────────────────────────────────────────
    Load_Brendan3 load (
        .out_N                   (),   // unused in top — for debug/testbench only
        .out_V                   (),
        .out_CC                  (),
        .out_BORDER_COLOURS      (),
        .out_INNER_COLOURS       (),
        .out_VAR_BIT_SIZE        (),
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

    // ── Solve_Brendan3 ────────────────────────────────────────
    Solve_Brendan3 solve (
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
        .out_solution_count      (w_solution_count)
    );

    // ── 7-segment display ─────────────────────────────────────
    // Display solution count as decimal across HEX0..HEX4
    // HEX5 is blanked
    SevenSegDecimal display (
        .in_value  (w_solution_count),
        .out_HEX0  (HEX0),
        .out_HEX1  (HEX1),
        .out_HEX2  (HEX2),
        .out_HEX3  (HEX3),
        .out_HEX4  (HEX4),
        .out_HEX5  (HEX5)
    );

endmodule
