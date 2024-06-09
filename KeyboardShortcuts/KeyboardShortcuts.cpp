//
// Created by Jonas Mendoza on 4/26/24.
//

#include "KeyboardShortcuts.h"

bool KeyboardShortcuts::isUndo() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
}
