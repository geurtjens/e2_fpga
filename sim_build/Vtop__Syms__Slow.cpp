// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(204);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_SingletonDetectionSlower = new VerilatedScope{this, "SingletonDetectionSlower", "SingletonDetectionSlower", "SingletonDetectionSlower", -12, VerilatedScope::SCOPE_MODULE};
    __Vscopep_SingletonDetectionSlower__unnamedblk2 = new VerilatedScope{this, "SingletonDetectionSlower.unnamedblk2", "unnamedblk2", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3 = new VerilatedScope{this, "SingletonDetectionSlower.unnamedblk2.unnamedblk3", "unnamedblk3", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4 = new VerilatedScope{this, "SingletonDetectionSlower.unnamedblk2.unnamedblk3.unnamedblk4", "unnamedblk4", "<null>", -12, VerilatedScope::SCOPE_OTHER};
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_SingletonDetectionSlower);
    __Vhier.add(__Vscopep_SingletonDetectionSlower, __Vscopep_SingletonDetectionSlower__unnamedblk2);
    __Vhier.add(__Vscopep_SingletonDetectionSlower__unnamedblk2, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3);
    __Vhier.add(__Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_SingletonDetectionSlower->varInsert("ID_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.SingletonDetectionSlower__DOT__ID_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_SingletonDetectionSlower->varInsert("N", const_cast<void*>(static_cast<const void*>(&(TOP.SingletonDetectionSlower__DOT__N))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_SingletonDetectionSlower->varInsert("VARIABLES", const_cast<void*>(static_cast<const void*>(&(TOP.SingletonDetectionSlower__DOT__VARIABLES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_SingletonDetectionSlower->varInsert("deadend", &(TOP.SingletonDetectionSlower__DOT__deadend), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_r0", &(TOP.SingletonDetectionSlower__DOT__in_r0), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_r1", &(TOP.SingletonDetectionSlower__DOT__in_r1), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_r2", &(TOP.SingletonDetectionSlower__DOT__in_r2), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_r3", &(TOP.SingletonDetectionSlower__DOT__in_r3), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_unassignedTiles", &(TOP.SingletonDetectionSlower__DOT__in_unassignedTiles), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("in_variablesIncludedMask", &(TOP.SingletonDetectionSlower__DOT__in_variablesIncludedMask), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_r0", &(TOP.SingletonDetectionSlower__DOT__out_r0), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_r1", &(TOP.SingletonDetectionSlower__DOT__out_r1), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_r2", &(TOP.SingletonDetectionSlower__DOT__out_r2), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_r3", &(TOP.SingletonDetectionSlower__DOT__out_r3), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_unassignedTiles", &(TOP.SingletonDetectionSlower__DOT__out_unassignedTiles), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("out_variablesIncludedMask", &(TOP.SingletonDetectionSlower__DOT__out_variablesIncludedMask), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_SingletonDetectionSlower->varInsert("singleton_found", &(TOP.SingletonDetectionSlower__DOT__singleton_found), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2->varInsert("v", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3->varInsert("combined", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3->varInsert("rot", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3->varInsert("tile_id", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3->varInsert("total_count", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4->varInsert("p", &(TOP.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("deadend", &(TOP.deadend), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("in_r0", &(TOP.in_r0), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("in_r1", &(TOP.in_r1), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("in_r2", &(TOP.in_r2), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("in_r3", &(TOP.in_r3), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("in_unassignedTiles", &(TOP.in_unassignedTiles), false, VLVT_UINT16, VLVD_IN|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("in_variablesIncludedMask", &(TOP.in_variablesIncludedMask), false, VLVT_UINT16, VLVD_IN|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("out_r0", &(TOP.out_r0), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("out_r1", &(TOP.out_r1), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("out_r2", &(TOP.out_r2), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("out_r3", &(TOP.out_r3), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW, 0, 2 ,15,0 ,15,0);
    __Vscopep_TOP->varInsert("out_unassignedTiles", &(TOP.out_unassignedTiles), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("out_variablesIncludedMask", &(TOP.out_variablesIncludedMask), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("singleton_found", &(TOP.singleton_found), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_SingletonDetectionSlower);
    __Vhier.remove(__Vscopep_SingletonDetectionSlower, __Vscopep_SingletonDetectionSlower__unnamedblk2);
    __Vhier.remove(__Vscopep_SingletonDetectionSlower__unnamedblk2, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3);
    __Vhier.remove(__Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_SingletonDetectionSlower, __Vscopep_SingletonDetectionSlower = nullptr);
    VL_DO_CLEAR(delete __Vscopep_SingletonDetectionSlower__unnamedblk2, __Vscopep_SingletonDetectionSlower__unnamedblk2 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4, __Vscopep_SingletonDetectionSlower__unnamedblk2__unnamedblk3__unnamedblk4 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    // Tear down sub module instances
}
