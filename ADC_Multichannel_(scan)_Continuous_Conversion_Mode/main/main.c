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

    // Step 2: Configure PA0, PA1, PA2 as analog input pins
    GPIOA->MODER |= GPIO_MODER_MODE0 | GPIO_MODER_MODE1 | GPIO_MODER_MODE2;

    // Step 3: Configure the ADC for 12-bit resolution, scan mode, and continuous conversion
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR1 |= ADC_CR1_SCAN;   // Enable scan mode for multiple channels
    ADC1->CR2 |= ADC_CR2_CONT;   // Continuous conversion mode
    ADC1->SQR3 = ADC_SQR3_SQ1_0 | ADC_SQR3_SQ2_1 | ADC_SQR3_SQ3_2; // Set channels 0 (PA0), 1 (PA1), and 2 (PA2)
    ADC1->SQR2 = 0;  // Clear previous sequence register settings
    ADC1->SQR1 &= ~ADC_SQR1_L; // Set the length to 3 channels (L = 2 channels + 1)

    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional delay for ADC to stabilize
    for (int i = 0; i < 10000; i++) {}

    // Step 5: Start the conversion (scan mode)
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start the conversion
}

void ADC_Read(void) {
    uint16_t adc_value1, adc_value2, adc_value3;

    // Continuously read the ADC values
    while (1) {
        // Wait for conversion to complete and read results
        while (!(ADC1->SR & ADC_SR_EOC)) {}
        adc_value1 = ADC1->DR; // Result of channel 0 (PA0)

        while (!(ADC1->SR & ADC_SR_EOC)) {}
        adc_value2 = ADC1->DR; // Result of channel 1 (PA1)

        while (!(ADC1->SR & ADC_SR_EOC)) {}
        adc_value3 = ADC1->DR; // Result of channel 2 (PA2)

        // Use adc_value1, adc_value2, adc_value3 for your application
    }
}

int main(void) {
    // Initialize the ADC
    ADC_Init();

    // Read the ADC values continuously
    ADC_Read();

    // Optional: Stop the ADC conversion (if needed)
    ADC1->CR2 &= ~ADC_CR2_ADON; // Disable the ADC

    while (1) {
        // Main loop
    }
}