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

#include "SMBios.h"

// ? Structure that will be used to access the Bios data.
typedef struct {
    char 
        // * This is _SM_
        EntryPointString[4],

        FormattedArea[5],

        // * This is _DMI_
        EntryPointString2[5];

    unsigned char 
        // * This is value summed with all the
        // * values of the table, should be 0 (overflow)
        CheckSum,

        // * Length of entry poiunt table, since version 2.1 of SMBios
        // * this is 0x1F
        Length,
        
        // * Major Version of SMBios
        MajorVersion, 

        // * Minor Version of SMBios
        MinorVersion,

        // * CheckSum for values from EntrypointString2
        // * to end of table
        CheckSum2,

        // * UnUsed
        BCDRevision;

    unsigned short 
        // * Maximun size of SMBios structure
        MaxStructureSize, 

        // * Length of the table containg all the structures
        TableLength, 

        // * Numbers of structures in the table
        NumberOfStructures;
        
    // * Address of the table
    unsigned int TableAddress;
} SMBiosEntryPoint;

typedef struct {
    unsigned char Type, Length;
    unsigned short Handle;
} SMBiosHeader;

// ? Creating an instance of the SMBios Header structure.
SMBiosHeader* SMBIOS_HEADER;

// ? Function that will allow to know the length of 
// ? the BIOS table, this function requires the header of the bios.
unsigned long SMBiosTableLength(SMBiosHeader* BiosHeader){
    // * An iterator is created, as this is an 
    // * iterator it will be unsigned because it 
    // * will never be less than 0 and we initialize it to 0.
    unsigned long Iterator;

    // * Creating a variable that stores the tabulation of the string.
    const char* StringTab = (char *)BiosHeader + BiosHeader->Length;

    for(Iterator = 1; (StringTab[Iterator - 1] != '\0') || (StringTab[Iterator] != '\0'); Iterator++);
    
    // * The length of the header of the bios is 
    // * returned increased by the value of the 
    // * variable Iterator and again increased by one.
    return BiosHeader->Length + Iterator + 1;
}

// ? Function that will allow to obtain the 
// ? following String, the function receives 
// ? a string to guide itself.
char* NextString(char* String){
    // * An iterator is created, as this is an 
    // * iterator it will be unsigned because it 
    // * will never be less than 0 and we initialize it to 0.
    unsigned long Iterator = 0;

    // * We check the memory space of the 
    // * string increasing in the 
    // * iterator, if this is not null we increase the iterator.
    while(*(String + Iterator) != 0)
        ++Iterator;
    
    // * Finally we return the String increased by 
    // * the value of the Iterator variable and 
    // * finally increased by one.
    return String + Iterator + 1;
}

// ? Function that will serve to obtain the version of the BIOS.
char* SMBiosGetVersion(){
    // * By creating a variable that will store the 
    // * version of the BIOS, this will be an arithmetic 
    // * operation which with a cast will be converted 
    // * to the type of value that the variable 
    // * corresponds to.
    char* Result = (char*)(SMBIOS_HEADER->Length + SMBIOS_HEADER);

    return Result;
}

// ? Function that will serve to obtain the name of the BIOS.
char* SMBiosGetName(){
    // * As when we obtain the version of the BIOS 
    // * we do something similar to obtain the name
    char* Result = (char*)(SMBIOS_HEADER->Length + SMBIOS_HEADER);

    // * We return the result of the Next String 
    // * function and send it as parameters the arithmetic 
    // * operation converted to char * using cast.
    return NextString(Result);
}

// ? Function that allows to initialize the BIOS, called in the Kernel.
void InitializeSMBios(){
    // * Creating a variable that will store bytes
    // * and that it will depend on the execution of 
    // * instructions of the while loop.
    char* Memory = (unsigned char *) 0xF0000;

    unsigned char CheckSum;
    while( (unsigned int)Memory < 0x100000){
        if( (Memory[0] == '_') && (Memory[1] == 'S') && (Memory[2] == 'M') && (Memory[3] == '_') ){
            // * Declaration of variables to use in the for loop.
            int Length, Iterator;

            Length = Memory[5];
            CheckSum = 0;

            // * We create a for loop which will increase the 
            // * value of CheckSum by the value of the memory 
            // * array according to the index that will depend 
            // * on the iterator of the for loop.
            for(Iterator = 0; Iterator < Length; Iterator++)
                CheckSum += Memory[Iterator];

            // * We verify that the value of the variable 
            // * CheckSum is 0, in case the value is 0 the 
            // * cycle will be terminated.
            if(CheckSum == 0) 
                break;
        }

        // * We increase the Memory variable by 16
        Memory += 16;
    }
    if( (unsigned int)Memory == 0x100000)
        KernelError(FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING);
    SMBiosEntryPoint* BiosEntryPoint = (SMBiosEntryPoint*) Memory;
    SMBIOS_HEADER = (SMBiosHeader*) BiosEntryPoint->TableAddress;
}