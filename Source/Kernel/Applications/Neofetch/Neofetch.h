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

// ? The NeoFetch function will display system 
// ? information on the screen, it will include the 
// ? operating system, the BIOS identifier, its 
// ? version, memory usage and memory total, the current 
// ? operating system topic and creator information 
// ? with an important message.
void CKNeofetch(){
    kPrintCharacter('\n');
    KernelPrintString(
          " $$$$$$\\   $$$$$$\\  \n"
          "$$  __$$\\ $$  __$$\\ \n"
          "$$ /  $$ |$$ /  \\__|\n"
          "$$ |  $$ |\\$$$$$$\\  \n"
          "$$ |  $$ | \\____$$\\ \n"
          "$$ |  $$ |$$\\   $$ |\n"
          " $$$$$$  |\\$$$$$$  |\n"
          " \\______/  \\______/ \n");
    SetCursorPosition(23, 16);
    KernelPrintString("OS: ChittyOS ");
    KernelPrintString(OS_VERSION);
    SetCursorPosition(23, 17);
    KernelPrintString("BIOS Identifier: ");
    KernelPrintString(SMBiosGetName());
    SetCursorPosition(23, 18);
    KernelPrintString("BIOS Version: ");
    KernelPrintString(SMBiosGetVersion());
    SetCursorPosition(23, 19);
    KernelPrintString("Memory: ");
    KernelPrintUint32(MemoryUsage());
    KernelPrintString("/");
    KernelPrintUint32(TotalMemory());
    SetCursorPosition(23, 20);
    KernelPrintString("Theme: ");
    KernelPrintString(ChittyTheme);
    SetCursorPosition(23, 22);
    KernelPrintString("https://github.com/codewithrodi/");
    SetCursorPosition(23, 23);
    KernelPrintString("Remember drink much water bby <3.");
    SetCursorPosition(0, 24);
    kPrintCharacter('\n');
}