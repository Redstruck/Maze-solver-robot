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

https://github.com/user-attachments/assets/b2950f95-da69-4e71-9404-3c124d75dd02

https://github.com/user-attachments/assets/4a9a394f-5105-411d-8003-3e2d329cc4b1


# Engineering Challenges

Developing an autonomous robot required solving numerous hardware and software issues.

## Motor Drift

### Problem

The robot frequently drifted away from straight paths.

### Solution

Motor timing was repeatedly adjusted and calibrated through testing until movement became more consistent.

 

## Slow Sensor Updates

### Problem

Sensor readings were initially too slow for responsive navigation.

### Solution

Sensor polling frequency and software timing were optimized to improve responsiveness.

 

## False Wall Detection

### Problem

Occasional inaccurate sensor readings caused unnecessary turns.

### Solution

Detection thresholds were refined through repeated testing to reduce false positives while maintaining reliable wall detection.

 

## Robot Becoming Stuck

### Problem

During testing the robot occasionally became trapped after unsuccessful turns.

### Solution

A dedicated recovery routine was developed to automatically detect and escape these situations.

 

## Wall Alignment Oscillation

### Problem

Early wall-alignment logic caused the robot to continuously overcorrect its position.

### Solution

The alignment algorithm was simplified and tuned to produce smoother movement.

 

# Calibration

A significant portion of development involved calibration rather than adding new features.

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
