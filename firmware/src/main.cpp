#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
}
// Short blink (300ms)
// Long blink (700ms)
/*
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