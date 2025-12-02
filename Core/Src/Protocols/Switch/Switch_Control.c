#include "Protocols/Switch/Switch_Control.h"


static int test;
void delayMs(uint32_t ms);

/* -------------------- GPIO INIT -------------------- */
void GPIO_Init(void)
{
    // Enable GPIOA (Button) and GPIOD (LEDs)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // PA0 as input (user button)
    GPIOA->MODER &= ~(3U << (0 * 2));  // Input mode
    GPIOA->PUPDR |= (2U << (0 * 2));  // 10 = Pull-down

}



/* -------------------- EXTI0 INIT (Button Interrupt) -------------------- */
void EXTI0_Init(void)
{
    // Enable SYSCFG clock (for EXTI line configuration)
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // Connect EXTI Line0 to PA0
    SYSCFG->EXTICR[0] &= ~(0xF << 0);   // EXTI0 from PA0

    // Configure EXTI line 0 for rising edge trigger (button press)
    EXTI->IMR  |= (1U << 0);   // Unmask line 0
    EXTI->RTSR |= (1U << 0);   // Rising edge trigger
    EXTI->FTSR &= ~(1U << 0);  // No falling edge

    // Enable EXTI0 interrupt in NVIC
    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_SetPriority(EXTI0_IRQn, 5);
}



void EXTI0_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (EXTI->PR & (1U << 0))
    {
    	test++;

        EXTI->PR = (1U << 0);  // Clear pending

        xSemaphoreGiveFromISR(Motor_Fault, &xHigherPriorityTaskWoken);

        delayMs(200);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

/* -------------------- SIMPLE DELAY -------------------- */
void delayMs(uint32_t ms)
{
    for(uint32_t i=0; i < ms*1600; i++);
}


