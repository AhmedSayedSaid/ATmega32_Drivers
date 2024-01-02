# ATmega32 Drivers Documentation

## Overview

This repository contains a comprehensive collection of drivers for the ATmega32 microcontroller, essential for embedded systems development. The drivers are written in C, structured to provide clear, modular interfacing with various peripherals and modules.

## Contents

- MCAL Drivers
- HAL Drivers
- Helper Functions and Definitions
- SPI and USART Service Drivers
- Test Cases for Entire Driver
- License
- Acknowledgments

## MCAL Drivers

### Digital I/O (DIO)
- **File**: `DIO.h`
- **Functionality**: Manages digital input/output operations on ATmega32 ports.

### EEPROM
- **File**: `EEPROM.h`
- **Functionality**: Enables reading and writing to the ATmega32's EEPROM.

### Timers
- **Files**: `TIMERS.h`
- **Functionality**: Controls the three timers in ATmega32, including mode selection and interrupt management.

### External Interrupts
- **File**: `EXT_INTERRUPT.h`
- **Functionality**: Manages external interrupts configuration and handling.

### SPI Services
- **File**: `SPI_Services.h`
- **Functionality**: Manages SPI communication as either master or slave.

### Watchdog Timer
- **File**: `Watch_Dog.h`
- **Functionality**: Configures the watchdog timer for system reliability.

### USART
- **File**: `USART.h`
- **Functionality**: Manages USART communication with various settings.

## HAL Drivers

### LCD Display Driver
- **File**: `LCD.h`
- **Functionality**: Controls operations of an LCD display in either 4-bit or 8-bit mode.

## Helper Functions and Definitions

- `Common_Includes.h`: Centralizes commonly used header files for ease of inclusion in driver modules.
- `MemoryMap.h`: Provides direct register access for ATmega32's hardware components.
- `Status.h`: Defines standard return types for driver functions.
- `STDTypes.h`: Defines standard data types for consistency across all drivers.
- `UTILS.h`: Provides utility macros for common bitwise operations.

## SPI and USART Service Drivers

### SPI Service Driver
- **File**: `SPI_Services.h`
- **Functionality**: Advanced SPI communication functionalities.

### USART Service Driver
- **File**: `USART_Services.h`
- **Functionality**: Enhanced USART communication services.

## Contributing

Contributions to this project are welcome. Adherence to the existing code structure and comment styles is appreciated.


## License

This project is licensed under the MIT License

## Acknowledgments

Hat tip to anyone whose code was used. Special thanks to Eng. Mohamed Abdel-Baset for inspiration.



##


# ATmega32 Drivers Test Cases Documentation

## Overview

This comprehensive guide provides test cases for ATmega32 microcontroller drivers, ensuring functionality and reliability. The tests are tailored for the ETA mini 32 platform.

## Contents

- General Instructions
- Test Cases for Digital I/O (DIO)
- Test Cases for EEPROM
- Test Cases for PWM Measurement using Input Capture Unit
- Test Cases for SPI Communication with Arduino Slave
- Test Cases for USART Communication
- Test Cases for WatchDog Timer
- Test Cases for External Interrupt 
- Test Cases for all Timer Modes
- Test Cases  for Input Capture Unit


## General Instructions

To execute these test cases:

1. Clone the repository with all driver modules.
2. Incorporate the test case content into your `main.c` file.
3. Before compling the project comment all the code of the test cases inside the tests folder
4. Compile and upload the code to the ETA mini 32.
5. Observe and compare the results with the expected outcomes.


## Test Case for Digital I/O (DIO)

### Objective

To verify the Digital I/O (DIO) driver's efficiency in managing ATmega32 ports.

### Test Procedure

- **Setup**: Configure microcontroller pins for digital I/O.
- **Execution**: Conduct read/write operations on the pins.
- **Validation**: Ensure read values correspond to expected output.

### Test Steps

1. Initialize the DIO driver.
2. Set `PINA0` to output, writing a HIGH signal.
3. Set `PINA1` to input, reading the signal.
4. Compare the read value with the expected result.

### Expected Results

- Successful HIGH signal on `PINA0`.
- `PINA1` reads back the value written to `PINA0`.


## Test Case for EEPROM

### Objective

To validate the EEPROM driver's ability to accurately write and read data.

### Test Procedure

- **Write Data**: Store specific values in the EEPROM.
- **Read and Display**: Retrieve and display these values on Port C LEDs.
- **Validation**: Ensure LED patterns match EEPROM values.

### Test Steps

1. Write binary values to the EEPROM.
2. Read values from EEPROM.
3. Display each value on Port C LEDs for 2 seconds.
4. Confirm LED patterns match the written values.

### Expected Results

- Port C LEDs display EEPROM read values' binary representation.

