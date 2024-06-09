//
// Created by jnmen on 6/8/2024.
//

#include "CircleText.h"

CircleText::CircleText() {
    circle.setPointCount(25);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    circle.setRadius(radius);
    //set origin at the center of the circle
    circle.setOrigin(radius/2, radius/2);
    circle.setPosition(WINDOW_CENTER);

    //set the font
    number.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    number.setCharacterSize(sizeText);
    number.setFillColor(sf::Color::White);
    number.setString("NULL");
    number.setOrigin(radius/2, radius/2);
    number.setPosition(WINDOW_CENTER);
}

CircleText::CircleText(const std::string& data) {
    circle.setPointCount(25);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(1);
    circle.setRadius(radius);
    //set origin at the center of the circle
    circle.setOrigin(radius, radius);
    circle.setPosition(WINDOW_CENTER);

    //set the font
    number.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    number.setCharacterSize(sizeText);
    number.setFillColor(sf::Color::White);
    number.setString(data);
    sf::FloatRect textRect = number.getLocalBounds();
    number.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    number.setPosition(WINDOW_CENTER);

    num = std::stoi(data);
}

void CircleText::update() {
    //UPDATE ARRAY SHAPE
}

void CircleText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform = circle.getTransform();

    target.draw(circle);
    target.draw(number);
}

void CircleText::zoom(float factor) {
    circle.setScale(factor, factor);
    number.setScale(factor, factor);
}

void CircleText::setPosition(const sf::Vector2f& position) {
    circle.setPosition(position);
    number.setPosition(position);
}

void CircleText::setData(const std::string& data) {
    number.setString(data);
    sf::FloatRect textRect = number.getLocalBounds();
    number.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
}

void CircleText::setFont(const sf::Font& font) {
    number.setFont(font);
}

void CircleText::setFontSize(unsigned int size) {
    number.setCharacterSize(size);
}

sf::FloatRect CircleText::getLocalBounds() const {
    return number.getLocalBounds();
}

sf::Vector2f CircleText::getPosition() const {
    return circle.getPosition();
}

std::string CircleText::getData() const {
    return data;
}

bool CircleText::operator==(const CircleText& rhs) const {
    return num == rhs.num;
}

bool CircleText::operator!=(const CircleText& rhs) const {
    return num != rhs.num;
}

bool CircleText::operator<(const CircleText& rhs) const {
    return num < rhs.num;
}

bool CircleText::operator>(const CircleText& rhs) const {
    return num > rhs.num;
}

bool CircleText::operator<=(const CircleText& rhs) const {
    return num <= rhs.num;
}

bool CircleText::operator>=(const CircleText& rhs) const {
    return num >= rhs.num;
}
