/*
 * LED_interface.h
 *
 * Created: 9/18/2022 1:42:16 PM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct
{
	u8 LED_PORT;
	u8 LED_PIN;
	u8 LED_ConnectionType;
}LED_t;

/* Macros For Led Connection Type */
#define LED_ACTIVE_HIGH     1
#define LED_ACTIVE_LOW      0


             /*************** APIS PROTO TYPES ***************/

void LED_on    (LED_t *PstrLED);
void LED_off   (LED_t *PstrLED);
void LED_toggle(LED_t *PstrLED);

#endif /* LED_INTERFACE_H_ */