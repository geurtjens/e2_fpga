// ─────────────────────────────────────────────────────────────
// DomainToColourAll
//
// Derives colour constraint masks for every variable on the
// board from its current domain.
//
// For each variable the output colour mask per edge is the OR
// of that edge's colour across all pieces still in the domain,
// across all valid rotations for that position.
//
// Border and corner positions contribute only their one valid
// rotation. Inner positions contribute all four rotations.
//
// Rotation convention:
//   rotation 0 — border faces bottom  (bottom edge / BL corner)
//   rotation 1 — border faces left    (left edge  / TL corner)
//   rotation 2 — border faces top     (top edge   / TR corner)
//   rotation 3 — border faces right   (right edge / BR corner)
//
// Parameters
//   N         — board side length (board is N x N)
//   TC        — total colour bits per edge
//   VARIABLES — N * N
//
// Outputs
//   out_top..left — derived colour masks per variable
//   changed       — 1 if any colour mask changed
//   deadend       — 1 if any variable has all-zero colour output
//                   despite having a non-empty domain
// ─────────────────────────────────────────────────────────────
module DomainToColourAll #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N
)(
    // ── Domain inputs ──────────────────────────────────────────
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r3,

    // ── Current colour masks (to detect change) ────────────────
    input  logic [VARIABLES-1:0][TC-1:0] in_top,
    input  logic [VARIABLES-1:0][TC-1:0] in_right,
    input  logic [VARIABLES-1:0][TC-1:0] in_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] in_left,

    // ── Piece pattern data (broadcast to all instances) ────────
    input  logic [VARIABLES-1:0][TC-1:0] p0_top,
    input  logic [VARIABLES-1:0][TC-1:0] p0_right,
    input  logic [VARIABLES-1:0][TC-1:0] p0_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p0_left,

    input  logic [VARIABLES-1:0][TC-1:0] p1_top,
    input  logic [VARIABLES-1:0][TC-1:0] p1_right,
    input  logic [VARIABLES-1:0][TC-1:0] p1_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p1_left,

    input  logic [VARIABLES-1:0][TC-1:0] p2_top,
    input  logic [VARIABLES-1:0][TC-1:0] p2_right,
    input  logic [VARIABLES-1:0][TC-1:0] p2_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p2_left,

    input  logic [VARIABLES-1:0][TC-1:0] p3_top,
    input  logic [VARIABLES-1:0][TC-1:0] p3_right,
    input  logic [VARIABLES-1:0][TC-1:0] p3_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p3_left,

    // ── Outputs ────────────────────────────────────────────────
    output logic [VARIABLES-1:0][TC-1:0] out_top,
    output logic [VARIABLES-1:0][TC-1:0] out_right,
    output logic [VARIABLES-1:0][TC-1:0] out_bottom,
    output logic [VARIABLES-1:0][TC-1:0] out_left,
    output logic                         changed,
    output logic                         deadend
);
    logic [VARIABLES-1:0] v_changed;
    logic [VARIABLES-1:0] v_deadend;

    genvar gx, gy;
    generate
        for (gy = 0; gy < N; gy++) begin : gen_y
            for (gx = 0; gx < N; gx++) begin : gen_x
                localparam int id = gy*N + gx;

                // ── Intermediate wires for multi-rotation OR ───
                // For inner positions we OR the outputs of all
                // four DomainToColourRotation instances together
                logic [TC-1:0] t0, r0w, b0, l0;
                logic [TC-1:0] t1, r1w, b1, l1;
                logic [TC-1:0] t2, r2w, b2, l2;
                logic [TC-1:0] t3, r3w, b3, l3;

                // ── Corners — one rotation each ────────────────
                if (gx == 0 && gy == N-1) begin : bottom_left
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r0[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gx == 0 && gy == 0) begin : top_left
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r1[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gx == N-1 && gy == 0) begin : top_right
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r2[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gx == N-1 && gy == N-1) begin : bottom_right
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r3[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                // ── Edges — one rotation each ──────────────────
                end else if (gy == N-1) begin : bottom_edge
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r0[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gx == 0) begin : left_edge
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r1[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gy == 0) begin : top_edge
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r2[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                end else if (gx == N-1) begin : right_edge
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r3[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .top(out_top[id]), .right(out_right[id]),
                        .bottom(out_bottom[id]), .left(out_left[id])
                    );

                // ── Inner — OR across all four rotations ────────
                end else begin : inner
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot0 (
                        .domain(r0[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .top(t0), .right(r0w), .bottom(b0), .left(l0)
                    );
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot1 (
                        .domain(r1[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .top(t1), .right(r1w), .bottom(b1), .left(l1)
                    );
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot2 (
                        .domain(r2[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .top(t2), .right(r2w), .bottom(b2), .left(l2)
                    );
                    DomainToColourRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot3 (
                        .domain(r3[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .top(t3), .right(r3w), .bottom(b3), .left(l3)
                    );

                    // OR all four rotation results together
                    assign out_top[id]    = t0 | t1 | t2 | t3;
                    assign out_right[id]  = r0w | r1w | r2w | r3w;
                    assign out_bottom[id] = b0 | b1 | b2 | b3;
                    assign out_left[id]   = l0 | l1 | l2 | l3;
                end

                // ── changed and deadend per variable ───────────
                assign v_changed[id] =
                    (out_top[id]    != in_top[id])    ||
                    (out_right[id]  != in_right[id])  ||
                    (out_bottom[id] != in_bottom[id]) ||
                    (out_left[id]   != in_left[id]);

                assign v_deadend[id] =
                    ((r0[id] | r1[id] | r2[id] | r3[id]) != '0) &&
                    ((out_top[id] | out_right[id] |
                      out_bottom[id] | out_left[id]) == '0);

            end
        end
    endgenerate

    assign changed = |v_changed;
    assign deadend = |v_deadend;

endmodule
