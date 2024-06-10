//
// Created by jnmen on 6/9/2024.
//

#include "AnimatedHashtable.h"

#include <iostream>

AnimatedHashtable::AnimatedHashtable() {
    hashtable = new Hashtable<int>(10);
    capacity = 10;
    for(auto i : verticalArrayShapes) {
        verticalArrayShapes.push_back(i);
        i.headPointer();
    }
    view.setCenter(WINDOW_CENTER);
    view.setSize(WINDOW_SIZE);
}

void AnimatedHashtable::createHashtable() {
    for (int i = 0; i < data.size(); i++) {
        insert(data[i]);
    }
    data.clear();
}

void AnimatedHashtable::update() {
    for(auto i : verticalArrayShapes) {
        i.update();
    }
    for(auto i : linkedListShapes) {
        i.update();
    }
}

void AnimatedHashtable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.setView(view);

    // Set the starting x-coordinate to a fixed value
    float startX = WINDOW_CENTER.x - WINDOW_SIZE.x / 4; // Adjust this value as needed

    // Calculate the total height of the nodes and the spaces between them
    float totalHeight = hashtable->getCapacity() * 50 + (hashtable->getCapacity() - 1) * 10;

    // Calculate the starting y-coordinate
    float startY = WINDOW_CENTER.y - totalHeight / 2;

    // Draw the hashtable
    for (int i = 0; i < hashtable->getCapacity(); i++) {
        std::vector<int> entries = hashtable->getTable()[i];

        // Create a NodeShape object for the head pointer
        NodeShape headPointer("EMPTY");
        headPointer.headPointer();
        headPointer.setFontSize(10);
        headPointer.setPosition({startX, startY + i * (50 + 10)});
        target.draw(headPointer, states);

        // Create NodeShape objects for each entry in the row
        for (int j = 0; j < entries.size(); j++) {
            NodeShape nodeShape(std::to_string(entries[j]));
            nodeShape.oneWayNode();
            nodeShape.setPosition({startX + j * (50 + 25), startY + i * (50 + 10)});
            target.draw(nodeShape, states);
        }
    }
}

void AnimatedHashtable::eventHandler(sf::RenderWindow& window, sf::Event& event) {
    // Set the center of the view to the center of the window
    view.setCenter(WINDOW_CENTER);
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            zoom(0.9);
        } else {
            zoom(1.1);
        }
    }
}

void AnimatedHashtable::zoom(float factor) {
    // Calculate the aspect ratio of the window
    float aspectRatio = WINDOW_SIZE.x / WINDOW_SIZE.y;

    // Calculate the new width and height of the view
    float newWidth = view.getSize().x * factor;
    float newHeight = newWidth / aspectRatio;

    // Set the new size of the view
    view.setSize(newWidth, newHeight);
}

void AnimatedHashtable::setPosition() {

}

void AnimatedHashtable::setCapacity(int capacity) {
    this->capacity = capacity;
}

void AnimatedHashtable::insert(int key) {
    hashtable->insert(key);
}

void AnimatedHashtable::remove(int key) {
    hashtable->remove(key);
}

bool AnimatedHashtable::search(int key) {
    return hashtable->search(key);
}

void AnimatedHashtable::clear() {
    hashtable->clear();
}

void AnimatedHashtable::pushData(std::string data) {
    this->data.push_back(std::stoi(data));
}







