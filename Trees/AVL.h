//
// Created by jnmen on 6/9/2024.
//

#ifndef AVL_H
#define AVL_H
#include "../Node.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>


template <typename T>
class AVL {
private:
    Node<T>* root;
    void clear(Node<T>* node);
    int size;

    void inOrder(Node<T>* node, void(*f)(T&param));
    void preOrder(Node<T>* node, void(*f)(T&param));
    void postOrder(Node<T>* node, void(*f)(T&param));
    void insert(Node<T>*& node, T data);
    void remove(Node<T>*& node, T data);
    Node<T>* findMin(Node<T>* node);

public:
    AVL();
    // ~AVL();

    void inOrder(void(*f)(T&param));
    void preOrder(void(*f)(T&param));
    void postOrder(void(*f)(T&param));
    void insert(T data);
    void leftRotate(Node<T>*& node);
    void rightRotate(Node<T>*& node);

    int height(Node<T>* node);
    int getBalance(Node<T>* node);
    void balance(Node<T>*& node);

    void remove(T data);

    void breadthOrder(void(*f)(T&param));
    void depthOrder(void(*f)(T&param));
    void clear();

    Node<T>* getRoot() const;
    int getSize() const;
    bool empty() const;

public:

};

#include "AVL.cpp"

#endif //AVL_H
