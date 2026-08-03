# 🤖 Autonomous Maze Solver Robot

![Robot Banner](media/images/banner.png)

<div align="center">

A fully autonomous maze-solving robot built using Arduino C++ and embedded systems techniques.

🏆 **1st Place — UCI ICS Intelligent Robotics Summer Academy Maze Competition**  
⏱️ **Fastest Completion Time: ~45 seconds**  
👥 **8 Competing Teams**

</div>

---

## About The Project

The **Autonomous Maze Solver Robot** is an embedded robotics project developed during the **UCI ICS Intelligent Robotics Summer Academy**.

The goal of the project was to design and program a robot capable of independently navigating a grid-based maze using distance sensors, motor control, and custom navigation algorithms.

The robot was programmed entirely in **Arduino C++**, with software responsible for sensor processing, movement decisions, maze navigation, error recovery, and system reliability.

Throughout development, multiple hardware and software challenges were encountered, including sensor instability and Arduino crashes. These issues were solved through debugging systems, algorithm improvements, and the implementation of a watchdog timer recovery system.

---

# Features

✅ Autonomous maze navigation  
✅ Distance sensor-based obstacle detection  
✅ Custom movement decision algorithm  
✅ Stuck detection and recovery system  
✅ Automatic orientation correction  
✅ Arduino watchdog timer crash recovery  
✅ WiFi-based real-time sensor debugging  
✅ Optimized movement algorithms for faster completion times  

---

# Built With

## Hardware

| Component | Purpose |
|---|---|
| Arduino UNO R4 WiFi | Main microcontroller |
| Distance Sensors | Detect maze walls and obstacles |
| Motor Driver | Controls DC motors |
| DC Motors | Robot movement |
| Custom Chassis | Robot structure |
| Battery System | Power source |

## Software

| Technology | Usage |
|---|---|
| Arduino C++ | Robot programming |
| Arduino IDE | Development environment |
| WiFi Communication | Sensor debugging |
| Embedded Systems | Hardware-software integration |

---

# Robot Design

![Robot Components](media/component_collage.png)

The robot was designed through multiple iterations to improve navigation performance. During development, the team experimented with factors such as robot size, sensor placement, and movement behavior.

---

# Software Versions

This repository contains different iterations of the robot's navigation software.

## Standard Version

The standard version established the foundation of the autonomous navigation system.

### Includes:
- Sensor data processing
- Movement decision logic
- Maze navigation
- Recovery mechanisms
- System stability features

 Location:

```
src/maze_solver_standard/
```

---

## Optimized Version

The optimized version improved upon the standard implementation by tuning movement parameters and refining navigation behavior to achieve faster maze completion.

### Improvements:
- Increased movement speed
- Adjusted turning behavior
- Optimized timing parameters
- Maintained core reliability systems

This version was used during the final competition and achieved:

 **1st Place among 8 teams**  
 **~45 second completion time**

📂 Location:

```
src/maze_solver_optimized/
```

---

# Engineering Challenges

## Arduino Crashes

### Problem
During testing, the Arduino would occasionally freeze and require a manual reset.

### Solution
A watchdog timer system was implemented to automatically detect failures and restart the controller without human intervention.

This improved reliability and prevented crashes from affecting competition performance.

---

## Sensor Debugging

### Problem
Sensor readings were difficult to analyze while the robot was operating.

### Solution
A WiFi debugging system was created where the Arduino transmitted live sensor data to a laptop server, allowing real-time monitoring and troubleshooting.

---

# Demo

![Robot Demo](media/videos/demo_placeholder.png)

*(Competition footage and demonstration videos will be added here.)*

---

# 🏆 Competition Results

<div align="center">

## 🥇 1st Place

### UCI ICS Intelligent Robotics Summer Academy Maze Competition

</div>

| Category | Result |
|---|---|
| Teams | 8 |
| Maze Size | 6 × 3 grid |
| Grid Dimensions | 14 × 14 inches |
| Completion Time | ~45 seconds |

---

# Repository Structure

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
├── hardware/
│
└── README.md
```

---

# Acknowledgments

Special thanks to:

- **UCI ICS Intelligent Robotics Summer Academy** for providing the learning environment and resources
- My teammates for their contributions to robot construction and design
- The instructors and mentors who supported the project throughout development

---

# Contact

Created by **Nishad Raghuvanshi**

GitHub: [Your GitHub Profile]

Project Link: [Repository Link]
