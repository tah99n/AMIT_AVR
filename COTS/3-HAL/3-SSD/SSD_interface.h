/*
 * SSD_interface.h
 *
 * Created: 9/18/2022 12:38:42 PM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

void SSD_on(void);
void SSD_displayNumber(u8 desiredNumber);
static void writeHalfPort(u8 Value);

#endif /* SSD_INTERFACE_H_ */