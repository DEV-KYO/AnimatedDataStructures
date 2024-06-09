//
// Created by jnmen on 5/29/2024.
//

#ifndef ARROWSHAPE_H
#define ARROWSHAPE_H
#include <SFML/Graphics.hpp>

#include "../EnumDrawables/EnumDirection.h"


class Arrowshape :      public sf::Drawable,
                        public sf::Transformable {
private:
    sf::CircleShape triangle;  // Triangle shape uses circle with 3 points to create a triangle
    sf::RectangleShape line;   // Line shape to create the arrow line

    sf::Vector2f arrowtip; //position of arrow tip
    sf::Vector2f arrowbase; //position of arrow base
    Direction direction; //direction of arrow


public:
    Arrowshape();                                   // Default constructor
    Arrowshape(const sf::Vector2f& size, Direction direction); // Constructor with size and direction
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override; // Draws the arrow shape
    void update();                                  // Updates the arrow shape

    void move(sf::Vector2<float> offset);//function to move the arrow
    void zoom(float factor);                        //function to zoom the arrow (scale the arrow)
    void rotate(float angle);                       //function to rotate the arrow


    static float point(Direction direction);        //function to get the direction of the arrow (in degrees)

    // Setters
    void setDirection(Direction direction);         // Sets the direction of the arrow
    void setPosition(const sf::Vector2f& position); // Sets the position of the arrow

    // Getters
    sf::Vector2f getBasePosition() const;           // Returns the position of the arrow base
    sf::Vector2f getTipPosition() const;            // Returns the position of the arrow tip
    Direction getDirection() const;                 // Returns the direction of the arrow
    sf::Vector2f getCenter(sf::Shape& shape);       //function to get the center of an object




};



#endif //ARROWSHAPE_H
