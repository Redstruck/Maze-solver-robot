<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Competition Result][competition-shield]][competition-url]
[![Fastest Solve][solve-shield]][solve-url]

<a href="https://summeracademy.ics.uci.edu/intelligent-robotics-course-description/" target="_blank">
  <img src="https://img.shields.io/badge/Program-UCI%20ICS%20Intelligent%20Robotics-blue?style=for-the-badge">
</a>

[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<div align="center">
  <h3 align="center">Arduino Maze Solver Robot</h3>

  <p align="center">
    An autonomous maze-solving robot built on an Arduino UNO R4 WiFi — 🥇 1st Place at the UCI ICS Intelligent Robotics Summer Academy
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#competition-results">Competition Results</a></li>
    <li><a href="#demo">Demo</a></li>
    <li><a href="#how-it-works">How It Works</a></li>
    <li><a href="#repository-structure">Repository Structure</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

[![Maze Solver Robot][product-screenshot]](#demo)

The Arduino Maze Solver Robot is an autonomous robot that navigates through a maze by sensing its environment and making real-time movement decisions — with no human control.

The robot uses distance sensors to detect nearby walls, processes that data on an Arduino microcontroller, and drives its motors through a maze-solving algorithm.

It navigates a completely unknown maze using nothing but distance sensors and decision logic — no pre-mapping, no remote control. Multiple software iterations were developed and tuned, trading off accuracy for speed as the design matured, and the robot was proven under real competition conditions.

Developed during the **UCI ICS Intelligent Robotics Summer Academy**, this project competed in the final maze competition and achieved **1st Place**.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

**Hardware:**
* Arduino UNO R4 WiFi
* Distance sensors (wall detection)
* Motor driver
* DC motors
* Custom robot chassis

**Software:**
* [![Arduino][Arduino-badge]][Arduino-url]
* [![Arduino IDE][ArduinoIDE-badge]][ArduinoIDE-url]
* [![C++][Cpp-badge]][Cpp-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- COMPETITION RESULTS -->
## Competition Results

**🥇 1st Place — UCI ICS Intelligent Robotics Summer Academy Maze Competition**

| Category | Result |
|---|---|
| Teams | 8 |
| Maze Size | 6 × 3 grid |
| Grid Dimensions | 14 × 14 inches |
| Completion Time | ~46 seconds |

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- DEMO -->
## Competition Demonstration

The video below shows the robot autonomously solving the competition maze and earning **1st Place** at the UCI ICS Intelligent Robotics Summer Academy.

https://github.com/user-attachments/assets/7b618d96-d567-4311-9a95-02d7791e41bc

> **Interested in the development process?** Additional demonstrations, milestone videos, and engineering documentation are available in the [Development Documentation](docs/development.md).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- HOW IT WORKS -->
## How It Works

At each step, the robot reads distance measurements from its sensors to detect nearby walls and open paths. That sensor data is fed into a decision-making routine on the Arduino, which selects the next movement — forward, turn, or stop — based on the walls it can currently see. This loop runs continuously as the robot moves, letting it react to the maze in real time without any prior map of the layout.

Two versions of the solving logic are included in the repo, tuned differently for reliability versus speed (see [Usage](#usage)).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Repository Structure

```text
arduino-maze-solver-robot/
├── src/
│   ├── maze_solver_standard/
│   └── maze_solver_optimized/
│
├── media/
│   ├── images/
│   └── videos/
│
├── docs/
│   ├── hardware.md
│   ├── algorithm.md
│   ├── development.md
│   └── testing.md
│
└── README.md
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Documentation

Detailed documentation about the robot's design and development:

- [Hardware Documentation](docs/hardware.md)
- [Algorithm Explanation](docs/algorithm.md)
- [Development Process](docs/development.md)
- [Testing Results](docs/testing.md)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

This section explains how to set up the project and upload the code to the robot.

### Prerequisites

Before running this project, you will need:

* Arduino IDE
  ```sh
  # Download from https://www.arduino.cc/en/software
  ```
* Arduino UNO R4 WiFi board support installed
  ```
  Arduino IDE > Tools > Board > Boards Manager > search "UNO R4" > Install
  ```
* Required hardware components (see Built With)
* USB-C cable for programming

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Redstruck/arduino-maze-solver-robot.git
   ```
2. Open the desired robot program in Arduino IDE:
   ```
   src/
   ├── maze_solver_standard/
   └── maze_solver_optimized/
   ```
3. Connect the Arduino UNO R4 WiFi to your computer via USB-C.
4. Select the correct board and port
   ```
   Tools > Board > Arduino UNO R4 WiFi
   Tools > Port > (your connected port)
   ```
5. Upload the sketch to the robot.
6. Place the robot in the maze and begin testing.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

The robot autonomously navigates a maze by continuously reading sensor data and selecting the best movement action.

The repository includes two versions:

* **Standard Version**
  * Focused on reliability and consistent maze completion
  * Uses slower movement for improved accuracy
* **Optimized Version**
  * Focused on increasing speed
  * Uses adjusted movement parameters for faster completion times

_For hardware wiring notes and further documentation, see the `hardware/` folder._

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [x] Build autonomous maze-solving robot
- [x] Implement distance-based navigation
- [x] Complete final competition maze
- [x] Achieve 1st Place at UCI ICS Intelligent Robotics Summer Academy Maze Competition
- [ ] Add competition demonstration videos
- [ ] Improve movement speed
- [ ] Add detailed algorithm explanation
- [ ] Create hardware documentation

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Special thanks to:
* UCI ICS Summer Academy's Intelligent Robotics Course for providing the learning environment, resources, and competition opportunity
* My teammates for their contributions to robot construction and design
* The instructors and mentors who supported the project throughout development

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->

[license-shield]: https://img.shields.io/badge/License-MIT-red?style=for-the-badge
[license-url]: https://github.com/Redstruck/arduino-maze-solver-robot/blob/main/LICENSE.txt

[competition-shield]: https://img.shields.io/badge/Award-1st%20Place%20Winner-FFD700?style=for-the-badge
[competition-url]: #competition-demonstration

[solve-shield]: https://img.shields.io/badge/Fastest%20Solve-46%20Seconds-green?style=for-the-badge
[solve-url]: #competition-demonstration

[program-shield]: https://img.shields.io/badge/Program-UCI%20ICS%20Intelligent%20Robotics-blue?style=for-the-badge
[program-url]: https://summeracademy.ics.uci.edu/intelligent-robotics-course-description/

[product-screenshot]: media/images/robot-demo.png
[demo-thumbnail]: media/images/demo-thumbnail.png

[Arduino-badge]: https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white
[Arduino-url]: https://www.arduino.cc/

[ArduinoIDE-badge]: https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white
[ArduinoIDE-url]: https://www.arduino.cc/en/software

[Cpp-badge]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white
[Cpp-url]: https://isocpp.org/
