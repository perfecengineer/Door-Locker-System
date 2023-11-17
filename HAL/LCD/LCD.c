
#include "LCD.h"
#include "LCD_CFG.h"
#include "../../MCAL/DIO/DIO.h"
#include "avr/io.h"
#include "../../MCAL/UART/usart.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "avr/delay.h"

void LCD_vInit(void)
{
	SET_GROUP_DIR(LCD_DATA_PORT, 0xFF);
	SET_PIN_DIR(LCD_CTRL_PORT, RS_PIN, OUTPUT);
	SET_PIN_DIR(LCD_CTRL_PORT, RW_PIN, OUTPUT);
	SET_PIN_DIR(LCD_CTRL_PORT, EN_PIN, OUTPUT);
	_delay_ms(50);
	LCD_vSendCMD(TWO_LINE_LCD_Eight_BIT_MODE);
	_delay_ms(50);
	LCD_vSendCMD(CURSOR_OFF);
	_delay_ms(50);
	LCD_vSendCMD(CLEAR_COMMAND);
	_delay_ms(50);

	
	
	
	

}

void LCD_vSendCMD(u8 cmd)
{
	SET_PIN_VALUE(LCD_CTRL_PORT, RS_PIN, LOW);
	SET_PIN_VALUE(LCD_CTRL_PORT, RW_PIN, LOW);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(50);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(50);
	SET_GROUP_VALUE(LCD_DATA_PORT, cmd);
	SET_GROUP_VALUE(LCD_DATA_PORT, cmd);
	_delay_ms(50);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(50);
	//SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, HIGH);
	//_delay_ms(50);
}

void LCD_vSendData(u8 data)
{
	SET_PIN_VALUE(LCD_CTRL_PORT, RS_PIN, HIGH);
	SET_PIN_VALUE(LCD_CTRL_PORT, RW_PIN, LOW);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(50);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, HIGH);
	_delay_ms(50);
	SET_GROUP_VALUE(LCD_DATA_PORT, data);
	_delay_ms(50);
	SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, LOW);
	_delay_ms(50);
	//SET_PIN_VALUE(LCD_CTRL_PORT, EN_PIN, HIGH);
	//_delay_ms(50);
}
void LCD_Display_Str(char *s)
{
	for(u8 i = 0; s[i] != '\0'; i++)
	{
		LCD_vSendData(s[i]);
	}
}
void LCD_GOTO_ROW_COL(u8 R,u8 C)
{
	u8 x;
	if(R == 0)
	{
		x = LCD_ROW_0 + C;
	}
	else if (R == 1)
	{
		x = LCD_ROW_1 + C;
	}

	LCD_vSendCMD(SET_CURSOR_LOCATION | x);


}
void LCD_Display_str_ROW_COL(char* w,u8 R,u8 C)
{
	LCD_GOTO_ROW_COL(R,C);
	LCD_Display_Str(w);
}
void LCD_Display_NUM(u32 k)
{
	u8 store_digits[5], i = 0;
	u8 pos = 0,f = 0;
	while(k != 0)
	{
			store_digits[i] = (k % 10) + '0';
			k /= 10;
			i++;f++;


	}

u8 s = i / 2;
	for(u8 j = 0; j < s; j++)
	{
		i--;
		pos = store_digits[i];
		store_digits[i] = store_digits[j];
		store_digits[j] = pos;
		//i--;
	}

	store_digits[f] = '\0';
	for(u8 j = 0; j < f; j++)
	{
		if(store_digits[j] < '0' || store_digits[j] > '9')
			LCD_vSendData(' ');
		else
			LCD_vSendData(store_digits[j]);
	}

}
void USART_CFG(void)
{
	CLEAR_BIT(DDRD,PIN_0);
	SET_BIT(DDRD,PIN_1);
	UART_vInit();
}
void Disply_DATA_UAR(void)
{
	u8 rec = 0;

	rec = UART_RECIV();
	LCD_vSendData(rec);
}
void Display_RESULT_OF_CALC(void)
{
	u8 x = 0, y = 0;
	u8 op = 0 , eq = 0;
	u8 result = 0;
	x = UART_RECIV();
	LCD_vSendData(x);
	op = UART_RECIV();
	LCD_vSendData(op);
	y = UART_RECIV();
	LCD_vSendData(y);
	eq = UART_RECIV();
	LCD_vSendData(eq);
	x-= '0';
	y -= '0';
	switch(op)
	{
	//((x + y) -'0')
	case '+' : result = (x + y);break;
	case '*' : result = (x * y);break;
	case '-' : result = (x - y);break;
	case '%' : result = (x % y);break;
	case '/' :
		if(y == 0)
		{
			LCD_vSendCMD(CLEAR_COMMAND);
			LCD_Display_Str("MATH Erro!");
			return;
		}
		else
			result = (x / y);
		break;
	default:
		LCD_vSendCMD(CLEAR_COMMAND);
		LCD_Display_Str("MATH Erro!");break;
	}
	if(eq == '=')
	{
		/*LCD_GOTO_ROW_COL(1,0);
		LCD_Display_Str("Result = ");*/
		if(result == 0)
			LCD_vSendData('0');
		else
			LCD_Display_NUM(result);


	}

}
