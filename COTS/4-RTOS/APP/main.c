/*
 * RTOS_test.c
 *
 * Created: 10/18/2022 9:56:04 AM
 * Author : Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* RTOS STACK */
#include "KERNEL_interface.h"

void LED_0(void);
void LED_1(void);
void LED_2(void);
void BUZZER(void);

int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); //LED_0
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT); //LED_1
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT); //LED_2
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT); //BUZZER
	
	RTOS_createTask(0,500,&LED_0);
	RTOS_createTask(1,1000,&LED_1);
	RTOS_createTask(2,1500,&LED_2);
	RTOS_createTask(3,2000,&BUZZER);
	
	RTOS_deleteTask(0);
	RTOS_createTask(0,1000,&LED_0);
	
	RTOS_start();
	
    while (1) 
    {
    }
}


void LED_0(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
}

void LED_1(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN7);
}

void LED_2(void)
{
	DIO_togglePinValue(DIO_PORTD,DIO_PIN3);
}

void BUZZER(void)
{
	DIO_togglePinValue(DIO_PORTA,DIO_PIN3);
	RTOS_resumeTask(0);
}