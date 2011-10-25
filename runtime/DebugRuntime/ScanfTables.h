//===- ScanfTables.h -  Floating point recognition tables      ------------===//
// 
//                       The SAFECode Compiler Project
//
// This file was developed by the LLVM research group and is distributed under
// the University of Illinois Open Source License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This file contains lexical tables used by the scanf() runtime wrapper to
// to recognize floating point numbers.
//
//===----------------------------------------------------------------------===//

#ifndef _SCANF_TABLES_H
#define _SCANF_TABLES_H

//
// This file contains tables for recognizing floating point numbers. These
// tables are used by f_collect(). They were generated with 'flex -f' on the
// following input:
//
// ----------------------------------------------------------------------------
//
// dg  [0-9]
// ndg [a-zA-Z_]
// xdg [0-9a-fA-F]
// 
// %%
// 
// [+-]?[iI][nN][fF]([iI][nN][iI][tT][yY])?                    ;
// [+-]?[nN][aA][nN](\(({dg}|{ndg})*\))?                       ;
// [+-]?(({dg}+\.?)|({dg}*\.{dg}+))([eE][+-]?{dg}+)?           ;
// [+-]?0[xX](({xdg}+\.?)|({xdg}*\.{xdg}+))([pP][+-]?{dg}+)?   ;
// 
// ----------------------------------------------------------------------------
//

#include <stdint.h>

