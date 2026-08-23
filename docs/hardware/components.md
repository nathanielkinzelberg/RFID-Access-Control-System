# Component Reference

---

## ESP32 DevKit

| Item              | Value |
|-------------------|-------|
| Board name        |       |
| USB chip          |       |
| Flash size        | 4MB (typical) |
| RAM               | 520 KB SRAM |
| Logic voltage     | 3.3V |
| Max GPIO current  | 12 mA per pin |
| CPU               | Xtensa LX6 dual-core, up to 240 MHz |

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

> 3.3V only. Connecting 5V will damage the module.

---

## SG90 Servo Motor

| Item              | Value |
|-------------------|-------|
| Operating voltage | 4.8–6V (use 5V) |
| Stall current     | ~650 mA |
| No-load current   | ~100–250 mA |
| PWM frequency     | 50 Hz (20 ms period) |
| Pulse: 0°         | ~1.0 ms |
| Pulse: 90°        | ~1.5 ms |
| Pulse: 180°       | ~2.0 ms |

> Power from external 5V supply, NOT the ESP32 3.3V pin. Share GND with ESP32.

---

## 0.96" OLED Display

| Item              | Value |
|-------------------|-------|
| Interface         | I2C |
| Operating voltage | 3.3V or 5V (most modules) |
| Default I2C address | 0x3C (some use 0x3D — run scanner) |
| Resolution        | 128×64 pixels |
| Controller IC     | SSD1306 |

---

## Buzzer

| Item              | Value |
|-------------------|-------|
| Type              | Active / Passive (determine via test) |
| Operating voltage | 3.3V or 5V |

How to test: Apply 3.3V directly. If it beeps without any signal, it is active. If it is silent, it is passive (requires PWM).

---

## LEDs

| Color  | Forward Voltage (typical) | Current Limiting Resistor (3.3V) |
|--------|---------------------------|----------------------------------|
| Red    | ~2.0V                     | 68–100 Ω                         |
| Green  | ~2.1V                     | 68–100 Ω                         |
| Yellow | ~2.1V                     | 68–100 Ω                         |

Formula: R = (Vsupply − Vforward) / Idesired

Example (red, 3.3V, 10 mA): R = (3.3 − 2.0) / 0.010 = 130 Ω → use 150 Ω or 220 Ω

---

## Raspberry Pi 5

| Item              | Value |
|-------------------|-------|
| GPIO voltage      | 3.3V |
| OS                | Raspberry Pi OS 64-bit |
| Serial port       | /dev/ttyAMA0 (UART0) or /dev/ttyUSB0 |
