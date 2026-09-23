#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 scanTing(SS_PIN, RST_PIN);

struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};

Servo myServo;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

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

/* Outputs str to the OLED for "time" milliseconds at text size "size" */
void screenOutput(String str, int time, int size) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(str);
  display.display();
  delay(time);
}

void lock() {
  screenOutput("Locking...", 0, 2);
  myServo.write(0);

  digitalWrite(26, HIGH);
  for(int i = 0; i < 7; i++){
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
  screenOutput("Locked", 2000, 2);
  digitalWrite(26, LOW);
}

void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23, 5);
  scanTing.PCD_Init();
  byte version = scanTing.PCD_ReadRegister(scanTing.VersionReg);
  Serial.print("MFRC522 Version: 0x");
  Serial.println(version, HEX);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  myServo.attach(14);
  Wire.begin(21, 15);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {

  screenOutput("Please\nScan\nYour Card", 0, 2);

  if(!digitalRead(4)) {
    lock();
  }

  if(!scanTing.PICC_IsNewCardPresent()) {
    return;
  }

  if(!scanTing.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print(F("Card UID:"));
  for (byte i = 0; i < scanTing.uid.size; i++) {
    Serial.print(scanTing.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(scanTing.uid.uidByte[i], HEX);
  }
  Serial.println();

  String user = lookup(scanTing.uid.uidByte, scanTing.uid.size);

  if(user != "Unknown"){
    Serial.print(F("Authorized User: "));
    Serial.println(user);
    screenOutput("Opening...", 0, 2);
    digitalWrite(25, HIGH);
    digitalWrite(13, HIGH);
    myServo.write(100);
    delay(2000);
    digitalWrite(13, LOW);
    digitalWrite(25, LOW);
    screenOutput("Access Granted\nWelcome\n" + user, 0, 1);
    
    unsigned long startTime = millis();

    while(digitalRead(4)){
      if(millis() - startTime > 4000){
        screenOutput("Open", 0, 2);
      }
      continue;
    }

    lock();

  } else {
    Serial.println(F("Unauthorized User: Access Denied"));
    screenOutput("Access\nDenied", 0, 2);
    digitalWrite(26, HIGH);
    for(int i = 0; i < 5; i++){
      digitalWrite(13, HIGH);
      delay(250);
      digitalWrite(13, LOW);
      delay(250);
    }
    digitalWrite(26, LOW);
    screenOutput("Please\nTry Again", 2000, 2);
  }
}