#ifndef INC_RTOS_MUTEX_H_
#define INC_RTOS_MUTEX_H_

#include "main.h"
#include "stm32f4xx_hal.h"

SemaphoreHandle_t xUartMutex;

xTaskHandle Motor_Handle;
xTaskHandle Sensor_Handle;


void MotorTask(void *argument);
void SensorTask(void *argument);

#endif /* INC_RTOS_MUTEX_H_ */
