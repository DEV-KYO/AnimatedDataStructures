//
// Created by jnmen on 6/8/2024.
//

#ifndef ANIMATETREES_H
#define ANIMATETREES_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>

#include "AVL.h"
#include "../Drawables/CircleText/CircleText.h"
#include "BST.h"
#include "../Node.h"
#include "EnumTree.h"
#include "Heap.h"
#include "../Settings.h"

class AnimateTrees {
private:
    sf::View view;
    std::vector<std::string> data;
    float zoomFactor = 1.0f;

    Node<CircleText>* root;
    EnumTree type = EnumTree::BST;
    BST<CircleText> bst;
    AVL<CircleText> avl;
    Heap<CircleText> heap;
    // Heap heap;

    int radius = 30;

    void setPosition();
    void setPositionRecursive(Node<CircleText>* node, int x, int y, int depth);
public:
    AnimateTrees();
    explicit AnimateTrees(Node<CircleText>* root);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawNode(sf::RenderTarget& target, sf::RenderStates states, Node<CircleText>* node) const;

    void update();
    void updateNode(Node<CircleText>* node);

    void eventHandler(sf::RenderWindow& window, sf::Event& event);

    void zoom(float factor);

    void zoomIn();
    void zoomOut();

    void push_back(const std::string& data);
    void push_front(const std::string& data);
    void pop_back();
    void pop_front();
    void clear();

    void selectTree(EnumTree type);

    void setRoot(Node<CircleText>* root);

    [[nodiscard]] Node<CircleText>* getRoot() const;
};



#endif //ANIMATETREES_H
