# ADR-002 — Use UART Before Wi-Fi for ESP32–Pi Communication

**Date:**
**Status:** Accepted

---

## Context

The ESP32 needs to send access events to the Raspberry Pi. Two options: UART serial or Wi-Fi.

## Decision

Implement UART first (Phase 12), add Wi-Fi later (Phase 17). Keep UART as a fallback/debug channel even after Wi-Fi is added.

## Reasoning

- UART is simpler to bring up: no network stack, no credentials, no IP addressing.
- UART is deterministic: it will work as long as the wire is connected.
- Starting with UART isolates the communication problem from the networking problem.
- UART is an excellent debug channel throughout development regardless of which protocol is primary.
- Wi-Fi adds latency, reconnection logic, and credential management — those are easier to handle once basic communication works.

## Consequences

- Requires a physical wire between ESP32 and Pi (TX → RX, RX → TX, common GND).
- Voltage levels must be verified (both 3.3V — compatible without a level shifter).
- UART must remain functional as a debug path throughout the project.
