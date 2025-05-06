/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

void ADC_Init(void) {
    // Enable the ADC clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Configure PA0 as analog input
    GPIOA->MODER |= GPIO_MODER_MODE0;

    // Configure the ADC
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR1 &= ~ADC_CR1_SCAN;  // Single-channel mode
    ADC1->CR2 &= ~ADC_CR2_CONT;  // Single conversion mode
    ADC1->SQR3 = ADC_SQR3_SQ1_0; // Select channel 0 (PA0)
    ADC1->SMPR2 |= ADC_SMPR2_SMP0; // 3 cycles for channel 0

    // Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;

    // Optional delay for ADC to stabilize
    for (int i = 0; i < 10000; i++) {}

    // Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;
}

uint16_t ADC_Read(void) {
    // Wait for conversion to complete
    while (!(ADC1->SR & ADC_SR_EOC)) {}

    // Read the result
    return (uint16_t)ADC1->DR;
}

int main(void) {
    uint16_t adc_value;

    // Initialize the ADC
    ADC_Init();

    // Read the ADC value
    adc_value = ADC_Read();

    // Optionally use adc_value for your application

    // Shutdown ADC (optional)
    ADC1->CR2 &= ~ADC_CR2_ADON;

    while (1) {
        // Main loop
    }
}