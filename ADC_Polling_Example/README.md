# STM32F4 ADC Polling Example

This project demonstrates how to read an analog value from the **PA0** pin using **ADC polling** on the STM32F4 microcontroller. The ADC will be configured for **single conversion mode** and the result will be read via polling.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A valid analog signal connected to **PA0**.

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 (ADC1 Channel 0).
- **GPIO Configuration**: PA0 configured as an analog input pin.

## Project Overview

This project:
- Configures the **ADC** in **single conversion mode**.
- Continuously polls the **EOC** (End of Conversion) flag to determine when the conversion is complete.
- Reads the result from the **ADC Data Register**.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
Enable the ADC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
