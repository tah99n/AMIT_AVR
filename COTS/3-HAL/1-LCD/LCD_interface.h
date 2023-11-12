/*
 * LCD_interface.h
 *
 * Created: 9/11/2022 11:28:58 AM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_8_BIT_MODE          1 
#define LCD_4_BIT_MODE          2

/* Macros For LCD Line Id */
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT          0
#define LCD_SHIFT_RIGHT         1

void LCD_init(void);
void LCD_sendCmnd(u8 Cmnd);
void LCD_sendChar(u8 data);
static void writeHalfPort(u8 value);
void LCD_writeString(u8* String);
void LCD_writeNumber(u32 number);
void LCD_clear(void);
void LCD_shift(u8 shifttingDirection);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);
/*void LCD_writeSpecialChar(u8 *pattern, u8 charPosition, u8 LineNumber, u8 Position);*/

#endif /* LCD_INTERFACE_H_ */