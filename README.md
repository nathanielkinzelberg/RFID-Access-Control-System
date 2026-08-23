# Embedded RFID Access Control System

A complete embedded access-control system built from scratch as a portfolio project. The ESP32 handles all real-time hardware control; the Raspberry Pi 5 handles logging, administration, and the web dashboard.

> **Status:** In progress — Phase 1 (GPIO Basics)

## Progress

| Phase | Title                      | Status   |
|-------|----------------------------|----------|
| 0     | Dev Environment            | Complete |
| 1     | GPIO Basics (LED + Button) | In Progress |
| 2     | RC522 RFID Reader          | Not Started |
| 3     | Authorization Logic        | Not Started |
| 4     | Status LEDs                | Not Started |
| 5     | Buzzer                     | Not Started |
| 6     | Servo Lock                 | Not Started |
| 7     | OLED Display               | Not Started |
| 8     | Firmware Architecture      | Not Started |
| 9–25  | ...                        | Not Started |

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

| Component         | Role                                      |
|-------------------|-------------------------------------------|
| ESP32 DevKit      | Main firmware controller                  |
| RC522 RFID module | Reads card UIDs via SPI                   |
| SG90 servo        | Physical lock actuator                    |
| 0.96" OLED        | User-facing status display (I2C)          |
| Green LED         | Access granted indicator                  |
| Red LED           | Access denied indicator                   |
| Active buzzer     | Audible feedback                          |
| Resistors         | Current limiting for LEDs                 |
| Raspberry Pi 5    | Linux backend, database, dashboard        |

---

## Firmware Architecture

*(Filled in during Phase 8)*

---

## Communication Protocol

*(Filled in during Phase 12)*

---

## Software Stack

| Layer      | Technology                        |
|------------|-----------------------------------|
| Firmware   | C/C++, PlatformIO, ESP-IDF/Arduino |
| Pi backend | Python 3, Flask/FastAPI            |
| Database   | SQLite                             |
| Dashboard  | HTML/CSS/JS (minimal)              |
| OS (Pi)    | Raspberry Pi OS (64-bit)           |

---

## Wiring Diagrams

See [`docs/wiring/`](docs/wiring/) for per-phase wiring tables.

---

## Build Instructions

*(Filled in once the project is complete)*

---

## Demo

*(Photos and video added after Phase 23)*

---

## Testing

See [`tests/test_plan.md`](tests/test_plan.md) for the full test matrix.

---

## Security Considerations

*(Filled in during Phase 21)*

---

## Challenges

*(Filled in during development)*

---

## What I Learned

*(Filled in during Phase 23)*

---

## Future Improvements

*(Filled in during Phase 23)*

---

## Project Journal

Detailed build notes for each phase live in [`docs/journal/`](docs/journal/).
