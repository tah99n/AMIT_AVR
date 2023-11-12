/*
 * TWI_program.c
 *
 * Created: 10/6/2022 1:23:43 PM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TWI_interface.h"


void TWI_initMaster(void)
{
	// Set Prescaller = 1 >> Set Freq. = 400KHZ
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	TWBR = 12;
	
	// Enable ACK 
	SET_BIT(TWCR,6);
	
	// Enable TWI
	SET_BIT(TWCR,2);
}


void TWI_initSlave(u8 slaveAdd)
{
	if(slaveAdd<128)
	{
	   // Set Slave Address
	   TWAR = slaveAdd<<1;
	   
	   // Disable General Call
	   CLR_BIT(TWAR,0);
		
	   // Enable ACK 
	   SET_BIT(TWCR,6);
	
	   // Enable TWI
	   SET_BIT(TWCR,2);
	}
}


void TWI_sendStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = SC ACK
	while((TWSR & 0xF8) != 0x08);
}


void TWI_sendRepStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = Repeated SC ACK	
	while((TWSR & 0xF8) != 0x10);
}


void TWI_sendStopCondition(void)
{
	// Send Stop Condition
	SET_BIT(TWCR,4);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
}


void TWI_sendSlaveAddwithWrite(u8 slaveAdd)
{
	// Send slave address
	TWDR = slaveAdd<<1;
	
	// Select write operation
	CLR_BIT(TWDR,0);
	
	// Clear SC bit
	CLR_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = Master transmit ( slave address + Write request ) ACK	
	while((TWSR & 0xF8) != 0x18);
}


void TWI_sendSlaveAddwithRead(u8 slaveAdd)
{
	// Send slave address
	TWDR = slaveAdd<<1;
	
	// Select read operation
	SET_BIT(TWDR,0);
	
	// Clear SC bit
	CLR_BIT(TWCR,5);
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = Master transmit ( slave address + Read request ) ACK
	while((TWSR & 0xF8) != 0x40);
}


void TWI_sendMasterDataByte(u8 data)
{
	// Write Data into data register
	TWDR = data;
	
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = Master transmit data ACK
	while((TWSR & 0xF8) != 0x28);
}


void TWI_readMasterDataByte(u8* returnedData)
{
	// Clear flag to start current job
	SET_BIT(TWCR,7);
	
	// Wait for the flag
	while(0 == GET_BIT(TWCR,7));
	
	// Check ACK = Master received data with ACK
	while((TWSR & 0xF8) != 0x50);
	
	// Read Data from data register
	*returnedData = TWDR;
}