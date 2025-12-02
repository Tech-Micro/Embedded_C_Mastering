#include "RTOS/Init.h"



void RTOS_INIT()
{
	Motor_Fault     = xSemaphoreCreateBinary();
	Dummy           = xSemaphoreCreateBinary();
	Duplicate_mutex = xSemaphoreCreateBinary();

	CountSem = xSemaphoreCreateCounting(10, 1);

	xUartMutex = xSemaphoreCreateMutex();

	uartQueue = xQueueCreate(32, sizeof(uint8_t));

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

	xTaskCreate(Motor_Saftey,"T1",128,NULL,5,&Motor_Saftey_Handle);
	xTaskCreate(Task2,"T2",128,NULL,5,&Task_Handle);
	xTaskCreate(High_Task,"High",128,NULL,4,&High_Handle);
	xTaskCreate(Medium_Task,"Medium",128,NULL,3,&Medium_Handle);
	xTaskCreate(Low_Task,"Low",128,NULL,2,&Low_Handle);


	xTaskCreate(ProducerTask, "Producer", 128, NULL, 2, NULL);
	xTaskCreate(ConsumerTask, "Consumer", 128, NULL, 2, NULL);


    xTaskCreate(MotorTask,  "Motor",  256, NULL, 2, NULL);
    xTaskCreate(SensorTask, "Sensor", 256, NULL, 2, NULL);

    xTaskCreate(UART_Task, "UART", 256, NULL, 2, NULL);

	vTaskStartScheduler();


}


