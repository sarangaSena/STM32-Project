# STM32F4 ADC Interrupt Example

This project demonstrates how to use **ADC interrupts** on the **STM32F4 microcontroller** to read an analog input (PA0) and trigger an interrupt when the conversion is complete. This allows the MCU to perform other tasks while waiting for the ADC conversion to complete.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A valid analog signal connected to **PA0** (ADC1 Channel 0).

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: PA0 (ADC1 Channel 0).
- **GPIO Configuration**: PA0 configured as an analog input pin.

## Project Overview

This project:
- Configures the **ADC** in **single conversion mode**.
- Enables **ADC interrupt** on **end-of-conversion (EOC)** to automatically process the conversion result.
- Uses the **NVIC** to manage the interrupt.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
Enable the ADC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