<!-- You can continue to add more test cases in a similar format -->


## Test Case for PWM Measurement using Input Capture Unit

### Objective
To assess the ATmega32A's Input Capture Unit in measuring PWM signals from an Arduino pin.

### Test Procedure
- **Setup**: Prepare ATmega32A for PWM signal measurement.
- **Execution**: Generate and measure PWM signals from Arduino.
- **Display**: Show frequency and duty cycle on an LCD via Port A.
- **Validation**: Match measured values with expected output.

### Expected Results
- Frequency around 976Hz.
- Duty cycle near 25%.

### Test Environment and Results
- Measurement using ATmega32A's input capture unit.
- Signal source: Arduino pin 5.

## Test Case for SPI Communication with Arduino Slave

### Objective
To validate the SPI communication between an ATmega32A master and an Arduino slave.

### Test Procedure
- **Setup**: Configure the ATmega32A as an SPI master and the Arduino as an SPI slave.
- **Execution**: Send data from the ATmega32A to the Arduino and receive responses.
- **Validation**: Compare the received data with the expected responses.

### Test Steps
1. Initialize SPI on the ATmega32A and set it as a master.
2. Transmit a series of bytes (0x00, 0xAA, 0xBB, 0xCC, 0xDD) to the Arduino slave.
3. Receive the response from the Arduino (0x55, 0x66, 0x77, 0x88) and display it on an LCD.
4. Verify that the received data matches the expected response.

### Expected Results
- The data received from the Arduino should match the expected response (0x55, 0x66, 0x77, 0x88).

### Connection Pins
- ATmega32A MOSI (PB5) to Arduino Uno MOSI (11)
- ATmega32A MISO (PB6) to Arduino Uno MISO (12)
- ATmega32A SCK (PB7) to Arduino Uno SCK (13)
- ATmega32A SS (PB4) to Arduino Uno SS (10)

## Test Case for USART Communication

### Objective
To validate the USART communication between an ATmega32 and an Arduino Uno.

### Test Procedure
- **Setup**: Configure USART modules on both ATmega32 and Arduino Uno.
- **Execution**: Perform send and receive operations of strings and numbers between the two devices.
- **Validation**: Ensure the received data matches the sent data.

### Test Steps
1. Initialize DIO and LCD on ATmega32; Serial on Arduino Uno.
2. Transmit and receive a string ("I am from ATmega32") between ATmega32 and Arduino.
3. Transmit and receive a number (12345) between ATmega32 and Arduino.
4. Validate data integrity using CRC in data transmission and reception.
5. Increment and modify test data for continuous testing.

### Expected Results
- The string and number sent from ATmega32 are correctly received by Arduino and vice versa.
- Data integrity is maintained in CRC-validated transmissions.

### Test Environment and Results
- ATmega32: Implements USART communication and interfaces with an LCD.
- Arduino Uno: Utilizes Serial communication to interact with ATmega32.
- Validation Method: Serial Monitor (Arduino) and LCD Display (ATmega32).


## Test Cases for Timer Driver

### Overview
This document outlines test cases for the Timer driver of the ATmega32 microcontroller, focusing on generating PWM signals in various modes. These tests ensure the accurate functioning of the Timer driver across different configurations.

### Test Environment
All tests utilize an Arduino Uno with an input capture unit on pin 8. This setup measures the frequency and duty cycle of the generated PWM signals. The results are displayed on the Arduino's serial monitor.

### Test Cases

#### 1. CTC Mode Test Cases
- **10Hz Frequency, 50% Duty Cycle**
  - **File**: `ctc_mode_10hz_50%duty.c`
  - **Objective**: Generate a PWM signal at 10Hz with a 50% duty cycle using Timer1 in CTC mode.
  - **Configuration**:
    - Timer1 in CTC mode with OCR1A as TOP
    - Prescaler: 8
    - OCR1A register: 50000
  - **Expected Results**:
    - High time: 50000.0 microseconds
    - Low time: 50000.0 microseconds
    - Frequency: 10Hz
    - Duty Cycle: 50%
  - **Measured Results**: Compare with oscilloscope data.

- **50kHz Frequency, 50% Duty Cycle**
  - **File**: `ctc_mode_50khz_50%duty.c`
  - **Objective**: Generate a PWM signal at 50kHz with a 50% duty cycle using Timer1 in CTC mode.
  - **Configuration**:
    - Timer1 in CTC mode
    - Prescaler: 8
    - OCR1A register: 10
  - **Expected Results**:
    - High time: 10.0 microseconds
    - Low time: 10.0 microseconds
    - Frequency: 50kHz
    - Duty Cycle: 50%
  - **Measured Results**: Compare with oscilloscope data.

