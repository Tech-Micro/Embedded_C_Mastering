#include "Protocols/Timer/Timer.h"


volatile int tim3_counter = 0;


void TIM3_Init(void)
{
    // Enable TIM3 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    /* TIM3 @ 1 ms tick
       PSC = 16000 - 1 = 1 kHz tick
       ARR = 1000 - 1 = 1 second overflow
    */
    TIM3->PSC = 1600 - 1;   //TIM3->PSC = 16000 - 1;
    TIM3->ARR = 12 - 1;      //TIM3->ARR = 1000 - 1;

    // Enable interrupt
    TIM3->DIER |= TIM_DIER_UIE;

    // Enable timer
    TIM3->CR1 |= TIM_CR1_CEN;

    // Set Low Priority (6)
    NVIC_SetPriority(TIM3_IRQn, 6);
    NVIC_EnableIRQ(TIM3_IRQn);
}




void TIM3_IRQHandler(void)
{
    if (TIM3->SR & TIM_SR_UIF)
    {
        TIM3->SR &= ~TIM_SR_UIF;   // Clear flag

        tim3_counter++;

        // Simulate long processing (busy loop)
        //for(int i = 0; i < 20000; i++);

        //printf("TIM3 IRQ Running... Count = %d\n", tim3_counter);
    }
}


