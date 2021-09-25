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

#include "String.h"

// ? Function that allows obtaining the 
// ? length of a String, String 
// ? which will be sent as a parameter.
unsigned int StringLength(char* String){
    // * Creating an unsigned variable since 
    // * the string will not get a negative 
    // * length :V, well this variable will store 
    // * the final length of the string.
    unsigned int Length = 0;

    // * With the help of a while loop we will 
    // * iterate as long as the pointer value is not 0.
    while(*String != 0){
        ++Length;
        ++String;
    }

    // * Finally, when the while loop is 
    // * finished, the variable that 
    // * contains the length of the 
    // * string will be returned.
    return Length;
}

// ? Function that will serve to copy 
// ? a string, receives two parameters 
// ? where the first indicates a variable 
// ? which will be the destination while the 
// ? other will be the source, that 
// ? is, the string to be copied.
void StringCopy(char* Destinity, char* Source){
    // * We create a variable that will 
    // * store the length of the 
    // * string, unsigned because the 
    // * length of the string cannot be negative.
    unsigned int Size = StringLength(Source) + 1;

    // * With the help of a for 
    // * loop, we will match the target 
    // * string character by character.
    for(unsigned int Iterator = 0; Iterator < Size; ++Iterator)
        Destinity[Iterator] = Source[Iterator];
}

// ? Function that will serve to compare a 
// ? string a with a string b, this function 
// ? is mostly used in the Chitty Shell, to 
// ? compare the received argument with a valid 
// ? command, the function receives two parameters 
// ? that, as you can imagine, are string 1 and chain 2.
bool StringCompare(char* StringA, char* StringB){
    // * We create an iterator to 
    // * iterate XDDDDD, this will be long 
    // * because we do not know how big the 
    // * string will be and it will be unsigned 
    // * because logically it will not be negative.
    unsigned long Iterator = 0;

    while(1){
        if(StringA[Iterator] != StringB[Iterator])
            return false;
        else if( (StringA[Iterator] == 0) && (StringB[Iterator] == 0) )
            return true;
        ++Iterator;
    }
}

// ? We create a function that will serve to 
// ? concatenate strings, where the parameters 
// ? that this function receives is 
// ? Base, indicating string 1 to which 
// ? you want to add a new string, and since 
// ? the second parameter is that string that 
// ? you want to add to that base string.
void StringConcat(char* Base, char* Extension){
    StringCopy(Base + StringLength(Base), Extension);
}

// ? Function that will be used to empty a 
// ? string, you will remove its 
// ? characters, you are bad, poor string, but the 
// ? memory will be more comfortable, this function 
// ? receives a Boolean, no, obviously 
// ? it receives a STRING AAAAAAAAA.
void StringClear(char* String){
    // * We create a while loop and with the help 
    // * of a pointer we verify if the value of 
    // * this is not 0, if it is 0 it means that 
    // * its value in memory is null and 
    // * there is no more string xd.
    while(*String != 0){
        // * We set the current memory position to 0.
        *String = 0;
        
        // * We increase our position in memory.
        ++String;
    }
}

// ? Function that will convert a 
// ? character to uppercase, the 
// ? function receives a character :).
char CharToUpper(char* Character){
    char Offset = 'A' - 'a';

    // * BLACK FUCKING MAGIC
    return ((int) Character >= 'a') && ((int) Character <= 'z') ? 
        *(Character + Offset) : *Character;
}

// ? Function that will convert a string 
// ? to uppercase, the function receives a string.
void StringToUpper(char* String){
    // * In the same way that we have done with the 
    // * other functions using the while loop with the 
    // * help of the pointer, now we will obtain the 
    // * value in memory of the pointer and we
    // * will convert it to a string.
    while(*String != 0){
        // * Establishing the new value that will 
        // * have the current position in memory of the string.
        *String = CharToUpper(String);

        // * Increasing position
        ++String;
    }
}