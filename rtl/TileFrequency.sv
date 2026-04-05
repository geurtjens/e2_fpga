// ─────────────────────────────────────────────────────────────
// TileFrequency
//
//! Runs ITERATIONS passes of TileFrequencySingle in series,
//! then checks for deadend conditions on the final output.
//!
//! Each pass scans all unassigned tiles and forces any tile
//! that can only go to one variable into that variable's domain.
//! Multiple passes allow cascading forcing — a tile forced in
//! pass 1 may enable further forcing in pass 2.
//!
//! Deadend conditions:
//!   - Any unassigned tile has no active variable that can hold it
//!   - popcount(unassigned_tiles) != popcount(unassigned_variables)
// ─────────────────────────────────────────────────────────────
module TileFrequency #(
    parameter int N          = 4,          //! int. size of puzzle grid.
    parameter int V          = N * N,      //! int. number of variables in grid (N*N).
    parameter int ITERATIONS = 2           //! int. number of TileFrequencySingle passes to run in series.
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,           //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,           //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,           //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,           //! rotation 3 domain bitmask for each variable.
    input  logic [V-1:0]        in_unassigned_variables, //! bitmask of unassigned variables — 1=unassigned, 0=placed.
    input  logic [V-1:0]        in_unassigned_tiles,     //! bitmask of unassigned tiles — 1=available, 0=already placed.

    output logic [V-1:0][V-1:0] out_domain_r0,          //! updated rotation 0 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r1,          //! updated rotation 1 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r2,          //! updated rotation 2 domain bitmask for each variable.
    output logic [V-1:0][V-1:0] out_domain_r3,          //! updated rotation 3 domain bitmask for each variable.
    output logic                out_deadend              //! 1 if any unassigned tile has no valid variable or popcount mismatch.
);

    // ── Inter-stage wires ─────────────────────────────────────
    //! wire_r0[0] = module inputs, wire_r0[ITERATIONS] = module outputs.
    //! Each stage reads from wire[s] and writes to wire[s+1].
    logic [ITERATIONS:0][V-1:0][V-1:0] wire_r0; //! inter-stage rotation 0 domain bitmasks.
    logic [ITERATIONS:0][V-1:0][V-1:0] wire_r1; //! inter-stage rotation 1 domain bitmasks.
    logic [ITERATIONS:0][V-1:0][V-1:0] wire_r2; //! inter-stage rotation 2 domain bitmasks.
    logic [ITERATIONS:0][V-1:0][V-1:0] wire_r3; //! inter-stage rotation 3 domain bitmasks.

    assign wire_r0[0] = in_domain_r0;
    assign wire_r1[0] = in_domain_r1;
    assign wire_r2[0] = in_domain_r2;
    assign wire_r3[0] = in_domain_r3;

    // ── Cascade of TileFrequencySingle stages ─────────────────
    //! Each stage takes the output of the previous stage as input.
    //! All stages share the same unassigned_variables and
    //! unassigned_tiles masks — these do not change during propagation.
    genvar s;
    generate
        for (s = 0; s < ITERATIONS; s++) begin : gen_stage
            TileFrequency_Single #(.N(N), .V(V)) stage (
                .in_domain_r0            (wire_r0[s]),
                .in_domain_r1            (wire_r1[s]),
                .in_domain_r2            (wire_r2[s]),
                .in_domain_r3            (wire_r3[s]),
                .in_unassigned_variables (in_unassigned_variables),
                .in_unassigned_tiles     (in_unassigned_tiles),
                .out_domain_r0           (wire_r0[s+1]),
                .out_domain_r1           (wire_r1[s+1]),
                .out_domain_r2           (wire_r2[s+1]),
                .out_domain_r3           (wire_r3[s+1])
            );
        end
    endgenerate

    assign out_domain_r0 = wire_r0[ITERATIONS];
    assign out_domain_r1 = wire_r1[ITERATIONS];
    assign out_domain_r2 = wire_r2[ITERATIONS];
    assign out_domain_r3 = wire_r3[ITERATIONS];

    // ── Popcount helper ───────────────────────────────────────
    //! Counts the number of set bits in a V-wide vector.
    function automatic int popcount_fn;
        input logic [V-1:0] vec;
        int count;
        begin
            count = 0;
            for (int i = 0; i < V; i++)
                count = count + vec[i];
            popcount_fn = count;
        end
    endfunction

    // ── check_deadend ─────────────────────────────────────────
    //! Scans the final stage output and raises out_deadend if:
    //!   1. Any unassigned tile has no active variable that can
    //!      hold it in any rotation — that tile is stranded.
    //!   2. popcount(unassigned_tiles) != popcount(unassigned_variables)
    //!      — the number of remaining tiles and positions are mismatched.
    always_comb begin : check_deadend
        out_deadend = 1'b0;

        for (int t = 0; t < V; t++) begin
            if (in_unassigned_tiles[t]) begin
                automatic int cnt;
                cnt = 0;
                for (int i = 0; i < V; i++) begin
                    if (in_unassigned_variables[i]) begin
                        automatic logic [V-1:0] combined;
                        combined = out_domain_r0[i] | out_domain_r1[i] |
                                   out_domain_r2[i] | out_domain_r3[i];
                        if (combined[t]) cnt = cnt + 1;
                    end
                end
                if (cnt == 0) out_deadend = 1'b1;
            end
        end

        if (popcount_fn(in_unassigned_tiles) !=
            popcount_fn(in_unassigned_variables))
            out_deadend = 1'b1;
    end

endmodule
