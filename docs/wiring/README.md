# Wiring Documentation

Each phase that introduces new hardware has a wiring table here and in its journal entry.

| Phase | File                  | Components Added                   |
|-------|-----------------------|------------------------------------|
| 0     | —                     | ESP32 only (USB)                   |
| 1     | phase_01_gpio.md      | LED, resistor, button              |
| 2     | phase_02_rfid.md      | RC522 RFID module (SPI)            |
| 4     | phase_04_leds.md      | Green + red LEDs                   |
| 5     | phase_05_buzzer.md    | Active/passive buzzer              |
| 6     | phase_06_servo.md     | SG90 servo (external 5V power)     |
| 7     | phase_07_oled.md      | 0.96" OLED (I2C)                   |
| 12    | phase_12_uart.md      | UART to Raspberry Pi               |

## Global Pin Reference

*(Fill in as you assign pins during each phase — avoids conflicts)*

| ESP32 GPIO | Function         | Phase |
|------------|------------------|-------|
| 2          | LED output       | 1     |
| 4          | Button input     | 1     |
| 5          | RC522 SDA (SS)   | 2     |
| 18         | RC522 SCK        | 2     |
| 19         | RC522 MISO       | 2     |
| 22         | RC522 RST        | 2     |
| 23         | RC522 MOSI       | 2     |

## Voltage Rails

| Rail   | Source              | Connected To                |
|--------|---------------------|-----------------------------|
| 3.3V   | ESP32 3V3 pin       | RC522 VCC, OLED VCC         |
| 5V     | External supply     | SG90 servo VCC              |
| GND    | Common              | All components              |

> Always verify with a multimeter before connecting new components.
