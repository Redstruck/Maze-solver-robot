# Autonomous Maze Solver Robot

![Robot Image](media/images/placeholder.png)

## About The Project

This project is an autonomous maze-solving robot developed during the **UCI ICS Intelligent Robotics Summer Academy**.

The robot was designed to independently navigate a grid-based maze using distance sensors, motor control systems, and custom Arduino C++ software. The project involved developing navigation algorithms, debugging hardware and software issues, and improving system reliability through multiple iterations.

The final optimized version of the robot achieved **1st place among 8 teams** in the final maze competition, completing the maze in approximately **45 seconds**.

---

## Built With

### Hardware
- Arduino UNO R4 WiFi
- Distance sensors
- Motor driver
- DC motors
- Robot chassis
- Battery system

### Software
- Arduino IDE
- Arduino C++
- WiFi-based debugging system

---

## Features

- Autonomous maze navigation
- Distance sensor-based obstacle detection
- Custom movement decision algorithm
- Stuck detection and recovery system
- Automatic orientation correction
- Watchdog timer system for Arduino crash recovery
- WiFi-based sensor debugging

---

## Robot Design

![Hardware Components](media/component_collage.png)

The robot was designed to balance size, sensor placement, and movement performance. During development, the team explored improvements such as reducing the robot footprint and adjusting sensor placement to improve navigation accuracy.

---

## Software Versions

This repository contains multiple iterations of the robot's software.

### Standard Version

The standard version is the foundation of the maze-solving system.

It focuses on consistent autonomous navigation and includes the core:
- Sensor processing
- Movement logic
- Maze-solving decisions
- Recovery systems

Location:

```
src/maze_solver_standard/
```

---

### Optimized Version

The optimized version builds upon the standard implementation by adjusting movement parameters and navigation behavior to improve maze completion speed.

It explores the trade-off between faster movement and consistent performance.

This version was used during the final competition, where the robot achieved **1st place among 8 teams** with a completion time of approximately **45 seconds**.

Location:

```
src/maze_solver_optimized/
```

---

## Challenges & Solutions

### Arduino Stability Issues

During development, the Arduino occasionally crashed during operation, requiring manual resets.

To solve this issue, a watchdog timer system was implemented to automatically recover the controller when failures occurred. This significantly improved reliability during testing and competition.

---

### Sensor Debugging

Debugging sensor issues was challenging because sensor readings were difficult to observe while the robot was moving.

A WiFi-based debugging system was created, allowing the Arduino to transmit sensor data to a laptop server for real-time monitoring and troubleshooting.

---

## Demo

![Competition Video](media/videos/placeholder.png)

---

## Competition Results

🏆 **1st Place — Final Maze Competition**

- Teams: 8
- Maze size: 6 × 3 grid
- Grid size: 14 × 14 inches
- Completion time: ~45 seconds

---

## Project Structure

```
arduino-maze-solver-robot/

├── src/
│   ├── maze_solver_standard/
│   └── maze_solver_optimized/
│
├── media/
│   ├── images/
│   └── videos/
│
└── README.md
```

---

## Acknowledgments

- UCI ICS Intelligent Robotics Summer Academy
- Team members who contributed to the robot design and construction
- Instructors and mentors who supported the project development
