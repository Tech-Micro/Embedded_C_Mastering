/*
 * Task.h
 *
 *  Created on: 3 Dec 2025
 *      Author: User
 */

#ifndef INC_RTOS_TASK_H_
#define INC_RTOS_TASK_H_

#include "main.h"
#include "stm32f4xx_hal.h"

xTaskHandle Task1_stack_Handle;
xTaskHandle Task2_stack_Handle;

void Task1_Stack(void *argument);
void Task2_Stack(void *argument);

#endif /* INC_RTOS_TASK_H_ */
