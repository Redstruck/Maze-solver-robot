# Hardware Documentation

## Overview

The Arduino Maze Solver Robot is built around an Arduino UNO R4 WiFi microcontroller connected to distance sensors, motor controllers, and DC motors. The hardware allows the robot to detect maze walls, process sensor data, and autonomously navigate through unknown environments.

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino UNO R4 WiFi | Main microcontroller responsible for processing sensor data and controlling movement |
| Modulino Distance Sensors (x3) | Detect nearby walls and obstacles |
| Adafruit PCA9546 I2C Multiplexer | Allows multiple distance sensors to communicate through the same I2C connection |
| DRV8835 Motor Driver Shield | Controls power delivery to the DC motors |
| DC Motors | Provide movement and turning capability |
| Battery Pack with Push-Button Switch | Powers the robot and provides an easy way to turn it on and off |
| Robot Chassis | Supports the electronics and mechanical components |

## Robot Design

(Add a picture of your robot here)

The robot was designed to fit within the competition maze dimensions while maintaining enough space for sensors, motors, and electronics.

## Sensor System

The robot uses multiple distance sensors positioned around the chassis to detect surrounding walls.

Sensor placement:

- Front sensor:
- Left sensor:
- Right sensor:

These readings are continuously processed by the Arduino to determine the robot's next movement.

## Motor System

The Arduino controls the motors through the DRV8835 motor driver. The motor system allows the robot to:

- Move forward
- Turn left
- Turn right
- Correct alignment

## Physical Specifications

| Specification | Measurement |
|---|---|
| Robot Width | 7 inches |
| Robot Length | 9 inches |
| Maze Grid Size | 14 × 14 inches |
