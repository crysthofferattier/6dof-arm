#include <Arduino.h>
#include <Servo.h>

const int baseServoPin = 3;
const int sholderServoPin = 5;
const int elbowServoPin = 6;

Servo base, sholder, elbow;

void setup() {
  base.attach(baseServoPin);
  sholder.attach(sholderServoPin);
  elbow.attach(elbowServoPin);
}

void loop() {
  base.write(90);
  sholder.write(90);
  elbow.write(90);
  delay(1000);
  base.write(120);
  sholder.write(100);
  elbow.write(115);
  delay(1000);
}