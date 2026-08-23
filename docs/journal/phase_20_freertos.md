# Phase 20 — FreeRTOS Upgrade (Optional)

**Date started:**
**Date completed:**

---

## Goal

Restructure the firmware to use FreeRTOS tasks, queues, and synchronization primitives where they genuinely improve the architecture.

---

## Decision: Was FreeRTOS Worth Adding?

*(Write your reasoning here after completing this phase)*

---

## Task Layout

| Task         | Priority | Stack Size | Core | Description |
|--------------|----------|------------|------|-------------|
| RFID Task    |          |            |      | Polls RC522 |
| Display Task |          |            |      | Updates OLED|
| Network Task |          |            |      | Wi-Fi/UART  |
| Lock Task    |          |            |      | Servo control|

---

## Synchronization

| Mechanism | Used For |
|-----------|----------|
| Queue     |          |
| Mutex     |          |
| Semaphore |          |

---

## Key Concepts Learned

### FreeRTOS Tasks vs Arduino loop()


### Queues for Inter-task Communication


### Mutexes — What They Protect


### Semaphores


### How These Map to OS Threading Concepts


### Priority Inversion — What Is It?


---

## Problems Encountered

---

## Git Commit

```
Phase 20: FreeRTOS multi-task firmware with queues and mutexes
```
