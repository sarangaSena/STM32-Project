# STM32F4 ADC Multichannel (Scan), Single Conversion Mode

This project demonstrates how to use the **Analog-to-Digital Converter (ADC)** in **multichannel (scan), single conversion mode** on the **STM32F4** microcontroller. The ADC reads from multiple channels sequentially and performs one conversion cycle for each channel in a non-continuous mode.

## Prerequisites

Before running the project, ensure that you have the following:
- **STM32F4 microcontroller** (e.g., STM32F407).
- **STM32CubeIDE** or any other compatible IDE to compile and flash the code.
- A suitable analog signal provided to the ADC input pins (e.g., a potentiometer or sensors).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 (ADC1 Channel 0), PA1 (ADC1 Channel 1), PA2 (ADC1 Channel 2).
- **GPIO Configuration**: PA0, PA1, and PA2 are configured as analog input pins.
- **Voltage Source**: Provide analog signals to PA0, PA1, and PA2 for testing.

## Project Overview

This project configures the STM32F4 ADC for **multichannel scan mode** and **single conversion mode**, where:
- The ADC converts data from multiple channels in sequence.
- The ADC operates in **single conversion mode**, where each conversion is triggered individually for each channel.
- After all conversions are completed, the results are read sequentially.

## Steps to Run the Code

### 1. **Enable the ADC Clock**

First, enable the clock for the ADC peripheral:

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;