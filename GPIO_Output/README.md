# STM32F4 Bare-Metal GPIO Toggle Example

This is a simple **bare-metal** program for the STM32F4 series microcontroller, which toggles an LED connected to **GPIOA Pin 5** every second. The program demonstrates basic GPIO configuration and how to control hardware without the use of an operating system.

## Requirements

- **STM32F4** microcontroller (e.g., STM32F4 Discovery Board or Nucleo)
- **GCC for ARM** toolchain or any compatible C compiler for ARM Cortex-M4
- **ST-Link** or any compatible programmer/debugger for flashing
- **OpenOCD** or a similar tool for flashing the program onto the STM32F4
- **STM32F4 Standard Peripheral Library** or access to STM32 registers

## Overview

This program:

- Configures **GPIOA Pin 5** as a general-purpose output.
- Enables the clock for GPIOA.
- Toggles the output on **PA5**, controlling an external LED.
- Implements a simple **delay** using a busy-wait loop to achieve a visible LED blink.

## Pin Configuration

- **GPIOA Pin 5 (PA5)** is configured as an **output** to control the LED.
- The output type is set to **push-pull** (default).
- The speed is set to **high-speed** for faster transitions.
- **No pull-up/pull-down resistors** are used.

## Program Flow

1. **Enable the Clock** for GPIOA.
2. **Configure PA5 as Output**.
3. **Toggle PA5** output on and off in an infinite loop.
4. **Delay** between toggles to make the LED blink visible.

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
   arm-none-eabi-gcc -o main.elf -mcpu=cortex-m4 -mthumb -nostartfiles -TSTM32F4.ld main.c