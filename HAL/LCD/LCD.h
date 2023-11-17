#ifndef LCD_H
#define LCD_H

#include "../../UTILS/STD_TYPES.h"

 // This function shall be responsible for initializing LCD
void LCD_vInit(void);

 // This function shall be responsible for sending commands to LCD
void LCD_vSendCMD(u8 cmd);


 // This function shall be responsible for sending data to LCD
void LCD_vSendData(u8 data);
// This function shall be responsible for sending sttring to LCD
void LCD_Display_Str(char *s);
  // This function shall move the cursor
void LCD_GOTO_ROW_COL(u8 R,u8 C);

void LCD_Display_str_ROW_COL(char* w,u8 R,u8 C);
void LCD_Display_NUM(u32 k);
void USART_CFG(void);
void Disply_DATA_UAR(void);
void Display_RESULT_OF_CALC(void);
#endif
