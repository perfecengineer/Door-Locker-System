#include "../../UTILS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "KEYPAD.h"
#include"KEYPAD_CFG.h"
u8 KEYPAD_VALUES[ROWSNUM][COLSNUM] = 
{
{'1','2','3','+'},
{'4','5','6','-'},
{'7','8','9','*'},
{'%','0','=','/'}	
}; 
void KEYPAD_Init(void)
{
	//cols mode 
	SET_PIN_DIR(KEYPAD_PORT,COL0,OUTPUT);
	SET_PIN_DIR(KEYPAD_PORT,COL1,OUTPUT);
	SET_PIN_DIR(KEYPAD_PORT,COL2,OUTPUT);
	SET_PIN_DIR(KEYPAD_PORT,COL3,OUTPUT);
	// cols value
	SET_PIN_VALUE(KEYPAD_PORT,COL0,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,COL1,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,COL2,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,COL3,HIGH);
	//ROWS mode 
	SET_PIN_DIR(KEYPAD_PORT,ROW0,INPUT);
	SET_PIN_DIR(KEYPAD_PORT,ROW1,INPUT);
	SET_PIN_DIR(KEYPAD_PORT,ROW2,INPUT);
	SET_PIN_DIR(KEYPAD_PORT,ROW3,INPUT);
	// ROWS value
	SET_PIN_VALUE(KEYPAD_PORT,ROW0,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,ROW1,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,ROW2,HIGH);
	SET_PIN_VALUE(KEYPAD_PORT,ROW3,HIGH);	
}
u8 KEYPAD_Get_Value(void)
{
	u8 col_count;
	u8 Row_count;
	u8 value = '\0';
	for(col_count = COL0; col_count <= COL3; col_count ++)
	{
		SET_PIN_VALUE(KEYPAD_PORT,col_count,LOW);
		for(Row_count = ROW0; Row_count <= ROW3; Row_count ++)
		{
			if(READ_PIN_VALUE(KEYPAD_PORT,Row_count) == PRESSED)
			{
				while(READ_PIN_VALUE(KEYPAD_PORT,Row_count) == PRESSED);
				value = KEYPAD_VALUES[Row_count - ROW0][col_count];
				SET_PIN_VALUE(KEYPAD_PORT,col_count,HIGH);
				return value;
				
			}
		}
		SET_PIN_VALUE(KEYPAD_PORT,col_count,HIGH); 
	}
	return value;
}
