# STM32F4 Bare-Metal GPIO Input Example

This project demonstrates how to read a **GPIO input** from a button connected to **GPIOA Pin 0 (PA0)** on an **STM32F4** microcontroller. When the button is pressed, an LED connected to **GPIOA Pin 5 (PA5)** toggles, indicating the button press.

## Requirements

- **STM32F4** microcontroller (e.g., STM32F4 Discovery Board or Nucleo)
- **GCC for ARM** toolchain or any compatible C compiler for ARM Cortex-M4
- **ST-Link** or any compatible programmer/debugger for flashing
- **OpenOCD** or a similar tool for flashing the program onto the STM32F4
- **STM32F4 Standard Peripheral Library** or access to STM32 registers

## Overview

This program:
- Configures **GPIOA Pin 0 (PA0)** as input to read a button press.
- Configures **GPIOA Pin 5 (PA5)** as output to control an LED.
- Uses a **pull-up resistor** on **PA0** to read the state of the button.
- Toggles the LED connected to **PA5** when the button is pressed.

## Pin Configuration

- **GPIOA Pin 0 (PA0)**: Input pin connected to the button. The button is configured with a **pull-up resistor** to ensure the pin reads high (`1`) when the button is not pressed.
- **GPIOA Pin 5 (PA5)**: Output pin connected to an LED. The LED toggles on and off based on the state of the button connected to **PA0**.

## Program Flow

1. **Enable the Clock** for GPIOA to allow access to the GPIO registers.
2. **Configure PA0** as an input pin to read the button press.
3. **Enable the Pull-Up Resistor** on PA0, so the pin reads `1` when the button is not pressed.
4. **Continuously Read PA0** to check if the button is pressed.
5. **Toggle PA5 (LED)** when the button is pressed (PA0 reads `0`).

## Steps to Build and Flash

### Toolchain Setup

1. Install **GCC for ARM** toolchain:
   - For Ubuntu/Debian:
     ```bash
     sudo apt-get install gcc-arm-none-eabi
     ```
   - For Windows, use **GNU Arm Embedded Toolchain** (can be downloaded from ARM's official site).

2. Install **OpenOCD** for flashing (optional):
   - On Ubuntu/Debian:
     ```bash
     sudo apt-get install openocd
     ```

### Compile the Code

1. Save the provided C code in a file, e.g., `main.c`.
2. Compile the program with the following command:
   ```bash
   arm-none-eabi-gcc -o main.elf -mcpu=cortex-m4 -mthumb -nostartfiles -TSTM32F4.ld main.ciles -TSTM32F4.ld main.c