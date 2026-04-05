// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__3(Vtop_PropagateOnce__N3_V9_C5* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ stage5_tile_frequency__DOT____VlemCall_1__popcount_fn;
    IData/*31:0*/ stage5_tile_frequency__DOT____VlemCall_0__popcount_fn;
    IData/*31:0*/ stage6_singleton_detection__DOT____VlemCall_1__popcount;
    IData/*31:0*/ stage6_singleton_detection__DOT____VlemCall_0__popcount;
    SData/*8:0*/ __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec = 0;
    IData/*31:0*/ __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count = 0;
    SData/*8:0*/ __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec = 0;
    IData/*31:0*/ __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count = 0;
    SData/*8:0*/ __Vfunc_stage6_singleton_detection__DOT__popcount__6__vec;
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__vec = 0;
    IData/*31:0*/ __Vfunc_stage6_singleton_detection__DOT__popcount__6__count;
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count = 0;
    SData/*8:0*/ __Vfunc_stage6_singleton_detection__DOT__popcount__7__vec;
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__vec = 0;
    IData/*31:0*/ __Vfunc_stage6_singleton_detection__DOT__popcount__7__count;
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count = 0;
    // Body
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r0[0U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r0[1U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[2U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[0U] 
            << 0x00000011U) | vlSelfRef.stage5_tile_frequency__DOT__in_domain_r0[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[3U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[0U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[1U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[4U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[1U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[2U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[5U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r0[0U] 
            << 2U) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r0[2U] 
                      >> 0x0000000fU));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[6U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r0[0U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r0[1U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r0[7U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r0[1U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r0[2U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r1[0U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r1[1U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[2U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[0U] 
            << 0x00000011U) | vlSelfRef.stage5_tile_frequency__DOT__in_domain_r1[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[3U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[0U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[1U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[4U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[1U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[2U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[5U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r1[0U] 
            << 2U) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r1[2U] 
                      >> 0x0000000fU));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[6U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r1[0U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r1[1U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r1[7U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r1[1U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r1[2U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r2[0U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r2[1U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[2U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[0U] 
            << 0x00000011U) | vlSelfRef.stage5_tile_frequency__DOT__in_domain_r2[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[3U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[0U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[1U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[4U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[1U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[2U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[5U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r2[0U] 
            << 2U) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r2[2U] 
                      >> 0x0000000fU));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[6U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r2[0U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r2[1U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r2[7U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r2[1U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r2[2U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r3[0U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__in_domain_r3[1U];
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[2U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[0U] 
            << 0x00000011U) | vlSelfRef.stage5_tile_frequency__DOT__in_domain_r3[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[3U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[0U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[1U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[4U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[1U] 
            >> 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[2U] 
                               << 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[5U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r3[0U] 
            << 2U) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__out_domain_r3[2U] 
                      >> 0x0000000fU));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[6U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r3[0U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r3[1U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__wire_r3[7U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r3[1U] 
            >> 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__out_domain_r3[2U] 
                               << 2U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r0[0U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r0[1U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U] 
        = (0x0001ffffU & vlSelfRef.stage5_tile_frequency__DOT__wire_r0[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r0[3U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[2U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r0[4U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[3U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U] 
        = (0x0001ffffU & ((vlSelfRef.stage5_tile_frequency__DOT__wire_r0[5U] 
                           << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[4U] 
                                              >> 0x00000011U)));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r0[6U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[5U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r0[7U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[6U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[2U] 
        = (0x0001ffffU & (vlSelfRef.stage5_tile_frequency__DOT__wire_r0[7U] 
                          >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r1[0U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r1[1U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U] 
        = (0x0001ffffU & vlSelfRef.stage5_tile_frequency__DOT__wire_r1[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r1[3U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[2U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r1[4U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[3U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U] 
        = (0x0001ffffU & ((vlSelfRef.stage5_tile_frequency__DOT__wire_r1[5U] 
                           << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[4U] 
                                              >> 0x00000011U)));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r1[6U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[5U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r1[7U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[6U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[2U] 
        = (0x0001ffffU & (vlSelfRef.stage5_tile_frequency__DOT__wire_r1[7U] 
                          >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r2[0U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r2[1U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U] 
        = (0x0001ffffU & vlSelfRef.stage5_tile_frequency__DOT__wire_r2[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r2[3U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[2U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r2[4U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[3U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U] 
        = (0x0001ffffU & ((vlSelfRef.stage5_tile_frequency__DOT__wire_r2[5U] 
                           << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[4U] 
                                              >> 0x00000011U)));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r2[6U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[5U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r2[7U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[6U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[2U] 
        = (0x0001ffffU & (vlSelfRef.stage5_tile_frequency__DOT__wire_r2[7U] 
                          >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r3[0U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U] 
        = vlSelfRef.stage5_tile_frequency__DOT__wire_r3[1U];
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U] 
        = (0x0001ffffU & vlSelfRef.stage5_tile_frequency__DOT__wire_r3[2U]);
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r3[3U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[2U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r3[4U] 
            << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[3U] 
                               >> 0x00000011U));
    vlSelfRef.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U] 
        = (0x0001ffffU & ((vlSelfRef.stage5_tile_frequency__DOT__wire_r3[5U] 
                           << 0x0000000fU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[4U] 
                                              >> 0x00000011U)));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[0U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r3[6U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[5U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[1U] 
        = ((vlSelfRef.stage5_tile_frequency__DOT__wire_r3[7U] 
            << 0x0000001eU) | (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[6U] 
                               >> 2U));
    vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[2U] 
        = (0x0001ffffU & (vlSelfRef.stage5_tile_frequency__DOT__wire_r3[7U] 
                          >> 2U));
    vlSelfRef.w5_domain_r0[0U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[0U];
    vlSelfRef.w5_domain_r0[1U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[1U];
    vlSelfRef.w5_domain_r0[2U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0[2U];
    vlSelfRef.w5_domain_r1[0U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[0U];
    vlSelfRef.w5_domain_r1[1U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[1U];
    vlSelfRef.w5_domain_r1[2U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1[2U];
    vlSelfRef.w5_domain_r2[0U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[0U];
    vlSelfRef.w5_domain_r2[1U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[1U];
    vlSelfRef.w5_domain_r2[2U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2[2U];
    vlSelfRef.stage5_tile_frequency__DOT__out_deadend = 0U;
    vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t = 0U;
    while (VL_GTS_III(32, 9U, vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t)) {
        if (((8U >= (0x0000000fU & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t)) 
             && (1U & ((IData)(vlSelfRef.stage5_tile_frequency__DOT__in_unassigned_tiles) 
                       >> (0x0000000fU & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t))))) {
            vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__cnt = 0U;
            vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__cnt = 0U;
            vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i = 0U;
            while (VL_GTS_III(32, 9U, vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)) {
                if (((8U >= (0x0000000fU & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)) 
                     && (1U & ((IData)(vlSelfRef.stage5_tile_frequency__DOT__in_unassigned_variables) 
                               >> (0x0000000fU & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))) {
                    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
                    vlSelf->stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__combined = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9749490672508886612ull);
                    vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__combined 
                        = (0x000001ffU & (((((0x50U 
                                              >= (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                              ? (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(9U) 
                                                       * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0
                                                   [
                                                   (((IData)(8U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))) 
                                                 | (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r0
                                                    [
                                                    (3U 
                                                     & (((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))
                                              : 0U) 
                                            | ((0x50U 
                                                >= 
                                                (0x0000007fU 
                                                 & ((IData)(9U) 
                                                    * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                                ? (
                                                   ((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1
                                                     [
                                                     (((IData)(8U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))) 
                                                   | (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r1
                                                      [
                                                      (3U 
                                                       & (((IData)(9U) 
                                                           * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))
                                                : 0U)) 
                                           | ((0x50U 
                                               >= (0x0000007fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                               ? ((
                                                   (0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2
                                                    [
                                                    (((IData)(8U) 
                                                      + 
                                                      (0x0000007fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))) 
                                                  | (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r2
                                                     [
                                                     (3U 
                                                      & (((IData)(9U) 
                                                          * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))
                                               : 0U)) 
                                          | ((0x50U 
                                              >= (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                              ? (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(9U) 
                                                       * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3
                                                   [
                                                   (((IData)(8U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))) 
                                                 | (vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3
                                                    [
                                                    (3U 
                                                     & (((IData)(9U) 
                                                         * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i))))
                                              : 0U)));
                    if (((8U >= (0x0000000fU & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t)) 
                         && (1U & ((IData)(vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__unnamedblk5__DOT__combined) 
                                   >> (0x0000000fU 
                                       & vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t))))) {
                        vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__cnt 
                            = ((IData)(1U) + vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__cnt);
                    }
                }
                vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i 
                    = ((IData)(1U) + vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i);
            }
            if ((0U == vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__cnt)) {
                vlSelfRef.stage5_tile_frequency__DOT__out_deadend = 1U;
            }
        }
        vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t 
            = ((IData)(1U) + vlSelfRef.stage5_tile_frequency__DOT__check_deadend__DOT__unnamedblk2__DOT__t);
    }
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec 
        = vlSelfRef.stage5_tile_frequency__DOT__in_unassigned_tiles;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (1U & (IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 1U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 2U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 3U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 4U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 5U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 6U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 7U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__vec) 
                    >> 8U)));
    stage5_tile_frequency__DOT____VlemCall_0__popcount_fn 
        = __Vfunc_stage5_tile_frequency__DOT__popcount_fn__4__count;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec 
        = vlSelfRef.stage5_tile_frequency__DOT__in_unassigned_variables;
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (1U & (IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 1U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 2U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 3U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 4U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 5U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 6U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 7U)));
    __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
        = (__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count 
           + (1U & ((IData)(__Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__vec) 
                    >> 8U)));
    stage5_tile_frequency__DOT____VlemCall_1__popcount_fn 
        = __Vfunc_stage5_tile_frequency__DOT__popcount_fn__5__count;
    if ((stage5_tile_frequency__DOT____VlemCall_0__popcount_fn 
         != stage5_tile_frequency__DOT____VlemCall_1__popcount_fn)) {
        vlSelfRef.stage5_tile_frequency__DOT__out_deadend = 1U;
    }
    vlSelfRef.w5_domain_r3[0U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[0U];
    vlSelfRef.w5_domain_r3[1U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[1U];
    vlSelfRef.w5_domain_r3[2U] = vlSelfRef.stage5_tile_frequency__DOT__out_domain_r3[2U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[0U] 
        = vlSelfRef.w5_domain_r0[0U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[1U] 
        = vlSelfRef.w5_domain_r0[1U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[2U] 
        = vlSelfRef.w5_domain_r0[2U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[0U] 
        = vlSelfRef.w5_domain_r1[0U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[1U] 
        = vlSelfRef.w5_domain_r1[1U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[2U] 
        = vlSelfRef.w5_domain_r1[2U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[0U] 
        = vlSelfRef.w5_domain_r2[0U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[1U] 
        = vlSelfRef.w5_domain_r2[1U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[2U] 
        = vlSelfRef.w5_domain_r2[2U];
    vlSelfRef.w5_deadend = vlSelfRef.stage5_tile_frequency__DOT__out_deadend;
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[0U] 
        = vlSelfRef.w5_domain_r3[0U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[1U] 
        = vlSelfRef.w5_domain_r3[1U];
    vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[2U] 
        = vlSelfRef.w5_domain_r3[2U];
    vlSelfRef.stage6_singleton_detection__DOT__out_unassignedVariables 
        = vlSelfRef.stage6_singleton_detection__DOT__in_unassignedVariables;
    vlSelfRef.stage6_singleton_detection__DOT__out_unassignedTiles 
        = vlSelfRef.stage6_singleton_detection__DOT__in_unassignedTiles;
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[0U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[0U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[1U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[1U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[2U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0[2U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[0U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[0U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[1U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[1U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[2U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1[2U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[0U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[0U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[1U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[1U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[2U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2[2U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[0U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[0U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[1U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[1U];
    vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[2U] 
        = vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3[2U];
    vlSelfRef.stage6_singleton_detection__DOT__out_singleton = 0U;
    vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v = 0U;
    while (VL_GTS_III(32, 9U, vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)) {
        if (((8U >= (0x0000000fU & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)) 
             && (1U & ((IData)(vlSelfRef.stage6_singleton_detection__DOT__in_unassignedVariables) 
                       >> (0x0000000fU & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) {
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
            vlSelf->stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13453519946834687628ull);
            vlSelf->stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2490805870949745100ull);
            vlSelf->stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16214943045022551740ull);
            vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined 
                = (0x000001ffU & (((((0x50U >= (0x0000007fU 
                                                & ((IData)(9U) 
                                                   * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                      ? (((0U == (0x0000001fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                           ? 0U : (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0
                                                   [
                                                   (((IData)(8U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                         | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0
                                            [(3U & 
                                              (((IData)(9U) 
                                                * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                               >> 5U))] 
                                            >> (0x0000001fU 
                                                & ((IData)(9U) 
                                                   * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))
                                      : 0U) | ((0x50U 
                                                >= 
                                                (0x0000007fU 
                                                 & ((IData)(9U) 
                                                    * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                ? (
                                                   ((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1
                                                     [
                                                     (((IData)(8U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                                   | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1
                                                      [
                                                      (3U 
                                                       & (((IData)(9U) 
                                                           * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))
                                                : 0U)) 
                                   | ((0x50U >= (0x0000007fU 
                                                 & ((IData)(9U) 
                                                    * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                       ? (((0U == (0x0000001fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                            ? 0U : 
                                           (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2
                                            [(((IData)(8U) 
                                               + (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                              >> 5U)] 
                                            << ((IData)(0x00000020U) 
                                                - (0x0000001fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                          | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2
                                             [(3U & 
                                               (((IData)(9U) 
                                                 * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                >> 5U))] 
                                             >> (0x0000001fU 
                                                 & ((IData)(9U) 
                                                    * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))
                                       : 0U)) | ((0x50U 
                                                  >= 
                                                  (0x0000007fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                  ? 
                                                 (((0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3
                                                    [
                                                    (((IData)(8U) 
                                                      + 
                                                      (0x0000007fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                                  | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r3
                                                     [
                                                     (3U 
                                                      & (((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))
                                                  : 0U)));
            if (((0U != (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)) 
                 & (0U == ((IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined) 
                           & ((IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined) 
                              - (IData)(1U)))))) {
                vlSelfRef.stage6_singleton_detection__DOT__out_singleton = 1U;
                vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id = 0U;
                vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p = 8U;
                while (VL_LTES_III(32, 0U, vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p)) {
                    if (((8U >= (0x0000000fU & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p)) 
                         && (1U & ((IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined) 
                                   >> (0x0000000fU 
                                       & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p))))) {
                        vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id 
                            = (0x0000000fU & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p);
                    }
                    vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p 
                        = (vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__p 
                           - (IData)(1U));
                }
                vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot 
                    = ((0U != ((0x50U >= (0x0000007fU 
                                          & ((IData)(9U) 
                                             * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                ? (0x000001ffU & ((
                                                   (0U 
                                                    == 
                                                    (0x0000001fU 
                                                     & ((IData)(9U) 
                                                        * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                    ? 0U
                                                    : 
                                                   (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0
                                                    [
                                                    (((IData)(8U) 
                                                      + 
                                                      (0x0000007fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                     >> 5U)] 
                                                    << 
                                                    ((IData)(0x00000020U) 
                                                     - 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                                  | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r0
                                                     [
                                                     (3U 
                                                      & (((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                         >> 5U))] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))))
                                : 0U)) ? 0U : ((0U 
                                                != 
                                                ((0x50U 
                                                  >= 
                                                  (0x0000007fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                  ? 
                                                 (0x000001ffU 
                                                  & (((0U 
                                                       == 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                       ? 0U
                                                       : 
                                                      (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1
                                                       [
                                                       (((IData)(8U) 
                                                         + 
                                                         (0x0000007fU 
                                                          & ((IData)(9U) 
                                                             * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                        >> 5U)] 
                                                       << 
                                                       ((IData)(0x00000020U) 
                                                        - 
                                                        (0x0000001fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                                     | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r1
                                                        [
                                                        (3U 
                                                         & (((IData)(9U) 
                                                             * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                            >> 5U))] 
                                                        >> 
                                                        (0x0000001fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))))
                                                  : 0U))
                                                ? 1U
                                                : (
                                                   (0U 
                                                    != 
                                                    ((0x50U 
                                                      >= 
                                                      (0x0000007fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                      ? 
                                                     (0x000001ffU 
                                                      & (((0U 
                                                           == 
                                                           (0x0000001fU 
                                                            & ((IData)(9U) 
                                                               * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))
                                                           ? 0U
                                                           : 
                                                          (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2
                                                           [
                                                           (((IData)(8U) 
                                                             + 
                                                             (0x0000007fU 
                                                              & ((IData)(9U) 
                                                                 * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                                                            >> 5U)] 
                                                           << 
                                                           ((IData)(0x00000020U) 
                                                            - 
                                                            (0x0000001fU 
                                                             & ((IData)(9U) 
                                                                * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) 
                                                         | (vlSelfRef.stage6_singleton_detection__DOT__in_domain_r2
                                                            [
                                                            (3U 
                                                             & (((IData)(9U) 
                                                                 * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v) 
                                                                >> 5U))] 
                                                            >> 
                                                            (0x0000001fU 
                                                             & ((IData)(9U) 
                                                                * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))))
                                                      : 0U))
                                                    ? 2U
                                                    : 3U)));
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h937e4710__0 
                    = ((0U == (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                        ? (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                        : 0U);
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_ha047ac56__0 
                    = ((1U == (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                        ? (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                        : 0U);
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h0983dcda__0 
                    = ((2U == (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                        ? (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                        : 0U);
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h8ffe20da__0 
                    = ((3U == (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__rot))
                        ? (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__combined)
                        : 0U);
                if (VL_LIKELY(((0x50U >= (0x0000007fU 
                                          & ((IData)(9U) 
                                             * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)))))) {
                    VL_ASSIGNSEL_WI(81, 9, (0x0000007fU 
                                            & ((IData)(9U) 
                                               * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)), vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0, vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h937e4710__0);
                    VL_ASSIGNSEL_WI(81, 9, (0x0000007fU 
                                            & ((IData)(9U) 
                                               * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)), vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1, vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_ha047ac56__0);
                    VL_ASSIGNSEL_WI(81, 9, (0x0000007fU 
                                            & ((IData)(9U) 
                                               * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)), vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2, vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h0983dcda__0);
                    VL_ASSIGNSEL_WI(81, 9, (0x0000007fU 
                                            & ((IData)(9U) 
                                               * vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v)), vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3, vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h8ffe20da__0);
                }
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h71e3b768__0 = 0U;
                if (VL_LIKELY(((8U >= (0x0000000fU 
                                       & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))))) {
                    vlSelfRef.stage6_singleton_detection__DOT__out_unassignedVariables 
                        = (((~ ((IData)(1U) << (0x0000000fU 
                                                & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))) 
                            & (IData)(vlSelfRef.stage6_singleton_detection__DOT__out_unassignedVariables)) 
                           | (0x01ffU & ((IData)(vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h71e3b768__0) 
                                         << (0x0000000fU 
                                             & vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v))));
                }
                vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h9e5ebd43__0 = 0U;
                if (VL_LIKELY(((8U >= (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id))))) {
                    vlSelfRef.stage6_singleton_detection__DOT__out_unassignedTiles 
                        = (((~ ((IData)(1U) << (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id))) 
                            & (IData)(vlSelfRef.stage6_singleton_detection__DOT__out_unassignedTiles)) 
                           | (0x01ffU & ((IData)(vlSelfRef.stage6_singleton_detection__DOT____Vlvbound_h9e5ebd43__0) 
                                         << (IData)(vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__unnamedblk3__DOT__tile_id))));
                }
            }
        }
        vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v 
            = ((IData)(1U) + vlSelfRef.stage6_singleton_detection__DOT__detect_singletons_and_deadend__DOT__unnamedblk2__DOT__v);
    }
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__vec 
        = vlSelfRef.stage6_singleton_detection__DOT__out_unassignedVariables;
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (1U & (IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 1U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 2U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 3U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 4U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 5U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 6U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 7U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__6__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__6__vec) 
                    >> 8U)));
    stage6_singleton_detection__DOT____VlemCall_0__popcount 
        = __Vfunc_stage6_singleton_detection__DOT__popcount__6__count;
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__vec 
        = vlSelfRef.stage6_singleton_detection__DOT__out_unassignedTiles;
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (1U & (IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 1U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 2U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 3U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 4U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 5U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 6U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 7U)));
    __Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
        = (__Vfunc_stage6_singleton_detection__DOT__popcount__7__count 
           + (1U & ((IData)(__Vfunc_stage6_singleton_detection__DOT__popcount__7__vec) 
                    >> 8U)));
    stage6_singleton_detection__DOT____VlemCall_1__popcount 
        = __Vfunc_stage6_singleton_detection__DOT__popcount__7__count;
    vlSelfRef.stage6_singleton_detection__DOT__out_deadend 
        = (stage6_singleton_detection__DOT____VlemCall_0__popcount 
           != stage6_singleton_detection__DOT____VlemCall_1__popcount);
    vlSelfRef.out_unassigned_variables = vlSelfRef.stage6_singleton_detection__DOT__out_unassignedVariables;
    vlSelfRef.out_unassigned_tiles = vlSelfRef.stage6_singleton_detection__DOT__out_unassignedTiles;
    vlSelfRef.out_domain_r0[0U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[0U];
    vlSelfRef.out_domain_r0[1U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[1U];
    vlSelfRef.out_domain_r0[2U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r0[2U];
    vlSelfRef.out_domain_r1[0U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[0U];
    vlSelfRef.out_domain_r1[1U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[1U];
    vlSelfRef.out_domain_r1[2U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r1[2U];
    vlSelfRef.out_domain_r2[0U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[0U];
    vlSelfRef.out_domain_r2[1U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[1U];
    vlSelfRef.out_domain_r2[2U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r2[2U];
    vlSelfRef.out_domain_r3[0U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[0U];
    vlSelfRef.out_domain_r3[1U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[1U];
    vlSelfRef.out_domain_r3[2U] = vlSelfRef.stage6_singleton_detection__DOT__out_domain_r3[2U];
    vlSelfRef.w6_deadend = vlSelfRef.stage6_singleton_detection__DOT__out_deadend;
    vlSelfRef.out_deadend = ((IData)(vlSelfRef.w1_deadend) 
                             | ((IData)(vlSelfRef.w2_deadend) 
                                | ((IData)(vlSelfRef.w3_deadend) 
                                   | ((IData)(vlSelfRef.w4_deadend) 
                                      | ((IData)(vlSelfRef.w5_deadend) 
                                         | (IData)(vlSelfRef.w6_deadend))))));
}
