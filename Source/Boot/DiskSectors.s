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

; ? The 'DH' sectors of the disk will be shit in ES:BX
LoadDisk:
    pusha

    ; * The disk needs specific values ​​in all registers
    ; * Therefore we will override the input parameters of 'DX'.
    ; * These will be stored in the stack for later use.
    push dx

    ; ? ah => (int 0x13) (function) (0x02 = 'read')
    mov ah, 0x02

    ; ? al => (Number of sectors to read) (0x01 ... 0x80)
    mov al, dh

    ; ? cl => (Sector) (0x01 ... 0x11)
    ; * 0x01 is the boot sector, 0x02 is the first available sector.
    mov cl, 0x02

    ; ? ch => (Cylinder) (0x0 ... 0x3FF) (Upper 2 bits in 'cl')
    mov ch, 0x00 

    ; ? dh => (Head number) (0x0 ... 0xF)
    mov dh, 0x00


    ; ? [ES:BX] - Pointer to the buffer where the disk data 
    ; ? will be saved, data mentioned at the 
    ; ? beginning of this function.
    
    ; * Caller sets it up for us, and it is 
    ; * actually the standard location for int 13h.
    
    ; ? BIOS Interrupt
    int 0x13

    ; ? If some error has ocurred, it will stored in the carry bit
    jc DiskError
    pop dx

    ; * BIOS also sets 'al' to the number of sectors read.
    cmp al, dh
    jne SectorErrors
    popa
    ret

; ? If an error occurs with the disk, the 
; ? following instructions will be executed.
DiskError:
    mov bx, DISK_ERROR
    call Print
    call PrintNewLine

    ; ? ah => (Error code) (dl => disk drive that generate the error)
    mov dh, ah 

    ; *  http://stanislavs.org/helppc/int_13-1.html
    call PrintHex
    jmp DiskLoop

; If an error occurs with the sectors of 
; the hard disk, the following 
; instructions will be executed.
SectorErrors:
    mov bx, SECTORS_ERROR
    call Print

DiskLoop:
    jmp $

; ? Messages that will be displayed 
; ? if an error occurs with the hard drive.
DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0