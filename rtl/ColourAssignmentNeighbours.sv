// ─────────────────────────────────────────────────────────────
// ColourAssignmentNeighbours
//
//! Propagates colour constraints from an assigned variable to
//! its four neighbours (right, below, left, above).
//! Each neighbour's shared edge is ANDed with the assigned
//! piece's colour on that edge — constraining what colours
//! remain valid for that neighbour.
//! Variables on the grid boundary have fewer neighbours —
//! boundary checks are handled internally.
//!
//! Parameters
//!   N       — board side length (board is N x N)
//!   CC      — total colour bits per edge
//!   V       — N * N
//!   ID_BITS — $clog2(V)
// ─────────────────────────────────────────────────────────────
module ColourAssignmentNeighbours #(
    parameter int N       = 4,          //! size of puzzle grid.
    parameter int V       = N * N,      //! number of variables.
    parameter int CC      = 6,          //! colour bits per edge.
    parameter int ID_BITS = $clog2(V)   //! bits needed to index a variable.
)(
    input  logic [ID_BITS-1:0]    in_variableId,        //! variable whose neighbours are being updated.

    input  logic [CC-1:0]         in_piece_top,         //! assigned piece's top colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_right,       //! assigned piece's right colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_bottom,      //! assigned piece's bottom colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_left,        //! assigned piece's left colour at chosen rotation.

    input  logic [V-1:0][CC-1:0]  in_colours_top,      //! current top colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_right,    //! current right colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_bottom,   //! current bottom colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_left,     //! current left colour array.

    output logic [V-1:0][CC-1:0]  out_colours_top,     //! updated top colour array.
    output logic [V-1:0][CC-1:0]  out_colours_right,   //! updated right colour array.
    output logic [V-1:0][CC-1:0]  out_colours_bottom,  //! updated bottom colour array.
    output logic [V-1:0][CC-1:0]  out_colours_left     //! updated left colour array.
);

    // ── Integer version of variableId for safe arithmetic ─────
    logic [31:0] vid;
    assign vid = 32'(in_variableId);

    always_comb begin : propagate_to_neighbours

        // ── Default: pass all colour arrays through unchanged ──
        out_colours_top    = in_colours_top;
        out_colours_right  = in_colours_right;
        out_colours_bottom = in_colours_bottom;
        out_colours_left   = in_colours_left;

        // ── Right neighbour (col < N-1) ────────────────────────
        if ((vid % N) < N-1)
            out_colours_left[vid+1] = in_colours_left[vid+1] & in_piece_right;

        // ── Below neighbour (row < N-1) ────────────────────────
        if ((vid / N) < N-1)
            out_colours_top[vid+N] = in_colours_top[vid+N] & in_piece_bottom;

        // ── Left neighbour (col > 0) ───────────────────────────
        if ((vid % N) > 0)
            out_colours_right[vid-1] = in_colours_right[vid-1] & in_piece_left;

        // ── Above neighbour (row > 0) ──────────────────────────
        if ((vid / N) > 0)
            out_colours_bottom[vid-N] = in_colours_bottom[vid-N] & in_piece_top;

    end

endmodule
