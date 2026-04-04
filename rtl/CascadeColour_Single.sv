// ─────────────────────────────────────────────────────────────
// CascadeColour_Single
//
//! ANDs two colour registers together (in_slotColour & in_neibourColour) and writes the result to
//! an output register (out_combinedColour).
//! Detects if a change has occurred (out_updated) and also if the result is no colour at all (_out_deadend)
//
// Parameters
//   CC — total colour bits (register width)
//
// Outputs
//   out_combinedColour     — colour & neighbourColour
//   out_deadend — 1 if out is all zeros
//   out_updated — 1 if out differs from colour
// ─────────────────────────────────────────────────────────────
module CascadeColour_Single #(
    parameter int CC = 6 //! colourCount - total colour bits (register width)
)(
    input  logic [CC-1:0] in_slotColour, //! colour of the current variable slot
    input  logic [CC-1:0] in_neighbourColour, //! colour of the neighbours slot
    output logic [CC-1:0] out_combinedColour, //! colour & neighbourColour. Include those which are in both only
    output logic          out_deadend, //! it is impossible for any side to not have a colour
    output logic          out_updated //! has the colour or neighbour colour changed
);

//! The out_combinedColour will become in_slotColour AND in_neighbourColour
//! If the out_combinedColour is empty then that is impossible and so its a deadend
//! Detect if any of the colours have changed
    always_comb begin: colour_cascade_deadend_update_detection
        out_combinedColour     = in_slotColour & in_neighbourColour;
        out_deadend = (out_combinedColour == '0);
        out_updated = (in_slotColour != out_combinedColour || in_neighbourColour != out_combinedColour);
    end

endmodule
