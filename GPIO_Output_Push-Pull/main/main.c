/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

// Simple delay function (for visual effects)
void delay(uint32_t delay)
{
    while (delay--)
    {
        for (volatile int i = 0; i < 1000; i++);
    }
}

int main(void)
{
    // Step 1: Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable GPIOA clock

    // Step 2: Set PA5 as output mode (01)
    GPIOA->MODER &= ~(GPIO_MODER_MODE5);  // Clear the mode bits for PA5
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // Set PA5 as output mode (01)

    // Step 3: Set PA5 to push-pull output (OTYPER bit = 0 for push-pull)
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);  // Set PA5 to push-pull

    // Step 4: Set PA5 output speed to high
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5_0 | GPIO_OSPEEDR_OSPEED5_1;  // High speed

    // Step 5: Disable pull-up/pull-down resistors for PA5
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);   // No pull-up, no pull-down

    while (1)
    {
        // Step 6: Set PA5 to low (turn off the LED)
        GPIOA->ODR &= ~GPIO_ODR_OD5;  // PA5 = 0 (low)
        delay(1000);  // Delay for visual effect

        // Step 7: Set PA5 to high (turn on the LED)
        GPIOA->ODR |= GPIO_ODR_OD5;   // PA5 = 1 (high)
        delay(1000);  // Delay for visual effect
    }

    return 0;  // This will never be reached
}