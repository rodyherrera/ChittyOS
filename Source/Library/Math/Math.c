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

#include "Math.h"

// ? Pow function to obtain a number raised to 
// ? its exponent, it receives the base which is 
// ? the number to be raised and as a second 
// ? parameter it receives the exponent that 
// ? is the times the number will be multiplied.
double Pow(double Base, double Exponent){
    // * Creating a variable of double type 
    // * because we will not be sure that the 
    // * value is integer or not, this variable 
    // * will start initialized at one.
    double Result = 1;
    
    // * With the help of a while loop we do 
    // * black magic, as long as the 
    // * Exponent is greater than 0
    while(Exponent > 0){
        // * We multiply the value of the Result 
        // * variable by the Base (number to expose)
        Result *= Base;

        // * We decrease the exponent so as
        // *  not to do an infinite while loop.
        --Exponent;
    }

    // * We return the result.
    return Result;
}

// ? Function that will serve 
// ? to obtain the absolute value of a 
// ? number that is indicated as a parameter.
double Abs(double Number){
    // * NASA BLACK MAGIC
    return Number < 0 ? -Number : Number;
}