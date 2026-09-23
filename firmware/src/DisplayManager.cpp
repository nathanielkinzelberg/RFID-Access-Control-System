#include "DisplayManager.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

static Adafruit_SSD1306 display(128, 64, &Wire, -1);

void displayInit() {
  Wire.begin(21, 15);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

/* Outputs str to the OLED for "time" milliseconds at text size "size" */
void screenOutput(String str, int time, int size) {
  display.clearDisplay();
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(str);
  display.display();
  delay(time);
}