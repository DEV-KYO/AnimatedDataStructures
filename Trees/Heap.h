//
// Created by jnmen on 6/9/2024.
//

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include "../Node.h"


//THIS IS A MAX HEAP
template<typename T>
class Heap {
private:
    Node<T>* root;
    void clear(Node<T>* node);

    std::vector<Node<T>*> nodes;
    int size;
    void siftUp(Node<T>* node);
    void siftDown(Node<T>* node);
    void swap(Node<T>* a, Node<T>* b);
    void heapify();

    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getParent(int childIndex);
    int getMaxChild(int parentIndex);


public:
    Heap();
    explicit Heap(Node<T>* root);
    void push(T data);
    void pop();
    T& top();
    int getSize();
    Node<T>* getRoot();
    void clear();
    bool empty();

};

#include "Heap.cpp"

#endif //HEAP_H
