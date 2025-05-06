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
    GPIOA->MODER |= GPIO_MODER_MODE0; // Set PA0 to analog mode

    // Step 3: Configure the ADC for 12-bit resolution, single channel, and continuous conversion
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR1 &= ~ADC_CR1_SCAN;  // Single channel mode (not scan mode)
    ADC1->CR2 |= ADC_CR2_CONT;   // Continuous conversion mode
    ADC1->SQR3 = ADC_SQR3_SQ1_0; // Select channel 0 (PA0) for conversion

    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional delay for ADC to stabilize
    for (int i = 0; i < 10000; i++) {}

    // Step 5: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start the conversion
}

uint16_t ADC_Read(void) {
    // Wait for conversion to complete
    while (!(ADC1->SR & ADC_SR_EOC)) {}

    // Read the result from the ADC data register
    return (uint16_t)ADC1->DR;
}

int main(void) {
    uint16_t adc_value;

    // Initialize the ADC
    ADC_Init();

    // Continuously read ADC values
    while (1) {
        adc_value = ADC_Read();
        // Process or use adc_value
        // For example: send it over UART, use it in control loops, etc.
    }

    // Stop the ADC conversion (optional)
    ADC1->CR2 &= ~ADC_CR2_ADON; // Disable the ADC (optional)

    while (1) {
        // Main loop
    }
}