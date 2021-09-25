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

// ? The help function will show all the commands 
// ? available in the operating system.
void CKHelp(){
    kPrintCharacter('\n');
    KernelPrintString("Available Commands<Command:Description>:\n\n");
    KernelPrintString("neofetch         Show information about your system.\n");
    KernelPrintString("memstat          Get allocated memory usage.\n");
    KernelPrintString("memtest          Allocate memory for test.\n");
    KernelPrintString("random           Generate a random number, yeah, black magic.\n");
    KernelPrintString("touch            Create a new file.\n");
    KernelPrintString("rm               Delete a file :(.\n");
    KernelPrintString("theme-purple     Activate the purple on black theme.\n");
    KernelPrintString("theme-red        Activate the red on white theme.\n");
    KernelPrintString("theme-black      Activate the black on white theme.\n");
    KernelPrintString("theme-white      Activate the white on black theme.\n");
    KernelPrintString("theme-blue       Activate the white on blue theme.\n");
    KernelPrintString("theme-cyan       Activate the white on cyan theme.\n");
    KernelPrintString("theme-gray       Activate the gray on black theme.\n");
    KernelPrintString("theme-default    Activate the default Chitty theme.\n");
    KernelPrintString("fvi              Read file content.\n");
    KernelPrintString("fed              Write in a file.\n");
    KernelPrintString("help             Displays the list of available commands.\n");
    KernelPrintString("ls               Show the available files you have on your instance.\n");
    KernelPrintString("exit             You log out of Chitty Shell :(\n");
    KernelPrintString("clear            You clean the screen, yeah, very very dirty.\n");
    KernelPrintString("hacker           You become a Russian hacker.\n");
    KernelPrintString("version          Current version of Chitty.\n");
}