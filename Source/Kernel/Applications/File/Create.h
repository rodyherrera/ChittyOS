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

// ? The function allows creating a file in the system, when 
// ? this is called the user will be asked to type the 
// ? name of the file then the function in charge of 
// ? creating the file will be called, then a series 
// ? of validations will be made as if the file 
// ? exists, If the file contains invalid characters in 
// ? its name or if the number of files in the system reached 
// ? its limit, depending on the error, this will be informed 
// ? to the user on the screen with a message.
void CKCreateFile(){
    KernelPrintString("File name > ");
    char* FileToMake = KernelMalloc(512);
    KernelInputString(FileToMake);
    int Response = CreateFile(FileToMake);
    if(Response == FILE_ALREADY_EXISTS)
        KernelPrintString("\nFile already exists!\n");
    else if(Response == FILE_NAME_INVALID){
        KernelPrintString("\nFile name can only contain the following characters:\n");
        KernelPrintString(FS_FILE_NAME_VALID_CHARS);
    }else if(Response == FILE_COUNT_MAX_EXCEEDED)
        KernelPrintString("\nThere are too many files!");
    kPrintCharacter('\n');
    KernelFree(FileToMake);
}