// ─────────────────────────────────────────────────────────────
// Assignment
//
// Locks a variable's domain to a single piece at a single
// rotation. All other rotations for that variable are cleared.
//
// This is the only responsibility of this module — setting
// one bit in one rotation array. Colour updates and neighbour
// propagation are handled by the downstream pipeline:
//
//   Assignment
//       ↓
//   DomainToColourAll  — derive colours from updated domain
//       ↓
//   CascadeColours     — propagate colours to neighbours
//       ↓
//   ColourToDomainAll  — filter domains by updated colours
//       ↓
//   AllDifferent       — remove taken tiles
//       ↓
//   SingletonDetection — lock any newly forced variables
//
// Parameters
//   N         — board side length (board is N x N)
//   VARIABLES — N * N
//   ID_BITS   — $clog2(VARIABLES)
//
// Inputs
//   variableId — which variable is being assigned
//   tileId     — which piece is being placed
//   rotation   — which rotation (0-3)
//   in_r0..r3  — current domain arrays for all variables
//
// Outputs
//   out_r0..r3 — updated domain arrays with assignment locked
// ─────────────────────────────────────────────────────────────
module Assignment #(
    parameter int N = 4,     //! puzzle size
    parameter int V = N * N  //! number of variables in the puzzle
)(
    input  logic [$clog2(V)-1:0]  in_variableId, //! variable to be assigned a value
    input  logic [$clog2(V)-1:0]  in_tileId,     //! value being assigned to variable
    input  logic [1:0]            in_rotation,   //! rotation of the tile assigned to variable

    input  logic [V-1:0][V-1:0]   in_domain_r0,  //! original domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r1,  //! original domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r2,  //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0]   in_domain_r3,  //! original domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic [V-1:0][V-1:0]   out_domain_r0, //! updated domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r1, //! updated domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r2, //! updated domain rotation 2 (190 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0]   out_domain_r3  //! updated domain rotation 3 (270 degrees), one bit per tile, 1=available, 0=unavailable.
);
    //! One-hot tile mask 
    logic [N*N-1:0] tile_mask;
    
    //! Creates a one-hot bitmask with only the chosen tile's bit set.
    //! All other tile bits are zero — used to lock a variable's domain
    //! to exactly one tile during assignment.
    always_comb begin : create_one_hot_tile_mask
        tile_mask          = '0;
        tile_mask[in_tileId] = 1'b1;
    end

    // ── Lock domain ────────────────────────────────────────────
    //! Pass all variables through unchanged except the assigned
    //! variable which gets its domain locked to one bit in one
    //! rotation and zeroed in all other rotations.
    always_comb begin : lock_variable_to_tile_and_rotation
        out_domain_r0 = in_domain_r0;
        out_domain_r1 = in_domain_r1;
        out_domain_r2 = in_domain_r2;
        out_domain_r3 = in_domain_r3;

        // Set the value only if its the correct rotation otherwise that would be 0
        out_domain_r0[in_variableId] = (in_rotation == 2'd0) ? tile_mask : '0;
        out_domain_r1[in_variableId] = (in_rotation == 2'd1) ? tile_mask : '0;
        out_domain_r2[in_variableId] = (in_rotation == 2'd2) ? tile_mask : '0;
        out_domain_r3[in_variableId] = (in_rotation == 2'd3) ? tile_mask : '0;
    end

endmodule
