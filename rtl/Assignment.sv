// ─────────────────────────────────────────────────────────────
// Assignment
//
// Assigns a specific piece at a specific rotation to a variable.
// Updates the assigned variable's domain and colours, then
// propagates colour constraints to all four neighbours.
//
// Part 1 — Lock the assigned variable's domain:
//   Only one bit in one rotation survives — the chosen tileId
//   in the chosen rotation. All other rotations become zero.
//
// Part 2 — Set the assigned variable's colours:
//   Looks up the piece's actual colours from pattern data and
//   sets top/right/bottom/left to exactly those colours.
//
// Part 3 — Update neighbouring colours:
//   Each neighbour's shared edge is ANDed with the assigned
//   piece's colour on that edge. If any result is zero that
//   neighbour has no valid colour on that edge — deadend.
//
// Parameters
//   N         — board side length (board is N x N)
//   TC        — total colour bits per edge
//   VARIABLES — N * N
//   ID_BITS   — $clog2(VARIABLES)
//
// Inputs
//   variableId — which variable is being assigned
//   tileId     — which piece is being placed
//   rotation   — which rotation (0-3)
//   in_top..left — current colour arrays for all variables
//   p0..p3_*   — piece pattern data from LoadPuzzle
//
// Outputs
//   out_top..left  — updated colour arrays
//   out_r0..r3     — updated domain (assigned variable locked)
//   colours_changed — 1 if any neighbour colour changed
// ─────────────────────────────────────────────────────────────
module Assignment #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N,
    parameter int ID_BITS   = $clog2(VARIABLES)
)(
    // ── Assignment inputs ──────────────────────────────────────
    input  logic [ID_BITS-1:0] variableId,
    input  logic [ID_BITS-1:0] tileId,
    input  logic [1:0]         rotation,

    // ── Current colour arrays ──────────────────────────────────
    input  logic [VARIABLES-1:0][TC-1:0] in_top,
    input  logic [VARIABLES-1:0][TC-1:0] in_right,
    input  logic [VARIABLES-1:0][TC-1:0] in_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] in_left,

    // ── Current domain arrays ──────────────────────────────────
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r3,

    // ── Piece pattern data from LoadPuzzle ─────────────────────
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
    output logic [VARIABLES-1:0][TC-1:0]        out_top,
    output logic [VARIABLES-1:0][TC-1:0]        out_right,
    output logic [VARIABLES-1:0][TC-1:0]        out_bottom,
    output logic [VARIABLES-1:0][TC-1:0]        out_left,

    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r0,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r1,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r2,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r3,

    output logic                                colours_changed
);
    // ── Coordinate helpers ─────────────────────────────────────
    logic [ID_BITS-1:0] x, y;
    assign x = variableId % N;
    assign y = variableId / N;

    // ── Piece colour for assigned tile at chosen rotation ──────
    logic [TC-1:0] piece_top, piece_right, piece_bottom, piece_left;

    always_comb begin
        case (rotation)
            2'd0: begin
                piece_top    = p0_top[tileId];
                piece_right  = p0_right[tileId];
                piece_bottom = p0_bottom[tileId];
                piece_left   = p0_left[tileId];
            end
            2'd1: begin
                piece_top    = p1_top[tileId];
                piece_right  = p1_right[tileId];
                piece_bottom = p1_bottom[tileId];
                piece_left   = p1_left[tileId];
            end
            2'd2: begin
                piece_top    = p2_top[tileId];
                piece_right  = p2_right[tileId];
                piece_bottom = p2_bottom[tileId];
                piece_left   = p2_left[tileId];
            end
            default: begin
                piece_top    = p3_top[tileId];
                piece_right  = p3_right[tileId];
                piece_bottom = p3_bottom[tileId];
                piece_left   = p3_left[tileId];
            end
        endcase
    end

    // ── Tile domain mask — one hot for the chosen tile ─────────
    logic [VARIABLES-1:0] tile_mask;
    always_comb begin
        tile_mask = '0;
        tile_mask[tileId] = 1'b1;
    end

    // ── Main combinational logic ───────────────────────────────
    always_comb begin
        // ── Default: pass everything through unchanged ─────────
        out_top    = in_top;
        out_right  = in_right;
        out_bottom = in_bottom;
        out_left   = in_left;
        out_r0     = in_r0;
        out_r1     = in_r1;
        out_r2     = in_r2;
        out_r3     = in_r3;

        // ── Part 1 — lock the assigned variable's domain ───────
        // Only the chosen tile at the chosen rotation survives
        out_r0[variableId] = (rotation == 2'd0) ? tile_mask : '0;
        out_r1[variableId] = (rotation == 2'd1) ? tile_mask : '0;
        out_r2[variableId] = (rotation == 2'd2) ? tile_mask : '0;
        out_r3[variableId] = (rotation == 2'd3) ? tile_mask : '0;

        // ── Part 2 — set the assigned variable's own colours ───
        // Colours are locked to exactly what the piece provides
        out_top[variableId]    = piece_top;
        out_right[variableId]  = piece_right;
        out_bottom[variableId] = piece_bottom;
        out_left[variableId]   = piece_left;

        // ── Part 3 — update neighbouring colours ───────────────
        // Each neighbour's shared edge is ANDed with the piece's
        // colour on that edge — constraining what colours remain

        // right neighbour (x < N-1): its left AND our right
        if (x < N-1) begin
            out_left[variableId+1] =
                in_left[variableId+1] & piece_right;
        end

        // below neighbour (y < N-1): its top AND our bottom
        if (y < N-1) begin
            out_top[variableId+N] =
                in_top[variableId+N] & piece_bottom;
        end

        // left neighbour (x > 0): its right AND our left
        if (x > 0) begin
            out_right[variableId-1] =
                in_right[variableId-1] & piece_left;
        end

        // above neighbour (y > 0): its bottom AND our top
        if (y > 0) begin
            out_bottom[variableId-N] =
                in_bottom[variableId-N] & piece_top;
        end

        // ── Colours changed detection ──────────────────────────
        colours_changed = 1'b0;
        if (x < N-1 && out_left[variableId+1]   != in_left[variableId+1])
            colours_changed = 1'b1;
        if (y < N-1 && out_top[variableId+N]    != in_top[variableId+N])
            colours_changed = 1'b1;
        if (x > 0   && out_right[variableId-1]  != in_right[variableId-1])
            colours_changed = 1'b1;
        if (y > 0   && out_bottom[variableId-N] != in_bottom[variableId-N])
            colours_changed = 1'b1;
    end

endmodule
