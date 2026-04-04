// ─────────────────────────────────────────────────────────────
// CascadeColour_Pair
//
//! Cascades two shared edges simultaneously — typically the
//! horizontal (right/left) and vertical (down/up) edges meeting
//! at a cell boundary.
//
//! Each edge is ANDed independently via CascadeSingleColour.
//! deadend and updated are the OR of both sub-results.
//
// Parameters
//   TC — total colour bits (register width)
//
// Outputs
//   out_h   — right & left
//   out_v   — down  & up
//   deadend — 1 if either cascaded edge is all zeros
//   updated — 1 if either cascaded edge changed from its left/right input
// ─────────────────────────────────────────────────────────────
module CascadeColour_Pair #(
    parameter int CC = 6 //! ColourCount - number of bits in each colour
)(
    input  logic [CC-1:0] in_slotRightColour, //! right colour of the current variable slot
    input  logic [CC-1:0] in_neighbourLeftColour, //! left colour of the neighbours slot
    
    input  logic [CC-1:0] in_slotDownColour, //! down colour of the current variable slot
    input  logic [CC-1:0] in_neighbourUpColour, //! up colour of the neighbours slot
    output logic [CC-1:0] out_horizontalColour, //! combined colours of slotRightColour and neighbourLeftColour
    output logic [CC-1:0] out_verticalColour, //! combined colours of slotBottomColour and neighbourTopColour
    output logic          out_deadend, //! if either output colour is zero
    output logic          out_updated //! if either output colour is different from input colours
);

    logic horizontal_deadend; //! HIGH when combining horizontal colours result in a deadend.
    logic vertical_deadend;  //! HIGH when combining vertical colours results in a deadend.
    logic horizontal_updated;  //! HIGH when either left or right colour registers change
    logic vertical_updated; //! HIGH when either top or bottom colour registers change

    //! Combine the horizontal colours by ANDing right and left colours to form combinedHorizontalColour
    CascadeColour_Single #(.CC(CC)) h_cascade (
        .in_slotColour      (in_slotRightColour),
        .in_neighbourColour (in_neighbourLeftColour),
        .out_combinedColour (out_horizontalColour),
        .out_deadend        (horizontal_deadend),
        .out_updated        (horizontal_updated)
    );

    //! Combine the vertical colours by ANDing bottom and top colours to form the combinedVerticalColour
    CascadeColour_Single #(.CC(CC)) v_cascade (
        .in_slotColour      (in_slotDownColour),
        .in_neighbourColour (in_neighbourUpColour),
        .out_combinedColour (out_verticalColour),
        .out_deadend        (vertical_deadend),
        .out_updated        (vertical_updated)
    );

    assign out_deadend = horizontal_deadend | vertical_deadend;
    assign out_updated = horizontal_updated | vertical_updated;

endmodule
