//
// Created by jnmen on 6/9/2024.
//

#ifndef HEAP_CPP
#define HEAP_CPP
#include "Heap.h"

template<typename T>
Heap<T>::Heap() {
    root = nullptr;
    size = 0;
    nodes = std::vector<Node<T>*>();

}

template<typename T>
Heap<T>::Heap(Node<T>* root) {
    this->root = root;
    size = 0;
    nodes = std::vector<Node<T>*>();
    heapify();
}

template<typename T>
void Heap<T>::push(T data) {
    Node<T>* node = new Node<T>(data);
    nodes.push_back(node);
    if (root == nullptr) {
        root = node;
    } else {
        Node<T>* parent = nodes[getParent(size)];
        if (parent->left == nullptr) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        node->parent = parent;
        siftUp(node);
    }
    size++;
}

template<typename T>
void Heap<T>::pop() {
    if (size == 0) {
        return;
    }
    Node<T>* last = nodes[size - 1];
    if (size == 1) {
        root = nullptr;
    } else {
        swap(root, last);
        Node<T>* parent = last->parent;
        if (parent->left == last) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        siftDown(root);
    }
    size--;
}

template<typename T>
T& Heap<T>::top() {
    return root->data;
}

template<typename T>
int Heap<T>::getSize() {
    return size;
}

template<typename T>
Node<T>* Heap<T>::getRoot() {
    return root;
}

template<typename T>
void Heap<T>::clear() {
    root = nullptr;
    size = 0;
    nodes.clear();
}

template<typename T>
bool Heap<T>::empty() {
    return size == 0;
}

template<typename T>
void Heap<T>::siftUp(Node<T>* node) {
    Node<T>* parent = node->parent;
    while (parent != nullptr && node->data > parent->data) {
        swap(node, parent);
        node = parent;
        parent = node->parent;
    }
}

template<typename T>
void Heap<T>::siftDown(Node<T>* node) {
    while (node != nullptr) {
        int maxChildIndex = getMaxChild(node);
        if (maxChildIndex == -1) {
            return;
        }
        Node<T>* maxChild = nodes[maxChildIndex];
        if (node->data < maxChild->data) {
            swap(node, maxChild);
            node = maxChild;
        } else {
            return;
        }
    }
}

template<typename T>
void Heap<T>::swap(Node<T>* a, Node<T>* b) {
    T temp = a->data;
    a->data = b->data;
    b->data = temp;
}

template<typename T>
void Heap<T>::heapify() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDown(nodes[i]);
    }
}

template<typename T>
int Heap<T>::getLeftChild(int parentIndex) {
    int leftChildIndex = 2 * parentIndex + 1;
    return leftChildIndex < size ? leftChildIndex : -1;
}

template<typename T>
int Heap<T>::getRightChild(int parentIndex) {
    int rightChildIndex = 2 * parentIndex + 2;
    return rightChildIndex < size ? rightChildIndex : -1;
}

template<typename T>
int Heap<T>::getParent(int childIndex) {
    return (childIndex - 1) / 2;
}

template<typename T>
int Heap<T>::getMaxChild(int parentIndex) {
    int leftChildIndex = getLeftChild(parentIndex);
    int rightChildIndex = getRightChild(parentIndex);
    if (leftChildIndex == -1 && rightChildIndex == -1) {
        return -1;
    }
    if (leftChildIndex == -1) {
        return rightChildIndex;
    }
    if (rightChildIndex == -1) {
        return leftChildIndex;
    }
    return nodes[leftChildIndex]->data > nodes[rightChildIndex]->data ? leftChildIndex : rightChildIndex;
}




#endif //HEAP_CPP
