// ─────────────────────────────────────────────────────────────
// ColoursToDomain
//
// Filters the domain of every variable on the board by checking
// each piece against the variable's colour constraints.
//
// Border and corner positions have only one valid rotation.
// Inner positions have all four rotations.
//
// Rotation convention:
//   rotation 0 — border faces bottom  (bottom edge / BL corner)
//   rotation 1 — border faces left    (left edge  / TL corner)
//   rotation 2 — border faces top     (top edge   / TR corner)
//   rotation 3 — border faces right   (right edge / BR corner)
//
// Parameters
//   N         — board side length (board is N x N)
//   CC        — total colour bits per edge
//   V — N * N
//
// Outputs
//   r0_out..r3_out — filtered domain bitmasks per variable
//   changed        — 1 if any domain changed
//   deadend        — 1 if any variable has empty domain
// ─────────────────────────────────────────────────────────────
module ColourToDomain #(
    parameter int N         = 4,
    parameter int CC        = 6,
    parameter int V = N * N
)(
    // ── Domain inputs ──────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0,
    input  logic [V-1:0][V-1:0] in_domain_r1,
    input  logic [V-1:0][V-1:0] in_domain_r2,
    input  logic [V-1:0][V-1:0] in_domain_r3,

    // ── Colour constraint inputs ───────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colours_top,
    input  logic [V-1:0][CC-1:0] in_colours_right,
    input  logic [V-1:0][CC-1:0] in_colours_bottom,
    input  logic [V-1:0][CC-1:0] in_colours_left,

    // ── Piece pattern data (broadcast to all instances) ────────
    input  logic [V-1:0][CC-1:0] in_element0_top,
    input  logic [V-1:0][CC-1:0] in_element0_right,
    input  logic [V-1:0][CC-1:0] in_element0_bottom,
    input  logic [V-1:0][CC-1:0] in_element0_left,

    input  logic [V-1:0][CC-1:0] in_element1_top,
    input  logic [V-1:0][CC-1:0] in_element1_right,
    input  logic [V-1:0][CC-1:0] in_element1_bottom,
    input  logic [V-1:0][CC-1:0] in_element1_left,

    input  logic [V-1:0][CC-1:0] in_element2_top,
    input  logic [V-1:0][CC-1:0] in_element2_right,
    input  logic [V-1:0][CC-1:0] in_element2_bottom,
    input  logic [V-1:0][CC-1:0] in_element2_left,

    input  logic [V-1:0][CC-1:0] in_element3_top,
    input  logic [V-1:0][CC-1:0] in_element3_right,
    input  logic [V-1:0][CC-1:0] in_element3_bottom,
    input  logic [V-1:0][CC-1:0] in_element3_left,

    // ── Outputs ────────────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0,
    output logic [V-1:0][V-1:0] out_domain_r1,
    output logic [V-1:0][V-1:0] out_domain_r2,
    output logic [V-1:0][V-1:0] out_domain_r3,
    output logic                out_changed,
    output logic                out_deadend
);
    // ── Per-variable changed and deadend wires ─────────────────
    logic [V-1:0] v_changed;
    logic [V-1:0] v_deadend;

    // ── Unused rotation outputs tied off ───────────────────────
    // Border/corner positions only use one rotation; the unused
    // rotation outputs are tied to the input domain unchanged
    // so they neither signal changed nor deadend

    genvar gx, gy;
    generate
        for (gy = 0; gy < N; gy++) begin : gen_y
            for (gx = 0; gx < N; gx++) begin : gen_x
                localparam int id = gy*N + gx;

                // ── Corners — one rotation each ────────────────
                if (gx == 0 && gy == N-1) begin : bottom_left
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r0[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element0_top), 
                        .in_element_right(in_element0_right),
                        .in_element_bottom(in_element0_bottom), 
                        .in_element_left(in_element0_left),
                        .out_domain(out_domain_r0[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gx == 0 && gy == 0) begin : top_left
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r1[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element1_top), 
                        .in_element_right(in_element1_right),
                        .in_element_bottom(in_element1_bottom), 
                        .in_element_left(in_element1_left),
                        .out_domain(out_domain_r1[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gx == N-1 && gy == 0) begin : top_right
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r2[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element2_top), 
                        .in_element_right(in_element2_right),
                        .in_element_bottom(in_element2_bottom), 
                        .in_element_left(in_element2_left),
                        .out_domain(out_domain_r2[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gx == N-1 && gy == N-1) begin : bottom_right
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r3[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element3_top), 
                        .in_element_right(in_element3_right),
                        .in_element_bottom(in_element3_bottom), 
                        .in_element_left(in_element3_left),
                        .out_domain(out_domain_r3[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];

                // ── Edges — one rotation each ──────────────────
                end else if (gy == N-1) begin : bottom_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r0[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element0_top), 
                        .in_element_right(in_element0_right),
                        .in_element_bottom(in_element0_bottom), 
                        .in_element_left(in_element0_left),
                        .out_domain(out_domain_r0[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gx == 0) begin : left_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r1[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element1_top), 
                        .in_element_right(in_element1_right),
                        .in_element_bottom(in_element1_bottom), 
                        .in_element_left(in_element1_left),
                        .out_domain(out_domain_r1[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r2[id] = in_domain_r2[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gy == 0) begin : top_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r2[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element2_top), 
                        .in_element_right(in_element2_right),
                        .in_element_bottom(in_element2_bottom), 
                        .in_element_left(in_element2_left),
                        .out_domain(out_domain_r2[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r3[id] = in_domain_r3[id];

                end else if (gx == N-1) begin : right_edge
                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot (
                        .in_domain(in_domain_r3[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element3_top), 
                        .in_element_right(in_element3_right),
                        .in_element_bottom(in_element3_bottom), 
                        .in_element_left(in_element3_left),
                        .out_domain(out_domain_r3[id]),
                        .out_changed(v_changed[id]), 
                        .out_deadend(v_deadend[id])
                    );
                    assign out_domain_r0[id] = in_domain_r0[id];
                    assign out_domain_r1[id] = in_domain_r1[id];
                    assign out_domain_r2[id] = in_domain_r2[id];

                // ── Inner — all four rotations ─────────────────
                end else begin : inner
                    logic rot0_changed, rot0_deadend;
                    logic rot1_changed, rot1_deadend;
                    logic rot2_changed, rot2_deadend;
                    logic rot3_changed, rot3_deadend;

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot0 (
                        .in_domain(in_domain_r0[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element0_top), 
                        .in_element_right(in_element0_right),
                        .in_element_bottom(in_element0_bottom), 
                        .in_element_left(in_element0_left),
                        .out_domain(out_domain_r0[id]),
                        .out_changed(rot0_changed), 
                        .out_deadend(rot0_deadend)
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot1 (
                        .in_domain(in_domain_r1[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element1_top), 
                        .in_element_right(in_element1_right),
                        .in_element_bottom(in_element1_bottom), 
                        .in_element_left(in_element1_left),
                        .out_domain(out_domain_r1[id]),
                        .out_changed(rot1_changed), 
                        .out_deadend(rot1_deadend)
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot2 (
                        .in_domain(in_domain_r2[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element2_top), 
                        .in_element_right(in_element2_right),
                        .in_element_bottom(in_element2_bottom), 
                        .in_element_left(in_element2_left),
                        .out_domain(out_domain_r2[id]),
                        .out_changed(rot2_changed), 
                        .out_deadend(rot2_deadend)
                    );

                    ColourToDomain_Rotation #(.V(V), .CC(CC)) rot3 (
                        .in_domain(in_domain_r3[id]), 
                        .in_colour_top(in_colours_top[id]), 
                        .in_colour_right(in_colours_right[id]),
                        .in_colour_bottom(in_colours_bottom[id]), 
                        .in_colour_left(in_colours_left[id]),
                        .in_element_top(in_element3_top), 
                        .in_element_right(in_element3_right),
                        .in_element_bottom(in_element3_bottom), 
                        .in_element_left(in_element3_left),
                        .out_domain(out_domain_r3[id]),
                        .out_changed(rot3_changed), 
                        .out_deadend(rot3_deadend)
                    );

                    assign v_changed[id] = rot0_changed | rot1_changed |
                                           rot2_changed | rot3_changed;
                    assign v_deadend[id] = rot0_deadend | rot1_deadend |
                                           rot2_deadend | rot3_deadend;
                end

            end
        end
    endgenerate

    assign out_changed = |v_changed;
    assign out_deadend = |v_deadend;

endmodule
