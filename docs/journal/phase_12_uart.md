# Phase 12 — ESP32 ↔ Raspberry Pi Communication (UART)

**Date started:**
**Date completed:**

---

## Goal

Send structured access-event messages from ESP32 to Raspberry Pi over UART serial.

---

## Wiring

| ESP32 Pin | Raspberry Pi Pin | Notes                          |
|-----------|------------------|--------------------------------|
| TX (GPIO) | RX               | Cross-connect TX→RX            |
| RX (GPIO) | TX               | Cross-connect RX→TX            |
| GND       | GND              | Common ground required         |

> **Warning:** Both ESP32 and Raspberry Pi GPIO are 3.3V. Do not connect to a 5V UART device without a level shifter.

---

## Protocol Design

### Message Format

```json
{
  "event": "access",
  "uid": "A342F191",
  "user": "Nathaniel",
  "result": "granted",
  "ts": 1724442000
}
```

### Delimiter

Each message is terminated with `\n` (newline).

---

## Key Concepts Learned

### UART (Universal Asynchronous Receiver-Transmitter)


### TX and RX


### Baud Rate and Framing


### Asynchronous vs Synchronous Serial


### Why Common Ground Matters


### Text Protocol vs Binary Protocol Trade-offs


### JSON vs Delimited Plain Text Trade-offs


---

## Problems Encountered

---

## Git Commit

```
Phase 12: UART communication — ESP32 sends JSON access events to Pi
```
