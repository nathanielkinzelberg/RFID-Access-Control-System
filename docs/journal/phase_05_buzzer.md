# Phase 5 — Buzzer

**Date started:** 2026-09-11
**Date completed:** 2026-09-11

---

## Goal

Add audible feedback: short beep for granted, multi-beep for denied.

---

## Buzzer Type

- [x] Active buzzer (beeps when power is applied)
- [ ] Passive buzzer (requires PWM frequency to produce sound)

How I determined the type: Has a sticker on top covering the hole — characteristic of active buzzers. Confirmed by applying power directly and hearing a tone with no PWM signal.

---

## Wiring

| Buzzer Pin | ESP32 Pin | Notes |
|------------|-----------|-------|
| + (long leg) | GPIO 13 | No resistor needed — buzzer has internal resistance |
| − (short leg) | GND    |       |

---

## Key Concepts Learned

### Active vs Passive Buzzer

An active buzzer has a built-in oscillator — apply power and it beeps at a fixed tone. A passive buzzer has no oscillator and requires a PWM signal at a specific frequency to produce sound. Active buzzers are identified by a sticker on top and a sealed bottom with no exposed circuitry.

### PWM for Tone Generation (passive only)

Not used this phase. A passive buzzer would require `tone(pin, frequency)` or manual PWM to produce sound. Useful for variable pitch or melodies.


---

## Problems Encountered

---

## Git Commit

```
Phase 5: Buzzer feedback — confirmation and warning tones
```
