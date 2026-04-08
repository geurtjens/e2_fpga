// ─────────────────────────────────────────────────────────────
// ColourAssignment
//
//! Writes a single variable's colours into the colour arrays.
//! Receives the four piece colours from the caller — colour
//! lookup is handled externally by ColourLookup.
//! No neighbour propagation.
//!
//! Parameters
//!   N       — board side length (board is N x N)
//!   CC      — total colour bits per edge
//!   V       — N * N
//!   ID_BITS — $clog2(V)
// ─────────────────────────────────────────────────────────────
module ColourAssignment #(
    parameter int N       = 4,          //! size of puzzle grid.
    parameter int V       = N * N,      //! number of variables.
    parameter int CC      = 6,          //! colour bits per edge.
    parameter int ID_BITS = $clog2(V)   //! bits needed to index a variable.
)(
    input  logic [ID_BITS-1:0]    in_variableId,        //! variable being updated.

    input  logic [CC-1:0]         in_piece_top,         //! piece top colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_right,       //! piece right colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_bottom,      //! piece bottom colour at chosen rotation.
    input  logic [CC-1:0]         in_piece_left,        //! piece left colour at chosen rotation.

    input  logic [V-1:0][CC-1:0]  in_colours_top,      //! current top colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_right,    //! current right colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_bottom,   //! current bottom colour array.
    input  logic [V-1:0][CC-1:0]  in_colours_left,     //! current left colour array.

    output logic [V-1:0][CC-1:0]  out_colours_top,     //! updated top colour array.
    output logic [V-1:0][CC-1:0]  out_colours_right,   //! updated right colour array.
    output logic [V-1:0][CC-1:0]  out_colours_bottom,  //! updated bottom colour array.
    output logic [V-1:0][CC-1:0]  out_colours_left     //! updated left colour array.
);

    always_comb begin : write_variable_colours
        out_colours_top    = in_colours_top;
        out_colours_right  = in_colours_right;
        out_colours_bottom = in_colours_bottom;
        out_colours_left   = in_colours_left;

        out_colours_top[in_variableId]    = in_piece_top;
        out_colours_right[in_variableId]  = in_piece_right;
        out_colours_bottom[in_variableId] = in_piece_bottom;
        out_colours_left[in_variableId]   = in_piece_left;
    end

endmodule