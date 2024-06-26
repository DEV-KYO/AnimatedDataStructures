//
// Created by jnmen on 6/8/2024.
//

#include "AnimateTrees.h"

#include <cmath>

AnimateTrees::AnimateTrees() {

    BSTButton = Button( "BST",
                        sf::Vector2f(20, TEXT_BOX_Y +20));

    AVLButton = Button( "AVL",
                        sf::Vector2f(BSTButton.getGlobalBounds().left + BSTButton.getGlobalBounds().width + 20,
                        TEXT_BOX_Y + 20));

    HeapButton = Button("HEAP",
                        sf::Vector2f(AVLButton.getGlobalBounds().left + AVLButton.getGlobalBounds().width + 20,
                        TEXT_BOX_Y + 20));

    root = nullptr;
    data = std::vector<std::string>();
    view.setCenter({WINDOW_CENTER.x, 10});

    // Set the new size of the view
    view.setSize(WINDOW_SIZE);

}

AnimateTrees::AnimateTrees(Node<CircleText>* root) {
    this->root = root;
    BSTButton = Button( "BST",
                        sf::Vector2f(20, TEXT_BOX_Y +20));

    AVLButton = Button( "AVL",
                        sf::Vector2f(BSTButton.getGlobalBounds().width + 20,
                        TEXT_BOX_Y + 20));

    HeapButton = Button("HEAP",
                        sf::Vector2f(AVLButton.getGlobalBounds().left + AVLButton.getGlobalBounds().width + 20,
                        TEXT_BOX_Y + 20));

}

void AnimateTrees::selectTree(EnumTree type) {
    this->type = type;
    switch(type) {
        case EnumTree::BST:
            bst.clear();


        for (const auto& item : data) {
            bst.insert(CircleText(item));
        }
        root = bst.getRoot();

        break;

        case EnumTree::AVL:
        for(const auto& item : data) {
            avl.insert(CircleText(item));
        }
        root = avl.getRoot();
        break;

        case EnumTree::HEAP:
            heap.clear();
        for(const auto& item : data) {
            heap.push(CircleText(item));
        }
        root = heap.getRoot();
        break;
        default:
            std::cerr << "NO TREE SELECTED" << std::endl;
        break;
    }
    setPosition();
}

void AnimateTrees::update() {
    setPosition();
}

void AnimateTrees::eventHandler(sf::RenderWindow& window, sf::Event& event) {
    // Set the center of the view to the position of the mouse cursor
    switch(event.type) {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if(BSTButton.checkClick(mousePos))
                    this->selectTree(EnumTree::BST);

                if(AVLButton.checkClick(mousePos))
                    this->selectTree(EnumTree::AVL);

                if(HeapButton.checkClick(mousePos))
                    this->selectTree(EnumTree::HEAP);
            }
            break;
        case sf::Event::MouseWheelScrolled:
            if (event.mouseWheelScroll.delta > 0) {
                zoom(0.9f);
            } else {
                zoom(1.1f);
            }
            break;
        case sf::Event::KeyPressed:
            case sf::Keyboard::Return:
                std::cout << "Return selecting tree type and setting pos" << std::endl;
                this->selectTree(type);
                break;
    }
}

void AnimateTrees::zoom(float factor) {
    // Calculate the aspect ratio of the window
    float aspectRatio = WINDOW_SIZE.x / WINDOW_SIZE.y;

    // Calculate the new width and height of the view
    float newWidth = view.getSize().x * factor;
    float newHeight = newWidth / aspectRatio;

    // Set the new size of the view
    view.setSize(newWidth, newHeight);
}

void AnimateTrees::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //draw every node in the tree
    BSTButton.draw(target);
    AVLButton.draw(target);
    HeapButton.draw(target);

    target.setView(view);
    drawNode(target, states, root);
}

void AnimateTrees::drawNode(sf::RenderTarget& target, sf::RenderStates states, Node<CircleText>* node) const {
    if (node == nullptr) {
        return;
    }

    // Draw lines to the left and right children
    if (node->left != nullptr) {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = node->data.getPosition();
        line[1].position = node->left->data.getPosition();
        target.draw(line, states);
    }
    if (node->right != nullptr) {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = node->data.getPosition();
        line[1].position = node->right->data.getPosition();
        target.draw(line, states);
    }

    // Draw the node's data
    node->data.draw(target, states);

    // Recursively draw the left and right children
    drawNode(target, states, node->left);
    drawNode(target, states, node->right);
}

void AnimateTrees::setPositionRecursive(Node<CircleText>* node, int x, int y, int depth) {
    if (node == nullptr) {
        return;
    }

    float offset = (400/ std::pow(depth,1.7324)) * zoomFactor;  // Decrease the offset as the depth increases
    float offset2 = (50) * zoomFactor;

    if (node->left != nullptr) {
        node->left->data.setPosition(sf::Vector2f(x - offset, y + offset2));
        node->left->data.zoom(zoomFactor);  // Set the scale of the node
        setPositionRecursive(node->left, x - offset, y + offset2, depth + 1);
    }

    if (node->right != nullptr) {
        node->right->data.setPosition(sf::Vector2f(x + offset, y + offset2));
        node->right->data.zoom(zoomFactor);  // Set the scale of the node
        setPositionRecursive(node->right, x + offset, y + offset2, depth + 1);
    }
}

void AnimateTrees::setPosition() {
    if (root == nullptr) {
        return;
    }

    root->data.setPosition(sf::Vector2f(WINDOW_CENTER.x, 30));

    setPositionRecursive(root, WINDOW_CENTER.x, 0, 1);
}

void AnimateTrees::zoomIn() {
    zoomFactor += 0.1f;
    setPosition();
}

void AnimateTrees::zoomOut() {
    zoomFactor -= 0.1f;
    setPosition();
}


void AnimateTrees::push_back(const std::string &data) {
    // Check if the data already exists in the vector
    if (std::find(this->data.begin(), this->data.end(), data) == this->data.end()) {
        // If it does not exist, insert it
        this->data.push_back(data);
    }
}

void AnimateTrees::pop_back() {
    this->data.pop_back();
}


void AnimateTrees::clear() {
    this->data.clear();
}

void AnimateTrees::setRoot(Node<CircleText> *root) {
    this->root = root;
}

Node<CircleText>* AnimateTrees::getRoot() const {
    return root;
}

EnumTree AnimateTrees::getType() const {
    return type;
}