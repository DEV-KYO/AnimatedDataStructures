//
// Created by jnmen on 6/10/2024.
//

#include "Button.h"


Button::Button(const std::string& label, sf::Vector2f position) {
    text = sf::Text(label, FontManager::getFont(PIXELGEORGIA) , 12);

    sf::Vector2f textBounds = {text.getLocalBounds().width, text.getLocalBounds().height};

    button.setSize({textBounds.x + 10, textBounds.y + 10});
    button.setFillColor(sf::Color::Transparent);
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(1);
    button.setPosition(position);

    text.setPosition(
        button.getPosition().x + (button.getSize().x - textBounds.x) / 2,
        button.getPosition().y + (button.getSize().y - textBounds.y) / 2
    );
}

void Button::draw(sf::RenderTarget& target) const {
    target.draw(button);
    target.draw(text);
}

bool Button::checkClick(sf::Vector2f mousePos) {
    if(button.getGlobalBounds().contains(mousePos)) {
        return true;
    }
    return false;
}


void Button::setText(const std::string& text) {
    this->text.setString(text);
}

void Button::setPosition(const sf::Vector2f& position) {
    button.setPosition(position);
}

void Button::setSize(const sf::Vector2f &size) {
    button.setSize(size);
}

sf::FloatRect Button::getGlobalBounds() const{
    return button.getGlobalBounds();
}