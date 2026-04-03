// ─────────────────────────────────────────────────────────────
// DepthFirstSearch
//
// Top level solver controller. Manages the search tree using
// depth first search with constraint propagation.
//
// Flow:
//   IDLE → PROPAGATE → CHECK → CHOOSE → NEXT_PIECE →
//   COPY_AND_ASSIGN → PROPAGATE (loop)
//   Deadend → NEXT_PIECE → BACKWARD if domain empty
//   Solution → NEXT_PIECE (continue searching for more)
//   gameId < 0 → EXHAUSTED
//
// Key design decisions:
//   - gameId range: 0..VARIABLES (one level per variable)
//   - Board state stored in 3D register arrays [gameId][variableId]
//   - Per level metadata in 1D arrays [gameId]
//   - Propagate is a black box module (defined separately)
//   - Copy parent to child, then remove tried bit from parent
//   - nodesTraversed is per level, uint64 width
//   - All solutions are counted, search continues after each find
//
// Parameters
//   N         — board side length
//   TC        — total colour bits per edge
//   VARIABLES — N * N
//   ID_BITS   — $clog2(VARIABLES)
//
// Inputs
//   clk       — clock
//   rst       — synchronous reset
//   start     — pulse to begin solving
//
// Outputs
//   solution_count — number of solutions found
//   done           — 1 when search is exhausted
//   solving        — 1 while solver is running
// ─────────────────────────────────────────────────────────────
module DepthFirstSearch #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N,
    parameter int ID_BITS   = $clog2(VARIABLES)
)(
    input  logic clk,
    input  logic rst,
    input  logic start,

    // Initial board state from CreateInitialGame
    input  logic [VARIABLES-1:0][TC-1:0]        init_top,
    input  logic [VARIABLES-1:0][TC-1:0]        init_right,
    input  logic [VARIABLES-1:0][TC-1:0]        init_bottom,
    input  logic [VARIABLES-1:0][TC-1:0]        init_left,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] init_r0,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] init_r1,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] init_r2,
    input  logic [VARIABLES-1:0][VARIABLES-1:0] init_r3,
    input  logic [VARIABLES-1:0]                init_variablesIncludedMask,
    input  logic [VARIABLES-1:0]                init_unassignedTiles,

    // Pattern data from LoadPuzzle (passed through to Assignment)
    input  logic [VARIABLES-1:0][TC-1:0] p0_top, p0_right, p0_bottom, p0_left,
    input  logic [VARIABLES-1:0][TC-1:0] p1_top, p1_right, p1_bottom, p1_left,
    input  logic [VARIABLES-1:0][TC-1:0] p2_top, p2_right, p2_bottom, p2_left,
    input  logic [VARIABLES-1:0][TC-1:0] p3_top, p3_right, p3_bottom, p3_left,

    output logic [63:0] solution_count,
    output logic        done,
    output logic        solving
);
    // ── State encoding ─────────────────────────────────────────
    typedef enum logic [3:0] {
        IDLE,
        PROPAGATE,
        WAIT_PROPAGATE,
        CHECK,
        CHOOSE,
        NEXT_PIECE,
        COPY_AND_ASSIGN,
        BACKWARD,
        EXHAUSTED
    } state_t;

    state_t state;

    // ── Game level pointer ─────────────────────────────────────
    logic [$clog2(VARIABLES+1)-1:0] gameId;

    // ── 3D board state registers [gameId][variableId] ──────────
    logic [VARIABLES:0][VARIABLES-1:0][TC-1:0]        top_mem;
    logic [VARIABLES:0][VARIABLES-1:0][TC-1:0]        right_mem;
    logic [VARIABLES:0][VARIABLES-1:0][TC-1:0]        bottom_mem;
    logic [VARIABLES:0][VARIABLES-1:0][TC-1:0]        left_mem;
    logic [VARIABLES:0][VARIABLES-1:0][VARIABLES-1:0] r0_mem;
    logic [VARIABLES:0][VARIABLES-1:0][VARIABLES-1:0] r1_mem;
    logic [VARIABLES:0][VARIABLES-1:0][VARIABLES-1:0] r2_mem;
    logic [VARIABLES:0][VARIABLES-1:0][VARIABLES-1:0] r3_mem;

    // ── Per level metadata registers [gameId] ──────────────────
    logic [VARIABLES:0][VARIABLES-1:0] unassigned_vars;
    logic [VARIABLES:0][VARIABLES-1:0] unassigned_tiles;
    logic [VARIABLES:0][ID_BITS-1:0]   branching_var;
    logic [VARIABLES:0]                first_visit;     // 1=first time at this level
    logic [VARIABLES:0][63:0]          nodes_traversed;

    // ── Propagate module interface ─────────────────────────────
    logic prop_start;
    logic prop_done;
    logic prop_deadend;

    logic [VARIABLES-1:0][TC-1:0]        prop_out_top, prop_out_right;
    logic [VARIABLES-1:0][TC-1:0]        prop_out_bottom, prop_out_left;
    logic [VARIABLES-1:0][VARIABLES-1:0] prop_out_r0, prop_out_r1;
    logic [VARIABLES-1:0][VARIABLES-1:0] prop_out_r2, prop_out_r3;
    logic [VARIABLES-1:0]                prop_out_vars;
    logic [VARIABLES-1:0]                prop_out_tiles;

    Propagate #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) propagate_inst (
        .clk                    (clk),
        .start                  (prop_start),
        .in_top                 (top_mem[gameId]),
        .in_right               (right_mem[gameId]),
        .in_bottom              (bottom_mem[gameId]),
        .in_left                (left_mem[gameId]),
        .in_r0                  (r0_mem[gameId]),
        .in_r1                  (r1_mem[gameId]),
        .in_r2                  (r2_mem[gameId]),
        .in_r3                  (r3_mem[gameId]),
        .in_variablesIncludedMask (unassigned_vars[gameId]),
        .in_unassignedTiles     (unassigned_tiles[gameId]),
        .out_top                (prop_out_top),
        .out_right              (prop_out_right),
        .out_bottom             (prop_out_bottom),
        .out_left               (prop_out_left),
        .out_r0                 (prop_out_r0),
        .out_r1                 (prop_out_r1),
        .out_r2                 (prop_out_r2),
        .out_r3                 (prop_out_r3),
        .out_variablesIncludedMask (prop_out_vars),
        .out_unassignedTiles    (prop_out_tiles),
        .done                   (prop_done),
        .deadend                (prop_deadend)
    );

    // ── ChooseNextVariable interface ───────────────────────────
    logic [ID_BITS-1:0] chosen_var;
    logic               chosen_valid;

    ChooseNextVariable #(.N(N), .VARIABLES(VARIABLES)) choose_inst (
        .variablesIncludedMask (unassigned_vars[gameId]),
        .r0                    (r0_mem[gameId]),
        .r1                    (r1_mem[gameId]),
        .r2                    (r2_mem[gameId]),
        .r3                    (r3_mem[gameId]),
        .next_var              (chosen_var),
        .valid                 (chosen_valid)
    );

    // ── Assignment interface ───────────────────────────────────
    // Assignment always operates on gameId+1 (the child level)
    logic [ID_BITS-1:0] assign_var;
    logic [ID_BITS-1:0] assign_tile;
    logic [1:0]         assign_rotation;

    logic [VARIABLES-1:0][TC-1:0]        assign_out_top, assign_out_right;
    logic [VARIABLES-1:0][TC-1:0]        assign_out_bottom, assign_out_left;
    logic [VARIABLES-1:0][VARIABLES-1:0] assign_out_r0, assign_out_r1;
    logic [VARIABLES-1:0][VARIABLES-1:0] assign_out_r2, assign_out_r3;
    logic                                assign_colours_changed;

    Assignment #(.N(N), .TC(TC), .VARIABLES(VARIABLES)) assign_inst (
        .variableId     (assign_var),
        .tileId         (assign_tile),
        .rotation       (assign_rotation),
        .in_top         (top_mem[gameId+1]),
        .in_right       (right_mem[gameId+1]),
        .in_bottom      (bottom_mem[gameId+1]),
        .in_left        (left_mem[gameId+1]),
        .in_r0          (r0_mem[gameId+1]),
        .in_r1          (r1_mem[gameId+1]),
        .in_r2          (r2_mem[gameId+1]),
        .in_r3          (r3_mem[gameId+1]),
        .p0_top(p0_top), .p0_right(p0_right),
        .p0_bottom(p0_bottom), .p0_left(p0_left),
        .p1_top(p1_top), .p1_right(p1_right),
        .p1_bottom(p1_bottom), .p1_left(p1_left),
        .p2_top(p2_top), .p2_right(p2_right),
        .p2_bottom(p2_bottom), .p2_left(p2_left),
        .p3_top(p3_top), .p3_right(p3_right),
        .p3_bottom(p3_bottom), .p3_left(p3_left),
        .out_top        (assign_out_top),
        .out_right      (assign_out_right),
        .out_bottom     (assign_out_bottom),
        .out_left       (assign_out_left),
        .out_r0         (assign_out_r0),
        .out_r1         (assign_out_r1),
        .out_r2         (assign_out_r2),
        .out_r3         (assign_out_r3),
        .colours_changed(assign_colours_changed)
    );

    // ── Next piece selection ───────────────────────────────────
    // Find lowest set bit across r0/r1/r2/r3 for branching var
    logic [VARIABLES-1:0] branch_combined;
    logic [ID_BITS-1:0]   next_tile;
    logic [1:0]           next_rotation;
    logic                 has_next_piece;

    always_comb begin
        automatic logic [VARIABLES-1:0] bv;
        bv = branching_var[gameId];

        branch_combined = r0_mem[gameId][bv] | r1_mem[gameId][bv] |
                          r2_mem[gameId][bv] | r3_mem[gameId][bv];

        // find lowest set bit — priority encoder
        next_tile    = '0;
        next_rotation = 2'd0;
        has_next_piece = 1'b0;

        for (int p = VARIABLES-1; p >= 0; p--) begin
            if (branch_combined[p]) begin
                next_tile      = ID_BITS'(p);
                has_next_piece = 1'b1;
                // determine rotation
                if      (r0_mem[gameId][bv][p]) next_rotation = 2'd0;
                else if (r1_mem[gameId][bv][p]) next_rotation = 2'd1;
                else if (r2_mem[gameId][bv][p]) next_rotation = 2'd2;
                else                             next_rotation = 2'd3;
            end
        end
    end

    // ── Check solution — all variables assigned ────────────────
    logic solution_valid;
    assign solution_valid = (unassigned_vars[gameId] == '0);

    // ── Outputs ────────────────────────────────────────────────
    assign done    = (state == EXHAUSTED);
    assign solving = (state != IDLE && state != EXHAUSTED);

    // ── Main state machine ─────────────────────────────────────
    always_ff @(posedge clk) begin
        if (rst) begin
            state          <= IDLE;
            gameId         <= '0;
            solution_count <= '0;
            prop_start     <= 1'b0;
            for (int g = 0; g <= VARIABLES; g++) begin
                first_visit[g]     <= 1'b1;
                nodes_traversed[g] <= '0;
            end
        end else begin
            prop_start <= 1'b0; // default — deassert each cycle

            case (state)

                // ── IDLE ───────────────────────────────────────
                IDLE: begin
                    if (start) begin
                        // load initial state into level 0
                        top_mem[0]    <= init_top;
                        right_mem[0]  <= init_right;
                        bottom_mem[0] <= init_bottom;
                        left_mem[0]   <= init_left;
                        r0_mem[0]     <= init_r0;
                        r1_mem[0]     <= init_r1;
                        r2_mem[0]     <= init_r2;
                        r3_mem[0]     <= init_r3;
                        unassigned_vars[0]  <= init_variablesIncludedMask;
                        unassigned_tiles[0] <= init_unassignedTiles;
                        gameId        <= '0;
                        state         <= PROPAGATE;
                        prop_start    <= 1'b1;
                    end
                end

                // ── PROPAGATE ──────────────────────────────────
                // Fire start pulse then wait for done
                PROPAGATE: begin
                    state <= WAIT_PROPAGATE;
                end

                // ── WAIT_PROPAGATE ─────────────────────────────
                WAIT_PROPAGATE: begin
                    if (prop_done) begin
                        if (prop_deadend) begin
                            // deadend — skip check, go straight to next piece
                            state <= NEXT_PIECE;
                        end else begin
                            // write stabilised state back into current level
                            top_mem[gameId]    <= prop_out_top;
                            right_mem[gameId]  <= prop_out_right;
                            bottom_mem[gameId] <= prop_out_bottom;
                            left_mem[gameId]   <= prop_out_left;
                            r0_mem[gameId]     <= prop_out_r0;
                            r1_mem[gameId]     <= prop_out_r1;
                            r2_mem[gameId]     <= prop_out_r2;
                            r3_mem[gameId]     <= prop_out_r3;
                            unassigned_vars[gameId]  <= prop_out_vars;
                            unassigned_tiles[gameId] <= prop_out_tiles;
                            state <= CHECK;
                        end
                    end
                end

                // ── CHECK ──────────────────────────────────────
                // All variables assigned — count solution
                // then fall through to find more
                CHECK: begin
                    if (solution_valid) begin
                        solution_count <= solution_count + 1;
                        state <= NEXT_PIECE;
                    end else begin
                        state <= CHOOSE;
                    end
                end

                // ── CHOOSE ─────────────────────────────────────
                // First visit: pick variable, store it
                // Return visit: use stored variable
                CHOOSE: begin
                    if (first_visit[gameId]) begin
                        if (chosen_valid) begin
                            branching_var[gameId] <= chosen_var;
                            first_visit[gameId]   <= 1'b0;
                            state <= NEXT_PIECE;
                        end else begin
                            // no valid candidate — treat as exhausted at this level
                            state <= BACKWARD;
                        end
                    end else begin
                        // already have branching var — go straight to next piece
                        state <= NEXT_PIECE;
                    end
                end

                // ── NEXT_PIECE ─────────────────────────────────
                // Pick lowest remaining bit for branching variable
                // If none left — backtrack
                NEXT_PIECE: begin
                    if (has_next_piece) begin
                        assign_var      <= branching_var[gameId];
                        assign_tile     <= next_tile;
                        assign_rotation <= next_rotation;
                        state <= COPY_AND_ASSIGN;
                    end else begin
                        state <= BACKWARD;
                    end
                end

                // ── COPY_AND_ASSIGN ────────────────────────────
                // 1. Copy current level to gameId+1
                // 2. Run assignment at gameId+1
                // 3. Remove tried bit from current level
                // 4. Increment nodesTraversed
                // 5. Move to gameId+1 and propagate
                COPY_AND_ASSIGN: begin
                    // copy parent state to child
                    top_mem[gameId+1]    <= top_mem[gameId];
                    right_mem[gameId+1]  <= right_mem[gameId];
                    bottom_mem[gameId+1] <= bottom_mem[gameId];
                    left_mem[gameId+1]   <= left_mem[gameId];
                    r0_mem[gameId+1]     <= r0_mem[gameId];
                    r1_mem[gameId+1]     <= r1_mem[gameId];
                    r2_mem[gameId+1]     <= r2_mem[gameId];
                    r3_mem[gameId+1]     <= r3_mem[gameId];
                    unassigned_vars[gameId+1]  <= prop_out_vars;
                    unassigned_tiles[gameId+1] <= prop_out_tiles;
                    first_visit[gameId+1]      <= 1'b1;

                    // apply assignment to child level
                    top_mem[gameId+1]    <= assign_out_top;
                    right_mem[gameId+1]  <= assign_out_right;
                    bottom_mem[gameId+1] <= assign_out_bottom;
                    left_mem[gameId+1]   <= assign_out_left;
                    r0_mem[gameId+1]     <= assign_out_r0;
                    r1_mem[gameId+1]     <= assign_out_r1;
                    r2_mem[gameId+1]     <= assign_out_r2;
                    r3_mem[gameId+1]     <= assign_out_r3;
                    // update unassigned vars/tiles for child
                    unassigned_vars[gameId+1]  <=
                        unassigned_vars[gameId] & ~(VARIABLES'(1) << assign_var);
                    unassigned_tiles[gameId+1] <=
                        unassigned_tiles[gameId] & ~(VARIABLES'(1) << assign_tile);

                    // remove tried bit from PARENT domain
                    case (assign_rotation)
                        2'd0: r0_mem[gameId][assign_var][assign_tile] <= 1'b0;
                        2'd1: r1_mem[gameId][assign_var][assign_tile] <= 1'b0;
                        2'd2: r2_mem[gameId][assign_var][assign_tile] <= 1'b0;
                        2'd3: r3_mem[gameId][assign_var][assign_tile] <= 1'b0;
                    endcase

                    // increment nodes traversed at this level
                    nodes_traversed[gameId] <= nodes_traversed[gameId] + 1;

                    // move to child level and propagate
                    gameId     <= gameId + 1;
                    state      <= PROPAGATE;
                    prop_start <= 1'b1;
                end

                // ── BACKWARD ───────────────────────────────────
                // Go back to parent level
                // Parent domain already has tried bit removed
                // If at level 0 — exhausted
                BACKWARD: begin
                    if (gameId == '0) begin
                        state <= EXHAUSTED;
                    end else begin
                        gameId <= gameId - 1;
                        state  <= NEXT_PIECE;
                    end
                end

                // ── EXHAUSTED ──────────────────────────────────
                EXHAUSTED: begin
                    // stay here — done signal is asserted
                end

                default: state <= IDLE;

            endcase
        end
    end

endmodule
