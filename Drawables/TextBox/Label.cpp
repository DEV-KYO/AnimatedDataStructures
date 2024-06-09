//
// Created by Jonas Mendoza on 4/28/24.
//

#include "Label.h"


Label::Label() {
    //Set the font
    text.setFont(FontManager::getFont(PIXELGEORGIA));
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::White);
//    text.setStyle(sf::Text::Bold);
    text.setPosition(1, 1);
    text.setString("Text Box");
}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text, states);
}

void Label::setText(const std::string &textString) {
    text.setString(textString);
}
