; ***
; * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
; * Licensed under the MIT license. See LICENSE file in the project root 
; * for full license information.
; *
; * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
; *
; * For related information - https://github.com/codewithrodi/ChittyOS/
; *
; * = This project has been done for no profit and just to test 
; * = my knowledge and skills, no contributions or bug fixes are expected.
; *
; * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
; ***

[bits 16]
SwitchToProtectedMode:
    ; * 1. Disable interrupts
    cli

    ; * 2. Load the GDT Descriptor
    lgdt [GDTDescriptor]
    mov eax, cr0

    ; * 3. Set 32-BIT mode bit in cr0
    or eax, 0x1
    mov cr0, eax

    ; * 4. Far jump by using a different segment
    jmp kCodeSegment:InitializeProtectedMode

; ? Using 32-BIT instructions
[bits 32]
InitializeProtectedMode:
    ; * Update the segment registers
    mov ax, kDataSegment 
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; * 6. Update the stack right at 
    ; * the top of the free space
    mov ebp, 0x90000 
    mov esp, ebp

    ; * 7. Call a well-known 
    ; * label wuth useful code
    call BeginProtectedMode