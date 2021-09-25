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
#include "../IO/IO.h"
#include "../Global.h"

// ? Declarations for using Message 
// ? functions in files that include this header.
void KernelInfo(char* Message);
void KernelWarning(char* Message);
void KernelError(char* Message);
void KernelPanic(char* Message);