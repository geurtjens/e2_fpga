// ─────────────────────────────────────────────────────────────
// CascadeEdgePair
//
// Cascades two shared edges simultaneously — typically the
// horizontal (right/left) and vertical (down/up) edges meeting
// at a cell boundary.
//
// Each edge is ANDed independently via CascadeSingleColour.
// deadend and updated are the OR of both sub-results.
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
module CascadeColourPair #(
    parameter int TC = 6
)(
    input  logic [TC-1:0] right,
    input  logic [TC-1:0] left,
    input  logic [TC-1:0] down,
    input  logic [TC-1:0] up,
    output logic [TC-1:0] out_h,
    output logic [TC-1:0] out_v,
    output logic          deadend,
    output logic          updated
);

    logic h_deadend, h_updated;
    logic v_deadend, v_updated;

    CascadeColourSingle #(.TC(TC)) h_cascade (
        .colour          (right),
        .neighbourColour (left),
        .out             (out_h),
        .deadend         (h_deadend),
        .updated         (h_updated)
    );

    CascadeColourSingle #(.TC(TC)) v_cascade (
        .colour          (down),
        .neighbourColour (up),
        .out             (out_v),
        .deadend         (v_deadend),
        .updated         (v_updated)
    );

    assign deadend = h_deadend | v_deadend;
    assign updated = h_updated | v_updated;

endmodule
