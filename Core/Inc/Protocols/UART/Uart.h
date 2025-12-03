#ifndef INC_PROTOCOLS_UART_UART_H_
#define INC_PROTOCOLS_UART_UART_H_

#include "main.h"
#include "stm32f4xx_hal.h"

xTaskHandle UART_Handle;

void UART_Task(void *argument);

void UART2_Init();

#endif /* INC_PROTOCOLS_UART_UART_H_ */
