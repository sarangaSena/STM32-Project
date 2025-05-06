# STM32F4 ADC Single-Channel Continuous Conversion Mode

This project demonstrates how to use the **Analog-to-Digital Converter (ADC)** on the **STM32F4 microcontroller** in **single-channel continuous conversion mode**. This mode continuously converts a signal from a single input channel.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A valid analog input signal connected to the ADC input pin (e.g., a potentiometer or sensor).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 (ADC1 Channel 0).
- **GPIO Configuration**: PA0 configured as an analog input pin.
- **Voltage Source**: Provide an analog signal to PA0 for testing.

## Project Overview

In this project:
- The **ADC** is configured for **single-channel** (PA0) and **continuous conversion** mode.
- The ADC continuously reads the input signal and provides the converted digital value.
- This mode is suitable for continuous analog signal monitoring applications.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
The ADC clock is enabled using the RCC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;