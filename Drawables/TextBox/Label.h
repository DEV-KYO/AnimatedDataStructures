//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_LABEL_H
#define TEXT_INPUT_PROJECT_LABEL_H

//SFML
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "../../Font/EnumFonts.h"
#include "../../Font/FontManager.h"
#include "_LOCAL_CONSTANTS.h"

class Label : public sf::Drawable {
private:
    sf::Text text;              //The text object that will be displayed
    sf::Font font;              //The font that will be used
    EnumFonts fontType;         //The font type that will be used
    std::string textString;     //The string that will be displayed
    sf::Vector2f position;      //The position of the text
    sf::Color color;            //The color of the text
    unsigned int fontSize{};    //The size of the text
    sf::Text::Style style;      //The style of the text



public:
    Label();    //Default constructor
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //Draws the text to the window
    void setText(const std::string &textString);    //Sets the text of the label
};


#endif //TEXT_INPUT_PROJECT_LABEL_H
