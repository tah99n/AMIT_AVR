/*
 * EEPROM_interface.h
 *
 * Created: 10/9/2022 11:18:43 AM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


#define EEPROM_FIXED_ADDRESS          0x50

void EEPROM_writeByte(u16 byteAddress,u8 data);
void EEPROM_readByte (u16 byteAddress,u8* returnedData);


#endif /* EEPROM_INTERFACE_H_ */