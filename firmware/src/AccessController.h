#pragma once

/* Represents the state of the access controller */
enum State {
    LOCKED,
    UNLOCKED
};

/* Initializes the access controller */
void accessInit();

/* Updates the access controller */
void accessUpdate();