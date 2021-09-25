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

// ? The function allows writing to the 
// ? file, when this is called first the name 
// ? of the file where you want to write is 
// ? requested, then the user is asked for 
// ? the content that the e-file will have, after 
// ? that the corresponding function is called, if its 
// ? return status is a FILE_NOT_FOUND it will show on 
// ? the screen that the file was not found.
void CKWriteFile(){
    KernelPrintString("Enter file name: ");
    char* Filename = (char*) KernelMalloc(256);
    StringClear(Filename);
    KernelInputString(Filename);
    char* Content = (char*) KernelMalloc(256);
    StringClear(Content);
    KernelPrintString("\nEnter content: ");
    KernelInputString(Content);
    StringConcat(Content, "\n");
    ClearFile(Filename);
    if(WritesFile(Filename, Content) == FILE_NOT_FOUND)
        KernelPrintString("\nFile not found!\n");
    KernelFree(Filename);
    KernelFree(Content);
}