# STM32F4 Open-Drain Output Example

This project demonstrates how to configure an **open-drain output** on the **STM32F4** microcontroller using **bare-metal programming in C**. The example shows how to set up **PA5** as an open-drain output, allowing the pin to pull low when active and letting an external **pull-up resistor** bring the line high when inactive.

## Features

- **GPIO Configuration**: Configures **PA5** as an open-drain output.
- **External Pull-up Resistor**: Uses an external pull-up resistor to bring the line high when not pulled low.
- **LED Control**: Toggles an LED connected to **PA5**, with **PA5** configured as an open-drain output.
- **Bare-Metal Programming**: No operating system is used, allowing direct control of the hardware.

## Hardware Requirements

- **STM32F4 Microcontroller** (e.g., STM32F407 or STM32F401).
- **LED** connected to **PA5** (or any other GPIO pin configured as output).
- **Button** (optional for external control).
- **Pull-up Resistor** (connected to **PA5**, if you're using the open-drain output).

## Software Requirements

- **GCC for ARM** toolchain or **STM32CubeIDE**.
- **OpenOCD** or **ST-Link** for flashing the firmware to the STM32F4.
- Basic understanding of STM32F4 GPIO and interrupt handling.