# Development

This document outlines the development process of the Arduino Maze Solver Robot, from the first movement tests to the final competition-ready version. The project was built through iterative hardware improvements, software development, debugging, and extensive testing.

 

# Development Overview

The robot was not built in a single iteration. Instead, it evolved through multiple stages of development, with each version introducing new capabilities and addressing limitations discovered during testing.

The primary development goals were:

- Build a reliable autonomous robot capable of navigating unknown mazes
- Detect walls using distance sensors
- Implement a complete maze-solving algorithm
- Recover automatically from navigation failures
- Optimize speed while maintaining reliability

Every improvement was validated through repeated testing before being integrated into the final competition version.


# Evolution of the Robot

| Version | Major Feature Added |
|---------|--------|
| **v0.1** | Basic motor movement |
| **v0.2** | Distance sensor integration |
| **v0.3** | Wall detection |
| **v0.4** | Right-hand rule navigation |
| **v0.5** | Dead-end handling |
| **v0.6** | Stuck recovery system |
| **v1.0** | Competition-ready robot |



# Hardware Development

The robot was assembled around the Arduino UNO R4 WiFi and gradually expanded as new hardware components were integrated.

Development included:

- Installing the motor shield
- Wiring three distance sensors
- Integrating the I²C multiplexer
- Optimizing sensor placement
- Adjusting battery placement for weight balance
- Improving cable management

As software became more advanced, small hardware adjustments significantly improved navigation accuracy and turning consistency.

 

# Software Development

## Stage 1 — Basic Motor Control

The first milestone was simply controlling the motors.

The robot was programmed to:

- Drive forward
- Reverse
- Turn left
- Turn right

This stage established reliable motor control before introducing sensor input.

### Demonstration

https://github.com/user-attachments/assets/caecbdef-9374-48b7-9718-84ff281ca026



## Stage 2 — Wall Detection

After motor control was complete, distance sensors were integrated.

The robot could now:

- Detect walls
- Stop before collisions
- Turn when obstacles were detected

This stage verified that sensor readings could reliably influence movement decisions.

### Demonstration

https://github.com/user-attachments/assets/3606b892-f53e-4eab-92a7-80134335bd01




## Stage 3 — Maze Navigation

Once wall detection was reliable, autonomous navigation logic was implemented.

The robot learned to:

- Follow the right-hand rule
- Detect intersections
- Navigate corners
- Continue exploring unknown paths

At this stage the robot could complete simple mazes but still struggled with reliability in more complex layouts.

 


## Stage 4 — Dead-End Handling

Additional logic was added to recognize dead ends.

When surrounded by walls, the robot:

1. Reversed slightly
2. Rotated 180°
3. Continued navigating

This prevented the robot from becoming trapped inside closed sections of the maze.

### Demonstration

https://github.com/user-attachments/assets/adc2c829-b14a-4e57-8157-776faf344c81




## Stage 5 — Recovery System

Although navigation had improved significantly, the robot occasionally became stuck because of wheel slip, imperfect turns, or unexpected positioning.

A recovery routine was developed to detect when the robot stopped making progress.

The recovery algorithm:

- Detected repeated sensor readings
- Identified when movement had stalled
- Executed corrective maneuvers
- Returned to normal navigation

This dramatically improved reliability during long runs.

### Demonstration

https://github.com/user-attachments/assets/f78b7be6-9f2f-427b-96e4-d2ce20c201c8




## Stage 6 — Competition Optimization

The final development phase focused entirely on optimization.

Numerous parameters were adjusted through repeated testing, including:

- Motor speed
- Turn duration
- Sensor thresholds
- Wall detection distance
- Navigation timing

Small adjustments often produced significant improvements in overall performance.

The final version successfully completed multiple different maze layouts before being used in competition.

### Demonstrations

https://github.com/user-attachments/assets/5ad4e985-8bb6-429d-bc40-1232510f7869

https://github.com/user-attachments/assets/f9386f6d-d679-4c7b-8168-fc9375a8573e

https://github.com/user-attachments/assets/4a9a394f-5105-411d-8003-3e2d329cc4b1


# Engineering Challenges

Developing an autonomous robot required solving numerous hardware and software issues.

## Motor Drift

### Problem

Previously, the robot frequently drifted and struggled to maintain a straight path due to hardware, specifically the DC motors that it used. As it gradually drifted toward one side of the maze, it would scrape against walls, become misaligned, and sometimes fail to detect or execute turns accurately.

### Solution

To prevent the robot from drifting, motor timing and delays were repeatedly adjusted and fine-tuned through testing until movement became more consistent. I also added the misalignment functions `turnRightSlightly()` and `turnLeftSlightly()`, which were called whenever the Modulino distance sensors detected that the robot was too close to either side. These functions allowed the robot to re-align itself before continuing to explore the maze.


## Slow Sensor Updates

### Problem

