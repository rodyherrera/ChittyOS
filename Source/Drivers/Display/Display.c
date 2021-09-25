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

#include "Display.h"
#include "../Cursor/Cursor.h"

// * By declaring a variable which will 
// * store the theme to use on the screen.
static unsigned char CurrentDisplayTheme;

// ? Function to obtain the screen 
// ? offset, to make this possible 
// ? two values ​​must be sent, both of 
// ? unsigned integer type, that is, positive 
// ? values, where the first is the column and 
// ? the second is the row.
unsigned int GetOffset(unsigned int Column, unsigned int Row){
    // * The value of an arithmetic operation will be 
    // * returned, where first the unsigned integer value 
    // * that indicates the row will be multiplied 
    // * together with the value of the DISPLAY_WIDTH macro 
    // * and this will be increased with the value of the 
    // * first unsigned integer parameter, that is, Column, then 
    // * this value will be multiplied by two.
    return 2 * (Row * DISPLAY_WIDTH + Column);
}

// ? Unlike the previous function, this function 
// ? returns only the Offset of the row, but 
// ? to make this possible you must send the Offset XD.
unsigned int GetOffsetRow(unsigned int Offset){
    // * The value that will be returned will be the result of an 
    // * arithmetic operation, where the value of the macro 
    // * DISPLAY_WIDTH will be multiplied by two first, 
    // * then the result of that will be divided by 
    // * the Offset, parameter sent to the function.
    return Offset / (2 * DISPLAY_WIDTH);
}

// ? As you saw in the previous function, it was 
// ? to return the row of an offset that you 
// ? gave it, this function does the same but 
// ? instead of returning the row it returns the column.
unsigned int GetOffsetColumn(unsigned int Offset){
    // * The value that will be returned will 
    // * be the value of an arithmetic 
    // * operation, where first the offset row will 
    // * be multiplied by 2 and then by the value 
    // * of the DISPLAY_WIDTH macro, then the 
    // * result of this operation will be 
    // * subtracted with the offset, the value sent to 
    // * the function as a parameter, after this subtraction 
    // * the value will be divided by 2, this will be 
    // * the column of the offset delivered.
    return (Offset - (GetOffsetRow(Offset) * 2 * DISPLAY_WIDTH)) / 2;
}

// ? Function that will establish the position of the 
// ? cursor on the screen, this function is used in 
// ? the definition of the neofetch command, it is 
// ? used to display the system information in a pleasant 
// ? way for the user, the function receives the Column as 
// ? the first parameter and the row as second 
// ? parameter, both have to be unsigned integers.
void SetCursorPosition(unsigned int Column, unsigned int Row){
    SetCursorOffset(GetOffset(Column, Row));
}

// ? Function that serves to turn off the system, no man 
// ? xd you are seeing that it says Display 
// ? Character: c, this function serves to show a 
// ? character on the screen, receives as a parameter 
// ? the Character to be displayed, the Offset referring 
// ? to the location where you want show Character 
// ? and Color as third parameter.
void DisplayCharacter(char Character, unsigned int Offset, unsigned int Color){
    // * Video initialization, this 
    // * "function" is a macro defined 
    // * in Display.h
    INITIALIZE_VIDEO
    VideoMemory[Offset * 2] = Character;

    // * We verify if the data that is sent as 
    // * the third parameter which is color is 
    // * different from transparent "macro 
    // * defined in Color.h" we will make 
    // * a series of instructions on the screen.
    if(Color != TRANSPARENT)
        VideoMemory[Offset * 2 + 1] = Color;
}

// ? Function that will serve to 
// ? print a line break on 
// ? the operating system screen.
void PrintLn(){
    // * We declare a variable which will 
    // * contain the offset of the screen row.
    unsigned int CursorOffsetRow = GetOffsetRow(GetCursorOffset());

    // * We establish the position of the cursor.
    SetCursorPosition(0, CursorOffsetRow + 1);

    // * We check if the result of an 
    // * arithmetic operation where the value of 
    // * the DISPLAY_HEIGH macro increased by the value 
    // * of the DISPLAY_SCROLL_DETECTION_DEBUG macro is 
    // * less than the offset of the row, to scroll the screen.
    if(CursorOffsetRow > DISPLAY_HEIGHT + DISPLAY_SCROLL_DETECTION_DEBUG)
        // ? Scroll bby SCROOOOOOOOOOLLL wuwuwuwuwuw
        DisplayScroll();
}

