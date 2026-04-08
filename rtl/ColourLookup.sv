// ─────────────────────────────────────────────────────────────
// Assignment_Colours
//
//! Looks up the four edge colours for a tile at a given rotation.
//! Pure combinational lookup — no neighbour propagation.
//! Used by Assignment and SingletonDetection to set a variable's
//! own colours after it has been locked to a single tile.
// ─────────────────────────────────────────────────────────────
module ColourLookup #(
    parameter int V  = 16, //! number of variables
    parameter int CC = 6   //! colour bits per edge
)(
    input  logic [$clog2(V)-1:0]  in_tileId,          //! tile being looked up
    input  logic [1:0]            in_rotation,         //! rotation (0=0°, 1=90°, 2=180°, 3=270°)

    input  logic [V-1:0][CC-1:0]  in_elements_top,    //! top colour for each tile in base orientation
    input  logic [V-1:0][CC-1:0]  in_elements_right,  //! right colour for each tile in base orientation
    input  logic [V-1:0][CC-1:0]  in_elements_bottom, //! bottom colour for each tile in base orientation
    input  logic [V-1:0][CC-1:0]  in_elements_left,   //! left colour for each tile in base orientation

    output logic [CC-1:0]         out_top,             //! top colour of tile at given rotation
    output logic [CC-1:0]         out_right,           //! right colour of tile at given rotation
    output logic [CC-1:0]         out_bottom,          //! bottom colour of tile at given rotation
    output logic [CC-1:0]         out_left             //! left colour of tile at given rotation
);

    always_comb begin : lookup_colours
        case (in_rotation)
            2'd0: begin
                out_top    = in_elements_top[in_tileId];
                out_right  = in_elements_right[in_tileId];
                out_bottom = in_elements_bottom[in_tileId];
                out_left   = in_elements_left[in_tileId];
            end
            2'd1: begin
                out_top    = in_elements_left[in_tileId];
                out_right  = in_elements_top[in_tileId];
                out_bottom = in_elements_right[in_tileId];
                out_left   = in_elements_bottom[in_tileId];
            end
            2'd2: begin
                out_top    = in_elements_bottom[in_tileId];
                out_right  = in_elements_left[in_tileId];
                out_bottom = in_elements_top[in_tileId];
                out_left   = in_elements_right[in_tileId];
            end
            default: begin
                out_top    = in_elements_right[in_tileId];
                out_right  = in_elements_bottom[in_tileId];
                out_bottom = in_elements_left[in_tileId];
                out_left   = in_elements_top[in_tileId];
            end
        endcase
    end

endmodule
