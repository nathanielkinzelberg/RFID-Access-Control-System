# Phase 7 — OLED Display

**Date started:**
**Date completed:**

---

## Goal

Connect the 0.96" OLED over I2C and display context-sensitive messages (idle, granted, denied).

---

## Wiring

| OLED Pin | ESP32 Pin | Notes                  |
|----------|-----------|------------------------|
| VCC      | 3.3V      |                        |
| GND      | GND       |                        |
| SDA      |           | I2C data               |
| SCL      |           | I2C clock              |

---

## I2C Device Address

Detected address: `0x` __ (run I2C scanner to confirm)

---

## Key Concepts Learned

### I2C (Inter-Integrated Circuit)


### SDA and SCL


### Device Addressing


### Shared I2C Bus


### I2C vs SPI Trade-offs


---

## Display States

| State    | Line 1         | Line 2        |
|----------|----------------|---------------|
| Idle     | RFID ACCESS    | Scan Card     |
| Granted  | ACCESS GRANTED | [User name]   |
| Denied   | ACCESS DENIED  | (blank)       |

---

## Problems Encountered

---

## Git Commit

```
Phase 7: OLED display over I2C with idle/granted/denied states
```
