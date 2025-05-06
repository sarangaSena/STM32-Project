# STM32F4 GPIO Interrupt Example (Button Press to Toggle LED)

This project demonstrates how to configure a **GPIO interrupt** on the **STM32F4** microcontroller. In this example, **PA0** (a button) is used as the interrupt source, and **PA5** (an LED) is toggled whenever the button is pressed.

The STM32F4 microcontroller is a powerful ARM Cortex-M4-based microcontroller. This project uses **bare-metal programming** to handle GPIO interrupts without relying on an operating system, giving you full control over the hardware.

## Features

- **GPIO Input (PA0)**: Configured to read a button press.
- **GPIO Output (PA5)**: Controls an LED that toggles on a button press.
- **GPIO Interrupt**: The interrupt is triggered on a **rising edge** (button press).
- **Interrupt Service Routine (ISR)**: The ISR is executed when the interrupt is triggered, toggling the LED.

## Hardware Requirements

- **STM32F4 Microcontroller** (e.g., STM32F407 or STM32F401)
- **Button**: Connected to **PA0**.
- **LED**: Connected to **PA5** (or any GPIO pin configured as output).

## Software Requirements

- **GCC for ARM** toolchain or an IDE like **STM32CubeIDE**.
- **OpenOCD** or **ST-Link** for flashing the firmware to the STM32F4.
- A basic understanding of STM32F4 microcontroller peripherals and interrupt handling.

