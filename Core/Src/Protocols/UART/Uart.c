#include "Protocols/UART/Uart.h"


void UART2_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // PA3 → USART2_RX (AF7)
    GPIOA->MODER |= (2U << (3*2));
    GPIOA->AFR[0] |= (7U << (3*4));

    USART2->BRR = 0x1117;   // 115200 @16MHz
    USART2->CR1 |= USART_CR1_RE;      // Receiver enable
    USART2->CR1 |= USART_CR1_RXNEIE;  // RX interrupt enable
    USART2->CR1 |= USART_CR1_UE;      // USART enable

    NVIC_SetPriority(USART2_IRQn, 5);
    NVIC_EnableIRQ(USART2_IRQn);
}


void USART2_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART2->SR & USART_SR_RXNE)
    {
        uint8_t byte = USART2->DR;  // Read data

        // Send received byte to queue
        xQueueSendFromISR(uartQueue, &byte, &xHigherPriorityTaskWoken);

        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}
