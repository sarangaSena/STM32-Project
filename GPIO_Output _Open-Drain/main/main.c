/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

// Delay function for visual effect (optional)
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

    // Step 3: Set PA5 to open-drain output (OTYPER bit = 1 for open-drain)
    GPIOA->OTYPER |= GPIO_OTYPER_OT_5;  // Set PA5 to open-drain

    // Step 4: Set PA5 output speed to high
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5_0 | GPIO_OSPEEDR_OSPEED5_1;  // High speed

    // Step 5: Enable internal pull-up resistor for PA5
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);   // Clear previous settings
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD5_0;    // Enable pull-up resistor for PA5

    while (1)
    {
        // Step 6: Set PA5 to low (pull the line to ground)
        GPIOA->ODR &= ~GPIO_ODR_OD5;  // PA5 = 0 (low)
        delay(1000);  // Delay for visual effect

        // Step 7: Set PA5 to high-impedance (let the pull-up resistor bring the line high)
        GPIOA->ODR |= GPIO_ODR_OD5;   // PA5 = 1 (high impedance)
        delay(1000);  // Delay for visual effect
    }

    return 0;  // This will never be reached
}