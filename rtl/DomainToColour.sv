// ─────────────────────────────────────────────────────────────
// DomainToColour
//
//! Derives colour masks from domain bitmasks for all variables.
//! Each variable's colour is the OR of all pieces still in its domain.
//!
//! Position type determines which rotations are used:
//!   Corner    — one rotation only
//!   Edge      — one rotation only
//!   Inner     — all four rotations OR'd together
//!
//! out_changed — 1 if any colour changed from input
//! out_deadend — 1 if any active variable has all-zero colours

//
//! Derives colour masks from domain bitmasks for all variables.
//! Each variable's colour is the OR of all pieces still in its domain.
//!
//! Takes a single set of tile elements and derives all four
//! rotations internally by rewiring the four sides:
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
//!
//! Position type determines which rotations are used:
//!   Corner    — one rotation only
//!   Edge      — one rotation only
//!   Inner     — all four rotations OR'd together
//!
//! out_changed — 1 if any colour changed from input
//! out_deadend — 1 if any active variable has all-zero colours
// ─────────────────────────────────────────────────────────────
module DomainToColour #(
    parameter int N  = 4,
    parameter int CC = 6,
    parameter int V  = N * N
)(
    // ── Domain bitmasks ───────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0, //! domain bitmask for rotation 0 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1, //! domain bitmask for rotation 1 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2, //! domain bitmask for rotation 2 for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3, //! domain bitmask for rotation 3 for each variable.

    // ── Current colour masks ──────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,    //! current top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,  //! current right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom, //! current bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,   //! current left colour mask for each variable.

    // ── Tile elements (base orientation, rotation handled internally) ──
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Derived colour masks ──────────────────────────────────
    output logic [V-1:0][CC-1:0] out_colours_top,    //! derived top colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_right,  //! derived right colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_bottom, //! derived bottom colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colours_left,   //! derived left colour mask for each variable.

    output logic                 out_changed, //! 1 if any colour changed from input.
    output logic                 out_deadend  //! 1 if any active variable has all-zero colours.
);

    // ── Rotation wiring ───────────────────────────────────────
    //! The four rotations are derived purely by rewiring the four
    //! sides of the base element set. No logic is required — the
    //! synthesiser will connect these directly as wires.
    //!
    //!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
    //!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
    //!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
    //!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top

    logic [V-1:0][CC-1:0] el0_top, el0_right, el0_bottom, el0_left; //! base orientation.
    logic [V-1:0][CC-1:0] el1_top, el1_right, el1_bottom, el1_left; //! 90 degrees clockwise.
    logic [V-1:0][CC-1:0] el2_top, el2_right, el2_bottom, el2_left; //! 180 degrees.
    logic [V-1:0][CC-1:0] el3_top, el3_right, el3_bottom, el3_left; //! 270 degrees clockwise.

    assign el0_top    = in_elements_top;
    assign el0_right  = in_elements_right;
    assign el0_bottom = in_elements_bottom;
    assign el0_left   = in_elements_left;

    assign el1_top    = in_elements_left;
    assign el1_right  = in_elements_top;
    assign el1_bottom = in_elements_right;
    assign el1_left   = in_elements_bottom;

    assign el2_top    = in_elements_bottom;
    assign el2_right  = in_elements_left;
    assign el2_bottom = in_elements_top;
    assign el2_left   = in_elements_right;

    assign el3_top    = in_elements_right;
    assign el3_right  = in_elements_bottom;
    assign el3_bottom = in_elements_left;
    assign el3_left   = in_elements_top;

    logic [V-1:0] v_changed; //! per-variable changed flag.
    logic [V-1:0] v_deadend; //! per-variable deadend flag.

    genvar gx, gy;
    generate
        for (gy = 0; gy < N; gy++) begin : gen_y
            for (gx = 0; gx < N; gx++) begin : gen_x
                localparam int id = gy*N + gx;

                // ── Bottom-left corner — rotation 0 ───────────
                if (gx == 0 && gy == N-1) begin : bottom_left
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r0[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Top-left corner — rotation 1 ──────────────
                end else if (gx == 0 && gy == 0) begin : top_left
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r1[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Top-right corner — rotation 2 ─────────────
                end else if (gx == N-1 && gy == 0) begin : top_right
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r2[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Bottom-right corner — rotation 3 ──────────
                end else if (gx == N-1 && gy == N-1) begin : bottom_right
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r3[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Bottom edge — rotation 0 ───────────────────
                end else if (gy == N-1) begin : bottom_edge
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r0[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Left edge — rotation 1 ─────────────────────
                end else if (gx == 0) begin : left_edge
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r1[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Top edge — rotation 2 ──────────────────────
                end else if (gy == 0) begin : top_edge
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r2[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Right edge — rotation 3 ────────────────────
                end else if (gx == N-1) begin : right_edge
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r3[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_colour_top    (out_colours_top[id]),
                        .out_colour_right  (out_colours_right[id]),
                        .out_colour_bottom (out_colours_bottom[id]),
                        .out_colour_left   (out_colours_left[id])
                    );

                // ── Inner — OR across all four rotations ────────
                //! Inner variables can hold any tile in any rotation
                //! so all four rotations are OR'd together to give
                //! the full set of colours still possible.
                end else begin : inner

                    logic [CC-1:0] t0, r0w, b0, l0;
                    logic [CC-1:0] t1, r1w, b1, l1;
                    logic [CC-1:0] t2, r2w, b2, l2;
                    logic [CC-1:0] t3, r3w, b3, l3;

                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot0 (
                        .in_domain         (in_domain_r0[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_colour_top    (t0),
                        .out_colour_right  (r0w),
                        .out_colour_bottom (b0),
                        .out_colour_left   (l0)
                    );
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot1 (
                        .in_domain         (in_domain_r1[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_colour_top    (t1),
                        .out_colour_right  (r1w),
                        .out_colour_bottom (b1),
                        .out_colour_left   (l1)
                    );
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot2 (
                        .in_domain         (in_domain_r2[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_colour_top    (t2),
                        .out_colour_right  (r2w),
                        .out_colour_bottom (b2),
                        .out_colour_left   (l2)
                    );
                    DomainToColour_Rotation #(.V(V), .CC(CC)) rot3 (
                        .in_domain         (in_domain_r3[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_colour_top    (t3),
                        .out_colour_right  (r3w),
                        .out_colour_bottom (b3),
                        .out_colour_left   (l3)
                    );

                    assign out_colours_top[id]    = t0 | t1 | t2 | t3;
                    assign out_colours_right[id]  = r0w | r1w | r2w | r3w;
                    assign out_colours_bottom[id] = b0 | b1 | b2 | b3;
                    assign out_colours_left[id]   = l0 | l1 | l2 | l3;
                end

                // ── changed and deadend per variable ───────────
                assign v_changed[id] =
                    (out_colours_top[id]    != in_colours_top[id])    ||
                    (out_colours_right[id]  != in_colours_right[id])  ||
                    (out_colours_bottom[id] != in_colours_bottom[id]) ||
                    (out_colours_left[id]   != in_colours_left[id]);

                assign v_deadend[id] =
                    ((in_domain_r0[id] | in_domain_r1[id] |
                      in_domain_r2[id] | in_domain_r3[id]) != '0) &&
                    ((out_colours_top[id]    | out_colours_right[id] |
                      out_colours_bottom[id] | out_colours_left[id]) == '0);
            end
        end
    endgenerate

    assign out_changed = |v_changed;
    assign out_deadend = |v_deadend;

endmodule
