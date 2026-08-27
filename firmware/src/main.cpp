#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT_PULLDOWN);
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