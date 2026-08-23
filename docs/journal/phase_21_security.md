# Phase 21 — Security Review

**Date started:**
**Date completed:**

---

## Goal

Identify and document real security weaknesses in the system, then implement reasonable mitigations.

---

## Threat Model

| Threat                         | Severity | Mitigation Implemented |
|--------------------------------|----------|------------------------|
| RFID UID cloning               | High     |                        |
| Unencrypted UART communication | Medium   |                        |
| Unencrypted HTTP (Wi-Fi)       | High     |                        |
| Replay attacks                 | Medium   |                        |
| Hardcoded credentials          | High     |                        |
| Wi-Fi credentials in firmware  | High     |                        |
| Physical access to ESP32       | High     |                        |
| Unauthorized admin card access | High     |                        |
| Database file permissions      | Medium   |                        |
| No API authentication          | High     |                        |

---

## Key Concepts Learned

### Why RFID UID Cloning Is Trivial


### Encryption Options for UART (TLS not applicable — discuss why)


### HTTPS for the REST API


### Replay Attack — Definition and Mitigation


### Credential Storage Best Practices


### Fail-Secure vs Security Theater


---

## Improvements Implemented

*(Document what you actually changed and why)*

---

## Limitations Accepted

*(Document what you deliberately did not fix and why it's an acceptable trade-off for a dev/portfolio system)*

---

## Git Commit

```
Phase 21: Security review — threat model documented, high-severity mitigations applied
```
