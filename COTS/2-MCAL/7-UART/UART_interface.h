/*
 * UART_interface.h
 *
 * Created: 10/4/2022 9:30:59 AM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_init    (void);
void UART_TxChar  (u8 data);
void UART_TxString(u8* String);
void UART_RxChar  (u8* returnedData);


#endif /* UART_INTERFACE_H_ */