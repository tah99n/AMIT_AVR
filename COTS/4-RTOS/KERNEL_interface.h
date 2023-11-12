/*
 * KERNEL_interface.h
 *
 * Created: 10/18/2022 9:58:21 AM
 *  Author: Mahmoud Tahoun
 */ 


#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_


#define RTOS_TASK_SUSPENDED           1
#define RTOS_TASK_RESUMED             2

typedef struct
{
	void(*pTaskFunc)(void);
	u16 TaskPeriodicity;
	u8  TaskState;
}Task_t;


void RTOS_start             (void);
void RTOS_createTask        (u8 priority, u16 periodicity, void(*pTaskCode)(void));
void RTOS_suspendTask       (u8 priority); 
void RTOS_resumeTask        (u8 priority);
void RTOS_deleteTask        (u8 priority);
static void privateScheduler(void);


#endif /* KERNEL_INTERFACE_H_ */