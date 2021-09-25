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

#include "Message.h"

// ? Print function to display 
// ? information on the console, receives 
// ? a parameter which will be the 
// ? text to display on the screen.
void KernelInfo(char* Message){
    KernelPrintString("Chitty [INFO] > ");
    KernelPrintString(Message);
}

// ? Print function to display 
// ? warning on the console, receives 
// ? a parameter which will be the 
// ? text to display on the screen.
void KernelWarning(char* Message){
    KernelPrintString("Chitty [WARNING] > ");
    KernelPrintString(Message);
}

// ? Print function to display 
// ? error on the console, receives 
// ? a parameter which will be the 
// ? text to display on the screen.
void KernelError(char* Message){
    KernelPrintString("Chitty [ERROR] > ");
    KernelPrintString(Message);
}

// ? Print function to display 
// ? panic on the console, receives 
// ? a parameter which will be the 
// ? text to display on the screen.
void KernelPanic(char* Message){
    KernelPrintString("Chitty [PANIC] > ");
    KernelPrintString(Message);
    while(1){};
}