#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 5
#define RST_PIN 22

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