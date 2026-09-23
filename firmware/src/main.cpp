#include "AccessController.h"
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  accessInit();
}

void loop() {
  accessUpdate();
}