//
// Created by jnmen on 5/31/2024.
//

#ifndef NODESHAPE_H
#define NODESHAPE_H
#include <any>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>


#include "../Arrowshape/Arrowshape.h"
#include "../../Font/FontManager.h"
#include "../../Font/EnumFonts.h"


class NodeShape : public sf::RectangleShape {
private:
    Arrowshape prev, next;
    sf::RectangleShape prevBlock, nextBlock;
    sf::RectangleShape body;

    sf::Vector2f nodeSize;

    std::string data;
    sf::Font font;
    sf::Text text;

public:
    //Constructors
    NodeShape();
    explicit NodeShape(const std::string& data);
    NodeShape(const sf::Vector2f &size, const std::string& data);

    //Functions
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(const sf::Vector2f &position);

    //Transformations
    void rotate(float angle);
    void headPointer();
    void move(sf::Vector2<float> offset);
    void zoom(float factor);

    //Bounds
    void getLocalBounds(sf::FloatRect& rect) const;

    //Setters
    void setData(const std::string& data);
    void setFont(EnumFonts font);
    void setFontSize(unsigned int size);

    //Getters
    std::string getData() const;
};


#endif //NODESHAPE_H
