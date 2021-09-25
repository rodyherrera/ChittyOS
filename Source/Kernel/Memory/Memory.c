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

#include "Memory.h"

// ? Variable that will contain a set of 
// ? characters with a maximum range defined 
// ? by the value of the macro MEMORY_INDEX_BASE_SIZE
unsigned char* MemoryIndex [MEMORY_INDEX_BASE_SIZE];

// ? Function that will return the 
// ? variable that contains the set 
// ? of index characters in memory.
unsigned char* GetMemoryIndex(){
    return (unsigned char*) MemoryIndex;
}

// ? Function that will allow you to reserve 
// ? memory, as you can see, the function receives 
// ? the maximum memory size that you want to reserve.
void* KernelMalloc(unsigned long Size){
    // * Creating an integer unsigned 
    // * variable that will act as an iterator 
    // * so it will be initialized to 0, being 
    // * an iterator it will never be less than 
    //*  0 so it will be unsigned :).
    unsigned int Iterator = 0;
    
    while(true){
        while(MemoryIndex[Iterator] != MEMORY_EMPTY)
            Iterator += 2;

        // ? By declaring variables 
        // ? that will be used within the while loop.
        unsigned char* LastPageEnd = MemoryIndex[Iterator - 1];
        unsigned int NextPageStartIdentifier = Iterator;
        
        // * As long as the value of the memory array in the 
        // * index that indicates the value of the 
        // * NextPageStartIdentifier variable is an 
        // * empty memory value, we will increase the index.
        while(MemoryIndex[NextPageStartIdentifier] == MEMORY_EMPTY)
            ++NextPageStartIdentifier;
        
        // * Once the memory index is found that is not 
        // * null, we are going to verify that the value in 
        // * memory using the index in the memory index matrix 
        // * subtracted with the value of the LastPageEnd 
        // * variable is less than size, we are going to 
        // * execute a series of instructions.
        if(MemoryIndex[NextPageStartIdentifier] - LastPageEnd > Size){
            if(Iterator >= (unsigned int) MEMORY_INDEX_BASE_SIZE)
                KernelPanic(KERNEL_PANIC_MEMORY_INDEX_FULL);
            if(Size + (unsigned long) LastPageEnd + 1 >= KERNEL_MEMORY_OFFSET_END)
                KernelPanic(KERNEL_PANIC_MEMORY_INDEX_FULL);
            MemoryIndex[Iterator] = LastPageEnd + 1;
            MemoryIndex[Iterator + 1] = MemoryIndex[Iterator] + Size;
            return (void *) MemoryIndex[Iterator];
        }
    }
}

// ? Function that will serve to 
// ? free the memory of the 
// ? kernel, receives the Malloc pointer.
void KernelFree(void* Memory){
    // * Identifier and/or iterator to use in 
    // * the while loop and iterate if the 
    // * reserved memory was not found in the indexed memory.
    unsigned int Identifier = 0;
    while(MemoryIndex[Identifier] != Memory)
        Identifier += 2;

    MemoryIndex[Identifier] = MEMORY_EMPTY;
    MemoryIndex[Identifier + 1] = MEMORY_EMPTY;
}

// ? Function to get the memory 
// ? in use by the operating system.
unsigned long MemoryUsage(){
    // * Variables that will be used within the 
    // * loop, Usage will be the variable 
    // * that will be returned.
    unsigned int Iterator = 2;
    unsigned long Usage = 0;

    // * As long as the value of the variable 
    // * Iterator is less than the value of 
    // * the macro MEMORY_INDEX_BASE_SIZE
    while(Iterator < MEMORY_INDEX_BASE_SIZE){
        // * If the value of the Iterator in
        // * the memory set is NOT null, the 
        // * value of the Usage memory will be increased.
        if(MemoryIndex[Iterator] != MEMORY_EMPTY)
            Usage += (unsigned long) MemoryIndex[Iterator + 1] - (unsigned long) MemoryIndex[Iterator];

        // * Increasing the value of the variable Iterator by 2.
        Iterator += 2;
    }

    // * Returning the value of the Usage variable.
    return Usage;
}

// ? Function that will return the 
// ? total memory allocated for the operating system.
unsigned long TotalMemory(){
    // * The value of the arithmetic operation will 
    // * be returned where the value of the macro 
    // * KERNEL_MEMORY_OFFSET_END is subtracted with 
    // * the value of the macro KERNEL_MEMORY_OFFSET_START
    return KERNEL_MEMORY_OFFSET_END - KERNEL_MEMORY_OFFSET_START;
}

// ? Function that will return effective memory usage
unsigned long MemoryUsageEffective(){
    // * Variables to be used within the while loop
    unsigned int Iterator = 2;
    unsigned long Usage = 0;

    // * As long as the value of the variable Iterator 
    // * is less than the value of 
    // * the macro MEMORY_INDEX_BASE_SIZE
    while(Iterator < MEMORY_INDEX_BASE_SIZE){
        // * If the index the value of the memory 
        // * according to the value of the variable Iterator 
        // * increased by 1 is greater than the value of the 
        // * variable Usage, the value of the variable Usage 
        // * will be reassigned by the value found in the 
        // * indexes of the memory using as index the value of 
        // * the variable Iterator increased by one.
        if((unsigned long) MemoryIndex[Iterator + 1] > Usage)
            // * Reassigning the value of the Usage variable 
            // * as mentioned above, it casts an unsigned long 
            // * because it is the type of the Usage variable, if 
            // * this is not done it gives warnings when compiling :(.
            Usage = (unsigned long) MemoryIndex[Iterator + 1];

        // * Increasing the value of the variable Iterator by two.
        Iterator += 2;
    }

    // * Returning the result of the arithmetic 
    // * operation of the value of the macro 
    // * KERNEL_MEMORY_OFFSET_START increased by 1, then 
    // * the value of that arithmetic operation is subtracted 
    // * by the value of the Usage variable.
    return Usage - (KERNEL_MEMORY_OFFSET_START + 1);
}

// ? Function to copy the memory, the function receives 
// ? a first parameter which is an unsigned char which 
// ? will be the destination of the memory copy, then the 
// ? second parameter will also be an unsigned char which will be 
// ? the Source or the memory that you want to copy, the third 
// ? parameter is the size that the new copy will get.
void CopyMemory(unsigned char* Destinity, unsigned char* Source, unsigned long Size){
    for(unsigned long Iterator = 0; Iterator < Size; ++Iterator)
        Destinity[Iterator] = Source[Iterator];
}