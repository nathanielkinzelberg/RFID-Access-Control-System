#include "LockController.h"
#include <Arduino.h>
#include <ESP32Servo.h>

static Servo myServo;

void lockInit() {
  pinMode(4, INPUT_PULLUP);
  myServo.attach(14);
  myServo.write(0);
}

void lockClose() {
  myServo.write(0);
}

void lockOpen() {
    myServo.write(100);
}