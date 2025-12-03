#ifndef INC_PROTOCOLS_TIMER_TIMER_H_
#define INC_PROTOCOLS_TIMER_TIMER_H_

#include "main.h"
#include "stm32f4xx_hal.h"

void TIM3_Init(void);
void TIM3_IRQHandler(void);

#endif /* INC_PROTOCOLS_TIMER_TIMER_H_ */
