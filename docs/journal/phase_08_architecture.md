# Phase 8 — Firmware Architecture Refactor

**Date started:**
**Date completed:**

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
       BOOTING
          │
          ▼
        LOCKED ◄────────────────────┐
          │                         │
      [card scan]                   │
          │                         │
          ▼                         │
    CARD_DETECTED                   │
          │                         │
          ▼                         │
       VERIFYING                    │
        ╱     ╲                     │
      YES       NO                  │
       │         │                  │
       ▼         ▼                  │
  ACCESS_    ACCESS_                │
  GRANTED    DENIED                 │
       │         │                  │
       ▼         └──► (3 fails?) ──►│
    UNLOCKED       LOCKOUT          │
       │               │            │
       └───────────────┴────────────┘
                  (timeout)
```

---

## State Descriptions

| State          | Description                                      |
|----------------|--------------------------------------------------|
| BOOTING        | Hardware init, peripheral checks                 |
| LOCKED         | Idle, polling for card                           |
| CARD_DETECTED  | Card present, UID read                           |
| VERIFYING      | Checking UID against authorized list             |
| ACCESS_GRANTED | Green LED, buzzer, unlock servo, show OLED       |
| ACCESS_DENIED  | Red LED, buzzer, deny OLED                       |
| UNLOCKED       | Servo open, waiting for relock timer             |
| LOCKOUT        | Too many failures — all scans rejected           |
| ERROR          | Hardware fault detected                          |

---

## Key Concepts Learned

### Finite State Machines in Embedded Systems


### Why Not One Giant loop()


### Module Separation (Single Responsibility)


---

## Problems Encountered

---

## Git Commit

```
Phase 8: Refactor firmware into FSM + separate module files
```
