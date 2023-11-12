/*
 * TWI_interface.h
 *
 * Created: 10/6/2022 1:23:52 PM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void TWI_initMaster           (void);
void TWI_initSlave            (u8 slaveAdd);
void TWI_sendStartCondition   (void);
void TWI_sendRepStartCondition(void);
void TWI_sendStopCondition    (void);
void TWI_sendSlaveAddwithWrite(u8 slaveAdd);
void TWI_sendSlaveAddwithRead (u8 slaveAdd);
void TWI_sendMasterDataByte   (u8 data);
void TWI_readMasterDataByte   (u8* returnedData);

#endif /* TWI_INTERFACE_H_ */