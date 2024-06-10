//
// Created by jnmen on 6/9/2024.
//

#ifndef ANIMATEDHASHTABLE_H
#define ANIMATEDHASHTABLE_H
#include "Hashtable.h"
#include "../Node.h"
#include "../LinkedList/AnimatedLinkedList.h"
#include "../Drawables/NodeShape/NodeShape.h"
#include "../Settings.h"

class AnimatedHashtable {
private:
    sf::View view;

    Hashtable<int>* hashtable;
    std::vector<NodeShape> linkedListShapes;
    std::vector<NodeShape> verticalArrayShapes;

    std::vector<int> data;


    int capacity;
    int size;

public:
    AnimatedHashtable();

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event& event);
    void zoom(float factor);

    void setPosition();
    void setCapacity(int capacity);
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void clear();

    void pushData(std::string data);
    void createHashtable();

};





#endif //ANIMATEDHASHTABLE_H
