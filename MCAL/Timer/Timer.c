#include"Timer.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
void Timer_vIntial(void)
{
	// ***********************disable the global interrupt
		CLEAR_BIT(SREG,7);
	#if Select_Timer == Timer1
				//***************** compare value:
				#if pin_MODE_OCX == NON_INVERTING_MODE
				//non_inverting mode
				CLEAR_BIT(TCCR1A,4);
				CLEAR_BIT(TCCR1A,6);
				SET_BIT(TCCR1A,5);
				SET_BIT(TCCR1A,7);
				#elif pin_MODE_OCX == INVERTING_MODE
				SET_BIT(TCCR1A,4);
				SET_BIT(TCCR1A,6);
				SET_BIT(TCCR1A,5);
				SET_BIT(TCCR1A,7);
				#elif pin_MODE_OCX == Normal_mode_Disconnected 
				CLEAR_BIT(TCCR1A,4);
				CLEAR_BIT(TCCR1A,6);
				CLEAR_BIT(TCCR1A,5);
				CLEAR_BIT(TCCR1A,7);
				#elif pin_MODE_OCX == Toggle_OCx_on_compare_match_IN_ CTC_Mode_only_OR_Reserved
				CLEAR_BIT(TCCR1A,5);
				CLEAR_BIT(TCCR1A,7);
				SET_BIT(TCCR1A,4);
				SET_BIT(TCCR1A,6);
				#endif
//*********************************************************************//				
				//*********************choose MODE
				#if select_mode == Fast_PWM_mode
				//choose ICR1 MODE(14)
				CLEAR_BIT(TCCR1A,0);
				SET_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,4);
				SET_BIT(TCCR1B,3);
				#elif select_mode == Normal_mode
				// Enable the perpheral interrupt:
				SET_BIT(TIMSK,2);
				// OVERFLOW MODE
				CLEAR_BIT(TCCR1A,0);
				CLEAR_BIT(TCCR1A,1);
				CLEAR_BIT(TCCR1B,4);
				CLEAR_BIT(TCCR1B,3);
				#elif select_mode == CTC_mode
				// Enable output compare force (CTC )
				CLEAR_BIT(TCCR1A,2);
				SET_BIT(TCCR1A,3);
				// Enable the perpherale interrupt:
				SET_BIT(TIMSK,4);
				// CTC MODE:
				CLEAR_BIT(TCCR1A,0);
				CLEAR_BIT(TCCR1A,1);
				CLEAR_BIT(TCCR1B,4);
				SET_BIT(TCCR1B,3);
				#elif select_mode == phase_correct_mode
				// **************** 8_bits 
				SET_BIT(TCCR1A,0);
				CLEAR_BIT(TCCR1A,1);
				CLEAR_BIT(TCCR1B,4);
				CLEAR_BIT(TCCR1B,3);
				#endif
//***********************************************************************				
				#if Select_CLK == NO_CLK_SOURSE 
				CLEAR_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
				#elif Select_CLK == CLK_1
				SET_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
				#elif Select_CLK == CLK_8
				CLEAR_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
				#elif Select_CLK == CLK_64
				SET_BIT(TCCR1B,0);
				SET_BIT(TCCR1B,1);
				CLEAR_BIT(TCCR1B,2);
				#elif Select_CLK == CLK_256
				CLEAR_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
				#elif Select_CLK == CLK_1024
				SET_BIT(TCCR1B,0);
				CLEAR_BIT(TCCR1B,1);
				SET_BIT(TCCR1B,2);
				#endif
				// ***************************************************************************
	#elif Select_Timer == Timer0
				#if pin_MODE_OCX == NON_INVERTING_MODE
				//non_inverting mode
				CLEAR_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
				#elif pin_MODE_OCX == INVERTING_MODE
				SET_BIT(TCCR0,4);
				SET_BIT(TCCR0,5);
				#elif pin_MODE_OCX == Normal_mode_Disconnected 
				CLEAR_BIT(TCCR0,4);
				CLEAR_BIT(TCCR0,5);
				#elif pin_MODE_OCX == Toggle_OCx_on_compare_match_IN_ CTC_Mode_only_OR_Reserved
				CLEAR_BIT(TCCR0,5);
				SET_BIT(TCCR0,4);
				#endif	
				//*********************************************************
				#if select_mode == Fast_PWM_mode
				//choose ICR1 MODE(14)
				SET_BIT(TCCR0,6);
				SET_BIT(TCCR0,3);
				#elif select_mode == Normal_mode
				//ENABLE THE INTERRUPT
				SET_BIT(TIMSK,0);
				// OVERFLOW MODE:
				CLEAR_BIT(TCCR0,6);
				CLEAR_BIT(TCCR0,3);
				#elif select_mode == CTC_mode
				// Enable output compare force (CTC )
				SET_BIT(TCCR0,7);
				//ENABLE THE INTERRUPT
				SET_BIT(TIMSK,1);
				// CTC MODE ENABLE:
				CLEAR_BIT(TCCR0,6);
				SET_BIT(TCCR0,3);
				#elif select_mode == phase_correct_mode
				// **************** 8_bits 
				SET_BIT(TCCR0,6);
				CLEAR_BIT(TCCR0,3);
				#endif
//***********************************************************************
				#if Select_CLK == NO_CLK_SOURSE 
				CLEAR_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
				#elif Select_CLK == CLK_1
				SET_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
				#elif Select_CLK == CLK_8
				CLEAR_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
				#elif Select_CLK == CLK_64
				SET_BIT(TCCR0,0);
				SET_BIT(TCCR0,1);
				CLEAR_BIT(TCCR0,2);
				#elif Select_CLK == CLK_256
				CLEAR_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
				#elif Select_CLK == CLK_1024
				SET_BIT(TCCR0,0);
				CLEAR_BIT(TCCR0,1);
				SET_BIT(TCCR0,2);
	/*			#endif
	#elif Select_Timer == Timer2
		
		 *
		 *
		 *
		 *
		 *
		*/
				#endif
			//*****************************************************
	#endif
	// ***********************Enable the global interrupt
	SET_BIT(SREG,7);
}
void SET_OCRX_value(u16 duty)
{
	#if Select_Timer == Timer1
	OCR1A = duty;
	#elif Select_Timer == Timer0
	OCR0 = duty;
	/*
	#elif Select_Timer == Timer2
	
	*/
	#endif
}
void SET_TOP_Timer1_value(u16 top)
{
	ICR1 = top;
}
void PRE_LOAD_Timer(u16 k)
{
	#if Select_Timer == Timer1
	TCNT1 = k;
	#elif Select_Timer == Timer0
	TCNT0 = k;
	/*
	#elif Select_Timer == Timer2

	*/
	#endif

}
