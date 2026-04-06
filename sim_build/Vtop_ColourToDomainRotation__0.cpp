// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__0__KET____DOT__top_left__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__0__KET____DOT__top_left__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r1[0U]);
    vlSelfRef.left = (0x0000003fU & vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U]);
    vlSelfRef.bottom = (0x0000003fU & vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U]);
    vlSelfRef.right = (0x0000003fU & vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U]);
    vlSelfRef.top = (0x0000003fU & vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U]);
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__1__KET____DOT__top_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__1__KET____DOT__top_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r2[0U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                     >> 6U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                       >> 6U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                      >> 6U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                    >> 6U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__2__KET____DOT__top_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__2__KET____DOT__top_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r2[1U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                     >> 0x0000000cU));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                       >> 0x0000000cU));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                      >> 0x0000000cU));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                    >> 0x0000000cU));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__3__KET____DOT__top_right__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__3__KET____DOT__top_right__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r2[1U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                     >> 0x00000012U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                       >> 0x00000012U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                      >> 0x00000012U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                    >> 0x00000012U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r1[2U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                     >> 0x00000018U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                       >> 0x00000018U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                      >> 0x00000018U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                    >> 0x00000018U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r0[2U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                      << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                                >> 0x0000001eU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                        << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                       << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                     << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                               >> 0x0000001eU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r1[2U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                      << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                                >> 0x0000001eU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                        << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                       << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                     << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                               >> 0x0000001eU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r2[2U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                      << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                                >> 0x0000001eU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                        << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                       << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                     << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                               >> 0x0000001eU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r3[2U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                      << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[0U] 
                                                >> 0x0000001eU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                        << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                       << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                     << 2U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[0U] 
                                               >> 0x0000001eU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r0[3U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 4U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 4U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 4U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 4U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r1[3U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 4U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 4U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 4U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 4U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r2[3U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 4U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 4U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 4U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 4U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r3[3U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 4U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 4U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 4U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 4U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r3[3U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x0000000aU));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x0000000aU));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x0000000aU));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x0000000aU));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r1[4U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x00000010U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x00000010U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x00000010U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x00000010U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r0[4U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x00000016U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x00000016U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x00000016U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x00000016U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r1[4U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x00000016U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x00000016U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x00000016U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x00000016U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r2[4U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x00000016U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x00000016U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x00000016U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x00000016U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r3[4U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                     >> 0x00000016U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                       >> 0x00000016U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                      >> 0x00000016U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                    >> 0x00000016U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r0[5U]);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                      << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                                >> 0x0000001cU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                        << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                       << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                     << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                               >> 0x0000001cU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p1_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r1[5U]);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                      << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                                >> 0x0000001cU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                        << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                       << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                     << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                               >> 0x0000001cU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p2_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r2[5U]);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                      << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                                >> 0x0000001cU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                        << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                       << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                     << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                               >> 0x0000001cU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r3[5U]);
    vlSelfRef.left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                      << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[1U] 
                                                >> 0x0000001cU)));
    vlSelfRef.bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                        << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                       << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                     << 4U) | (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[1U] 
                                               >> 0x0000001cU)));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r3[5U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                     >> 2U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                       >> 2U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                      >> 2U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                    >> 2U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__0__KET____DOT__bottom_left__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__0__KET____DOT__bottom_left__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r0[6U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                     >> 8U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                       >> 8U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                      >> 8U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                    >> 8U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__1__KET____DOT__bottom_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__1__KET____DOT__bottom_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r0[6U] 
                        >> 0x00000010U);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                     >> 0x0000000eU));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                       >> 0x0000000eU));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                      >> 0x0000000eU));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                    >> 0x0000000eU));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__2__KET____DOT__bottom_edge__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__2__KET____DOT__bottom_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p0_top[2U];
    vlSelfRef.domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomainAll__DOT__r0[7U]);
    vlSelfRef.left = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                                     >> 0x00000014U));
    vlSelfRef.bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                                       >> 0x00000014U));
    vlSelfRef.right = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                                      >> 0x00000014U));
    vlSelfRef.top = (0x0000003fU & (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                                    >> 0x00000014U));
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}

void Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__3__KET____DOT__bottom_right__DOT__rot__0(Vtop_ColourToDomainRotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomainRotation___ico_sequent__TOP__ColourToDomainAll__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__3__KET____DOT__bottom_right__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.p_left[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[0U];
    vlSelfRef.p_left[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[1U];
    vlSelfRef.p_left[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_left[2U];
    vlSelfRef.p_bottom[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[0U];
    vlSelfRef.p_bottom[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[1U];
    vlSelfRef.p_bottom[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_bottom[2U];
    vlSelfRef.p_right[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[0U];
    vlSelfRef.p_right[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[1U];
    vlSelfRef.p_right[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_right[2U];
    vlSelfRef.p_top[0U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[0U];
    vlSelfRef.p_top[1U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[1U];
    vlSelfRef.p_top[2U] = vlSymsp->TOP.ColourToDomainAll__DOT__p3_top[2U];
    vlSelfRef.domain = (vlSymsp->TOP.ColourToDomainAll__DOT__r3[7U] 
                        >> 0x00000010U);
    vlSelfRef.left = (vlSymsp->TOP.ColourToDomainAll__DOT__in_left[2U] 
                      >> 0x0000001aU);
    vlSelfRef.bottom = (vlSymsp->TOP.ColourToDomainAll__DOT__in_bottom[2U] 
                        >> 0x0000001aU);
    vlSelfRef.right = (vlSymsp->TOP.ColourToDomainAll__DOT__in_right[2U] 
                       >> 0x0000001aU);
    vlSelfRef.top = (vlSymsp->TOP.ColourToDomainAll__DOT__in_top[2U] 
                     >> 0x0000001aU);
    vlSelfRef.domain_out = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.domain) >> (0x0000000fU 
                                               & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.top) & 
                          ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.p_top
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.p_top[(3U 
                                                   & (((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p) 
                                                      >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.right) 
                                               & ((0x5fU 
                                                   >= 
                                                   (0x0000007fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 
                                                  (((0U 
                                                     == 
                                                     (0x0000001fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p)))
                                                     ? 0U
                                                     : 
                                                    (vlSelfRef.p_right
                                                     [
                                                     (((IData)(5U) 
                                                       + 
                                                       (0x0000007fU 
                                                        & ((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x00000020U) 
                                                      - 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                   | (vlSelfRef.p_right
                                                      [
                                                      (3U 
                                                       & (((IData)(6U) 
                                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                                          >> 5U))] 
                                                      >> 
                                                      (0x0000001fU 
                                                       & ((IData)(6U) 
                                                          * vlSelfRef.unnamedblk1__DOT__p))))
                                                   : 0U)))) 
              & (0U != ((IData)(vlSelfRef.bottom) & 
                        ((0x5fU >= (0x0000007fU & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p)))
                          ? (((0U == (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                               ? 0U : (vlSelfRef.p_bottom
                                       [(((IData)(5U) 
                                          + (0x0000007fU 
                                             & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))) 
                                         >> 5U)] << 
                                       ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(6U) 
                                              * vlSelfRef.unnamedblk1__DOT__p))))) 
                             | (vlSelfRef.p_bottom[
                                (3U & (((IData)(6U) 
                                        * vlSelfRef.unnamedblk1__DOT__p) 
                                       >> 5U))] >> 
                                (0x0000001fU & ((IData)(6U) 
                                                * vlSelfRef.unnamedblk1__DOT__p))))
                          : 0U)))) & (0U != ((IData)(vlSelfRef.left) 
                                             & ((0x5fU 
                                                 >= 
                                                 (0x0000007fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p)))
                                                 ? 
                                                (((0U 
                                                   == 
                                                   (0x0000001fU 
                                                    & ((IData)(6U) 
                                                       * vlSelfRef.unnamedblk1__DOT__p)))
                                                   ? 0U
                                                   : 
                                                  (vlSelfRef.p_left
                                                   [
                                                   (((IData)(5U) 
                                                     + 
                                                     (0x0000007fU 
                                                      & ((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))) 
                                                 | (vlSelfRef.p_left
                                                    [
                                                    (3U 
                                                     & (((IData)(6U) 
                                                         * vlSelfRef.unnamedblk1__DOT__p) 
                                                        >> 5U))] 
                                                    >> 
                                                    (0x0000001fU 
                                                     & ((IData)(6U) 
                                                        * vlSelfRef.unnamedblk1__DOT__p))))
                                                 : 0U))))) {
            vlSelfRef.domain_out = ((IData)(vlSelfRef.domain_out) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.changed = ((IData)(vlSelfRef.domain_out) 
                         != (IData)(vlSelfRef.domain));
    vlSelfRef.deadend = ((0U != (IData)(vlSelfRef.domain)) 
                         & (0U == (IData)(vlSelfRef.domain_out)));
}
