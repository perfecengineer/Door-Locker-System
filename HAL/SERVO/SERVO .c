#include "SERVO.h"
#include "../../MCAL/Timer/Timer.h"
void vIniat_function_of_servo(void)
{
	    SET_BIT(DDRD,5);
		Timer_vIntial();
		SET_TOP_Timer1_value(2500);
}
void vServo_Angle(u16 angle)
{
	u16 value = 0;
/*
 *
 */
	if(angle <= 180 || angle >= 0 )
	{
		//x = (angle * 250);
		value = ((angle * 250)/ 180);
		SET_OCRX_value(value);
	}

}
