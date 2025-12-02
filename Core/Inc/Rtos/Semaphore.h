#ifndef INC_RTOS_SEMAPHORE_H_
#define INC_RTOS_SEMAPHORE_H_

#include "main.h"
#include "stm32f4xx_hal.h"

xTaskHandle Motor_Saftey_Handle;
xTaskHandle Task_Handle;

xSemaphoreHandle Motor_Fault;
xSemaphoreHandle Dummy;
xSemaphoreHandle Duplicate_mutex;


xTaskHandle High_Handle;
xTaskHandle Medium_Handle;
xTaskHandle Low_Handle;


void Create_Semap_API();

void Motor_Saftey(void *PVparamater);
void Task2(void *PVparamater);


void Low_Task(void *pvParameters);
void Medium_Task(void *pvParameters);
void High_Task(void *pvParameters);


#endif /* INC_RTOS_SEMAPHORE_H_ */
