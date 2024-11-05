// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__sigdelay__DOT__wr_addr;
    CData/*7:0*/ __Vdly__sigdelay__DOT__rd_addr;
    CData/*7:0*/ __Vdlyvdim0__sigdelay__DOT__dualRam__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__dualRam__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__sigdelay__DOT__dualRam__DOT__ram_array__v0;
    // Body
    __Vdly__sigdelay__DOT__wr_addr = vlSelf->sigdelay__DOT__wr_addr;
    __Vdly__sigdelay__DOT__rd_addr = vlSelf->sigdelay__DOT__rd_addr;
    __Vdlyvset__sigdelay__DOT__dualRam__DOT__ram_array__v0 = 0U;
    if (vlSelf->en) {
        __Vdly__sigdelay__DOT__wr_addr = (0xffU & ((IData)(3U) 
                                                   + (IData)(vlSelf->sigdelay__DOT__wr_addr)));
        __Vdly__sigdelay__DOT__rd_addr = (0xffU & ((IData)(3U) 
                                                   + (IData)(vlSelf->sigdelay__DOT__rd_addr)));
    }
    if (vlSelf->rd) {
        vlSelf->dout = vlSelf->sigdelay__DOT__dualRam__DOT__ram_array
            [vlSelf->sigdelay__DOT__rd_addr];
    }
    if (vlSelf->wr) {
        __Vdlyvval__sigdelay__DOT__dualRam__DOT__ram_array__v0 
            = vlSelf->din;
        __Vdlyvset__sigdelay__DOT__dualRam__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__sigdelay__DOT__dualRam__DOT__ram_array__v0 
            = vlSelf->sigdelay__DOT__wr_addr;
    }
    vlSelf->sigdelay__DOT__rd_addr = __Vdly__sigdelay__DOT__rd_addr;
    if (__Vdlyvset__sigdelay__DOT__dualRam__DOT__ram_array__v0) {
        vlSelf->sigdelay__DOT__dualRam__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__dualRam__DOT__ram_array__v0] 
            = __Vdlyvval__sigdelay__DOT__dualRam__DOT__ram_array__v0;
    }
    vlSelf->sigdelay__DOT__wr_addr = __Vdly__sigdelay__DOT__wr_addr;
}

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsigdelay___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->wr & 0xfeU))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY((vlSelf->rd & 0xfeU))) {
        Verilated::overWidthError("rd");}
}
#endif  // VL_DEBUG
