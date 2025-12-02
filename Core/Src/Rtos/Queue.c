#include "RTOS/Queue.h"


void UART_Task(void *argument)
{
    uint8_t rx;

    while(1)
    {
        // Block until data available
        if (xQueueReceive(uartQueue, &rx, portMAX_DELAY) == pdTRUE)
        {
            printf("Received Byte: %c\n", rx);
        }
    }
}
