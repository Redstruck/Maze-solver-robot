// This is the standard iteration of my maze solver robot developed in the Arduino IDE.
// It can autonomously navigate mazes, detect walls, and make movement decisions.
// This version prioritizes reliability and consistent maze completion over speed.

#include <WDT.h> // Initialize Watchdog Timer

#include <DRV8835MotorShield.h>   // Initialize Motor Shield
DRV8835MotorShield motors; 

#include "Modulino.h"   // Initialize Modulino Sensors
ModulinoDistance rightSensor;
ModulinoDistance frontSensor;
ModulinoDistance leftSensor;

#include <stdio.h>  // Add for boolean logic

#include <Wire.h>  // Initialize Wire

int getDistance(int channel) {
  delay(15);
  switchSensor(channel);
  rightSensor.available();
  if (rightSensor.available()) {
    return rightSensor.get();
  }
  else {           // If Sensor is unable to detect an object, automatically set rightDist to set direction as "(Clear)"
    return 9999;
  }
}

// Switches sensor by taking channel as argument 
void switchSensor(int channel) {
  Wire1.beginTransmission(0x70);
  Wire1.write(1 << channel); // Select channel
  Wire1.endTransmission();
  delay(10);
}

// Initialize global distance variables to track length between robot and walls in front, right, and left
volatile int frontDist = 9999, rightDist = 9999, leftDist = 9999;

// Read Sensor input values
void readSensors() {
  for (int i = 0; i < 3; ++i) {
    rightDist = getDistance(0);
  }
  
  for (int i = 0; i < 3; ++i) {
    frontDist = getDistance(1);
  }
  
  for (int i = 0; i < 3; ++i) {
    leftDist = getDistance(2);
  }
}

// Declate Constant movement variables
const int DRIVE_SPEED = 100;
const int TURN_SPEED = 170;
const int REVERSE_SPEED = 100;

// Motion Functions
void setMotors(int leftmotor, int rightmotor) {
  motors.setM1Speed(leftmotor);   // Left Motor
  motors.setM2Speed(rightmotor);  // Right Motor
}

void robotStop() {                              // Robot brakes
  setMotors(0, 0);
}

void turnRight() {                              // Robot turns right
  setMotors(TURN_SPEED, -TURN_SPEED);
  delay(300);
  robotStop();
}

void turnLeft() {                               // Robot turns left
  setMotors(-TURN_SPEED, TURN_SPEED);
  delay(300);
  robotStop();
}

void reverseBackwards() {                       // Robot reverses (useful for dead ends)
  robotStop();
  setMotors(-REVERSE_SPEED, -REVERSE_SPEED);
  delay(500);
  robotStop();
}

void turnAroundFromLeft() {                             // Robot turns around by rotating 180 degrees by turning left
  robotStop();
  setMotors(-TURN_SPEED, TURN_SPEED);
  delay(585);
  robotStop();
}

void turnAroundFromRight() {                             // Robot turns around by rotating 180 degrees by turning right
  robotStop();
  setMotors(TURN_SPEED, -TURN_SPEED);
  delay(585);
  robotStop();
}

// Misalignment Functions
void turnLeftSlightly() {       // If the right wall is very close, the robot will execute this function to turn left slightly
  setMotors(65, 80);
  delay(50);
}

void turnRightSlightly() {      // If the left wall is very close, the robot will execute this function to turn right slightly
  setMotors(80, 65);
  delay(50);
}

// Declare MIS_SIDE_THRESHOLD, which determines how close the robot can be to a side wall before misalignment functions begin.
const int MIS_SIDE_THRESHOLD_MIN = 50;
const int MIS_SIDE_THRESHOLD_MAX = 70;

void driveForwards() {       // Robot drives ahead and re-aligns itself if too close to a side wall
  if (MIS_SIDE_THRESHOLD_MIN < leftDist && leftDist < MIS_SIDE_THRESHOLD_MAX) {
    turnRightSlightly();    // If leftDist is between MIS_SIDE_THRESHOLD_MIN and MIS_SIDE_THRESHOLD_MAX, turnRightSlightly
  }
  else if (MIS_SIDE_THRESHOLD_MIN < rightDist && rightDist < MIS_SIDE_THRESHOLD_MAX) {
    turnLeftSlightly();     // If rightDist is between MIS_SIDE_THRESHOLD_MIN and MIS_SIDE_THRESHOLD_MAX, turnLeftSlightly
  }
  else {
    setMotors(DRIVE_SPEED, DRIVE_SPEED);
  }
}

// Declare Constant Values that determine how close a wall can be to the front or sides of the robot
const int MaxFrontDist = 180;
const int MaxSideDist = 250;

// Initialize Booleans for Wall logic
bool WallInFront; 
bool WallOnRight;
bool WallOnLeft;

void updateWallStates() {
  WallInFront = (frontDist < MaxFrontDist); // True if Front Distance between robot and nearest wall is less than maximum distance allowed (180 mm)
  WallOnRight = (rightDist < MaxSideDist); // True if Right Distance between robot and nearest wall is less than maximum distance allowed (250 mm)
  WallOnLeft = (leftDist < MaxSideDist); // True if Left Distance between robot and nearest wall is less than maximum distance allowed (250 mm)
}

