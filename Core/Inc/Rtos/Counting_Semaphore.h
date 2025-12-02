#ifndef INC_RTOS_COUNTING_SEMAPHORE_H_
#define INC_RTOS_COUNTING_SEMAPHORE_H_


#include "main.h"
#include "stm32f4xx_hal.h"


SemaphoreHandle_t CountSem;


void ProducerTask(void *argument);
void ConsumerTask(void *argument);


#endif /* INC_RTOS_COUNTING_SEMAPHORE_H_ */
