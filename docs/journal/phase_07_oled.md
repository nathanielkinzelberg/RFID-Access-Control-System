# Phase 7 — OLED Display

**Date started:** 2026-09-23
**Date completed:** 2026-09-23

---

## Goal

Connect the 0.96" OLED over I2C and display context-sensitive messages (idle, granted, denied).

---

## Wiring

| OLED Pin | ESP32 Pin | Notes                  |
|----------|-----------|------------------------|
| VCC      | 3.3V      | Shared rail with RC522 |
| GND      | GND       | Right − rail           |
| SDA      | GPIO 21   | I2C data               |
| SCL      | GPIO 15   | I2C clock              |

---

## I2C Device Address

Detected address: `0x3C` (confirmed via I2C scanner)

---

## Key Concepts Learned

### I2C (Inter-Integrated Circuit)

A two-wire serial protocol using SDA (data) and SCL (clock). Multiple devices can share the same two wires, each identified by a unique address. Much simpler wiring than SPI but generally slower.

### SDA and SCL

SDA carries data bidirectionally. SCL is the clock driven by the master (ESP32). The ESP32 can assign I2C to almost any GPIO — default pins are 21/22 but GPIO 22 was already used by RC522 RST, so SCL was moved to GPIO 15. `Wire.begin(SDA, SCL)` sets custom pins.

### Device Addressing

Each I2C device has a 7-bit address. The SSD1306 OLED defaults to 0x3C (some modules use 0x3D). Confirmed with an I2C scanner sketch that iterates all addresses and checks for acknowledgement.

### Shared I2C Bus

Multiple devices can share SDA and SCL. This OLED shares the 3.3V rail with the RC522 — a wire bridges row 30 on the breadboard to feed both VCC pins.

### I2C vs SPI Trade-offs

SPI is faster and full-duplex but requires 4+ wires and a dedicated CS pin per device. I2C only needs 2 wires and supports multiple devices on the same bus, but is slower and half-duplex. OLED uses I2C; RFID reader uses SPI.


---

## Display States

| State          | Display                                      |
|----------------|----------------------------------------------|
| Idle           | "Please / Scan / Your Card" (size 2)         |
| Opening        | "Opening..." (size 2)                        |
| Access Granted | "Access Granted / Welcome / [name]" (size 1) |
| Open (4s)      | "Open" (size 4, after 4s millis timer)       |
| Locking        | "Locking..." (size 2)                        |
| Locked         | "Locked" (size 2, 2s)                        |
| Access Denied  | "Access Denied" (size 2)                     |
| Retry          | "Please Try Again" (size 1, 2s)              |

---

## Problems Encountered

- GPIO 22 conflict: default I2C SCL pin is 22, but that's already used by RC522 RST. Moved SCL to GPIO 15 using `Wire.begin(21, 15)`.
- I2C scanner showed no output initially — ESP32 wasn't printing because serial monitor wasn't open during boot. Fixed by pressing EN button after opening monitor.
- OLED top ~16px zone is yellow, rest is blue — physical property of this module type, not configurable in code.
- File accidentally duplicated mid-edit causing compile errors — fixed by rewriting the file cleanly.

---

## Git Commit

```
Phase 7: OLED display over I2C with idle/granted/denied states
```
