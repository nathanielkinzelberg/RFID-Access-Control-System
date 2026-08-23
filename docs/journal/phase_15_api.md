# Phase 15 — REST API

**Date started:**
**Date completed:**

---

## Goal

Create a REST API on the Raspberry Pi that exposes access events and user management over HTTP.

---

## Framework

- [ ] Flask
- [ ] FastAPI

---

## Endpoints

| Method | Path               | Description              |
|--------|--------------------|--------------------------|
| GET    | /api/status        | System health check      |
| GET    | /api/events        | All access events        |
| GET    | /api/events?limit= | Paginated events         |
| GET    | /api/users         | All users                |
| POST   | /api/users         | Add new user             |
| DELETE | /api/users/{id}    | Remove user              |

---

## Key Concepts Learned

### HTTP Request/Response Cycle


### GET vs POST vs DELETE


### JSON as API Data Format


### REST Constraints


### Client/Server Architecture


### Status Codes (200, 201, 400, 404, 500)


---

## Problems Encountered

---

## Git Commit

```
Phase 15: REST API for events and user management
```
