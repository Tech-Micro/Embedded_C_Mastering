#include "RTOS/Semaphore.h"



void Motor_Saftey(void *PVparamater)
{
	while(1)
	{
		xSemaphoreTake(Motor_Fault,portMAX_DELAY);
        printf("Motor Turned off\n");
        Red_LED_ON();
		xSemaphoreGive(Dummy);
        vTaskDelay(1);
	}
}
void Task2(void *PVparamater)
{

	while(1)
	{

		xSemaphoreTake(Dummy,portMAX_DELAY);
		printf("Task2\n");
		vTaskDelay(5000);
		Red_LED_OFF();
	}
}



void Low_Task(void *pvParameters)
{
    while (1)
    {
        xSemaphoreTake(Duplicate_mutex, portMAX_DELAY); // Holds the resource
        printf("Low Task: Using shared resource\n");
        vTaskDelay(10000);                              // Simulate long processing
        xSemaphoreGive(Duplicate_mutex);
    }
}

void Medium_Task(void *pvParameters)
{
    while (1)
    {
        printf("Medium Task: Running\n");
        vTaskDelay(2000);
    }
}

void High_Task(void *pvParameters)
{
	xSemaphoreGive(Duplicate_mutex);
    while (1)
    {

        printf("High Task: Wants shared resource\n");
        xSemaphoreTake(Duplicate_mutex, portMAX_DELAY); // Gets blocked here
        vTaskDelay(500);
        printf("High Task: Got resource!\n");
        xSemaphoreGive(Duplicate_mutex);
        vTaskDelay(100);
    }
}



