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

#include "IDT.h"

// ? Function that allows setting the 
// ? IDT Gate, receives the number as the 
// ? first parameter and the Handler as the second.
void SetIDTGate(int Number, unsigned long Handler){
    IDT[Number].LowOffset = Low16(Handler);
    IDT[Number].Selector = KERNEL_CS;
    IDT[Number].Always0 = 0;
    IDT[Number].Flags = 0x8E;
    IDT[Number].HighOffset = High16(Handler);
}

// ? Function that allows to apply the IDT changes.
void ApplyIDT(){
    IDT_Register.Base = (unsigned long) &IDT;
    IDT_Register.Limit = IDT_ENTRIES * sizeof(IDT_Gate_t) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&IDT_Register));
}