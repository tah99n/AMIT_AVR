/*
 * SWITCH_interface.h
 *
 * Created: 16/18/2022 
 *  Author: Mahmoud Tahoun
 */ 

 #ifndef SWITCH_interface_H_
 #define SWITCH_interface_H_
 
 typedef struct
{
	u8 SWITCH_PORT;
	u8 SWITCH_PIN;
	u8 SWITCH_ConnectionType;
}SWITCH_t;

/* enum For Switch state */
typedef enum
{
	SWITCH_PRESSED,
	SWITCH_NOT_PRESSED
}SWITCH_State_t;

/* Macros For Switch Connection Type */
#define SWITCH_ACTIVE_HIGH     1
#define SWITCH_ACTIVE_LOW      0

                 /*************** APIS PROTO TYPES ***************/

					   
void SWITCH_GetState(SWITCH_t *PstrSwitch, SWITCH_State_t *PEnuSwitch);
 #endif