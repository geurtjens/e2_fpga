// ─────────────────────────────────────────────────────────────
// Elements_Brendan8
//
//! Tile element colour masks for the Brendan8 puzzle (8x8).
//!
//! N=8, V=64, CC=12
//! Colours: x=bit0   a=bit1   b=bit2   c=bit3
//!          d=bit4   e=bit5   f=bit6   g=bit7
//!          h=bit8   i=bit9   j=bit10  k=bit11
//!
//! Rotation is handled externally by the consumer (e.g. DomainToColour).
//!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
//!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
//!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
//!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
// ─────────────────────────────────────────────────────────────
module Brendan8_Elements #(
    parameter int CC = 12,
    parameter int V  = 64
)(
    output logic [V-1:0][CC-1:0] out_elements_top,    //! top colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_right,  //! right colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_bottom, //! bottom colour for each tile.
    output logic [V-1:0][CC-1:0] out_elements_left    //! left colour for each tile.
);

    // ── Colour bit masks ──────────────────────────────────────
    localparam logic [CC-1:0] X = 12'b000000000001; // boundary grey
    localparam logic [CC-1:0] A = 12'b000000000010;
    localparam logic [CC-1:0] B = 12'b000000000100;
    localparam logic [CC-1:0] C = 12'b000000001000;
    localparam logic [CC-1:0] D = 12'b000000010000;
    localparam logic [CC-1:0] E = 12'b000000100000;
    localparam logic [CC-1:0] F = 12'b000001000000;
    localparam logic [CC-1:0] G = 12'b000010000000;
    localparam logic [CC-1:0] H = 12'b000100000000;
    localparam logic [CC-1:0] I = 12'b001000000000;
    localparam logic [CC-1:0] J = 12'b010000000000;
    localparam logic [CC-1:0] K = 12'b100000000000;

    // ── Tile definitions ──────────────────────────────────────
    // tile  string  top  right  bottom  left
    //   0   abxx     a     b      x      x
    //   1   baxx     b     a      x      x
    //   2   bbxx     b     b      x      x
    //   3   bcxx     b     c      x      x
    //   4   daxa     d     a      x      a
    //   5   ecxa     e     c      x      a
    //   6   fcxa     f     c      x      a
    //   7   haxa     h     a      x      a
    //   8   hcxa     h     c      x      a
    //   9   jaxa     j     a      x      a
    //  10   jbxa     j     b      x      a
    //  11   kaxa     k     a      x      a
    //  12   kbxa     k     b      x      a
    //  13   daxb     d     a      x      b
    //  14   dbxb     d     b      x      b
    //  15   dcxb     d     c      x      b
    //  16   iaxb     i     a      x      b
    //  17   ibxb     i     b      x      b
    //  18   jcxb     j     c      x      b
    //  19   dbxc     d     b      x      c
    //  20   dcxc     d     c      x      c
    //  21   eaxc     e     a      x      c
    //  22   ebxc     e     b      x      c
    //  23   iaxc     i     a      x      c
    //  24   icxc     i     c      x      c
    //  25   jbxc     j     b      x      c
    //  26   kaxc     k     a      x      c
    //  27   kcxc     k     c      x      c
    //  28   dedg     d     e      d      g
    //  29   dejf     d     e      j      f
    //  30   dfei     d     f      e      i
    //  31   dfge     d     f      g      e
    //  32   dfji     d     f      j      i
    //  33   dgdi     d     g      d      i
    //  34   dgef     d     g      e      f
    //  35   dhgk     d     h      g      k
    //  36   dhjj     d     h      j      j
    //  37   dife     d     i      f      e
    //  38   difh     d     i      f      h
    //  39   djkh     d     j      k      h
    //  40   dkgj     d     k      g      j
    //  41   dkhf     d     k      h      f
    //  42   eeeh     e     e      e      h
    //  43   eekj     e     e      k      j
    //  44   efjj     e     f      j      j
    //  45   egej     e     g      e      j
    //  46   egfi     e     g      f      i
    //  47   ehff     e     h      f      f
    //  48   eiff     e     i      f      f
    //  49   eihk     e     i      h      k
    //  50   ekhg     e     k      h      g
    //  51   ffhk     f     f      h      k
    //  52   fghg     f     g      h      g
    //  53   fgkg     f     g      k      g
    //  54   fhgi     f     h      g      i
    //  55   fijg     f     i      j      g
    //  56   fjgh     f     j      g      h
    //  57   ghik     g     h      i      k
    //  58   gijk     g     i      j      k
    //  59   gjjh     g     j      j      h
    //  60   gjkk     g     j      k      k
    //  61   gkih     g     k      i      h
    //  62   gkii     g     k      i      i
    //  63   hhik     h     h      i      k

    assign out_elements_top[ 0] = A; // abxx
    assign out_elements_top[ 1] = B; // baxx
    assign out_elements_top[ 2] = B; // bbxx
    assign out_elements_top[ 3] = B; // bcxx
    assign out_elements_top[ 4] = D; // daxa
    assign out_elements_top[ 5] = E; // ecxa
    assign out_elements_top[ 6] = F; // fcxa
    assign out_elements_top[ 7] = H; // haxa
    assign out_elements_top[ 8] = H; // hcxa
    assign out_elements_top[ 9] = J; // jaxa
    assign out_elements_top[10] = J; // jbxa
    assign out_elements_top[11] = K; // kaxa
    assign out_elements_top[12] = K; // kbxa
    assign out_elements_top[13] = D; // daxb
    assign out_elements_top[14] = D; // dbxb
    assign out_elements_top[15] = D; // dcxb
    assign out_elements_top[16] = I; // iaxb
    assign out_elements_top[17] = I; // ibxb
    assign out_elements_top[18] = J; // jcxb
    assign out_elements_top[19] = D; // dbxc
    assign out_elements_top[20] = D; // dcxc
    assign out_elements_top[21] = E; // eaxc
    assign out_elements_top[22] = E; // ebxc
    assign out_elements_top[23] = I; // iaxc
    assign out_elements_top[24] = I; // icxc
    assign out_elements_top[25] = J; // jbxc
    assign out_elements_top[26] = K; // kaxc
    assign out_elements_top[27] = K; // kcxc
    assign out_elements_top[28] = D; // dedg
    assign out_elements_top[29] = D; // dejf
    assign out_elements_top[30] = D; // dfei
    assign out_elements_top[31] = D; // dfge
    assign out_elements_top[32] = D; // dfji
    assign out_elements_top[33] = D; // dgdi
    assign out_elements_top[34] = D; // dgef
    assign out_elements_top[35] = D; // dhgk
    assign out_elements_top[36] = D; // dhjj
    assign out_elements_top[37] = D; // dife
    assign out_elements_top[38] = D; // difh
    assign out_elements_top[39] = D; // djkh
    assign out_elements_top[40] = D; // dkgj
    assign out_elements_top[41] = D; // dkhf
    assign out_elements_top[42] = E; // eeeh
    assign out_elements_top[43] = E; // eekj
    assign out_elements_top[44] = E; // efjj
    assign out_elements_top[45] = E; // egej
    assign out_elements_top[46] = E; // egfi
    assign out_elements_top[47] = E; // ehff
    assign out_elements_top[48] = E; // eiff
    assign out_elements_top[49] = E; // eihk
    assign out_elements_top[50] = E; // ekhg
    assign out_elements_top[51] = F; // ffhk
    assign out_elements_top[52] = F; // fghg
    assign out_elements_top[53] = F; // fgkg
    assign out_elements_top[54] = F; // fhgi
    assign out_elements_top[55] = F; // fijg
    assign out_elements_top[56] = F; // fjgh
    assign out_elements_top[57] = G; // ghik
    assign out_elements_top[58] = G; // gijk
    assign out_elements_top[59] = G; // gjjh
    assign out_elements_top[60] = G; // gjkk
    assign out_elements_top[61] = G; // gkih
    assign out_elements_top[62] = G; // gkii
    assign out_elements_top[63] = H; // hhik

    assign out_elements_right[ 0] = B; // abxx
    assign out_elements_right[ 1] = A; // baxx
    assign out_elements_right[ 2] = B; // bbxx
    assign out_elements_right[ 3] = C; // bcxx
    assign out_elements_right[ 4] = A; // daxa
    assign out_elements_right[ 5] = C; // ecxa
    assign out_elements_right[ 6] = C; // fcxa
    assign out_elements_right[ 7] = A; // haxa
    assign out_elements_right[ 8] = C; // hcxa
    assign out_elements_right[ 9] = A; // jaxa
    assign out_elements_right[10] = B; // jbxa
    assign out_elements_right[11] = A; // kaxa
    assign out_elements_right[12] = B; // kbxa
    assign out_elements_right[13] = A; // daxb
    assign out_elements_right[14] = B; // dbxb
    assign out_elements_right[15] = C; // dcxb
    assign out_elements_right[16] = A; // iaxb
    assign out_elements_right[17] = B; // ibxb
    assign out_elements_right[18] = C; // jcxb
    assign out_elements_right[19] = B; // dbxc
    assign out_elements_right[20] = C; // dcxc
    assign out_elements_right[21] = A; // eaxc
    assign out_elements_right[22] = B; // ebxc
    assign out_elements_right[23] = A; // iaxc
    assign out_elements_right[24] = C; // icxc
    assign out_elements_right[25] = B; // jbxc
    assign out_elements_right[26] = A; // kaxc
    assign out_elements_right[27] = C; // kcxc
    assign out_elements_right[28] = E; // dedg
    assign out_elements_right[29] = E; // dejf
    assign out_elements_right[30] = F; // dfei
    assign out_elements_right[31] = F; // dfge
    assign out_elements_right[32] = F; // dfji
    assign out_elements_right[33] = G; // dgdi
    assign out_elements_right[34] = G; // dgef
    assign out_elements_right[35] = H; // dhgk
    assign out_elements_right[36] = H; // dhjj
    assign out_elements_right[37] = I; // dife
    assign out_elements_right[38] = I; // difh
    assign out_elements_right[39] = J; // djkh
    assign out_elements_right[40] = K; // dkgj
    assign out_elements_right[41] = K; // dkhf
    assign out_elements_right[42] = E; // eeeh
    assign out_elements_right[43] = E; // eekj
    assign out_elements_right[44] = F; // efjj
    assign out_elements_right[45] = G; // egej
    assign out_elements_right[46] = G; // egfi
    assign out_elements_right[47] = H; // ehff
    assign out_elements_right[48] = I; // eiff
    assign out_elements_right[49] = I; // eihk
    assign out_elements_right[50] = K; // ekhg
    assign out_elements_right[51] = F; // ffhk
    assign out_elements_right[52] = G; // fghg
    assign out_elements_right[53] = G; // fgkg
    assign out_elements_right[54] = H; // fhgi
    assign out_elements_right[55] = I; // fijg
    assign out_elements_right[56] = J; // fjgh
    assign out_elements_right[57] = H; // ghik
    assign out_elements_right[58] = I; // gijk
    assign out_elements_right[59] = J; // gjjh
    assign out_elements_right[60] = J; // gjkk
    assign out_elements_right[61] = K; // gkih
    assign out_elements_right[62] = K; // gkii
    assign out_elements_right[63] = H; // hhik

    assign out_elements_bottom[ 0] = X; // abxx
    assign out_elements_bottom[ 1] = X; // baxx
    assign out_elements_bottom[ 2] = X; // bbxx
    assign out_elements_bottom[ 3] = X; // bcxx
    assign out_elements_bottom[ 4] = X; // daxa
    assign out_elements_bottom[ 5] = X; // ecxa
    assign out_elements_bottom[ 6] = X; // fcxa
    assign out_elements_bottom[ 7] = X; // haxa
    assign out_elements_bottom[ 8] = X; // hcxa
    assign out_elements_bottom[ 9] = X; // jaxa
    assign out_elements_bottom[10] = X; // jbxa
    assign out_elements_bottom[11] = X; // kaxa
    assign out_elements_bottom[12] = X; // kbxa
    assign out_elements_bottom[13] = X; // daxb
    assign out_elements_bottom[14] = X; // dbxb
    assign out_elements_bottom[15] = X; // dcxb
    assign out_elements_bottom[16] = X; // iaxb
    assign out_elements_bottom[17] = X; // ibxb
    assign out_elements_bottom[18] = X; // jcxb
    assign out_elements_bottom[19] = X; // dbxc
    assign out_elements_bottom[20] = X; // dcxc
    assign out_elements_bottom[21] = X; // eaxc
    assign out_elements_bottom[22] = X; // ebxc
    assign out_elements_bottom[23] = X; // iaxc
    assign out_elements_bottom[24] = X; // icxc
    assign out_elements_bottom[25] = X; // jbxc
    assign out_elements_bottom[26] = X; // kaxc
    assign out_elements_bottom[27] = X; // kcxc
    assign out_elements_bottom[28] = D; // dedg
    assign out_elements_bottom[29] = J; // dejf
    assign out_elements_bottom[30] = E; // dfei
    assign out_elements_bottom[31] = G; // dfge
    assign out_elements_bottom[32] = J; // dfji
    assign out_elements_bottom[33] = D; // dgdi
    assign out_elements_bottom[34] = E; // dgef
    assign out_elements_bottom[35] = G; // dhgk
    assign out_elements_bottom[36] = J; // dhjj
    assign out_elements_bottom[37] = F; // dife
    assign out_elements_bottom[38] = F; // difh
    assign out_elements_bottom[39] = K; // djkh
    assign out_elements_bottom[40] = G; // dkgj
    assign out_elements_bottom[41] = H; // dkhf
    assign out_elements_bottom[42] = E; // eeeh
    assign out_elements_bottom[43] = K; // eekj
    assign out_elements_bottom[44] = J; // efjj
    assign out_elements_bottom[45] = E; // egej
    assign out_elements_bottom[46] = F; // egfi
    assign out_elements_bottom[47] = F; // ehff
    assign out_elements_bottom[48] = F; // eiff
    assign out_elements_bottom[49] = H; // eihk
    assign out_elements_bottom[50] = H; // ekhg
    assign out_elements_bottom[51] = H; // ffhk
    assign out_elements_bottom[52] = H; // fghg
    assign out_elements_bottom[53] = K; // fgkg
    assign out_elements_bottom[54] = G; // fhgi
    assign out_elements_bottom[55] = J; // fijg
    assign out_elements_bottom[56] = G; // fjgh
    assign out_elements_bottom[57] = I; // ghik
    assign out_elements_bottom[58] = J; // gijk
    assign out_elements_bottom[59] = J; // gjjh
    assign out_elements_bottom[60] = K; // gjkk
    assign out_elements_bottom[61] = I; // gkih
    assign out_elements_bottom[62] = I; // gkii
    assign out_elements_bottom[63] = I; // hhik

    assign out_elements_left[ 0] = X; // abxx
    assign out_elements_left[ 1] = X; // baxx
    assign out_elements_left[ 2] = X; // bbxx
    assign out_elements_left[ 3] = X; // bcxx
    assign out_elements_left[ 4] = A; // daxa
    assign out_elements_left[ 5] = A; // ecxa
    assign out_elements_left[ 6] = A; // fcxa
    assign out_elements_left[ 7] = A; // haxa
    assign out_elements_left[ 8] = A; // hcxa
    assign out_elements_left[ 9] = A; // jaxa
    assign out_elements_left[10] = A; // jbxa
    assign out_elements_left[11] = A; // kaxa
    assign out_elements_left[12] = A; // kbxa
    assign out_elements_left[13] = B; // daxb
    assign out_elements_left[14] = B; // dbxb
    assign out_elements_left[15] = B; // dcxb
    assign out_elements_left[16] = B; // iaxb
    assign out_elements_left[17] = B; // ibxb
    assign out_elements_left[18] = B; // jcxb
    assign out_elements_left[19] = C; // dbxc
    assign out_elements_left[20] = C; // dcxc
    assign out_elements_left[21] = C; // eaxc
    assign out_elements_left[22] = C; // ebxc
    assign out_elements_left[23] = C; // iaxc
    assign out_elements_left[24] = C; // icxc
    assign out_elements_left[25] = C; // jbxc
    assign out_elements_left[26] = C; // kaxc
    assign out_elements_left[27] = C; // kcxc
    assign out_elements_left[28] = G; // dedg
    assign out_elements_left[29] = F; // dejf
    assign out_elements_left[30] = I; // dfei
    assign out_elements_left[31] = E; // dfge
    assign out_elements_left[32] = I; // dfji
    assign out_elements_left[33] = I; // dgdi
    assign out_elements_left[34] = F; // dgef
    assign out_elements_left[35] = K; // dhgk
    assign out_elements_left[36] = J; // dhjj
    assign out_elements_left[37] = E; // dife
    assign out_elements_left[38] = H; // difh
    assign out_elements_left[39] = H; // djkh
    assign out_elements_left[40] = J; // dkgj
    assign out_elements_left[41] = F; // dkhf
    assign out_elements_left[42] = H; // eeeh
    assign out_elements_left[43] = J; // eekj
    assign out_elements_left[44] = J; // efjj
    assign out_elements_left[45] = J; // egej
    assign out_elements_left[46] = I; // egfi
    assign out_elements_left[47] = F; // ehff
    assign out_elements_left[48] = F; // eiff
    assign out_elements_left[49] = K; // eihk
    assign out_elements_left[50] = G; // ekhg
    assign out_elements_left[51] = K; // ffhk
    assign out_elements_left[52] = G; // fghg
    assign out_elements_left[53] = G; // fgkg
    assign out_elements_left[54] = I; // fhgi
    assign out_elements_left[55] = G; // fijg
    assign out_elements_left[56] = H; // fjgh
    assign out_elements_left[57] = K; // ghik
    assign out_elements_left[58] = K; // gijk
    assign out_elements_left[59] = H; // gjjh
    assign out_elements_left[60] = K; // gjkk
    assign out_elements_left[61] = H; // gkih
    assign out_elements_left[62] = I; // gkii
    assign out_elements_left[63] = K; // hhik

endmodule
