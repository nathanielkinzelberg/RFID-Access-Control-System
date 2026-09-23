#include "AccessController.h"
#include "RFIDManager.h"
#include "LockController.h"
#include "Buzzer.h"
#include "DisplayManager.h"
#include <Arduino.h>

static State current_state = LOCKED;

void accessInit() {
    scanInit();
    lockInit();
    buzzerInit();
    displayInit();
    current_state = LOCKED;
}

void accessUpdate() {

    if (current_state == LOCKED) {
        screenOutput("Please\nScan\nYour Card", 0, 2);
        if (isCardPresent()) {
            String user = getCardUID();
            if (user != "Unknown") {
                current_state = UNLOCKED;
                screenOutput("Access Granted\nWelcome\n" + user, 0, 2);
                lockOpen();
                beepAccessGranted();
            } else {
                screenOutput("Access Denied", 0, 2);
                beepAccessDenied();
            }
        }
    }

    if(current_state == UNLOCKED) {
        screenOutput("Open", 0, 2);
        if (digitalRead(4) == LOW) {
            lockClose();
            screenOutput("Locking...", 0, 2);
            beepLock();
            current_state = LOCKED;
        }
    }


}