#include "C_Language/Typecasting.h"

#define GPIOA_IDR_ADDR_SAPMLE  0x40020010U
volatile uint32_t * const GPIOA_IDR_SAPMLE = (uint32_t *)GPIOA_IDR_ADDR_SAPMLE;


typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t IDR;
} GPIO_TypeDef_Simple ;

#define GPIOA_SIMPLE   ((GPIO_TypeDef_Simple  *)0x40020000)




void Typecasting()
{

/*
    | Code                         | Meaning                                        |
	| ---------------------------- | ---------------------------------------------- |
	| `(int)x`                     | convert float → int                            |
	| `(uint8_t *)&var`            | convert variable address to byte pointer       |
	| `(uint32_t *)0x40020000`     | treat hex address as pointer                   |
	| `(GPIO_TypeDef *)0x40020000` | treat address as peripheral register structure |
	| `(unsigned int)x`            | fix printf warnings                            |
	| `(void *)ptr`                | generic pointer for RTOS/HAL                   |

*/


	int a = 5;
	float b = (float)a;
	printf("%f\n", b);   // 5.000000

	float x = 5.99f;
	int y = (int)x;
	printf("%d\n", y);   // 5

	uint8_t v = 255;
	int8_t k = (int8_t)v;
	printf("%d\n", k);   // -1  (overflow, two’s complement)

	uint32_t value = 0x12345678;
	uint8_t *ptr   = (uint8_t *)&value;
	printf("%x\n", ptr[3]);   // prints lowest byte


	uint32_t value_x = 1234;
	void *p = &value_x;                  // p now points to value
	uint32_t *reg = (uint32_t *)p;       // cast void* → uint32_t*
	printf("%u\n",(unsigned int)*reg);   // Output: 1234


	uint32_t z = 100;
	printf("%u\n", (unsigned int)z);   // prevents format warning

	uint32_t data = 0xABCD;
	uint16_t low = (uint16_t)data;
	printf("%u\n", low);

	uint32_t pin = GPIOA_SIMPLE->IDR;    // Read PA0–PA15 input states
	printf("%u\n", (unsigned int)pin);

}
