# Smart Home Automation Using ATmega32

![Project Image](C:\Users\Mohamed\OneDrive\Pictures\Screenshots)

## Project Overview
This project involves designing and implementing a smart home automation system using the **ATmega32** microcontroller. It automates the control of lighting, fan speed, and fire detection based on environmental conditions, utilizing various sensors and an LCD for real-time feedback.

## Features

### 🔦 Automatic Lighting Control:
- The system uses an **LDR** (Light Dependent Resistor) to detect ambient light intensity and controls three LEDs based on predefined thresholds:
  - **Intensity < 15%**: All LEDs (Red, Green, Blue) ON.
  - **Intensity 16–50%**: Red and Green LEDs ON.
  - **Intensity 51–70%**: Only Red LED ON.
  - **Intensity > 70%**: All LEDs OFF.

### 🌡️ Automatic Fan Speed Control:
- A **LM35** temperature sensor adjusts the fan speed using **PWM** based on room temperature:
  - **Temperature ≥ 40°C**: Fan ON at 100% speed.
  - **Temperature ≥ 35°C and < 40°C**: Fan ON at 75% speed.
  - **Temperature ≥ 30°C and < 35°C**: Fan ON at 50% speed.
  - **Temperature ≥ 25°C and < 30°C**: Fan ON at 25% speed.
  - **Temperature < 25°C**: Fan OFF.

### 🔥 Fire Detection and Alert:
- A **flame sensor** detects fire and triggers an alarm, displaying **"Critical alert!"** on the LCD until the flame is no longer detected.
- Activates a buzzer for immediate alert.

### 🖥️ LCD Display:
- Provides real-time feedback on system status:
  - **First Row**: Displays "FAN is ON" or "FAN is OFF."
  - **Second Row**: Displays temperature (**"Temp= xx°C"**) and light intensity (**"LDR= xx%"**).

## Hardware Components
- **Microcontroller**: ATmega32
- **Light Sensor**: LDR (Connected to PA0, ADC Channel 0)
- **Temperature Sensor**: LM35 (Connected to PA1, ADC Channel 1)
- **Display**: 16x2 LCD in 8-bit mode
  - RS: PD0
  - Enable: PD1
  - R/W: Ground (always write mode)
  - Data Pins: PORTC (8-bit mode)
- **Motor Control**: H-Bridge for motor speed control
  - IN1: PB0
  - IN2: PB1
  - Enable1: PB3/OC0
- **LEDs**:
  - Red LED: Connected to PB5
  - Green LED: Connected to PB6
  - Blue LED: Connected to PB7
- **Flame Sensor**: Connected to PD2 to detect fire.
- **Buzzer**: Connected to PD3, activated during fire alert.

## Operation Description
- **Lighting Control (LDR)**: The LDR monitors light intensity, and the three LEDs are controlled based on predefined thresholds.
- **Temperature Control (LM35)**: The LM35 sensor measures room temperature, and the fan speed is controlled using a PWM signal that adjusts speed according to specified temperature ranges.
- **Fire Detection**: The flame sensor triggers an alert when fire is detected:
  - Displays **"Critical alert!"** on the LCD.
  - Activates the buzzer.
  - The system remains in alert mode until the flame sensor no longer detects fire.

## System Requirements
- **Microcontroller**: ATmega32
- **System Frequency**: 16 MHz
- **Layered Model Architecture**: The project should be implemented using a structured layered model architecture for better organization and modularity.

## How to Use
### Setup:
- Connect the hardware components as described in the project documentation.

### Operation:
- The system automatically adjusts lighting and fan speed based on environmental readings.
- In case of fire detection, an alarm is triggered, and the alert is displayed on the LCD.

### Real-Time Monitoring:
- The LCD continuously updates to show the fan state, temperature, and light intensity.

## Installation
### Hardware Setup:
- Assemble the circuit as per the provided schematic diagram.

### Software:
- Compile the code using an AVR-compatible compiler.
- Upload the code to the ATmega32 microcontroller.

