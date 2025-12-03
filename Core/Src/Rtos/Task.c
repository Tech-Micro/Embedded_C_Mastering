#include "RTOS/Task.h"


void Task1_Stack(void *argument)
{
    while(1)
    {
        int a = 10;
        int b = 20;
        int c = a + b;

        printf("Task1 result = %d\n", c);

        // Print remaining stack (in words)
        printf("Task1 Free Stack = %lu words\n",uxTaskGetStackHighWaterMark(Task1_stack_Handle));

        Calculate_Heap_Size();

        vTaskDelay(1000);
    }
}


void Task2_Stack(void *argument)
{
    char msg[100];  // Uses stack heavily

    while(1)
    {
        strcpy(msg, "This is a long message stored on stack");
        printf("Task2: %s\n", msg);

        // Check stack usage
        printf("Task2 Free Stack = %lu words\n",uxTaskGetStackHighWaterMark(Task2_stack_Handle));

        vTaskDelay(1500);
    }
}
