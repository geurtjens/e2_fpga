// ─────────────────────────────────────────────────────────────
// Elements_Brendan3
//
//! Tile element colour masks for the Brendan3 puzzle (3x3).
//!
//! Puzzle:  aaxx abxx baxx / bbxx cbxa daxa / caxb dbxb ccdd
//! N=3, V=9, CC=5
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3  d=bit4
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan3_Elements #(
    parameter int CC = 5,
    parameter int V  = 9
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 5'b00001; // boundary grey
    localparam logic [CC-1:0] A = 5'b00010;
    localparam logic [CC-1:0] B = 5'b00100;
    localparam logic [CC-1:0] C = 5'b01000;
    localparam logic [CC-1:0] D = 5'b10000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   aaxx     a     a      x      x
    //   1   abxx     a     b      x      x
    //   2   baxx     b     a      x      x
    //   3   bbxx     b     b      x      x
    //   4   cbxa     c     b      x      a
    //   5   daxa     d     a      x      a
    //   6   caxb     c     a      x      b
    //   7   dbxb     d     b      x      b
    //   8   ccdd     c     c      d      d

    assign out_elements_top[0] = A; // aaxx
    assign out_elements_top[1] = A; // abxx
    assign out_elements_top[2] = B; // baxx
    assign out_elements_top[3] = B; // bbxx
    assign out_elements_top[4] = C; // cbxa
    assign out_elements_top[5] = D; // daxa
    assign out_elements_top[6] = C; // caxb
    assign out_elements_top[7] = D; // dbxb
    assign out_elements_top[8] = C; // ccdd

    assign out_elements_right[0] = A; // aaxx
    assign out_elements_right[1] = B; // abxx
    assign out_elements_right[2] = A; // baxx
    assign out_elements_right[3] = B; // bbxx
    assign out_elements_right[4] = B; // cbxa
    assign out_elements_right[5] = A; // daxa
    assign out_elements_right[6] = A; // caxb
    assign out_elements_right[7] = B; // dbxb
    assign out_elements_right[8] = C; // ccdd

    assign out_elements_bottom[0] = X; // aaxx
    assign out_elements_bottom[1] = X; // abxx
    assign out_elements_bottom[2] = X; // baxx
    assign out_elements_bottom[3] = X; // bbxx
    assign out_elements_bottom[4] = X; // cbxa
    assign out_elements_bottom[5] = X; // daxa
    assign out_elements_bottom[6] = X; // caxb
    assign out_elements_bottom[7] = X; // dbxb
    assign out_elements_bottom[8] = D; // ccdd

    assign out_elements_left[0] = X; // aaxx
    assign out_elements_left[1] = X; // abxx
    assign out_elements_left[2] = X; // baxx
    assign out_elements_left[3] = X; // bbxx
    assign out_elements_left[4] = A; // cbxa
    assign out_elements_left[5] = A; // daxa
    assign out_elements_left[6] = B; // caxb
    assign out_elements_left[7] = B; // dbxb
    assign out_elements_left[8] = D; // ccdd

endmodule
