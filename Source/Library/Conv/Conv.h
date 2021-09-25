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
#include "../Type.h"

// ? Declaration of functions so that other 
// ? files can access this header to carry out 
// ? conversions, hopefully I could with assembler 
// ? alter the quantum particles of the universe 
// ? and make a function that turns me from 
// ? ugly to beautiful ah XDOASDJSADÍSADPKOSADP
unsigned char CharToHex(char Character);
unsigned char UintToChar(unsigned int Number);
unsigned char Uint32ToChar(unsigned long Number);
void ShortToString(char* Output, short Number);
void IntToString(char* Output, int Number);
void UintToString(char* Output, unsigned int Number);
void Uint32ToHex(char* Output, unsigned long Number);
void Uint32ToString(char* Output, unsigned long Number);
int StringToInteger(char* String);