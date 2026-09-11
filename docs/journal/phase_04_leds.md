# Phase 4 — Status LEDs

**Date started:** 2026-09-11
**Date completed:** 2026-09-11

---

## Goal

Add green (granted) and red (denied) LEDs with non-blocking 2-second feedback timing.

---

## Wiring

| Component   | ESP32 Pin | Resistor |
|-------------|-----------|----------|
| Green LED + | GPIO 25   | 220 Ω    |
| Green LED − | GND       |          |
| Red LED +   | GPIO 26   | 220 Ω    |
| Red LED −   | GND       |          |

---

## Key Concepts Learned

### Non-blocking State Timing

`delay()` is blocking — it freezes the entire program for the duration. This works fine for Phase 4 since there is nothing else running in the loop, but it will be replaced with `millis()`-based timing in Phase 20 (FreeRTOS). Non-blocking timing works by recording a timestamp when the LED turns on, then checking on each loop iteration whether enough time has passed to turn it off — without ever pausing execution.

### Current-Limiting Resistors

LEDs must always have a series resistor. Formula: R = (Vsupply − Vforward) / Idesired. At 3.3V with a ~2.0V forward voltage and 10 mA target: R = (3.3 − 2.0) / 0.010 = 130Ω. A 220Ω resistor is conservative and safe.

---

## Problems Encountered

---

## Git Commit

```
Phase 4: Green/red status LEDs with non-blocking timing
```
