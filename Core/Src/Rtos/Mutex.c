#include "RTOS/Mutex.h"


int Read_Temperature();


void MotorTask(void *argument)
{
    while(1)
    {
        if (xSemaphoreTake(xUartMutex, portMAX_DELAY) == pdTRUE)
        {
            printf("Motor Task: Motor Running...\n");
            xSemaphoreGive(xUartMutex);
        }

        vTaskDelay(3000);
    }
}


void SensorTask(void *argument)
{
    while(1)
    {
        if (xSemaphoreTake(xUartMutex, portMAX_DELAY) == pdTRUE)
        {
            printf("Sensor Task: Temp = %d C\n", Read_Temperature());
            xSemaphoreGive(xUartMutex);
        }

        vTaskDelay(3000);
    }
}


int Read_Temperature()
{
	int temp=100;
	return temp;
}
