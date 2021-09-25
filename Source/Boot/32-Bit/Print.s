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

; ? Using 32-BIT protected mode
[bits 32]

; * Defining the constants
kVideoMemory equ 0xb8000

; * The color byte for each character
kWhiteOnBlack equ 0x0f

PrintStringProtectedMode:
    pusha
    mov edx, kVideoMemory

PrintStringLoopProtectedMode:
    ; ? [ebx] (Is the address of our character)
    mov al, [ebx]
    mov ah, kWhiteOnBlack

    ; * Check if end of string
    cmp al, 0
    je ProtectedModeDone

    ; Store character + attribute in video memory
    mov [edx], ax

    ; Next character
    add ebx, 1

    ; Next video memory position
    add edx, 2
    
    ; Bye byeeeeeeeeeeeeeeeeeeeeeeeeeee
    jmp PrintStringLoopProtectedMode

ProtectedModeDone:
    popa
    ret