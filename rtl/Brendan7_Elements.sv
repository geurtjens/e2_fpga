// ─────────────────────────────────────────────────────────────
// Elements_Brendan7
//
//! Tile element colour masks for the Brendan7 puzzle (7x7).
//!
//! N=7, V=49, CC=10
//! Colours: x=bit0  a=bit1  b=bit2  c=bit3  d=bit4
//!          e=bit5  f=bit6  g=bit7  h=bit8  i=bit9
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan7_Elements #(
    parameter int CC = 10,
    parameter int V  = 49
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 10'b0000000001; // boundary grey
    localparam logic [CC-1:0] A = 10'b0000000010;
    localparam logic [CC-1:0] B = 10'b0000000100;
    localparam logic [CC-1:0] C = 10'b0000001000;
    localparam logic [CC-1:0] D = 10'b0000010000;
    localparam logic [CC-1:0] E = 10'b0000100000;
    localparam logic [CC-1:0] F = 10'b0001000000;
    localparam logic [CC-1:0] G = 10'b0010000000;
    localparam logic [CC-1:0] H = 10'b0100000000;
    localparam logic [CC-1:0] I = 10'b1000000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   abxx     a     b      x      x
    //   1   acxx     a     c      x      x
    //   2   baxx     b     a      x      x
    //   3   cbxx     c     b      x      x
    //   4   eaxa     e     a      x      a
    //   5   faxa     f     a      x      a
    //   6   fcxa     f     c      x      a
    //   7   gbxa     g     b      x      a
    //   8   hbxa     h     b      x      a
    //   9   hcxa     h     c      x      a
    //  10   dbxb     d     b      x      b
    //  11   ecxb     e     c      x      b
    //  12   gbxb     g     b      x      b
    //  13   hbxb     h     b      x      b
    //  14   hcxb     h     c      x      b
    //  15   iaxb     i     a      x      b
    //  16   icxb     i     c      x      b
    //  17   daxc     d     a      x      c
    //  18   dbxc     d     b      x      c
    //  19   eaxc     e     a      x      c
    //  20   faxc     f     a      x      c
    //  21   fcxc     f     c      x      c
    //  22   hcxc     h     c      x      c
    //  23   iaxc     i     a      x      c
    //  24   ddeh     d     d      e      h
    //  25   ddge     d     d      g      e
    //  26   ddgg     d     d      g      g
    //  27   deeg     d     e      e      g
    //  28   dehe     d     e      h      e
    //  29   dfeg     d     f      e      g
    //  30   dfgf     d     f      g      f
    //  31   dhfi     d     h      f      i
    //  32   dhgg     d     h      g      g
    //  33   dhie     d     h      i      e
    //  34   dhif     d     h      i      f
    //  35   difh     d     i      f      h
    //  36   dihe     d     i      h      e
    //  37   diif     d     i      i      f
    //  38   eehg     e     e      h      g
    //  39   eeig     e     e      i      g
    //  40   efgg     e     f      g      g
    //  41   efhf     e     f      h      f
    //  42   efii     e     f      i      i
    //  43   eigi     e     i      g      i
    //  44   fgih     f     g      i      h
    //  45   fhgg     f     h      g      g
    //  46   fhhg     f     h      h      g
    //  47   fihi     f     i      h      i
    //  48   fiig     f     i      i      g

    assign out_elements_top[ 0] = A; // abxx
    assign out_elements_top[ 1] = A; // acxx
    assign out_elements_top[ 2] = B; // baxx
    assign out_elements_top[ 3] = C; // cbxx
    assign out_elements_top[ 4] = E; // eaxa
    assign out_elements_top[ 5] = F; // faxa
    assign out_elements_top[ 6] = F; // fcxa
    assign out_elements_top[ 7] = G; // gbxa
    assign out_elements_top[ 8] = H; // hbxa
    assign out_elements_top[ 9] = H; // hcxa
    assign out_elements_top[10] = D; // dbxb
    assign out_elements_top[11] = E; // ecxb
    assign out_elements_top[12] = G; // gbxb
    assign out_elements_top[13] = H; // hbxb
    assign out_elements_top[14] = H; // hcxb
    assign out_elements_top[15] = I; // iaxb
    assign out_elements_top[16] = I; // icxb
    assign out_elements_top[17] = D; // daxc
    assign out_elements_top[18] = D; // dbxc
    assign out_elements_top[19] = E; // eaxc
    assign out_elements_top[20] = F; // faxc
    assign out_elements_top[21] = F; // fcxc
    assign out_elements_top[22] = H; // hcxc
    assign out_elements_top[23] = I; // iaxc
    assign out_elements_top[24] = D; // ddeh
    assign out_elements_top[25] = D; // ddge
    assign out_elements_top[26] = D; // ddgg
    assign out_elements_top[27] = D; // deeg
    assign out_elements_top[28] = D; // dehe
    assign out_elements_top[29] = D; // dfeg
    assign out_elements_top[30] = D; // dfgf
    assign out_elements_top[31] = D; // dhfi
    assign out_elements_top[32] = D; // dhgg
    assign out_elements_top[33] = D; // dhie
    assign out_elements_top[34] = D; // dhif
    assign out_elements_top[35] = D; // difh
    assign out_elements_top[36] = D; // dihe
    assign out_elements_top[37] = D; // diif
    assign out_elements_top[38] = E; // eehg
    assign out_elements_top[39] = E; // eeig
    assign out_elements_top[40] = E; // efgg
    assign out_elements_top[41] = E; // efhf
    assign out_elements_top[42] = E; // efii
    assign out_elements_top[43] = E; // eigi
    assign out_elements_top[44] = F; // fgih
    assign out_elements_top[45] = F; // fhgg
    assign out_elements_top[46] = F; // fhhg
    assign out_elements_top[47] = F; // fihi
    assign out_elements_top[48] = F; // fiig

    assign out_elements_right[ 0] = B; // abxx
    assign out_elements_right[ 1] = C; // acxx
    assign out_elements_right[ 2] = A; // baxx
    assign out_elements_right[ 3] = B; // cbxx
    assign out_elements_right[ 4] = A; // eaxa
    assign out_elements_right[ 5] = A; // faxa
    assign out_elements_right[ 6] = C; // fcxa
    assign out_elements_right[ 7] = B; // gbxa
    assign out_elements_right[ 8] = B; // hbxa
    assign out_elements_right[ 9] = C; // hcxa
    assign out_elements_right[10] = B; // dbxb
    assign out_elements_right[11] = C; // ecxb
    assign out_elements_right[12] = B; // gbxb
    assign out_elements_right[13] = B; // hbxb
    assign out_elements_right[14] = C; // hcxb
    assign out_elements_right[15] = A; // iaxb
    assign out_elements_right[16] = C; // icxb
    assign out_elements_right[17] = A; // daxc
    assign out_elements_right[18] = B; // dbxc
    assign out_elements_right[19] = A; // eaxc
    assign out_elements_right[20] = A; // faxc
    assign out_elements_right[21] = C; // fcxc
    assign out_elements_right[22] = C; // hcxc
    assign out_elements_right[23] = A; // iaxc
    assign out_elements_right[24] = D; // ddeh
    assign out_elements_right[25] = D; // ddge
    assign out_elements_right[26] = D; // ddgg
    assign out_elements_right[27] = E; // deeg
    assign out_elements_right[28] = E; // dehe
    assign out_elements_right[29] = F; // dfeg
    assign out_elements_right[30] = F; // dfgf
    assign out_elements_right[31] = H; // dhfi
    assign out_elements_right[32] = H; // dhgg
    assign out_elements_right[33] = H; // dhie
    assign out_elements_right[34] = H; // dhif
    assign out_elements_right[35] = I; // difh
    assign out_elements_right[36] = I; // dihe
    assign out_elements_right[37] = I; // diif
    assign out_elements_right[38] = E; // eehg
    assign out_elements_right[39] = E; // eeig
    assign out_elements_right[40] = F; // efgg
    assign out_elements_right[41] = F; // efhf
    assign out_elements_right[42] = F; // efii
    assign out_elements_right[43] = I; // eigi
    assign out_elements_right[44] = G; // fgih
    assign out_elements_right[45] = H; // fhgg
    assign out_elements_right[46] = H; // fhhg
    assign out_elements_right[47] = I; // fihi
    assign out_elements_right[48] = I; // fiig

    assign out_elements_bottom[ 0] = X; // abxx
    assign out_elements_bottom[ 1] = X; // acxx
    assign out_elements_bottom[ 2] = X; // baxx
    assign out_elements_bottom[ 3] = X; // cbxx
    assign out_elements_bottom[ 4] = X; // eaxa
    assign out_elements_bottom[ 5] = X; // faxa
    assign out_elements_bottom[ 6] = X; // fcxa
    assign out_elements_bottom[ 7] = X; // gbxa
    assign out_elements_bottom[ 8] = X; // hbxa
    assign out_elements_bottom[ 9] = X; // hcxa
    assign out_elements_bottom[10] = X; // dbxb
    assign out_elements_bottom[11] = X; // ecxb
    assign out_elements_bottom[12] = X; // gbxb
    assign out_elements_bottom[13] = X; // hbxb
    assign out_elements_bottom[14] = X; // hcxb
    assign out_elements_bottom[15] = X; // iaxb
    assign out_elements_bottom[16] = X; // icxb
    assign out_elements_bottom[17] = X; // daxc
    assign out_elements_bottom[18] = X; // dbxc
    assign out_elements_bottom[19] = X; // eaxc
    assign out_elements_bottom[20] = X; // faxc
    assign out_elements_bottom[21] = X; // fcxc
    assign out_elements_bottom[22] = X; // hcxc
    assign out_elements_bottom[23] = X; // iaxc
    assign out_elements_bottom[24] = E; // ddeh
    assign out_elements_bottom[25] = G; // ddge
    assign out_elements_bottom[26] = G; // ddgg
    assign out_elements_bottom[27] = E; // deeg
    assign out_elements_bottom[28] = H; // dehe
    assign out_elements_bottom[29] = E; // dfeg
    assign out_elements_bottom[30] = G; // dfgf
    assign out_elements_bottom[31] = F; // dhfi
    assign out_elements_bottom[32] = G; // dhgg
    assign out_elements_bottom[33] = I; // dhie
    assign out_elements_bottom[34] = I; // dhif
    assign out_elements_bottom[35] = F; // difh
    assign out_elements_bottom[36] = H; // dihe
    assign out_elements_bottom[37] = I; // diif
    assign out_elements_bottom[38] = H; // eehg
    assign out_elements_bottom[39] = I; // eeig
    assign out_elements_bottom[40] = G; // efgg
    assign out_elements_bottom[41] = H; // efhf
    assign out_elements_bottom[42] = I; // efii
    assign out_elements_bottom[43] = G; // eigi
    assign out_elements_bottom[44] = I; // fgih
    assign out_elements_bottom[45] = G; // fhgg
    assign out_elements_bottom[46] = H; // fhhg
    assign out_elements_bottom[47] = H; // fihi
    assign out_elements_bottom[48] = I; // fiig

    assign out_elements_left[ 0] = X; // abxx
    assign out_elements_left[ 1] = X; // acxx
    assign out_elements_left[ 2] = X; // baxx
    assign out_elements_left[ 3] = X; // cbxx
    assign out_elements_left[ 4] = A; // eaxa
    assign out_elements_left[ 5] = A; // faxa
    assign out_elements_left[ 6] = A; // fcxa
    assign out_elements_left[ 7] = A; // gbxa
    assign out_elements_left[ 8] = A; // hbxa
    assign out_elements_left[ 9] = A; // hcxa
    assign out_elements_left[10] = B; // dbxb
    assign out_elements_left[11] = B; // ecxb
    assign out_elements_left[12] = B; // gbxb
    assign out_elements_left[13] = B; // hbxb
    assign out_elements_left[14] = B; // hcxb
    assign out_elements_left[15] = B; // iaxb
    assign out_elements_left[16] = B; // icxb
    assign out_elements_left[17] = C; // daxc
    assign out_elements_left[18] = C; // dbxc
    assign out_elements_left[19] = C; // eaxc
    assign out_elements_left[20] = C; // faxc
    assign out_elements_left[21] = C; // fcxc
    assign out_elements_left[22] = C; // hcxc
    assign out_elements_left[23] = C; // iaxc
    assign out_elements_left[24] = H; // ddeh
    assign out_elements_left[25] = E; // ddge
    assign out_elements_left[26] = G; // ddgg
    assign out_elements_left[27] = G; // deeg
    assign out_elements_left[28] = E; // dehe
    assign out_elements_left[29] = G; // dfeg
    assign out_elements_left[30] = F; // dfgf
    assign out_elements_left[31] = I; // dhfi
    assign out_elements_left[32] = G; // dhgg
    assign out_elements_left[33] = E; // dhie
    assign out_elements_left[34] = F; // dhif
    assign out_elements_left[35] = H; // difh
    assign out_elements_left[36] = E; // dihe
    assign out_elements_left[37] = F; // diif
    assign out_elements_left[38] = G; // eehg
    assign out_elements_left[39] = G; // eeig
    assign out_elements_left[40] = G; // efgg
    assign out_elements_left[41] = F; // efhf
    assign out_elements_left[42] = I; // efii
    assign out_elements_left[43] = I; // eigi
    assign out_elements_left[44] = H; // fgih
    assign out_elements_left[45] = G; // fhgg
    assign out_elements_left[46] = G; // fhhg
    assign out_elements_left[47] = I; // fihi
    assign out_elements_left[48] = G; // fiig

endmodule
