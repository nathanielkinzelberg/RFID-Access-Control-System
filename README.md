# Embedded RFID Access Control System

A complete embedded access-control system built from scratch as a portfolio project. The ESP32 handles all real-time hardware control; the Raspberry Pi 5 handles logging, administration, and the web dashboard.

> **Status:** In progress — Phase 8 (Firmware Architecture)

## Progress

| Phase | Title                      | Status      |
|-------|----------------------------|-------------|
| 0     | Dev Environment            | Complete    |
| 1     | GPIO Basics (LED + Button) | Complete    |
| 2     | RC522 RFID Reader          | Complete    |
| 3     | Authorization Logic        | Complete    |
| 4     | Status LEDs                | Complete    |
| 5     | Buzzer                     | Complete    |
| 6     | Servo Lock                 | Complete    |
| 7     | OLED Display               | Complete    |
| 8     | Firmware Architecture      | Not Started |
| 9     | Persistent Authorized Users| Not Started |
| 10    | Admin Mode                 | Not Started |
| 11    | Failed Login Protection    | Not Started |
| 12    | ESP32 ↔ Pi Communication   | Not Started |
| 13    | Raspberry Pi Linux Service | Not Started |
| 14    | SQLite Database            | Not Started |
| 15    | REST API                   | Not Started |
| 16    | Web Dashboard              | Not Started |
| 17    | ESP32 Wi-Fi                | Not Started |
| 18    | Fault Handling             | Not Started |
| 19    | Hardware Debugging         | Not Started |
| 20    | FreeRTOS Upgrade           | Not Started |
| 21    | Security Review            | Not Started |
| 22    | Testing                    | Not Started |
| 23    | GitHub Portfolio + Portfolio Site | Not Started |
| 24    | Résumé Bullets             | Not Started |
| 25    | Interview Prep             | Not Started |

---

## Overview

This project implements a physical door-access control system using RFID cards. When an authorized card is scanned, a servo motor unlocks a door, the OLED display shows the user's name, and the Raspberry Pi logs the event to a SQLite database visible on a web dashboard.

Unauthorized cards trigger a denied state — red LED, warning buzzer, OLED denial message, and the lock stays closed. After repeated failed attempts, the system enters a temporary lockout.

---

## Features

- RFID card scanning via RC522 over SPI
- Real-time access grant/deny with servo lock, LEDs, buzzer, and OLED feedback
- Persistent authorized-user storage on ESP32 flash (NVS)
- Admin RFID card for adding/removing users without reflashing
- Failed-attempt rate limiting and lockout
- UART + Wi-Fi communication to Raspberry Pi
- SQLite access-event logging
- REST API for querying events and managing users
- Web dashboard with live access log
- Fault tolerance: ESP32 controls the lock even if the Pi is offline
- FreeRTOS multi-task firmware architecture

---

## System Architecture

```
               RFID Card
                   │
                   ▼
              RC522 Reader
                   │ SPI
                   ▼
                 ESP32
          ┌────────┼────────┐
          ▼        ▼        ▼
        OLED     Servo    LED/Buzzer
                   │
                   ▼
              Door Lock
                   │
              UART / Wi-Fi
                   │
                   ▼
             Raspberry Pi 5
                   │
          ┌────────┼────────┐
          ▼        ▼        ▼
       SQLite    REST API   Logs
                   │
                   ▼
             Web Dashboard
```

---

## Hardware

| Component         | Role                                      | Notes                        |
|-------------------|-------------------------------------------|------------------------------|
| ESP32 DevKit V1   | Main firmware controller                  | 3.3V logic, 240MHz dual-core |
| RC522 RFID module | Reads card UIDs via SPI                   | 3.3V only — clone module, MOSI/MISO labels swapped |
| SG90 servo        | Physical lock actuator                    | External 5V power required   |
| 0.96" OLED        | User-facing status display (I2C)          | SSD1306, address 0x3C        |
| Green LED         | Access granted indicator                  | 220Ω resistor                |
| Red LED           | Access denied indicator                   | 220Ω resistor                |
| Active buzzer     | Audible feedback                          |                              |
| Raspberry Pi 5    | Linux backend, database, dashboard        | 3.3V GPIO logic              |

---

## Firmware Architecture

*(Filled in during Phase 8)*

---

## Communication Protocol

*(Filled in during Phase 12)*

---

## Software Stack

| Layer      | Technology                         |
|------------|------------------------------------|
| Firmware   | C/C++, PlatformIO, Arduino framework |
| Pi backend | Python 3, Flask/FastAPI            |
| Database   | SQLite                             |
| Dashboard  | HTML/CSS/JS                        |
| OS (Pi)    | Raspberry Pi OS (64-bit)           |

---

## Wiring

See [`docs/wiring/README.md`](docs/wiring/README.md) for the global pin reference and per-phase wiring tables.

**Current pin assignments:**

| GPIO | Function       | Phase |
|------|----------------|-------|
| 2    | LED output     | 1     |
| 4    | Button input   | 1     |
| 5    | RC522 SDA (SS) | 2     |
| 18   | RC522 SCK      | 2     |
| 19   | RC522 MISO     | 2     |
| 22   | RC522 RST      | 2     |
| 23   | RC522 MOSI     | 2     |

---

## Challenges

Real problems encountered during the build:

**Phase 0**
- Serial monitor showing no output — baud rate mismatch (monitor defaulted to 9600, ESP32 transmitting at 115200)
- Upload failing at baud rate change — USB cable couldn't sustain 460800 baud, fixed by setting `upload_speed = 115200`
- Permission denied on `/dev/ttyUSB0` — user not in `dialout` group

**Phase 1**
- LED didn't light up on first try — wiring was correct but GPIO pin was never configured in code

**Phase 2**
- `version 0x0` and boot loop — SPI communication failing completely due to loose breadboard connections
- Clone RC522 module returns firmware version `0x18` instead of the expected `0x91`/`0x92` — works fine, non-standard version is normal for clones
- MOSI and MISO silk-screen labels are **physically swapped** on the clone RC522 module — wires must be crossed to match

---

## Skills Covered

See [`docs/skills.md`](docs/skills.md) for the full breakdown by phase.

Topics include: SPI, I2C, UART, PWM, FreeRTOS, GPIO, state machines, SQLite, REST APIs, systemd, threat modeling, and hardware debugging.

---

## Testing

See [`tests/test_plan.md`](tests/test_plan.md) for the full test matrix (14 test cases).

---

## Security Considerations

*(Filled in during Phase 21)*

Key known limitation: RFID UIDs can be cloned with cheap hardware. This is documented and accepted for a dev/portfolio system — the threat model will be fully analyzed in Phase 21.

---

## Project Journal

Detailed build notes, wiring tables, concepts learned, and problems encountered for each phase live in [`docs/journal/`](docs/journal/).

---

## Demo

*(Photos and video added after Phase 23)*

---

## Build Instructions

*(Filled in once the project is complete)*
