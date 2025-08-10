# ESP32 Dual Motor Control using MCPWM Driver

This project demonstrates controlling two DC motors independently using ESP32's new MCPWM driver in ESP-IDF. Each motor has its own modular driver files (`driver.c` and `driver.h`) for easy integration and maintenance.

## Features

- Independent control of two DC motors using MCPWM hardware
- Modular driver design for each motor (`driver.c` and `driver.h`)
- GPIO 2 LED status indicator for debugging and feedback
- Uses ESP-IDF new MCPWM API for better performance and reliability

## Hardware Requirements

- ESP32 development board
- Two DC motors connected to motor driver module
- Motor driver modules (e.g., L298N or similar) connected to MCPWM output pins 
- LED connected to GPIO 2 for status indication
