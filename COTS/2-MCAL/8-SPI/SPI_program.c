/*
 * SPI_program.c
 *
 * Created: 10/4/2022 1:21:02 PM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "SPI_interface.h"


void SPI_initMaster(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPI->SPCR,5);
	
	// select Master Mode
	SET_BIT(SPI->SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPI->SPCR,3);
	SET_BIT(SPI->SPCR,2);
	
	// select CLK Rate = FCPU/16 (1 MHZ)
	SET_BIT(SPI->SPCR,0);
	CLR_BIT(SPI->SPCR,1);
	CLR_BIT(SPI->SPSR,0);
	
	// enable SPI
	SET_BIT(SPI->SPCR,6);
}


void SPI_initSlave(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPI->SPCR,5);
	
	// select Slave Mode
	CLR_BIT(SPI->SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPI->SPCR,3);
	SET_BIT(SPI->SPCR,2);
	
	// enable SPI
	SET_BIT(SPI->SPCR,6);
}


void SPI_transieve(u8 TxData,u8* RxData)
{
	if(RxData != NULL)
	{
		SPI->SPDR = TxData;
		
		while (0 == GET_BIT(SPI->SPSR,7));
		*RxData = SPI->SPDR;
	}
}