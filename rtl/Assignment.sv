// ─────────────────────────────────────────────────────────────
// Assignment
//
//! Assigns a specific piece at a specific rotation to a variable.
//! Updates the assigned variable's domain and colours, then
//! propagates colour constraints to all four neighbours.
//! Also updates the unassigned variables and tiles masks.
//!
//! Part 1 — Lock the assigned variable's domain:
//!   Only one bit in one rotation survives — the chosen tileId
//!   in the chosen rotation. All other rotations become zero.
//!
//! Part 2 — Set the assigned variable's colours:
//!   Looks up the piece's actual colours from element data and
//!   sets top/right/bottom/left to exactly those colours.
//!
//! Part 3 — Update neighbouring colours:
//!   Each neighbour's shared edge is ANDed with the assigned
//!   piece's colour on that edge. If any result is zero that
//!   neighbour has no valid colour on that edge — deadend.
//!
//! Part 4 — Update availability masks:
//!   Clears the assigned variable and tile from their respective
//!   unassigned masks — they are now placed and no longer available.
//!
//! Parameters
//!   N       — board side length (board is N x N)
//!   CC      — total colour bits per edge
//!   V       — N * N
//!   ID_BITS — $clog2(V)
// ─────────────────────────────────────────────────────────────
module Assignment #(
    parameter int N       = 4,          //! int. size of puzzle grid.
    parameter int CC      = 6,          //! int. total colour bits per edge.
    parameter int V       = N * N,      //! int. number of variables (N*N).
    parameter int ID_BITS = $clog2(V)   //! int. bits needed to index a variable.
)(
    // ── Assignment inputs ──────────────────────────────────────
    input  logic [ID_BITS-1:0] in_variableId, //! position in the grid being assigned.
    input  logic [ID_BITS-1:0] in_tileId,     //! tile being placed.
    input  logic [1:0]         in_rotation,   //! rotation of tile (0=0°, 1=90°, 2=180°, 3=270°).

    // ── Availability mask inputs ───────────────────────────────
    input  logic [V-1:0] in_unassigned_variables, //! current unassigned variables — 1=unassigned, 0=placed.
    input  logic [V-1:0] in_unassigned_tiles,     //! current unassigned tiles — 1=available, 0=placed.

    // ── Colour inputs ─────────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_colour_top,    //! current top colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colour_right,  //! current right colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colour_bottom, //! current bottom colour mask for each variable.
    input  logic [V-1:0][CC-1:0] in_colour_left,   //! current left colour mask for each variable.

    // ── Domain inputs ─────────────────────────────────────────
    input  logic [V-1:0][V-1:0] in_domain_r0, //! current rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1, //! current rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2, //! current rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3, //! current rotation 3 domain bitmask for each variable.

    // ── Tile element inputs ────────────────────────────────────
    input  logic [V-1:0][CC-1:0] in_elements_top,    //! top colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_right,  //! right colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_bottom, //! bottom colour for each tile in base orientation.
    input  logic [V-1:0][CC-1:0] in_elements_left,   //! left colour for each tile in base orientation.

    // ── Colour outputs ────────────────────────────────────────
    output logic [V-1:0][CC-1:0] out_colour_top,    //! updated top colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colour_right,  //! updated right colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colour_bottom, //! updated bottom colour mask for each variable.
    output logic [V-1:0][CC-1:0] out_colour_left,   //! updated left colour mask for each variable.

    // ── Domain outputs ────────────────────────────────────────
    output logic [V-1:0][V-1:0] out_domain_r0, //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1, //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2, //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3, //! updated rotation 3 domain bitmask for each variable.

    // ── Availability mask outputs ─────────────────────────────
    output logic [V-1:0] out_unassigned_variables, //! updated unassigned variables — assigned variable bit cleared.
    output logic [V-1:0] out_unassigned_tiles      //! updated unassigned tiles — assigned tile bit cleared.
);

    // ── Integer versions of inputs for safe arithmetic ────────
    //! Cast to int so that addition, subtraction, modulo and
    //! division all operate on 32-bit signed values with no
    //! width warnings.
    logic [31:0] vid; //! variable ID as 32-bit int for arithmetic.
    logic [31:0] tid; //! tile ID as 32-bit int for arithmetic.
    assign vid = 32'(in_variableId);
    assign tid = 32'(in_tileId);

    // ── Piece colours at chosen rotation ──────────────────────
    //! Derive the four colours of the assigned tile by applying
    //! the rotation rewiring to the base element orientation:
    //!   rotation 0:  top=top,    right=right,  bottom=bottom, left=left
    //!   rotation 1:  top=left,   right=top,    bottom=right,  left=bottom
    //!   rotation 2:  top=bottom, right=left,   bottom=top,    left=right
    //!   rotation 3:  top=right,  right=bottom, bottom=left,   left=top
    logic [CC-1:0] piece_top;    //! top colour of assigned tile at chosen rotation.
    logic [CC-1:0] piece_right;  //! right colour of assigned tile at chosen rotation.
    logic [CC-1:0] piece_bottom; //! bottom colour of assigned tile at chosen rotation.
    logic [CC-1:0] piece_left;   //! left colour of assigned tile at chosen rotation.

    always_comb begin : derive_piece_colours
        case (in_rotation)
            2'd0: begin
                piece_top    = in_elements_top[tid];
                piece_right  = in_elements_right[tid];
                piece_bottom = in_elements_bottom[tid];
                piece_left   = in_elements_left[tid];
            end
            2'd1: begin
                piece_top    = in_elements_left[tid];
                piece_right  = in_elements_top[tid];
                piece_bottom = in_elements_right[tid];
                piece_left   = in_elements_bottom[tid];
            end
            2'd2: begin
                piece_top    = in_elements_bottom[tid];
                piece_right  = in_elements_left[tid];
                piece_bottom = in_elements_top[tid];
                piece_left   = in_elements_right[tid];
            end
            default: begin
                piece_top    = in_elements_right[tid];
                piece_right  = in_elements_bottom[tid];
                piece_bottom = in_elements_left[tid];
                piece_left   = in_elements_top[tid];
            end
        endcase
    end

    // ── Tile domain mask — one hot for the chosen tile ────────
    logic [V-1:0] tile_mask; //! one-hot bitmask with only the chosen tile's bit set.
    always_comb begin : create_tile_mask
        tile_mask      = '0;
        tile_mask[tid] = 1'b1;
    end

    // ── Main combinational logic ──────────────────────────────
    always_comb begin : apply_assignment

        // ── Default: pass everything through unchanged ─────────
        out_colour_top    = in_colour_top;
        out_colour_right  = in_colour_right;
        out_colour_bottom = in_colour_bottom;
        out_colour_left   = in_colour_left;
        out_domain_r0     = in_domain_r0;
        out_domain_r1     = in_domain_r1;
        out_domain_r2     = in_domain_r2;
        out_domain_r3     = in_domain_r3;

        // ── Part 1 — lock the assigned variable's domain ───────
        //! Only the chosen tile at the chosen rotation survives.
        //! All other rotations for this variable are zeroed.
        out_domain_r0[vid] = (in_rotation == 2'd0) ? tile_mask : '0;
        out_domain_r1[vid] = (in_rotation == 2'd1) ? tile_mask : '0;
        out_domain_r2[vid] = (in_rotation == 2'd2) ? tile_mask : '0;
        out_domain_r3[vid] = (in_rotation == 2'd3) ? tile_mask : '0;

        // ── Part 2 — set the assigned variable's own colours ───
        //! Colours are locked to exactly what the piece provides
        //! at the chosen rotation.
        out_colour_top[vid]    = piece_top;
        out_colour_right[vid]  = piece_right;
        out_colour_bottom[vid] = piece_bottom;
        out_colour_left[vid]   = piece_left;

        // ── Part 3 — update neighbouring colours ───────────────
        //! Each neighbour's shared edge is ANDed with the piece's
        //! colour on that edge — constraining what colours remain
        //! valid for that neighbour.

        // right neighbour (col < N-1)
        if ((vid % N) < N-1)
            out_colour_left[vid+1] = in_colour_left[vid+1] & piece_right;

        // below neighbour (row < N-1)
        if ((vid / N) < N-1)
            out_colour_top[vid+N] = in_colour_top[vid+N] & piece_bottom;

        // left neighbour (col > 0)
        if ((vid % N) > 0)
            out_colour_right[vid-1] = in_colour_right[vid-1] & piece_left;

        // above neighbour (row > 0)
        if ((vid / N) > 0)
            out_colour_bottom[vid-N] = in_colour_bottom[vid-N] & piece_top;

    end

    // ── Part 4 — update availability masks ───────────────────
    //! Clear the assigned variable and tile from their respective
    //! unassigned masks — they are now placed and no longer available.
    assign out_unassigned_variables = in_unassigned_variables & ~(V'(1) << vid);
    assign out_unassigned_tiles     = in_unassigned_tiles     & ~(V'(1) << tid);

endmodule
