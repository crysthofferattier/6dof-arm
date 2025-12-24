#include <Arduino.h>
#include <Servo.h>

const int baseServoPin = 3;
const int sholderServoPin = 5;
const int elbowServoPin = 6;

Servo base, sholder, elbow;

const int baseAngle = 0;
const int sholderAngle = 0;
const int elbowAngle = 0;

void setup() {
  base.attach(baseServoPin);
  sholder.attach(sholderServoPin);
  elbow.attach(elbowServoPin);
}

void loop() {
  base.write(90);
  sholder.write(90);
  elbow.write(90);
  delay(3000);
  base.write(baseAngle);
  sholder.write(sholderAngle);
  elbow.write(elbowAngle);
  delay(3000);
}