// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ SingletonDetectionSlower__DOT____VlemCall_1__popcount;
    IData/*31:0*/ SingletonDetectionSlower__DOT____VlemCall_0__popcount;
    SData/*15:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec = 0;
    IData/*31:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count = 0;
    SData/*15:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec = 0;
    IData/*31:0*/ __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count = 0;
    // Body
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[0U] 
        = vlSelfRef.in_r0[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[1U] 
        = vlSelfRef.in_r0[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[2U] 
        = vlSelfRef.in_r0[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[3U] 
        = vlSelfRef.in_r0[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[4U] 
        = vlSelfRef.in_r0[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[5U] 
        = vlSelfRef.in_r0[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[6U] 
        = vlSelfRef.in_r0[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r0[7U] 
        = vlSelfRef.in_r0[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[0U] 
        = vlSelfRef.in_r1[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[1U] 
        = vlSelfRef.in_r1[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[2U] 
        = vlSelfRef.in_r1[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[3U] 
        = vlSelfRef.in_r1[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[4U] 
        = vlSelfRef.in_r1[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[5U] 
        = vlSelfRef.in_r1[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[6U] 
        = vlSelfRef.in_r1[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r1[7U] 
        = vlSelfRef.in_r1[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[0U] 
        = vlSelfRef.in_r2[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[1U] 
        = vlSelfRef.in_r2[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[2U] 
        = vlSelfRef.in_r2[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[3U] 
        = vlSelfRef.in_r2[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[4U] 
        = vlSelfRef.in_r2[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[5U] 
        = vlSelfRef.in_r2[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[6U] 
        = vlSelfRef.in_r2[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r2[7U] 
        = vlSelfRef.in_r2[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[0U] 
        = vlSelfRef.in_r3[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[1U] 
        = vlSelfRef.in_r3[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[2U] 
        = vlSelfRef.in_r3[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[3U] 
        = vlSelfRef.in_r3[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[4U] 
        = vlSelfRef.in_r3[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[5U] 
        = vlSelfRef.in_r3[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[6U] 
        = vlSelfRef.in_r3[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_r3[7U] 
        = vlSelfRef.in_r3[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__in_unassignedTiles 
        = vlSelfRef.in_unassignedTiles;
    vlSelfRef.SingletonDetectionSlower__DOT__in_variablesIncludedMask 
        = vlSelfRef.in_variablesIncludedMask;
    vlSelfRef.SingletonDetectionSlower__DOT__out_variablesIncludedMask 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_variablesIncludedMask;
    vlSelfRef.SingletonDetectionSlower__DOT__out_unassignedTiles 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_unassignedTiles;
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[0U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[1U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[2U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[3U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[4U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[5U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[6U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r0[7U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r0[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[0U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[1U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[2U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[3U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[4U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[5U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[6U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r1[7U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r1[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[0U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[1U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[2U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[3U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[4U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[5U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[6U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r2[7U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r2[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[0U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[0U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[1U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[1U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[2U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[2U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[3U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[3U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[4U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[4U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[5U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[5U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[6U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[6U];
    vlSelfRef.SingletonDetectionSlower__DOT__out_r3[7U] 
        = vlSelfRef.SingletonDetectionSlower__DOT__in_r3[7U];
    vlSelfRef.SingletonDetectionSlower__DOT__singleton_found = 0U;
    vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v)) {
        if ((1U & ((IData)(vlSelfRef.SingletonDetectionSlower__DOT__in_variablesIncludedMask) 
                   >> (0x0000000fU & vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v)))) {
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
            vlSelf->SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3574786826605908100ull);
            vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count = 0U;
            vlSelf->SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13935433469074046238ull);
            vlSelf->SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12597781318334118384ull);
            vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined 
                = (0x0000ffffU & ((((((0U == (0x0000001fU 
                                              & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                       ? 0U : (vlSelfRef.SingletonDetectionSlower__DOT__in_r0
                                               [(((IData)(0x0000000fU) 
                                                  + 
                                                  (0x000000ffU 
                                                   & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                 >> 5U)] 
                                               << ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                     | (vlSelfRef.SingletonDetectionSlower__DOT__in_r0
                                        [(7U & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                >> 5U))] 
                                        >> (0x0000001fU 
                                            & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))) 
                                    | (((0U == (0x0000001fU 
                                                & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                         ? 0U : (vlSelfRef.SingletonDetectionSlower__DOT__in_r1
                                                 [(
                                                   ((IData)(0x0000000fU) 
                                                    + 
                                                    (0x000000ffU 
                                                     & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                   >> 5U)] 
                                                 << 
                                                 ((IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                       | (vlSelfRef.SingletonDetectionSlower__DOT__in_r1
                                          [(7U & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                  >> 5U))] 
                                          >> (0x0000001fU 
                                              & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                   | (((0U == (0x0000001fU 
                                               & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                        ? 0U : (vlSelfRef.SingletonDetectionSlower__DOT__in_r2
                                                [(((IData)(0x0000000fU) 
                                                   + 
                                                   (0x000000ffU 
                                                    & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                  >> 5U)] 
                                                << 
                                                ((IData)(0x00000020U) 
                                                 - 
                                                 (0x0000001fU 
                                                  & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                      | (vlSelfRef.SingletonDetectionSlower__DOT__in_r2
                                         [(7U & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                 >> 5U))] 
                                         >> (0x0000001fU 
                                             & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                  | (((0U == (0x0000001fU 
                                              & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                       ? 0U : (vlSelfRef.SingletonDetectionSlower__DOT__in_r3
                                               [(((IData)(0x0000000fU) 
                                                  + 
                                                  (0x000000ffU 
                                                   & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                 >> 5U)] 
                                               << ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                     | (vlSelfRef.SingletonDetectionSlower__DOT__in_r3
                                        [(7U & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                >> 5U))] 
                                        >> (0x0000001fU 
                                            & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec 
                = vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined;
            vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count = 0U;
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count = 0U;
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count = 0U;
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (1U & (IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 1U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 2U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 3U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 4U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 5U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 6U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 7U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 8U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 9U)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0aU)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0bU)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0cU)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0dU)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0eU)));
            vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                = (vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count 
                   + (1U & ((IData)(vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__vec) 
                            >> 0x0fU)));
            vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count 
                = vlSelfRef.__Vfunc_SingletonDetectionSlower__DOT__popcount__0__count;
            if ((1U == vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__total_count)) {
                vlSelfRef.SingletonDetectionSlower__DOT__singleton_found = 1U;
                vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id = 0U;
                vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p = 0x0000000fU;
                while (VL_LTES_III(32, 0U, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p)) {
                    if ((1U & ((IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined) 
                               >> (0x0000000fU & vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p)))) {
                        vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id 
                            = (0x0000000fU & vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p);
                    }
                    vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p 
                        = (vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p 
                           - (IData)(1U));
                }
                vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot 
                    = ((0U != (0x0000ffffU & (((0U 
                                                == 
                                                (0x0000001fU 
                                                 & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                                ? 0U
                                                : (vlSelfRef.SingletonDetectionSlower__DOT__in_r0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     (0x000000ffU 
                                                      & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                              | (vlSelfRef.SingletonDetectionSlower__DOT__in_r0
                                                 [(7U 
                                                   & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                      >> 5U))] 
                                                 >> 
                                                 (0x0000001fU 
                                                  & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))))
                        ? 0U : ((0U != (0x0000ffffU 
                                        & (((0U == 
                                             (0x0000001fU 
                                              & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                             ? 0U : 
                                            (vlSelfRef.SingletonDetectionSlower__DOT__in_r1
                                             [(((IData)(0x0000000fU) 
                                                + (0x000000ffU 
                                                   & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                               >> 5U)] 
                                             << ((IData)(0x00000020U) 
                                                 - 
                                                 (0x0000001fU 
                                                  & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                           | (vlSelfRef.SingletonDetectionSlower__DOT__in_r1
                                              [(7U 
                                                & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                   >> 5U))] 
                                              >> (0x0000001fU 
                                                  & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))))
                                 ? 1U : ((0U != (0x0000ffffU 
                                                 & (((0U 
                                                      == 
                                                      (0x0000001fU 
                                                       & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)))
                                                      ? 0U
                                                      : 
                                                     (vlSelfRef.SingletonDetectionSlower__DOT__in_r2
                                                      [
                                                      (((IData)(0x0000000fU) 
                                                        + 
                                                        (0x000000ffU 
                                                         & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))) 
                                                       >> 5U)] 
                                                      << 
                                                      ((IData)(0x00000020U) 
                                                       - 
                                                       (0x0000001fU 
                                                        & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))) 
                                                    | (vlSelfRef.SingletonDetectionSlower__DOT__in_r2
                                                       [
                                                       (7U 
                                                        & (VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U) 
                                                           >> 5U))] 
                                                       >> 
                                                       (0x0000001fU 
                                                        & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U))))))
                                          ? 2U : 3U)));
                VL_ASSIGNSEL_WI(256, 16, (0x000000ffU 
                                          & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)), vlSelfRef.SingletonDetectionSlower__DOT__out_r0, 
                                ((0U == (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                                  ? (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                                  : 0U));
                VL_ASSIGNSEL_WI(256, 16, (0x000000ffU 
                                          & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)), vlSelfRef.SingletonDetectionSlower__DOT__out_r1, 
                                ((1U == (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                                  ? (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                                  : 0U));
                VL_ASSIGNSEL_WI(256, 16, (0x000000ffU 
                                          & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)), vlSelfRef.SingletonDetectionSlower__DOT__out_r2, 
                                ((2U == (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                                  ? (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                                  : 0U));
                VL_ASSIGNSEL_WI(256, 16, (0x000000ffU 
                                          & VL_SHIFTL_III(8,32,32, vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v, 4U)), vlSelfRef.SingletonDetectionSlower__DOT__out_r3, 
                                ((3U == (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                                  ? (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                                  : 0U));
                vlSelfRef.SingletonDetectionSlower__DOT__out_variablesIncludedMask 
                    = ((~ ((IData)(1U) << (0x0000000fU 
                                           & vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v))) 
                       & (IData)(vlSelfRef.SingletonDetectionSlower__DOT__out_variablesIncludedMask));
                vlSelfRef.SingletonDetectionSlower__DOT__out_unassignedTiles 
                    = ((~ ((IData)(1U) << (IData)(vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id))) 
                       & (IData)(vlSelfRef.SingletonDetectionSlower__DOT__out_unassignedTiles));
            }
        }
        vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v 
            = ((IData)(1U) + vlSelfRef.SingletonDetectionSlower__DOT__unnamedblk2__DOT__v);
    }
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec 
        = vlSelfRef.SingletonDetectionSlower__DOT__out_variablesIncludedMask;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (1U & (IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 1U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 2U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 3U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 4U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 5U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 6U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 7U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 8U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 9U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0aU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0bU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0cU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0dU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0eU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__1__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__1__vec) 
                    >> 0x0fU)));
    SingletonDetectionSlower__DOT____VlemCall_0__popcount 
        = __Vfunc_SingletonDetectionSlower__DOT__popcount__1__count;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec 
        = vlSelfRef.SingletonDetectionSlower__DOT__out_unassignedTiles;
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (1U & (IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 1U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 2U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 3U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 4U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 5U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 6U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 7U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 8U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 9U)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0aU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0bU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0cU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0dU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0eU)));
    __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
        = (__Vfunc_SingletonDetectionSlower__DOT__popcount__2__count 
           + (1U & ((IData)(__Vfunc_SingletonDetectionSlower__DOT__popcount__2__vec) 
                    >> 0x0fU)));
    SingletonDetectionSlower__DOT____VlemCall_1__popcount 
        = __Vfunc_SingletonDetectionSlower__DOT__popcount__2__count;
    vlSelfRef.SingletonDetectionSlower__DOT__deadend 
        = (SingletonDetectionSlower__DOT____VlemCall_0__popcount 
           != SingletonDetectionSlower__DOT____VlemCall_1__popcount);
    vlSelfRef.out_variablesIncludedMask = vlSelfRef.SingletonDetectionSlower__DOT__out_variablesIncludedMask;
    vlSelfRef.out_unassignedTiles = vlSelfRef.SingletonDetectionSlower__DOT__out_unassignedTiles;
    vlSelfRef.out_r0[0U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[0U];
    vlSelfRef.out_r0[1U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[1U];
    vlSelfRef.out_r0[2U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[2U];
    vlSelfRef.out_r0[3U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[3U];
    vlSelfRef.out_r0[4U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[4U];
    vlSelfRef.out_r0[5U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[5U];
    vlSelfRef.out_r0[6U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[6U];
    vlSelfRef.out_r0[7U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r0[7U];
    vlSelfRef.out_r1[0U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[0U];
    vlSelfRef.out_r1[1U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[1U];
    vlSelfRef.out_r1[2U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[2U];
    vlSelfRef.out_r1[3U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[3U];
    vlSelfRef.out_r1[4U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[4U];
    vlSelfRef.out_r1[5U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[5U];
    vlSelfRef.out_r1[6U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[6U];
    vlSelfRef.out_r1[7U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r1[7U];
    vlSelfRef.out_r2[0U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[0U];
    vlSelfRef.out_r2[1U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[1U];
    vlSelfRef.out_r2[2U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[2U];
    vlSelfRef.out_r2[3U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[3U];
    vlSelfRef.out_r2[4U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[4U];
    vlSelfRef.out_r2[5U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[5U];
    vlSelfRef.out_r2[6U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[6U];
    vlSelfRef.out_r2[7U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r2[7U];
    vlSelfRef.out_r3[0U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[0U];
    vlSelfRef.out_r3[1U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[1U];
    vlSelfRef.out_r3[2U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[2U];
    vlSelfRef.out_r3[3U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[3U];
    vlSelfRef.out_r3[4U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[4U];
    vlSelfRef.out_r3[5U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[5U];
    vlSelfRef.out_r3[6U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[6U];
    vlSelfRef.out_r3[7U] = vlSelfRef.SingletonDetectionSlower__DOT__out_r3[7U];
    vlSelfRef.singleton_found = vlSelfRef.SingletonDetectionSlower__DOT__singleton_found;
    vlSelfRef.deadend = vlSelfRef.SingletonDetectionSlower__DOT__deadend;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/parallels/e2_fpga/rtl/SingletonDetectionSlower.sv", 39, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