#### 2. Fast PWM Mode Test Cases
- **1kHz Frequency, 20% Duty Cycle**
  - **File**: `fastPwm_1khz_20%dutycycle.c`
  - **Objective**: Generate a PWM signal at 1kHz with a 20% duty cycle using Timer1 in fast PWM mode.
  - **Configuration**:
    - Timer1 in fast PWM mode with ICR1 as TOP
    - Prescaler: 8
    - ICR1 register: 999
    - OCR1A register: 199
  - **Expected Results**:
    - High time: 200 microseconds
    - Low time: 800 microseconds
    - Frequency: 1kHz
    - Duty Cycle: 20%
  - **Measured Results**: Compare with Arduino Uno input capture data.

- **25kHz Frequency, 25% Duty Cycle**
  - **File**: `fastPwm_25khz_25%dutycycle.c`
  - **Objective**: Generate a PWM signal at 25kHz with a 25% duty cycle using Timer1 in fast PWM mode.
  - **Configuration**:
    - Timer1 in fast PWM mode with ICR1 as TOP
    - Prescaler: 8
    - ICR1 register: 39
    - OCR1A register: 9
  - **Expected Results**:
    - High time: 10.00 microseconds
    - Low time: 30.00 microseconds
    - Frequency: 25kHz
    - Duty Cycle: 25%
  - **Measured Results**: Compare with Arduino Uno input capture data.

#### 3. Normal Mode Test Cases
- **1kHz Frequency, 20% Duty Cycle**
  - **File**: `normal_mode_1khz_20%dutycycle.c`
  - **Objective**: Generate a PWM signal at 1kHz with a 20% duty cycle using Timer0 in normal mode.
  - **Configuration**:
    - Timer0 in normal mode
    - Prescaler: 8
    - TCNT0 register: 56
  - **Expected Results**:
    - High time: 200 microseconds
    - Low time: 800 microseconds
    - Frequency: 1kHz
    - Duty Cycle: 20%
  - **Measured Results**: Compare with Arduino Uno input capture data.

- **5kHz Frequency, 30% Duty Cycle**
  - **File**: `normal_mode_5khz_30%dutycycle.c`
  - **Objective**: Generate a PWM signal at 5kHz with a 30% duty cycle using Timer0 in normal mode.
  - **Configuration**:
    - Timer0 in normal mode
    - Prescaler: 8
    - TCNT0 register: 196 and 116 alternately
  - **Expected Results**:
    - High time: 60 microseconds
    - Low time: 140 microseconds
    - Frequency: 5kHz
    - Duty Cycle: 30%
  - **Measured Results**: Compare with Arduino Uno input capture data.

- **50Hz Frequency, 50% Duty Cycle**
  - **File**: `normal_mode_50hz_50%dutycycle.c`
  - **Objective**: Generate a PWM signal at 50Hz with a 50% duty cycle using Timer0 in normal mode.
  - **Configuration**:
    - Timer0 in normal mode
    - Prescaler: 8
    - TCNT0 register: 6
  - **Expected Results**:
    - High time: 10000 microseconds
    - Low time: 10000 microseconds
    - Frequency: 50Hz
    - Duty Cycle: 50%
  - **Measured Results**: Compare with Arduino Uno input capture data.

#### 4. Phase Correct PWM Mode Test Cases
- **1953Hz Frequency, 40% Duty Cycle**
  - **File**: `phase_correct_1953hz_40%dutycylce.c`
  - **Objective**: Generate a PWM signal at 1953Hz with a 40% duty cycle using Timer0 in phase correct PWM mode.
  - **Configuration**:
    - Timer0 in phase correct mode
    - Prescaler: 8
    - OCR0 register: 99
  - **Expected Results**:
    - High time: 200 microseconds
    - Low time: 312 microseconds
    - Frequency: 1953.125Hz
    - Duty Cycle: 40%
  - **Measured Results**: Compare with Arduino Uno input capture data.

- **1953Hz Frequency, 60% Duty Cycle**
  - **File**: `phase_correct_1953hz_60%dutycylce.c`
  - **Objective**: Generate a PWM signal at 1953Hz with a 60% duty cycle using Timer0 in phase correct PWM mode.
  - **Configuration**:
    - Timer0 in phase correct mode
    - Prescaler: 8
    - OCR0 register: 99
  - **Expected Results**:
    - High time: 312 microseconds
    - Low time: 200 microseconds
    - Frequency: 1953.125Hz
    - Duty Cycle: 60.9%
  - **Measured Results**: Compare with Arduino Uno input capture data.

Each test case is structured to assess the Timer driver's capability to generate PWM signals accurately across a range of frequencies and duty cycles. The Arduino Uno's input capture feature serves as a reliable tool for measuring and validating these signal characteristics.
