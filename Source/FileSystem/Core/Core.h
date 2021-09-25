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
#include "../Global.h"
#include "../../Library/Type.h"
#include "../../Library/String/String.h"
#include "../../Kernel/Global.h"
#include "../../Kernel/Memory/Memory.h"
#include "../../Kernel/Message/Message.h"

// ? Macros to be used in Core.c and in
// ? files that include this header.
#define OK 0
#define FILE_COUNT_MAX_EXCEEDED 1
#define FILE_ALREADY_EXISTS 2
#define FILE_NAME_INVALID 3
#define FILE_NOT_FOUND 1

// ? Declaration of functions that 
// ? this header will have, whose 
// ? definitions will be in Core.c
void InitializeFileSystem();
int RemoveFile(char* Name);
int CreateFile(char* Name);
char* GetNamePerIdentifier(int Identifier);
int GetIdentifierPerName(char* Name);
int FilesInSystem();
bool FileExists(char* Name);
int FileSize(char* Name);
int ReadFile(char* Name, char* Output);
int WriteFile(char* Name, char* Data, unsigned long Depth);
int WritesFile(char* Name, char* Data);
int ClearFile(char* Name);