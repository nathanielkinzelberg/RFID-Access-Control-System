# Phase 1 — GPIO Basics (LED + Button)

**Date started:** 2026-08-24
**Date completed:**

---

## Goal

Learn fundamental ESP32 GPIO by wiring an LED and button, then replace blocking delays with non-blocking timing using `millis()`.

---

## Hardware Used

- ESP32 DevKit V1
- 1x LED
- 1x 220–330 Ω resistor
- 1x tactile push button
- Breadboard + jumper wires (male-to-male and female-to-male)

---

## Wiring (LED and Button)

| Component        | Breadboard hole | Notes                          |
|------------------|-----------------|--------------------------------|
| Jumper wire      | a1              | Other end → ESP32 GPIO 2 (female-to-male) |
| LED long leg (+) | b1              | Same row as GPIO 2 wire        |
| LED short leg (−)| b2              |                                |
| Resistor leg 1   | c2              | Same row as LED short leg      |
| Resistor leg 2   | c4              |                                |
| Jumper wire      | d4              | Other end → ESP32 GND (female-to-male) |

**Button (GPIO 4, active HIGH, no external resistor needed):**

| Component   | Breadboard hole | Notes                          |
|-------------|-----------------|--------------------------------|
| Jumper wire | a10             | Other end → ESP32 3V3          |
| Button leg 1| b10             | Same row as 3V3 wire           |
| Button leg 2| b12             | Other side of button gap       |
| Jumper wire | a12             | Other end → ESP32 GPIO 4 (D4)  |

---

## Key Concepts Learned

### GPIO Output
GPIO pins on the ESP32 are configurable. You must call `pinMode(pin, OUTPUT)` before using a pin as output — pins do not do anything by default. `digitalWrite(pin, HIGH)` sets the pin to 3.3V; `digitalWrite(pin, LOW)` sets it to 0V.

### Why the LED didn't work at first
The ESP32 does not drive any pins unless explicitly told to in code. Wiring alone is not enough — you must configure the pin and set its state in firmware.

### Pin Numbers in Code
`D2` is the label printed on the physical board. In Arduino/PlatformIO code you refer to it by its GPIO number — `2`. On the ESP32 DevKit V1 these match.

### delay()
`delay(500)` pauses execution for 500 milliseconds. The CPU sits idle doing nothing during this time. Simple and easy to use — useful for timing-based exercises like Morse code — but problematic for systems that need to handle multiple things at once (like reading a button while blinking an LED). That's why `millis()` is used next.

### Breadboard
Holes in the same numbered row (same side of the gap) are electrically connected. The gap in the middle separates the two halves. Female-to-male jumper wires connect the breadboard to ESP32 pins.

### GPIO Input and INPUT_PULLDOWN
A pin set to `INPUT_PULLDOWN` is a listener — it never outputs anything. The internal pull-down resistor (~45kΩ) holds the pin firmly at LOW when nothing is connected, preventing floating/garbage readings. When the button is pressed, 3.3V is connected directly to the pin and it reads HIGH.

### digitalRead()
`digitalRead(pin)` returns `HIGH` (1) or `LOW` (0) depending on whether voltage is present on the pin at that moment. Used to check the button state each time through `loop()`.

### Active HIGH Button
Wiring the button between 3V3 and the input pin means pressing it connects 3.3V to the pin → HIGH. Using `INPUT_PULLDOWN` means no external resistor is needed.

### Full Embedded Loop
Write code → Compile → Flash → ESP32 executes → Physical world responds.
This is the core loop of all embedded development.

---

## Progress

- [x] LED wired correctly
- [x] LED turned on with `digitalWrite(2, HIGH)`
- [x] LED turned off with `digitalWrite(2, LOW)`
- [x] LED blinking with `delay()`
- [x] Button wired and read
- [x] LED controlled by button
- [ ] Non-blocking timing with `millis()`

---

## Morse Code Exercise

As a first blinking exercise, coded "NATE" in Morse code using the LED on GPIO 2.

| Letter | Morse | Pattern                        |
|--------|-------|--------------------------------|
| N      | −·    | 700ms on, 100ms off, 300ms on  |
| A      | ·−    | 300ms on, 100ms off, 700ms on  |
| T      | −     | 700ms on                       |
| E      | ·     | 300ms on                       |

Timing conventions used:
- Dot: 300ms HIGH
- Dash: 700ms HIGH
- Gap between symbols in same letter: 100ms LOW
- Gap between letters: 1000ms LOW
- End of word: 2000ms LOW

---

## Code — Morse Code (delay-based blink)

```cpp
#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  // N (-.)
  digitalWrite(2, HIGH);
  delay(700);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(300);

  digitalWrite(2, LOW);
  delay(1000);

  // A (.-)
  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(700);

  digitalWrite(2, LOW);
  delay(1000);

  // T (-)
  digitalWrite(2, HIGH);
  delay(700);

  digitalWrite(2, LOW);
  delay(1000);

  // E (.)
  digitalWrite(2, HIGH);
  delay(300);

  digitalWrite(2, LOW);
  delay(2000);
}
```

## Code — Button Controls LED

```cpp
#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, INPUT_PULLDOWN);
}

void loop() {
  // Check if the input pin is HIGH aka Button is being pressed
  if (digitalRead(4) == HIGH) {
    // If the input pin is HIGH, turn on the output pin
    digitalWrite(2, HIGH);
  } else {
    // If the input pin is LOW (button unpressed), turn off the output pin
    digitalWrite(2, LOW);
  }
}
```

---

## Problems Encountered

### LED didn't light up on first try
**Cause:** No code written to drive the GPIO pin — wiring was correct but the pin was never configured or set HIGH.
**Fix:** Wrote `pinMode(2, OUTPUT)` and `digitalWrite(2, HIGH)` in `setup()`, then uploaded.

---

## Multimeter Work

*(To be filled in)*

---

## Git Commit

```
Phase 1: GPIO basics — LED blink and button control with non-blocking timing
```
