// ─────────────────────────────────────────────────────────────
// DomainToColourRotation
//
// Derives the colour mask for a single variable and single
// rotation by ORing the edge colours of every piece still
// present in the domain.
//
// A colour bit is set in the output if at least one piece
// remaining in the domain has that colour on that edge.
//
// Fully combinational — all pieces checked simultaneously.
//
// Parameters
//   VARIABLES — total number of pieces (and domain width)
//   TC        — total colour bits per edge
//
// Inputs
//   domain      — current domain bitmask for this variable
//                 and rotation, one bit per piece
//   p_top..left — piece colour patterns for this rotation,
//                 indexed by piece
//
// Outputs
//   top..left   — derived colour masks for this variable
// ─────────────────────────────────────────────────────────────
module DomainToColourRotation #(
    parameter int VARIABLES = 16,
    parameter int TC        = 6
)(
    input  logic [VARIABLES-1:0] domain,

    input  logic [VARIABLES-1:0][TC-1:0] p_top,
    input  logic [VARIABLES-1:0][TC-1:0] p_right,
    input  logic [VARIABLES-1:0][TC-1:0] p_bottom,
    input  logic [VARIABLES-1:0][TC-1:0] p_left,

    output logic [TC-1:0] top,
    output logic [TC-1:0] right,
    output logic [TC-1:0] bottom,
    output logic [TC-1:0] left
);
    always_comb begin
        // ── Start with no colours ──────────────────────────────
        top    = '0;
        right  = '0;
        bottom = '0;
        left   = '0;

        // ── OR in each surviving piece's colours ───────────────
        // If piece p is still in the domain, its colour on each
        // edge is still a possibility for this variable
        for (int p = 0; p < VARIABLES; p++) begin
            if (domain[p]) begin
                top    |= p_top[p];
                right  |= p_right[p];
                bottom |= p_bottom[p];
                left   |= p_left[p];
            end
        end
    end

endmodule
