#pragma once
#include <Arduino.h>

/* Initializes the RFID scanner */
void scanInit();

/* Checks if a new card is present */
bool isCardPresent();

/* Gets the UID of the currently scanned card */
String getCardUID();