//
// Created by Jonas Mendoza on 4/26/24.
//

#include "States.h"
// Constructor
States::States() {
    for(int i = 0; i < LASTSTATE; i++)
        states[static_cast<ObjectState>(i)] = false;
}

// Get state of object
bool States::getState() const {
    return (states.at(ENABLED) == true); // Return state
}

// Set state of object
void States::enableState() {
    states[ENABLED] = true;
}

// Disable state of object
void States::disableState() {
    states[ENABLED] = false;
    states[DISABLED] = true;
}

// Toggle state of object
void States::toggleState() {
    if (states[ENABLED]) {
        states[ENABLED] = false;
        states[DISABLED] = true;
    } else if (states[DISABLED]) {
        states[DISABLED] = false;
        states[ENABLED] = true;
    }
}