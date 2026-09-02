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
| 0     | Dev Environment              | Complete    |
| 1     | GPIO Basics (LED + Button)   | Complete    |
| 2     | RC522 RFID Reader            | Complete    |
| 3     | Authorization Logic          | Complete    |
| 4     | Status LEDs                  | In Progress |
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
| 23    | GitHub Portfolio + Portfolio Site | Not Started |
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

## End of Phase Checklist

At the end of every phase, before the user commits, always update:
1. **CLAUDE.md** — mark the phase Complete in the Phase Tracking table, mark next phase In Progress
2. **README.md** — update the status line and Progress table
3. **docs/journal/phase_NN_*.md** — fill in all sections: dates, hardware, wiring, concepts learned, problems encountered, multimeter work, final code reference
4. **docs/hardware/components.md** — fill in any newly confirmed hardware details
5. **docs/wiring/README.md** — add any new pin assignments to the global pin reference table

## Phase 23 — GitHub Portfolio + Portfolio Site

When Phase 23 is reached, do the following in order:

### 1. GitHub
- Confirm the repo is public at: https://github.com/nathanielkinzelberg/RFID-Access-Control-System
- Verify README.md is polished and complete

### 2. Portfolio Site
- Portfolio lives at: `~/portfolio/index.html`
- Portfolio CLAUDE.md is at: `~/portfolio/CLAUDE.md` — read it before touching anything
- Add a project card to the **Personal Projects** section (`#personal`)
- Add an entry to the **All Projects** dropdown
- Use the `badge-progress` class on the `<h3>` if still in progress; remove it when complete

**Card template to use:**
```html
<div class="card">
  <div class="card-header">
    <i class="fa-solid fa-key card-icon"></i>
  </div>
  <h3>RFID Access Control System</h3>
  <p>Physical door-access control system built from scratch. ESP32 handles real-time hardware: RFID reader, servo lock, OLED, LEDs, and buzzer. Raspberry Pi runs logging, a REST API, and a web dashboard. Built phase by phase across 25 stages.</p>
  <div class="card-tags"><span>C++</span><span>ESP32</span><span>Embedded</span><span>Python</span><span>Raspberry Pi</span><span>Linux</span></div>
  <div class="card-footer">
    <a href="https://github.com/nathanielkinzelberg/RFID-Access-Control-System" class="card-btn" target="_blank" rel="noopener">
      <i class="fa-brands fa-github"></i> GitHub
    </a>
  </div>
</div>
```

**Portfolio tone rules (from portfolio/CLAUDE.md):**
- No em-dashes. Use a colon or a new sentence.
- No corporate/AI language ("hands-on", "proven ability", etc.)
- Short and conversational
- Commit the portfolio after adding the card

---

## Key Rules for Claude

- Never generate the entire finished project at once.
- Work one phase at a time and wait for "Phase N complete." before moving on.
- Ask Nathaniel to write code first; give hints before full solutions.
- Always include wiring tables before any hardware connection step.
- Flag 3.3V vs 5V mismatches, current limits, and servo power warnings explicitly.
- Update the Phase Tracking table above when a phase changes status.
- Remind Nathaniel to commit at the end of each phase.