const int closeFrontThreshold = 70;

// Movement Deciding algorithm
void decideMovement() {

  // Normal Movement
  if (!WallOnRight) {   // If there isn't a wall on right -> Go Right
    if (frontDist <= closeFrontThreshold) {   // If distance of wall in front is less than or equal to 70 (mm), simply turn right and move forward
      robotStop();
      turnRight();
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED);
      delay(800);
    }
    else {    // Else, if distance of wall in front is detected but not within 70 (mm), move forward, turn right, and move forward again
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED);
      delay(600);
      robotStop();
      turnRight();
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED);
      delay(800);
    }
  }
  else if (!WallInFront) {    // If there isn't a wall in front -> Go Forward
    driveForwards();
  }
  else if (!WallOnLeft) {     // If there isn't a wall on left -> Go Left

    if (frontDist <= closeFrontThreshold) {   // If distance of wall in front is less than or equal to 70 (mm), simply turn left and move forward
      robotStop();
      turnLeft();
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED); // C.D. was here
      delay(800);
    }
    else {    // Else, if distance of wall in front is detected but not within 70 (m), move forward, turn left, and move forward again [TEST]
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED);
      delay(500);
      robotStop();
      turnLeft();
      robotStop();
      setMotors(DRIVE_SPEED, DRIVE_SPEED);
      delay(800);
    }

  }
  else {  // Dead End Logic: If surrounded by walls, reverse and turn around (180 degrees)
    reverseBackwards();
    robotStop();
    turnAroundFromLeft();
    robotStop();
  }
}

const unsigned long STUCK_TIMEOUT = 1500;   // This is how long the sensor readings can remain unchanged until the code checks if the robot is stuck (1.5 seconds / 1500 ms)
const int STUCK_TOLERANCE = 15;             // This is our tolerance for how much of a difference the sensor readings can show while checkIfStuck() is true

int lastFrontDist = -1, lastRightDist = -1, lastLeftDist = -1;
unsigned long lastChangeTime = 0;

bool checkIfStuck() {
  // If the differnece between last sensor value and present sensor value changed more than tolerance (15), reset the timer and set checkIfStuck False
  if (abs(frontDist - lastFrontDist) > STUCK_TOLERANCE ||
      abs(rightDist - lastRightDist) > STUCK_TOLERANCE ||
      abs(leftDist  - lastLeftDist)  > STUCK_TOLERANCE ||
      lastFrontDist == -1) {      // Don't trigger Stuck detection at launch of robot

    // Update last distance values with newer ones
      lastFrontDist = frontDist;
      lastRightDist = rightDist;
      lastLeftDist = leftDist;
      lastChangeTime = millis();    // Resets LastChangeTime when sensors are updated
      return false;
  }

  // If values haven't changed for 1.5 seconds, check how long its been since sensors were last updated
  if (millis() - lastChangeTime > STUCK_TIMEOUT) {
    lastChangeTime = millis();   // reset so it doesn't retrigger every loop
    return true;
  }

  return false;
}

// When called, the Robot reverses then turns right to until isStuck() becomes false 
void handleStuck() {
  robotStop();
  // Reverse the robot backwards
  reverseBackwards();
  robotStop();
  // if rightSensor is less than leftSensor, turn 375 degrees right
  if (rightDist < leftDist) {
    turnAroundFromRight(); // 180 degrees
    setMotors(-TURN_SPEED, TURN_SPEED); // 195 degrees
    delay(850);
  }
  // if leftSensor is less than rightSensor, turn 375 degrees left
  else if (leftDist < rightDist) {
    turnAroundFromLeft(); // 180 degrees
    setMotors(TURN_SPEED, -TURN_SPEED); // 195 degrees
    delay(850);
  }
  // else:
  robotStop();

}

void setup() {
  Serial.begin(9600);

  WDT.begin(4000); // Start Watchdog Timer for 4 seconds

  // Call Wire1
  Wire1.begin();
  Modulino.begin(Wire1);
  Wire1.setClock(400000);

  // Start all sensors to calulate distances (mm)
  switchSensor(0);        // Switch to Sensor 0 to calculate rightDist
  rightSensor.begin();

  switchSensor(1);        // Switch to Sensor 1 to calculate frontDist
  frontSensor.begin();

  switchSensor(2);        // Switch to Sensor 2 to calculate leftDist
  leftSensor.begin();

  // Make robot stop until sensors data is read by decideMovement()
  robotStop();
}

void loop() {
  // Obtain distance values from sensors
  readSensors();

  // Update Wall states using distance values
  updateWallStates();

  // Check if robot is stuck. If true, execute handleStuck()
  if (checkIfStuck()) {
    handleStuck();
  }
  // If the robot is not stuck, it will decide its next course of action
  else {
    decideMovement();
  }

  delay(10);

  // Reset the countdown back to 5 seconds
  WDT.refresh(); 
}
