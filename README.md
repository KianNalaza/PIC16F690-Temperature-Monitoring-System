# PIC16F690 Temperature Monitoring System

An embedded temperature monitoring system built using a **PIC16F690 microcontroller**, **LM35 temperature sensor**, **10-bit ADC**, and **multiplexed 7-segment displays**.

<img width="1024" height="473" alt="image" src="https://github.com/user-attachments/assets/56f141d8-2e55-4c0e-897c-dd802d82c46f" />

## Overview

This project explores analog-to-digital conversion and sensor interfacing using the PIC16F690 microcontroller.

An LM35 temperature sensor produces an analog voltage proportional to the measured temperature. The PIC16F690 samples this signal using its built-in 10-bit ADC, converts the ADC reading into a temperature value, and displays the result on two multiplexed 7-segment displays.

The project also investigates how high-level C code is translated into PIC assembly and compares compiler-generated code with a simple hand-written assembly implementation.

## System Operation

The system follows the signal path:

```text
LM35 Temperature Sensor
        ↓
   Analog Voltage
        ↓
 PIC16F690 (AN2)
        ↓
    10-bit ADC
        ↓
Temperature Conversion
        ↓
Multiplexed 7-Segment Displays
```

The ADC produces a value between **0 and 1023**.

The input voltage is calculated using:

`Vin = (ADC Result / 1023) × Vref`

The LM35 produces approximately **10 mV/°C**, allowing the temperature to be calculated as:

`Temperature (°C) = (ADC Result × Vref × 100) / 1023`

A measured reference voltage of **4.95 V** was used during testing.

<img width="1563" height="617" alt="image" src="https://github.com/user-attachments/assets/12aea255-6470-4f77-b954-834d9663c61e" />


## Hardware

- PIC16F690 microcontroller
- LM35 temperature sensor
- Two 7-segment displays
- 10 kΩ potentiometer
- Current-limiting resistors
- Breadboard and jumper wires
- 5 V power supply

## Software & Tools

- Embedded C
- PIC Assembly
- MPLAB X IDE
- XC8 Compiler

## Key Features

- 10-bit analog-to-digital conversion
- LM35 temperature sensing
- Real-time temperature conversion
- Dual 7-segment display output
- Display multiplexing
- Direct PIC register configuration
- C-to-assembly analysis

## ADC Configuration

The PIC16F690 ADC was configured to:

- Use **AN2 / RA2** as the analog input
- Store the ADC result in right-justified format
- Use VDD as the ADC reference
- Operate with the PIC running at 4 MHz

The conversion result is reconstructed from the `ADRESH` and `ADRESL` registers before being converted into a temperature.

## Display Multiplexing

The two 7-segment displays share the segment lines connected to PORTC.

RA4 and RA5 are used to alternate between the units and tens digits. By switching between the displays rapidly, both digits appear continuously illuminated to the human eye.

<img width="1563" height="617" alt="image" src="https://github.com/user-attachments/assets/421036ec-755a-4872-8ade-cc5df95afe8f" />

## C and Assembly Investigation

A second part of the project investigated how a simple C multiplication algorithm is translated into PIC assembly.

```c
unsigned char multiplicand = 10;
unsigned char multiplier = 5;
int product = 0;

while (multiplier > 0) {
    product += multiplicand;
    multiplier--;
}
```

The generated assembly demonstrated how high-level operations are implemented using instructions such as `MOVLW`, `MOVWF`, `ADDWF`, `SUBWF`, `BTFSS`, `BTFSC`, and `GOTO`.

<img width="911" height="787" alt="image" src="https://github.com/user-attachments/assets/e4966409-70d4-46d9-916e-ae401bf42477" />

This highlighted the trade-off between the readability of high-level C and the greater control and potential efficiency of directly written assembly.

## What I Learned

Through this project I gained practical experience with:

- PIC16F690 microcontroller programming
- Analog-to-digital conversion
- Embedded sensor interfacing
- ADC register configuration
- LM35 temperature measurement
- 7-segment display multiplexing
- Embedded C
- PIC assembly
- Debugging hardware and software
- Understanding compiler-generated assembly

## Author

**Kian Nalaza**  
Electronic and Computer Engineering
Dublin City University
