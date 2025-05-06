
# STM32F4 ADC with DMA Example

This project demonstrates how to use **Direct Memory Access (DMA)** with the **Analog-to-Digital Converter (ADC)** on the **STM32F4** microcontroller. By using DMA, we can efficiently transfer ADC data directly into memory without involving the CPU, which helps in real-time data logging or signal processing applications.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A valid analog signal connected to **PA0** (ADC1 Channel 0) for testing.

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: **PA0 (ADC1 Channel 0)** for analog data input.
- **GPIO Configuration**: PA0 configured as an analog input pin.
- **DMA**: Configured to transfer data from ADC to memory.

## Project Overview

In this project:
- The **ADC** is configured to read analog data from **PA0** (ADC1 Channel 0).
- **DMA** is used to automatically transfer the ADC result to a memory location without CPU intervention.
- The ADC is set up to operate in **single conversion mode**.
- An interrupt is triggered when the DMA transfer is complete, allowing further processing of the ADC result.

## Steps to Run the Code

### 1. **Enable the ADC and DMA Clocks**
The ADC and DMA clocks are enabled via the RCC register.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
