/*
 * UART_program.c
 *
 * Created: 10/4/2022 9:30:07 AM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "UART_interface.h"


void UART_init(void)
{
	/*u8 UCSRC_value;
	// configure data bits = 8
	SET_BIT(UCSRC_value,1);
	SET_BIT(UCSRC_value,2);
	
	
	// configure no parity
	CLR_BIT(UCSRC_value,4);
	CLR_BIT(UCSRC_value,5);
	
	// configure stop bits = 1
	CLR_BIT(UCSRC_value,3);
	
	// selct UART MODE = Asynchronous
	CLR_BIT(UCSRC_value,6);
	
	// writing the UCSRC
	SET_BIT(UCSRC_value,7);
	
	UCSRC = UCSRC_value;*/
	
	// writing the UCSRC , // selct UART MODE = Asynchronous , 	// configure no parity , // configure data bits = 8 , // configure stop bits = 1
	UCSRC = 0x86; // 0b10000110
	CLR_BIT(UCSRB,2);
	
	// set buad rate = 9600
	UBRRL = 103;
	
	//Enable Tx
	SET_BIT(UCSRB,3);
	
	//Enable Rx
	SET_BIT(UCSRB,4);
}


void UART_TxChar(u8 data)
{
	UDR = data;
	while(0 == GET_BIT(UCSRA,5));
}


void UART_RxChar(u8* returnedData)
{
	if(returnedData != NULL)
	{
		while(0 == GET_BIT(UCSRA,7));
		
		*returnedData = UDR;
	}
}


void UART_TxString(u8* String)
{
	if(String != NULL)
	{
	  u8 counter = 0;
	  while (String[counter] != '\0')
	  {
	  	UART_TxChar(String[counter]);
	  	counter++;
	  }
	}
}