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
#include "../Library/Type.h"
#include "../Library/String/String.h"
#include "../Library/Rand/Rand.h"
#include "../Drivers/Display/Color.h"
#include "Memory/Memory.h"
#include "Message/Message.h"
#include "IO/IO.h"
#include "../Firmware/SMBios/SMBios.h"
#include "Global.h"
#include "../FileSystem/Core/Core.h"

// ? Variable that stores the theme of the 
// ? operating system, it is defined in this 
// ? place because some applications may require it.
char* ChittyTheme;

#include "Applications/Neofetch/Neofetch.h"
#include "Applications/Help/Help.h"
#include "Applications/File/List.h"
#include "Applications/File/Create.h"
#include "Applications/File/Read.h"
#include "Applications/File/Remove.h"
#include "Applications/File/Write.h"

// ? Defining macros to use in relation to the SHELL
#define SHELL_OK 0x0
#define SHELL_EXIT 0x1
#define SHELL_INPUT_BUFFER 31

// ? Function that will allow redirecting an 
// ? action according to what the user indicates 
// ? as a command in Shell.
unsigned char* ShellInterpreter(char* Command){
    // * Showing the endline in screen
    kPrintCharacter('\n');

    if(StringCompare(Command, "help"))
        CKHelp();

    else if(StringCompare(Command, "ls"))
        CKListFiles();

    else if(StringCompare(Command, "clear"))
        ClearDisplay();

    else if(StringCompare(Command, "rm"))
        CKRemoveFile();

    else if(StringCompare(Command, "fvi"))
        CKReadFile();

    else if(StringCompare(Command, "fed"))
        CKWriteFile();

    else if(StringCompare(Command, "touch"))
        CKCreateFile();

    else if(StringCompare(Command, "neofetch"))
        CKNeofetch();

    else if(StringCompare(Command, "hacker")){
        DisplayTheme(LIGHT_GREEN_ON_BLACK);
        ChittyTheme = "LIGHT_GREEN_ON_BLACK";
        KernelPrintStringWithColor("OMGGG You are a fucking RUSSSIAN HACKER RIGHT NOW!\n", RED_ON_WHITE);

    }else if(StringCompare(Command, "theme-blue")){
        DisplayTheme(WHITE_ON_BLUE);
        ChittyTheme = "WHITE_ON_BLUE";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-red")){
        DisplayTheme(RED_ON_WHITE);
        ChittyTheme = "RED_ON_WHITE";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-purple")){
        DisplayTheme(PURPLE_ON_BLACK);
        ChittyTheme = "PURPLE_ON_BLACK";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-black")){
        DisplayTheme(BLACK_ON_WHITE);
        ChittyTheme = "BLACK_ON_WHITE";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-white")){
        DisplayTheme(WHITE_ON_BLACK);
        ChittyTheme = "WHITE_ON_BLACK";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-default")){
        DisplayTheme(DISPLAY_THEME);
        ChittyTheme = "DEFAULT_THEME";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "theme-cyan")){
        DisplayTheme(WHITE_ON_CYAN);
        ChittyTheme = "WHITE_ON_CYAN";
        KernelPrintString("OK\n");
    
    }else if(StringCompare(Command, "theme-gray")){
        DisplayTheme(WHITE_ON_GRAY);
        ChittyTheme = "WHITE_ON_GRAY";
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "version")){
        KernelPrintString("Version: ");
        KernelPrintString(OS_VERSION);
        kPrintCharacter('\n');
    
        KernelPrintString("Remember drink water bby <3!");
        kPrintCharacter('\n');

    }else if(StringCompare(Command, "random")){
        KernelPrintUnsignedInteger(Rand() % 100);
        kPrintCharacter('\n');
    
    }else if(StringCompare(Command, "memstat")){
        KernelPrintString("Memory Usage");
        KernelPrintString("\nTotal: ");
        KernelPrintUint32(MemoryUsage());
        KernelPrintString("\nEffective: ");
        KernelPrintUint32(MemoryUsageEffective());
        kPrintCharacter('\n');

    }else if(StringCompare(Command, "memtest")){
        KernelMalloc(1);
        KernelPrintString("OK\n");

    }else if(StringCompare(Command, "exit")){
        ClearDisplay();
        return (unsigned char*) SHELL_EXIT;

    }else
        KernelPrintString(KERNEL_INFO_SHELL_UNKNOWN_COMMAND);

    // * The value of the SHELL_OK status 
    // * macro is returned, that 
    // * is, everything went correct.
    return SHELL_OK;
}

// ? Function that will be 
// ? called at the end of all the
// ? kernel startup loads.
void StartShell(){
    // * Setting the default 
    // * theme for the operating system.
    ChittyTheme = "DEFAULT_THEME";

    // * Creating a variable that will store 
    // * the command entered by the user with 
    // * a maximum set of characters set in the 
    // * SHELL_INPUT_BUFFER macro
    char Command[SHELL_INPUT_BUFFER];
    
    for(unsigned int Iterator = 0; Iterator < SHELL_INPUT_BUFFER; ++Iterator)
        Command[Iterator] = (char) 0;
    
    // * Creating a variable that will 
    // * store the Response of the command entered 
    // * by the user, probably SHELL_OK
    unsigned char* Response;
    
    // * Showing the endline in screen
    kPrintCharacter('\n');
    
    // * Showing the welcome message to Chitty's Shell.
    KernelPrintString(KERNEL_INFO_SHELL_WELCOME);

    while(true){
        // * Showing the endline in screen
        kPrintCharacter('\n');

        // * Creating an input for the user to enter the command.
        KernelPrintString("Chitty > ");

        // * Saving the data that the user enters in 
        // * the Command variable that has been created.
        KernelInputString(Command);

        // * We store the Response 
        // * of the shell match call in the Response variable.
        Response = ShellInterpreter(Command);

        // * If the Response variable does 
        // * not have a SHELL_OK if it does not 
        // * have a SHELL_EXIT, a break will be made 
        // * in the infinite while loop to close the Shell
        if(Response == (unsigned char*) SHELL_EXIT)
            break;
        
        // * We clean the content of the Command variable.
        StringClear(Command);
    }
}