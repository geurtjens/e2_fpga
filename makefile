SIM = verilator
TOPLEVEL_LANG = verilog
VERILATOR_FLAGS = --trace
VERILOG_SOURCES = $(shell find $(PWD)/rtl -name "*.sv")
COCOTB_TEST_MODULES = test_$(TOPLEVEL)
export COCOTB_RESOLVE_X = ZEROS
export PYTHONPATH := $(PWD)/tests:$(PYTHONPATH)

MODULES = nand_gate CascadeColourSingle CascadeColourPair

test_all:
	@for m in $(MODULES); do \
		echo ""; \
		echo "=== Testing $$m ==="; \
		rm -rf sim_build; \
		TOPLEVEL=$$m $(MAKE) sim || exit 1; \
	done
	@echo ""
	@echo "=== All tests passed ==="

include $(shell cocotb-config --makefiles)/Makefile.sim