// ─────────────────────────────────────────────────────────────
// TileFrequency
//
//! Runs a single pass of TileFrequency_Single to force tiles
//! that can only go to one variable, then runs
//! SingletonAssignment to update the availability masks.
//!
//! out_deadend — 1 if any unassigned tile has no valid variable
//!               or popcount(unassigned_tiles) != popcount(unassigned_variables).
//!
//! Parameters
//!   N — board side length (board is N x N)
//!   V — N * N
// ─────────────────────────────────────────────────────────────
module TileFrequency #(
    parameter int N = 4,
    parameter int V = N * N
)(
    input  logic [V-1:0][V-1:0] in_domain_r0,            //! rotation 0 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r1,            //! rotation 1 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r2,            //! rotation 2 domain bitmask for each variable.
    input  logic [V-1:0][V-1:0] in_domain_r3,            //! rotation 3 domain bitmask for each variable.
    input  logic [V-1:0]        in_unassigned_variables,  //! 1=unassigned, 0=placed.
    input  logic [V-1:0]        in_unassigned_tiles,      //! 1=available, 0=placed.

    output logic [V-1:0][V-1:0] out_domain_r0,            //! updated rotation 0 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r1,            //! updated rotation 1 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r2,            //! updated rotation 2 domain bitmask.
    output logic [V-1:0][V-1:0] out_domain_r3,            //! updated rotation 3 domain bitmask.
    output logic [V-1:0]        out_unassigned_variables,  //! updated availability mask — singletons removed.
    output logic [V-1:0]        out_unassigned_tiles,      //! updated tile mask — forced tiles removed.
    output logic                out_deadend                //! 1 if a tile is stranded or popcount mismatch.
);

    // ── Inter-stage wires ─────────────────────────────────────
    logic [1:0][V-1:0][V-1:0] wire_r0;
    logic [1:0][V-1:0][V-1:0] wire_r1;
    logic [1:0][V-1:0][V-1:0] wire_r2;
    logic [1:0][V-1:0][V-1:0] wire_r3;

    assign wire_r0[0] = in_domain_r0;
    assign wire_r1[0] = in_domain_r1;
    assign wire_r2[0] = in_domain_r2;
    assign wire_r3[0] = in_domain_r3;

    // ── Single pass ───────────────────────────────────────────
    TileFrequency_Single #(.N(N), .V(V)) stage_0 (
        .in_domain_r0            (wire_r0[0]),
        .in_domain_r1            (wire_r1[0]),
        .in_domain_r2            (wire_r2[0]),
        .in_domain_r3            (wire_r3[0]),
        .in_unassigned_variables (in_unassigned_variables),
        .in_unassigned_tiles     (in_unassigned_tiles),
        .out_domain_r0           (wire_r0[1]),
        .out_domain_r1           (wire_r1[1]),
        .out_domain_r2           (wire_r2[1]),
        .out_domain_r3           (wire_r3[1])
    );

    // ── Deadend check ─────────────────────────────────────────
    //! Raises out_deadend if any unassigned tile has no active
    //! variable that can hold it, or if popcount mismatch.
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

    always_comb begin : check_deadend
        out_deadend = 1'b0;
        for (int t = 0; t < V; t++) begin
            if (in_unassigned_tiles[t]) begin
                automatic int cnt;
                cnt = 0;
                for (int i = 0; i < V; i++) begin
                    if (in_unassigned_variables[i]) begin
                        automatic logic [V-1:0] combined;
                        combined = wire_r0[1][i] | wire_r1[1][i] |
                                   wire_r2[1][i] | wire_r3[1][i];
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

    // ── SingletonAssignment ───────────────────────────────────
    //! Sweeps the collapsed domains and updates availability masks.
    SingletonAssignment #(.N(N), .V(V)) singleton_assignment (
        .in_unassignedVariables  (in_unassigned_variables),
        .in_unassignedTiles      (in_unassigned_tiles),
        .in_domain_r0            (wire_r0[1]),
        .in_domain_r1            (wire_r1[1]),
        .in_domain_r2            (wire_r2[1]),
        .in_domain_r3            (wire_r3[1]),
        .out_unassignedVariables (out_unassigned_variables),
        .out_unassignedTiles     (out_unassigned_tiles),
        .out_domain_r0           (out_domain_r0),
        .out_domain_r1           (out_domain_r1),
        .out_domain_r2           (out_domain_r2),
        .out_domain_r3           (out_domain_r3)
    );

endmodule
