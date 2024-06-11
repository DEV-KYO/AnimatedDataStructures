//
// Created by jnmen on 6/8/2024.
//

#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#include "../Node.h"

template <typename T>
class BST {
private:
    Node<T>* root = nullptr;
    void clear(Node<T>*& node);

    int _size = 0;

    void inOrder(Node<T>* node, void(*f)(T&param));
    void preOrder(Node<T>* node, void(*f)(T&param));
    void postOrder(Node<T>* node, void(*f)(T&param));
    void insert(Node<T>*& node, T data);
    void remove(Node<T>*& node, T data);


public:
    BST();
    ~BST();
    void inOrder(void(*f)(T&param));
    void preOrder(void(*f)(T&param));
    void postOrder(void(*f)(T&param));
    void insert(T data);
    void remove(T data);

    void breadthOrder(void(*f)(T&param));
    void depthOrder(void(*f)(T&param));
    void clear();


    [[nodiscard]] Node<T>* getRoot() const;
    [[nodiscard]] int size() const;
    [[nodiscard]] bool empty() const;
};

#include "BST.cpp"

#endif //BST_H
