// ─────────────────────────────────────────────────────────────
// CreateInitialGame
//
// Computes the initial top, right, bottom, left colour masks
// and r0,r1,r2,r3 domain bitmasks for every variable in an
// Eternity-2 style puzzle.
//
// Parameters
//   N                   — board side length (board is N x N)
//   BORDER_COLOUR_COUNT — number of border colours
//   INNER_COLOUR_COUNT  — number of inner colours
//
// Derived constants
//   TC        = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT
//   VARIABLES = N * N
//   NUM_EDGES = 4 * (N - 2)
//   NUM_INNER = (N - 2) * (N - 2)
//
// Colour bitmask layout (TC bits wide)
//   bit 0              — boundary colour  (always 0b1)
//   bits 1..BC         — border colours
//   bits BC+1..BC+IC   — inner colours
//
// Domain bitmask layout (VARIABLES bits wide)
//   bits 0..3                 — corner pieces  (4 corners)
//   bits 4..4+NUM_EDGES-1     — edge pieces
//   bits 4+NUM_EDGES..end     — inner pieces
//
// Variable 0 (top-left corner) is the fixed starting placement.
// Its domain is locked to r1=0b0001 only.
// All other corners have domain 0b1110 across all rotations
// meaning any of the 3 remaining corner pieces can be placed
// in any rotation.
// ─────────────────────────────────────────────────────────────
module CreateInitialGame #(
    parameter int N                   = 4,
    parameter int BORDER_COLOUR_COUNT = 3,
    parameter int INNER_COLOUR_COUNT  = 2,
    // TC is derived — exposed as parameter so it is available
    // at port declaration time
    parameter int TC                  = 1 + BORDER_COLOUR_COUNT + INNER_COLOUR_COUNT
)(
    output logic [N*N-1:0][TC-1:0]        top,
    output logic [N*N-1:0][TC-1:0]        right,
    output logic [N*N-1:0][TC-1:0]        bottom,
    output logic [N*N-1:0][TC-1:0]        left,
    output logic [N*N-1:0][N*N-1:0]       r0,
    output logic [N*N-1:0][N*N-1:0]       r1,
    output logic [N*N-1:0][N*N-1:0]       r2,
    output logic [N*N-1:0][N*N-1:0]       r3,
    output logic [N*N-1:0]                variablesIncludedMask
);
    // ── Derived constants ──────────────────────────────────────
    localparam int VARIABLES = N * N;
    localparam int NUM_EDGES = 4 * (N - 2);
    localparam int NUM_INNER = (N - 2) * (N - 2);

    // ── Colour masks ───────────────────────────────────────────
    localparam logic [TC-1:0] BOUNDARY = TC'(1);
    localparam logic [TC-1:0] BORDER   = TC'({BORDER_COLOUR_COUNT{1'b1}}) << 1;
    localparam logic [TC-1:0] INNER_C  = TC'({INNER_COLOUR_COUNT{1'b1}})
                                         << (BORDER_COLOUR_COUNT + 1);

    // ── Domain masks ───────────────────────────────────────────
    // var 0 is fixed — only corner piece 0, rotation 1
    localparam logic [VARIABLES-1:0] FIXED_CORNER = VARIABLES'(1);

    // all other corners — any of the 3 remaining corner pieces,
    // any rotation
    localparam logic [VARIABLES-1:0] FREE_CORNER  = VARIABLES'(4'b1110);

    // edge pieces occupy bits 4..4+NUM_EDGES-1
    localparam logic [VARIABLES-1:0] EDGE_D =
        VARIABLES'({NUM_EDGES{1'b1}}) << 4;

    // inner pieces occupy bits above the edge domain
    localparam logic [VARIABLES-1:0] INNER_D =
        VARIABLES'({NUM_INNER{1'b1}}) << (4 + NUM_EDGES);

    // ── variablesIncludedMask — only variable 0 placed ────────
    assign variablesIncludedMask = VARIABLES'(1);

    // ── Combinational assignment ───────────────────────────────
    always_comb begin
        for (int id = 0; id < VARIABLES; id++) begin
            automatic int x = id % N;
            automatic int y = id / N;

            // defaults
            top[id]    = '0;
            right[id]  = '0;
            bottom[id] = '0;
            left[id]   = '0;
            r0[id]     = '0;
            r1[id]     = '0;
            r2[id]     = '0;
            r3[id]     = '0;

            // ── Top Left Corner  (x==0, y==0) ─────────────────
            if (x == 0 && y == 0) begin
                top[id]    = BOUNDARY;
                left[id]   = BOUNDARY;
                right[id]  = BORDER;
                bottom[id] = BORDER;
                r1[id]     = FIXED_CORNER;
            end

            // ── Top Right Corner  (x==N-1, y==0) ──────────────
            else if (x == N-1 && y == 0) begin
                top[id]    = BOUNDARY;
                right[id]  = BOUNDARY;
                left[id]   = BORDER;
                bottom[id] = BORDER;
                r0[id] = FREE_CORNER;
                r1[id] = FREE_CORNER;
                r2[id] = FREE_CORNER;
                r3[id] = FREE_CORNER;
            end

            // ── Bottom Left Corner  (x==0, y==N-1) ────────────
            else if (x == 0 && y == N-1) begin
                left[id]   = BOUNDARY;
                bottom[id] = BOUNDARY;
                right[id]  = BORDER;
                top[id]    = BORDER;
                r0[id] = FREE_CORNER;
                r1[id] = FREE_CORNER;
                r2[id] = FREE_CORNER;
                r3[id] = FREE_CORNER;
            end

            // ── Bottom Right Corner  (x==N-1, y==N-1) ─────────
            else if (x == N-1 && y == N-1) begin
                right[id]  = BOUNDARY;
                bottom[id] = BOUNDARY;
                left[id]   = BORDER;
                top[id]    = BORDER;
                r0[id] = FREE_CORNER;
                r1[id] = FREE_CORNER;
                r2[id] = FREE_CORNER;
                r3[id] = FREE_CORNER;
            end

            // ── Left Edge  (x==0, y>0, y<N-1) ─────────────────
            else if (x == 0) begin
                left[id]   = BOUNDARY;
                right[id]  = INNER_C;
                top[id]    = BORDER;
                bottom[id] = BORDER;
                r1[id]     = EDGE_D;
            end

            // ── Right Edge  (x==N-1, y>0, y<N-1) ─────────────
            else if (x == N-1) begin
                right[id]  = BOUNDARY;
                left[id]   = INNER_C;
                top[id]    = BORDER;
                bottom[id] = BORDER;
                r3[id]     = EDGE_D;
            end

            // ── Top Edge  (y==0, x>0, x<N-1) ──────────────────
            else if (y == 0) begin
                top[id]    = BOUNDARY;
                bottom[id] = INNER_C;
                left[id]   = BORDER;
                right[id]  = BORDER;
                r1[id]     = EDGE_D;
            end

            // ── Bottom Edge  (y==N-1, x>0, x<N-1) ────────────
            else if (y == N-1) begin
                bottom[id] = BOUNDARY;
                top[id]    = INNER_C;
                left[id]   = BORDER;
                right[id]  = BORDER;
                r0[id]     = EDGE_D;
            end

            // ── Inner variable ─────────────────────────────────
            else begin
                top[id]    = INNER_C;
                right[id]  = INNER_C;
                bottom[id] = INNER_C;
                left[id]   = INNER_C;
                r0[id]     = INNER_D;
                r1[id]     = INNER_D;
                r2[id]     = INNER_D;
                r3[id]     = INNER_D;
            end

        end
    end

endmodule
