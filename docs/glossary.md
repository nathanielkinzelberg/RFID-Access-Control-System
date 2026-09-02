# Glossary — Terms and Concepts

A running reference of every term learned during this project.

---

## Communication Protocols

### Serial
Sending data **one bit at a time** in sequence. The opposite of parallel (which sends multiple bits simultaneously). Used everywhere in embedded systems because it requires fewer wires.

### SPI (Serial Peripheral Interface)
A 4-wire protocol for a master chip to talk to peripheral devices. The master controls the clock and decides when to communicate. The slave only responds when selected.
- **Bus** — the physical wires connecting the chips
- **Protocol** — the rules for how data travels across those wires

### UART (Universal Asynchronous Receiver-Transmitter)
A serial protocol used for communication between the ESP32 and your computer over USB. What `Serial.print()` uses. Completely separate from SPI — same concept (one bit at a time), different hardware and purpose.

### I2C (Inter-Integrated Circuit)
Another serial protocol, uses only 2 wires (SDA and SCL). Used for the OLED display in Phase 7. Multiple devices can share the same 2 wires, each with a unique address.

---

## SPI Pins

### SCK / SCL (Serial Clock)
The metronome of a serial conversation. Pulses once per bit — every pulse means "read one bit." Both sides stay in sync because they share this wire.
- On SPI it's called **SCK**
- On I2C it's called **SCL**
- On the ESP32, the hardware SPI clock is hardwired to **GPIO 18 (D18)**

### MOSI (Master Out Slave In)
The wire the master (ESP32) uses to send **instructions and commands** to the slave (RC522). One bit per clock pulse, outbound from ESP32.
- Hardwired to **GPIO 23 (D23)** on the ESP32's SPI hardware

### MISO (Master In Slave Out)
The wire the slave (RC522) uses to send **responses and data back** to the master (ESP32). One bit per clock pulse, inbound to ESP32.
- Hardwired to **GPIO 19 (D19)** on the ESP32's SPI hardware

### SS / CS / SDA (Slave Select / Chip Select / Serial Data)
The pin the master pulls LOW to say "I'm talking to you now." The slave ignores the bus unless this pin is LOW. Allows multiple SPI devices to share the same MOSI/MISO/SCK wires.
- Can be any free GPIO — you choose and tell the library
- On the RC522 board it's labelled **SDA** (confusing but same function)
- Used **GPIO 5 (D5)** in this project

### RST (Reset)
When pulled LOW, restarts the peripheral from scratch. Used during `PCD_Init()` to put the RC522 into a known good state at startup. Can be any free GPIO.
- Used **GPIO 22 (D22)** in this project

---

## GPIO

### GPIO (General Purpose Input Output)
A pin with no fixed job — you decide what it does in code.
- `pinMode(pin, OUTPUT)` + `digitalWrite()` — you control it (LED, RST, SS)
- `pinMode(pin, INPUT_PULLDOWN)` + `digitalRead()` — it listens (button)

Pins like D18/D19/D23 are also GPIO pins, but they have additional special hardware functions (SPI). When used for SPI, the hardware function takes over. When used for LED or button, they act as plain GPIO.

### INPUT_PULLDOWN
A GPIO mode that internally connects a ~45kΩ resistor between the pin and GND. Keeps the pin firmly at LOW when nothing is connected, preventing floating/garbage readings. No external resistor needed.

### Full-Duplex
Sending and receiving simultaneously. SPI is full-duplex — while the ESP32 sends a command on MOSI, the RC522 is already sending its response back on MISO at the same time.

---

## Timing

### delay()
Pauses execution for N milliseconds. The CPU sits idle doing nothing. Simple but blocks everything else — the ESP32 can't read a button or check for cards while waiting.

### millis()
Returns milliseconds since the ESP32 booted — a stopwatch always running. Used to check "has enough time passed?" without freezing execution. The ESP32 keeps running through `loop()` and only acts when the condition is met.

### Non-blocking
Code that checks time with `millis()` instead of freezing with `delay()`. The CPU stays free to handle multiple things at once.

---

## RFID

### RFID (Radio Frequency Identification)
The technology — uses radio waves to communicate between a reader (RC522) and a card or fob. Operates at 13.56 MHz for MIFARE cards.

### UID (Unique Identifier)
A serial number burned into every RFID card at manufacture. Typically 4 or 7 bytes. Automatically broadcast when a card enters the reader's field — no authentication required. Cannot be changed (on genuine cards).

### MIFARE
A family of RFID cards by NXP. Common in gyms, transit systems, offices. MIFARE Classic cards store up to 1KB in 16 blocks and support encrypted sectors.

### UID Cloning
Copying a card's UID onto a blank writable card using cheap hardware (~$10). Works on systems that only check the UID. Does NOT work against systems using encrypted sector authentication. Covered in Phase 21 security review.

---

## Power

### 3.3V / 3V3
The logic voltage of the ESP32 and RC522. The ESP32's 3V3 pin outputs a steady 3.3V to power connected modules. Do not connect 3.3V-only devices to 5V.

### GND (Ground)
The 0V reference point. Every component in the circuit must share a common ground or voltage measurements mean nothing and communication fails.

### Voltage Rail
A shared power line. All components drawing from 3.3V share the 3.3V rail; all GND connections share the GND rail.

---

## ESP32 Hardware SPI Pin Assignments (VSPI)

| Function | GPIO | Board Label |
|----------|------|-------------|
| SCK      | 18   | D18         |
| MISO     | 19   | D19         |
| MOSI     | 23   | D23         |
| SS (CS)  | 5    | D5 (chosen) |
| RST      | 22   | D22 (chosen)|

> SCK/MISO/MOSI are fixed by internal hardware. SS and RST can be any free GPIO.
