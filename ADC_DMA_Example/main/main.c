/*
 * main.c
 *
 * Created: 5/6/2024 12:51:35 PM
 * Author : Saranga Senarathna
 */ 

#include "stm32f4xx.h"

uint16_t adc_value;  // Memory location for ADC result

void ADC_Init(void) {
    // Step 1: Enable the ADC clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Step 2: Enable the DMA1 clock
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;

    // Step 3: Configure PA0 as analog input
    GPIOA->MODER |= GPIO_MODER_MODE0;  // Set PA0 to analog mode

    // Step 4: Configure DMA1 for ADC1
    DMA1_Stream0->CR &= ~DMA_SxCR_EN;  // Disable DMA Stream before configuration
    DMA1_Stream0->CR |= DMA_SxCR_PL_0;  // Set DMA priority level to medium (optional)
    DMA1_Stream0->CR |= DMA_SxCR_MSIZE_0 | DMA_SxCR_PSIZE_0; // Memory and peripheral size 8 bits
    DMA1_Stream0->CR |= DMA_SxCR_MINC;  // Memory increment mode
    DMA1_Stream0->CR &= ~DMA_SxCR_PINC; // Peripheral address does not increment
    DMA1_Stream0->CR |= DMA_SxCR_TCIE;  // Enable transfer complete interrupt (optional)
    DMA1_Stream0->NDTR = 1;  // Number of data items to transfer (1 for a single channel)
    DMA1_Stream0->PAR = (uint32_t)&ADC1->DR;  // Peripheral address (ADC1 data register)
    DMA1_Stream0->M0AR = (uint32_t)&adc_value;  // Memory address

    // Step 5: Configure the ADC for 12-bit resolution, single conversion mode
    ADC1->CR1 |= ADC_CR1_RES_1;  // 12-bit resolution
    ADC1->SQR3 = 0;  // Select channel 0 (PA0) for conversion
    ADC1->CR2 |= ADC_CR2_DMA;    // Enable DMA for ADC1

    // Step 6: Power on the ADC
    ADC1->CR2 |= ADC_CR2_ADON;   // Power on the ADC

    // Optional: Delay for ADC stabilization
    for (int i = 0; i < 10000; i++) {}

    // Step 7: Start the conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start conversion
}

// DMA Interrupt Handler
void DMA1_Stream0_IRQHandler(void) {
    if (DMA1_Stream0->CR & DMA_SxCR_TCIF) {
        // Clear the interrupt flag
        DMA1_Stream0->CR &= ~DMA_SxCR_TCIF;
        
        // Process the adc_value here
        // For example, send via UART or store in memory
    }
}

int main(void) {
    // Initialize the ADC
    ADC_Init();

    // Main loop
    while (1) {
        // Wait for DMA interrupt to process the ADC result
        // The system can perform other tasks while waiting
    }
}
