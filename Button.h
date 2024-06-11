//
// Created by jnmen on 6/10/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>

#include <functional>
#include <utility>


#include "Font/FontManager.h"
#include "Font/EnumFonts.h"
#include "MouseEvents/MouseEvents.h"


class Button {
private:
    sf::RectangleShape button;
    sf::Text text;

    MouseEvents<sf::RectangleShape> mouseEvents;

public:
    Button() = default;
    Button(const std::string& label, sf::Vector2f position);
    void draw(sf::RenderTarget& target) const;
    bool checkClick(sf::Vector2f mousePos);

    void setText(const std::string& text);
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    //Get Global Bounds
    sf::FloatRect getGlobalBounds() const;



};



#endif //BUTTON_H
