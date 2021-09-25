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

// ? The function allows reading a file, when it is 
// ? called, the user is asked for the name of the file 
// ? and then sent to the function loaded to read the 
// ? file, which will store the information in the 
// ? variable that is indicated and then be displayed on the screen.
void CKReadFile(){
  char* Filename = (char*) KernelMalloc(256);
  KernelPrintString("Enter file name: ");
  KernelInputString(Filename);
  char* Content = (char*) KernelMalloc(FileSize(Filename));
  if(ReadFile(Filename, Content) == FILE_NOT_FOUND)
    KernelPrintString("\nFile not found!\n");
  KernelPrintString(Content);
  kPrintCharacter('\n');
  KernelFree(Filename);
  KernelFree(Content);
}