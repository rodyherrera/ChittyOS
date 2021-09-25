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

#include "Rand.h"

// ? By declaring a variable that 
// ? will then store the seed for Rand and
// ? this is not initialized because by 
// ? default C assigns it its maximum rank.
int RandSeed;

// ? Function that will serve to initialize Rand.
void InitializeRand(){
    // * Like the other variable, it is not 
    // * initialized because the 
    // * language assigns its value to it.
    int RandomData;

    // * Setting the seed for Rand.
    RandSeed = RandomData + 2;
}

// ? Function that will serve to generate rand 
// ? using the congruential generator
int RandLinearCongruentialGenerator(int x){
  int 
    a = 1103515245,
    c = 12345,
    m = 2147483648,
    result = (a * x + c) % m;
    if(result < 0) result = -result;
    return result;
}

// ? Rand function that will serve 
// ? to generate the random value
int Rand(){
    // * Storing a random value in 
    // * the seed by calling the congruential generator
    RandSeed = RandLinearCongruentialGenerator(RandSeed);

    // * Returning the generated value.
    return RandSeed;
}