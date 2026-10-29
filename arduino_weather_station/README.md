# Arduino Weather Station 🌡️

## Overview

Arduino Weather Station is a simple electronics project that measures temperature and relative humidity using a DHT11 sensor and displays the readings on a 128×64 SSD1306 OLED display.

The system displays temperature in both Celsius and Fahrenheit, along with humidity percentage. It is built using Arduino and communicates with the OLED display through the I2C interface.

This project is intended for learning sensor interfacing, embedded programming, and real-time environmental monitoring.

## Arduino IDE - https://www.arduino.cc/en/software/

## Features

- Measures temperature in Celsius (°C)
- Converts and displays temperature in Fahrenheit (°F)
- Measures relative humidity (%)
- Displays readings on an OLED screen
- Updates measurements approximately every two seconds
- Handles invalid sensor readings with an error message
- Uses a compact Arduino-based circuit

## Components Required

- Arduino Uno or classic Arduino Nano
- DHT11 temperature and humidity sensor
- SSD1306 128×64 I2C OLED display
- Breadboard
- Jumper wires
- USB cable for Arduino power and programming

A DHT11 module with three pins or a bare four-pin DHT11 sensor may be used. The wiring differs slightly depending on the sensor version.

## Pin Connections

### 1. DHT11 Sensor

| DHT11 Pin | Arduino Uno / Nano |
|---|---|
| VCC / + | 5V, if supported by the module |
| DATA / OUT | Digital Pin 2 |
| GND / - | GND |

For a bare four-pin DHT11 sensor, identify the pins using its datasheet. A suitable pull-up resistor, typically 4.7kΩ–10kΩ, is generally required between DATA and VCC when one is not already present on the sensor module.

### 2. SSD1306 OLED Display

| OLED Pin | Arduino Uno | Classic Arduino Nano |
|---|---|---|
| VCC | 5V, if supported | 5V, if supported |
| GND | GND | GND |
| SDA | A4 | A4 |
| SCL | A5 | A5 |

**Important:** Check the voltage requirements of your specific sensor and OLED modules before connecting power. Some OLED modules support only 3.3V. Other Arduino boards may use different I2C pins.

## Libraries Required

Install the following libraries through the Arduino IDE Library Manager:

- Adafruit Unified Sensor
- DHT sensor library by Adafruit
- Adafruit GFX Library
- Adafruit SSD1306

The `Wire` library is used for I2C communication and is normally included with the Arduino platform.

## How It Works

1. The Arduino initializes the DHT11 sensor and SSD1306 OLED display.
2. The DHT11 measures the surrounding temperature and relative humidity.
3. The Arduino reads the sensor values.
4. Temperature in Fahrenheit is calculated from Celsius using the formula: °F = (°C × 1.8) + 32.
5. The OLED displays temperature in both units and the humidity percentage.
6. If the sensor returns an invalid reading, the display shows a DHT11 error message.
7. The measurement process repeats approximately every two seconds.

## Software Details

- Microcontroller: Arduino Uno / Nano
- Programming language: C++ (Arduino framework)
- Sensor communication: Digital interface
- Display communication: I2C
- Display resolution: 128×64 pixels
- OLED I2C address configured in code: `0x3C`
- Sensor data pin: Digital Pin 2
- Serial communication: 9600 baud

## Use Cases

- Learning temperature and humidity sensor interfacing
- Monitoring indoor room conditions
- Building a basic environmental monitoring system
- Understanding I2C OLED communication
- Practising Arduino programming and sensor data handling
- Developing a foundation for more advanced weather monitoring projects

## Limitations

- DHT11 has limited accuracy and operating range compared with more advanced sensors.
- This project measures temperature and humidity only.
- It does not measure atmospheric pressure, rainfall, wind speed, or air quality.
- Readings may vary depending on sensor placement and environmental conditions.

## Project Status

Source code prepared for an Arduino Uno/Nano, DHT11 sensor, and SSD1306 I2C OLED display.

Hardware testing status: Update after testing the complete circuit.

## Future Improvements

- Add an atmospheric pressure sensor such as BMP280
- Add an RTC module to display date and time
- Store readings for later analysis
- Add Wi-Fi connectivity using an ESP8266 or ESP32
- Build a web dashboard for monitoring sensor readings
- Add minimum and maximum temperature tracking

## License

This project is distributed under the MIT License if the repository includes the corresponding MIT license file.

