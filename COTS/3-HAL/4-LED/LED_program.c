/*
 * LED_program.c
 *
 * Created: 9/18/2022 1:42:06 PM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LED_interface.h"


void LED_on(LED_t *PstrLED)
{
	if(PstrLED != NULL)
	{
		if(PstrLED->LED_ConnectionType == LED_ACTIVE_HIGH)
		{
			DIO_setPinValue(PstrLED->LED_PORT,PstrLED->LED_PIN,DIO_PIN_HIGH);
		}
		else if(PstrLED->LED_ConnectionType == LED_ACTIVE_LOW)
		{
			DIO_setPinValue(PstrLED->LED_PORT,PstrLED->LED_PIN,DIO_PIN_LOW);
		}
	}
}


void LED_off(LED_t *PstrLED)
{
	if(PstrLED != NULL)
	{
		if(PstrLED->LED_ConnectionType == LED_ACTIVE_HIGH)
		{
			DIO_setPinValue(PstrLED->LED_PORT,PstrLED->LED_PIN,DIO_PIN_LOW);
		}
		else if(PstrLED->LED_ConnectionType == LED_ACTIVE_LOW)
		{
			DIO_setPinValue(PstrLED->LED_PORT,PstrLED->LED_PIN,DIO_PIN_HIGH);
		}
	}
}


void LED_toggle(LED_t *PstrLED)
{
	if(PstrLED != NULL)
	{
		DIO_togglePinValue(PstrLED->LED_PORT,PstrLED->LED_PIN);
	}
}