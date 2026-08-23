# Phase 0 — Development Environment

**Date started:** 2026-08-23
**Date completed:** 2026-08-23

---

## Goal

Set up the complete development environment and confirm the ESP32 can be flashed and communicate over serial.

---

## What I Built

- Installed PlatformIO extension inside VS Code
- Added user to `dialout` group for serial port access
- Installed PlatformIO udev rules (`99-platformio-udev.rules`) for USB device permissions
- Created the PlatformIO ESP32 project targeting `esp32doit-devkit-v1`
- Wrote a minimal `main.cpp` that boots and prints over serial
- Initialized the Git repository with full project scaffold

---

## Hardware Used

- ESP32 DevKit V1 (ESP32-D0WD-V3, revision 3.1)
- USB cable (data-capable)
- Ubuntu Linux computer

---

## Environment Details

| Item               | Value                  |
|--------------------|------------------------|
| OS                 | Ubuntu Linux           |
| PlatformIO version | 7.0.1 (Espressif 32)   |
| ESP32 board ID     | esp32doit-devkit-v1    |
| ESP32 chip         | ESP32-D0WD-V3 rev 3.1  |
| CPU speed          | 240 MHz, dual core     |
| RAM                | 320 KB                 |
| Flash              | 4 MB                   |
| Serial port        | /dev/ttyUSB0           |
| Baud rate          | 115200                 |
| Upload speed       | 115200                 |

---

## Key Concepts Learned

### Firmware
Code that runs directly on a microcontroller. Unlike a desktop program, there is no operating system underneath it. The firmware IS the software layer on the hardware.

### Compiling
Translating C++ source into machine instructions for the ESP32's Xtensa LX6 processor. Because the ESP32 and the laptop use different processor architectures, this is called cross-compilation — the compiler runs on the laptop but produces code for a completely different chip.

### Linking
After compiling, the linker combines all compiled object files and libraries into a single binary (`.bin` file). It resolves references between files and assigns final memory addresses.

### Flashing
Writing the compiled binary to the ESP32's internal flash memory over USB. PlatformIO uses `esptool.py` under the hood. The ESP32 must enter bootloader mode first — PlatformIO triggers this automatically by pulsing the BOOT and EN pins via the USB-serial chip.

### Serial Communication
The ESP32 sends debug text back to the computer over the same USB connection used to flash it. The USB-serial bridge chip (CP210x or CH340) on the dev board converts UART signals to USB. The computer sees it as a virtual serial port (`/dev/ttyUSB0` on Linux).

### Baud Rate
The speed of serial communication in bits per second. We use 115200. Both sides must agree or output is garbled. At 115200 baud, one character (10 bits with start/stop) takes ~87 microseconds.

### EN Button
Resets the ESP32. Pressing it triggers a full reboot — the chip re-runs the boot ROM and then your firmware. Used constantly during development to restart the program without unplugging.

### BOOT Button
Forces the ESP32 into bootloader mode when held during reset. Normally not needed since PlatformIO handles this automatically, but useful as a manual fallback if flashing fails.

### Boot ROM Output
The serial output before our print statement is the boot ROM running:
```
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
load:0x3fff0030,len:1184
load:0x40078000,len:13232
load:0x40080400,len:3028
entry 0x400805e4
```
This is the hardware-determined startup code — analogous to `_start` in Linux before `main()` is called. It loads firmware from flash into RAM and jumps to the entry point before our `setup()` ever runs.

### setup() vs main()
`setup()` is called once at boot by the Arduino framework — similar to `main()` on a desktop. But like `_start` on Linux, `setup()` is not the first thing that executes. The reset vector → boot ROM → C runtime startup → Arduino framework all run first, then `setup()`.

### udev
The Linux subsystem that manages device permissions. When the ESP32 is plugged in, udev reads rules files in `/etc/udev/rules.d/` to decide who can access the device. The PlatformIO udev rules grant the `dialout` group access to ESP32-class USB serial devices.

---

## Serial Output

```
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
...
entry 0x400805e4
RFID Access Control System Booting...
```

---

## Problems Encountered

### Permission denied on /dev/ttyUSB0
**Symptom:** Upload failed with `[Errno 13] Permission denied: '/dev/ttyUSB0'`
**Cause:** User not yet in `dialout` group, and udev rules not installed
**Fix:** Ran `sudo usermod -a -G dialout $USER` and installed PlatformIO udev rules, then replugged the ESP32

### Upload failed at baud rate change
**Symptom:** Flashing failed after "Changing baud rate to 460800"
**Cause:** USB cable or CH340 chip couldn't sustain 460800 baud reliably
**Fix:** Added `upload_speed = 115200` to `platformio.ini`

### Serial monitor showing blank output
**Symptom:** Monitor connected but no output visible
**Cause:** Monitor defaulted to 9600 baud, ESP32 transmitting at 115200
**Fix:** Added `monitor_speed = 115200` to `platformio.ini`

---

## platformio.ini (final)

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
upload_speed = 115200
monitor_speed = 115200
```

---

## Git Commit

```
Phase 0: Dev environment confirmed, ESP32 boots and prints over serial
```

Files committed:
- `firmware/src/main.cpp`
- `firmware/platformio.ini`
- `README.md`
- `CLAUDE.md`
- `.gitignore`
- `docs/`
- `tests/`
