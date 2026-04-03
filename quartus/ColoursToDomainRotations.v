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
//   TC        — total colour bits per edge
//   VARIABLES — N * N
//
// Outputs
//   r0_out..r3_out — filtered domain bitmasks per variable
//   changed        — 1 if any domain changed
//   deadend        — 1 if any variable has empty domain
// ─────────────────────────────────────────────────────────────
module ColourToDomainAll #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N
)(
    // ── Domain inputs ──────────────────────────────────────────
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r3,

    // ── Colour constraint inputs ───────────────────────────────
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
    output logic [VARIABLES-1:0][VARIABLES-1:0] r0_out,
    output logic [VARIABLES-1:0][VARIABLES-1:0] r1_out,
    output logic [VARIABLES-1:0][VARIABLES-1:0] r2_out,
    output logic [VARIABLES-1:0][VARIABLES-1:0] r3_out,
    output logic                                changed,
    output logic                                deadend
);
    // ── Per-variable changed and deadend wires ─────────────────
    logic [VARIABLES-1:0] v_changed;
    logic [VARIABLES-1:0] v_deadend;

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
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r0[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .domain_out(r0_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r1_out[id] = r1[id];
                    assign r2_out[id] = r2[id];
                    assign r3_out[id] = r3[id];

                end else if (gx == 0 && gy == 0) begin : top_left
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r1[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .domain_out(r1_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r2_out[id] = r2[id];
                    assign r3_out[id] = r3[id];

                end else if (gx == N-1 && gy == 0) begin : top_right
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r2[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .domain_out(r2_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r1_out[id] = r1[id];
                    assign r3_out[id] = r3[id];

                end else if (gx == N-1 && gy == N-1) begin : bottom_right
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r3[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .domain_out(r3_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r1_out[id] = r1[id];
                    assign r2_out[id] = r2[id];

                // ── Edges — one rotation each ──────────────────
                end else if (gy == N-1) begin : bottom_edge
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r0[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .domain_out(r0_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r1_out[id] = r1[id];
                    assign r2_out[id] = r2[id];
                    assign r3_out[id] = r3[id];

                end else if (gx == 0) begin : left_edge
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r1[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .domain_out(r1_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r2_out[id] = r2[id];
                    assign r3_out[id] = r3[id];

                end else if (gy == 0) begin : top_edge
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r2[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .domain_out(r2_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r1_out[id] = r1[id];
                    assign r3_out[id] = r3[id];

                end else if (gx == N-1) begin : right_edge
                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot (
                        .domain(r3[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .domain_out(r3_out[id]),
                        .changed(v_changed[id]), .deadend(v_deadend[id])
                    );
                    assign r0_out[id] = r0[id];
                    assign r1_out[id] = r1[id];
                    assign r2_out[id] = r2[id];

                // ── Inner — all four rotations ─────────────────
                end else begin : inner
                    logic rot0_changed, rot0_deadend;
                    logic rot1_changed, rot1_deadend;
                    logic rot2_changed, rot2_deadend;
                    logic rot3_changed, rot3_deadend;

                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot0 (
                        .domain(r0[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p0_top), .p_right(p0_right),
                        .p_bottom(p0_bottom), .p_left(p0_left),
                        .domain_out(r0_out[id]),
                        .changed(rot0_changed), .deadend(rot0_deadend)
                    );

                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot1 (
                        .domain(r1[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p1_top), .p_right(p1_right),
                        .p_bottom(p1_bottom), .p_left(p1_left),
                        .domain_out(r1_out[id]),
                        .changed(rot1_changed), .deadend(rot1_deadend)
                    );

                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot2 (
                        .domain(r2[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p2_top), .p_right(p2_right),
                        .p_bottom(p2_bottom), .p_left(p2_left),
                        .domain_out(r2_out[id]),
                        .changed(rot2_changed), .deadend(rot2_deadend)
                    );

                    ColoursToDomainRotation #(.VARIABLES(VARIABLES), .TC(TC)) rot3 (
                        .domain(r3[id]), .top(in_top[id]), .right(in_right[id]),
                        .bottom(in_bottom[id]), .left(in_left[id]),
                        .p_top(p3_top), .p_right(p3_right),
                        .p_bottom(p3_bottom), .p_left(p3_left),
                        .domain_out(r3_out[id]),
                        .changed(rot3_changed), .deadend(rot3_deadend)
                    );

                    assign v_changed[id] = rot0_changed | rot1_changed |
                                           rot2_changed | rot3_changed;
                    assign v_deadend[id] = rot0_deadend | rot1_deadend |
                                           rot2_deadend | rot3_deadend;
                end

            end
        end
    endgenerate

    assign changed = |v_changed;
    assign deadend = |v_deadend;

endmodule