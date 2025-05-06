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

    // Step 2: Configure ADC for temperature sensor (Channel 16)
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->SQR3 = 16;  // Select channel 16 (Temperature sensor)
    
    // Step 3: Enable continuous conversion mode
    ADC1->CR2 |= ADC_CR2_CONT;   // Continuous conversion mode

    // Step 4: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional delay for ADC to stabilize
    for (int i = 0; i < 10000; i++) {}

    // Step 5: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start conversion
}

float ADC_Read_Temperature(void) {
    uint16_t adc_value;
    float temperature;

    // Continuously read the ADC values from the temperature sensor channel
    while (1) {
        // Wait for conversion to complete
        while (!(ADC1->SR & ADC_SR_EOC)) {}

        // Read the result from the ADC data register
        adc_value = ADC1->DR;  // Temperature sensor value

        // Convert ADC value to temperature (in Celsius)
        temperature = ((adc_value / 4095.0) * 3.3 - 0.76) * 100;

        // Return the temperature value
        return temperature;
    }
}

int main(void) {
    float temperature;

    // Initialize the ADC
    ADC_Init();

    // Read the temperature value from the internal temperature sensor
    temperature = ADC_Read_Temperature();

    // Optionally, stop the ADC conversion
    ADC1->CR2 &= ~ADC_CR2_ADON;  // Disable the ADC

    while (1) {
        // Main loop
    }
}
