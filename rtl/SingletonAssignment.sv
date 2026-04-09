// ─────────────────────────────────────────────────────────────
// SingletonAssignment
//
//! Scans all active (unassigned) variables and detects any that
//! have exactly one piece remaining across all four rotation
//! arrays combined.  Those variables are forced assignments —
//! only one piece and rotation is possible so they are locked in.
//!
//! For each detected singleton:
//!   - The variable is removed from unassignedVariables
//!   - The tile is removed from unassignedTiles
//!   - The domain is locked to one tile at one rotation
//!
//! Singleton assignment applies the one-hot bit trick to each
//! rotation independently:
//!   x & (x-1) clears the lowest set bit. If the result is
//!   zero and x is non-zero, exactly one bit is set (one-hot).
//!
//! A singleton requires two conditions:
//!   1. Exactly one rotation domain is non-empty (active_count==1)
//!   2. That rotation domain is one-hot (single tile remaining)
//!
//! This correctly handles inner pieces where the same tile can
//! appear in multiple rotation domains simultaneously — using
//! OR across rotations would collapse those into one bit and
//! give a false singleton reading.
//!
//! Note: out_deadend has been removed from this module.
//!   Deadend detection is now handled centrally by
//!   DeadendOrSolutionCheck at the end of the pipeline.
//!
//! Colours are NOT updated here — rely on DomainToColour to
//! derive fresh colours from the updated domains afterwards.
//!
//! Parameters
//!   N       — board side length (board is N x N)
//!   V       — N * N
//!   ID_BITS — $clog2(V)
// ─────────────────────────────────────────────────────────────
module SingletonAssignment #(
    parameter int N       = 4,
    parameter int V       = N * N,
    parameter int ID_BITS = $clog2(V)
)(
    input  logic [V-1:0]        in_unassignedVariables,  //! 1=unassigned, 0=already placed.
    input  logic [V-1:0]        in_unassignedTiles,      //! 1=tile not yet placed, 0=already used.
    input  logic [V-1:0][V-1:0] in_domain_r0,            //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! rotation 3 domain bitmask for each variable.

    output logic [V-1:0]        out_unassignedVariables, //! updated mask with detected singletons removed.
    output logic [V-1:0]        out_unassignedTiles,     //! updated tile availability with singleton tiles removed.
    output logic [V-1:0][V-1:0] out_domain_r0,           //! updated rotation 0 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r1,           //! updated rotation 1 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r2,           //! updated rotation 2 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r3            //! updated rotation 3 domain bitmask.
);

    always_comb begin : detect_singletons

        // ── Default — pass everything through unchanged ────────
        out_unassignedVariables = in_unassignedVariables;
        out_unassignedTiles     = in_unassignedTiles;
        out_domain_r0           = in_domain_r0;
        out_domain_r1           = in_domain_r1;
        out_domain_r2           = in_domain_r2;
        out_domain_r3           = in_domain_r3;

        // ── Scan all active variables ──────────────────────────
        for (int v = 0; v < V; v++) begin
            if (in_unassignedVariables[v]) begin

                automatic logic           r0_any,    r1_any,    r2_any,    r3_any;
                automatic logic           r0_onehot, r1_onehot, r2_onehot, r3_onehot;
                automatic int             active_count;
                automatic logic [V-1:0]   combined;
                automatic logic [ID_BITS-1:0] tile_id;
                automatic logic [1:0]     rot;

                // ── One-hot bit trick per rotation ────────────
                //! For each rotation check whether it is
                //! non-empty (any) and one-hot (single bit set).
                //! x & (x-1) clears the lowest set bit — if the
                //! result is zero and x is non-zero, exactly one
                //! bit is set.
                r0_any    = (in_domain_r0[v] != '0);
                r1_any    = (in_domain_r1[v] != '0);
                r2_any    = (in_domain_r2[v] != '0);
                r3_any    = (in_domain_r3[v] != '0);

                r0_onehot = r0_any && ((in_domain_r0[v] & (in_domain_r0[v] - 1)) == '0);
                r1_onehot = r1_any && ((in_domain_r1[v] & (in_domain_r1[v] - 1)) == '0);
                r2_onehot = r2_any && ((in_domain_r2[v] & (in_domain_r2[v] - 1)) == '0);
                r3_onehot = r3_any && ((in_domain_r3[v] & (in_domain_r3[v] - 1)) == '0);

                // ── Count active rotations ────────────────────
                //! Count how many rotation domains are non-empty.
                //! A singleton requires exactly one rotation to
                //! be active — if two or more rotations have
                //! bits set then more than one tile/rotation
                //! combination remains and it is not a singleton.
                //automatic logic [2:0] active_count;
                //active_count = {2'b0, r0_any} + {2'b0, r1_any} + {2'b0, r2_any} + {2'b0, r3_any};

                active_count = int'(r0_any) + int'(r1_any) + int'(r2_any) + int'(r3_any);

                // ── Singleton condition ───────────────────────
                //! Exactly one rotation is active AND that
                //! rotation has exactly one bit set.
                if (active_count == 1 &&
                    (r0_onehot | r1_onehot | r2_onehot | r3_onehot)) begin

                    // ── Find the singleton tile bit ────────────
                    //! OR all rotations — since only one rotation
                    //! is active this just extracts that one bit.
                    combined = in_domain_r0[v] | in_domain_r1[v] |
                               in_domain_r2[v] | in_domain_r3[v];

                    // ── Extract tile ID ────────────────────────
                    //! Priority encode to find the position of
                    //! the single set bit — this is the tile ID.
                    tile_id = '0;
                    for (int p = V-1; p >= 0; p--) begin
                        if (combined[p])
                            tile_id = ID_BITS'(p);
                    end

                    // ── Extract rotation ───────────────────────
                    //! Whichever rotation domain is non-zero
                    //! holds the singleton tile.
                    if      (r0_any) rot = 2'd0;
                    else if (r1_any) rot = 2'd1;
                    else if (r2_any) rot = 2'd2;
                    else             rot = 2'd3;

                    // ── Lock domain to singleton ───────────────
                    out_domain_r0[v] = (rot == 2'd0) ? combined : '0;
                    out_domain_r1[v] = (rot == 2'd1) ? combined : '0;
                    out_domain_r2[v] = (rot == 2'd2) ? combined : '0;
                    out_domain_r3[v] = (rot == 2'd3) ? combined : '0;

                    // ── Remove from availability masks ─────────
                    out_unassignedVariables[v]   = 1'b0;
                    out_unassignedTiles[tile_id] = 1'b0;
                end
            end
        end
    end

endmodule
