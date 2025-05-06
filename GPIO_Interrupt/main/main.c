/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

// Delay function for some basic timing control (optional)
void delay(uint32_t delay)
{
    while (delay--)
    {
        for (volatile int i = 0; i < 1000; i++);
    }
}

int main(void)
{
    // Step 1: Enable clock for GPIOA and SYSCFG
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;   // Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;  // Enable SYSCFG clock

    // Step 2: Set PA0 as input mode (00)
    GPIOA->MODER &= ~(GPIO_MODER_MODE0);  // PA0 as input

    // Step 3: Configure PA0 to trigger external interrupt (EXTI) on rising edge
    SYSCFG->CFGR1 |= SYSCFG_CFGR1_EXTISOURCE_PA0;  // Map PA0 to EXTI line 0
    EXTI->FTSR &= ~EXTI_FTSR_TR0;     // Disable falling edge trigger
    EXTI->RTSR |= EXTI_RTSR_TR0;      // Enable rising edge trigger
    EXTI->IMR |= EXTI_IMR_IM0;        // Enable interrupt for EXTI line 0

    // Step 4: Enable NVIC interrupt for EXTI Line 0 (PA0)
    NVIC_EnableIRQ(EXTI0_IRQn);       // Enable interrupt in NVIC for EXTI line 0

    // Step 5: Set PA5 as output mode (01) to control an LED
    GPIOA->MODER &= ~(GPIO_MODER_MODE5);  // Clear PA5 mode
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // Set PA5 as output mode

    // Main program loop
    while (1)
    {
        // Wait for interrupts to occur
    }

    return 0;  // This will never be reached
}

// EXTI0 interrupt handler (for EXTI line 0, which corresponds to PA0)
void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR0)  // Check if interrupt was triggered by PA0
    {
        EXTI->PR |= EXTI_PR_PR0;  // Clear the interrupt pending bit for EXTI Line 0

        // Toggle the LED on PA5
        GPIOA->ODR ^= GPIO_ODR_OD5;  // Toggle PA5 (LED)
    }
}