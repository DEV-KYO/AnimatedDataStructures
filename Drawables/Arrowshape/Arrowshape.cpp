//
// Created by jnmen on 5/29/2024.
//

#include "Arrowshape.h"
Arrowshape::Arrowshape() {
    // Default constructor
}

Arrowshape::Arrowshape(const sf::Vector2f &size, Direction direction) : triangle(size.x * 1/6.0f,3), direction(direction)  {
    // Constructor with size and direction
    // /////////////////////////////////////////////////////////////////////
    //                    --OUTLINE-- ERASE WHEN DONE                    //
    triangle.setFillColor(sf::Color(0,0,0));
    triangle.setOutlineColor(sf::Color({0,255,0}));
    triangle.setOutlineThickness(1.0f);

    line.setFillColor(sf::Color(0,0,0));
    line.setOutlineColor(sf::Color({0,255,0}));
    line.setOutlineThickness(1.0f);
    // /////////////////////////////////////////////////////////////////////

    //2 to 1 ratio for the head and body
    float radius = size.x * 1/6.0f;

    //rectangle length and height
    float width = size.x * 2/3;
    float height = (radius * 2) / 3;

    //height of head is 3 to 1
    line.setSize({height, width});

    sf::FloatRect b = line.getLocalBounds();
    sf::FloatRect h = triangle.getLocalBounds();

    triangle.setOrigin({radius, 0});
    triangle.setPosition({(height/2), -radius});
    line.setOrigin({height/2, width});
    line.setPosition({(width * 1/6), radius});

    line.rotate(point(direction));

    arrowtip = getCenter(triangle);
    arrowbase = getCenter(line);
    //position head to the right of body

    //body centered to head



}

void Arrowshape::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    // Draws the arrow shape
    states.transform = line.getTransform();
    window.draw(line);
    window.draw(triangle, states);
}



void Arrowshape::update() {
    // Updates the arrow shape

}

void Arrowshape::move(sf::Vector2<float> offset) {
    //function to move the arrow
    line.move(offset);
}

void Arrowshape::zoom(float factor) {
    //function to zoom the arrow (scale the arrow)
    line.scale(factor, factor);
}

void Arrowshape::rotate(float angle) {
    //function to rotate the arrow
    sf::Transformable::rotate(angle); //rotate the arrow using sf::Transformable
    line.rotate(angle);
}

float Arrowshape::point(Direction direction) {
    //function to get the direction of the arrow (in degrees)
    switch (direction) {
        case Direction::UP:
            return 0.0f;
        case Direction::DOWN:
            return 180.0f;
        case Direction::LEFT:
            return 270.0f;
        case Direction::RIGHT:
            return 90.0f;
    }
}


void Arrowshape::setDirection(Direction direction) {
    // Sets the direction of the arrow
    this->direction = direction;
}

void Arrowshape::setPosition(const sf::Vector2f &position) {
    // Sets the position of the arrow
    line.setPosition(position);
}

sf::Vector2f Arrowshape::getCenter(sf::Shape &shape) {
    //function to get the center of an object
    return sf::Vector2f(shape.getGlobalBounds().left + shape.getGlobalBounds().width / 2,
                        shape.getGlobalBounds().top + shape.getGlobalBounds().height / 2);
}

sf::Vector2f Arrowshape::getBasePosition() const {
    // Returns the position of the arrow base
    return arrowbase;
}

sf::Vector2f Arrowshape::getTipPosition() const {
    // Returns the position of the arrow tip
    return arrowtip;
}

Direction Arrowshape::getDirection() const {
    // Returns the direction of the arrow
    return direction;
}

