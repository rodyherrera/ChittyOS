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

; ? Declarations of global constants that will be 
; ? used in the final assembly 
; ? file, these files are included.

; * This variable indicates the number of 
; * sectors in which the kernel of the operating system will be located.
kKernelSize db 33

; * Maximum amount that will be 
; * assigned to the kernel offset.
kKernelOffset equ 0x1000

; * Like the previous kernel offset 
; * assignment, the same will be 
; * done for the Stack.
kStackOffset db 9000

; ? Message declarations, these declarations will be used when 
; ? you need to display something on the screen within the 
; ? operating system, be it an error or a success message.

; * Message that will be displayed when the kernel is loading.

; * Message that will be displayed when starting in Real Mode using 16 bit
kRealModeMessage db "https://github.com/codewithrodi/ChittyOS/", 0

; * Message to be displayed when starting in 32 bit protected mode
kProtectedModeMessage db "32-BIT Protection Mode.", 0

; * Message that will be displayed when the kernel is loading.
kLoadKernelMessage db "Boot > Loading Kernel into memory.", 0

; * Message that will be displayed if the kernel crashes.
kKernelCrash db "Nothing to do, just drink water.", 0