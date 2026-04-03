// ─────────────────────────────────────────────────────────────
// CopyLevel
//
// Copies one search level in BRAM to the next level.
// Given a gameId, copies all data from gameId to gameId+1.
//
// Copies per variable:
//   - r0, r1, r2, r3  (domain bitmasks)
//   - top, right, bottom, left  (colour edges, packed)
//
// Copies scalar metadata:
//   - availableVariables  (unassigned variable mask)
//   - availableTiles      (unassigned tile mask)
//
// BRAM address = gameId * VARIABLES + variableId
//
// Operation:
//   Pulse start=1 for one cycle to begin.
//   done pulses high for one cycle when complete.
//   Takes VARIABLES + 2 cycles (read latency + copy loop + final write).
//
// Parameters
//   N         — board side length
//   TC        — colour bits per edge
//   VARIABLES — N * N
//   DEPTH     — VARIABLES + 1  (search stack depth)
//   ADDR_BITS — address width for BRAM
// ─────────────────────────────────────────────────────────────
module CopyLevel #(
    parameter int N         = 4,
    parameter int TC        = 6,
    parameter int VARIABLES = N * N,
    parameter int ID_BITS   = $clog2(VARIABLES),
    parameter int DEPTH     = VARIABLES + 1,
    parameter int ADDR_BITS = $clog2(DEPTH * VARIABLES)
)(
    input  logic clk,
    input  logic rst,
    input  logic start,

    // Which level to copy FROM — copies gameId → gameId+1
    input  logic [$clog2(DEPTH)-1:0] gameId,

    // ── Domain BRAM ports ──────────────────────────────────────
    // Read port
    output logic [ADDR_BITS-1:0]  dom_rd_addr,
    input  logic [VARIABLES-1:0]  dom_rd_r0,
    input  logic [VARIABLES-1:0]  dom_rd_r1,
    input  logic [VARIABLES-1:0]  dom_rd_r2,
    input  logic [VARIABLES-1:0]  dom_rd_r3,

    // Write port
    output logic                  dom_wr_en,
    output logic [ADDR_BITS-1:0]  dom_wr_addr,
    output logic [VARIABLES-1:0]  dom_wr_r0,
    output logic [VARIABLES-1:0]  dom_wr_r1,
    output logic [VARIABLES-1:0]  dom_wr_r2,
    output logic [VARIABLES-1:0]  dom_wr_r3,

    // ── Colour BRAM ports ──────────────────────────────────────
    // word = { left, bottom, right, top } each TC bits wide
    // Read port
    output logic [ADDR_BITS-1:0]  col_rd_addr,
    input  logic [4*TC-1:0]       col_rd_data,

    // Write port
    output logic                  col_wr_en,
    output logic [ADDR_BITS-1:0]  col_wr_addr,
    output logic [4*TC-1:0]       col_wr_data,

    // ── Metadata ports — scalar registers in parent ────────────
    input  logic [VARIABLES-1:0]  in_availableVariables,
    input  logic [VARIABLES-1:0]  in_availableTiles,

    output logic [VARIABLES-1:0]  out_availableVariables,
    output logic [VARIABLES-1:0]  out_availableTiles,
    output logic                  out_valid,   // pulses with done

    // ── Control ────────────────────────────────────────────────
    output logic done
);

    // ── Address helper ─────────────────────────────────────────
    function automatic logic [ADDR_BITS-1:0] mk_addr;
        input logic [$clog2(DEPTH)-1:0] gid;
        input logic [ID_BITS-1:0]       vid;
        mk_addr = gid * VARIABLES + vid;
    endfunction

    // ── State machine ──────────────────────────────────────────
    typedef enum logic [1:0] {
        S_IDLE = 2'd0,
        S_READ = 2'd1,   // assert read address, capture data next cycle
        S_DONE = 2'd2    // final word written, pulse done
    } state_t;

    state_t              state;
    logic [ID_BITS:0]  cnt;   // counts 0..VARIABLES

    always_ff @(posedge clk) begin
        if (rst) begin
            state      <= S_IDLE;
            done       <= 1'b0;
            dom_wr_en  <= 1'b0;
            col_wr_en  <= 1'b0;
            out_valid  <= 1'b0;
        end else begin
            done      <= 1'b0;
            dom_wr_en <= 1'b0;
            col_wr_en <= 1'b0;
            out_valid <= 1'b0;

            case (state)

                // ── Idle — wait for start ──────────────────────
                S_IDLE: begin
                    if (start) begin
                        dom_rd_addr <= mk_addr(gameId, '0);
                        col_rd_addr <= mk_addr(gameId, '0);
                        cnt         <= '0;
                        state       <= S_READ;
                    end
                end

                // ── Read loop ──────────────────────────────────
                // Each cycle:
                //   - Advance read address to next variable
                //   - Write data that arrived from previous address
                S_READ: begin
                    cnt         <= cnt + 1;
                    dom_rd_addr <= mk_addr(gameId, cnt + 1);
                    col_rd_addr <= mk_addr(gameId, cnt + 1);

                    // Data for (cnt-1) arrives this cycle — write to child
                    if (cnt > 0) begin
                        dom_wr_en   <= 1'b1;
                        col_wr_en   <= 1'b1;
                        dom_wr_addr <= mk_addr(gameId + 1, cnt - 1);
                        col_wr_addr <= mk_addr(gameId + 1, cnt - 1);
                        dom_wr_r0   <= dom_rd_r0;
                        dom_wr_r1   <= dom_rd_r1;
                        dom_wr_r2   <= dom_rd_r2;
                        dom_wr_r3   <= dom_rd_r3;
                        col_wr_data <= col_rd_data;
                    end

                    // After VARIABLES+1 cycles the last word has arrived
                    if (cnt == VARIABLES) begin
                        dom_wr_en   <= 1'b1;
                        col_wr_en   <= 1'b1;
                        dom_wr_addr <= mk_addr(gameId + 1, VARIABLES - 1);
                        col_wr_addr <= mk_addr(gameId + 1, VARIABLES - 1);
                        dom_wr_r0   <= dom_rd_r0;
                        dom_wr_r1   <= dom_rd_r1;
                        dom_wr_r2   <= dom_rd_r2;
                        dom_wr_r3   <= dom_rd_r3;
                        col_wr_data <= col_rd_data;

                        // Copy scalar metadata
                        out_availableVariables <= in_availableVariables;
                        out_availableTiles     <= in_availableTiles;
                        out_valid              <= 1'b1;

                        state <= S_DONE;
                    end
                end

                // ── Done — pulse done for one cycle ───────────
                S_DONE: begin
                    done  <= 1'b1;
                    state <= S_IDLE;
                end

            endcase
        end
    end

endmodule
