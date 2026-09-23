# Component Reference

---

## ESP32 DevKit

| Item              | Value |
|-------------------|-------|
| Board name        | ESP32 DevKit V1 (DOIT) |
| Chip              | ESP32-D0WD-V3, revision 3.1 |
| USB chip          | CP210x (confirmed via /dev/ttyUSB0) |
| Flash size        | 4 MB |
| RAM               | 320 KB (reported by PlatformIO) |
| Logic voltage     | 3.3V |
| Max GPIO current  | 12 mA per pin |
| CPU               | Xtensa LX6 dual-core, 240 MHz |
| Serial port       | /dev/ttyUSB0 |
| MAC address       | 1c:c3:ab:3d:99:2c |

**Datasheet / pinout:** (add URL or local file reference)

---

## RC522 RFID Module

| Item              | Value |
|-------------------|-------|
| Interface         | SPI |
| Operating voltage | 3.3V (NOT 5V tolerant) |
| Frequency         | 13.56 MHz |
| Protocol          | ISO/IEC 14443 A |
| Max SPI clock     | 10 MHz |
| Module type       | Clone (non-genuine) |
| Firmware version  | 0x18 (genuine returns 0x91 or 0x92) |
| Pin layout        | SDA, SCK, MOSI, MISO, IRQ, GND, RST, 3.3 (left to right) |
| MOSI/MISO labels  | **Swapped on this module** — wire opposite to silk-screen labels |
| Library           | miguelbalboa/MFRC522@^1.4.11 |

> 3.3V only. Connecting 5V will damage the module.

> **MOSI/MISO are physically swapped on this clone module.** Connect ESP32 D23 (MOSI) to the RC522 pin labelled MISO, and ESP32 D19 (MISO) to the RC522 pin labelled MOSI. This is a known issue with cheap clone modules.

---

## SG90 Servo Motor

| Item              | Value |
|-------------------|-------|
| Operating voltage | 4.8–6V (use 5V) |
| Power source      | USB charger via cut USB cable (5V red wire, GND black wire) |
| Stall current     | ~650 mA |
| No-load current   | ~100–250 mA |
| PWM frequency     | 50 Hz (20 ms period) |
| Pulse: 0°         | ~1.0 ms |
| Pulse: 90°        | ~1.5 ms |
| Pulse: 180°       | ~2.0 ms |
| GPIO (Phase 6)    | GPIO 14 (PWM signal) |
| Library           | madhephaestus/ESP32Servo@^0.13.0 |

> Power from external 5V supply, NOT the ESP32 3.3V pin. Share GND with ESP32.

---

## 0.96" OLED Display

| Item              | Value |
|-------------------|-------|
| Interface         | I2C |
| Operating voltage | 3.3V or 5V (most modules) |
| I2C address       | 0x3C (confirmed via scanner) |
| Resolution        | 128×64 pixels |
| Controller IC     | SSD1306 |
| SDA pin           | GPIO 21 |
| SCL pin           | GPIO 15 (moved from default 22 — conflict with RC522 RST) |
| Display zones     | Top ~16px yellow, remainder blue — physical property of module |
| Library           | adafruit/Adafruit SSD1306@^2.5.7 + adafruit/Adafruit GFX Library@^1.11.9 |

---

## Buzzer

| Item              | Value |
|-------------------|-------|
| Type              | Active / Passive (determine via test) |
| Operating voltage | 3.3V or 5V |

How to test: Apply 3.3V directly. If it beeps without any signal, it is active. If it is silent, it is passive (requires PWM).

---

## LEDs

| Color  | Forward Voltage (typical) | Current Limiting Resistor (3.3V) | GPIO (Phase 4) |
|--------|---------------------------|----------------------------------|----------------|
| Red    | ~2.0V                     | 220 Ω (confirmed)                | GPIO 26        |
| Green  | ~2.1V                     | 220 Ω (confirmed)                | GPIO 25        |
| Yellow | ~2.1V                     | 68–100 Ω                         | —              |

Formula: R = (Vsupply − Vforward) / Idesired

Example (red, 3.3V, 10 mA): R = (3.3 − 2.0) / 0.010 = 130 Ω → use 150 Ω or 220 Ω

---

## Raspberry Pi 5

| Item              | Value |
|-------------------|-------|
| GPIO voltage      | 3.3V |
| OS                | Raspberry Pi OS 64-bit |
| Serial port       | /dev/ttyAMA0 (UART0) or /dev/ttyUSB0 |
