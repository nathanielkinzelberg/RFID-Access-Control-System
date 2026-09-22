#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <ESP32Servo.h>
#include <Wire.h>

#define SS_PIN 5
#define RST_PIN 22


MFRC522 scanTing(SS_PIN, RST_PIN); // Create MFRC522 instance thats global

// Struct to hole the UID + name + byte size for each Authorized User.
struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};

Servo myServo; // Create Servo object to control a servo

authorizedUser authorizedUsers[] = {
  {{0xC7, 0xFA, 0x4D, 0x07, 0x00, 0x00, 0x00}, 4, "Blank Kit Card"},
  {{0x04, 0x27, 0x5A, 0x0A, 0x0A, 0x1F, 0x91}, 7, "Icon Card"}
};

String lookup(byte* uid, byte uidSize){
  for(int i = 0; i < sizeof(authorizedUsers) / sizeof(authorizedUsers[0]); i++){
    if(uidSize == authorizedUsers[i].uidSize){
      if(memcmp(uid, authorizedUsers[i].uid, uidSize) == 0){
        return authorizedUsers[i].name;
      }
    }
  }
  return "Unknown";
}

void setup() {
  Serial.begin(115200); // starts serial so we can print to monito
  SPI.begin(18, 19, 23, 5); // Starts SPI bus
  scanTing.PCD_Init(); // Init MFRC522
  byte version = scanTing.PCD_ReadRegister(scanTing.VersionReg); // Read version register
  Serial.print("MFRC522 Version: 0x");
  Serial.println(version, HEX);
  pinMode(25, OUTPUT); // Set pin 25 as output for the Green LED 
  pinMode(26, OUTPUT); // Set pin 26 as output for the Red LED
  pinMode(13, OUTPUT); // Set pin 13 as output for the Active Buzzer
  pinMode(4, INPUT_PULLUP); // Set pin 4 as output for the locking button
  myServo.attach(14); // Attach servo to pin 14

 }

void loop () {

    if(!digitalRead(4)) { // If the locking button is pressed
    myServo.write(0); // Move the servo back to 0 degrees

    /* Locking Beeps: Flashed red and beeps twice quickly */

    digitalWrite(26, HIGH); // Turn on the Red LED
    for(int i = 0; i < 5; i++){
      digitalWrite(13, HIGH); // Turn on the Active Buzzer
      delay(50); // Wait 50 milliseconds
      digitalWrite(13, LOW); // Turn off the Active Buzzer
      delay(50); // Wait 50 milliseconds
    }
    digitalWrite(26, LOW); // Turn off the Red LED

  }

  if(!scanTing.PICC_IsNewCardPresent()) { // If no new card is present, return
    return;
  }

  if(!scanTing.PICC_ReadCardSerial()) { // If we can't read the card, return
    return;
  }

  Serial.print(F("Card UID:")); // Print UID
  for (byte i = 0; i < scanTing.uid.size; i++) {
    Serial.print(scanTing.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(scanTing.uid.uidByte[i], HEX);
  }

  Serial.println();

  String user = lookup(scanTing.uid.uidByte, scanTing.uid.size); // Lookup the name of the user based on the UID 


  if(user != "Unknown"){ // If the card is authorized
    Serial.print(F("Authorized User: ")); // Print the name of the user
    Serial.println(user);
    digitalWrite(25, HIGH); // Turn on the Green LED
    digitalWrite(13, HIGH); // Turn on the Active Buzzer
    myServo.write(100); // Move the servo to 180 degrees
    delay(2000); // Wait 2 seconds after an access granted
    digitalWrite(13, LOW); // Turn off the Active Buzzer
    digitalWrite(25, LOW); // Turn off the Green LED
    while(digitalRead(4)){ // Wait until the locking button is pressed
      continue; // Keep Looping Until Button is Pressed
    }
    myServo.write(0); // Move the servo back to 0 degrees

    /* Locking Beeps: Flashed red and beeps twice quickly */
    
    digitalWrite(26, HIGH); // Turn on the Red LED
    for(int i = 0; i < 5; i++){
      digitalWrite(13, HIGH); // Turn on the Active Buzzer
      delay(50); // Wait 50 milliseconds
      digitalWrite(13, LOW); // Turn off the Active Buzzer
      delay(50); // Wait 50 milliseconds
    }
    digitalWrite(26, LOW); // Turn off the Red LED

  } else {
    Serial.println(F("Unauthorized User: Access Denied")); // If the card is not authorized, print unauthorized user
    digitalWrite(26, HIGH); // Turn on the Red LED
    for(int i = 0; i < 5; i++){
      digitalWrite(13, HIGH); // Turn on the Active Buzzer
      delay(200); // Wait 100 milliseconds
      digitalWrite(13, LOW); // Turn off the Active Buzzer
      delay(200); // Wait 100 milliseconds
    }
    digitalWrite(26, LOW); // Turn off the Red LED
  }


} 




