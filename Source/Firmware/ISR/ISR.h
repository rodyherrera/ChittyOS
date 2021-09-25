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

#include "../IDT/IDT.h"
#include "../../Drivers/Display/Display.h"
#include "../../Kernel/Message/Message.h"
#include "../../Library/Type.h"
#include "../Port/Port.h"

extern void IsR0();
extern void IsR1();
extern void IsR2();
extern void IsR3();
extern void IsR4();
extern void IsR5();
extern void IsR6();
extern void IsR7();
extern void IsR8();
extern void IsR9();
extern void IsR10();
extern void IsR11();
extern void IsR12();
extern void IsR13();
extern void IsR14();
extern void IsR15();
extern void IsR16();
extern void IsR17();
extern void IsR18();
extern void IsR19();
extern void IsR20();
extern void IsR21();
extern void IsR22();
extern void IsR23();
extern void IsR24();
extern void IsR25();
extern void IsR26();
extern void IsR27();
extern void IsR28();
extern void IsR29();
extern void IsR30();
extern void IsR31();

extern void Irq0();
extern void Irq1();
extern void Irq2();
extern void Irq3();
extern void Irq4();
extern void Irq5();
extern void Irq6();
extern void Irq7();
extern void Irq8();
extern void Irq9();
extern void Irq10();
extern void Irq11();
extern void Irq12();
extern void Irq13();
extern void Irq14();
extern void Irq15();

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef struct {
    unsigned long DS, EDI, ESI, EBP, ESP, EBX, EDX, ECX, EAX, IntNo, ErrorCode, EIP, CS, EFlags, UserSpace, SS;
} Registers_t;

void IsrInstall();
void IsrHandler(Registers_t);

typedef void(*Isr_t)(Registers_t);
void RegisterInterruptHandler(unsigned char Number, Isr_t Handler);