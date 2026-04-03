
// ─────────────────────────────────────────────────────────────
// ChangeInColours
//
// Compares cascade inputs against outputs across all edges
// and asserts changed if any value has been updated.
// ─────────────────────────────────────────────────────────────
module CascadeColourChanges #(
    parameter int N  = 4,
    parameter int TC = 6
)(
    input  logic [N*N-1:0][TC-1:0] in_top,
    input  logic [N*N-1:0][TC-1:0] in_right,
    input  logic [N*N-1:0][TC-1:0] in_bottom,
    input  logic [N*N-1:0][TC-1:0] in_left,
    input  logic [N*N-1:0][TC-1:0] out_top,
    input  logic [N*N-1:0][TC-1:0] out_right,
    input  logic [N*N-1:0][TC-1:0] out_bottom,
    input  logic [N*N-1:0][TC-1:0] out_left,
    output logic                   changed
);
    localparam int VARIABLES = N * N;

    always_comb begin
        changed = 1'b0;
        for (int id = 0; id < VARIABLES; id++) begin
            if (out_top[id]    != in_top[id]    ||
                out_right[id]  != in_right[id]  ||
                out_bottom[id] != in_bottom[id] ||
                out_left[id]   != in_left[id])
                changed = 1'b1;
        end
    end

endmodule
