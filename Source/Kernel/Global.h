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

// ? Global macro declarations 
// ? to be used at the kernel level.

#define DISPLAY_THEME GREEN_ON_BLACK
#define KERNEL_STARTUP StartShell();

#define KERNEL_MEMORY_OFFSET_START 0xffffff
#define KERNEL_MEMORY_OFFSET_END 0xffffffff
#define MEMORY_INDEX_BASE_SIZE 10000

#define INCLUDED_VERSION
#define OS_VERSION "1.0.0"

#define INCLUDED_MESSAGES
#define KERNEL_INFO_ENTERED "Entering the Kernel...\n"
#define KERNEL_INFO_INITIALIZE_START "Connected to the kernel, initializing...\n"
#define KERNEL_INFO_INITIALIZE_DONE "Initialized successfully.\n"
#define KERNEL_INFO_WELCOME "Welcome to ChittyOS!\n"
#define KERNEL_INFO_SHELL_WELCOME "Type 'help' to get a list of commands.\n"
#define KERNEL_INFO_SHELL_UNKNOWN_COMMAND "Unknown command.\n"
#define KERNEL_PANIC_MEMORY_INDEX_FULL "Kernel index is full, probably many KernelMalloc() calls...\n"
#define KERNEL_PANIC_MEMORY_FULL "Kernel memory is full, no enough ram.\n"
#define FIRMWARE_ERROR_ISR_EXCEPTION "ISR exception."
#define FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING "Could not find SMBIOS etntry.\n"