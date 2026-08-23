# Phase 2 — RC522 RFID Reader

**Date started:**
**Date completed:**

---

## Goal

Connect the RC522 RFID module over SPI and read card UIDs printed to serial.

---

## Hardware Used

- ESP32 DevKit
- RC522 RFID module
- RFID card(s) and/or fob(s)
- Breadboard + jumper wires

---

## Wiring

| RC522 Pin | ESP32 Pin | Notes                  |
|-----------|-----------|------------------------|
| VCC       |           | 3.3V ONLY — not 5V     |
| GND       |           |                        |
| RST       |           |                        |
| SDA (SS)  |           | Chip select            |
| MOSI      |           |                        |
| MISO      |           |                        |
| SCK       |           |                        |
| IRQ       | —         | Not used in this phase |

> **Warning:** RC522 is a 3.3V device. Connecting VCC to 5V will damage it.

---

## Key Concepts Learned

### SPI (Serial Peripheral Interface)


### MOSI / MISO / SCLK / SS


### Full-Duplex Communication


### Master vs Peripheral


### Sharing a SPI Bus (Multiple CS Lines)


### RFID UIDs — What They Are


### Why UID Alone Is Not Enough for High Security


---

## Serial Output

```
RFID Card Detected
UID: A3 42 F1 91
```

---

## Problems Encountered

*(Document any wiring mistakes, logic errors, or unexpected behavior)*

---

## Multimeter Work

- Verified 3.3V on RC522 VCC: __ V
- Verified GND continuity:

---

## Git Commit

```
Phase 2: RC522 RFID reader over SPI — card UID printed to serial
```
