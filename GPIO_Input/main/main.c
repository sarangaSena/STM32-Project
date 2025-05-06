/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

// Delay function to create a simple delay
void delay(uint32_t delay)
{
    while (delay--)
    {
        for (volatile int i = 0; i < 1000; i++);  // Simple busy-wait loop for delay
    }
}

int main(void)
{
    // Step 1: Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Set bit for GPIOA in AHB1ENR register to enable clock for GPIOA

    // Step 2: Set pin PA0 as input mode (00)
    GPIOA->MODER &= ~(GPIO_MODER_MODE0);  // Clear the mode bits for PA0 (input mode)
    
    // Step 3: Configure pull-up resistor for PA0 (so the button reads 1 when not pressed)
    GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD0);  // Clear previous settings
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_0;   // Set pull-up resistor (01)

    // Step 4: Main loop to continuously read the input from PA0
    while (1)
    {
        // Step 5: Read the input value of PA0
        uint32_t pin_value = (GPIOA->IDR & GPIO_IDR_ID0) ? 1 : 0;  // Check if PA0 is high or low

        // If the button is pressed, the value of PA0 will be 0 due to the pull-up resistor
        if (pin_value == 0)
        {
            // The button is pressed (PA0 is low)
            // You can toggle an LED, or execute any code here
            // For now, let's just toggle PA5 for visualization (LED Blinking)
            GPIOA->ODR ^= GPIO_ODR_OD5;  // Toggle the LED connected to PA5
            delay(1000);  // Delay for visual effect
        }
    }

    return 0;  // Never reached
}