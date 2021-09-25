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

; * Don't remove the labels, they're 
; * needed to compute sizes and jumps
GDTStart:
    ; * The GDT starts with a null 8-byte
    dd 0x0
    dd 0x0

GDTCode:
    ; Segment length, bits 0-15
    dw 0xffff
    
    ; Segment base, bits 0-15
    dw 0x0
    
    ; Segment base, bits 16-23
    db 0x0

    ; Flags (8 bits)
    db 10011010b

    ; Flags (4 bits) + Segment Length, bits 16-19
    db 11001111b

    ; Segment base, bits 24-31
    db 0x0

; GDT for data segment. base and length identical to code segment
; some flags changed, again, refer to os-dev.pdf
GDTData:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

GDTEnd:

GDTDescriptor:
    ; Size (16 bit), always one less of its true size
    dw GDTEnd - GDTStart - 1
    dd GDTStart ; Address (32 bit)

; Define some constants for later use
kCodeSegment equ GDTCode - GDTStart
kDataSegment equ GDTData - GDTStart
