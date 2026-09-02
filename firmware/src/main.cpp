#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 5
#define RST_PIN 22


MFRC522 scanTing(SS_PIN, RST_PIN); // Create MFRC522 instance thats global

// Struct to hole the UID + name + byte size for each Authorized User.
struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};

authorizedUser authorizedUsers[] = {
  {{0xC7, 0xFA, 0x4D, 0x07, 0x00, 0x00, 0x00}, 4, "Blank Kit Card"},
  {{0x04, 0x27, 0x5A, 0x0A, 0x0A, 0x1F, 0x91}, 7, "Icon Bomboclat Card"}
};

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




bool lookup(int id){
  for(int i = 0; i < sizeOf(authorizedUsers); i++){
    if(id == authorizedUsers[i].uid){
      return true;
    }
  }
  return false;
}