# Phase 17 — ESP32 Wi-Fi Communication

**Date started:**
**Date completed:**

---

## Goal

Replace (or supplement) UART with Wi-Fi — ESP32 POSTs access events to the Pi's REST API over the local network.

---

## Protocol Choice

- [ ] HTTP POST
- [ ] MQTT
- [ ] Both (HTTP primary, MQTT secondary)

Rationale for choice:

---

## Network Details

| Item              | Value |
|-------------------|-------|
| Pi IP address     |       |
| API endpoint      | http://[pi-ip]:5000/api/events |
| SSID              | (do not commit to public repo) |

---

## Key Concepts Learned

### Wi-Fi on the ESP32


### HTTP vs MQTT — Trade-offs


### TCP vs UDP


### Why Keep UART as Fallback


---

## Credential Handling

Wi-Fi credentials are NOT hardcoded in the repo. They are stored:

- [ ] In a `secrets.h` file excluded via `.gitignore`
- [ ] In ESP32 NVS
- [ ] Via a provisioning flow

---

## Problems Encountered

---

## Git Commit

```
Phase 17: Wi-Fi communication — ESP32 POSTs events to Pi REST API
```
