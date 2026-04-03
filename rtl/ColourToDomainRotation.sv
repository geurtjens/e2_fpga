// ─────────────────────────────────────────────────────────────
// ColourToDomainRotation
//
// Filters the domain of a single variable for a single rotation
// by checking every piece against the variable's colour
// constraints on all four edges.
//
// A piece is kept only if its colour on every edge has at least
// one bit in common with the variable's constraint mask for that
// edge (AND is non-zero on all four sides).
//
// Fully combinational — all pieces checked simultaneously.
//
// Parameters
//   VARIABLES — total number of pieces (and domain width)
//   TC        — total colour bits per edge
//
// Inputs
//   domain      — current domain bitmask for this variable and
//                 rotation, one bit per piece
//   top..left   — colour constraint masks for this variable
//   p_top..left — piece colour patterns for this rotation,
//                 indexed by piece
//
// Outputs
//   domain_out  — filtered domain bitmask
//   changed     — 1 if any bit was cleared
//   deadend     — 1 if domain was non-empty but is now empty
// ─────────────────────────────────────────────────────────────
module ColourToDomainRotation #(
    parameter int VARIABLES = 16,
    parameter int TC        = 6
)(
    input  logic [VARIABLES-1:0] domain,

    input  logic [TC-1:0] top,
    input  logic [TC-1:0] right,
    input  logic [TC-1:0] bottom,
    input  logic [TC-1:0] left,

    input  logic [VARIABLES-1:0][TC-1:0] p_top,
    input  logic [VARIABLES-1:0][TC-1:0] p_right,
    input  logic [VARIABLES-1:0][TC-1:0] p_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p_left,

    output logic [VARIABLES-1:0] domain_out,
    output logic                 changed,
    output logic                 deadend
);
    always_comb begin
        // ── Step 1 — clear all output bits ────────────────────
        // Each bit set selectively below if piece passes check
        domain_out = '0;

        // ── Step 2 — test each piece against constraints ───────
        // Piece p survives if it was in the domain AND its colour
        // on every edge overlaps with the constraint mask
        for (int p = 0; p < VARIABLES; p++) begin
            if (domain[p] &&
                (top    & p_top[p])    != '0 &&
                (right  & p_right[p])  != '0 &&
                (bottom & p_bottom[p]) != '0 &&
                (left   & p_left[p])   != '0)
                domain_out[p] = 1'b1;
        end

        // ── Step 3 — changed detection ─────────────────────────
        // True if any bit was cleared — domain only ever shrinks
        changed = (domain_out != domain);

        // ── Step 4 — deadend detection ─────────────────────────
        // True if domain was non-empty but is now completely empty
        deadend = (domain != '0) && (domain_out == '0);
    end

endmodule
