//
// Created by jnmen on 6/7/2024.
//

#include "SquareText.h"

SquareText::SquareText() {
    //Set the dimmensions for default square
    square.setSize(sizeSqr);
    square.setFillColor({0,0,0,0});
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(1.0f);
    square.setOrigin(sizeSqr.x/2, sizeSqr.y/2);
    square.setPosition(WINDOW_CENTER);

    //Set the font
    numberDisplay.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    numberDisplay.setCharacterSize(sizeText);
    numberDisplay.setFillColor(sf::Color::White);
    numberDisplay.setString("NULL");
    numberDisplay.setOrigin(sizeSqr.x/2, sizeSqr.y/2);
    numberDisplay.setPosition(WINDOW_CENTER);

}

SquareText::SquareText(sf::Vector2f size, std::string data) {
    //Set the dimmensions for default square
    square.setSize(size);
    square.setFillColor({0,0,0,0});
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(1.0f);
    square.setOrigin(size.x/2, size.y/2);
    square.setPosition(WINDOW_CENTER);

    //Set the font
    numberDisplay.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    numberDisplay.setCharacterSize(sizeText);
    numberDisplay.setFillColor(sf::Color::White);
    numberDisplay.setString(data);
    sf::FloatRect textRect = numberDisplay.getLocalBounds();
    numberDisplay.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    numberDisplay.setPosition(WINDOW_CENTER);
}

void SquareText::update() {
    //UPDATE ARRAY SHAPE
}

void SquareText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform = square.getTransform();

    target.draw(square);
    target.draw(numberDisplay);
}

void SquareText::rotate(float angle) {
    square.rotate(angle);
    numberDisplay.rotate(angle);
}

void SquareText::move(sf::Vector2<float> offset) {
    square.move(offset);
    numberDisplay.move(offset);
}

void SquareText::zoom(float factor) {
    square.scale(factor, factor);
    numberDisplay.scale(factor, factor);
}

void SquareText::setPosition(const sf::Vector2f& position) {
    square.setPosition(position);
    numberDisplay.setPosition(position);
}

void SquareText::setData(const std::string& data) {
    numberDisplay.setString(data);

}

void SquareText::setFont(EnumFonts font) {
    numberDisplay.setFont(FontManager::getFont(font));
}

void SquareText::setFontSize(unsigned int size) {
    numberDisplay.setCharacterSize(size);
}

sf::FloatRect SquareText::getLocalBounds() const {
    return square.getLocalBounds();
}

std::string SquareText::getData() const {
    return data;
}




