# Eye Movement Dummy 👀

## Overview

Eye Movement Dummy is an Arduino-based electronics project that displays animated eyes on a 0.96-inch SSD1306 OLED display.

The eyes blink automatically at random intervals and occasionally look left or right, creating a simple robotic eye animation.

This project is designed for learning Arduino programming, OLED display interfacing, and basic animation logic.

## Features

- Animated circular eyes
- Automatic blinking animation
- Random left and right eye movements
- Random blinking intervals
- Adjustable eye positions and sizes
- Smooth display updates
- Compact and low-cost hardware setup

## Components Required

- Arduino Uno or Arduino Nano
- SSD1306 128×64 OLED display with I2C interface
- Jumper wires
- USB cable for programming and power

**Note:** This code is configured for an I2C OLED display with address `0x3C`. Confirm your display's voltage compatibility and I2C address before connecting it.

## Pin Connections

The following connections are for an Arduino Uno or a classic Arduino Nano using the hardware I2C interface.

| OLED Display Pin | Arduino Uno | Arduino Nano |
|---|---|---|
| VCC | 5V, if supported by the module | 5V, if supported by the module |
| GND | GND | GND |
| SDA | A4 | A4 |
| SCL | A5 | A5 |

**Important:** Some OLED modules support only 3.3V power. Check the module specifications before connecting VCC. Other Arduino boards may use different I2C pins.

## Libraries Required

Install these libraries using the Arduino IDE Library Manager:

- Adafruit GFX Library
- Adafruit SSD1306

The `Wire` library is used for I2C communication and is generally included with the Arduino platform.

## How It Works

1. The OLED display initializes using the SSD1306 driver at I2C address `0x3C`.
2. Two white circular eyes are drawn on the black OLED background.
3. The eyes blink automatically after a randomly selected interval.
4. The eyes occasionally shift left or right by changing their horizontal drawing position.
5. After a short duration, the eyes return to the center.
6. The process repeats continuously.

The program uses `millis()` for the main blink and glance timing logic, while short `delay()` calls are used during the blink animation and display refresh.

## Code Configuration

The following variables can be adjusted to customize the animation:

- `SCREEN_WIDTH` and `SCREEN_HEIGHT`: OLED resolution
- `leftEyeX` and `rightEyeX`: Horizontal eye positions
- `eyeY`: Vertical eye position
- `eyeRadius`: Circular eye size
- `eyeWidth` and `eyeHeight`: Blink animation dimensions
- `glanceOffset`: Horizontal movement direction and distance

## Use Cases

- Learning Arduino and I2C communication
- Practising OLED graphics and animation
- Building a simple robotic face
- Creating expressive eyes for a small robot
- Developing a starting point for interactive robotics projects

## Project Status

Source code prepared for an SSD1306 I2C OLED display.

Hardware testing status: Update this section after testing the circuit on your Arduino board.

## Future Improvements

- Add pupil movement and more expressive eye shapes
- Add facial expressions such as happiness or surprise
- Add buttons or sensors to control eye movement
- Integrate the eyes into a small robot
- Improve animation timing and transitions

## License

This project is available under the MIT License if distributed with the repository's MIT license file.

