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

#include "Port.h"

unsigned char PortByteIn(unsigned short Port){
    unsigned char Result;
    __asm__("in %%dx, %%al" : "=a" (Result) : "d" (Port));
    return Result;
}

void PortByteOut(unsigned short Port, unsigned char Data){
    __asm__("out %%al, %%dx" : : "a" (Data), "d" (Port));
}

unsigned short PortWordIn(unsigned short Port){
    unsigned short Result;
    __asm__("in %%dx, %%ax" : "=a" (Result) : "d" (Port));
    return Result;
}

void PortWordOut(unsigned short Port, unsigned short Data){
    __asm__("out %%ax, %%dx" : : "a" (Data), "d" (Port));
}