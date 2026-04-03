// ─────────────────────────────────────────────────────────────
// CascadeColourDeadend
//
// Detects if any cascaded internal edge has become zero,
// indicating a deadend (no valid colour remains on that edge).
//
// Only checks edges that participate in a cascade:
//   horizontal — out_right for x < N-1
//   vertical   — out_bottom for y < N-1
// ─────────────────────────────────────────────────────────────
module CascadeColourDeadend #(
    parameter int N  = 4,
    parameter int TC = 6
)(
    input  logic [N*N-1:0][TC-1:0] out_right,
    input  logic [N*N-1:0][TC-1:0] out_bottom,
    output logic                   deadend
);
    localparam int VARIABLES = N * N;

    always_comb begin
        deadend = 1'b0;
        for (int id = 0; id < VARIABLES; id++) begin
            automatic int x = id % N;
            automatic int y = id / N;
            if (x < N-1 && out_right[id]  == '0) deadend = 1'b1;
            if (y < N-1 && out_bottom[id] == '0) deadend = 1'b1;
        end
    end

endmodule

