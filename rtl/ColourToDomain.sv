// ─────────────────────────────────────────────────────────────
// ColourToDomain
//
//! Filters the domain of every variable on the board by checking
//! each piece against the variable's colour constraints.
//!
//! Takes a single set of tile elements and derives all four
//! rotations internally by rewiring the four sides:
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
//!
//! Border and corner positions have only one valid rotation.
//! Inner positions have all four rotations.
//!
//! Rotation convention:
//!   rotation 0 — border faces bottom  (bottom edge / BL corner)
//!   rotation 1 — border faces left    (left edge  / TL corner)
//!   rotation 2 — border faces top     (top edge   / TR corner)
//!   rotation 3 — border faces right   (right edge / BR corner)
//!
//! out_changed — 1 if any domain changed
//! out_deadend — 1 if any variable has empty domain
// ─────────────────────────────────────────────────────────────
module ColourToDomain #(
    parameter int N  = 4,    //! Size of grid.
    parameter int CC = 6,    //! Colour count — number of bits to represent colours.
    parameter int V  = N * N //! Variables in grid — N * N.
)(
    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0,        //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,        //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,        //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,        //! rotation 3 domain bitmask for each variable.

    // ── Colour constraint inputs ───────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,     //! top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_right,   //! right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_bottom,  //! bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colours_left,    //! left colour mask for each variable.

    // ── Tile elements (base orientation, rotation handled internally) ──
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Domain outputs ────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0,       //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,       //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,       //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3       //! updated rotation 3 domain bitmask for each variable.
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

    genvar gx, gy;
    generate
        for (gy = 0; gy < N; gy++) begin : gen_y
            for (gx = 0; gx < N; gx++) begin : gen_x
                localparam int id = gy*N + gx;

                // ── Bottom-left corner — rotation 0 ───────────
                if (gx == 0 && gy == N-1) begin : bottom_left
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r0[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_domain        (out_domain_r0[id])
                    );
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Top-left corner — rotation 1 ──────────────
                end else if (gx == 0 && gy == 0) begin : top_left
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r1[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_domain        (out_domain_r1[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Top-right corner — rotation 2 ─────────────
                end else if (gx == N-1 && gy == 0) begin : top_right
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r2[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_domain        (out_domain_r2[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Bottom-right corner — rotation 3 ──────────
                end else if (gx == N-1 && gy == N-1) begin : bottom_right
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r3[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_domain        (out_domain_r3[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];

                // ── Bottom edge — rotation 0 ───────────────────
                end else if (gy == N-1) begin : bottom_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r0[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_domain        (out_domain_r0[id])
                    );
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Left edge — rotation 1 ─────────────────────
                end else if (gx == 0) begin : left_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r1[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_domain        (out_domain_r1[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Top edge — rotation 2 ──────────────────────
                end else if (gy == 0) begin : top_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r2[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_domain        (out_domain_r2[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                // ── Right edge — rotation 3 ────────────────────
                end else if (gx == N-1) begin : right_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain         (in_domain_r3[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_domain        (out_domain_r3[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];

                // ── Inner — all four rotations ─────────────────
                //! Inner variables can hold any tile in any rotation
                //! so all four rotations are filtered independently.
                //! The variable is a deadend only if all four
                //! rotation domains are empty simultaneously.
                end else begin : inner

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot0 (
                        .in_domain         (in_domain_r0[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el0_top),
                        .in_element_right  (el0_right),
                        .in_element_bottom (el0_bottom),
                        .in_element_left   (el0_left),
                        .out_domain        (out_domain_r0[id])
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot1 (
                        .in_domain         (in_domain_r1[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el1_top),
                        .in_element_right  (el1_right),
                        .in_element_bottom (el1_bottom),
                        .in_element_left   (el1_left),
                        .out_domain        (out_domain_r1[id])
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot2 (
                        .in_domain         (in_domain_r2[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el2_top),
                        .in_element_right  (el2_right),
                        .in_element_bottom (el2_bottom),
                        .in_element_left   (el2_left),
                        .out_domain        (out_domain_r2[id])
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot3 (
                        .in_domain         (in_domain_r3[id]),
                        .in_colour_top     (in_colours_top[id]),
                        .in_colour_right   (in_colours_right[id]),
                        .in_colour_bottom  (in_colours_bottom[id]),
                        .in_colour_left    (in_colours_left[id]),
                        .in_element_top    (el3_top),
                        .in_element_right  (el3_right),
                        .in_element_bottom (el3_bottom),
                        .in_element_left   (el3_left),
                        .out_domain        (out_domain_r3[id])
                    );

                end
            end
        end
    endgenerate

endmodule
