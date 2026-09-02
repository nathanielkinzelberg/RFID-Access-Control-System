# Phase 3 — Authorization Logic

**Date started:** 2026-09-02
**Date completed:** 2026-09-03

---

## Goal

Compare scanned UIDs against a list of authorized users and print GRANTED or DENIED to serial.

---

## Hardware Used

- ESP32 DevKit V1
- RC522 RFID module (same wiring as Phase 2)
- Blank RC522 kit card (4-byte MIFARE)
- Icon Gym card (7-byte MIFARE)
- RC522 kit key fob (used as unauthorized test card)

---

## Key Concepts Learned

### Structs for Organizing Data

A struct groups related fields into a single named type. Instead of keeping three separate arrays (one for UIDs, one for sizes, one for names) and keeping them in sync manually, a struct bundles them together so each user is one self-contained unit:

```cpp
struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};
```

This makes the code easier to read, extend, and maintain.

### uidSize Field

MIFARE UIDs come in two sizes: 4 bytes or 7 bytes. Storing the UID in a fixed `byte uid[7]` array works for both, but the comparison function needs to know how many bytes are actually valid. A separate `uidSize` field records this per entry — 4-byte cards store `4`, 7-byte cards store `7`. The remaining slots in the array are padded with `0x00` on the right.

### Byte Arrays vs Strings

UIDs are raw byte arrays, not strings. The hex representation (`C7 FA 4D 07`) is just how we print them for readability. Comparing two byte arrays with `==` does not work in C++ — it compares pointers, not contents. `memcmp()` is the correct tool: it compares two byte arrays element by element and returns 0 if they are identical.

```cpp
memcmp(uid, authorizedUsers[i].uid, uidSize) == 0
```

### Lookup Function Pattern

Rather than putting the comparison logic inside `loop()`, it lives in a dedicated `lookup()` function that takes the scanned UID and size and returns the user's name or `"Unknown"`. This keeps `loop()` readable and puts the comparison logic in one place.

```cpp
String lookup(byte* uid, byte uidSize) { ... }
```

### Calling lookup() Once

The result of `lookup()` is stored in a local variable before the `if` check. Calling it twice — once to check and once to get the name — is wasteful and harder to read.

```cpp
String user = lookup(scanTing.uid.uidByte, scanTing.uid.size);
if (user != "Unknown") { ... }
```

### File Order Matters in C++

The compiler reads top to bottom. `lookup()` must be defined before `setup()` and `loop()` or the compiler won't know it exists when `loop()` calls it.

---

## Serial Output

```
MFRC522 Version: 0x18
Card UID: C7 FA 4D 07
Authorized User: Blank Kit Card
Card UID: 04 27 5A 0A 0A 1F 91
Authorized User: Icon Bomboclat Card
Card UID: 04 2A 38 07
Unauthorized User: Access Denied
```

---

## Authorized Users List

| UID                         | Size | Name                 |
|-----------------------------|------|----------------------|
| C7 FA 4D 07                 | 4    | Blank Kit Card       |
| 04 27 5A 0A 0A 1F 91        | 7    | Icon Bomboclat Card  |

---

## Test Results

| Card         | Expected        | Actual          | Pass? |
|--------------|-----------------|-----------------|-------|
| Kit card     | GRANTED         | GRANTED         | ✓     |
| Gym card     | GRANTED         | GRANTED         | ✓     |
| Kit key fob  | DENIED          | DENIED          | ✓     |

---

## Problems Encountered

### Garbage characters in serial output
**Symptom:** `����������` appeared mid-output occasionally.
**Cause:** USB serial connection briefly lost sync — not a code bug.
**Fix:** No fix needed. Output corrected itself on the next print. Consistent baud rate (115200) on both sides is confirmed correct.

### Calling lookup() twice
**Symptom:** First attempt checked `lookup() != "Unknown"` and then called `lookup()` again to get the name — redundant and slower.
**Fix:** Stored the result in a `String user` variable before the `if` check.

---

## Final Code

```cpp
#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 scanTing(SS_PIN, RST_PIN);

struct authorizedUser {
  byte uid[7];
  byte uidSize;
  String name;
};

authorizedUser authorizedUsers[] = {
  {{0xC7, 0xFA, 0x4D, 0x07, 0x00, 0x00, 0x00}, 4, "Blank Kit Card"},
  {{0x04, 0x27, 0x5A, 0x0A, 0x0A, 0x1F, 0x91}, 7, "Icon Bomboclat Card"}
};

String lookup(byte* uid, byte uidSize) {
  for (int i = 0; i < sizeof(authorizedUsers) / sizeof(authorizedUsers[0]); i++) {
    if (uidSize == authorizedUsers[i].uidSize) {
      if (memcmp(uid, authorizedUsers[i].uid, uidSize) == 0) {
        return authorizedUsers[i].name;
      }
    }
  }
  return "Unknown";
}

void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23, 5);
  scanTing.PCD_Init();
  byte version = scanTing.PCD_ReadRegister(scanTing.VersionReg);
  Serial.print("MFRC522 Version: 0x");
  Serial.println(version, HEX);
}

void loop() {
  if (!scanTing.PICC_IsNewCardPresent()) return;
  if (!scanTing.PICC_ReadCardSerial()) return;

  Serial.print(F("Card UID:"));
  for (byte i = 0; i < scanTing.uid.size; i++) {
    Serial.print(scanTing.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(scanTing.uid.uidByte[i], HEX);
  }
  Serial.println();

  String user = lookup(scanTing.uid.uidByte, scanTing.uid.size);
  if (user != "Unknown") {
    Serial.print(F("Authorized User: "));
    Serial.println(user);
    delay(2000);
  } else {
    Serial.println(F("Unauthorized User: Access Denied"));
    delay(2000);
  }
}
```

---

## Git Commit

```
Phase 3: Authorization logic with struct-based user table
```
