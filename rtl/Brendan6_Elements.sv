// ─────────────────────────────────────────────────────────────
// Elements_Brendan6
//
//! Tile element colour masks for the Brendan6 puzzle (6x6).
//!
//! Puzzle:  aaxx acxx bbxx bcxx faxa fbxa /
//!          haxa hbxa hcxa daxb eaxb fbxb /
//!          fcxb gcxb dbxc dcxc eaxc fbxc /
//!          gaxc hbxc ddge deee dehh dffg /
//!          dfgh dgfe dgge dggg dhef dheg /
//!          dhgf dhgh efeg effh efgh ehfh
//! N=6, V=36, CC=9
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3  d=bit4
//!          e=bit5  f=bit6  g=bit7  h=bit8
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan6_Elements #(
    parameter int CC = 9,
    parameter int V  = 36
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 9'b000000001; // boundary grey
    localparam logic [CC-1:0] A = 9'b000000010;
    localparam logic [CC-1:0] B = 9'b000000100;
    localparam logic [CC-1:0] C = 9'b000001000;
    localparam logic [CC-1:0] D = 9'b000010000;
    localparam logic [CC-1:0] E = 9'b000100000;
    localparam logic [CC-1:0] F = 9'b001000000;
    localparam logic [CC-1:0] G = 9'b010000000;
    localparam logic [CC-1:0] H = 9'b100000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   aaxx     a     a      x      x
    //   1   acxx     a     c      x      x
    //   2   bbxx     b     b      x      x
    //   3   bcxx     b     c      x      x
    //   4   faxa     f     a      x      a
    //   5   fbxa     f     b      x      a
    //   6   haxa     h     a      x      a
    //   7   hbxa     h     b      x      a
    //   8   hcxa     h     c      x      a
    //   9   daxb     d     a      x      b
    //  10   eaxb     e     a      x      b
    //  11   fbxb     f     b      x      b
    //  12   fcxb     f     c      x      b
    //  13   gcxb     g     c      x      b
    //  14   dbxc     d     b      x      c
    //  15   dcxc     d     c      x      c
    //  16   eaxc     e     a      x      c
    //  17   fbxc     f     b      x      c
    //  18   gaxc     g     a      x      c
    //  19   hbxc     h     b      x      c
    //  20   ddge     d     d      g      e
    //  21   deee     d     e      e      e
    //  22   dehh     d     e      h      h
    //  23   dffg     d     f      f      g
    //  24   dfgh     d     f      g      h
    //  25   dgfe     d     g      f      e
    //  26   dgge     d     g      g      e
    //  27   dggg     d     g      g      g
    //  28   dhef     d     h      e      f
    //  29   dheg     d     h      e      g
    //  30   dhgf     d     h      g      f
    //  31   dhgh     d     h      g      h
    //  32   efeg     e     f      e      g
    //  33   effh     e     f      f      h
    //  34   efgh     e     f      g      h
    //  35   ehfh     e     h      f      h

    assign out_elements_top[ 0] = A; // aaxx
    assign out_elements_top[ 1] = A; // acxx
    assign out_elements_top[ 2] = B; // bbxx
    assign out_elements_top[ 3] = B; // bcxx
    assign out_elements_top[ 4] = F; // faxa
    assign out_elements_top[ 5] = F; // fbxa
    assign out_elements_top[ 6] = H; // haxa
    assign out_elements_top[ 7] = H; // hbxa
    assign out_elements_top[ 8] = H; // hcxa
    assign out_elements_top[ 9] = D; // daxb
    assign out_elements_top[10] = E; // eaxb
    assign out_elements_top[11] = F; // fbxb
    assign out_elements_top[12] = F; // fcxb
    assign out_elements_top[13] = G; // gcxb
    assign out_elements_top[14] = D; // dbxc
    assign out_elements_top[15] = D; // dcxc
    assign out_elements_top[16] = E; // eaxc
    assign out_elements_top[17] = F; // fbxc
    assign out_elements_top[18] = G; // gaxc
    assign out_elements_top[19] = H; // hbxc
    assign out_elements_top[20] = D; // ddge
    assign out_elements_top[21] = D; // deee
    assign out_elements_top[22] = D; // dehh
    assign out_elements_top[23] = D; // dffg
    assign out_elements_top[24] = D; // dfgh
    assign out_elements_top[25] = D; // dgfe
    assign out_elements_top[26] = D; // dgge
    assign out_elements_top[27] = D; // dggg
    assign out_elements_top[28] = D; // dhef
    assign out_elements_top[29] = D; // dheg
    assign out_elements_top[30] = D; // dhgf
    assign out_elements_top[31] = D; // dhgh
    assign out_elements_top[32] = E; // efeg
    assign out_elements_top[33] = E; // effh
    assign out_elements_top[34] = E; // efgh
    assign out_elements_top[35] = E; // ehfh

    assign out_elements_right[ 0] = A; // aaxx
    assign out_elements_right[ 1] = C; // acxx
    assign out_elements_right[ 2] = B; // bbxx
    assign out_elements_right[ 3] = C; // bcxx
    assign out_elements_right[ 4] = A; // faxa
    assign out_elements_right[ 5] = B; // fbxa
    assign out_elements_right[ 6] = A; // haxa
    assign out_elements_right[ 7] = B; // hbxa
    assign out_elements_right[ 8] = C; // hcxa
    assign out_elements_right[ 9] = A; // daxb
    assign out_elements_right[10] = A; // eaxb
    assign out_elements_right[11] = B; // fbxb
    assign out_elements_right[12] = C; // fcxb
    assign out_elements_right[13] = C; // gcxb
    assign out_elements_right[14] = B; // dbxc
    assign out_elements_right[15] = C; // dcxc
    assign out_elements_right[16] = A; // eaxc
    assign out_elements_right[17] = B; // fbxc
    assign out_elements_right[18] = A; // gaxc
    assign out_elements_right[19] = B; // hbxc
    assign out_elements_right[20] = D; // ddge
    assign out_elements_right[21] = E; // deee
    assign out_elements_right[22] = E; // dehh
    assign out_elements_right[23] = F; // dffg
    assign out_elements_right[24] = F; // dfgh
    assign out_elements_right[25] = G; // dgfe
    assign out_elements_right[26] = G; // dgge
    assign out_elements_right[27] = G; // dggg
    assign out_elements_right[28] = H; // dhef
    assign out_elements_right[29] = H; // dheg
    assign out_elements_right[30] = H; // dhgf
    assign out_elements_right[31] = H; // dhgh
    assign out_elements_right[32] = F; // efeg
    assign out_elements_right[33] = F; // effh
    assign out_elements_right[34] = F; // efgh
    assign out_elements_right[35] = H; // ehfh

    assign out_elements_bottom[ 0] = X; // aaxx
    assign out_elements_bottom[ 1] = X; // acxx
    assign out_elements_bottom[ 2] = X; // bbxx
    assign out_elements_bottom[ 3] = X; // bcxx
    assign out_elements_bottom[ 4] = X; // faxa
    assign out_elements_bottom[ 5] = X; // fbxa
    assign out_elements_bottom[ 6] = X; // haxa
    assign out_elements_bottom[ 7] = X; // hbxa
    assign out_elements_bottom[ 8] = X; // hcxa
    assign out_elements_bottom[ 9] = X; // daxb
    assign out_elements_bottom[10] = X; // eaxb
    assign out_elements_bottom[11] = X; // fbxb
    assign out_elements_bottom[12] = X; // fcxb
    assign out_elements_bottom[13] = X; // gcxb
    assign out_elements_bottom[14] = X; // dbxc
    assign out_elements_bottom[15] = X; // dcxc
    assign out_elements_bottom[16] = X; // eaxc
    assign out_elements_bottom[17] = X; // fbxc
    assign out_elements_bottom[18] = X; // gaxc
    assign out_elements_bottom[19] = X; // hbxc
    assign out_elements_bottom[20] = G; // ddge
    assign out_elements_bottom[21] = E; // deee
    assign out_elements_bottom[22] = H; // dehh
    assign out_elements_bottom[23] = F; // dffg
    assign out_elements_bottom[24] = G; // dfgh
    assign out_elements_bottom[25] = F; // dgfe
    assign out_elements_bottom[26] = G; // dgge
    assign out_elements_bottom[27] = G; // dggg
    assign out_elements_bottom[28] = E; // dhef
    assign out_elements_bottom[29] = E; // dheg
    assign out_elements_bottom[30] = G; // dhgf
    assign out_elements_bottom[31] = G; // dhgh
    assign out_elements_bottom[32] = E; // efeg
    assign out_elements_bottom[33] = F; // effh
    assign out_elements_bottom[34] = G; // efgh
    assign out_elements_bottom[35] = F; // ehfh

    assign out_elements_left[ 0] = X; // aaxx
    assign out_elements_left[ 1] = X; // acxx
    assign out_elements_left[ 2] = X; // bbxx
    assign out_elements_left[ 3] = X; // bcxx
    assign out_elements_left[ 4] = A; // faxa
    assign out_elements_left[ 5] = A; // fbxa
    assign out_elements_left[ 6] = A; // haxa
    assign out_elements_left[ 7] = A; // hbxa
    assign out_elements_left[ 8] = A; // hcxa
    assign out_elements_left[ 9] = B; // daxb
    assign out_elements_left[10] = B; // eaxb
    assign out_elements_left[11] = B; // fbxb
    assign out_elements_left[12] = B; // fcxb
    assign out_elements_left[13] = B; // gcxb
    assign out_elements_left[14] = C; // dbxc
    assign out_elements_left[15] = C; // dcxc
    assign out_elements_left[16] = C; // eaxc
    assign out_elements_left[17] = C; // fbxc
    assign out_elements_left[18] = C; // gaxc
    assign out_elements_left[19] = C; // hbxc
    assign out_elements_left[20] = E; // ddge
    assign out_elements_left[21] = E; // deee
    assign out_elements_left[22] = H; // dehh
    assign out_elements_left[23] = G; // dffg
    assign out_elements_left[24] = H; // dfgh
    assign out_elements_left[25] = E; // dgfe
    assign out_elements_left[26] = E; // dgge
    assign out_elements_left[27] = G; // dggg
    assign out_elements_left[28] = F; // dhef
    assign out_elements_left[29] = G; // dheg
    assign out_elements_left[30] = F; // dhgf
    assign out_elements_left[31] = H; // dhgh
    assign out_elements_left[32] = G; // efeg
    assign out_elements_left[33] = H; // effh
    assign out_elements_left[34] = H; // efgh
    assign out_elements_left[35] = H; // ehfh

endmodule
