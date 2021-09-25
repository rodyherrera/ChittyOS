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

#include "../../Drivers/Display/Display.h"
#include "../../Drivers/Keyboard/Keyboard.h"
#include "../../Drivers/Display/Color.h"

// ? Functions that will be 
// ? available for files that include IO.h
void KernelPrintInteger(int Number);
void KernelPrintUnsignedInteger(unsigned int Number);
void KernelPrintUint32(unsigned long Number);
void KernelInputString(char* Output);
void KernelPrintString(char* String);
void KernelPrintStringWithColor(char* String, char Color);