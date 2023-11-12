/*
 * KERNEL_programe.c
 *
 * Created: 10/18/2022 9:58:07 AM
 *  Author: Mahmoud Tahoun
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "GI_interface.h"

/* RTOS STACK */
#include "TMR_interface.h"
#include "KERNEL_interface.h"
#include "KERNEL_config.h"

Task_t TaskArr[RTOS_TASK_NUM];

void RTOS_start(void)
{
	GI_enable();
	TMR_timer0Init();
	TMR_timer0SetCompareMatchValue(249);
	TMR_timer0_CTC_SetCallBack(&privateScheduler);
	TMR_timer0start();
}


void RTOS_createTask(u8 priority, u16 periodicity, void(*pTaskCode)(void))
{
	if((priority < RTOS_TASK_NUM) && (pTaskCode != NULL) && (TaskArr[priority].pTaskFunc == NULL))
	{
		TaskArr[priority].TaskPeriodicity = periodicity;
		TaskArr[priority].pTaskFunc       = pTaskCode;
		TaskArr[priority].TaskState       = RTOS_TASK_RESUMED; 
	}
	
	else
	{
		// Do Nothing
	}
}


void RTOS_suspendTask(u8 priority)
{
	TaskArr[priority].TaskState = RTOS_TASK_SUSPENDED;
}


void RTOS_resumeTask(u8 priority)
{
	TaskArr[priority].TaskState = RTOS_TASK_RESUMED;
}


void RTOS_deleteTask(u8 priority)
{
	TaskArr[priority].pTaskFunc = NULL;
}


static void privateScheduler(void)
{
	volatile static u16 tickCounter = 0; 
	++tickCounter;
	
	u8 taskCounter;
	for(taskCounter=0;taskCounter<RTOS_TASK_NUM;++taskCounter)
	{
		if(TaskArr[taskCounter].TaskState == RTOS_TASK_RESUMED)
		{
			if(tickCounter%(TaskArr[taskCounter].TaskPeriodicity)==0)
			{
				if(TaskArr[taskCounter].pTaskFunc != NULL)
				{
					// Call Task
				    TaskArr[taskCounter].pTaskFunc();
				}
				else
				{
					//Do Nothing
				}
			}
			else
			{
				//continue
			}
		}
		else
		{
			// Task is Suspended Do Nothing
		}
	}
}