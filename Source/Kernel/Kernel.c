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

#include "Global.h"
#include "IO/IO.h"
#include "Message/Message.h"
#include "Memory/Memory.h"
#include "Shell.h"
#include "../Firmware/ISR/ISR.h"
#include "../Firmware/SMBios/SMBios.h"
#include "../FileSystem/Core/Core.h"
#include "../Library/Type.h"
#include "../Library/Rand/Rand.h"

void main(){
    // ? Showing the endline in screen
    kPrintCharacter('\n');
    
    // ? Showing the Kernel Entered message
    KernelInfo(KERNEL_INFO_ENTERED);

    // ? Showing the Kernel Start message
    KernelInfo(KERNEL_INFO_INITIALIZE_START);
    
    // ? Setting display theme
    DisplayTheme(DISPLAY_THEME);
    
    // ? Setting all ISR Handlers
    IsrInstall(); 
    
    // ? Initialize Keyboard
    InitializeKeyboard();
    
    // ? Reserve Memory
    KernelMalloc(2);
    
    // ? Get hardware information
    InitializeSMBios();
    
    // ? Initialize some display variables
    InitializeDisplay();
    
    // ? Initialize file system
    InitializeFileSystem();

    // ? Set start seed for Library/Rand/Rand.h
    InitializeRand();

    // ? Showing the endline in screen
    kPrintCharacter('\n');

    // ? Showing the Kernel Done message
    KernelInfo(KERNEL_INFO_INITIALIZE_DONE);

    // ? Showing the Kernel Welcome message
    KernelInfo(KERNEL_INFO_WELCOME);
    
    // ? Start ChittyOS Shell
    KERNEL_STARTUP
}