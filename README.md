# Autonomous Maze Solver Robot

![Robot Screenshot](media/images/placeholder.png)

## About The Project

This project is an autonomous maze-solving robot developed during the UCI ICS Intelligent Robotics Summer Academy.

The robot was designed to navigate a grid-based maze independently using distance sensors, motor control, and custom Arduino C++ software. Throughout development, I worked on robot programming, navigation algorithms, debugging systems, and reliability improvements to create a robot capable of completing the maze autonomously.

The final optimized version of the robot achieved **1st place among 8 teams** in the final maze competition, completing the maze in approximately **45 seconds**.

The main goals of this project were:

- Develop an autonomous robot capable of navigating an unknown maze
- Create reliable movement and decision-making algorithms
- Debug hardware and software issues through iterative testing
- Improve performance through optimization and engineering trade-offs



## Built With

This project was built using the following hardware and software:

### Hardware

- Arduino UNO R4 WiFi
- Distance sensors
- Motor driver
- DC motors
- Robot chassis
- Battery system

### Software

- Arduino C++
- Arduino IDE
- WiFi-based debugging system



## Features

The robot includes the following features:

- Autonomous maze navigation
- Distance sensor-based wall detection
- Custom movement decision algorithm
- Stuck detection and recovery system
- Automatic orientation correction
- Watchdog timer system for Arduino crash recovery
- WiFi-based real-time sensor debugging



## Robot Design

![Robot Components](media/component_collage.png)

The robot was developed through multiple design iterations. During development, the team explored improvements such as optimizing robot size, adjusting sensor placement, and improving movement consistency.

The final design balanced hardware limitations, navigation accuracy, and speed.



## Software Versions

This repository contains multiple versions of the robot's software.

### Standard Version

The standard version is the foundation of the maze solver system.

It focuses on establishing consistent autonomous navigation through:

- Sensor data processing
- Movement decision logic
- Maze-solving behavior
- Recovery systems

Location:
