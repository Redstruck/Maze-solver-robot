<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
![Competition Result][competition-shield]
![Fastest Solve][solve-shield]
![Program][program-shield]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/your_username/arduino-maze-solver-robot">
    <img src="media/images/logo.png" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">Arduino Maze Solver Robot</h3>

  <p align="center">
    An autonomous maze-solving robot built on an Arduino UNO R4 WiFi — 🥇 1st Place at the UCI ICS Intelligent Robotics Summer Academy
    <br />
    <a href="#about-the-project"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="#demo">View Demo</a>
    &middot;
    <a href="https://github.com/your_username/arduino-maze-solver-robot/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/your_username/arduino-maze-solver-robot/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
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
        <li><a href="#competition-results">Competition Results</a></li>
      </ul>
    </li>
    <li><a href="#demo">Demo</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#repository-structure">Repository Structure</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

[![Maze Solver Robot][product-screenshot]](#demo)

The Arduino Maze Solver Robot is an autonomous robot designed to navigate through a maze by sensing its environment and making real-time movement decisions — with no human control.

The robot uses distance sensors to detect nearby walls, processes that data on an Arduino microcontroller, and drives its motors through a maze-solving algorithm. Multiple software iterations were developed and tuned to balance reliability against speed.

Developed during the **UCI ICS Intelligent Robotics Summer Academy**, this project competed in the final maze competition and achieved **1st Place**.

Here's why it stands out:
* It navigates a completely unknown maze using nothing but distance sensors and decision logic — no pre-mapping, no remote control
* It went through multiple software iterations, trading off accuracy for speed as the design matured
* It was proven under competition conditions, finishing 1st out of 8 teams

**Features:**
- Autonomous maze navigation
- Real-time distance sensing
- Wall detection and avoidance
- Algorithm-based movement decisions
- Multiple software iterations for reliability and optimization

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* [![Arduino][Arduino-badge]][Arduino-url]
* [![Arduino IDE][ArduinoIDE-badge]][ArduinoIDE-url]
* [![C++][Cpp-badge]][Cpp-url]

**Hardware:**
* Arduino UNO R4 WiFi
* Distance sensors (wall detection)
* Motor driver
* DC motors
* Custom robot chassis

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Competition Results

**🥇 1st Place — UCI ICS Intelligent Robotics Summer Academy Maze Competition**

| Category | Result |
|---|---|
| Teams | 8 |
| Maze Size | 6 × 3 grid |
| Grid Dimensions | 14 × 14 inches |
| Completion Time | ~45 seconds |

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- DEMO -->
## Demo

Competition footage and demonstration videos will be added here.

[![Watch the Demo][demo-thumbnail]](#demo)

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
   git clone https://github.com/your_username/arduino-maze-solver-robot.git
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
7. Change the git remote url to avoid accidental pushes to the base project
   ```sh
   git remote set-url origin your_username/arduino-maze-solver-robot
   git remote -v # confirm the changes
   ```

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
├── hardware/
│
└── README.md
```

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

See the [open issues](https://github.com/your_username/arduino-maze-solver-robot/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions, suggestions, and improvements are welcome — they're what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your Changes (`git commit -m "Add NewFeature"`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

### Top contributors:

<a href="https://github.com/your_username/arduino-maze-solver-robot/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=your_username/arduino-maze-solver-robot" alt="contrib.rocks image" />
</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Created by **Nishad Raghuvanshi**

- GitHub: [@your-username](https://github.com/your-username)
- Project Link: [https://github.com/your_username/arduino-maze-solver-robot](https://github.com/your_username/arduino-maze-solver-robot)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Special thanks to:

* UCI ICS Intelligent Robotics Summer Academy for providing the learning environment, resources, and competition opportunity
* My teammates for their contributions to robot construction and design
* The instructors and mentors who supported the project throughout development
* [Choose an Open Source License](https://choosealicense.com)
* [Img Shields](https://shields.io)
* [Best-README-Template](https://github.com/othneildrew/Best-README-Template) — the structure this README is based on

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[license-shield]: https://img.shields.io/badge/License-MIT-red?style=for-the-badge
[license-url]: https://github.com/your_username/arduino-maze-solver-robot/blob/main/LICENSE.txt

[competition-shield]: https://img.shields.io/badge/Award-1st%20Place%20Winner-FFD700?style=for-the-badge

[program-shield]: https://img.shields.io/badge/Program-UCI%20ICS%20Intelligent%20Robotics-blue?style=for-the-badge

[solve-shield]: https://img.shields.io/badge/Fastest%20Solve-45%20Seconds-green?style=for-the-badge

[product-screenshot]: media/images/robot-demo.png
[demo-thumbnail]: media/images/demo-thumbnail.png

[Arduino-badge]: https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white
[Arduino-url]: https://www.arduino.cc/

[ArduinoIDE-badge]: https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white
[ArduinoIDE-url]: https://www.arduino.cc/en/software

[Cpp-badge]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white
[Cpp-url]: https://isocpp.org/
