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

// ? The function allows removing a file, when 
// ? it is called, the user will be asked to 
// ? type the name of the file to be deleted, then 
// ? the corresponding function will be called, if its 
// ? return is a FILE_NOT_FOUND, a message will be displayed 
// ? indicating that the file is I request delete was not found.
void CKRemoveFile(){
    KernelPrintString("Enter file name: ");
    char FileToRemove[255];
    KernelInputString(FileToRemove);
    if(RemoveFile(FileToRemove) == FILE_NOT_FOUND)
        KernelPrintString("\nFile not found!\n");
}