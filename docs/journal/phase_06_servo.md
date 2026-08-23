# Phase 6 — Servo Lock

**Date started:**
**Date completed:**

---

## Goal

Control an SG90 servo motor as a physical lock using PWM. Authorized card unlocks for 4 seconds, then relocks — non-blocking.

---

## Power Warning

> **Critical:** The SG90 servo draws more current than the ESP32's 3.3V pin can safely supply. Power the servo from an external 5V source with a shared ground. Do NOT power it directly from the ESP32.

---

## Wiring

| Servo Wire  | Connected To       | Notes                        |
|-------------|---------------------|------------------------------|
| Brown (GND) | External GND + ESP32 GND | Common ground required  |
| Red (VCC)   | External 5V         | Not ESP32 3.3V pin           |
| Orange (PWM)| ESP32 GPIO          | 3.3V PWM signal is fine      |

---

## Servo Positions

| State    | Angle | PWM Pulse Width |
|----------|-------|-----------------|
| LOCKED   | 0°    | ~1.0 ms         |
| UNLOCKED | 90°   | ~1.5 ms         |

---

## Key Concepts Learned

### PWM and Servo Control


### Why Servos Need External Power


### Non-blocking Relock Timer


---

## Problems Encountered

---

## Multimeter Work

- Measured servo VCC: __ V
- Measured current draw during movement: __ mA (if ammeter available)

---

## Git Commit

```
Phase 6: SG90 servo lock control via PWM with non-blocking relock timer
```
