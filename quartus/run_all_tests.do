# ─────────────────────────────────────────────────────────────
# run_all_tests.do
# Runs all testbenches in sequence and reports pass/fail summary
#
# Usage from Questa console:
#   do run_all_tests.do
#
# Usage from command line (batch mode):
#   vsim -batch -do run_all_tests.do
# ─────────────────────────────────────────────────────────────

# ── Global settings ───────────────────────────────────────────
# Suppress the "are you sure you want to quit" prompt from $finish
# and disable break prompts during batch runs
quietly set WildcardFilter [lsearch -not -inline $WildcardFilter Memory]
onbreak {resume}

# ── Helper procedure — compile and run one testbench ──────────
# Arguments:
#   tb_name   — top level testbench module name
#   src_files — list of source files to compile
proc run_test {tb_name src_files} {
    global test_pass test_fail

    puts ""
    puts "══════════════════════════════════════════════════════"
    puts " Running: $tb_name"
    puts "══════════════════════════════════════════════════════"

    # Fresh library for each test to avoid stale compiled units
    if {[file exists work]} { vdel -lib work -all }
    vlib work

    # Compile all source files for this test
    set compile_ok 1
    foreach f $src_files {
        if {[catch {vlog -sv -quiet -svinputport=var $f} err]} {
            puts "  COMPILE ERROR in $f: $err"
            set compile_ok 0
        }
    }

    if {$compile_ok} {
        # Run simulation in batch — suppress UI, capture transcript
        if {[catch {
            vsim -quiet \
                 -onfinish stop \
                 -do "run -all" \
                 $tb_name
        } err]} {
            puts "  SIM ERROR: $err"
            incr test_fail
        } else {
            incr test_pass
        }
    } else {
        incr test_fail
    }
}

# ── Initialise counters ────────────────────────────────────────
set test_pass 0
set test_fail 0

# ── Core constraint modules ────────────────────────────────────
run_test tb_all_different {
    all_different.sv
    tb_all_different.sv
}

run_test tb_create_initial_game {
    create_initial_game.sv
    tb_create_initial_game.sv
}

run_test tb_cascade_colours {
    cascade_colours.sv
    tb_cascade_colours.sv
}

run_test tb_domain_to_colour {
    load_puzzle_brendan4.sv
    domain_to_colour.sv
    tb_domain_to_colour.sv
}

run_test tb_colours_to_domain {
    load_puzzle_brendan4.sv
    colours_to_domain.sv
    tb_colours_to_domain.sv
}

# ── LoadPuzzle ROM tests ───────────────────────────────────────
run_test tb_load_puzzle {
    load_puzzle_my3x3.sv
    tb_load_puzzle_my3x3.sv
}

run_test tb_load_puzzle {
    load_puzzle_my3x3_unsolvable.sv
    tb_load_puzzle_my3x3_unsolvable.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan3.sv
    tb_load_puzzle_brendan3.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan4.sv
    tb_load_puzzle_brendan4.sv
}

run_test tb_load_puzzle {
    load_puzzle_my4x4.sv
    tb_load_puzzle_my4x4.sv
}

run_test tb_load_puzzle {
    load_puzzle_my4x4_twosolutions.sv
    tb_load_puzzle_my4x4_twosolutions.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan5.sv
    tb_load_puzzle_brendan5.sv
}

run_test tb_load_puzzle {
    load_puzzle_my5x5.sv
    tb_load_puzzle_my5x5.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan6.sv
    tb_load_puzzle_brendan6.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan7.sv
    tb_load_puzzle_brendan7.sv
}

run_test tb_load_puzzle {
    load_puzzle_brendan8.sv
    tb_load_puzzle_brendan8.sv
}

# ── Summary ────────────────────────────────────────────────────
set total [expr {$test_pass + $test_fail}]
puts ""
puts "╔══════════════════════════════════════════════════════╗"
puts [format " Test Summary: %d/%d passed" $test_pass $total]
if {$test_fail > 0} {
    puts [format " FAILED: %d testbench(es)" $test_fail]
} else {
    puts " All tests passed"
}
puts "╚══════════════════════════════════════════════════════╝"
puts ""
