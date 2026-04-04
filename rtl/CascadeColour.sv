// ─────────────────────────────────────────────────────────────
// CascadeColour
//
//! Propagates colour constraints between adjacent variables by
//! ANDing shared edges together.
//!
//! Horizontal: right[id] & left[id+1]  — for x < N-1
//! Vertical:   bottom[id] & top[id+N]  — for y < N-1
//!
//! The AND result is written to both sides of the shared edge.
//! Variables not involved in a cascade pass through unchanged.
//!
//! out_deadend — 1 if any cascaded internal edge becomes zero
//! out_updated — 1 if any colour value changed
//
// Parameters
//   N  — board side length (board is N x N)
//   CC — total colour bits per edge
//   V  — number of variables (derived from N — do not override)
// ─────────────────────────────────────────────────────────────
module CascadeColour #(
    parameter int N  = 4,     //! Puzzle size
    parameter int CC = 6,     //! Colour count per edge
    parameter int V  = N * N  //! Number of variables — derived from N, do not override
)(
    input  logic [V-1:0][CC-1:0] in_colours_top,    //! top colour for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_right,  //! right colour for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_bottom, //! bottom colour for each grid position
    input  logic [V-1:0][CC-1:0] in_colours_left,   //! left colour for each grid position

    output logic [V-1:0][CC-1:0] out_colours_top,    //! updated top colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_right,  //! updated right colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_bottom, //! updated bottom colour for each grid position
    output logic [V-1:0][CC-1:0] out_colours_left,   //! updated left colour for each grid position

    output logic out_deadend, //! HIGH if any cascaded edge becomes empty — no valid colour remains
    output logic out_updated  //! HIGH if any colour changed during cascade
);
    localparam int PAIRS = (N-1) * (N-1); //! number of internal shared edges

    //! per-pair deadend and updated signals
    logic [PAIRS-1:0] pair_deadend;
    logic [PAIRS-1:0] pair_updated;

    //! intermediate pair results — horizontal and vertical ANDs
    logic [PAIRS-1:0][CC-1:0] pair_horizontal;
    logic [PAIRS-1:0][CC-1:0] pair_vertical;

    // ── Step 1 — instantiate CascadeColour_Pair for each pair ─
    genvar x, y;
    generate
        for (y = 0; y < N-1; y++) begin : gen_y
            for (x = 0; x < N-1; x++) begin : gen_x
                localparam int id = y*N + x;
                localparam int p  = y*(N-1) + x;

                CascadeColour_Pair #(.CC(CC)) pair (
                    .in_slotRightColour     (in_colours_right[id]),
                    .in_neighbourLeftColour (in_colours_left[id+1]),
                    .in_slotDownColour      (in_colours_bottom[id]),
                    .in_neighbourUpColour   (in_colours_top[id+N]),
                    .out_horizontalColour   (pair_horizontal[p]),
                    .out_verticalColour     (pair_vertical[p]),
                    .out_deadend            (pair_deadend[p]),
                    .out_updated            (pair_updated[p])
                );
            end
        end
    endgenerate

    // ── Step 2 — write pair results back to full colour arrays ─
    //! Default all outputs to inputs then overwrite cascaded positions.
    //! Variables not involved in a cascade pass through unchanged.
    always_comb begin : write_cascade_results_to_colour_arrays
        out_colours_top    = in_colours_top;
        out_colours_right  = in_colours_right;
        out_colours_bottom = in_colours_bottom;
        out_colours_left   = in_colours_left;
    
        for (int py = 0; py < N-1; py++) begin
            for (int px = 0; px < N-1; px++) begin
                // no automatic keyword — use expressions directly
                out_colours_right[py*N + px]   = pair_horizontal[py*(N-1) + px];
                out_colours_left[py*N + px+1]  = pair_horizontal[py*(N-1) + px];
                out_colours_bottom[py*N + px]  = pair_vertical[py*(N-1) + px];
                out_colours_top[py*N + px+N]   = pair_vertical[py*(N-1) + px];
            end
        end
    end

    // ── Step 3 — OR all pair deadend and updated signals ──────
    assign out_deadend = |pair_deadend;
    assign out_updated = |pair_updated;

endmodule
