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

; ? Receiving the data from 'dx'
PrintHex:
    pusha

    ; ? Index variable
    mov cx, 0

; ? Strategy: get the last char of 'dx', then convert to ASCII
; ? numeric ASCII values: '0' (ASCII 0x30) to 
; ? '9' (0x39), so just add 0x30 to byte N.
; ? for alphabetic characters A-F: 'A' (ASCII 0x41) 
; ? to 'F' (0x46) we'll add 0x40
; ? then, move the ASCII byte to the correct position 
; ? on the resulting stringHexLoop:
HexLoop:
    ; * Generating a loop that will give 4 cycles.
    cmp cx, 4
    je End

    ; * 1. Convert last char of 'dx' to ascii
    ; * we will use 'ax' as our working register
    mov ax, dx

    ; * 0x1234 -> 0x0004 By masking first three to zeros
    and ax, 0x000f

    ; * Add 0x30 to N to convert it to ASCII "N"
    add al, 0x30

    ; * if > 9, Add extra 8 to represent 'A' to 'F'
    cmp al, 0x39
    jle Ending

    ; * 'A' is ASCII 65 instead of 58, so 65-58=7
    add al, 7

Ending:
    ; * 2. Get the correct position of the string to place our ASCII char
    ; * bx <- base address + string length - index of char
    mov bx, OUTPUT + 5

    ; * Index variable
    sub bx, cx

    ; * Copy the ASCII char on 'al' to the position pointed by 'bx'
    mov [bx], al

    ; * 0x1234 -> 0x4123 -> 0x3412 -> 0x2341 -> 0x1234
    ror dx, 4

    ; * Increment index and loop
    add cx, 1
    jmp HexLoop

End:
    ; * Prepare the parameter and call the function
    ; * remember that print receives parameters in 'bx'
    mov bx, OUTPUT
    call Print
    popa
    ret

OUTPUT:
    ; * Reserve ememory for new string
    db '0x0000', 0