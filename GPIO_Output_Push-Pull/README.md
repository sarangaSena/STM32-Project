# STM32F4 Push-Pull Output Example

This project demonstrates how to configure a **GPIO pin (PA5)** as a **push-pull output** on an **STM32F4** microcontroller using **bare-metal programming in C**. The example toggles an LED connected to **PA5**, with **PA5** configured as a push-pull output. The program drives the pin high and low to control the LED.

## Features

- **GPIO Configuration**: Configures **PA5** as a push-pull output.
- **LED Control**: Toggles an LED connected to **PA5**.
- **Bare-Metal Programming**: No operating system is used, providing direct control over the hardware.

## Hardware Requirements

- **STM32F4 Microcontroller** (e.g., STM32F407 or STM32F401).
- **LED** connected to **PA5** (or any other GPIO pin configured as output).
- **Resistor** (optional for limiting current to the LED).

## Software Requirements

- **GCC for ARM** toolchain or **STM32CubeIDE**.
- **OpenOCD** or **ST-Link** for flashing the firmware to the STM32F4.
- Basic understanding of STM32F4 GPIO and microcontroller peripherals.