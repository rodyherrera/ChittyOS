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

#include "IO.h"
#include "../../Library/Conv/Conv.h"

// ? Function that will allow writing a 
// ? string with a color on the Kernel 
// ? side, as you can see, the function 
// ? receives a string as the first parameter 
// ? and a color as the second, which must belong
// ? to the macros defined in Source/Display/Color.h
void KernelPrintStringWithColor(char* String, char Color){
    // * We carry out a cycle which will execute 
    // * certain instructions as long as the pointer 
    // * in memory of the String variable does not 
    // * indicate a value of 0 which would be a null value.
    while(*String != 0){
        // * Calling the function found in the display 
        // * drivers to perform the painting with character.
        kPrintCharacterWithColor(*String, Color);

        // * Increasing a value in memory 
        // * the pointer where the string is located.
        ++String;
    }
}

// ? Function that will allow printing a 
// ? string on the Kernel side, the function 
// ? receives a parameter that as you can 
// ? think is the string that you want to print.
void KernelPrintString(char* String){
    // * Calling the previous function that allows 
    // * you to print a color, but since we only 
    // * want to print a string without color, we 
    // * will send it as a transparent color.
    KernelPrintStringWithColor(String, TRANSPARENT);
}

// ? Function that will allow to print a whole 
// ? number on the side of the Kernel, receives 
// ? as a parameter the whole number that you want to print.
void KernelPrintInteger(int Number){
    // * Creating a variable which will store the 
    // * received number as a string when the IntToString 
    // * function of the conversions library is called.
    char Output[12];

    // * Doing purple magic with the number and the Output variable.
    IntToString(Output, (int) Number);

    // * Showing the number stored as a string in 
    // * the output variable on the screen.
    KernelPrintString(Output);
}

// ? Function that allows you to print an 
// ? unsigned integer, receives a parameter 
// ? which is the unsigned integer that you want to print.
void KernelPrintUnsignedInteger(unsigned int Number){
    // * Like the previous function we will create an 
    // * Output variable that will store the received 
    // * unsigned number in a string and it will be 
    // * stored in this variable.
    char Output[12];

    // * Doing the yellow magic.
    IntToString(Output, Number);

    // * Showing unsigned integer now 
    // * converted to string on screen.
    KernelPrintString(Output);
}

// ? Function that will show an unsigned long on the 
// ? screen on the kernel side, this function receives
// ? as a parameter the unsigned long that you want to show.
void KernelPrintUint32(unsigned long Number){
    // * Like the other functions, a set of characters is
    // * created to later convert the unsigned long into a 
    // * string and store it in this variable.
    char Output[12];

    // * Doing the red magic.
    Uint32ToString(Output, Number);

    // * Showing the unsigned long integer now
    // * converted to string on the screen
    KernelPrintString(Output);
}

// ? Function that will allow displaying 
// ? a Hex on the kernel side screen, receives as 
// ? a function an unsigned long that 
// ? will be the Hex to be displayed.
void KernelPrintHex(unsigned long Number){
    // * Creating a variable to store the Hex.
    char* Output;

    // * Converting from unsigned long to hex
    Uint32ToHex(Output, Number);

    // * Showing on screen the Output variable that after 
    // * the conversion will save the output, that is, the Hex.
    KernelPrintString(Output);
}

// ? Function that will allow asking the 
// ? user for data, receives a variable
// ? where the value entered by the user will be saved.
void KernelInputString(char* Output){
    // * Creating an iterator, being an 
    // * iterator it will be unsigned 
    // * and will be initialized to 0.
    unsigned long Iterator = 0;
    char Input = 0;
    while(Input != '\n'){
        Input = KeyboardInputCharacter();
        if( (Input == '\b') && (Iterator > 0) ){
            --Iterator;
            DeleteDisplay();
        }else if(Input == '\n')
            Output[Iterator] = 0;
        else if(Input != '\b'){
            kPrintCharacter(Input);
            Output[Iterator] = Input;
            ++Iterator;
        }
    }
}