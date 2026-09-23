#include "Buzzer.h"
#include <Arduino.h>

void buzzerInit() {
  pinMode(13, OUTPUT);
}


void beepAccessGranted() {
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}

void beepAccessDenied() {
  for(int i = 0; i < 5; i++){
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
}

void beepLock() {
    for(int i = 0; i < 7; i++){
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}


