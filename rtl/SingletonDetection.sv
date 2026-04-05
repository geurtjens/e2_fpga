// ─────────────────────────────────────────────────────────────
// SingletonDetection
//
//! Scans all active (unassigned) variables and detects any that
//! have exactly one piece remaining across all four rotation
//! arrays combined.  Those variables are forced assignments —
//! only one piece and rotation is possible so they are locked in.
//!
//! For each detected singleton:
//!   - The variable is removed from unassignedVariables
//!   - The tile is removed from unassignedTiles
//!   - The domain is locked to one tile at rotation
//
// Singleton detection uses the one-hot bit trick:
//   x & (x-1) clears the lowest set bit. If the result is zero
//   and x is non-zero, exactly one bit is set (one-hot).
//   This is faster than popcount on FPGA as it avoids the
//   adder tree and only requires a subtract and AND gate.
//!
//! out_deadend condition:
//!   If after processing, popcount(unassignedVariables) does
//!   not equal popcount(unassignedTiles), two variables were
//!   forced to the same tile which is impossible and so out_deadend is set.
//
// Colours are NOT updated here — rely on DomainToColour to
// derive fresh colours from the updated domains afterwards.
//
// Parameters
//   N         — board side length (board is N x N)
//   VARIABLES — N * N
//   ID_BITS   — $clog2(VARIABLES)
//
// Inputs
//   in_unassignedVariables — 1=unassigned, 0=already singleton
//   in_unassignedTiles       — 1=tile not yet placed
//   in_domain_r0..r3               — current domain bitmasks
//
// Outputs
//   out_unassignedVariables — updated mask with new singletons removed
//   out_unassignedTiles       — updated tile availability
//   out_domain_r0..r3               — domains with singletons locked
//   out_singleton           — 1 if at least one singleton was detected
//   out_deadend                   — 1 if variable/tile counts diverged
// ─────────────────────────────────────────────────────────────
module SingletonDetection #(
    parameter int N       = 4,                           //! size of puzzle 3,4,5,6,7,8
    parameter int V       = N * N,                       //! number of positions in the grid.
    parameter int ID_BITS = $clog2(V)                    //! number of bits needed to represent a variable ID e.g. 4 for 16 V
)(
    input  logic [V-1:0]        in_unassignedVariables,  //! original bitmask — one bit per variable, 1=unassigned, 0=already placed (singleton)
    input  logic [V-1:0]        in_unassignedTiles,      //! original V-wide bitmask — one bit per tile, 1=tile not yet placed, 0=tile already use

    input  logic [V-1:0][V-1:0] in_domain_r0,            //! original domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! original domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! original domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic [V-1:0]        out_unassignedVariables, //! updated bitmask — one bit per variable, 1=unassigned, 0=already placed (singleton)
    output logic [V-1:0]        out_unassignedTiles,     //! updated V-wide bitmask — one bit per tile, 1=tile not yet placed, 0=tile already use

    output logic [V-1:0][V-1:0] out_domain_r0,           //! updated domain rotation 0 (0 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r1,           //! updated domain rotation 1 (90 degrees), one bit per tile, 1=available, 0=unavailable.
    output logic [V-1:0][V-1:0] out_domain_r2,           //! updated domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable. 
    output logic [V-1:0][V-1:0] out_domain_r3,           //! updated domain rotation 2 (180 degrees), one bit per tile, 1=available, 0=unavailable.

    output logic                out_singleton,           //! whether or not a singleton was detected, 1 = singleton was detected
    output logic                out_deadend              //! whether or not a deadend was detected, 1 = deadend was detected
);

    
    //! Counts the number of set bits in a VARIABLES-wide vector.
    //! Used only for the final deadend check — compares unassigned
    //! variable count against unassigned tile count.
    //! Quartus synthesises this as an adder tree of LUTs.
    //! Not used for singleton detection — the faster one-hot
    //! bit trick (x & (x-1)) is used there instead.
    function automatic int popcount;
        input logic [V-1:0] vec;
        int count;
        begin
            count = 0;
            for (int i = 0; i < V; i++)
                count = count + vec[i];
            popcount = count;
        end
    endfunction

    //! Scans all unassigned variables looking for singletons which are variables where only one tile remains across all rotations.
    //! For each singleton found:
    //!   - Locks the domain to that one tile and rotation
    //!   - Removes the variable from unassignedVariables
    //!   - Removes the tile from unassignedTiles
    //! After processing all variables, checks for deadend:
    //!   - If popcount(unassignedVariables) != popcount(unassignedTiles) then two variables were forced to the same tile which is impossible and so a deadend.
    always_comb begin : detect_singletons_and_deadend
        // ── Default — pass everything through unchanged ────────
        out_unassignedVariables = in_unassignedVariables;
        out_unassignedTiles       = in_unassignedTiles;
        out_domain_r0 = in_domain_r0;
        out_domain_r1 = in_domain_r1;
        out_domain_r2 = in_domain_r2;
        out_domain_r3 = in_domain_r3;

        out_singleton = 1'b0;

        // ── Scan all active variables ──────────────────────────
        for (int v = 0; v < V; v++) begin

            if (in_unassignedVariables[v]) begin

                automatic logic [V-1:0] combined;
                automatic logic [ID_BITS-1:0]   tile_id;
                automatic logic [1:0]           rot;

                // OR all rotations — bits are non-overlapping
                // since each piece can only be in one rotation
                combined = in_domain_r0[v] | in_domain_r1[v] | in_domain_r2[v] | in_domain_r3[v];

                // ── One-hot detection ──────────────────────────
                // x & (x-1) clears the lowest set bit.
                // If result is zero and x is non-zero, exactly
                // one bit is set — this variable is a singleton.
                // Faster than popcount on FPGA: subtract + AND
                // instead of an adder tree.
                if (combined != '0 &&
                    (combined & (combined - 1)) == '0) begin

                    out_singleton = 1'b1;

                    // Extract tileId — position of the single set bit
                    // Priority encode: find lowest set bit
                    tile_id = '0;
                    for (int p = V-1; p >= 0; p--) begin
                        if (combined[p])
                            tile_id = ID_BITS'(p);
                    end

                    // Extract rotation — which array has the bit set
                    if      (in_domain_r0[v] != '0) rot = 2'd0;
                    else if (in_domain_r1[v] != '0) rot = 2'd1;
                    else if (in_domain_r2[v] != '0) rot = 2'd2;
                    else                     rot = 2'd3;

                    // Lock domain to this one piece at this rotation
                    out_domain_r0[v] = (rot == 2'd0) ? combined : '0;
                    out_domain_r1[v] = (rot == 2'd1) ? combined : '0;
                    out_domain_r2[v] = (rot == 2'd2) ? combined : '0;
                    out_domain_r3[v] = (rot == 2'd3) ? combined : '0;

                    // Remove variable from unassigned mask
                    out_unassignedVariables[v] = 1'b0;

                    // Remove tile from available tiles
                    out_unassignedTiles[tile_id] = 1'b0;
                end
            end
        end

        // ── out_deadend check ──────────────────────────────────────
        // If unassigned variable count != unassigned tile count
        // then two variables were forced to the same tile
        out_deadend = (popcount(out_unassignedVariables) !=
                   popcount(out_unassignedTiles));
    end

endmodule
