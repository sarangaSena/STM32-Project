# STM32F4 ADC Internal Temperature Sensor

This project demonstrates how to use the **internal temperature sensor** on the **STM32F4 microcontroller** to continuously monitor the temperature using **ADC in continuous conversion mode**. This allows real-time temperature measurement without requiring external triggers.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: Internal **Temperature Sensor** (Channel 16).
- **GPIO Configuration**: No external GPIO configuration is needed for the temperature sensor.
- **Voltage Source**: The temperature sensor is internally powered by the microcontroller.

## Project Overview

This project:
- Configures the **ADC** in **continuous conversion mode** to read the **internal temperature sensor**.
- Continuously measures the internal temperature of the STM32F4.
- Converts the ADC value into degrees Celsius.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
The ADC clock is enabled using the RCC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
