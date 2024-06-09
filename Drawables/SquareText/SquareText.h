//
// Created by jnmen on 6/7/2024.
//

#ifndef SQUARETEXT_H
#define SQUARETEXT_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../../Settings.h"
#include "../../Font/FontManager.h"
#include "../../Font/EnumFonts.h"




class SquareText {
private:
    //Shape Values
    sf::Text numberDisplay;
    sf::RectangleShape square;
    std::string data;

    //Size Values
    sf::Vector2f sizeSqr = sf::Vector2f(50, 50);
    int sizeText = 20;

    //Position Values

public:
    SquareText();
    SquareText(sf::Vector2f size, std::string data);

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void rotate(float angle);
    void move(sf::Vector2<float> offset);
    void zoom(float factor);

    //Setters
    void setPosition(const sf::Vector2f& position);
    void setData(const std::string& data);
    void setFont(EnumFonts font);
    void setFontSize(unsigned int size);

    //Getters
    sf::FloatRect getLocalBounds() const;
    std::string getData() const;


};



#endif //ARRAYSHAPE_H
