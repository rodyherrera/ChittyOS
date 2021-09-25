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

[extern IsrHandler]
[extern IrqHandler]

ISRCommon:
    ; ? Save state
    ; * Push [edi, si, ebp, esp, ebx, edx, ecx, eax]
    pusha

    ; * Lower 16-BIT of eax
    mov ax, ds
    
    ; * Save the data segment descriptor
    push eax

    ; * Kernel data segment descriptor
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; ? Call Handler
    call IsrHandler

    ; Restore state
    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    add esp, 8
    sti
    iret

IRQCommon:
    ; Save state
    pusha
    mov ax, ds
    push eax
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Call Handler
    call IrqHandler

    ; Restore state
    pop ebx
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx
    popa
    add esp, 8
    sti
    iret

global IsR0
global IsR1
global IsR2
global IsR3
global IsR4
global IsR5
global IsR6
global IsR7
global IsR8
global IsR9
global IsR10
global IsR11
global IsR12
global IsR13
global IsR14
global IsR15
global IsR16
global IsR17
global IsR18
global IsR19
global IsR20
global IsR21
global IsR22
global IsR23
global IsR24
global IsR25
global IsR26
global IsR27
global IsR28
global IsR29
global IsR30
global IsR31

global Irq0
global Irq1
global Irq2
global Irq3
global Irq4
global Irq5
global Irq6
global Irq7
global Irq8
global Irq9
global Irq10
global Irq11
global Irq12
global Irq13
global Irq14
global Irq15

; ? 0 - Divide by Zero Exception
IsR0:
    cli
    push byte 0
    push byte 0
    jmp ISRCommon

; ? Debug Exception
IsR1:
    cli
    push byte 0
    push byte 1
    jmp ISRCommon

; ? Non-Maskable Interrupt Exception
IsR2:
    cli
    push byte 0
    push byte 2
    jmp ISRCommon

; ? Int 3 Exception
IsR3:   
    cli
    push byte 0
    push byte 3
    jmp ISRCommon

; ? INTO Excepton
IsR4:
    cli
    push byte 0
    push byte 4
    jmp ISRCommon

; ? Out of Bounds Exception
IsR5:
    cli
    push byte 0
    push byte 5
    jmp ISRCommon

; ? Invalid Opcode Exception
IsR6:
    cli
    push byte 0
    push byte 6
    jmp ISRCommon

; ? Coprocessor Not Available Exception
IsR7:
    cli
    push byte 0
    push byte 7
    jmp ISRCommon

; ? Double Fault Exception (With Error Code!)
IsR8:
    cli
    push byte 8
    jmp ISRCommon

; ? Coprocessor Segment Overrun Exception
IsR9:
    cli
    push byte 0
    push byte 9
    jmp ISRCommon

; ? Bad TSS Exception (With Error Code!)
IsR10:
    cli
    push byte 10
    jmp ISRCommon

; ? Segment Not Present Exception (With Error Code!)
IsR11:
    cli
    push byte 11
    jmp ISRCommon

; ? Stack Fault Exception (With Error Code!)
IsR12:
    cli
    push byte 12
    jmp ISRCommon

; ? General Protection Fault Exception (With Error Code!)
IsR13:
    cli
    push byte 13
    jmp ISRCommon

; ? Page Fault Exception (With Error Code!)
IsR14:
    cli
    push byte 14
    jmp ISRCommon

; ? Reserved Exception
IsR15:
    cli
    push byte 0
    push byte 15
    jmp ISRCommon

; ? Floating Point Exception
IsR16:
    cli
    push byte 0
    push byte 16
    jmp ISRCommon

; ? Alignment Check Exception
IsR17:
    cli
    push byte 0
    push byte 17
    jmp ISRCommon

; ? Machine Check Exception
IsR18:
    cli
    push byte 0
    push byte 18
    jmp ISRCommon

; ? Reserved
IsR19:
    cli
    push byte 0
    push byte 19
    jmp ISRCommon

; ? Reserved
IsR20:
    cli 
    push byte 0
    push byte 20
    jmp ISRCommon

; ? Reserved
IsR21:
    cli
    push byte 0
    push byte 21
    jmp ISRCommon

; ? Reserved
IsR22:
    cli
    push byte 0
    push byte 22
    jmp ISRCommon

; ? Reserved
IsR23:
    cli
    push byte 0
    push byte 23
    jmp ISRCommon

; ? Reserved
IsR24:
    cli
    push byte 0
    push byte 24
    jmp ISRCommon

; ? Reserved
IsR25:
    cli
    push byte 0
    push byte 25
    jmp ISRCommon

; ? Reserved
IsR26:
    cli
    push byte 0
    push byte 26
    jmp ISRCommon

; ? Reserved
IsR27:
    cli
    push byte 0
    push byte 27
    jmp ISRCommon

; ? Reserved
IsR28:
    cli
    push byte 0
    push byte 28
    jmp ISRCommon

; ? Reserved
IsR29:
    cli
    push byte 0
    push byte 29
    jmp ISRCommon

; ? Reserved
IsR30:
    cli
    push byte 0
    push byte 30
    jmp ISRCommon

; ? Reserved
IsR31:
    cli
    push byte 0
    push byte 31
    jmp ISRCommon

Irq0:
    cli
    push byte 0
    push byte 32
    jmp IRQCommon

Irq1:
    cli
    push byte 1
    push byte 33
    jmp IRQCommon

Irq2:
    cli
    push byte 2
    push byte 34
    jmp IRQCommon

Irq3:
    cli
    push byte 3
    push byte 35
    jmp IRQCommon

Irq4:
    cli
    push byte 4
    push byte 36
    jmp IRQCommon

Irq5:
    cli
    push byte 5
    push byte 37
    jmp IRQCommon

Irq6:
    cli
    push byte 6
    push byte 38
    jmp IRQCommon

Irq7:
    cli
    push byte 7
    push byte 39
    jmp IRQCommon

Irq8:
    cli
    push byte 8
    push byte 40
    jmp IRQCommon

Irq9:
    cli
    push byte 9
    push byte 41
    jmp IRQCommon

Irq10:
    cli
    push byte 10
    push byte 42
    jmp IRQCommon

Irq11:
    cli
    push byte 11
    push byte 43
    jmp IRQCommon

Irq12:
    cli
    push byte 12
    push byte 44
    jmp IRQCommon

Irq13:
    cli
    push byte 13
    push byte 45
    jmp IRQCommon

Irq14:
    cli
    push byte 14
    push byte 46
    jmp IRQCommon

Irq15:
    cli
    push byte 15
    push byte 47
    jmp IRQCommon