The robot did not receive updated distance measurements from the sensors fast enough, causing it to react too late when approaching walls or openings. This delay resulted in missed turns, late corrections, and occasional collisions because navigation decisions were based on outdated sensor data.

### Solution

In `readSensors()`, each sensor was read three times to clear the I2C communication buffer, with only the final readings being stored as `frontDist`, `leftDist`, and `rightDist`. I also configured the I2C bus speed using `Wire1.setClock(400000);`, increasing the clock frequency from 100 kHz (Default Mode) to 400 kHz (Fast Mode). This reduced communication delay between the Arduino and the Modulino distance sensors, allowing sensor data to be updated more frequently. Together, these optimizations allowed for more recent distance readings, making the robot significantly more responsive to walls and sudden changes in its environment.

## False Wall Detection

### Problem

Early versions of the robot used inaccurate sensor distance thresholds, causing it to detect maze openings too early or too late. As a result, the robot would sometimes turn before reaching an opening or continue past it before attempting to turn. 

### Solution

I made Distance thresholds into constant variables (`MaxFrontDist` and `MaxSideDist`) so they could be easily adjusted during testing without modifying the robot's navigation logic. The `updateWallStates()` function then compared the live sensor readings against these thresholds to determine whether a wall was present in front, to the left, or to the right. By repeatedly testing and fine-tuning these threshold values on the physical robot, the wall detection became much more reliable, preventing early turns and ensuring the robot only changed direction when it reached a valid maze opening. 

## Robot Becoming Stuck

### Problem

During testing, the robot would occasionally become stuck after an unsuccessful turn or when its wheels became wedged against a wall. In these situations, the sensor readings also remained almost unchanged, preventing the robot from making progress through the maze.

### Solution

I wrote a stuck detection system using `checkIfStuck()`, which continuously compared the current sensor readings with the previous values stored in `lastFrontDist`, `lastRightDist`, and `lastLeftDist`. If all three sensor readings remained within `STUCK_TOLERANCE`(15 mm) for longer than `STUCK_TIMEOUT` (900 ms), the function determined that the robot was no longer making progress and triggered `handleStuck()`. This function caused the robot to reverse before choosing the side with more available space based on the distance sensor readings, allowing it to free itself and continue navigating the maze without human intervention.
 

## Arduino Board Crashing

### Problem

During testing, the Arduino would occasionally freeze while the robot was navigating the maze, most likely due to a temporary hardware or power issue such as motor-induced voltage drops (brownouts) or another unexpected fault. Pressing the Arduino's reset button would immediately restart the program, and the robot would continue navigating correctly from its current position. This issue was common among nearly every team in the competition, and the professor even allowed competitors to manually press the reset button during a run if necessary. However, the goal of this project was to build a fully autonomous maze-solving robot, so relying on manual intervention was not considered an acceptable solution.

### Solution

The Arduino Watchdog Timer library (`WDT.h`) was added, and `WDT.begin(4000);` was called during `setup()` to configure a 4-second watchdog timeout. At the end of every iteration of `loop()`, `WDT.refresh();` reset the watchdog timer after the robot successfully completed one movement cycle, confirming that the program was still running normally. If the code ever froze before reaching `WDT.refresh()`, the watchdog timer would automatically reset the Arduino, allowing the robot to recover without any human intervention and continue operating autonomously. This approach ultimately allowed the robot to recover from an unexpected Arduino crash towards the end of the maze, allowing it to solve the rest and achieve a first-place finish in the Intelligent Robotics Competition.

# Fine Tuning

A significant portion of development involved fine-tuning existing values rather than adding new features.

Repeated testing was performed to determine values for:

- Forward movement speed
- Turning speed
- Turn duration
- Sensor thresholds
- Wall detection distance
- Recovery timing

These values were refined over numerous trial runs until consistent performance was achieved.

Performance graphs and testing results can be found in **testing.md**.

 

# Development Timeline

| Stage | Result |
|---------|--------|
| Motor Control | Robot successfully drove in all directions |
| Sensor Integration | Reliable wall detection achieved |
| Navigation Logic | Robot navigated simple mazes autonomously |
| Dead-End Logic | Robot escaped enclosed sections |
| Recovery System | Robot recovered from navigation failures |
| Optimization | Speed and reliability improved through calibration |
| Watchdog Timer | A Watchdog Timer was added as a precaution if the Arduino crashed unexpectedly |
| Competition | Successfully completed the maze and earned 1st Place |

 

# Lessons Learned

Developing this project provided valuable experience in robotics, embedded systems, and software engineering.

Some of the most important lessons included:

- Reliable autonomous systems require extensive testing and iteration.
- Small calibration changes can significantly affect robot behavior.
- Hardware placement is just as important as software design.
- Modular software makes debugging considerably easier.
- Testing on multiple maze layouts is essential to verify that an algorithm generalizes beyond a single environment.

The final robot represents the result of continuous refinement, testing, and engineering improvements throughout the entire development process.
