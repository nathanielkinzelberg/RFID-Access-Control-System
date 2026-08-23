# Test Plan — RFID Access Control System

---

## How to Use This Document

Run each test case manually. Record the actual result and whether it passed. Add notes on any unexpected behavior. Date each test run.

---

## Test Environment

| Item         | Value |
|--------------|-------|
| Firmware version / commit |  |
| Pi software version / commit | |
| Test date    |       |
| Tester       | Nathaniel Kinzelberg |

---

## Test Cases

### TC-01 — Authorized Card Access

**Precondition:** System in LOCKED state. Card UID is in the authorized list.

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan authorized card | Card UID printed to serial |
| 2 | | `ACCESS GRANTED` on OLED |
| 3 | | Green LED on |
| 4 | | Short confirmation beep |
| 5 | | Servo rotates to UNLOCKED (90°) |
| 6 | | Pi logs GRANTED event to database |
| 7 | Wait 4 seconds | Servo returns to LOCKED (0°) |
| 8 | | OLED returns to idle |
| 9 | | Green LED off |

**Actual result:**
**Pass?** ☐

---

### TC-02 — Unauthorized Card

**Precondition:** System in LOCKED state. Card UID is NOT in the authorized list.

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan unauthorized card | Card UID printed to serial |
| 2 | | `ACCESS DENIED` on OLED |
| 3 | | Red LED on |
| 4 | | Warning beeps (2–3) |
| 5 | | Servo remains LOCKED |
| 6 | | Pi logs DENIED event to database |
| 7 | After 2 seconds | Red LED off, OLED returns to idle |

**Actual result:**
**Pass?** ☐

---

### TC-03 — Repeated Unauthorized Attempts → Lockout

**Precondition:** System in LOCKED state.

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan unauthorized card | DENIED |
| 2 | Scan unauthorized card | DENIED |
| 3 | Scan unauthorized card | DENIED (3rd failure) |
| 4 | | LOCKOUT state entered |
| 5 | | OLED shows LOCKOUT |
| 6 | | Buzzer alarm sounds |
| 7 | Scan any card during lockout | Scan rejected |
| 8 | Wait for lockout duration | System returns to LOCKED |

**Actual result:**
**Pass?** ☐

---

### TC-04 — Admin Card Flow (Add User)

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan admin card | Admin mode entered, OLED indicates |
| 2 | Scan a new (unknown) card | New card added to authorized list |
| 3 | Scan admin card again | Admin mode exited |
| 4 | Scan the newly added card | ACCESS GRANTED |

**Actual result:**
**Pass?** ☐

---

### TC-05 — Admin Card Flow (Remove User)

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan admin card | Admin mode entered |
| 2 | Scan an existing authorized card | Card removed from list |
| 3 | Exit admin mode | |
| 4 | Scan the removed card | ACCESS DENIED |

**Actual result:**
**Pass?** ☐

---

### TC-06 — ESP32 Reboot Recovery

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Power cycle or reset ESP32 | Boots successfully |
| 2 | | Serial prints boot message |
| 3 | | OLED shows idle state |
| 4 | Scan authorized card | ACCESS GRANTED (user still in NVS) |

**Actual result:**
**Pass?** ☐

---

### TC-07 — Raspberry Pi Reboot

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Reboot Raspberry Pi | |
| 2 | Scan a card during reboot | ESP32 continues to operate locally |
| 3 | Pi completes boot | rfid-listener service auto-starts |
| 4 | Scan another card | Event logged to Pi database |

**Actual result:**
**Pass?** ☐

---

### TC-08 — Wi-Fi Failure

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Disconnect Wi-Fi / turn off router | |
| 2 | Scan authorized card | LOCAL grant still works |
| 3 | | ESP32 queues or falls back to UART |
| 4 | Restore Wi-Fi | Connection re-established |
| 5 | Scan card | Event sent to Pi over Wi-Fi |

**Actual result:**
**Pass?** ☐

---

### TC-09 — UART Failure

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Disconnect UART cable | |
| 2 | Scan authorized card | Local access still works |
| 3 | Reconnect UART | Communication resumes |

**Actual result:**
**Pass?** ☐

---

### TC-10 — Database Unavailable

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Corrupt or delete DB file | |
| 2 | Trigger an access event | Pi handles error gracefully (no crash) |
| 3 | Restore DB | Logging resumes |

**Actual result:**
**Pass?** ☐

---

### TC-11 — RC522 Disconnected

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Disconnect RC522 | ERROR state entered |
| 2 | | Serial/OLED indicates hardware fault |
| 3 | | System does not crash in a tight loop |
| 4 | Reconnect RC522 and reboot | System recovers |

**Actual result:**
**Pass?** ☐

---

### TC-12 — Rapid Repeated Scans

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Scan authorized card rapidly 5+ times | Debounce prevents duplicate events |
| 2 | | Only one unlock cycle per scan |

**Actual result:**
**Pass?** ☐

---

### TC-13 — OLED Disconnected

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Disconnect OLED | System continues operating |
| 2 | | No crash, serial confirms access decisions |
| 3 | Reconnect OLED | Display resumes |

**Actual result:**
**Pass?** ☐

---

### TC-14 — Servo Failure Simulation

| Step | Action | Expected Result |
|------|--------|-----------------|
| 1 | Disconnect servo signal wire | |
| 2 | Grant access | No servo movement, but grant still logged |
| 3 | | Error state or warning flagged in serial |

**Actual result:**
**Pass?** ☐

---

## Regression Log

*(After changes, note which test cases were re-run and results)*

| Date | Change Made | Tests Re-run | All Pass? |
|------|-------------|--------------|-----------|
|      |             |              |           |
