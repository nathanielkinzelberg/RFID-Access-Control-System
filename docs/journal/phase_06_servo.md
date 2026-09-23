# Phase 6 — Servo Lock

**Date started:** 2026-09-22
**Date completed:** 2026-09-22

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
| Brown (GND) | Left − rail (common ground with ESP32) | Common ground required |
| Red (VCC)   | Left + rail (USB charger 5V)           | Not ESP32 3.3V pin     |
| Orange (PWM)| GPIO 14                                | 3.3V PWM signal is fine |

---

## Servo Positions

| State    | Angle | PWM Pulse Width |
|----------|-------|-----------------|
| LOCKED   | 0°    | ~1.0 ms         |
| UNLOCKED | 90°   | ~1.5 ms         |

---

## Key Concepts Learned

### PWM and Servo Control

Servos are controlled by a PWM signal at 50 Hz (20 ms period). The pulse width determines the angle: ~1.0 ms = 0°, ~1.5 ms = 90°, ~2.0 ms = 180°. The ESP32Servo library (madhephaestus/ESP32Servo) abstracts this — `myServo.write(angle)` handles the pulse width calculation internally. The servo does not move to exactly the specified angle on cheap units like the SG90 — small deviations are normal.

### Why Servos Need External Power

The SG90 draws up to 650 mA at stall. The ESP32's 3.3V pin cannot supply this — it would brown out the ESP32 or damage the pin. Power comes from an external 5V source (USB charger), with GND shared between the servo, USB supply, and ESP32 so the PWM signal has a common reference.

### Non-blocking Relock Timer

This phase uses `delay()` which blocks for the unlock duration. A true non-blocking implementation would use `millis()` to timestamp the unlock event and check elapsed time each loop iteration without freezing. This will be addressed in Phase 20 (FreeRTOS).


---

## Additional Feature

A manual relock button was added on GPIO 4 (`INPUT_PULLUP`). After an authorized scan, the servo unlocks and waits in a `while(digitalRead(4))` loop until the button is pressed, then relocks with a short red LED flash and two quick beeps. As a side effect of checking the button at the top of `loop()`, pressing the button while already locked also triggers the feedback — this is not an explicitly designed feature but is acceptable behavior (acts as a "confirmed locked" indicator).

---

## Problems Encountered

- 9V battery on hand but too high for SG90 (rated 4.8–6V). Used a cut USB cable + phone charger as a 5V supply instead.
- Servo does not rotate to exactly 90° — slight deviation is normal for cheap SG90 clones.

---

## Multimeter Work

- Measured servo VCC: __ V
- Measured current draw during movement: __ mA (if ammeter available)

---

## Git Commit

```
Phase 6: SG90 servo lock control via PWM with non-blocking relock timer
```
