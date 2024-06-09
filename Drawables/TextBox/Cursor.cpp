#include "Cursor.h"

Cursor::Cursor() {
    //Set the cursor
    cursor.setSize(sf::Vector2f(1, TEXT_SIZE));
    cursor.setFillColor(sf::Color::White);
    cursor.setPosition(3, TEXT_BOX_Y + 1);
    cursorInterval = 0.5;       //Set the interval of the cursor
    visible = true;             //Set the visibility of the cursor
    cursorStates.enableState(); //Set the state of the cursor
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //If the cursor is visible and the state is enabled then draw the cursor
    if(visible && cursorStates.getState())
        window.draw(cursor, states);
}

void Cursor::update() {
    //If the clock has passed the interval and the state is enabled then change the visibility of the cursor
    if(clock.getElapsedTime().asSeconds() > cursorInterval  && cursorStates.getState())
    {
        visible = !visible; //Change the visibility of the cursor
        clock.restart();    //Restart the clock
    }
}

void Cursor::setPosition(const sf::Vector2f &position) {
    cursor.setPosition(position);
}

void Cursor::setSize(const sf::Vector2f &size) {
    cursor.setSize(size);
}

void Cursor::setFillColor(const sf::Color &color) {
    cursor.setFillColor(color);
}

void Cursor::setOutlineColor(const sf::Color &color) {
    cursor.setOutlineColor(color);
}

void Cursor::setState(ObjectState state) {
    if(state == ENABLED) {
        cursorStates.enableState();
        visible = state;
    } else {
        cursorStates.disableState();
        visible = state;
    }
}

void Cursor::getPosition() {
    cursor.getPosition();
}


