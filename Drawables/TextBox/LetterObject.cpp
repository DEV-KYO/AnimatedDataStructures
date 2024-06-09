//
// Created by Jonas Mendoza on 4/26/24.
//

#include "LetterObject.h"


LetterObject::LetterObject() {
    //Set the font of the text
    text = sf::Text();
    text.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setPosition(1, TEXT_BOX_Y + 3);
}


void LetterObject::update() {
    //Empty
}

void LetterObject::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void LetterObject::setCharacter(char typedChar) {
    text.setString(typedChar);
}

//Get the character of the letter object
char LetterObject::getCharacter() const {
    return text.getString().toAnsiString()[0];
}

sf::Vector2f LetterObject::getPosition() {
    return text.getPosition();
}

void LetterObject::setPosition(const sf::Vector2f& position) {
    text.setPosition(position);
}

void LetterObject::setState(ObjectState state) {
    //Set the color of the text depending on the state
    if(state == ENABLED)
        text.setFillColor(sf::Color::White);
    else {
        text.setFillColor({128,128, 128, 90});
    }
}

sf::FloatRect LetterObject::getLocalBounds() const {
    return text.getLocalBounds();
}

