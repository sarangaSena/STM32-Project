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

    // Step 2: Configure ADC for continuous conversion and VBAT channel
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR2 |= ADC_CR2_CONT;   // Continuous conversion mode

    // Step 3: Select VBAT (channel 17) for ADC conversion
    ADC1->SQR3 = 17; // Select channel 17 (VBAT)
    
    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional delay for stabilization
    for (int i = 0; i < 10000; i++) {}

    // Step 5: Start the ADC conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start conversion
}

uint16_t ADC_Read(void) {
    uint16_t adc_value;

    // Continuously read the ADC values from VBAT channel
    while (1) {
        // Wait for conversion to complete
        while (!(ADC1->SR & ADC_SR_EOC)) {}

        // Read the result from the ADC data register
        adc_value = ADC1->DR; // Battery voltage value

        // Return the value
        return adc_value;
    }
}

int main(void) {
    uint16_t battery_value;

    // Initialize the ADC
    ADC_Init();

    // Continuously read the battery voltage value
    battery_value = ADC_Read();

    // Optional: Stop the ADC conversion
    ADC1->CR2 &= ~ADC_CR2_ADON;  // Disable the ADC

    while (1) {
        // Main loop
    }
}