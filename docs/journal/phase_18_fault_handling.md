# Phase 18 — Fault Handling

**Date started:**
**Date completed:**

---

## Goal

Make the system resilient to component and network failures. The physical lock must continue working even when the Pi is offline.

---

## Fault Scenarios Tested

| Scenario                | Expected Behavior              | Actual Behavior | Pass? |
|-------------------------|--------------------------------|-----------------|-------|
| RC522 disconnected      | ERROR state, safe fail         |                 |       |
| OLED disconnected       | Continues without display      |                 |       |
| Raspberry Pi offline    | Lock still operates, events queued |             |       |
| Wi-Fi disconnected      | Falls back to UART             |                 |       |
| Database unavailable    | Pi logs to file, retries later |                 |       |
| Malformed UART message  | Discarded, no crash            |                 |       |
| Servo failure           | Error state flagged            |                 |       |
| ESP32 reboot            | Recovers to LOCKED state       |                 |       |
| Raspberry Pi reboot     | Service auto-restarts (systemd)|                 |       |

---

## Key Concepts Learned

### Fail-Safe vs Fail-Secure Design


### Why the ESP32 Must Be the Lock Authority


### Event Queuing During Outages


---

## Problems Encountered

---

## Git Commit

```
Phase 18: Fault handling — graceful degradation for component and network failures
```
