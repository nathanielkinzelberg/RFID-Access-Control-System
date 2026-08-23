# ADR-001 — Split Responsibilities: ESP32 for Hardware, Pi for Backend

**Date:**
**Status:** Accepted

---

## Context

The system needs to control physical hardware (servo, LEDs, buzzer, RFID reader, OLED) in real time AND provide logging, a database, and a web dashboard.

## Decision

The ESP32 handles all real-time hardware control. The Raspberry Pi handles logging, the database, the REST API, and the web dashboard.

## Reasoning

- The ESP32 is a microcontroller optimized for low-latency hardware control. It has GPIO, SPI, I2C, PWM, and UART peripherals directly on-chip.
- The Raspberry Pi is a full Linux computer suited for networking, databases, web servers, and file I/O — but it runs a general-purpose OS and is not suitable for hard real-time hardware control.
- Splitting the responsibilities gives each device work it is architecturally suited for.
- The ESP32 must be the lock authority. If the Pi crashes, the physical lock must still work.

## Consequences

- Requires a communication link between ESP32 and Pi (UART initially, Wi-Fi later).
- The Pi becoming unavailable must not prevent the ESP32 from making access decisions.
- Two separate codebases to maintain (C/C++ firmware + Python backend).
