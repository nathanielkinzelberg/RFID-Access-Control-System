# Phase 2 — RC522 RFID Reader

**Date started:** 2026-08-27
**Date completed:**

---

## Goal

Connect the RC522 RFID module over SPI and read card UIDs printed to serial.

---

## Hardware Used

- ESP32 DevKit V1
- RC522 RFID module (pins: SDA, SCK, MOSI, MISO, IRQ, GND, RST, 3.3)
- RFID card(s) and/or fob(s)
- Breadboard + male-to-female jumper wires (breadboard used as middleman, no female-to-female available)
- MFRC522 library by Miguel Balboa (miguelbalboa/MFRC522@^1.4.11)

---

## Wiring

| RC522 Pin | ESP32 Pin | Notes                  |
|-----------|-----------|------------------------|
| SDA       | D5        | Chip select            |
| SCK       | D18       | Clock                  |
| MOSI      | D23       | ESP32 → RC522          |
| MISO      | D19       | RC522 → ESP32          |
| IRQ       | —         | Not used in this phase |
| GND       | GND       |                        |
| RST       | D22       | Reset                  |
| 3.3       | 3V3       | 3.3V ONLY — not 5V     |

> Pin order matches the physical board layout (left to right).
> Connected via breadboard as middleman using male-to-female wires — female-to-female wires not available at time of wiring.

> **Warning:** RC522 is a 3.3V device. Connecting VCC to 5V will damage it.

---

## Key Concepts Learned

### SPI (Serial Peripheral Interface)
A 4-wire communication protocol for chips to talk to each other. The master controls the clock and decides when to communicate. The slave only responds when selected. Unlike UART, both sides share a clock wire so there's no baud rate to agree on.

### MOSI / MISO / SCLK / SS
- **MOSI** (Master Out Slave In): ESP32 sends data to RC522
- **MISO** (Master In Slave Out): RC522 sends data back to ESP32
- **SCLK**: Clock wire — pulses once per bit so both sides stay in sync
- **SS** (Slave Select): pulled LOW by the master to activate a specific device

### Full-Duplex Communication
SPI sends and receives simultaneously — MOSI and MISO carry data in both directions at the same time, on every clock pulse.

### Master vs Peripheral
The ESP32 is the master: it drives the clock and controls SS. The RC522 is the peripheral: it only talks when selected and only in sync with the clock.

### Sharing a SPI Bus (Multiple CS Lines)
Multiple SPI devices can share the same MOSI/MISO/SCLK wires. Each device gets its own SS pin. The master pulls one SS LOW at a time to select which device it's addressing.

### RFID UIDs — What They Are
Every RFID card or fob has a unique identifier (UID) burned in at manufacture — typically 4 or 7 bytes. When a card enters the RC522's field, it broadcasts its UID. The ESP32 reads it and can compare it against an authorized list.

### Why UID Alone Is Not Enough for High Security
UIDs can be cloned with cheap hardware in seconds. Anyone with a blank writable card and a $10 reader can copy a UID. For this project it's acceptable — the threat model section in Phase 21 covers this explicitly.


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
