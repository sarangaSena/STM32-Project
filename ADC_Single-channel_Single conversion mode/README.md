# STM32F4 ADC Single-Channel, Single Conversion Mode

This project demonstrates how to use the Analog-to-Digital Converter (ADC) on the STM32F4 microcontroller in **single-channel, single conversion mode**. The ADC is configured to read data from a single analog pin, convert it to a digital value, and return the result.

## Prerequisites

Before running the project, ensure that you have the following:
- STM32F4 microcontroller (e.g., STM32F407).
- STM32CubeIDE or any other compatible IDE to compile and flash the code.
- A suitable external analog signal for the ADC pin (e.g., a potentiometer connected to the ADC input pin).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 (ADC1 Channel 0).
- **GPIO Configuration**: PA0 configured as an analog input pin.
- **Voltage Source**: Provide an analog signal to PA0 for testing.

## Project Overview

The main functionality of this project includes:
- **ADC Initialization**: Enabling the ADC clock, configuring the ADC pin as an analog input, and setting up the ADC for a single conversion on one channel.
- **ADC Conversion**: Initiating a conversion, waiting for it to complete, and reading the result from the ADC data register.
- **ADC Shutdown**: Optionally powering down the ADC to conserve power after the conversion.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
The clock for the ADC peripheral is enabled via the RCC (Reset and Clock Control) register.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;