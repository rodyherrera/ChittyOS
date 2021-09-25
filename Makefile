# /***
# * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
# * Licensed under the MIT license. See LICENSE file in the project root 
# * for full license information.
# *
# * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
# *
# * For related information - https://github.com/rodiihernandezz/ChittyOS/
# *
# * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
# ***

.DEFAULT_GOAL = Production/Distribution/ChittyOS-Image.bin
.PHONY: Clear Run ISO all full

# C Configuration
C_COMPILER ?= gcc -m32
C_FLAGS ?= -ffreestanding -fno-pie -Os -c

# Assembly Configuration
ASM_COMPILER ?= nasm
ASM_FORMAT ?= elf32

# Linker Configuration
LINKER ?= ld -m elf_i386 -s

# Emulator Configuration
EMULATOR ?= qemu-system-i386

# ChittyOS Internal Configuration
# Kernel
KERNEL_C_SOURCESS := $(wildcard Source/Kernel/*.c) 
KERNEL_MESSAGE_C_SOURCES := $(wildcard Source/Kernel/Message/*.c)
KERNEL_MEMORY_C_SOURCES := $(wildcard Source/Kernel/Memory/*.c)
KERNEL_IO_C_SOURCES := $(wildcard Source/Kernel/IO/*.c)

KERNEL_C_OBJECTS := $(patsubst Source/Kernel/%.c, Production/Kernel/%.o, $(KERNEL_C_SOURCESS))
KERNEL_MESSAGE_C_OBJECTS := $(patsubst Source/Kernel/Message/%.c, Production/Kernel/Message/%.o, $(KERNEL_MESSAGE_C_SOURCES))
KERNEL_MEMORY_C_OBJECTS := $(patsubst Source/Kernel/Memory/%.c, Production/Kernel/Memory/%.o, $(KERNEL_MEMORY_C_SOURCES))
KERNEL_IO_C_OBJECTS := $(patsubst Source/Kernel/IO/%.c, Production/Kernel/IO/%.o, $(KERNEL_IO_C_SOURCES))

# Drivers
DRIVER_CURSOR_C_SOURCES := $(wildcard Source/Drivers/Cursor/*.c)
DRIVER_DISPLAY_C_SOURCES := $(wildcard Source/Drivers/Display/*.c)
DRIVER_KEYBOARD_C_SOURCES := $(wildcard Source/Drivers/Keyboard/*.c)

DRIVER_CURSOR_C_OBJECTS := $(patsubst Source/Drivers/Cursor/%.c, Production/Drivers/Cursor/%.o, $(DRIVER_CURSOR_C_SOURCES))
DRIVER_DISPLAY_C_OBJECTS := $(patsubst Source/Drivers/Display/%.c, Production/Drivers/Display/%.o, $(DRIVER_DISPLAY_C_SOURCES))
DRIVER_KEYBOARD_C_OBJECTS := $(patsubst Source/Drivers/Keyboard/%.c, Production/Drivers/Keyboard/%.o, $(DRIVER_KEYBOARD_C_SOURCES))

# Firmware
FIRMWARE_IDT_C_SOURCES := $(wildcard Source/Firmware/IDT/*.c)
FIRMWARE_ISR_C_SOURCES := $(wildcard Source/Firmware/ISR/*.c)
FIRMWARE_PORT_C_SOURCES := $(wildcard Source/Firmware/Port/*.c)
FIRMWARE_SMBIOS_C_SOURCES := $(wildcard Source/Firmware/SMBios/*.c)

FIRMWARE_IDT_C_OBJECTS := $(patsubst Source/Firmware/IDT/%.c, Production/Firmware/IDT/%.o, $(FIRMWARE_IDT_C_SOURCES))
FIRMWARE_ISR_C_OBJECTS := $(patsubst Source/Firmware/ISR/%.c, Production/Firmware/ISR/%.o, $(FIRMWARE_ISR_C_SOURCES))
FIRMWARE_PORT_C_OBJECTS := $(patsubst Source/Firmware/Port/%.c, Production/Firmware/Port/%.o, $(FIRMWARE_PORT_C_SOURCES))
FIRMWARE_SMBIOS_C_OBJECTS := $(patsubst Source/Firmware/SMBios/%.c, Production/Firmware/SMBios/%.o, $(FIRMWARE_SMBIOS_C_SOURCES))

# Library
LIBRARY_CONV_C_SOURCES := $(wildcard Source/Library/Conv/*.c)
LIBRARY_MATH_C_SOURCES := $(wildcard Source/Library/Math/*.c)
LIBRARY_RAND_C_SOURCES := $(wildcard Source/Library/Rand/*.c)
LIBRARY_STRING_C_SOURCES := $(wildcard Source/Library/String/*.c)

LIBRARY_CONV_C_OBJECTS := $(patsubst Source/Library/Conv/%.c, Production/Library/Conv/%.o, $(LIBRARY_CONV_C_SOURCES))
LIBRARY_MATH_C_OBJECTS := $(patsubst Source/Library/Math/%.c, Production/Library/Math/%.o, $(LIBRARY_MATH_C_SOURCES))
LIBRARY_RAND_C_OBJECTS := $(patsubst Source/Library/Rand/%.c, Production/Library/Rand/%.o, $(LIBRARY_RAND_C_SOURCES))
LIBRARY_STRING_C_OBJECTS := $(patsubst Source/Library/String/%.c, Production/Library/String/%.o, $(LIBRARY_STRING_C_SOURCES))

# File System
FILESYSTEM_CORE_C_SOURCES := $(wildcard Source/FileSystem/Core/*.c)

FILESYSTEM_CORE_C_OBJECTS := $(patsubst Source/FileSystem/Core/%.c, Production/FileSystem/Core/%.o, $(FILESYSTEM_CORE_C_SOURCES))

# C Headers
# Library
LIBRARY_C_HEADERS := $(wildcard Source/Library/*.h)
LIBRARY_C_CONV_HEADERS := $(wildcard Source/Library/Conv/*.h)
LIBRARY_C_MATH_HEADERS := $(wildcard Source/Library/Math/*.h)
LIBRARY_C_RAND_HEADERS := $(wildcard Source/Library/Rand/*.h)
LIBRARY_C_STRING_HEADERS := $(wildcard Source/Library/String/*.h)

# Kernel
KERNEL_C_HEADERS := $(wildcard Source/Kernel/*.h)
KERNEL_C_IO_HEADERS := $(wildcard Source/Kernel/IO/*.h)
KERNEL_C_MEMORY_HEADERS := $(wildcard Source/Kernel/Memory/*.h)
KERNEL_C_MESSAGE_HEADERS := $(wildcard Source/Kernel/Message/*.h)

# Kernel Applications Headers
KERNEL_C_APPLICATIONS_FILE_HEADERS := $(wildcard Source/Kernel/Applications/File/*.h)
KERNEL_C_APPLICATIONS_HELP_HEADERS := $(wildcard Source/Kernel/Applications/Help/*.h)
KERNEL_C_APPLICATIONS_NEOFETCH_HEADERS := $(wildcard Source/Kernel/Applications/Neofetch/*.h)

# Firmware
FIRMWARE_C_IDT_HEADERS := $(wildcard Source/Firmware/IDT/*.h)
FIRMWARE_C_ISR_HEADERS := $(wildcard Source/Firmware/ISR/*.h)
FIRMWARE_C_PORT_HEADERS := $(wildcard Source/Firmware/Port/*.h)
FIRMWARE_C_SMBIOS_HEADERS := $(wildcard Source/Firmware/SMBios/*.h)

# File System
FILESYSTEM_C_HEADERS := $(wildcard Source/FileSystem/*.h)
FILESYSTEM_C_CORE_HEADERS := $(wildcard Source/FileSystem/Core/*.h)

# Drivers
DRIVER_C_CURSOR_HEADERS := $(wildcard Source/Drivers/Cursor/*.h)
DRIVER_C_DISPLAY_HEADERS := $(wildcard Source/Drivers/Display/*.h)
DRIVER_C_KEYBOARD_HEADERS := $(wildcard Source/Drivers/Keyboard/*.h)

# Just one varrrr
C_HEADERS = $(LIBRARY_C_HEADERS) $(LIBRARY_C_CONV_HEADERS) $(LIBRARY_C_MATH_HEADERS) $(LIBRARY_C_RAND_HEADERS) $(LIBRARY_C_STRING_HEADERS) $(KERNEL_C_HEADERS) $(KERNEL_C_IO_HEADERS) $(KERNEL_C_MEMORY_HEADERS) $(KERNEL_C_MESSAGE_HEADERS) $(KERNEL_C_APPLICATIONS_FILE_HEADERS) $(KERNEL_C_APPLICATIONS_HELP_HEADERS) $(KERNEL_C_APPLICATIONS_NEOFETCH_HEADERS) $(FIRMWARE_C_IDT_HEADERS) $(FIRMWARE_C_ISR_HEADERS) $(FIRMWARE_C_PORT_HEADERS) $(FIRMWARE_C_SMBIOS_HEADERS) $(FILESYSTEM_C_HEADERS) $(FILESYSTEM_C_CORE_HEADERS) $(DRIVER_C_CURSOR_HEADERS) $(DRIVER_C_DISPLAY_HEADERS) $(DRIVER_C_KEYBOARD_HEADERS)

# Setting Objects
KERNEL_OBJECTS = $(KERNEL_C_OBJECTS) $(KERNEL_MESSAGE_C_OBJECTS) $(KERNEL_MEMORY_C_OBJECTS) $(KERNEL_IO_C_OBJECTS) Production/Kernel/Entry.o

DRIVER_OBJECTS = $(DRIVER_CURSOR_C_OBJECTS) $(DRIVER_DISPLAY_C_OBJECTS) $(DRIVER_KEYBOARD_C_OBJECTS)

FIRMWARE_OBJECTS = $(FIRMWARE_IDT_C_OBJECTS) $(FIRMWARE_ISR_C_OBJECTS) $(FIRMWARE_PORT_C_OBJECTS) $(FIRMWARE_SMBIOS_C_OBJECTS) Production/Firmware/Interrupt.o

LIB_OBJECTS = $(LIBRARY_CONV_C_OBJECTS) $(LIBRARY_MATH_C_OBJECTS) $(LIBRARY_RAND_C_OBJECTS) $(LIBRARY_STRING_C_OBJECTS)

FILESYSTEM_OBJECTS = $(FILESYSTEM_CORE_C_OBJECTS)

# Build Image
Production/Distribution/ChittyOS-Image.bin: Production/Binary/Kernel.bin Production/Binary/BootSection.bin
	rm -rf Production/Distribution/ChittyOS-Image.bin
	cat Production/Binary/* > $@
	chmod +x Production/Distribution/ChittyOS-Image.bin

# Generate ISO
ISO: $(.DEFAULT_GOAL)
	mkdir -p Production/ISO/
	rm -rf Production/Distribution/ChittyOS.iso
	truncate $(.DEFAULT_GOAL) -s 1200k
	cp $(.DEFAULT_GOAL) Production/ISO/Kernel.bin
	mkisofs -b Kernel.bin -o Production/Distribution/ChittyOS-Image.iso Production/ISO/

# Binary
Production/Binary/Kernel.bin: $(KERNEL_OBJECTS) $(DRIVER_OBJECTS) $(FIRMWARE_OBJECTS) $(LIB_OBJECTS) $(FILESYSTEM_OBJECTS)
	$(LINKER) -o $@ -Ttext 0x1000 $^ --oformat binary

Production/Binary/BootSection.bin: Source/Boot/*
	$(ASM_COMPILER) -f bin -o $@ Source/Boot/Sections.s
	chmod +x $@

# C Files
# Kernel
Production/Kernel/%.o: Source/Kernel/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Kernel/IO/%.o: Source/Kernel/IO/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Kernel/Memory/%.o: Source/Kernel/Memory/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Kernel/Message/%.o: Source/Kernel/Message/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# Drivers
Production/Drivers/Cursor/%.o: Source/Drivers/Cursor/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Drivers/Display/%.o: Source/Drivers/Display/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Drivers/Keyboard/%.o: Source/Drivers/Keyboard/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# Firmware
Production/Firmware/IDT/%.o: Source/Firmware/IDT/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Firmware/ISR/%.o: Source/Firmware/ISR/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Firmware/Port/%.o: Source/Firmware/Port/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Firmware/SMBios/%.o: Source/Firmware/SMBios/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# Library
Production/Library/Conv/%.o: Source/Library/Conv/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Library/Math/%.o: Source/Library/Math/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Library/Rand/%.o: Source/Library/Rand/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

Production/Library/String/%.o: Source/Library/String/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# File System
Production/FileSystem/Core/%.o: Source/FileSystem/Core/%.c $(C_HEADERS)
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# Specific
Production/Kernel/Entry.o: Source/Kernel/Entry.s
	$(ASM_COMPILER) -f $(ASM_FORMAT) -o $@ $<

Production/Firmware/Interrupt.o: $(C_HEADERS) Source/Firmware/Interrupt.s
	$(ASM_COMPILER) -f $(ASM_FORMAT) -o $@ Source/Firmware/Interrupt.s

# Phony
Run: $(.DEFAULT_GOAL)
	$(EMULATOR) Production/Distribution/ChittyOS-Image.bin

Clear:
	rm -rf Production/