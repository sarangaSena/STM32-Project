# STM32F4 ADC Injected Conversion Mode

This project demonstrates how to use the **Analog-to-Digital Converter (ADC)** on the **STM32F4** microcontroller in **Injected Conversion Mode**. This mode allows you to trigger ADC conversions of specific channels independently from the regular conversion process.

## Prerequisites

Before running the project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A valid analog input signal connected to the ADC input pin (e.g., a sensor connected to PA3).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 for the regular group, PA3 for the injected group.
- **GPIO Configuration**: PA0 and PA3 configured as analog input pins.
- **Voltage Source**: Provide analog signals to PA3 for testing.

## Project Overview

In this project:
- The **ADC** is configured for **Injected Conversion Mode**.
- A specific channel (e.g., PA3) is sampled independently from the regular conversion group.
- The injected conversion can be triggered by software or external events.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
The ADC clock is enabled using the RCC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;