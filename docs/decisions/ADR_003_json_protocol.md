# ADR-003 — JSON for ESP32–Pi Message Protocol

**Date:**
**Status:** Accepted

---

## Context

The ESP32 sends access events to the Pi. The message format could be a simple delimited string or structured JSON.

## Options Considered

**Option A — Delimited plain text:**
```
ACCESS|1724442000|A342F191|Nathaniel|GRANTED
```

**Option B — JSON:**
```json
{"event":"access","uid":"A342F191","user":"Nathaniel","result":"granted","ts":1724442000}
```

## Decision

JSON (Option B).

## Reasoning

- JSON is self-describing: field names travel with the data. Adding a new field doesn't break old parsers.
- Python's `json` module makes parsing trivial on the Pi side.
- JSON is easier to debug in a serial monitor.
- Delimited formats break if a field value contains the delimiter character.
- The ESP32 has enough flash and RAM for `ArduinoJson` — size is not a concern.

## Consequences

- Each message is longer than a delimited string — not a concern at 115200 baud with infrequent messages.
- Both sides must agree on field names (document them below).

## Message Schema

```json
{
  "event":  "access",
  "uid":    "A342F191",
  "user":   "Nathaniel",
  "result": "granted",
  "ts":     1724442000
}
```

| Field   | Type   | Description                         |
|---------|--------|-------------------------------------|
| event   | string | Always "access" for now             |
| uid     | string | Hex UID, no spaces, uppercase       |
| user    | string | Name or "unknown" if not authorized |
| result  | string | "granted" or "denied"               |
| ts      | int    | Unix timestamp from ESP32 RTC/NTP   |
