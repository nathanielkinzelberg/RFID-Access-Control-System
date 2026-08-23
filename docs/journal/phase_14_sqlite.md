# Phase 14 — SQLite Database

**Date started:**
**Date completed:**

---

## Goal

Log every access event to a SQLite database on the Raspberry Pi with a normalized schema.

---

## Database Location

`/home/pi/rfid/rfid_access.db`

---

## Schema

### users table

```sql
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    rfid_uid TEXT UNIQUE NOT NULL,
    active INTEGER DEFAULT 1,
    created_at TEXT DEFAULT (datetime('now'))
);
```

### access_events table

```sql
CREATE TABLE access_events (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    rfid_uid TEXT NOT NULL,
    user_id INTEGER REFERENCES users(id),
    result TEXT NOT NULL,
    timestamp TEXT DEFAULT (datetime('now'))
);
```

---

## Key Concepts Learned

### Relational Database Basics


### Primary Keys and Foreign Keys


### Normalization


### Basic SQL Queries


---

## Useful Queries

```sql
-- All events
SELECT * FROM access_events ORDER BY timestamp DESC;

-- Denied events only
SELECT * FROM access_events WHERE result = 'DENIED';

-- Events with user names joined
SELECT ae.timestamp, u.name, ae.result
FROM access_events ae
LEFT JOIN users u ON ae.user_id = u.id
ORDER BY ae.timestamp DESC;
```

---

## Problems Encountered

---

## Git Commit

```
Phase 14: SQLite database schema and event logging
```
