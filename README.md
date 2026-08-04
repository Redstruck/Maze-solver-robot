<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Competition Result][competition-shield]][competition-url]
[![Fastest Solve][solve-shield]][solve-url]
[![Program][program-shield]][program-url]
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
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

[![Arduino Maze Solver Robot][product-screenshot]](docs/algorithm.md)

> **Interested in how the robot makes decisions?** See the [Algorithm Documentation](docs/algorithm.md) to learn how the maze-solving logic works.

The Arduino Maze Solver Robot is an autonomous robot built to navigate mazes without any human control. Using distance sensors, it detects walls and open paths, processes that information on an Arduino microcontroller, and decides where to move in real time based on a maze-solving algorithm.

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

At each step, the robot collects distance readings from its sensors to identify nearby walls and available paths. The Arduino processes this sensor data and uses the decision-making routine to choose the next action, such as moving forward, turning, reversing, or stopping. This process repeats continuously while the robot navigates, allowing it to adjust to the maze in real time without needing a pre-built map of the layout.

> **Interested in how the robot makes decisions?** See the [Algorithm Documentation](docs/algorithm.md) to learn more about the solving logic and decision-making process.

Two versions of the solving logic are included in the repo, tuned differently for reliability versus speed (see [Usage](#usage)).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Repository Structure

```text
├── docs/
│   ├── assets/
│   │   ├── diagrams/
│   │   │   ├── hardware_architecture.png
│   │   │   ├── main_algorithm_flowchart.png
│   │   │   └── sensor_data_collection_flowchart.png
│   │   │
│   │   ├── graphs/
│   │   │   └── trial_completion_times.png
│   │   │
│   │   └── images/
│   │       ├── electronics-overview.png
│   │       ├── robot_bottom_labeled.png
│   │       └── robot_top_labeled.png
│   │
│   ├── README.md
│   ├── algorithm.md
│   ├── development.md
│   ├── hardware.md
│   └── testing.md
│
├── media/
│   ├── images/
│   │   ├── .gitkeep
│   │   └── robot-hero.png
│   └── videos/
│       ├── basic-motor-movement.mp4
│       ├── competition-maze-run.mp4
│       ├── dead-end-logic.mp4
│       ├── demo-maze-1.mp4
│       ├── demo-maze-2.mp4
│       ├── stuck-recovery.mp4
│       └── wall-detection-v1.mp4
│
├── src/
│   ├── maze_solver_optimized/
│   │   └── maze_solver_optimized.ino
│   └── maze_solver_standard/
│       └── maze_solver_standard.ino
│
├── .gitignore
├── LICENSE
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

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Special thanks to:
* UCI ICS Summer Academy's Intelligent Robotics Course for providing the learning environment, resources, and competition opportunity
* My teammates for their contributions to robot construction and design
* The instructors and mentors who supported the project throughout development

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->

[license-shield]: https://img.shields.io/badge/License-MIT-red?style=for-the-badge
[license-url]: https://github.com/Redstruck/arduino-maze-solver-robot/blob/main/LICENSE

[competition-shield]: https://img.shields.io/badge/Award-1st%20Place%20Winner-FFD700?style=for-the-badge
[competition-url]: #competition-demonstration

[solve-shield]: https://img.shields.io/badge/Fastest%20Solve-46%20Seconds-green?style=for-the-badge
[solve-url]: #competition-demonstration

[program-shield]: https://img.shields.io/badge/Program-UCI%20ICS%20Intelligent%20Robotics-blue?style=for-the-badge
[program-url]: https://summeracademy.ics.uci.edu/intelligent-robotics-course-description/

[product-screenshot]: media/images/robot-hero.png
[demo-thumbnail]: media/images/demo-thumbnail.png

[Arduino-badge]: https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white
[Arduino-url]: https://www.arduino.cc/

[ArduinoIDE-badge]: https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white
[ArduinoIDE-url]: https://www.arduino.cc/en/software

[Cpp-badge]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white
[Cpp-url]: https://isocpp.org/
