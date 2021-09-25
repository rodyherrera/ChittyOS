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
#include "../Message/Message.h"
#include "../Global.h"

// ? Macros that will be used in Memory.c
// ? and in files that include this header
#define MEMORY_EMPTY 0x0

// ? Declaring the functions that will be
// ? used in the files that include Memory.c
void* KernelMalloc(unsigned long Size);
void KernelFree(void* Memory);
void CopyMemory(unsigned char* Destinity, unsigned char* Source, unsigned long Size);
unsigned long MemoryUsage();
unsigned long MemoryUsageEffective();
unsigned long TotalMemory();
unsigned char* GetMemoryIndex();