/*
 * EXTI_test.c
 *
 * Created: 9/15/2022 11:59:08 AM
 * Author : Mahmoud Tahoun
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"

int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	//global interrupt enable
	SET_BIT(SREG,7);
	
	EXTI_enable(EXTI_INT0,EXTI_FALLING_EDGE);
    while (1) 
    {
    }
}


// ISR Function protoType for EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	DIO_togglePinValue(DIO_PORTA,DIO_PIN3);
}