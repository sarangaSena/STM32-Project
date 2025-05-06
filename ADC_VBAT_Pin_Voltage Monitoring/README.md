# STM32F4 ADC Battery Voltage Monitoring in Continuous Conversion Mode

This project demonstrates how to use the **Analog-to-Digital Converter (ADC)** on the **STM32F4 microcontroller** to continuously monitor the **battery voltage (VBAT)** using **continuous conversion mode**. This mode enables real-time monitoring of the battery voltage without the need for external triggers.

## Prerequisites

Before running this project, ensure you have:
- **STM32F4** series microcontroller (e.g., STM32F407).
- **STM32CubeIDE** or any compatible IDE to compile and flash the code.
- A battery source connected to the **VBAT** pin for measurement.

## Hardware Setup

- **Microcontroller**: STM32F4 series (e.g., STM32F407).
- **Analog Input**: Internal **VBAT** pin used for measuring battery voltage.
- **GPIO Configuration**: **VBAT** is internally connected to the ADC, no external GPIO configuration needed.
- **Voltage Source**: The **VBAT** pin is connected to the battery source.

## Project Overview

This project:
- Configures the **ADC** in **continuous conversion mode** to sample the **VBAT** channel.
- Continuously reads the battery voltage using the ADC in 12-bit resolution.
- Provides a real-time view of the battery voltage.

## Steps to Run the Code

### 1. **Enable the ADC Clock**
Enable the ADC peripheral clock.

```c
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;