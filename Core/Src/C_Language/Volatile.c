#include "C_Language/Volatile.h"


// Create a constant pointer to a volatile 32-bit register
#define GPIOA_IDR_ADDRESS  0x40020010U   // Example GPIO Input register address

// volatile   → value can change anytime (hardware changes it)
// const      → pointer is constant (cannot be modified)
// uint32_t * → pointer type
volatile uint32_t * const GPIOA_IDR = (uint32_t *)GPIOA_IDR_ADDRESS;


#define TIM3_CNT   (*((volatile uint32_t*)0x40000424))

void Read_PA0_Switch()
{
	//uint32_t pin_value;
	//pin_value = *GPIOA_IDR;  	// Read the hardware register

	if((*GPIOA_IDR) & (1 << 0))   // Check PA0
	{
		for(int i = 0; i < 50000; i++)
		{
		}
		    if( (*GPIOA_IDR & 1) == 0 )
		    {
		         Green_LED_TOGGLE();
		    }
	}
	else
	{
		uint32_t time;
		time = TIM3_CNT;  // Read changes every clock tick
		printf("Timer: %u\n", (unsigned int)time);

	}
}


/*void Read_PA0_Switch()
{

	  | Declaration                     | Meaning                                                    |
	  | ------------------------------- | ---------------------------------------------------------- |
	  | `volatile uint32_t *ptr`        | pointer to volatile data                                   |
	  | `uint32_t * volatile ptr`       | volatile pointer                                           |
	  | `volatile uint32_t * const ptr` | **constant pointer** to volatile data (best for registers) |
	  | `const volatile uint32_t *ptr`  | pointer to read-only volatile data                         |


	const volatile uint32_t *ptr = (uint32_t *)0x40020010;


	volatile uint32_t *ptr = (uint32_t *)0x40020010;
	ptr = (uint32_t *)0x40020456;    // no error
	*ptr=23;                         // no error



	uint32_t * volatile ptr = (uint32_t *)0x40020010;
	ptr = (uint32_t *)0x40020456;    // no error
	*ptr=23;                         // no error


	volatile uint32_t * const ptr = (uint32_t *)0x40020010;
	ptr = (uint32_t *)0x40020456;    // it will give error
	*ptr=23;                         // no error


	const volatile uint32_t *ptr = (uint32_t *)0x40020010;
	ptr = (uint32_t *)0x40020456;    // no error
	*ptr=23;                         // it will give error



	if((*ptr) & (1 << 0))   // Check PA0
		{
			for(int i = 0; i < 50000; i++)
			{
			}
			    if( (*GPIOA_IDR & 1) == 0 )
			    {
			         Green_LED_TOGGLE();
			    }
		}
		else
		{
			uint32_t time;
			time = TIM3_CNT;  // Read changes every clock tick
			printf("Timer: %u\n", (unsigned int)time);

		}

}*/


/*volatile uint32_t sensor_value = 0;   // ISR changes this

volatile uint32_t *ptr = &sensor_value;   // pointer to volatile data

void EXTI0_IRQHandler(void)
{
    sensor_value++;    // Interrupt updates it
}

int main()
{
    while(1)
    {
        uint32_t temp = *ptr;   // Always reads fresh value
    }
}*/


/*uint32_t val1 = 10;
uint32_t val2 = 20;

uint32_t * volatile ptr = &val1;   // volatile pointer (address may change)

void update_pointer()
{
    ptr = &val2;     // pointer changes here
}

int main()
{
    uint32_t temp = *ptr;   // reads from whichever variable ptr currently points to
}*/



/*#define GPIOA_IDR_ADDRESS  0x40020010U   // STM32F407 GPIOA Input Register

volatile uint32_t * const GPIOA_IDR = (uint32_t *)GPIOA_IDR_ADDRESS;

int main()
{
    uint32_t pin = *GPIOA_IDR;   // Read register (value changes → volatile)

    if(pin & (1 << 0))
    {
        // PA0 HIGH
    }
}*/



/*
#define TIM3_CNT_ADDR   0x40000424U   // Timer 3 CNT register

const volatile uint32_t *ptr = (uint32_t *)TIM3_CNT_ADDR;

int main()
{
    uint32_t counter = *ptr;  // OK (read)
    // *ptr = 100;            // ❌ compile error (read-only)
}
*/