static const int8_t yy_nxt[][128] =
    {
    {
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,

        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,    0,    0
    },

    {
        3,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    5,    4,    5,    6,    4,    7,    8,
        8,    8,    8,    8,    8,    8,    8,    8,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,

        4,    4,    4,    9,    4,    4,    4,    4,   10,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    9,    4,    4,    4,    4,
       10,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4
    },

    {
        3,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,

        4,    4,    4,    5,    4,    5,    6,    4,    7,    8,
        8,    8,    8,    8,    8,    8,    8,    8,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    9,    4,    4,    4,    4,   10,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    9,    4,    4,    4,    4,
       10,    4,    4,    4,    4,    4,    4,    4,    4,    4,
        4,    4,    4,    4,    4,    4,    4,    4
    },

    {
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,

       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,

       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
       -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3
    },

    {
        3,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,

       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
       -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4
    },

    {
        3,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   11,   -5,   12,   13,

       13,   13,   13,   13,   13,   13,   13,   13,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   14,   -5,   -5,   -5,   -5,   15,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   14,   -5,   -5,   -5,   -5,
       15,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
       -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5
    },

    {
        3,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,

       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,
       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6,

       -6,   -6,   -6,   -6,   -6,   -6,   -6,   -6
    },

    {
        3,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   17,   -7,   13,   13,
       13,   13,   13,   13,   13,   13,   13,   13,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   18,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   19,   -7,

       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   18,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,   -7,
       19,   -7,   -7,   -7,   -7,   -7,   -7,   -7
    },

    {
        3,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   17,   -8,   13,   13,
       13,   13,   13,   13,   13,   13,   13,   13,   -8,   -8,

       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   18,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   18,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8,
       -8,   -8,   -8,   -8,   -8,   -8,   -8,   -8
    },

    {
        3,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,

       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   20,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       20,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9,
       -9,   -9,   -9,   -9,   -9,   -9,   -9,   -9

    },

    {
        3,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,   21,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,   21,  -10,  -10,

      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10,
      -10,  -10,  -10,  -10,  -10,  -10,  -10,  -10
    },

    {
        3,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,

      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11,
      -11,  -11,  -11,  -11,  -11,  -11,  -11,  -11
    },

    {
        3,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,

      -12,  -12,  -12,  -12,  -12,  -12,   17,  -12,   13,   13,
       13,   13,   13,   13,   13,   13,   13,   13,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,   18,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,   19,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,   18,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
      -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,  -12,
       19,  -12,  -12,  -12,  -12,  -12,  -12,  -12
    },

    {
        3,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,

      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,   17,  -13,   13,   13,
       13,   13,   13,   13,   13,   13,   13,   13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,   18,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,   18,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,

      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
      -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13
    },

    {
        3,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,   20,  -14,

      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
       20,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14,
      -14,  -14,  -14,  -14,  -14,  -14,  -14,  -14
    },

    {
        3,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,

      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,   21,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,   21,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
      -15,  -15,  -15,  -15,  -15,  -15,  -15,  -15
    },

    {
        3,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,

      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,   18,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,   18,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,
      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16,

      -16,  -16,  -16,  -16,  -16,  -16,  -16,  -16
    },

    {
        3,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,   18,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,

      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,   18,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17,
      -17,  -17,  -17,  -17,  -17,  -17,  -17,  -17
    },

    {
        3,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,   22,  -18,   22,  -18,  -18,   23,   23,
       23,   23,   23,   23,   23,   23,   23,   23,  -18,  -18,

      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
      -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18
    },

    {
        3,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,

      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,   24,  -19,   25,   25,
       25,   25,   25,   25,   25,   25,   25,   25,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,   25,   25,   25,   25,   25,
       25,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,   25,   25,   25,
       25,   25,   25,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19,
      -19,  -19,  -19,  -19,  -19,  -19,  -19,  -19

    },

    {
        3,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
       26,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,

      -20,  -20,   26,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20,
      -20,  -20,  -20,  -20,  -20,  -20,  -20,  -20
    },

    {
        3,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,

      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,   27,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
       27,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
      -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21
    },

    {
        3,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,

      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,   23,   23,
       23,   23,   23,   23,   23,   23,   23,   23,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22,
      -22,  -22,  -22,  -22,  -22,  -22,  -22,  -22
    },

    {
        3,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,

      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,   23,   23,
       23,   23,   23,   23,   23,   23,   23,   23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,

      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
      -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23
    },

    {
        3,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,   28,   28,
       28,   28,   28,   28,   28,   28,   28,   28,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,   28,   28,   28,   28,   28,
       28,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,

      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,   28,   28,   28,
       28,   28,   28,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24,
      -24,  -24,  -24,  -24,  -24,  -24,  -24,  -24
    },

    {
        3,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,   29,  -25,   25,   25,

       25,   25,   25,   25,   25,   25,   25,   25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,   25,   25,   25,   25,   25,
       25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
       30,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,  -25,   25,   25,   25,
       25,   25,   25,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,   30,  -25,  -25,  -25,  -25,  -25,  -25,  -25,
      -25,  -25,  -25,  -25,  -25,  -25,  -25,  -25
    },

    {
        3,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,

      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,   31,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,   31,  -26,  -26,  -26,  -26,
      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26,

      -26,  -26,  -26,  -26,  -26,  -26,  -26,  -26
    },

    {
        3,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
       32,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,

      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
      -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27
    },

    {
        3,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,   28,   28,
       28,   28,   28,   28,   28,   28,   28,   28,  -28,  -28,

      -28,  -28,  -28,  -28,  -28,   28,   28,   28,   28,   28,
       28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
       30,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,   28,   28,   28,
       28,   28,   28,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,   30,  -28,  -28,  -28,  -28,  -28,  -28,  -28,
      -28,  -28,  -28,  -28,  -28,  -28,  -28,  -28
    },

    {
        3,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,

      -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,   28,   28,
       28,   28,   28,   28,   28,   28,   28,   28,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,   28,   28,   28,   28,   28,
       28,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
       30,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,  -29,  -29,   28,   28,   28,
       28,   28,   28,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,   30,  -29,  -29,  -29,  -29,  -29,  -29,  -29,
      -29,  -29,  -29,  -29,  -29,  -29,  -29,  -29

    },

    {
        3,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,   33,  -30,   33,  -30,  -30,   34,   34,
       34,   34,   34,   34,   34,   34,   34,   34,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,

      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30,
      -30,  -30,  -30,  -30,  -30,  -30,  -30,  -30
    },

    {
        3,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,

      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,   35,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
       35,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31,
      -31,  -31,  -31,  -31,  -31,  -31,  -31,  -31
    },

    {
        3,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
      -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
      -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
      -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,

      -32,   36,  -32,  -32,  -32,  -32,  -32,  -32,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,  -32,  -32,
      -32,  -32,  -32,  -32,  -32,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,  -32,  -32,  -32,  -32,   37,  -32,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,  -32,  -32,  -32,  -32,  -32
    },

    {
        3,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,

      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,   34,   34,
       34,   34,   34,   34,   34,   34,   34,   34,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,

      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
      -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33
    },

    {
        3,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,   34,   34,
       34,   34,   34,   34,   34,   34,   34,   34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,

      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
      -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34
    },

    {
        3,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,

      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,   38,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,   38,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35,
      -35,  -35,  -35,  -35,  -35,  -35,  -35,  -35
    },

    {
        3,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,

      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,

      -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36
    },

    {
        3,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
      -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
      -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
      -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,  -37,
      -37,   36,  -37,  -37,  -37,  -37,  -37,  -37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,  -37,  -37,
      -37,  -37,  -37,  -37,  -37,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,

       37,  -37,  -37,  -37,  -37,   37,  -37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
       37,   37,   37,  -37,  -37,  -37,  -37,  -37
    },

    {
        3,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,

      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,   39,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,   39,  -38,  -38,  -38,
      -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38
    },

    {
        3,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,

      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,   40,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,  -39,
      -39,   40,  -39,  -39,  -39,  -39,  -39,  -39

    },

    {
        3,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,

      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
      -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40
    },

    } ;


static const int8_t yy_accept[41] =
    {   0,
        0,    0,    6,    5,    5,    5,    3,    3,    5,    5,
        0,    3,    3,    0,    0,    3,    3,    0,    0,    0,
        0,    0,    3,    0,    4,    1,    2,    4,    4,    0,
        0,    0,    0,    4,    0,    2,    0,    0,    0,    1
    } ;

#endif