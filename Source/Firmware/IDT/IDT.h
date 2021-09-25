/***
 * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
 * Licensed under the MIT license. See LICENSE file in the project root 
 * for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * For related information - https://github.com/codewithrodi/ChittyOS/
 * 
 * = This project has been done for no profit and just to test 
 * = my knowledge and skills, no contributions or bug fixes are expected.
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ***/

#pragma once
#include "../../Library/Type.h"

// ? Macros that will be available in 
// ? IDT.c and in the files that include this header.
#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

// ? Structures declarations
typedef struct {
    unsigned short LowOffset, Selector, HighOffset;
    char* Always0, Flags;
} __attribute__((packed)) IDT_Gate_t;

typedef struct {
    unsigned short Limit;
    unsigned long Base;
} __attribute__((packed)) IDT_Register_t;

static IDT_Gate_t IDT[IDT_ENTRIES];
static IDT_Register_t IDT_Register;

// ? Functions Declarations
void SetIDTGate(int Number, unsigned long Handler);
void ApplyIDT();