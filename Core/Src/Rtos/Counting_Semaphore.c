#include "RTOS/Counting_Semaphore.h"


void ProducerTask(void *argument)
{
	while(1)
	{
		  // Simulate sensor reading
		  vTaskDelay(pdMS_TO_TICKS(500));

		  // Add one item into the buffer
		  xSemaphoreGive(CountSem);

		  printf("Produced 1 item\n");
	}
}


void ConsumerTask(void *argument)
{
	while(1)
	{
	  // Wait until at least one item is available
	  xSemaphoreTake(CountSem, portMAX_DELAY);

	  printf("Consumed 1 item\n");

	  vTaskDelay(pdMS_TO_TICKS(5000));  // slow consumer
	}
}
