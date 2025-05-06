/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

// Delay function to create a delay for toggling the LED
void delay(uint32_t delay)
{
    while (delay--)
    {
        for (volatile int i = 0; i < 1000; i++);  // Simple busy-wait loop for delay
    }
}

int main(void)
{
    // Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Set bit for GPIOA in AHB1ENR register to enable clock for GPIOA

    // Set pin PA5 as output mode (01)
    GPIOA->MODER &= ~(GPIO_MODER_MODE5);  // Clear the mode bits for PA5
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // Set mode to output (01)

    // Set the output type to push-pull (0) - Default
    GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);  // Set pin PA5 as push-pull output

    // Set the output speed to high-speed (11)
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5);  // Clear speed bits
    GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5_1 | GPIO_OSPEEDR_OSPEED5_0;  // Set to high speed

    // Disable pull-up/pull-down resistors (00)
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);  // Disable pull-up and pull-down resistors for PA5

    // Main loop
    while (1)
    {
        GPIOA->ODR ^= GPIO_ODR_OD5;  // Toggle the output of PA5 (turn the LED on/off)
        delay(1000);  // Wait for a while
    }

    return 0;  // Never reached
}