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

#include "Cursor.h"
#include "../Display/Display.h"

// ? This function will allow you to get the cursor 
// ? of the operating system screen on its X axis.
unsigned long GetCursorPositionInX(){
  // * Creating a variable that will 
  // * allow the data to be stored.
  unsigned long Position = 0;

  // * Operations with port output 
  // * and with the value of the 
  // * Position variable.
  PortByteOut(0x3D4, 0x0F);
  Position |= PortByteIn(0x3D5);
  PortByteOut(0x3D4, 0x0E);
  Position |= ((unsigned long)PortByteIn(0x3D5)) << 8;

  // * We return the result of the operation where the 
  // * data stored in the variable Position is removed 
  // * from the remainder of the division together with 
  // * the value stored by the macro DISPLAY_WIDTH
  return Position % DISPLAY_WIDTH;
}

// ? Like the previous function, this function 
// ? will allow obtaining the cursor on the 
// ? y-axis of the screen.
unsigned long GetCursorPositionInY(){
  // * Creating a variable that 
  // * will store the axis of the cursor.
  unsigned long Position = 0;

  // * Operations with port output 
  // * and with the value of the 
  // * Position variable.
  PortByteOut(0x3D4, 0x0F);
  Position |= PortByteIn(0x3D5);
  PortByteOut(0x3D4, 0x0E);
  Position |= ((unsigned long)PortByteIn(0x3D5)) << 8;

  // * We return the result of the arithmetic 
  // * operation where the value that the Position 
  // * variable contains is divided with the value 
  // * that the DISPLAY_WIDTH macro has
  return Position / DISPLAY_WIDTH;
}

// ? Function that will allow to obtain the 
// ? Offset of the cursor on the screen 
// ? of the operating system bby <3.
unsigned int GetCursorOffset(){
    // * Operations with the output port, also in 
    // * this block a variable is created that will 
    // * contain a value returned by the input port, then 
    // * operations will be carried out with that value.
    PortByteOut(REG_DISPLAY_CTRL, 14);
    unsigned int Offset = PortByteIn(REG_DISPLAY_DATA) << 8;
    PortByteOut(REG_DISPLAY_CTRL, 15);
    Offset += PortByteIn(REG_DISPLAY_DATA);

    // * Finally we return the result of an arithmetic 
    // * operation where the value of the 
    // * Offset variable is multiplied * 2.
    return Offset * 2;
}

// ? Function that will allow you to set 
// ? the cursor offset on the 
// ? operating system screen.
void SetCursorOffset(unsigned int Offset){
    Offset /= 2;
    PortByteOut(REG_DISPLAY_CTRL, 14);
    PortByteOut(REG_DISPLAY_DATA, (unsigned char) (Offset >> 8));
    PortByteOut(REG_DISPLAY_CTRL, 15);
    PortByteOut(REG_DISPLAY_DATA, (unsigned char) (Offset & 0xff));
}