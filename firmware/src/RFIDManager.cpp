#include "RFIDManager.h"
#include <MFRC522.h>
#include <Arduino.h>
#include <SPI.h>

#define SS_PIN 5
#define RST_PIN 22

static MFRC522 scanTing(SS_PIN, RST_PIN);
struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};


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

/* Initializes the RFID scanner */
void scanInit() {
    SPI.begin(18, 19, 23, 5);
    scanTing.PCD_Init();
    byte version = scanTing.PCD_ReadRegister(scanTing.VersionReg);

}

/* Checks if a new card is present */
bool isCardPresent() {
    return scanTing.PICC_IsNewCardPresent() && scanTing.PICC_ReadCardSerial();
}

/* Gets the UID of the currently scanned card */
String getCardUID() {
    return lookup(scanTing.uid.uidByte, scanTing.uid.size);
}

