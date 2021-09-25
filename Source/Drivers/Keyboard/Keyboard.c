/***
 * Copyright (C) Rodolfo Herrera Hernandez. All rights reserved.
 * Licensed under the MIT license. See LICENSE file in the project root 
 * for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * For related information - https://github.com/codewithrodi/ChittyOS/
 * 
 * = This project has been done for no profit and just to test 
 * = my knowledge and skills, no contributions or bug fixes are expected.
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ***/

#include "Keyboard.h"
#include "../../Library/Conv/Conv.h"

// ? Variable declarations that will be 
// ? used throughout the driver's execution
bool
    KeyDown[384],
    CLock = false,
    NLock = false,
    SLock = false,
    LsftD = false,
    LctlD = false,
    LaltD = false,
    RsftD = false,
    RctlD = false,
    RaltD = false,
    KeyboardAltCharacter = false,
    xE0 = false;

static unsigned char 
    KeyMapLower[128] = "\e1234567890-=\b\tqwertyuiop[]\n\0asdfghjkl;'`\0\\zxcvbnm,./\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\0\0""789-456+1230.\0\0\0\x8A\x8B",
    KeyMapUpper[128] = "\e!@#$%^&*()_+\b\tQWERTYUIOP{}\n\0ASDFGHJKL:\"~\0|ZXCVBNM<>?\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\0\0""789-456+1230.\0\0\0\x8A\x8B",
    KeyMapSpecial[128] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0/\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\x8C\x92\0\x8D\0\x8E\0\x91\x8F\x93\x94\x7F\0\0\0\0\0\0\0\x95\x96",
    KeyMapAscii[128] = "\e1234567890-=\b\t\x11\x17\x05\x12\x14\x19\x15\x09\x0F\x10[]\r\0\x01\x13\x04\x06\x07\x08\x0A\x0B\x0C;'`\0\\\x1A\x18\x03\x16\x02\x0E\x0D,./\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\0""789-456+1230.\0\0\0\x8A\x8B",
    Character = 0,
    CharacterH = 0;

unsigned int KeyBinary;
unsigned char TempBuffer[4] = "\0\0\0";
int TempPtr = 0;

static bool Key = false;

void KeyboardPortByteOut(unsigned char Byte) {
    unsigned char tmp;
    unsigned int tries = 0;
    do{
        PortByteOut(0x60, Byte);
        do{
            tmp = PortByteIn(0x60);
        }while(tmp == 0);
        tries++;
    }while( (tmp == 0xFE) && (tries < 3) );
}    

void KeyboardUpdateLeds() {
    KeyboardPortByteOut(0xED);
    KeyboardPortByteOut((SLock & 1) + ((NLock & 1) << 1) + ((CLock & 1) << 2));
}

void KeyboardH() {
    KeyBinary = PortByteIn(0x60);
    KeyboardAltCharacter = false;
    Character = 0;
    if(KeyBinary == 0xE0) {
        xE0 = true;
        goto KeyboardEnd;
    }
    if(KeyBinary < 128){
        if( (!NLock) && (KeyBinary >= 0x47) && (KeyBinary <= 0x52) ) 
            xE0 = true;
        if(xE0){
            switch(KeyBinary){
                case 0x1D:
                    RctlD = true;
                    break;
                case 0x38:
                    RaltD = true;
                    break;
                default:
                    Character = KeyMapSpecial[KeyBinary - 1];
                    KeyDown[KeyBinary + 127] = true;
                    break;
            }
            xE0 = false;
        }else{
            switch(KeyBinary){
                case 0x1D:
                    LctlD = true;
                    break;
                case 0x2A:
                    LsftD = true;
                    break;
                case 0x36:
                    RsftD = true;
                    break;
                case 0x38:
                    LaltD = true;
                    break;
                case 0x3A:
                    CLock = !CLock;
                    KeyboardUpdateLeds();
                    break;
                case 0x45:
                    NLock = !NLock;
                    KeyboardUpdateLeds();
                    break;
                case 0x46:
                    SLock = !SLock;
                    KeyboardUpdateLeds();
                    break;
                default:
                    if(LaltD || RaltD){
                        if(KeyMapLower[KeyBinary - 1] >= '0' && KeyMapLower[KeyBinary - 1] <= '9' && TempPtr < 3 && KeyBinary >= 0x47 && KeyBinary <= 0x52){
                            TempBuffer[TempPtr] = KeyMapLower[KeyBinary - 1];
                            TempPtr++;
                        }
                    }else{
                        if(LctlD || RctlD){
                            Character = KeyMapAscii[KeyBinary - 1];
                        }else{
                            if(CLock){
                                if(LsftD || RsftD){
                                    Character = KeyMapLower[KeyBinary - 1];
                                }else{
                                    Character = KeyMapUpper[KeyBinary - 1];
                                }
                            }else{
                                if(LsftD || RsftD){
                                    Character = KeyMapUpper[KeyBinary - 1];
                                }else{
                                    Character = KeyMapLower[KeyBinary - 1];
                                }
                            }
                        }
                        KeyDown[KeyBinary - 1] = true;
                    }
                    break;
            }
        }
    }else{
        KeyBinary -= 128;
        if( (!NLock) && (KeyBinary >= 0x47) && (KeyBinary <= 0x52) ) 
            xE0 = true;
        if(xE0){
            switch(KeyBinary){
                case 0x1D:
                    RctlD = false;
                    break;
                case 0x38:
                    RaltD = false;
                    break;
                default:
                    KeyDown[KeyBinary + 127] = false;
                    break;
            }
            xE0 = false;
        }else{
            switch(KeyBinary){
                case 0x1D:
                    LctlD = false;
                    break;
                case 0x2A:
                    LsftD = false;
                    break;
                case 0x36:
                    RsftD = false;
                    break;
                case 0x38:
                    LaltD = false;
                    break;
                case 0x3A:
                    break;
                case 0x45:
                    break;
                case 0x46:
                    break;
                default:
                    KeyDown[KeyBinary - 1] = false;
                    break;
            }
            KeyBinary += 128;
        }
        if( !(LaltD || RaltD) && (TempPtr > 0) ){
            Character = StringToInteger(TempBuffer) % 256;
            for(TempPtr = 0; TempPtr < 3; TempPtr++) {
                TempBuffer[TempPtr] = 0;
            }
            TempPtr = 0;
            KeyboardAltCharacter = true;
        }
    }
    KeyboardEnd:
        Key = true;
}

void InitializeKeyboard() {
    Key = false;
    for(unsigned short int Iterator = 0; Iterator < 384; Iterator++)
        KeyDown[Iterator] = false;
    NLock = true;
    KeyboardUpdateLeds();
    RegisterInterruptHandler(IRQ1, KeyboardH);
}

char KeyboardInputCharacter(){
    do{
        if( (KeyBinary >= 128) || (KeyBinary == 0xE0) )
            CharacterH = 0;
        KeyboardH();
    }while( (Character == CharacterH) || (KeyBinary >= 128) );
    CharacterH = Character;
    return (char) CharacterH;
}