// ? Function that will serve to print a character 
// ? on the operating system screen with a little color
void kPrintCharacterWithColor(char Character, char Color){
    // * Video initialization, this 
    // * "function" is a macro defined 
    // * in Display.h
    INITIALIZE_VIDEO

    // * We create a variable that 
    // * will be of type unsigned integer 
    // * that will store the offset of 
    // * the cursor on the screen.
    unsigned int Cursor = GetCursorOffset();

    // * We check if the character sent as 
    // * the first parameter is a "\ n" that 
    // * refers to a line break, if so, we 
    // * will call the function that prints a line.
    if(Character == '\n')
        PrintLn();
    else
        // ? We check if the cursor offset is less than or equal to 
        // ? the result of the arithmetic operation where 
        // ? the value of the macro DISPLAY_WIDTH is 
        // ? multiplied by the value of the macro DISPLAY_HEIGH 
        // ? then the result of the multiplication is decreased 
        // ? by two and then multiplied by two.
        if(Cursor <= (DISPLAY_WIDTH * DISPLAY_HEIGHT - 2) * 2){
            // * We set the character according to the Offset.
            VideoMemory[Cursor] = Character;

            // * We check if the color they send us is 
            // * TRANSPARENT, macro defined in "Color.h", if 
            // * so, a series of instructions will be executed.
            if(Color != TRANSPARENT)
                VideoMemory[Cursor + 1] = Color;

            // * We set a new offset position for 
            // * the cursor, whose new offset will 
            // * be the current offset increased by two.
            SetCursorOffset(Cursor + 2);
        }else PrintLn();
}

// ? Function that will allow printing a 
// ? character on the screen, this function 
// ? receives a parameter which will be the 
// ? character to print xd.
void kPrintCharacter(char Character){
    // * The function that does the ugly job of printing 
    // * on the screen is called, it is assigned 
    // * the transparent color by default.
    kPrintCharacterWithColor(Character, TRANSPARENT);
}

// ? We create a function to print a set of 
// ? characters <String> on the 
// ? screen, it receives the string depth 
// ? and color bby <3
void kPrintWithColor(char* String, unsigned long Depth, unsigned char Color){
    for(unsigned long Iterator = 0; Iterator < Depth; ++Iterator)
        kPrintCharacterWithColor(String[Iterator], Color);
}

// ? Function that will allow making a print of 
// ? a tring on the screen, this function executes the 
// ? previously executed function with the difference 
// ? that by default it is assigned a color which is transparent.
void kPrint(char* String, unsigned long Depth){
    kPrintWithColor(String, Depth, TRANSPARENT);
}

// ? Function that will allow the enablement of the 
// ? theme, receives a parameter which is the Color.
void DisplayTheme(char Color){
    // * Video initialization, this 
    // * "function" is a macro defined 
    // * in Display.h
    INITIALIZE_VIDEO
    
    // * We set the variable that stores the 
    // * theme of the screen to the new 
    // * color that this function received as a parameter.
    CurrentDisplayTheme = Color;

    // * Black fucking magic
    for(unsigned int Iterator= 1; Iterator < DISPLAY_WIDTH * DISPLAY_WIDTH; Iterator += 2)
        VideoMemory[Iterator] = Color;
}

// ? Function that will allow copying a row, receives the 
// ? destination as the first parameter which is an unsigned 
// ? integer and receives the source, that is, the current 
// ? row, the one to be copied which must also be an unsigned 
// ? integer, a negative row :DD:D:DD
void RowCopy(unsigned int Destinity, unsigned int Source){
    // * Video initialization, this 
    // * "function" is a macro defined 
    // * in Display.h
    INITIALIZE_VIDEO

    // * Two variables are declared in which the first 
    // * one will save the Offset of the destination 
    // * increased with the value of the video 
    // * memory, while the second one will obtain 
    // * the Offset of the row to be copied 
    // * increased with the video memory.
    char* DestinityOffset = GetOffset(0, Destinity) + VideoMemory;
    char* SourceOffset = GetOffset(0, Source) + VideoMemory;
    
    // * Unicorn 3400
    for(unsigned long Iterator = 0; Iterator < DISPLAY_WIDTH + DISPLAY_SCROLL_DEBUG; ++Iterator)
        DestinityOffset[Iterator] = SourceOffset[Iterator];
}

// ? Function that will allow you to scroll on the screen.
void DisplayScroll(){
    for(unsigned int Row = 1; Row <= DISPLAY_HEIGHT; ++Row)
        RowCopy(Row - 1, Row);

    // * The new position of the cursor on the screen is set.
    SetCursorPosition(0, GetOffsetRow(GetCursorOffset()) - 1);
}

// ? Function that will clean the screen.
void ClearDisplay(){
    // * Cycle that will allow cleaning the screen.
    for(unsigned int Iterator = 0; Iterator < DISPLAY_WIDTH * DISPLAY_HEIGHT; ++Iterator)
        DisplayCharacter(0, Iterator, 0x00);
    
    // * The position of the virgin offset is set.
    SetCursorOffset(0);
    
    // * The theme that was being used is established again.
    DisplayTheme(CurrentDisplayTheme);
}

void DeleteDisplay(){
    SetCursorOffset(GetCursorOffset() - 1);
    kPrintCharacter(0);
    SetCursorOffset(GetCursorOffset() - 1);
}

void InitializeDisplay(){
    CurrentDisplayTheme = DISPLAY_THEME;
}