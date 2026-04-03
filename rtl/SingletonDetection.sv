// ─────────────────────────────────────────────────────────────
// SingletonDetection
//
// Scans all active (unassigned) variables and detects any that
// have exactly one piece remaining across all four rotation
// arrays combined.  Those variables are forced assignments —
// only one piece and rotation is possible so they are locked in.
//
// For each detected singleton:
//   - The variable is removed from variablesIncludedMask
//   - The tile is removed from unassignedTiles
//   - The domain is locked to that one piece at that rotation
//
// Singleton detection uses the one-hot bit trick:
//   x & (x-1) clears the lowest set bit. If the result is zero
//   and x is non-zero, exactly one bit is set (one-hot).
//   This is faster than popcount on FPGA as it avoids the
//   adder tree and only requires a subtract and AND gate.
//
// Deadend condition:
//   If after processing, popcount(variablesIncludedMask) does
//   not equal popcount(unassignedTiles), two variables were
//   forced to the same tile — deadend.
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
//   in_variablesIncludedMask — 1=unassigned, 0=already singleton
//   in_unassignedTiles       — 1=tile not yet placed
//   in_r0..r3               — current domain bitmasks
//
// Outputs
//   out_variablesIncludedMask — updated mask with new singletons removed
//   out_unassignedTiles       — updated tile availability
//   out_r0..r3               — domains with singletons locked
//   singleton_found           — 1 if at least one singleton was detected
//   deadend                   — 1 if variable/tile counts diverged
// ─────────────────────────────────────────────────────────────
module SingletonDetection #(
    parameter int N         = 4,
    parameter int VARIABLES = N * N,
    parameter int ID_BITS   = $clog2(VARIABLES)
)(
    input  logic [VARIABLES-1:0]                in_variablesIncludedMask,
    input  logic [VARIABLES-1:0]                in_unassignedTiles,

    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r3,

    output logic [VARIABLES-1:0]                out_variablesIncludedMask,
    output logic [VARIABLES-1:0]                out_unassignedTiles,

    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r0,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r1,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r2,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r3,

    output logic                                singleton_found,
    output logic                                deadend
);

    // ── Synthesisable popcount ─────────────────────────────────
    // Used only for the final deadend check.
    // Quartus synthesises this as an adder tree of LUTs.
    function automatic int popcount;
        input logic [VARIABLES-1:0] vec;
        int count;
        begin
            count = 0;
            for (int i = 0; i < VARIABLES; i++)
                count = count + vec[i];
            popcount = count;
        end
    endfunction

    always_comb begin
        // ── Default — pass everything through unchanged ────────
        out_variablesIncludedMask = in_variablesIncludedMask;
        out_unassignedTiles       = in_unassignedTiles;
        out_r0 = in_r0;
        out_r1 = in_r1;
        out_r2 = in_r2;
        out_r3 = in_r3;

        singleton_found = 1'b0;

        // ── Scan all active variables ──────────────────────────
        for (int v = 0; v < VARIABLES; v++) begin

            if (in_variablesIncludedMask[v]) begin

                automatic logic [VARIABLES-1:0] combined;
                automatic logic [ID_BITS-1:0]   tile_id;
                automatic logic [1:0]           rot;

                // OR all rotations — bits are non-overlapping
                // since each piece can only be in one rotation
                combined = in_r0[v] | in_r1[v] | in_r2[v] | in_r3[v];

                // ── One-hot detection ──────────────────────────
                // x & (x-1) clears the lowest set bit.
                // If result is zero and x is non-zero, exactly
                // one bit is set — this variable is a singleton.
                // Faster than popcount on FPGA: subtract + AND
                // instead of an adder tree.
                if (combined != '0 &&
                    (combined & (combined - 1)) == '0) begin

                    singleton_found = 1'b1;

                    // Extract tileId — position of the single set bit
                    // Priority encode: find lowest set bit
                    tile_id = '0;
                    for (int p = VARIABLES-1; p >= 0; p--) begin
                        if (combined[p])
                            tile_id = ID_BITS'(p);
                    end

                    // Extract rotation — which array has the bit set
                    if      (in_r0[v] != '0) rot = 2'd0;
                    else if (in_r1[v] != '0) rot = 2'd1;
                    else if (in_r2[v] != '0) rot = 2'd2;
                    else                     rot = 2'd3;

                    // Lock domain to this one piece at this rotation
                    out_r0[v] = (rot == 2'd0) ? combined : '0;
                    out_r1[v] = (rot == 2'd1) ? combined : '0;
                    out_r2[v] = (rot == 2'd2) ? combined : '0;
                    out_r3[v] = (rot == 2'd3) ? combined : '0;

                    // Remove variable from unassigned mask
                    out_variablesIncludedMask[v] = 1'b0;

                    // Remove tile from available tiles
                    out_unassignedTiles[tile_id] = 1'b0;
                end
            end
        end

        // ── Deadend check ──────────────────────────────────────
        // If unassigned variable count != unassigned tile count
        // then two variables were forced to the same tile
        deadend = (popcount(out_variablesIncludedMask) !=
                   popcount(out_unassignedTiles));
    end

endmodule