// ─────────────────────────────────────────────────────────────
// SolutionStore
//
//! Stores complete solution assignments as the solver finds them.
//!
//! A solution is represented as V tile IDs — one per variable.
//! When a solution is detected every variable has exactly one
//! bit set across its four rotation domains. That bit position
//! is the tile ID. Rotation is implicit and not stored.
//!
//! Behaviour:
//!   - On store=1, solution_count increments unconditionally.
//!   - If solution_count < MAX_SOLUTIONS the assignment is
//!     written to BRAM. If the store is full the assignment is
//!     discarded but the count still increments.
//!   - solution_count therefore reflects the true number of
//!     solutions found even if some were not stored.
//!   - A stored solution is retrieved by presenting a valid
//!     read_index and asserting read_en. rdata is valid one
//!     cycle later (M10K registered read latency).
//!   - read_valid pulses high on the cycle rdata is ready.
//!
//! Frame format:
//!   V packed tile IDs, each VAR_BITS wide.
//!   Variable i occupies wdata[(i+1)*VAR_BITS-1 : i*VAR_BITS].
//!   FRAME_BITS = VAR_BITS * V
//!
//! BRAM usage:
//!   N=4: 4*16  = 64  bits/frame,  9 frames =     576 bits
//!   N=5: 5*25  = 125 bits/frame,  4 frames =     500 bits
//!   N=6: 6*36  = 216 bits/frame, 65 frames =  14,040 bits
//!   N=7: 6*49  = 294 bits/frame,512 frames = 150,528 bits (~15 M10Ks, capped)
//!   N=8: 6*64  = 384 bits/frame, 13 frames =   4,992 bits
//!
//! Parameters:
//!   N             — board side length
//!   MAX_SOLUTIONS — maximum solutions to store. Set to known
//!                   upper bound where BRAM permits, otherwise
//!                   cap to fit available M10K blocks:
//!                     N=4 →    9
//!                     N=5 →    4
//!                     N=6 →   65
//!                     N=7 →  512 (true count is 6297, capped)
//!                     N=8 →   13
//!                     N=9 →    2
// ─────────────────────────────────────────────────────────────
module SolutionStore #(
    parameter int N             = 8,    //! Board side length
    parameter int MAX_SOLUTIONS = 13    //! Maximum solutions to store
)(
    input  logic                    clk,
    input  logic                    rst,

    // ── Write port (solver side) ───────────────────────────
    input  logic                    store,          //! Pulse high for one cycle when solution found
    input  logic [FRAME_BITS-1:0]   wdata,          //! Packed tile IDs — V × VAR_BITS

    // ── Read port (HPS / testbench side) ──────────────────
    input  logic                    read_en,        //! Assert to request a solution
    input  logic [INDEX_BITS-1:0]   read_index,     //! Which solution to read (0-based)
    output logic [FRAME_BITS-1:0]   rdata,          //! Packed tile IDs (valid when read_valid=1)
    output logic                    read_valid,     //! rdata is ready to consume

    // ── Status ────────────────────────────────────────────
    output logic [COUNT_BITS-1:0]   solution_count, //! Total solutions found (may exceed MAX_SOLUTIONS)
    output logic                    store_full      //! 1 if store is full — further solutions counted only
);

    // ── Geometry ──────────────────────────────────────────
    localparam int V          = N * N;
    localparam int VAR_BITS   = $clog2(V);
    localparam int FRAME_BITS = VAR_BITS * V;           //! tile ID per variable, packed
    localparam int INDEX_BITS = $clog2(MAX_SOLUTIONS);  //! address width for solution RAM
    localparam int COUNT_BITS = INDEX_BITS + 1;         //! extra bit so count can exceed MAX_SOLUTIONS

    // ── Solution RAM ──────────────────────────────────────
    //! Inferred as M10K BRAM by Quartus.
    //! Width = FRAME_BITS, Depth = MAX_SOLUTIONS.
    //! Quartus stripes across M10K blocks automatically.
    logic [FRAME_BITS-1:0] solution_ram [0:MAX_SOLUTIONS-1];

    // ── Write ─────────────────────────────────────────────
    //! Write on store pulse if not full.
    //! Lower INDEX_BITS of solution_count is the write address.
    //! Safe because store_full blocks writes once count reaches
    //! MAX_SOLUTIONS — the address never overflows the RAM.
    always_ff @(posedge clk) begin
        if (store && !store_full)
            solution_ram[solution_count[INDEX_BITS-1:0]] <= wdata;
    end

    // ── Counter ───────────────────────────────────────────
    //! Increments on every store pulse regardless of store_full.
    //! Reflects the true number of solutions found.
    always_ff @(posedge clk) begin
        if (rst)
            solution_count <= '0;
        else if (store)
            solution_count <= solution_count + 1'b1;
    end

    // ── Full flag ─────────────────────────────────────────
    //! Combinational — goes high the cycle after the last
    //! slot is written (counter has incremented to MAX_SOLUTIONS).
    assign store_full = (solution_count >= COUNT_BITS'(MAX_SOLUTIONS));

    // ── Read — registered (one cycle M10K latency) ────────
    //! rdata is valid ONE cycle after read_en is asserted.
    //! read_index must be stable on the cycle read_en is high.
    always_ff @(posedge clk) begin
        if (read_en)
            rdata <= solution_ram[read_index];
    end

    // ── Read valid pulse ──────────────────────────────────
    always_ff @(posedge clk) begin
        if (rst)
            read_valid <= 1'b0;
        else
            read_valid <= read_en;
    end

endmodule
