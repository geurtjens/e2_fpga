// ─────────────────────────────────────────────────────────────
// CascadeSingleColour
//
// ANDs two colour registers together and writes the result to
// a single output register.
//
// Parameters
//   TC — total colour bits (register width)
//
// Outputs
//   out     — colour & neighbourColour
//   deadend — 1 if out is all zeros
//   updated — 1 if out differs from colour
// ─────────────────────────────────────────────────────────────
module CascadeColourSingle #(
    parameter int TC = 6
)(
    input  logic [TC-1:0] colour,
    input  logic [TC-1:0] neighbourColour,
    output logic [TC-1:0] out,
    output logic          deadend,
    output logic          updated
);

    always_comb begin
        out     = colour & neighbourColour;
        deadend = (out == '0);
        updated = (out != colour);
    end

endmodule
