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

    // Step 3: Configure the ADC for 12-bit resolution, single conversion mode
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR2 &= ~ADC_CR2_CONT;  // Single conversion mode
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start conversion when initiated by software
}

uint16_t ADC_Read(void) {
    uint16_t adc_value;

    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Step 5: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start the conversion

    // Step 6: Poll for the end of conversion (EOC flag)
    while (!(ADC1->SR & ADC_SR_EOC)) {
        // Wait until conversion is complete
    }

    // Step 7: Read the result from the ADC data register
    adc_value = ADC1->DR;  // Get the ADC result

    // Optional: Disable the ADC (power off the ADC to save energy)
    ADC1->CR2 &= ~ADC_CR2_ADON;  // Power off the ADC

    return adc_value;
}

int main(void) {
    uint16_t adc_value;

    // Initialize the ADC
    ADC_Init();

    // Read the ADC value from PA0
    adc_value = ADC_Read();

    // Use adc_value for your application (e.g., display it or process it)
    while (1) {
        // Main loop
    }
}
