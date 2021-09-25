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

; ? The Sections.s file is the main file in the 
; ? Boot folder of the ChittyOS source code, here the 
; ? imports are made to develop black magic.

[org 0x7c00]
    mov [BootDrive], dl

    ; ? Setting the maximum size for the 
    ; ? stack, value defined in Global.s
    mov bp, [kStackOffset]
    mov sp, bp

    ; ? We show the message when the kernel 
    ; ? is loading in real mode with 32 
    ; ? bit, this message is defined in Global.s
    call PrintNewLine
    mov bx, kRealModeMessage
    call Print
    call PrintNewLine

    ; Loading Chitttttttty Kernel :D
    call LoadKernel

    ; Switch to 16 bit protected mode.
    call SwitchToProtectedMode

    ; For security we divert the flow of the program
    jmp $

; ? Carrying out the imports of the modules 
; ? that we have created to use in this main file.
%include "Source/Boot/Display/Print.s"
%include "Source/Boot/Display/PrintHex.s"
%include "Source/Boot/DiskSectors.s"
%include "Source/Boot/32-Bit/GDT.s"
%include "Source/Boot/32-Bit/Print.s"
%include "Source/Boot/32-Bit/Switch.s"

[bits 16]
LoadKernel:
    ; ? Carrying out the kernel load, we show the 
    ; ? message defined in Global.s to inform the user 
    ; ? that the kernel started to load.
    mov bx, kLoadKernelMessage
    call Print
    call PrintNewLine

    ; ? Read from disk and store in 0x1000
    ; * Value defined in Global.s 
    ; * file, imported file that includes 
    ; * kernel offset.
    mov bx, kKernelOffset

    ; ? Setting the maximum kernel size which indicates the maximum number of sectors.
    ; * More information in Global.s
    mov dh, [kKernelSize]
    mov dl, [BootDrive]

    ; ? Everything has gone well, let's mount the disk sir computer.
    call LoadDisk
    ret

[bits 32]
BeginProtectedMode:
    ; ? We show the protection 
    ; ? mode message, message defined in Global.s
    mov ebx, kProtectedModeMessage
    call PrintStringProtectedMode

    ; * Calling the Kernel Entry
    call kKernelOffset
    mov ebx, kKernelCrash
    call PrintStringProtectedMode

    ; * If kernel has crashes
    jmp $

BootDrive db 0

; * We include the Global file that contains the 
; * declarations that will be used in the 
; * modules and in this file.
%include "Source/Boot/Global.s"

; Black fucking magic!
times 510 - ($-$$) db 0
dw 0xaa55