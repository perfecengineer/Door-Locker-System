/*
 * main.c
 *
 *  Created on: Nov 17, 2022
 *      Author: ACS
 */
//#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_CFG.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/KEYPAD.h"
#include "../HAL/SERVO/SERVO.h"
#include "../HAL/LCD/LCD_CFG.h"
#include "../HAL/BLUTOOTH_MODULE/BLUTOOTH.h"

#define CLOSE_SERVO     (0)
#define OPEN_SERVO      (180)
#define CLOSE_STEPPER   (-180)
#define OPEN_STEPPER    (180)
#define PASSWORD_WORD              (8888)
#define NUMBER_OF_PASSWORD_DIGITS  (4)
#define NUMBER_OF_FAILD_TRYING     (3)
#define ENTER_KEY                                ('+')
#define CLOSE_KEY                                ('/')
#define CHARACTER_FROM_MOBILE_TO_OPEN_DOOR       ('F')
#define CHARACTER_FROM_MOBILE_TO_CLOSE_DOOR      ('B')
int main()
{
	/*
	 * these variables using for open & close the serov:
	 */
	// direction of pins that using with buzzer & led:
	SET_PIN_DIR(GROUP_B,PIN_5, OUTPUT);
	SET_PIN_VALUE(GROUP_B,PIN_5, LOW);
	SET_PIN_DIR(GROUP_B,PIN_6, OUTPUT);
	SET_PIN_DIR(GROUP_B,PIN_7, OUTPUT);
	// this variable use to get data from mobile:
	u16 ReceiveDataFromMobile = HIGH;
	// this variable use to get data from keypad:
	u8 DataFromKeyPad = HIGH;
	// this variable use to check the state of system opend or closed :
	u8 DoorStatus = LOW;
	// this variable use to counts the number of digit of password:
	u8 NumberOfPassWordDigit = LOW;
	// this variable use to counts the number of try fail:
	u8 NumberOfFaildTrying = LOW;
	// this variable use to store the input password:
	u16 InputPassWordValueFromUser = LOW ;
	// this variable use check on the typing of LCD :
	u8 ScreenCheckFlag = LOW;
	// the firmware to initiate the  servo:
	vIniat_function_of_servo();
	// the firmware to initiate the  keypad:
	KEYPAD_Init();
	// the firmware to initiate the  LCD:
	LCD_vInit();
	// the firmware to initiate the  BLuetooth:
	BLUTOOTH_vInit();
	// close the servo:
	vServo_Angle(CLOSE_SERVO);
	// display on LCD to enter the password:
	 LCD_vSendCMD(CLEAR_COMMAND);
	 LCD_Display_Str("Enter_password");

	while(1)
	{
		/*
		 * this block use to get data from the use via the mobile or keypad:
		 */
		DataFromKeyPad = KEYPAD_Get_Value();
		ReceiveDataFromMobile = BLUTOOTH_RECIV();
		_delay_ms(30);

		/*
		 * this block use to store the value of password from user:
		 */
		if( DataFromKeyPad > LOW && NumberOfPassWordDigit < NUMBER_OF_PASSWORD_DIGITS && DataFromKeyPad != ENTER_KEY && DataFromKeyPad != CLOSE_KEY && DoorStatus == LOW)
		{
			// check the LCD:
			if(ScreenCheckFlag == LOW)
			{
				//clear the LCD:
				LCD_vSendCMD(CLEAR_COMMAND);
				// rising the flag by one that mean that LCD is cleared:
				ScreenCheckFlag = HIGH;
			}
			//calculate the digit of password and store it in variable:
			InputPassWordValueFromUser = InputPassWordValueFromUser * 10 + (DataFromKeyPad - '0');// 48
			LCD_GOTO_ROW_COL(LOW,NumberOfPassWordDigit);
			//display the data from user On LCD:
			//LCD_vSendData(data_of_keypad);
			LCD_vSendData('*');
			//increase the digit counter by 1 even reach to 4 digit:
			NumberOfPassWordDigit++;
		}
		/*
		 * '+' meaning or used an "Enter switch" to update the data of user:
		 * 'F' is data from mobile meaning open the system:
		 */
		if((DataFromKeyPad == ENTER_KEY || ReceiveDataFromMobile == 'F') && DoorStatus == LOW)
		{

			LCD_vSendCMD(CLEAR_COMMAND);
			NumberOfPassWordDigit = LOW;
			ScreenCheckFlag = LOW;
			// check the password from the user:
			if(InputPassWordValueFromUser ==  PASSWORD_WORD || ReceiveDataFromMobile == CHARACTER_FROM_MOBILE_TO_OPEN_DOOR)
			{
				DoorStatus = HIGH;
				InputPassWordValueFromUser = LOW;
				// open the system:
				 LCD_Display_Str("system_open");
				 vServo_Angle(OPEN_SERVO);
				 SET_PIN_VALUE(GROUP_B,PIN_6, HIGH);

			}
			else
			{
				/*
				 * this meaning that the password is not correct:
				 */
				InputPassWordValueFromUser = LOW;
				//increase the number of fail try by 1:
				NumberOfFaildTrying ++;
				// display the error indication:
				 LCD_Display_Str("Incorrect_pass");
				 LCD_GOTO_ROW_COL(1,0);
				 LCD_Display_Str("Try_again");
				 _delay_ms(100);
				 vServo_Angle(CLOSE_SERVO);
				 LCD_vSendCMD(CLEAR_COMMAND);
				 if(NumberOfFaildTrying < NUMBER_OF_FAILD_TRYING){
					 LCD_Display_Str("Enter_password");
				 }
				 else
				 {
					 // this meaning the number of tring exceed 3 times:
					 // so the system not safe and then we need to end the program:
					 LCD_Display_Str("system's Stop");
					 // this loop using as indicate the system not safe:
					 // by turn on the led & buzzer 3 times every 2 seconds:
					while(NumberOfFaildTrying > LOW)
					{
						SET_PIN_VALUE(GROUP_B,PIN_7, HIGH);
						_delay_ms(1000);
						SET_PIN_VALUE(GROUP_B,PIN_7, LOW);
						_delay_ms(1000);
						NumberOfFaildTrying --;
					}
					// and then End the program:
					// To Run the program, you need to reset the MCU:
					SET_PIN_VALUE(GROUP_B,PIN_7, HIGH);
					//_delay_ms(1000);
					LCD_vSendCMD(CLEAR_COMMAND);
					LCD_Display_Str("PLZ_RESET_SYS");
					 break;
				 }

			}
		}
		/*
		 * This block used to closed the system.
		 */
		else if( (ReceiveDataFromMobile == CHARACTER_FROM_MOBILE_TO_CLOSE_DOOR || DataFromKeyPad == CLOSE_KEY) && DoorStatus == HIGH)
		{
			/*********** reset all objects to default values ***************/
			LCD_vSendCMD(CLEAR_COMMAND);
			LCD_Display_Str("system_closed");
			vServo_Angle(CLOSE_SERVO);

			SET_PIN_VALUE(GROUP_B,PIN_6, LOW);
			SET_PIN_VALUE(GROUP_B,PIN_5,HIGH);
		}

	}

	return 0;
}

