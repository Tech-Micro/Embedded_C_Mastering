#include "RTOS/Init.h"


void Calculate_Heap_Size();
void First_Task(void *PVparamater);
xTaskHandle First_Task_Handle;

void RTOS_INIT()
{
	Motor_Fault     = xSemaphoreCreateBinary();
	Calculate_Heap_Size();

	Dummy           = xSemaphoreCreateBinary();
	Calculate_Heap_Size();

	Duplicate_mutex = xSemaphoreCreateBinary();
	Calculate_Heap_Size();

	CountSem = xSemaphoreCreateCounting(10, 1);
	Calculate_Heap_Size();

	xUartMutex = xSemaphoreCreateMutex();
	Calculate_Heap_Size();

	uartQueue = xQueueCreate(32, sizeof(uint8_t));
	Calculate_Heap_Size();

	if(Motor_Fault==NULL)
	{
		printf("Motor_Fault semaphore allocation failed");
	}
	if(Dummy == NULL)
	{
		printf("Dummy semaphore allocation failed");
	}
	if(Duplicate_mutex == NULL)
	{
		printf("Duplicate_mutex semaphore allocation failed");
	}
	if(CountSem == NULL)
	{
		printf("CountSem semaphore allocation failed");
	}

	xTaskCreate(First_Task,"First Task",128,NULL,6,&First_Task_Handle);

	xTaskCreate(Motor_Saftey,"T1",128,NULL,5,&Motor_Saftey_Handle);
	xTaskCreate(Task2,"T2",128,NULL,5,&Task_Handle);
	Calculate_Heap_Size();

	xTaskCreate(High_Task,"High",128,NULL,4,&High_Handle);
	xTaskCreate(Medium_Task,"Medium",128,NULL,3,&Medium_Handle);
	xTaskCreate(Low_Task,"Low",128,NULL,2,&Low_Handle);
	Calculate_Heap_Size();

	xTaskCreate(ProducerTask, "Producer", 128, NULL, 2, &Producer_Handle);
	xTaskCreate(ConsumerTask, "Consumer", 128, NULL, 2, &Consumer_Handle);
	Calculate_Heap_Size();


    xTaskCreate(MotorTask,  "Motor",  256, NULL, 2, &Motor_Handle);
    xTaskCreate(SensorTask, "Sensor", 256, NULL, 2, &Sensor_Handle);
    Calculate_Heap_Size();

    xTaskCreate(UART_Task, "UART", 256, NULL, 2, &UART_Handle);
    Calculate_Heap_Size();

    xTaskCreate(Task1_Stack, "T1 stack", 128, NULL, 2, &Task1_stack_Handle);   // Task1 → 128 words = 512 bytes
    xTaskCreate(Task2_Stack, "T2 stack", 256, NULL, 2, &Task2_stack_Handle);   // Task2 → 256 words = 1024 bytes
    Calculate_Heap_Size();

	printf("Now Starting Scheduler...\n");

	vTaskStartScheduler();


}

void Calculate_Heap_Size()
{
    uint32_t free_heap_size;
    static uint32_t old_size=20472;
	free_heap_size = xPortGetFreeHeapSize();
	uint32_t result= old_size - free_heap_size;
	printf("Free Heap Size is %lu bytes----- This event has taken %lu bytes\n", free_heap_size,result);
	old_size = free_heap_size;
}



void First_Task(void *PVparamater)
{
	while(1)
	{
        //vTaskSuspend(Motor_Saftey_Handle);
    	//vTaskSuspend(Task_Handle);
    	vTaskSuspend(High_Handle);
    	vTaskSuspend(Medium_Handle);
    	vTaskSuspend(Low_Handle);
    	vTaskSuspend(Producer_Handle);
    	vTaskSuspend(Consumer_Handle);
    	vTaskSuspend(Motor_Handle);
    	vTaskSuspend(Sensor_Handle);
    	vTaskSuspend(UART_Handle);
    	vTaskSuspend(Task1_stack_Handle);
    	vTaskSuspend(Task2_stack_Handle);
        vTaskDelete(First_Task_Handle);
	}
}
