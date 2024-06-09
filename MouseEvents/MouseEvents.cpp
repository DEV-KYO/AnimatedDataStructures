//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_MOUSEEVENTS_CPP
#define TEXT_INPUT_PROJECT_MOUSEEVENTS_CPP


#include "MouseEvents.h"



template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    //this is what I used to determine if a double click or triple click occurred
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(clock.getElapsedTime().asMilliseconds() < 500)
            {
                clicks++;
            }
            else {
                clicks = 1;
            }
            clock.restart();
        }
    }
}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    return  MouseEvents<T>::hovered(object,window) &&
            sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    countClicks(event);
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    return clicks == 2;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    return clicks == 3;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    //do not understand this implementation
    return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::FloatRect bounds = object.getLocalBounds();
    return bounds.contains({(sf::Vector2f)sf::Mouse::getPosition(window)});
}

#endif