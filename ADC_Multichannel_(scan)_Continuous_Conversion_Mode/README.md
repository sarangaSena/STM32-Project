# STM32F4 ADC Multichannel (Scan) Continuous Conversion Mode

This project demonstrates how to use the **Analog-to-Digital Converter (ADC)** on the **STM32F4 microcontroller** in **multichannel scan** and **continuous conversion mode**. This mode continuously converts multiple channels in sequence, ideal for applications requiring real-time monitoring of multiple analog inputs.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- Multiple valid analog input signals connected to the ADC input pins (e.g., sensors).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Inputs**: PA0 (ADC1 Channel 0), PA1 (ADC1 Channel 1), PA2 (ADC1 Channel 2).
- **GPIO Configuration**: PA0, PA1, and PA2 configured as analog input pins.
- **Voltage Source**: Provide analog signals to PA0, PA1, and PA2 for testing.

## Project Overview

In this project:
- The **ADC** is configured for **multichannel scan** and **continuous conversion mode**.
- The ADC continuously samples **multiple channels** in sequence.
- The conversion results are read continuously and can be used for processing, display, or other applications.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
The ADC clock is enabled using the RCC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;