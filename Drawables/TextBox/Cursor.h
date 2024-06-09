//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_CURSOR_H
#define TEXT_INPUT_PROJECT_CURSOR_H

//SFML
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "../../States/States.h"
#include "_LOCAL_CONSTANTS.h"

class Cursor : public sf::Drawable {
private:
    sf::RectangleShape cursor;      //The cursor object that will be displayed
    sf::Clock clock;                //The clock that will be used to determine the cursor's visibility
    bool visible;                   //The visibility of the cursor
    float cursorInterval;           //The interval of the cursor
    States cursorStates;            //The state of the cursor


public:
    Cursor();   //Default constructor
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;    //Draws the cursor to the window
    void update();  //Updates the cursor's visibility
    void setPosition(const sf::Vector2f& position);   //Sets the position of the cursor
    void setSize(const sf::Vector2f& size);      //Sets the size of the cursor
    void setFillColor(const sf::Color& color);  //Sets the fill color of the cursor
    void setOutlineColor(const sf::Color& color);   //Sets the outline color of the cursor
    void setState(ObjectState state);   //Sets the state of the cursor
    void getPosition(); //Gets the position of the cursor
};


#endif //TEXT_INPUT_PROJECT_CURSOR_H
