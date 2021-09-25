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

#include "ISR.h"

Isr_t InterruptHandlers[256];

void IsrInstall(){
    SetIDTGate(0, (unsigned long)IsR0);
    SetIDTGate(1, (unsigned long)IsR1);
    SetIDTGate(2, (unsigned long)IsR2);
    SetIDTGate(3, (unsigned long)IsR3);
    SetIDTGate(4, (unsigned long)IsR4);
    SetIDTGate(5, (unsigned long)IsR5);
    SetIDTGate(6, (unsigned long)IsR6);
    SetIDTGate(7, (unsigned long)IsR7);
    SetIDTGate(8, (unsigned long)IsR8);
    SetIDTGate(9, (unsigned long)IsR9);
    SetIDTGate(10, (unsigned long)IsR10);
    SetIDTGate(11, (unsigned long)IsR11);
    SetIDTGate(12, (unsigned long)IsR12);
    SetIDTGate(13, (unsigned long)IsR13);
    SetIDTGate(14, (unsigned long)IsR14);
    SetIDTGate(15, (unsigned long)IsR15);
    SetIDTGate(16, (unsigned long)IsR16);
    SetIDTGate(17, (unsigned long)IsR17);
    SetIDTGate(18, (unsigned long)IsR18);
    SetIDTGate(19, (unsigned long)IsR19);
    SetIDTGate(20, (unsigned long)IsR20);
    SetIDTGate(21, (unsigned long)IsR21);
    SetIDTGate(22, (unsigned long)IsR22);
    SetIDTGate(23, (unsigned long)IsR23);
    SetIDTGate(24, (unsigned long)IsR24);
    SetIDTGate(25, (unsigned long)IsR25);
    SetIDTGate(26, (unsigned long)IsR26);
    SetIDTGate(27, (unsigned long)IsR27);
    SetIDTGate(28, (unsigned long)IsR28);
    SetIDTGate(29, (unsigned long)IsR29);
    SetIDTGate(30, (unsigned long)IsR30);
    SetIDTGate(31, (unsigned long)IsR31);

    PortByteOut(0x20, 0x11);
    PortByteOut(0xA0, 0x11);
    PortByteOut(0x21, 0x20);
    PortByteOut(0xA1, 0x28);
    PortByteOut(0x21, 0x04);
    PortByteOut(0xA1, 0x02);
    PortByteOut(0x21, 0x01);
    PortByteOut(0xA1, 0x01);
    PortByteOut(0x21, 0x0);
    PortByteOut(0xA1, 0x0);

    SetIDTGate(32, (unsigned long)Irq0);
    SetIDTGate(33, (unsigned long)Irq1);
    SetIDTGate(34, (unsigned long)Irq2);
    SetIDTGate(35, (unsigned long)Irq3);
    SetIDTGate(36, (unsigned long)Irq4);
    SetIDTGate(37, (unsigned long)Irq5);
    SetIDTGate(38, (unsigned long)Irq6);
    SetIDTGate(39, (unsigned long)Irq7);
    SetIDTGate(40, (unsigned long)Irq8);
    SetIDTGate(41, (unsigned long)Irq9);
    SetIDTGate(42, (unsigned long)Irq10);
    SetIDTGate(43, (unsigned long)Irq11);
    SetIDTGate(44, (unsigned long)Irq12);
    SetIDTGate(45, (unsigned long)Irq13);
    SetIDTGate(46, (unsigned long)Irq14);
    SetIDTGate(47, (unsigned long)Irq15);

    ApplyIDT();
}

char *ExceptionMessages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void IsrHandler(Registers_t Register){
    KernelError(FIRMWARE_ERROR_ISR_EXCEPTION);
    KernelPrintString(ExceptionMessages[Register.IntNo]);
    kPrintCharacter('\n');
}

void RegisterInterruptHandler(unsigned char Number, Isr_t Handler){
    InterruptHandlers[Number] = Handler;
}

void IrqHandler(Registers_t Register){
    if(Register.IntNo >= 40)
        PortByteOut(0xA0, 0x20);
    
    if(InterruptHandlers[Register.IntNo] != 0){
        Isr_t Handler = InterruptHandlers[Register.IntNo];
        Handler(Register);
    }
}