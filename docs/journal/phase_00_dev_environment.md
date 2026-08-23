# Phase 0 — Development Environment

**Date started:**
**Date completed:**

---

## Goal

Set up the complete development environment and confirm the ESP32 can be flashed and communicate over serial.

---

## What I Built

- Installed VS Code and PlatformIO
- Created the PlatformIO ESP32 project
- Wrote a minimal `main.cpp` that boots and prints over serial
- Initialized the Git repository and pushed to GitHub

---

## Hardware Used

- ESP32 DevKit (model: )
- USB cable (data-capable, not charge-only)
- Linux/Windows computer

---

## Environment Details

| Item              | Value |
|-------------------|-------|
| OS                |       |
| VS Code version   |       |
| PlatformIO version|       |
| ESP32 board ID    |       |
| Serial port       |       |
| Baud rate         | 115200 |

---

## Key Concepts Learned

### Firmware
Code that runs directly on a microcontroller. Unlike a desktop program, there is no operating system underneath it. The firmware IS the software layer on the hardware.

### Compiling
The process of translating C/C++ source code into machine instructions the ESP32's Xtensa LX6 processor can execute.

### Linking
After compiling, the linker combines all compiled object files and libraries into a single binary (`.bin` file). It resolves references between files — e.g., if `main.cpp` calls a function defined in another file, the linker connects them.

### Flashing
Writing the compiled binary to the ESP32's internal flash memory over USB. PlatformIO uses `esptool.py` to do this. The ESP32 must be in bootloader mode (usually automatic, sometimes requires holding the BOOT button).

### Serial Communication
The ESP32 sends debug text back to the computer over the same USB connection used to flash it. This uses a UART-to-USB bridge chip on the dev board (CP2102, CH340, etc.). The computer sees it as a virtual COM/serial port.

### Baud Rate
The speed of serial communication measured in bits per second. We use 115200. Both sides (ESP32 and serial monitor) must agree on the same baud rate, or you'll see garbled output.

---

## Serial Output

```
RFID Access Control System Booting...
```

---

## Problems Encountered

*(Document any issues and how you solved them)*

---

## Multimeter Work

*(Any measurements taken during this phase)*

---

## Git Commit

```
Phase 0: Initialize project, dev environment confirmed
```

Files committed:
- `firmware/src/main.cpp`
- `firmware/platformio.ini`
- `README.md`
- `.gitignore`
- `CLAUDE.md`
- `docs/`
