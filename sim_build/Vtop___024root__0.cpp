// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                    (((((((0U 
                                                           != 
                                                           (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                              ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[0U]) 
                                                             | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[1U])) 
                                                            | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                               ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[2U]))) 
                                                          << 3U) 
                                                         | ((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[2U]))) 
                                                            << 2U)) 
                                                        | (((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[2U]))) 
                                                            << 1U) 
                                                           | (0U 
                                                              != 
                                                              (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[0U]) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[1U])) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[2U]))))) 
                                                       << 0x0000000cU) 
                                                      | (((((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[2U]))) 
                                                            << 3U) 
                                                           | ((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[2U]))) 
                                                              << 2U)) 
                                                          | (((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[2U]))) 
                                                              << 1U) 
                                                             | (0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[2U]))))) 
                                                         << 8U)) 
                                                     | ((((((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[2U]))) 
                                                            << 3U) 
                                                           | ((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[2U]))) 
                                                              << 2U)) 
                                                          | (((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[2U]))) 
                                                              << 1U) 
                                                             | (0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[2U]))))) 
                                                         << 4U) 
                                                        | ((((0U 
                                                              != 
                                                              (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[0U]) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[1U])) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[2U]))) 
                                                             << 3U) 
                                                            | ((0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[2U]))) 
                                                               << 2U)) 
                                                           | (((0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[2U]))) 
                                                               << 1U) 
                                                              | (0U 
                                                                 != 
                                                                 (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[0U]) 
                                                                   | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                      ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[1U])) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[2U])))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U];
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
        vlSelfRef.__VicoDidInit = 1U;
        vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000010ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000020ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000040ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000080ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000100ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000200ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000400ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000000800ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000001000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000002000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000004000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
        vlSelfRef.__VicoTriggered[0U] = (0x0000000000008000ULL 
                                         | vlSelfRef.__VicoTriggered[0U]);
    }
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
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
    } while ((2U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_top 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_colours_top;
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_right 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_colours_right;
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_colours_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_left 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_colours_left;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_left 
        = vlSelfRef.Brendan3_OneStep__DOT__w_elements_left;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__w_elements_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_right 
        = vlSelfRef.Brendan3_OneStep__DOT__w_elements_right;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_top 
        = vlSelfRef.Brendan3_OneStep__DOT__w_elements_top;
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__initial_game__DOT__out_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_colours_top 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_top;
    vlSelfRef.Brendan3_OneStep__DOT__w_load_colours_right 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_right;
    vlSelfRef.Brendan3_OneStep__DOT__w_load_colours_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__w_load_colours_left 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_colours_left;
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_load_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__loader__DOT__out_domain_r3[2U];
}

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_top 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_top;
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_right 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_right;
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_bottom 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_left 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_left;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_top 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_top;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_right 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_right;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_left 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_left;
}

