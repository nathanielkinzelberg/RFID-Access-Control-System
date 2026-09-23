# Phase 8 — Firmware Architecture Refactor

**Date started:** 2026-09-23
**Date completed:** 2026-09-23

---

## Goal

Refactor monolithic `loop()` into a proper state machine with separate modules for each subsystem.

---

## Final File Structure

```
firmware/src/
    main.cpp
    RFIDManager.cpp / .h
    LockController.cpp / .h
    DisplayManager.cpp / .h
    Buzzer.cpp / .h
    AccessController.cpp / .h   (state machine)
```

---

## State Machine

```
        LOCKED ◄─────────────────┐
          │                      │
      [card scan]                │
          │                      │
     ┌────┴────┐                 │
   known    unknown              │
     │          │                │
     │     [denied feedback]     │
     │          │                │
     │        LOCKED             │
     ▼                           │
  UNLOCKED                       │
     │                           │
  [button press]                 │
     │                           │
  [lock feedback] ───────────────┘
```

---

## State Descriptions

| State    | Description                                                        |
|----------|--------------------------------------------------------------------|
| LOCKED   | Idle, showing "Please Scan Your Card", polling for RFID card       |
| UNLOCKED | Servo open, showing "Open", waiting for button press to relock     |

---

## Key Concepts Learned

### Finite State Machines in Embedded Systems

A FSM models a system as a set of discrete states with defined transitions between them. Only one state is active at a time. In embedded systems this replaces deeply nested if/else logic with a clean, predictable structure that is easy to extend and debug.

### Why Not One Giant loop()

A monolithic loop() becomes hard to maintain as complexity grows — adding a new feature means understanding the entire function. Splitting into a state machine means each state is self-contained. Adding a new state (e.g. LOCKOUT) only requires adding a new case without touching existing logic.

### Module Separation (Single Responsibility)

Each `.cpp` file owns one subsystem: `RFIDManager` handles scanning and UID lookup, `LockController` handles the servo, `DisplayManager` handles the OLED, `Buzzer` handles audio feedback. `AccessController` coordinates them via the state machine. `main.cpp` is reduced to 5 lines.


---

## Problems Encountered

- Simplified the state machine from the original design (removed BOOTING, CARD_DETECTED, VERIFYING, LOCKOUT, ERROR) — kept only LOCKED and UNLOCKED. Granted/denied feedback happens inline during transitions, not as separate states.
- LEDs removed from the system — OLED display provides sufficient visual feedback, LEDs were redundant.
- `struct authorizedUser` had to be defined before use in `RFIDManager.cpp` — compiler reads top to bottom.
- `getCardUID()` initially returned the raw UID object instead of the looked-up name — fixed to call `lookup()`.

---

## Git Commit

```
Phase 8: Refactor firmware into FSM + separate module files
```
