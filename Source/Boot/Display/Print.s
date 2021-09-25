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

Print:
    pusha

; ? Keep this in mind:
; * while(String[Iterator] != 0)
;       print(String[Iterator]), Iterator++;

; ? The comparison for string end (null byte)
Start:
    ; * bx => (base address for string)
    mov al, [bx]
    cmp al, 0
    je Done

    ; * The part where we print with BIOS help
    mov ah, 0x0e

    ; * 'al' Already contains the character
    int 0x10

    ; * Increment pointer and do next loop
    add bx, 1
    jmp Start

Done:
    popa
    ret

PrintNewLine:
    pusha
    mov ah, 0x0e

    ; * NewLine character
    mov al, 0x0a
    int 0x10

    ; * Carriage return
    mov al, 0x0d
    int 0x10
    
    popa
    ret