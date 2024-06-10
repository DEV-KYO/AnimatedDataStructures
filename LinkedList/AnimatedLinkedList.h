//
// Created by jnmen on 6/1/2024.
//

#ifndef ANIMATEDLINKEDLIST_H
#define ANIMATEDLINKEDLIST_H
#include <List>
#include "../Drawables/NodeShape/NodeShape.h"

class AnimatedLinkedList : public NodeShape {
private:
    sf::View view; //view of the window
    std::list<NodeShape> list; //list of nodes
    sf::Vector2f center; //center of the window


public:
    AnimatedLinkedList(); //constructor to initialize the linked list
    explicit AnimatedLinkedList(const std::vector<std::string>& data); //constructor to initialize the linked list with data


    void push_back(const std::string& data); //function to add a node to the linked list
    void push_front(const std::string& data); //function to add a node to the front of the linked list
    void pop_back(); //function to remove a node from the linked list
    void pop_front(); //function to remove a node from the front of the linked list
    void clear(); //function to clear the linked list

    void setPosition(const sf::Vector2f& position); //function to set the position of the linked list


    void update(); //function to update the linked list
    void draw(sf::RenderWindow& target, sf::RenderStates states) const; //function to draw the linked list
    void zoom(float factor); //function to zoom the linked list
    void eventHandler(sf::RenderWindow& window, sf::Event& event); //function to handle events
};


#endif //LINKEDLIST_H
