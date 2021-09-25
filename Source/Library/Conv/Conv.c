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

#include "Conv.h"

// ? Function that will convert unsigned long 
// ? values ​​to string, receives a variable 
// ? which will be the Output, since this must 
// ? be a string, and as a second parameter it 
// ? receives the unsigned long to which you 
// ? want to convert a string.
void Uint32ToString(char* Output, unsigned long Number){
    // * Creating a constant that will store an array of digits.
    const char Digits[10] = "0123456789";

    // * Creating two iterators, a main and a helper.
    int Iterator = 0, SubIterator;

    // * Creating two variables plus a Remains to 
    // * know how many characters are left 
    // * and another Character to save the character.
    unsigned Remains;
    char Character;

    do{
        // * We assign a value to the variable 
        // * Remains which will be the result 
        // * of the arithmetic operation where 
        // * the remainder of Number in 10 is obtained.
        Remains = Number % 10;

        // * We assign using the string type 
        // * variable that is the output the 
        // * value of Digits using the index 
        // * that resulted in the arithmetic operation.
        Output[Iterator++] = Digits[Remains];

        // * We reassign the value of the 
        // * Number variable by its 
        // * current value between 10.
        Number /= 10;
    }while(Number != 0);

    // * We assign to Output using Iterator index
    // * after the do while cicle
    // * the '\0' character (WHITESPACE)
    Output[Iterator] = '\0';

    // * We create another for loop using the 
    // * SubIterator, which will run until it is less than Iterator.
    for(SubIterator = 0, SubIterator--; SubIterator < Iterator; SubIterator++, Iterator--){
        Character = Output[SubIterator];
        Output[SubIterator] = Output[Iterator];
        Output[Iterator] = Character;
    }
}

// ? Function that converts a string to an 
// ? integer, the function, as you might 
// ? think, receives a string which will be 
// ? the one that will be converted to an integer.
int StringToInteger(char* String){
    // * We create an integer which will be 
    // * the result and the variable that 
    // * will be returned, we will initialize it to 0.
    int Result = 0;

    // * We create an iterator so that its instructions 
    // * are fulfilled as long as the String [Iterator] is 
    // * different than '\ 0', that is, as long as the index of 
    // * the string in memory is different than a blank space.
    for(int Iterator = 0; String[Iterator] != '\0'; ++Iterator)
        Result = Result * 10 + String[Iterator] - '0';

    // * The result is returned: D
    return Result;
}

// ? Function that will convert a uint32 to 
// ? a hex, the function receives a variable 
// ? that will act as Output and receives an 
// ? unsinged unsigned which will be the number 
// ? to convert to hex.
void Uint32ToHex(char* Output, unsigned long Number){
    // * Creating a constant that will store an array of digits.
    const char Digits[16] = "0123456789ABCDEF";

    // * Creating two iterators, a main and a helper.
    int Iterator = 0, SubIterator;

    // * Creating two variables plus a Remains to 
    // * know how many characters are left 
    // * and another Character to save the character.
    unsigned Remains;
    char Character;

    do{
        // * We assign a value to the variable 
        // * Remains which will be the result 
        // * of the arithmetic operation where 
        // * the remainder of Number in 16 is obtained.
        Remains = Number % 16;

        // * We assign using the string type 
        // * variable that is the output the 
        // * value of Digits using the index 
        // * that resulted in the arithmetic operation.
        Output[Iterator++] = Digits[Remains];

        // * We reassign the value of the 
        // * Number variable by its 
        // * current value between 16.
        Number = Number / 16;
    }while(Number != 0);
    
    // * We assign to Output using Iterator index
    // * after the do while cicle
    // * the '\0' character (WHITESPACE)
    Output[Iterator] = '\0';

    // * We create another for loop using the 
    // * SubIterator, which will run until it is less than Iterator.
    for(SubIterator = 0, Iterator--; SubIterator < Iterator; SubIterator++, Iterator--){
        Character = Output[SubIterator];
        Output[SubIterator] = Output[Iterator];
        Output[Iterator] = Character;
    }
}

// ? Function that will convert a uint to 
// ? string, the function receives a first 
// ? parameter which will be the output, that
// ? is, the uint as string and then the second 
// ? parameter is the unsigned int to convert 
// ? to a string bby <3.
void UintToString(char* Output, unsigned int Number){
    Uint32ToString(Output, (unsigned long)Number);
}

// ? Function that will convert an int to a 
// ? string, receives the output as a 
// ? parameter, that is, the function 
// ? that will store the integer as a string 
// ? and therefore the second parameter will 
// ? be the integer to be converted.
void IntToString(char* Output, int Number){
    // * We check if the number is 
    // * less than 0, if it is, we 
    // * will do black magic.
    if(Number < 0){
        // * The first value in 
        // * memory of the output 
        // * character array will be a '-0.
        Output[0] = '-';

        // * We increase index
        ++Output;

        // * We subtract Number 
        // * with the same value xd.
        Number -= Number;
    }
    UintToString(Output, Number);
}

// ? Function that will serve to convert a 
// ? short to a string, the function receives 
// ? as the first parameter a variable that will 
// ? act as an output, that is, the short as a 
// ? string, and of course the second parameter 
// ? will be the short that you want to convert to a string.
void ShortToString(char* Output, short Number){
    IntToString(Output, (int)Number);
}

// ? Function that will serve to convert an 
// ? unsigned long to a char, receives as a 
// ? parameter the unsigned long to convert to character.
unsigned char Uint32ToChar(unsigned long Number){
    switch(Number){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
    }
}

// ? Function that converts an unsigned int to 
// ? a char, receives as a parameter the 
// ? unsigned int to convert to char.
unsigned char UintToChar(unsigned int Number){
    return Uint32ToChar((unsigned long)Number);
}

// ? Function that converts a char to a 
// ? hex, receives as a parameter a character 
// ? which will be converted to hex.
unsigned char CharToHex(char Character){
    switch(Character){
        case '0':
            return 0x0;
        case '1':
            return 0x1;
        case '2':
            return 0x2;
        case '3':
            return 0x3;
        case '4':
            return 0x4;
        case '5':
            return 0x5;
        case '6':
            return 0x6;
        case '7':
            return 0x7;
        case '8':
            return 0x8;
        case '9':
            return 0x9;
        case 'a': 
            return 0xA;
        case 'A': 
            return 0xA;
        case 'b': 
            return 0xB;
        case 'B': 
            return 0xB;
        case 'c': 
            return 0xC;
        case 'C': 
            return 0xC;
        case 'd': 
            return 0xD;
        case 'D': 
            return 0xD;
        case 'e': 
            return 0xE;
        case 'E': 
            return 0xE;
        case 'f': 
            return 0xF;
        case 'F': 
            return 0xF;
    }
}