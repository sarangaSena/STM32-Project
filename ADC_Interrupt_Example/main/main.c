/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

void ADC_Init(void) {
    // Step 1: Enable the ADC clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Step 2: Configure PA0 as analog input
    GPIOA->MODER |= GPIO_MODER_MODE0;  // Set PA0 to analog mode

    // Step 3: Configure the ADC for 12-bit resolution, single conversion
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->SQR3 = 0;  // Select channel 0 (PA0) for conversion

    // Step 4: Enable the ADC interrupt (EOCIE flag)
    ADC1->CR1 |= ADC_CR1_EOCIE;  // Enable end-of-conversion interrupt

    // Step 5: Enable ADC interrupt in NVIC
    NVIC_EnableIRQ(ADC1_2_IRQn);  // Enable interrupt for ADC1

    // Step 6: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional: Delay for ADC stabilization
    for (int i = 0; i < 10000; i++) {}

    // Step 7: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start conversion
}

// ADC1 interrupt handler
void ADC1_2_IRQHandler(void) {
    if (ADC1->SR & ADC_SR_EOC) {
        // Read the ADC result from the Data Register
        uint16_t adc_value = ADC1->DR;

        // Process the adc_value (e.g., store it, send it over UART, etc.)
        // For now, we can just use it as needed

        // Clear the EOC flag
        ADC1->SR &= ~ADC_SR_EOC;  // Clear the EOC flag
    }
}

int main(void) {
    // Initialize the ADC
    ADC_Init();

    // Main loop
    while (1) {
        // The MCU can perform other tasks while waiting for ADC interrupt
        // You can do other processing here while ADC conversion is happening
    }
}
