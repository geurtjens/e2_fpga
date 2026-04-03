// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(singleton_found,0,0);
    VL_OUT8(deadend,0,0);
    CData/*0:0*/ SingletonDetectionSlower__DOT__singleton_found;
    CData/*0:0*/ SingletonDetectionSlower__DOT__deadend;
    CData/*3:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id;
    CData/*1:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    VL_IN16(in_variablesIncludedMask,15,0);
    VL_IN16(in_unassignedTiles,15,0);
    VL_INW(in_r0,255,0,8);
    VL_INW(in_r1,255,0,8);
    VL_INW(in_r2,255,0,8);
    VL_INW(in_r3,255,0,8);
    VL_OUT16(out_variablesIncludedMask,15,0);
    VL_OUT16(out_unassignedTiles,15,0);
    VL_OUTW(out_r0,255,0,8);
    VL_OUTW(out_r1,255,0,8);
    VL_OUTW(out_r2,255,0,8);
    VL_OUTW(out_r3,255,0,8);
    SData/*15:0*/ SingletonDetectionSlower__DOT__in_variablesIncludedMask;
    SData/*15:0*/ SingletonDetectionSlower__DOT__in_unassignedTiles;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__in_r0;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__in_r1;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__in_r2;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__in_r3;
    SData/*15:0*/ SingletonDetectionSlower__DOT__out_variablesIncludedMask;
    SData/*15:0*/ SingletonDetectionSlower__DOT__out_unassignedTiles;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__out_r0;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__out_r1;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__out_r2;
    VlWide<8>/*255:0*/ SingletonDetectionSlower__DOT__out_r3;
    SData/*15:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined;
    SData/*15:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec;
    IData/*31:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__v;
    IData/*31:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count;
    IData/*31:0*/ SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p;
    IData/*31:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__0__count;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ SingletonDetectionSlower__DOT__N = 4U;
    static constexpr IData/*31:0*/ SingletonDetectionSlower__DOT__VARIABLES = 0x00000010U;
    static constexpr IData/*31:0*/ SingletonDetectionSlower__DOT__ID_BITS = 4U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
