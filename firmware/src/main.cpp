#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 5
#define RST_PIN 22


MFRC522 scanTing(SS_PIN, RST_PIN); // Create MFRC522 instance thats global


void setup() {
  Serial.begin(115200); // starts serial so we can print to monito
  SPI.begin(18, 19, 23, 5); // Starts SPI bus
  scanTing.PCD_Init(); // Init MFRC522
  byte version = scanTing.PCD_ReadRegister(scanTing.VersionReg); // Read version register
  Serial.print("MFRC522 Version: 0x");
  Serial.println(version, HEX);
}

void loop () {

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

} 