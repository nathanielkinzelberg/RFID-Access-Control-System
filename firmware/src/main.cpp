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


/* MORSE-CODE Blinking short
Short Blink
 digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
  delay(100);
  
  Long Blink
  digitalWrite(2, HIGH);
  delay(700);
  delay(100);
*/

/* NATE in Morse Code

void loop() {
  // N
  digitalWrite(2, HIGH);
  delay(700);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(300);
  
  //Space
  digitalWrite(2, LOW);
  delay(1000);

  // A
  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(700);

  //Space
  digitalWrite(2, LOW);
  delay(1000);

  //T
  digitalWrite(2, HIGH);
  delay(700);
  
  //Space
  digitalWrite(2, LOW);
  delay(1000);

  //E
  digitalWrite(2, HIGH);
  delay(300);

  //2 Second Break
  digitalWrite(2, LOW);
  delay(2000);
}

*/

/* Button-Controlled Blinking 

void loop() {
  // Check if the input pin is HIGH aka Button is being pressed
  if (digitalRead(4) == HIGH) {
    // If the input pin is HIGH, turn on the output pin
    digitalWrite(2, HIGH);
  } else {
    // If the input pin is LOW (button unpressed), turn off the output pin
    digitalWrite(2, LOW);
  }
}

*/



void loop() {

  /* Initialization of the light to be pasted into setup. Not Loop.
    digitalWrite(2, HIGH);
    lastTime = millis();
  */

  // N: On_700ms, Off_100ms, On_300ms. Steps 0, 1, 2

  if((millis() - lastTime >= 700) && (step == 0)) {
    // Turn off the LED after 700 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }

  if((millis() - lastTime >= 100) && (step == 1)) {
    // Turn on the LED after 100 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step++;
  }

  if((millis() - lastTime >= 300) && (step == 2)) {
    // Turn off the LED after 300 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }

  

  // Space: Off_1000ms. Step 3

  if((millis() - lastTime >= 1000) && (step == 3)) {
    // Turn on the LED after 1000 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step++;
  }



  // A: On_300ms, Off_100ms, On_700ms. Steps 4, 5, 6

  if((millis() - lastTime >= 300) && (step == 4)) {
    // Turn off the LED after 300 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }

  if((millis() - lastTime >= 100) && (step == 5)) {
    // Turn on the LED after 100 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step++;
  }

  if((millis() - lastTime >= 700) && (step == 6)) {
    // Turn off the LED after 700 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }



  // Space: Off_1000ms. Step 7

  if((millis() - lastTime >= 1000) && (step == 7)) {
    // Turn on the LED after 1000 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step++;
  }



  // T: On_700ms. Step 8

  if((millis() - lastTime >= 700) && (step == 8)) {
    // Turn off the LED after 700 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }

  

  // Space: Off_1000ms. Step 9

  if((millis() - lastTime >= 1000) && (step == 9)) {
    // Turn on the LED after 1000 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step++;
  }



  // E: On_300ms. Step 10

  if((millis() - lastTime >= 300) && (step == 10)) {
    // Turn off the LED after 300 milliseconds
    digitalWrite(2, LOW);
    lastTime = millis();
    step++;
  }



  // 2 Second Break: Step 11

  if((millis() - lastTime >= 2000) && (step == 11)) {
    // Turn on the LED after 2000 milliseconds
    digitalWrite(2, HIGH);
    lastTime = millis();
    step = 0;
  }
}





