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

#include "../../Firmware/Port/Port.h"
#include "../../Library/Type.h"
#include "../../Kernel/Global.h"
#include "Color.h"

// ? Declaration of macros that will be 
// ? used in Display.c and in other 
// ? programs that include this file.
#define VIDEO_MEMORY_OFFSET (unsigned int *) 0xb8000
#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define DISPLAY_SCROLL_DEBUG 80
#define DISPLAY_SCROLL_DETECTION_DEBUG -2
#define INITIALIZE_VIDEO char* VideoMemory = (char*) VIDEO_MEMORY_OFFSET;

// ? Declaration of functions 
// ? that can be used by other 
// ? files that include this one.
void kPrintCharacter(char Character);
void kPrintCharacterWithColor(char Character, char Color);
void kPrint(char* String, unsigned long Depth);
void kPrintWithColor(char* String, unsigned long Depth, unsigned char Color);
void ClearDisplay();
void DisplayScroll();
void DisplayTheme(char Color);
void DeleteDisplay();
void InitializeDisplay();
void SetCursorPosition(unsigned int Column, unsigned int Row);