//
// Created by jnmen on 6/8/2024.
//

#ifndef NODE_H
#define NODE_H
#include <SFML/System/Vector2.hpp>

template <typename T>
struct  Node {
    T data;
    Node* right;
    Node* left;
    Node* parent;
    int height;

    Node(): data(0), right(nullptr), left(nullptr), height(0), parent(nullptr) {}
    explicit Node(T data) : data(data), right(nullptr), left(nullptr), height(0), parent(nullptr) {}
    Node(T data, Node* right, Node* left) : data(data), right(right), left(left), height(0), parent(nullptr) {}

    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }

    sf::Vector2f getPosition() const {
        return position;
    }

private:
    sf::Vector2f position;


};
#endif //NODE_H
