/*
 * TMR_program.c
 *
 * Created: 9/22/2022 12:37:16 PM
 *  Author: Mahmoud Tahoun
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR_interface.h"


static void(*TMR_timer0_ctc_pCallBack)(void) = NULL;


/* TIMER0 */
void TMR_timer0Init(void)
{
	// Select Mode = CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);
}


void TMR_timer0start(void)
{
    // Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


void TMR_timer0stop(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


void TMR_timer0SetCompareMatchValue(u8 OCR0_Value)
{
	// Init Timer With Compare Value
	OCR0 = OCR0_Value;
}


void TMR_timer0_CTC_SetCallBack(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		TMR_timer0_ctc_pCallBack = ptr;
	}
}


// ISR Function protoType for TMR0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
  //call action
  if(TMR_timer0_ctc_pCallBack != NULL)
  {
  	TMR_timer0_ctc_pCallBack();
  }
}