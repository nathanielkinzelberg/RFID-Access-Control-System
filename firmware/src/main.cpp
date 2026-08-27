#include <Arduino.h>
  // Used for the millis() function to get the current time in milliseconds since the program started running.
  // Specifically for the Morse Code Blinking project, this allows for precise timing of the LED blinks to represent Morse code signals.
  unsigned long lastTime = 0;
  int step = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT_PULLDOWN);

  // Initialize the light to be on at the start of the program
  digitalWrite(2, HIGH);
  lastTime = millis();
}

void loop () {

  
}