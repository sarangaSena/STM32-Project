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

    // Step 3: Configure the ADC for 12-bit resolution, scan mode, and single conversion
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR1 |= ADC_CR1_SCAN;   // Enable scan mode for multiple channels
    ADC1->CR2 &= ~ADC_CR2_CONT;  // Single conversion mode

    // Step 4: Select channels for conversion (PA0, PA1, PA2)
    ADC1->SQR3 = ADC_SQR3_SQ1_0 | ADC_SQR3_SQ2_1 | ADC_SQR3_SQ3_2; // Channel 0, 1, and 2
    ADC1->SQR2 = 0; // Clear previous sequence register settings
    ADC1->SQR1 &= ~ADC_SQR1_L; // Set the length to 3 channels (L = 2 channels + 1)

    // Step 5: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;

    // Optional delay for ADC stabilization
    for (int i = 0; i < 10000; i++) {}

    // Step 6: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;
}

void ADC_Read(void) {
    uint16_t adc_value1, adc_value2, adc_value3;

    // Wait for conversion to complete and read results
    while (!(ADC1->SR & ADC_SR_EOC)) {}
    adc_value1 = ADC1->DR; // Read the result of channel 0 (PA0)

    while (!(ADC1->SR & ADC_SR_EOC)) {}
    adc_value2 = ADC1->DR; // Read the result of channel 1 (PA1)

    while (!(ADC1->SR & ADC_SR_EOC)) {}
    adc_value3 = ADC1->DR; // Read the result of channel 2 (PA2)
}

int main(void) {
    // Initialize the ADC
    ADC_Init();

    // Read the ADC values for each channel
    ADC_Read();

    // Shutdown the ADC (optional)
    ADC1->CR2 &= ~ADC_CR2_ADON;

    while (1) {
        // Main loop
    }
}
