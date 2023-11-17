/*
 * main.c
 *
 *  Created on: Nov 17, 2022
 *      Author: ACS
 */
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/BIT_MATH.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/KEYPAD.h"
#include "../HAL/SERVO/SERVO.h"
#include "../HAL/LCD/LCD_CFG.h"
#include "../HAL/BLUTOOTH_MODULE/BLUTOOTH.h"

int main()
{
	/*
	 * these variables using for open & close the serov:
	 */
	const u8 close = 0, open  = 180;
	// direction of pins that using with buzzer & led:
	DDRB = 0XFF;
	// this variable use to get data from mobile:
	u16 recieve_of_bluetooth = 1;
	// this variable use to get data from keypad:
	u8 data_of_keypad = 1;
	// this variable use to check the state of system opend or closed :
	u8 close_flag = 0;
	// this variable use to counts the number of digit of password:
	u8 numbre_of_digit = 0;
	// this variable use to counts the number of try fail:
	u8 number_of_faild_tring = 0;
	// this variable use to store the input password:
	u16 password = 0 ;
	// this variable use check on the typing of LCD :
	u8 screen_flag = 0;
	// the firmware to initiate the  servo:
	vIniat_function_of_servo();
	// the firmware to initiate the  keypad:
	KEYPAD_Init();
	// the firmware to initiate the  LCD:
	LCD_vInit();
	// the firmware to initiate the  BLuetooth:
	BLUTOOTH_vInit();
	// close the servo:
	vServo_Angle(close);
	// display on LCD to enter the password:
	 LCD_Display_Str("Enter_password");

	while(1)
	{
		/*
		 * this block use to get data from the use via the mobile or keypad:
		 */
		data_of_keypad = KEYPAD_Get_Value();
		recieve_of_bluetooth = BLUTOOTH_RECIV();
		_delay_ms(30);

		/*
		 * this block use to store the value of password from user:
		 */
		if( data_of_keypad > 0 && numbre_of_digit < 4 && data_of_keypad != '+' && data_of_keypad != '/' && close_flag == 0)
		{
			// check the LCD:
			if(screen_flag == 0)
			{
				//clear the LCD:
				LCD_vSendCMD(CLEAR_COMMAND);
			}
			// rising the flag by one that mean that LCD is cleared:
			screen_flag = 1;
			//calculate the digit of password and store it in variable:
			password = password * 10 + (data_of_keypad - '0');
			LCD_GOTO_ROW_COL(0,numbre_of_digit);
			//display the data from user On LCD:
			LCD_vSendData(data_of_keypad);
			//increase the digit counter by 1 even reach to 4 digit:
			numbre_of_digit++;
		}
		/*
		 * '+' meaning or used an "Enter switch" to update the data of user:
		 * 'F' is data from mobile meaning open the system:
		 */
		if((data_of_keypad == '+' || recieve_of_bluetooth == 'F') && close_flag == 0)
		{

			LCD_vSendCMD(CLEAR_COMMAND);
			numbre_of_digit = 0;screen_flag = 0;
			// check the password from the user:
			if(password == 1234 || recieve_of_bluetooth == 'F')
			{
				close_flag = 1;
				password = 0;
				// open the system:
				 LCD_Display_Str("system_opened");
				 vServo_Angle(open);

			}
			else
			{
				/*
				 * this meaning that the password is not correct:
				 */
				password = 0;
				//increase the number of fail try by 1:
				number_of_faild_tring++;
				// display the error indication:
				 LCD_Display_Str("Error_password");
				 LCD_GOTO_ROW_COL(1,0);
				 LCD_Display_Str("Try_again");
				 _delay_ms(100);
				 vServo_Angle(close);
				 LCD_vSendCMD(CLEAR_COMMAND);
				 if(number_of_faild_tring < 3)
				 LCD_Display_Str("Enter_password");
				 else
				 {
					 // this meaning the number of tring exceed 3 times:
					 // so the system not safe and then we need to end the program:
					 LCD_Display_Str("system_not_safe");
					 // this loop using as indicate the system not safe:
					 // by turn on the led & buzzer 3 times every 2 seconds:
					while(number_of_faild_tring <= 3)
					{
						TOGGLE_BIT(PORTB,7);
						TOGGLE_BIT(PORTB,6);
						_delay_ms(2000);
						number_of_faild_tring--;
					}
					// and then End the program:
					// To oprate the program we need to reset the MCU:
					SET_BIT(PORTB,7);
					SET_BIT(PORTB,6);
					 break;
				 }

			}
		}
		else if( (recieve_of_bluetooth == 'B' || data_of_keypad == '/') && close_flag == 1)
		{
			close_flag = 0;
			password = 0;data_of_keypad = 1;
			LCD_vSendCMD(CLEAR_COMMAND);
			LCD_Display_Str("system_closed");
			vServo_Angle(close);
		}

	}
	return 0;
}

