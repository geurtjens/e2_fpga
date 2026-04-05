// ─────────────────────────────────────────────────────────────
// Elements_Brendan4
//
//! Tile element colour masks for the Brendan4 puzzle (4x4).
//!
//! Puzzle:  aaxx abxx baxx bbxx /
//!          caxa cbxa daxa ebxa /
//!          daxb dbxb eaxb ebxb /
//!          ccee cdce cddd ceed
//! N=4, V=16, CC=6
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3  d=bit4  e=bit5
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan4_Elements #(
    parameter int CC = 6,
    parameter int V  = 16
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 6'b000001; // boundary grey
    localparam logic [CC-1:0] A = 6'b000010;
    localparam logic [CC-1:0] B = 6'b000100;
    localparam logic [CC-1:0] C = 6'b001000;
    localparam logic [CC-1:0] D = 6'b010000;
    localparam logic [CC-1:0] E = 6'b100000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   aaxx     a     a      x      x
    //   1   abxx     a     b      x      x
    //   2   baxx     b     a      x      x
    //   3   bbxx     b     b      x      x
    //   4   caxa     c     a      x      a
    //   5   cbxa     c     b      x      a
    //   6   daxa     d     a      x      a
    //   7   ebxa     e     b      x      a
    //   8   daxb     d     a      x      b
    //   9   dbxb     d     b      x      b
    //  10   eaxb     e     a      x      b
    //  11   ebxb     e     b      x      b
    //  12   ccee     c     c      e      e
    //  13   cdce     c     d      c      e
    //  14   cddd     c     d      d      d
    //  15   ceed     c     e      e      d

    assign out_elements_top[ 0] = A; // aaxx
    assign out_elements_top[ 1] = A; // abxx
    assign out_elements_top[ 2] = B; // baxx
    assign out_elements_top[ 3] = B; // bbxx
    assign out_elements_top[ 4] = C; // caxa
    assign out_elements_top[ 5] = C; // cbxa
    assign out_elements_top[ 6] = D; // daxa
    assign out_elements_top[ 7] = E; // ebxa
    assign out_elements_top[ 8] = D; // daxb
    assign out_elements_top[ 9] = D; // dbxb
    assign out_elements_top[10] = E; // eaxb
    assign out_elements_top[11] = E; // ebxb
    assign out_elements_top[12] = C; // ccee
    assign out_elements_top[13] = C; // cdce
    assign out_elements_top[14] = C; // cddd
    assign out_elements_top[15] = C; // ceed

    assign out_elements_right[ 0] = A; // aaxx
    assign out_elements_right[ 1] = B; // abxx
    assign out_elements_right[ 2] = A; // baxx
    assign out_elements_right[ 3] = B; // bbxx
    assign out_elements_right[ 4] = A; // caxa
    assign out_elements_right[ 5] = B; // cbxa
    assign out_elements_right[ 6] = A; // daxa
    assign out_elements_right[ 7] = B; // ebxa
    assign out_elements_right[ 8] = A; // daxb
    assign out_elements_right[ 9] = B; // dbxb
    assign out_elements_right[10] = A; // eaxb
    assign out_elements_right[11] = B; // ebxb
    assign out_elements_right[12] = C; // ccee
    assign out_elements_right[13] = D; // cdce
    assign out_elements_right[14] = D; // cddd
    assign out_elements_right[15] = E; // ceed

    assign out_elements_bottom[ 0] = X; // aaxx
    assign out_elements_bottom[ 1] = X; // abxx
    assign out_elements_bottom[ 2] = X; // baxx
    assign out_elements_bottom[ 3] = X; // bbxx
    assign out_elements_bottom[ 4] = X; // caxa
    assign out_elements_bottom[ 5] = X; // cbxa
    assign out_elements_bottom[ 6] = X; // daxa
    assign out_elements_bottom[ 7] = X; // ebxa
    assign out_elements_bottom[ 8] = X; // daxb
    assign out_elements_bottom[ 9] = X; // dbxb
    assign out_elements_bottom[10] = X; // eaxb
    assign out_elements_bottom[11] = X; // ebxb
    assign out_elements_bottom[12] = E; // ccee
    assign out_elements_bottom[13] = C; // cdce
    assign out_elements_bottom[14] = D; // cddd
    assign out_elements_bottom[15] = E; // ceed

    assign out_elements_left[ 0] = X; // aaxx
    assign out_elements_left[ 1] = X; // abxx
    assign out_elements_left[ 2] = X; // baxx
    assign out_elements_left[ 3] = X; // bbxx
    assign out_elements_left[ 4] = A; // caxa
    assign out_elements_left[ 5] = A; // cbxa
    assign out_elements_left[ 6] = A; // daxa
    assign out_elements_left[ 7] = A; // ebxa
    assign out_elements_left[ 8] = B; // daxb
    assign out_elements_left[ 9] = B; // dbxb
    assign out_elements_left[10] = B; // eaxb
    assign out_elements_left[11] = B; // ebxb
    assign out_elements_left[12] = E; // ccee
    assign out_elements_left[13] = E; // cdce
    assign out_elements_left[14] = D; // cddd
    assign out_elements_left[15] = D; // ceed

endmodule
