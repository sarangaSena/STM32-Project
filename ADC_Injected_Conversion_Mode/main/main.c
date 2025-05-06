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

    // Step 2: Configure PA0 and PA3 as analog input pins
    GPIOA->MODER |= GPIO_MODER_MODE0 | GPIO_MODER_MODE3;  // Set to analog mode

    // Step 3: Configure the ADC for 12-bit resolution and injected conversion mode
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->CR1 |= ADC_CR1_JAUTO;  // Injected auto mode (optional)
    
    // Select the injected channel (e.g., channel 3 for PA3)
    ADC1->JSQR = ADC_JSQR_JSQ1_2;  // Select channel 3 (PA3) for injected conversion
    
    // Configure external trigger for injected conversions
    ADC1->CR2 |= ADC_CR2_JEXTTRIG; // Enable external trigger for injected conversions

    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;  // Power on the ADC

    // Optional delay for ADC stabilization
    for (int i = 0; i < 10000; i++) {}

    // Step 5: Start the regular conversion (if needed)
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start the regular conversion (optional)
    
    // Step 6: Start the injected conversion (software trigger)
    ADC1->CR2 |= ADC_CR2_JSWSTART;  // Software trigger for injected conversion
}

uint16_t ADC_Read_Injected(void) {
    uint16_t injected_value;

    // Wait for injected conversion to complete
    while (!(ADC1->SR & ADC_SR_JEOC)) {}

    // Read the injected result from the injected data register
    injected_value = ADC1->JDR1;  // Injected data register 1 for channel 3

    return injected_value;
}

int main(void) {
    uint16_t injected_value;

    // Initialize the ADC
    ADC_Init();

    // Read the injected ADC value
    injected_value = ADC_Read_Injected();

    // Optional: Stop the ADC conversion
    ADC1->CR2 &= ~ADC_CR2_ADON;  // Disable the ADC (optional)

    while (1) {
        // Main loop
    }
}