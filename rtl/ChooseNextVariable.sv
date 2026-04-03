// ─────────────────────────────────────────────────────────────
// ChooseNextVariable
//
// Selects the next variable for the solver to branch on.
//
// Strategy:
//   1. Find all singletons (assigned variables — NOT in mask)
//   2. Expand to unassigned neighbours (up/down/left/right)
//   3. Among neighbours pick the one with smallest domain
//      (measured as popcount of r0+r1+r2+r3 combined)
//   4. If tie, pick the lowest variable ID (priority encoder)
//   5. Return binary encoded variable ID
//
// Parameters
//   N         — board side length (board is N x N)
//   VARIABLES — N * N
//   ID_BITS   — $clog2(VARIABLES) — width of output ID
//
// Inputs
//   variablesIncludedMask — 1=unassigned, 0=singleton
//   r0..r3               — domain bitmasks per variable
//
// Outputs
//   next_var  — binary encoded ID of chosen variable
//   valid     — 1 if a valid candidate was found
//               0 if no unassigned neighbours exist
// ─────────────────────────────────────────────────────────────
module ChooseNextVariable #(
    parameter int N         = 4,
    parameter int VARIABLES = N * N,
    parameter int ID_BITS   = $clog2(VARIABLES)
)(
    input  logic [VARIABLES-1:0]           variablesIncludedMask,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] r3,
    output logic [ID_BITS-1:0]             next_var,
    output logic                           valid
);
    // ── Elaboration-time constants ─────────────────────────────
    // validMask — 1 for all valid variable positions
    localparam logic [VARIABLES-1:0] VALID_MASK = VARIABLES'((1 << VARIABLES) - 1);

    // notFirstCol — 1 everywhere except column 0
    // prevents left-shift wrapping across row boundaries
    function automatic logic [VARIABLES-1:0] calc_not_first_col();
        logic [VARIABLES-1:0] mask;
        mask = '0;
        for (int r = 0; r < N; r++)
            for (int c = 1; c < N; c++)
                mask[r * N + c] = 1'b1;
        return mask;
    endfunction

    // notLastCol — 1 everywhere except column N-1
    // prevents right-shift wrapping across row boundaries
    function automatic logic [VARIABLES-1:0] calc_not_last_col();
        logic [VARIABLES-1:0] mask;
        mask = '0;
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N-1; c++)
                mask[r * N + c] = 1'b1;
        return mask;
    endfunction

    localparam logic [VARIABLES-1:0] NOT_FIRST_COL = calc_not_first_col();
    localparam logic [VARIABLES-1:0] NOT_LAST_COL  = calc_not_last_col();

    // ── Internal signals ───────────────────────────────────────
    logic [VARIABLES-1:0] singletons;
    logic [VARIABLES-1:0] expanded;
    logic [VARIABLES-1:0] candidates;

    // popcount per variable — sum of set bits across all rotations
    // max value = 4 * VARIABLES, needs enough bits to hold that
    logic [$clog2(4*VARIABLES+1)-1:0] pop_count [VARIABLES-1:0];

    // minimum popcount among candidates
    logic [$clog2(4*VARIABLES+1)-1:0] min_count;

    // ── Step 1 — find singletons ───────────────────────────────
    // Singletons are variables NOT in variablesIncludedMask
    assign singletons = VALID_MASK & ~variablesIncludedMask;

    // ── Step 2 — expand to neighbours ─────────────────────────
    // Each singleton contributes its four neighbours
    // Shifts implement up/down/left/right adjacency
    always_comb begin
        expanded =
            (singletons >> N)                        |  // up
            (singletons << N)                        |  // down
            ((singletons & NOT_FIRST_COL) >> 1)      |  // left
            ((singletons & NOT_LAST_COL)  << 1);        // right

        // candidates = neighbours that are unassigned and in bounds
        // strip singletons themselves (already assigned)
        candidates = expanded & VALID_MASK & variablesIncludedMask;
    end

    // ── Step 3 — compute popcount for every variable ───────────
    always_comb begin
        for (int v = 0; v < VARIABLES; v++) begin
            pop_count[v] = $countones(r0[v]) + $countones(r1[v]) +
                           $countones(r2[v]) + $countones(r3[v]);
        end
    end

    // ── Step 4 — find minimum popcount among candidates ────────
    always_comb begin
        min_count = '1; // start at max value
        for (int v = 0; v < VARIABLES; v++) begin
            if (candidates[v] && pop_count[v] < min_count)
                min_count = pop_count[v];
        end
    end

    // ── Step 5 — priority encode: lowest candidate with min count
    always_comb begin
        next_var = '0;
        valid    = 1'b0;
        for (int v = VARIABLES-1; v >= 0; v--) begin
            // iterate high to low so lowest bit wins (last write wins)
            if (candidates[v] && pop_count[v] == min_count) begin
                next_var = ID_BITS'(v);
                valid    = 1'b1;
            end
        end
    end

endmodule
