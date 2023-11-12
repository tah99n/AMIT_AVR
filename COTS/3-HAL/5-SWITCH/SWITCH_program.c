/*
 * SWITCH_program.c
 *
 * Created: 16/18/2022 
 *  Author: Mahmoud Tahoun
 */ 

 
 /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SWITCH_interface.h"

void SWITCH_GetState(SWITCH_t *PstrSwitch, SWITCH_State_t *PEnuSwitch)
{
	u8 Local_switchState;
	if ((PstrSwitch != NULL) && (PEnuSwitch != NULL ))
	{
		DIO_getPinValue(PstrSwitch->SWITCH_PORT, PstrSwitch->SWITCH_PIN, &Local_switchState);
		
		if ((PstrSwitch->SWITCH_ConnectionType) == SWITCH_ACTIVE_LOW)
		{
			if (0 == Local_switchState)
			{
				*PEnuSwitch = SWITCH_PRESSED;
			}
			else if (1 == Local_switchState)
			{
				*PEnuSwitch = SWITCH_NOT_PRESSED;
			}
		}
		
		else if ((PstrSwitch->SWITCH_ConnectionType) == SWITCH_ACTIVE_HIGH)
		{
			if (1 == Local_switchState)
			{
				*PEnuSwitch = SWITCH_PRESSED;
			}
			else if (0 == Local_switchState)
			{
				*PEnuSwitch = SWITCH_NOT_PRESSED;
			}
		}
	}
}