# CLAUDE.md — RFID Access Control System

This file tells Claude Code how to work with this repository.

## Project Overview

A multi-phase embedded RFID access-control system built as a portfolio project.

- **ESP32** handles all real-time hardware (RFID, servo lock, OLED, buzzer, LEDs)
- **Raspberry Pi 5** handles logging, administration, SQLite database, REST API, and web dashboard
- Communication between them via UART (primary) and Wi-Fi (secondary)

## Repository Layout

```
embedded-rfid-access-control/
├── firmware/               # ESP32 C/C++ code (PlatformIO project)
│   ├── src/
│   ├── include/
│   └── platformio.ini
├── pi/                     # Raspberry Pi Python backend
│   ├── serial_listener/
│   ├── api/
│   └── dashboard/
├── docs/                   # All project documentation
│   ├── journal/            # Per-phase build journal entries
│   ├── wiring/             # Wiring tables and diagrams
│   ├── hardware/           # Component datasheets, notes
│   └── decisions/          # Architecture decision records
├── tests/                  # Test plans and results
├── README.md
├── CLAUDE.md               # This file
└── .gitignore
```

## Development Workflow

- **Firmware:** VS Code + PlatformIO. Build/flash/monitor from PlatformIO sidebar or CLI.
- **Pi backend:** Python 3, standard library + Flask/FastAPI + SQLite.
- **Phases:** Work one phase at a time. Do not advance until the current phase is confirmed working.
- **Commits:** One commit per completed phase minimum. Commit message format: `Phase N: short description`.

## Phase Tracking

| Phase | Title                        | Status      |
|-------|------------------------------|-------------|
| 0     | Dev Environment              | In Progress |
| 1     | GPIO Basics (LED + Button)   | Not Started |
| 2     | RC522 RFID Reader            | Not Started |
| 3     | Authorization Logic          | Not Started |
| 4     | Status LEDs                  | Not Started |
| 5     | Buzzer                       | Not Started |
| 6     | Servo Lock                   | Not Started |
| 7     | OLED Display                 | Not Started |
| 8     | Firmware Architecture        | Not Started |
| 9     | Persistent Authorized Users  | Not Started |
| 10    | Admin Mode                   | Not Started |
| 11    | Failed Login Protection      | Not Started |
| 12    | ESP32 ↔ Pi Communication     | Not Started |
| 13    | Raspberry Pi Linux Service   | Not Started |
| 14    | SQLite Database              | Not Started |
| 15    | REST API                     | Not Started |
| 16    | Web Dashboard                | Not Started |
| 17    | ESP32 Wi-Fi                  | Not Started |
| 18    | Fault Handling               | Not Started |
| 19    | Hardware Debugging           | Not Started |
| 20    | FreeRTOS Upgrade             | Not Started |
| 21    | Security Review              | Not Started |
| 22    | Testing                      | Not Started |
| 23    | GitHub Portfolio             | Not Started |
| 24    | Résumé Bullets               | Not Started |
| 25    | Interview Prep               | Not Started |

## Hardware

| Component        | Notes                                      |
|------------------|--------------------------------------------|
| ESP32 DevKit     | 3.3V logic — do not connect 5V signals     |
| RC522 RFID       | SPI, 3.3V                                  |
| SG90 Servo       | Power from external 5V, not ESP32 3.3V pin |
| 0.96" OLED       | I2C, typically address 0x3C                |
| Active buzzer    | Confirm polarity                           |
| Green/Red LEDs   | Always use current-limiting resistor       |
| Raspberry Pi 5   | 3.3V GPIO logic                            |

## Key Rules for Claude

- Never generate the entire finished project at once.
- Work one phase at a time and wait for "Phase N complete." before moving on.
- Ask Nathaniel to write code first; give hints before full solutions.
- Always include wiring tables before any hardware connection step.
- Flag 3.3V vs 5V mismatches, current limits, and servo power warnings explicitly.
- Update the Phase Tracking table above when a phase changes status.
- Remind Nathaniel to commit at the end of each phase.
