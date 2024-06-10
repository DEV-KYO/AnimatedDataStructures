//
// Created by jnmen on 6/1/2024.
//

#include "AnimatedLinkedList.h"
#include <iostream>

#include "../Settings.h"

AnimatedLinkedList::AnimatedLinkedList() {
    // Create a NodeShape object with an empty string as data
    center = {800, 450};
    list.emplace_back( "HEAD");
    for(auto& node : list) {
        node.setPosition(center);
        node.headPointer();
    }
    view.setCenter(WINDOW_CENTER);
    view.setSize(WINDOW_SIZE);
}

AnimatedLinkedList::AnimatedLinkedList(const std::vector<std::string>& data) {
    for (const auto& d : data) {
        // Create a NodeShape object for each string in the data vector
        list.emplace_back(d);
    }
}
void AnimatedLinkedList::push_back(const std::string &data) {
    list.emplace_back(data);

    // Set the position of the new node to be next to the last one and center the position of the list
    setPosition(center);
}

void AnimatedLinkedList::push_front(const std::string &data) {
    if(isalpha(data[0]) || isdigit(data[0])) {
        auto it = list.begin();
        list.erase(it);
        list.emplace_front(data);
        list.emplace_front("HEAD");
        //fix "HEAD" with headPointer()
        it = list.begin();
        it->headPointer();
        setPosition(center);
    }
}

void AnimatedLinkedList::pop_back() {
    if(list.size() > 1)
        list.pop_back();
    setPosition(center);
}

void AnimatedLinkedList::pop_front() {
    if(list.size() > 1) {
        auto it = list.begin();
        it++;
        list.erase(it);
    }
    setPosition(center);
}

void AnimatedLinkedList::clear() {
    list.clear();
    list.emplace_back("HEAD");
    for(auto& node : list) {
        node.setPosition(center);
        node.headPointer();
    }
    setPosition(center);
}


void AnimatedLinkedList::setPosition(const sf::Vector2f &center) {
    float nodeWidth = list.front().getSize().x;
    float space = 85; // the space between nodes
    int numNodes = list.size();

    float totalWidth = numNodes * nodeWidth + (numNodes - 1) * space;
    float startX = center.x - totalWidth / 2;

    float x = startX;
    float y = center.y;
    for (auto& node : list) {
        node.setPosition({x, y});
        x += nodeWidth + space;
    }
}



void AnimatedLinkedList::update() {
    for (auto& n : list) {
        n.update();
    }
}

void AnimatedLinkedList::draw(sf::RenderWindow &target, sf::RenderStates states) const {
    target.setView(view);
    for (auto& node : list) {
        if (!node.getData().empty()) { // Only draw the node if it is not empty
            target.draw(node, states);
        }
    }
}



void AnimatedLinkedList::zoom(float factor) {
    // Calculate the aspect ratio of the window
    float aspectRatio = WINDOW_SIZE.x / WINDOW_SIZE.y;

    // Calculate the new width and height of the view
    float newWidth = view.getSize().x * factor;
    float newHeight = newWidth / aspectRatio;

    // Set the new size of the view
    view.setSize(newWidth, newHeight);
}

void AnimatedLinkedList::eventHandler(sf::RenderWindow &window, sf::Event &event) {

    // Set the center of the view to the position of the mouse cursor
    view.setCenter(WINDOW_CENTER);
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            zoom(0.9f);
        } else {
            zoom(1.1f);
        }
    }
}