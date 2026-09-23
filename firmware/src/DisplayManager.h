#pragma once
#include <Arduino.h>

/* Outputs str to the OLED for "time" milliseconds at text size "size" */
void screenOutput(String str, int time, int size);

/* Initializes the OLED display */
void screenInit();