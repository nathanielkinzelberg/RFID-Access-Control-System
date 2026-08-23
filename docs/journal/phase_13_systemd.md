# Phase 13 — Raspberry Pi Linux Service

**Date started:**
**Date completed:**

---

## Goal

Write a Python serial listener on the Pi and run it as a systemd service that starts automatically on boot.

---

## Service Details

| Item              | Value                        |
|-------------------|------------------------------|
| Serial port       | /dev/ttyAMA0 or /dev/ttyUSB0 |
| Baud rate         | 115200                       |
| Service file path | /etc/systemd/system/rfid-listener.service |
| Python script     | /home/pi/rfid/serial_listener.py |

---

## Key Concepts Learned

### Linux Processes


### Daemons


### stdout vs stderr


### systemd


### Service Unit File Anatomy


### journalctl for Log Reading


---

## Useful Commands

```bash
# Start/stop/restart the service
sudo systemctl start rfid-listener
sudo systemctl stop rfid-listener
sudo systemctl restart rfid-listener

# Enable auto-start on boot
sudo systemctl enable rfid-listener

# Check status
sudo systemctl status rfid-listener

# View logs
journalctl -u rfid-listener -f
journalctl -u rfid-listener --since "1 hour ago"
```

---

## Service File

```ini
[Unit]
Description=RFID Access Control Serial Listener
After=network.target

[Service]
Type=simple
User=pi
WorkingDirectory=/home/pi/rfid
ExecStart=/usr/bin/python3 /home/pi/rfid/serial_listener.py
Restart=always
RestartSec=5
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
```

---

## Problems Encountered

---

## Git Commit

```
Phase 13: Pi serial listener as systemd service
```