void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h15189a87__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h15189a87__0 = 0;
    CData/*4:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab56d522__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab56d522__0 = 0;
    CData/*4:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_he875acff__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_he875acff__0 = 0;
    CData/*4:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h9bbc6fbf__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h9bbc6fbf__0 = 0;
    SData/*8:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hcc1878b4__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hcc1878b4__0 = 0;
    SData/*8:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hf559d4d4__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hf559d4d4__0 = 0;
    SData/*8:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hd46a6474__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hd46a6474__0 = 0;
    SData/*8:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h579c9f26__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h579c9f26__0 = 0;
    CData/*0:0*/ Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab6deb74__0;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab6deb74__0 = 0;
    // Body
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_unassigned_tiles 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_unassigned_tiles;
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_prop1_unassigned_variables 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_unassigned_variables;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_unassigned_tiles 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_unassigned_tiles;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_unassigned_variables 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_unassigned_variables;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_unassignedVariables 
        = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_unassigned_variables;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_unassignedVariables 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_unassignedVariables;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__singletons 
        = (0x000001ffU & (~ (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__in_unassignedVariables)));
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 9U, vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT____Vlvbound_hfd3c7f52__0 
            = (0x0000003fU & (((VL_COUNTONES_I(((0x50U 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                 ? 
                                                (0x000001ffU 
                                                 & (((0U 
                                                      == 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                      ? 0U
                                                      : 
                                                     (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r0
                                                      [
                                                      (((IData)(8U) 
                                                        + 
                                                        (0x0000007fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))) 
                                                       >> 5U)] 
                                                      << 
                                                      ((IData)(0x00000020U) 
                                                       - 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))))) 
                                                    | (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r0
                                                       [
                                                       (3U 
                                                        & (((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i) 
                                                           >> 5U))] 
                                                       >> 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))))
                                                 : 0U)) 
                                + VL_COUNTONES_I(((0x50U 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(9U) 
                                                       * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                   ? 
                                                  (0x000001ffU 
                                                   & (((0U 
                                                        == 
                                                        (0x0000001fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                        ? 0U
                                                        : 
                                                       (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r1
                                                        [
                                                        (((IData)(8U) 
                                                          + 
                                                          (0x0000007fU 
                                                           & ((IData)(9U) 
                                                              * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))) 
                                                         >> 5U)] 
                                                        << 
                                                        ((IData)(0x00000020U) 
                                                         - 
                                                         (0x0000001fU 
                                                          & ((IData)(9U) 
                                                             * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))))) 
                                                      | (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r1
                                                         [
                                                         (3U 
                                                          & (((IData)(9U) 
                                                              * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i) 
                                                             >> 5U))] 
                                                         >> 
                                                         (0x0000001fU 
                                                          & ((IData)(9U) 
                                                             * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))))
                                                   : 0U))) 
                               + VL_COUNTONES_I(((0x50U 
                                                  >= 
                                                  (0x0000007fU 
                                                   & ((IData)(9U) 
                                                      * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                  ? 
                                                 (0x000001ffU 
                                                  & (((0U 
                                                       == 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                       ? 0U
                                                       : 
                                                      (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r2
                                                       [
                                                       (((IData)(8U) 
                                                         + 
                                                         (0x0000007fU 
                                                          & ((IData)(9U) 
                                                             * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))) 
                                                        >> 5U)] 
                                                       << 
                                                       ((IData)(0x00000020U) 
                                                        - 
                                                        (0x0000001fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))))) 
                                                     | (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r2
                                                        [
                                                        (3U 
                                                         & (((IData)(9U) 
                                                             * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i) 
                                                            >> 5U))] 
                                                        >> 
                                                        (0x0000001fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))))
                                                  : 0U))) 
                              + VL_COUNTONES_I(((0x50U 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                 ? 
                                                (0x000001ffU 
                                                 & (((0U 
                                                      == 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))
                                                      ? 0U
                                                      : 
                                                     (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r3
                                                      [
                                                      (((IData)(8U) 
                                                        + 
                                                        (0x0000007fU 
                                                         & ((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))) 
                                                       >> 5U)] 
                                                      << 
                                                      ((IData)(0x00000020U) 
                                                       - 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i))))) 
                                                    | (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__in_domain_r3
                                                       [
                                                       (3U 
                                                        & (((IData)(9U) 
                                                            * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i) 
                                                           >> 5U))] 
                                                       >> 
                                                       (0x0000001fU 
                                                        & ((IData)(9U) 
                                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))))
                                                 : 0U))));
        if (VL_LIKELY(((0x35U >= (0x0000003fU & ((IData)(6U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))))) {
            vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__out_pop_count 
                = (((~ (0x000000000000003fULL << (0x0000003fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))) 
                    & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__out_pop_count) 
                   | (0x003fffffffffffffULL & ((QData)((IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT____Vlvbound_hfd3c7f52__0)) 
                                               << (0x0000003fU 
                                                   & ((IData)(6U) 
                                                      * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i)))));
        }
        vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__compute_domain_sizes__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_singletons 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__singletons;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__pop_count 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__domain_sizes_inst__DOT__out_pop_count;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__expanded 
        = (0x000001ffU & (((VL_SHIFTR_III(9,9,32, (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_singletons), 3U) 
                            | VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_singletons), 3U)) 
                           | (0x00dbU & VL_SHIFTR_III(9,9,32, (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_singletons), 1U))) 
                          | (0x01b6U & VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_singletons), 1U))));
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__out_candidates 
        = ((IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__expanded) 
           & (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__in_unassignedVariables));
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_pop_count 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__pop_count;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__in_pop_count 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__pop_count;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__candidates 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__expand_inst__DOT__out_candidates;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_candidates 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__candidates;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__in_candidates 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__candidates;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__out_min_count = 0x3fU;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 9U, vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)) {
        if ((((8U >= (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)) 
              && (1U & ((IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__in_candidates) 
                        >> (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)))) 
             & (((0x35U >= (0x0000003fU & ((IData)(6U) 
                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)))
                  ? (0x0000003fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__in_pop_count 
                                            >> (0x0000003fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)))))
                  : 0U) < (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__out_min_count)))) {
            vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__out_min_count 
                = ((0x35U >= (0x0000003fU & ((IData)(6U) 
                                             * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)))
                    ? (0x0000003fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__in_pop_count 
                                              >> (0x0000003fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i)))))
                    : 0U);
        }
        vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__find_minimum_domain_size__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_count 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_domain_inst__DOT__out_min_count;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_min_count 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__min_count;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_next_var = 0U;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_valid = 0U;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i = 8U;
    while (VL_LTES_III(32, 0U, vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i)) {
        if ((((8U >= (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i)) 
              && (1U & ((IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_candidates) 
                        >> (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i)))) 
             & (((0x35U >= (0x0000003fU & ((IData)(6U) 
                                           * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i)))
                  ? (0x0000003fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_pop_count 
                                            >> (0x0000003fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i)))))
                  : 0U) == (IData)(vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__in_min_count)))) {
            vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_next_var 
                = (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i);
            vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_valid = 1U;
        }
        vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i 
            = (vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__select_next_variable__DOT__unnamedblk1__DOT__i 
               - (IData)(1U));
    }
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__out_valid 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_valid;
    vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__out_next_var 
        = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__select_inst__DOT__out_next_var;
    vlSelfRef.Brendan3_OneStep__DOT__w_valid = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__out_valid;
    vlSelfRef.Brendan3_OneStep__DOT__w_next_var = vlSelfRef.Brendan3_OneStep__DOT__choose__DOT__out_next_var;
    vlSelfRef.Brendan3_OneStep__DOT__out_valid = vlSelfRef.Brendan3_OneStep__DOT__w_valid;
    vlSelfRef.Brendan3_OneStep__DOT__out_next_var = vlSelfRef.Brendan3_OneStep__DOT__w_next_var;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_variableId 
        = vlSelfRef.Brendan3_OneStep__DOT__w_next_var;
    vlSelfRef.Brendan3_OneStep__DOT__w_combined_domain 
        = (0x000001ffU & (((((0x50U >= (0x0000007fU 
                                        & ((IData)(9U) 
                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(9U) 
                                             * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                   ? 0U : (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0
                                           [(((IData)(8U) 
                                              + (0x0000007fU 
                                                 & ((IData)(9U) 
                                                    * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(9U) 
                                                     * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))) 
                                 | (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0
                                    [(3U & (((IData)(9U) 
                                             * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(9U) 
                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))
                              : 0U) | ((0x50U >= (0x0000007fU 
                                                  & ((IData)(9U) 
                                                     * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                        ? (((0U == 
                                             (0x0000001fU 
                                              & ((IData)(9U) 
                                                 * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                             ? 0U : 
                                            (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1
                                             [(((IData)(8U) 
                                                + (0x0000007fU 
                                                   & ((IData)(9U) 
                                                      * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))) 
                                               >> 5U)] 
                                             << ((IData)(0x00000020U) 
                                                 - 
                                                 (0x0000001fU 
                                                  & ((IData)(9U) 
                                                     * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))) 
                                           | (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1
                                              [(3U 
                                                & (((IData)(9U) 
                                                    * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                   >> 5U))] 
                                              >> (0x0000001fU 
                                                  & ((IData)(9U) 
                                                     * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))
                                        : 0U)) | ((0x50U 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(9U) 
                                                       * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(9U) 
                                                         * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2
                                                     [
                                                     (((IData)(8U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(9U) 
                                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))) 
                                                   | (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2
                                                      [
                                                      (3U 
                                                       & (((IData)(9U) 
                                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(9U) 
                                                          * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))
                                                   : 0U)) 
                          | ((0x50U >= (0x0000007fU 
                                        & ((IData)(9U) 
                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(9U) 
                                             * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var))))
                                   ? 0U : (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3
                                           [(((IData)(8U) 
                                              + (0x0000007fU 
                                                 & ((IData)(9U) 
                                                    * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(9U) 
                                                     * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))) 
                                 | (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r3
                                    [(3U & (((IData)(9U) 
                                             * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(9U) 
                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)))))
                              : 0U)));
    vlSelfRef.Brendan3_OneStep__DOT__w_tile_id = 0U;
    vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t = 8U;
    while (VL_LTES_III(32, 0U, vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t)) {
        if (((8U >= (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t)) 
             && (1U & ((IData)(vlSelfRef.Brendan3_OneStep__DOT__w_combined_domain) 
                       >> (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t))))) {
            vlSelfRef.Brendan3_OneStep__DOT__w_tile_id 
                = (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t);
        }
        vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t 
            = (vlSelfRef.Brendan3_OneStep__DOT__select_tile_and_rotation__DOT__unnamedblk1__DOT__t 
               - (IData)(1U));
    }
    vlSelfRef.Brendan3_OneStep__DOT__w_rotation = (
                                                   ((0x50U 
                                                     >= 
                                                     (0x0000007fU 
                                                      & (((IData)(9U) 
                                                          * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                         + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)))) 
                                                    && (1U 
                                                        & (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r0
                                                           [
                                                           (3U 
                                                            & ((((IData)(9U) 
                                                                 * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                                + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)) 
                                                               >> 5U))] 
                                                           >> 
                                                           (0x0000001fU 
                                                            & (((IData)(9U) 
                                                                * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                               + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id))))))
                                                    ? 0U
                                                    : 
                                                   (((0x50U 
                                                      >= 
                                                      (0x0000007fU 
                                                       & (((IData)(9U) 
                                                           * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                          + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)))) 
                                                     && (1U 
                                                         & (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r1
                                                            [
                                                            (3U 
                                                             & ((((IData)(9U) 
                                                                  * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                                 + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)) 
                                                                >> 5U))] 
                                                            >> 
                                                            (0x0000001fU 
                                                             & (((IData)(9U) 
                                                                 * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                                + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id))))))
                                                     ? 1U
                                                     : 
                                                    (((0x50U 
                                                       >= 
                                                       (0x0000007fU 
                                                        & (((IData)(9U) 
                                                            * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                           + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)))) 
                                                      && (1U 
                                                          & (vlSelfRef.Brendan3_OneStep__DOT__w_prop1_domain_r2
                                                             [
                                                             (3U 
                                                              & ((((IData)(9U) 
                                                                   * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                                  + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id)) 
                                                                 >> 5U))] 
                                                             >> 
                                                             (0x0000001fU 
                                                              & (((IData)(9U) 
                                                                  * (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_next_var)) 
                                                                 + (IData)(vlSelfRef.Brendan3_OneStep__DOT__w_tile_id))))))
                                                      ? 2U
                                                      : 3U)));
    vlSelfRef.out_valid = vlSelfRef.Brendan3_OneStep__DOT__out_valid;
    vlSelfRef.out_next_var = vlSelfRef.Brendan3_OneStep__DOT__out_next_var;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_variableId;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation 
        = vlSelfRef.Brendan3_OneStep__DOT__w_rotation;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_tileId 
        = vlSelfRef.Brendan3_OneStep__DOT__w_tile_id;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_unassigned_variables 
        = ((~ VL_SHIFTL_III(9,9,32, (IData)(1U), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)) 
           & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_unassigned_variables));
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_tileId;
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_unassigned_variables 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_unassigned_variables;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_unassigned_tiles 
        = ((~ VL_SHIFTL_III(9,9,32, (IData)(1U), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)) 
           & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_unassigned_tiles));
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask = 0U;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab6deb74__0 = 1U;
    if ((8U >= (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid))) 
                & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask)) 
               | (0x01ffU & ((IData)(Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab6deb74__0) 
                             << (0x0000000fU & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid))));
    }
    if ((0U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))) {
        if ((0x2cU >= (0x0000003fU & ((IData)(5U) * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_top 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_right 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_bottom 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_left 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
        } else {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                = (0x0000001fU & 0U);
        }
        Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h579c9f26__0 
            = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask;
    } else {
        if ((1U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))) {
            if ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))) {
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_left 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_top 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_right 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_bottom 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            } else {
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                    = (0x0000001fU & 0U);
            }
        } else if ((2U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))) {
            if ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))) {
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_bottom 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_left 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_top 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                    = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_right 
                                              >> (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            } else {
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                    = (0x0000001fU & 0U);
                vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                    = (0x0000001fU & 0U);
            }
        } else if ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                             * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_right 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_bottom 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_left 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                = (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_elements_top 
                                          >> (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tid)))));
        } else {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom 
                = (0x0000001fU & 0U);
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left 
                = (0x0000001fU & 0U);
        }
        Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h579c9f26__0 = 0U;
    }
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_top;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_right;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_left;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h9bbc6fbf__0 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_he875acff__0 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab56d522__0 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom;
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h15189a87__0 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left;
    if ((0x2cU >= (0x0000003fU & ((IData)(5U) * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top 
            = (((~ (0x000000000000001fULL << (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) 
                & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top) 
               | (0x00001fffffffffffULL & ((QData)((IData)(Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h9bbc6fbf__0)) 
                                           << (0x0000003fU 
                                               & ((IData)(5U) 
                                                  * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))));
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right 
            = (((~ (0x000000000000001fULL << (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) 
                & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right) 
               | (0x00001fffffffffffULL & ((QData)((IData)(Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_he875acff__0)) 
                                           << (0x0000003fU 
                                               & ((IData)(5U) 
                                                  * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))));
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom 
            = (((~ (0x000000000000001fULL << (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) 
                & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom) 
               | (0x00001fffffffffffULL & ((QData)((IData)(Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hab56d522__0)) 
                                           << (0x0000003fU 
                                               & ((IData)(5U) 
                                                  * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))));
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left 
            = (((~ (0x000000000000001fULL << (0x0000003fU 
                                              & ((IData)(5U) 
                                                 * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) 
                & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left) 
               | (0x00001fffffffffffULL & ((QData)((IData)(Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h15189a87__0)) 
                                           << (0x0000003fU 
                                               & ((IData)(5U) 
                                                  * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))));
    }
    if ((2U > VL_MODDIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h608a81e7__0 
            = (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * ((IData)(1U) 
                                             + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
                 ? (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_left 
                            >> (0x0000003fU & ((IData)(5U) 
                                               * ((IData)(1U) 
                                                  + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))))
                 : 0U) & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_right));
        if ((0x2cU >= (0x0000003fU & ((IData)(5U) * 
                                      ((IData)(1U) 
                                       + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left 
                = (((~ (0x000000000000001fULL << (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     ((IData)(1U) 
                                                      + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))) 
                    & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left) 
                   | (0x00001fffffffffffULL & ((QData)((IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h608a81e7__0)) 
                                               << (0x0000003fU 
                                                   & ((IData)(5U) 
                                                      * 
                                                      ((IData)(1U) 
                                                       + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))));
        }
    }
    if ((2U > VL_DIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h989d9e08__0 
            = (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * ((IData)(3U) 
                                             + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
                 ? (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_top 
                            >> (0x0000003fU & ((IData)(5U) 
                                               * ((IData)(3U) 
                                                  + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))))
                 : 0U) & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_bottom));
        if ((0x2cU >= (0x0000003fU & ((IData)(5U) * 
                                      ((IData)(3U) 
                                       + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top 
                = (((~ (0x000000000000001fULL << (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     ((IData)(3U) 
                                                      + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))) 
                    & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top) 
                   | (0x00001fffffffffffULL & ((QData)((IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h989d9e08__0)) 
                                               << (0x0000003fU 
                                                   & ((IData)(5U) 
                                                      * 
                                                      ((IData)(3U) 
                                                       + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))));
        }
    }
    if ((0U < VL_MODDIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h7930cb7c__0 
            = (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                             - (IData)(1U)))))
                 ? (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_right 
                            >> (0x0000003fU & ((IData)(5U) 
                                               * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                  - (IData)(1U))))))
                 : 0U) & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_left));
        if ((0x2cU >= (0x0000003fU & ((IData)(5U) * 
                                      (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                       - (IData)(1U)))))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right 
                = (((~ (0x000000000000001fULL << (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                      - (IData)(1U)))))) 
                    & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right) 
                   | (0x00001fffffffffffULL & ((QData)((IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h7930cb7c__0)) 
                                               << (0x0000003fU 
                                                   & ((IData)(5U) 
                                                      * 
                                                      (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                       - (IData)(1U)))))));
        }
    }
    if ((0U < VL_DIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h3e832cfe__0 
            = (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                          * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                             - (IData)(3U)))))
                 ? (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_bottom 
                            >> (0x0000003fU & ((IData)(5U) 
                                               * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                  - (IData)(3U))))))
                 : 0U) & (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__piece_top));
        if ((0x2cU >= (0x0000003fU & ((IData)(5U) * 
                                      (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                       - (IData)(3U)))))) {
            vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom 
                = (((~ (0x000000000000001fULL << (0x0000003fU 
                                                  & ((IData)(5U) 
                                                     * 
                                                     (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                      - (IData)(3U)))))) 
                    & vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom) 
                   | (0x00001fffffffffffULL & ((QData)((IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h3e832cfe__0)) 
                                               << (0x0000003fU 
                                                   & ((IData)(5U) 
                                                      * 
                                                      (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                       - (IData)(3U)))))));
        }
    }
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colours_changed = 0U;
    if (((2U > VL_MODDIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U))) 
         & (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                       * ((IData)(1U) 
                                          + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
              ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left 
                                        >> (0x0000003fU 
                                            & ((IData)(5U) 
                                               * ((IData)(1U) 
                                                  + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))))
              : 0U) != ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                                  * 
                                                  ((IData)(1U) 
                                                   + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
                         ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_left 
                                                   >> 
                                                   (0x0000003fU 
                                                    & ((IData)(5U) 
                                                       * 
                                                       ((IData)(1U) 
                                                        + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))))
                         : 0U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colours_changed = 1U;
    }
    if (((2U > VL_DIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U))) 
         & (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                       * ((IData)(3U) 
                                          + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
              ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top 
                                        >> (0x0000003fU 
                                            & ((IData)(5U) 
                                               * ((IData)(3U) 
                                                  + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))))
              : 0U) != ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                                  * 
                                                  ((IData)(3U) 
                                                   + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))
                         ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_top 
                                                   >> 
                                                   (0x0000003fU 
                                                    & ((IData)(5U) 
                                                       * 
                                                       ((IData)(3U) 
                                                        + vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid))))))
                         : 0U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colours_changed = 1U;
    }
    if (((0U < VL_MODDIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U))) 
         & (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                       * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                          - (IData)(1U)))))
              ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right 
                                        >> (0x0000003fU 
                                            & ((IData)(5U) 
                                               * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                  - (IData)(1U)))))))
              : 0U) != ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                                  * 
                                                  (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                   - (IData)(1U)))))
                         ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_right 
                                                   >> 
                                                   (0x0000003fU 
                                                    & ((IData)(5U) 
                                                       * 
                                                       (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                        - (IData)(1U)))))))
                         : 0U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colours_changed = 1U;
    }
    if (((0U < VL_DIV_III(32, vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid, (IData)(3U))) 
         & (((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                       * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                          - (IData)(3U)))))
              ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom 
                                        >> (0x0000003fU 
                                            & ((IData)(5U) 
                                               * (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                  - (IData)(3U)))))))
              : 0U) != ((0x2cU >= (0x0000003fU & ((IData)(5U) 
                                                  * 
                                                  (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                   - (IData)(3U)))))
                         ? (0x0000001fU & (IData)((vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_bottom 
                                                   >> 
                                                   (0x0000003fU 
                                                    & ((IData)(5U) 
                                                       * 
                                                       (vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid 
                                                        - (IData)(3U)))))))
                         : 0U)))) {
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colours_changed = 1U;
    }
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_unassigned_tiles 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_unassigned_tiles;
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r2[2U];
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hf559d4d4__0 
        = ((2U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))
            ? (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask)
            : 0U);
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r3[2U];
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hcc1878b4__0 
        = ((3U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))
            ? (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask)
            : 0U);
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r1[2U];
    Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hd46a6474__0 
        = ((1U == (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_rotation))
            ? (IData)(vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__tile_mask)
            : 0U);
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_domain_r0[2U];
    if ((0x50U >= (0x0000007fU & ((IData)(9U) * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)))) {
        VL_ASSIGNSEL_WI(81, 9, (0x0000007fU & ((IData)(9U) 
                                               * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2, Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hf559d4d4__0);
        VL_ASSIGNSEL_WI(81, 9, (0x0000007fU & ((IData)(9U) 
                                               * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3, Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hcc1878b4__0);
        VL_ASSIGNSEL_WI(81, 9, (0x0000007fU & ((IData)(9U) 
                                               * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1, Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_hd46a6474__0);
        VL_ASSIGNSEL_WI(81, 9, (0x0000007fU & ((IData)(9U) 
                                               * vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__vid)), vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0, Brendan3_OneStep__DOT__assign_inst__DOT____Vlvbound_h579c9f26__0);
    }
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_colours_top 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_top;
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_colours_right 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_right;
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_colours_bottom 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_colours_left 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_colour_left;
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r2[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r2[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r2[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r3[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r3[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r3[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r1[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r1[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r1[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r0[0U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r0[1U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__w_assign_domain_r0[2U] 
        = vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__out_domain_r0[2U];
}

void Vtop___024root___ico_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Brendan3_OneStep__DOT__out_colours_top 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_top;
    vlSelfRef.Brendan3_OneStep__DOT__out_colours_right 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_right;
    vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_bottom;
    vlSelfRef.Brendan3_OneStep__DOT__out_colours_left 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_left;
    vlSelfRef.Brendan3_OneStep__DOT__out_changed = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_changed;
    vlSelfRef.out_colours_top = vlSelfRef.Brendan3_OneStep__DOT__out_colours_top;
    vlSelfRef.out_colours_right = vlSelfRef.Brendan3_OneStep__DOT__out_colours_right;
    vlSelfRef.out_colours_bottom = vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom;
    vlSelfRef.out_colours_left = vlSelfRef.Brendan3_OneStep__DOT__out_colours_left;
    vlSelfRef.out_changed = vlSelfRef.Brendan3_OneStep__DOT__out_changed;
}

void Vtop___024root___ico_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.Brendan3_OneStep__DOT__out_unassigned_variables 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_unassigned_variables;
    vlSelfRef.Brendan3_OneStep__DOT__out_unassigned_tiles 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_unassigned_tiles;
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r0[0U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r0[1U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r0[2U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r1[0U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r1[1U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r1[2U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r2[0U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r2[1U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r2[2U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r3[0U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r3[1U];
    vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_domain_r3[2U];
    vlSelfRef.Brendan3_OneStep__DOT__out_deadend = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_deadend;
    vlSelfRef.out_unassigned_variables = vlSelfRef.Brendan3_OneStep__DOT__out_unassigned_variables;
    vlSelfRef.out_unassigned_tiles = vlSelfRef.Brendan3_OneStep__DOT__out_unassigned_tiles;
    vlSelfRef.out_domain_r0[0U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[0U];
    vlSelfRef.out_domain_r0[1U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[1U];
    vlSelfRef.out_domain_r0[2U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r0[2U];
    vlSelfRef.out_domain_r1[0U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[0U];
    vlSelfRef.out_domain_r1[1U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[1U];
    vlSelfRef.out_domain_r1[2U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r1[2U];
    vlSelfRef.out_domain_r2[0U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[0U];
    vlSelfRef.out_domain_r2[1U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[1U];
    vlSelfRef.out_domain_r2[2U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r2[2U];
    vlSelfRef.out_domain_r3[0U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[0U];
    vlSelfRef.out_domain_r3[1U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[1U];
    vlSelfRef.out_domain_r3[2U] = vlSelfRef.Brendan3_OneStep__DOT__out_domain_r3[2U];
    vlSelfRef.out_deadend = vlSelfRef.Brendan3_OneStep__DOT__out_deadend;
}

void Vtop_PropagateOnce__N3_V9_C5___ico_sequent__TOP__Brendan3_OneStep__DOT__prop2__0(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_sequent__TOP__Brendan3_OneStep__DOT__prop1__0(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__0(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__1(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__2(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__0(Vtop_PropagateOnce__N3_V9_C5* vlSelf);
void Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__3(Vtop_PropagateOnce__N3_V9_C5* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[1U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_PropagateOnce__N3_V9_C5___ico_sequent__TOP__Brendan3_OneStep__DOT__prop2__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
        Vtop_PropagateOnce__N3_V9_C5___ico_sequent__TOP__Brendan3_OneStep__DOT__prop1__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
        vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_top 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_top;
        vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_right 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_right;
        vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_bottom 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_bottom;
        vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_left 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.out_colours_left;
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_top 
            = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_top;
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_right 
            = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_right;
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_bottom 
            = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_bottom;
        vlSelfRef.Brendan3_OneStep__DOT__assign_inst__DOT__in_colour_left 
            = vlSelfRef.Brendan3_OneStep__DOT__w_prop1_colours_left;
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x000000000000000fULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x00000000000000f0ULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__1((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x00000000000000ffULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__2((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
        Vtop___024root___ico_comb__TOP__0(vlSelf);
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_top 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_top;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_right 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_right;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_bottom;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_left 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_left;
        vlSelfRef.Brendan3_OneStep__DOT__out_changed 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_changed;
        vlSelfRef.out_colours_top = vlSelfRef.Brendan3_OneStep__DOT__out_colours_top;
        vlSelfRef.out_colours_right = vlSelfRef.Brendan3_OneStep__DOT__out_colours_right;
        vlSelfRef.out_colours_bottom = vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom;
        vlSelfRef.out_colours_left = vlSelfRef.Brendan3_OneStep__DOT__out_colours_left;
        vlSelfRef.out_changed = vlSelfRef.Brendan3_OneStep__DOT__out_changed;
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x0000000000000fffULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x000000000000f0ffULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__1((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
    }
    if (((1ULL & vlSelfRef.__VicoTriggered[1U]) | (0x000000000000ffffULL 
                                                   & vlSelfRef.__VicoTriggered[0U]))) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__3((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
        Vtop___024root___ico_comb__TOP__2(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
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

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((((0U 
                                                           != 
                                                           (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                              ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[0U]) 
                                                             | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[1U])) 
                                                            | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                               ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[2U]))) 
                                                          << 3U) 
                                                         | ((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[2U]))) 
                                                            << 2U)) 
                                                        | (((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[2U]))) 
                                                            << 1U) 
                                                           | (0U 
                                                              != 
                                                              (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[0U]) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[1U])) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[2U]))))) 
                                                       << 0x0000000cU) 
                                                      | (((((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[2U]))) 
                                                            << 3U) 
                                                           | ((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[2U]))) 
                                                              << 2U)) 
                                                          | (((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[2U]))) 
                                                              << 1U) 
                                                             | (0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[2U]))))) 
                                                         << 8U)) 
                                                     | ((((((0U 
                                                             != 
                                                             (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[0U]) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[1U])) 
                                                              | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[2U]))) 
                                                            << 3U) 
                                                           | ((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[2U]))) 
                                                              << 2U)) 
                                                          | (((0U 
                                                               != 
                                                               (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[0U]) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[1U])) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[2U]))) 
                                                              << 1U) 
                                                             | (0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[2U]))))) 
                                                         << 4U) 
                                                        | ((((0U 
                                                              != 
                                                              (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[0U]) 
                                                                | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[1U])) 
                                                               | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[2U]))) 
                                                             << 3U) 
                                                            | ((0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[2U]))) 
                                                               << 2U)) 
                                                           | (((0U 
                                                                != 
                                                                (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[0U]) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[1U])) 
                                                                 | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[2U]))) 
                                                               << 1U) 
                                                              | (0U 
                                                                 != 
                                                                 (((vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[0U]) 
                                                                   | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U] 
                                                                      ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[1U])) 
                                                                  | (vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[2U])))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop1__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop1.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__0__KET____DOT__stage__DOT__in_domain_r3[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r0[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r1[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r2[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[0U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[1U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__Brendan3_OneStep__DOT__prop2__stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3__1[2U] 
        = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.stage5_tile_frequency__DOT__gen_stage__BRA__1__KET____DOT__stage__DOT__in_domain_r3[2U];
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered[0U] = (1ULL | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (2ULL | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000010ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000020ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000040ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000080ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000100ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000200ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000400ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000000800ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000001000ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000002000ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000004000ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
        vlSelfRef.__VactTriggered[0U] = (0x0000000000008000ULL 
                                         | vlSelfRef.__VactTriggered[0U]);
    }
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000fULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
    }
    if ((0x00000000000000f0ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__1((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
    }
    if ((0x00000000000000ffULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__2((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop1));
        Vtop___024root___ico_comb__TOP__0(vlSelf);
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_top 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_top;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_right 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_right;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_bottom;
        vlSelfRef.Brendan3_OneStep__DOT__out_colours_left 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_colours_left;
        vlSelfRef.Brendan3_OneStep__DOT__out_changed 
            = vlSymsp->TOP__Brendan3_OneStep__DOT__prop2.out_changed;
        vlSelfRef.out_colours_top = vlSelfRef.Brendan3_OneStep__DOT__out_colours_top;
        vlSelfRef.out_colours_right = vlSelfRef.Brendan3_OneStep__DOT__out_colours_right;
        vlSelfRef.out_colours_bottom = vlSelfRef.Brendan3_OneStep__DOT__out_colours_bottom;
        vlSelfRef.out_colours_left = vlSelfRef.Brendan3_OneStep__DOT__out_colours_left;
        vlSelfRef.out_changed = vlSelfRef.Brendan3_OneStep__DOT__out_changed;
    }
    if ((0x0000000000000fffULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__0((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
    }
    if ((0x000000000000f0ffULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop1__1((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
    }
    if ((0x000000000000ffffULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop_PropagateOnce__N3_V9_C5___ico_comb__TOP__Brendan3_OneStep__DOT__prop2__3((&vlSymsp->TOP__Brendan3_OneStep__DOT__prop2));
        Vtop___024root___ico_comb__TOP__2(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/parallels/e2_fpga/rtl/Brendan3_OneStep.sv", 18, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/parallels/e2_fpga/rtl/Brendan3_OneStep.sv", 18, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/parallels/e2_fpga/rtl/Brendan3_OneStep.sv", 18, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
