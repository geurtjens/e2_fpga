// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__0__KET____DOT__top_left__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__0__KET____DOT__top_left__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[0U]);
    vlSelfRef.in_colour_left = (0x0000003fU & vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U]);
    vlSelfRef.in_colour_bottom = (0x0000003fU & vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U]);
    vlSelfRef.in_colour_right = (0x0000003fU & vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U]);
    vlSelfRef.in_colour_top = (0x0000003fU & vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U]);
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__1__KET____DOT__top_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__1__KET____DOT__top_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[0U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                               >> 6U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                 >> 6U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                >> 6U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                              >> 6U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__2__KET____DOT__top_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__2__KET____DOT__top_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[1U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                               >> 0x0000000cU));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                 >> 0x0000000cU));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                >> 0x0000000cU));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                              >> 0x0000000cU));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__3__KET____DOT__top_right__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__0__KET____DOT__gen_x__BRA__3__KET____DOT__top_right__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[1U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                               >> 0x00000012U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                 >> 0x00000012U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                >> 0x00000012U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                              >> 0x00000012U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[2U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                               >> 0x00000018U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                 >> 0x00000018U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                >> 0x00000018U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                              >> 0x00000018U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[2U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                << 2U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                  << 2U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                    >> 0x0000001eU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                 << 2U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                               << 2U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[2U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                << 2U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                  << 2U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                    >> 0x0000001eU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                 << 2U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                               << 2U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[2U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                << 2U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                  << 2U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                    >> 0x0000001eU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                 << 2U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                               << 2U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[2U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                << 2U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[0U] 
                                                  >> 0x0000001eU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                  << 2U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[0U] 
                                                    >> 0x0000001eU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                 << 2U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[0U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                               << 2U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[0U] 
                                                 >> 0x0000001eU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[3U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 4U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 4U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 4U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 4U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[3U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 4U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 4U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 4U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 4U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[3U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 4U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 4U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 4U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 4U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[3U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 4U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 4U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 4U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 4U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__1__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[3U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x0000000aU));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x0000000aU));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x0000000aU));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x0000000aU));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__0__KET____DOT__left_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[4U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x00000010U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x00000010U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x00000010U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x00000010U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[4U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x00000016U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x00000016U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x00000016U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x00000016U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[4U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x00000016U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x00000016U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x00000016U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x00000016U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[4U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x00000016U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x00000016U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x00000016U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x00000016U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__1__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[4U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                               >> 0x00000016U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                 >> 0x00000016U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                >> 0x00000016U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                              >> 0x00000016U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[5U]);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                                << 4U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                  << 4U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                    >> 0x0000001cU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                 << 4U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                   >> 0x0000001cU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                               << 4U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element1_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r1[5U]);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                                << 4U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                  << 4U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                    >> 0x0000001cU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                 << 4U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                   >> 0x0000001cU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                               << 4U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element2_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r2[5U]);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                                << 4U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                  << 4U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                    >> 0x0000001cU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                 << 4U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                   >> 0x0000001cU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                               << 4U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__2__KET____DOT__inner__DOT__rot3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[5U]);
    vlSelfRef.in_colour_left = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                                << 4U) 
                                               | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[1U] 
                                                  >> 0x0000001cU)));
    vlSelfRef.in_colour_bottom = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                  << 4U) 
                                                 | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[1U] 
                                                    >> 0x0000001cU)));
    vlSelfRef.in_colour_right = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                 << 4U) 
                                                | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[1U] 
                                                   >> 0x0000001cU)));
    vlSelfRef.in_colour_top = (0x0000003fU & ((vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                               << 4U) 
                                              | (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[1U] 
                                                 >> 0x0000001cU)));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__2__KET____DOT__gen_x__BRA__3__KET____DOT__right_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[5U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                               >> 2U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                 >> 2U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                >> 2U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                              >> 2U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__0__KET____DOT__bottom_left__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__0__KET____DOT__bottom_left__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[6U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                               >> 8U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                 >> 8U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                >> 8U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                              >> 8U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__1__KET____DOT__bottom_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__1__KET____DOT__bottom_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[6U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                               >> 0x0000000eU));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                 >> 0x0000000eU));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                >> 0x0000000eU));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                              >> 0x0000000eU));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__2__KET____DOT__bottom_edge__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__2__KET____DOT__bottom_edge__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element0_top[2U];
    vlSelfRef.in_domain = (0x0000ffffU & vlSymsp->TOP.ColourToDomain__DOT__in_domain_r0[7U]);
    vlSelfRef.in_colour_left = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                               >> 0x00000014U));
    vlSelfRef.in_colour_bottom = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                                 >> 0x00000014U));
    vlSelfRef.in_colour_right = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                                >> 0x00000014U));
    vlSelfRef.in_colour_top = (0x0000003fU & (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                                              >> 0x00000014U));
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}

void Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__3__KET____DOT__bottom_right__DOT__rot__0(Vtop_ColourToDomain_Rotation* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ColourToDomain_Rotation___ico_sequent__TOP__ColourToDomain__DOT__gen_y__BRA__3__KET____DOT__gen_x__BRA__3__KET____DOT__bottom_right__DOT__rot__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.in_element_left[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[0U];
    vlSelfRef.in_element_left[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[1U];
    vlSelfRef.in_element_left[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_left[2U];
    vlSelfRef.in_element_bottom[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[0U];
    vlSelfRef.in_element_bottom[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[1U];
    vlSelfRef.in_element_bottom[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_bottom[2U];
    vlSelfRef.in_element_right[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[0U];
    vlSelfRef.in_element_right[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[1U];
    vlSelfRef.in_element_right[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_right[2U];
    vlSelfRef.in_element_top[0U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[0U];
    vlSelfRef.in_element_top[1U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[1U];
    vlSelfRef.in_element_top[2U] = vlSymsp->TOP.ColourToDomain__DOT__in_element3_top[2U];
    vlSelfRef.in_domain = (vlSymsp->TOP.ColourToDomain__DOT__in_domain_r3[7U] 
                           >> 0x00000010U);
    vlSelfRef.in_colour_left = (vlSymsp->TOP.ColourToDomain__DOT__in_colours_left[2U] 
                                >> 0x0000001aU);
    vlSelfRef.in_colour_bottom = (vlSymsp->TOP.ColourToDomain__DOT__in_colours_bottom[2U] 
                                  >> 0x0000001aU);
    vlSelfRef.in_colour_right = (vlSymsp->TOP.ColourToDomain__DOT__in_colours_right[2U] 
                                 >> 0x0000001aU);
    vlSelfRef.in_colour_top = (vlSymsp->TOP.ColourToDomain__DOT__in_colours_top[2U] 
                               >> 0x0000001aU);
    vlSelfRef.out_domain = 0U;
    vlSelfRef.unnamedblk1__DOT__p = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.unnamedblk1__DOT__p)) {
        if (((((((IData)(vlSelfRef.in_domain) >> (0x0000000fU 
                                                  & vlSelfRef.unnamedblk1__DOT__p)) 
                & (0U != ((IData)(vlSelfRef.in_colour_top) 
                          & ((0x5fU >= (0x0000007fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                              ? (((0U == (0x0000001fU 
                                          & ((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p)))
                                   ? 0U : (vlSelfRef.in_element_top
                                           [(((IData)(5U) 
                                              + (0x0000007fU 
                                                 & ((IData)(6U) 
                                                    * vlSelfRef.unnamedblk1__DOT__p))) 
                                             >> 5U)] 
                                           << ((IData)(0x00000020U) 
                                               - (0x0000001fU 
                                                  & ((IData)(6U) 
                                                     * vlSelfRef.unnamedblk1__DOT__p))))) 
                                 | (vlSelfRef.in_element_top
                                    [(3U & (((IData)(6U) 
                                             * vlSelfRef.unnamedblk1__DOT__p) 
                                            >> 5U))] 
                                    >> (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p))))
                              : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_right) 
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
                                                      (vlSelfRef.in_element_right
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
                                                     | (vlSelfRef.in_element_right
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
              & (0U != ((IData)(vlSelfRef.in_colour_bottom) 
                        & ((0x5fU >= (0x0000007fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p)))
                            ? (((0U == (0x0000001fU 
                                        & ((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p)))
                                 ? 0U : (vlSelfRef.in_element_bottom
                                         [(((IData)(5U) 
                                            + (0x0000007fU 
                                               & ((IData)(6U) 
                                                  * vlSelfRef.unnamedblk1__DOT__p))) 
                                           >> 5U)] 
                                         << ((IData)(0x00000020U) 
                                             - (0x0000001fU 
                                                & ((IData)(6U) 
                                                   * vlSelfRef.unnamedblk1__DOT__p))))) 
                               | (vlSelfRef.in_element_bottom
                                  [(3U & (((IData)(6U) 
                                           * vlSelfRef.unnamedblk1__DOT__p) 
                                          >> 5U))] 
                                  >> (0x0000001fU & 
                                      ((IData)(6U) 
                                       * vlSelfRef.unnamedblk1__DOT__p))))
                            : 0U)))) & (0U != ((IData)(vlSelfRef.in_colour_left) 
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
                                                    (vlSelfRef.in_element_left
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
                                                   | (vlSelfRef.in_element_left
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
            vlSelfRef.out_domain = ((IData)(vlSelfRef.out_domain) 
                                    | (0x0000ffffU 
                                       & ((IData)(1U) 
                                          << (0x0000000fU 
                                              & vlSelfRef.unnamedblk1__DOT__p))));
        }
        vlSelfRef.unnamedblk1__DOT__p = ((IData)(1U) 
                                         + vlSelfRef.unnamedblk1__DOT__p);
    }
    vlSelfRef.out_changed = ((IData)(vlSelfRef.out_domain) 
                             != (IData)(vlSelfRef.in_domain));
    vlSelfRef.out_deadend = ((0U != (IData)(vlSelfRef.in_domain)) 
                             & (0U == (IData)(vlSelfRef.out_domain)));
}
