#include "Protocols/LED/Led.h"



/* -------------------- GPIO INIT -------------------- */
void LED_GPIO_Init(void)
{
    // Enable GPIOD (LEDs)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // PD12–PD15 as output (LEDs)
    GPIOD->MODER &= ~((3U<<(12*2)) | (3U<<(13*2)) | (3U<<(14*2)) | (3U<<(15*2)));
    GPIOD->MODER |=  ((1U<<(12*2)) | (1U<<(13*2)) | (1U<<(14*2)) | (1U<<(15*2)));
}


void Red_LED_ON()
{
    GPIOD->ODR |= (1U<<12);  //GPIOD->ODR ^= (1U<<12);//Toggle
}

void Red_LED_OFF()
{
    // Toggle LEDs
    GPIOD->ODR &= ~(1U<<12);
}

void Blue_LED_ON()
{
    // Toggle LEDs
    GPIOD->ODR |= (1U<<13);
}

void Blue_LED_OFF()
{
    // Toggle LEDs
    GPIOD->ODR &= ~(1U<<13);
}


void Green_LED_ON()
{
    // Toggle LEDs
    GPIOD->ODR |= (1U<<14);
}

void Green_LED_OFF()
{
    // Toggle LEDs
    GPIOD->ODR &= ~(1U<<14);
}

void Orange_LED_ON()
{
    // Toggle LEDs
    GPIOD->ODR |= (1U<<15);
}

void Orange_LED_OFF()
{
    // Toggle LEDs
    GPIOD->ODR &= ~(1U<<15);
}





void Green_LED_TOGGLE()
{
    // Toggle LEDs
    GPIOD->ODR ^= (1U<<14);
}



