
#ifndef LCD_CFG_H
#define LCD_CFG_H

#include "../../MCAL/DIO/DIO_CFG.h"

/********* LCD COMMANDS ********/

#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0F
#define SET_CURSOR_LOCATION 0x80

/******** LCD ROWS ADDRESSES ******/

#define LCD_ROW_0	0x00
#define	LCD_ROW_1	0x40
#define LCD_ROW_2	0x10
#define	LCD_ROW_3	0x50

/******** LCD PORTS ******/

#define LCD_DATA_PORT	GROUP_C
#define LCD_CTRL_PORT	GROUP_B
#define RS_PIN	PIN_0
#define RW_PIN	PIN_1
#define EN_PIN	PIN_2



#endif
