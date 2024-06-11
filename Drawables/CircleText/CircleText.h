//
// Created by jnmen on 6/8/2024.
//

#ifndef CIRCLETEXT_H
#define CIRCLETEXT_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../Settings.h"
#include "../../Font/FontManager.h"
#include "../../Font/EnumFonts.h"

class CircleText {
private:
    sf::Text number;
    sf::CircleShape circle;
    std::string data;
    int num;

    float radius = 25.0f;
    int sizeText = 20;

public:
    CircleText();
    explicit CircleText(const std::string& data);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void zoom(float factor);

    //setters
    void setPosition(const sf::Vector2f& position);
    void setData(const std::string& data);
    void setFont(const sf::Font& font);
    void setFontSize(unsigned int size);

    //getters
    sf::FloatRect getLocalBounds() const;
    std::string getData() const;
    sf::Vector2f getPosition() const;

    //overload operators
    bool operator==(const CircleText& rhs) const;
    bool operator!=(const CircleText& rhs) const;
    bool operator<(const CircleText& rhs) const;
    bool operator>(const CircleText& rhs) const;
    bool operator<=(const CircleText& rhs) const;
    bool operator>=(const CircleText& rhs) const;

};



#endif //CIRCLETEXT_H
