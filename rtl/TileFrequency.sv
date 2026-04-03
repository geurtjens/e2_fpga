// ─────────────────────────────────────────────────────────────
// TileFrequency
// ─────────────────────────────────────────────────────────────
module TileFrequency #(
    parameter int N          = 4,
    parameter int VARIABLES  = N * N,
    parameter int ITERATIONS = 2
)(
    input  logic [VARIABLES-1:0]                in_variablesIncludedMask,
    input  logic [VARIABLES-1:0]                in_unassignedTiles,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] in_r3,

    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r0,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r1,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r2,
    output logic [VARIABLES-1:0][VARIABLES-1:0] out_r3,
    output logic                                deadend
);
    // ── One TileFrequencySingle stage ─────────────────────────
    // Instantiate ITERATIONS times in series using a generate
    // Each stage is a separate submodule to avoid circular logic

    // Inter-stage wires — ITERATIONS+1 sets
    // wire_r0[0] = inputs, wire_r0[ITERATIONS] = outputs
    logic [ITERATIONS:0][VARIABLES-1:0][VARIABLES-1:0] wire_r0;
    logic [ITERATIONS:0][VARIABLES-1:0][VARIABLES-1:0] wire_r1;
    logic [ITERATIONS:0][VARIABLES-1:0][VARIABLES-1:0] wire_r2;
    logic [ITERATIONS:0][VARIABLES-1:0][VARIABLES-1:0] wire_r3;

    assign wire_r0[0] = in_r0;
    assign wire_r1[0] = in_r1;
    assign wire_r2[0] = in_r2;
    assign wire_r3[0] = in_r3;

    genvar s;
    generate
        for (s = 0; s < ITERATIONS; s++) begin : gen_stage
            TileFrequencySingle #(.N(N), .VARIABLES(VARIABLES)) stage (
                .in_variablesIncludedMask (in_variablesIncludedMask),
                .in_unassignedTiles       (in_unassignedTiles),
                .in_r0  (wire_r0[s]),
                .in_r1  (wire_r1[s]),
                .in_r2  (wire_r2[s]),
                .in_r3  (wire_r3[s]),
                .out_r0 (wire_r0[s+1]),
                .out_r1 (wire_r1[s+1]),
                .out_r2 (wire_r2[s+1]),
                .out_r3 (wire_r3[s+1])
            );
        end
    endgenerate

    assign out_r0 = wire_r0[ITERATIONS];
    assign out_r1 = wire_r1[ITERATIONS];
    assign out_r2 = wire_r2[ITERATIONS];
    assign out_r3 = wire_r3[ITERATIONS];

    // ── Final deadend check ────────────────────────────────────
    function automatic int popcount_fn;
        input logic [VARIABLES-1:0] vec;
        int count;
        begin
            count = 0;
            for (int i = 0; i < VARIABLES; i++)
                count = count + vec[i];
            popcount_fn = count;
        end
    endfunction

    always_comb begin
        deadend = 1'b0;
        for (int t = 0; t < VARIABLES; t++) begin
            if (in_unassignedTiles[t]) begin
                automatic int cnt;
                cnt = 0;
                for (int v = 0; v < VARIABLES; v++) begin
                    if (in_variablesIncludedMask[v]) begin
                        automatic logic [VARIABLES-1:0] combined;
                        combined = out_r0[v] | out_r1[v] |
                                   out_r2[v] | out_r3[v];
                        if (combined[t]) cnt = cnt + 1;
                    end
                end
                if (cnt == 0) deadend = 1'b1;
            end
        end
        if (popcount_fn(in_unassignedTiles) !=
            popcount_fn(in_variablesIncludedMask))
            deadend = 1'b1;
    end

endmodule
