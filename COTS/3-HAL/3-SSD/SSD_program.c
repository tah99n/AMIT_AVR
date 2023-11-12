/*
 * SSD_program.c
 *
 * Created: 9/18/2022 12:38:32 PM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h"


void SSD_on(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}


void SSD_displayNumber(u8 desiredNumber)
{
	writeHalfPort(desiredNumber);
}


static void writeHalfPort(u8 Value)
{
	if (0 == GET_BIT(Value, 0))
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_LOW);
	}
	else 
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN4, DIO_PIN_HIGH);
	}
	
	if (0 == GET_BIT(Value, 1))
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_LOW);
	}
	else 
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN5, DIO_PIN_HIGH);
	}
	
	if (0 == GET_BIT(Value, 2))
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN6, DIO_PIN_LOW);
	}
	else 
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN6, DIO_PIN_HIGH);
	}
	
	if (0 == GET_BIT(Value, 3))
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN7, DIO_PIN_LOW);
	}
	else 
	{
		DIO_setPinValue(DIO_PORTA, DIO_PIN7, DIO_PIN_HIGH);
	}
}