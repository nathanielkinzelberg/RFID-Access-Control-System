# Phase 10 — Admin Mode

**Date started:**
**Date completed:**

---

## Goal

Designate an admin RFID card that enters a privileged mode for adding/removing authorized users without reflashing.

---

## Admin Card UID

`__ __ __ __` (do not commit the actual UID to a public repo)

---

## Admin Flow

```
Scan Admin Card → Enter Admin Mode
    ↓
Scan card to add → Added to NVS
    ↓
Scan admin again → Exit Admin Mode
```

---

## Key Concepts Learned

### Privilege Separation


### Why a Physical Button or Timeout Is Important in Admin Mode


---

## Security Notes

- Admin mode times out after __ seconds if no card is scanned
- Admin card UID is stored separately from the regular user list

---

## Problems Encountered

---

## Git Commit

```
Phase 10: Admin RFID card enables add/remove user mode
```
