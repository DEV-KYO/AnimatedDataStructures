//
// Created by jnmen on 6/8/2024.
//

#ifndef BST_CPP
#define BST_CPP

#include "BST.h"


template<typename T>
BST<T>::BST() = default;

template<typename T>
void BST<T>::inOrder(void (*f)(T &param)) {
    inOrder(root, f);
}

template<typename T>
void BST<T>::preOrder(void (*f)(T &param)) {
    preOrder(root, f);
}

template<typename T>
void BST<T>::postOrder(void (*f)(T &param)) {
    postOrder(root, f);
}

template<typename T>
void BST<T>::insert(T data) {
    insert(root, data);
}

template<typename T>
void BST<T>::breadthOrder(void (*f)(T &param)) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();

        f(current->data);

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

template<typename T>
void BST<T>::depthOrder(void (*f)(T &param)) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node<T>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<T>* current = s.top();
        s.pop();

        f(current->data);

        if (current->right != nullptr) {
            s.push(current->right);
        }

        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
}

template<typename T>
void BST<T>::remove(T data) {
    remove(root, data);
}

template<typename T>
Node<T>* BST<T>::getRoot() const {
    return root;
}

template<typename T>
int BST<T>::size() const {
    return _size;
}

template<typename T>
bool BST<T>::empty() const {
    return _size == 0;
}

template<typename T>
void BST<T>::inOrder(Node<T> *node, void (*f)(T &param)) {
    if (node == nullptr) {
        return;
    }

    inOrder(node->left, f);
    f(node->data);
    inOrder(node->right, f);
}

template<typename T>
void BST<T>::preOrder(Node<T> *node, void (*f)(T &param)) {
    if (node == nullptr) {
        return;
    }

    f(node->data);
    preOrder(node->left, f);
    preOrder(node->right, f);
}

template<typename T>
void BST<T>::postOrder(Node<T> *node, void (*f)(T &param)) {
    if (node == nullptr) {
        return;
    }

    postOrder(node->left, f);
    postOrder(node->right, f);
    f(node->data);
}

template<typename T>
void BST<T>::insert(Node<T>*& node, T data) {
    if (node == nullptr) {
        node = new Node<T>(data);
        _size++;
        return;
    }

    if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

template<typename T>
void BST<T>::remove(Node<T>*& node, T data) {
    if (node == nullptr) {
        return;
    }

    if (data < node->data) {
        remove(node->left, data);
    } else if (data > node->data) {
        remove(node->right, data);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            _size--;
        } else if (node->left == nullptr) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
            _size--;
        } else if (node->right == nullptr) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
            _size--;
        } else {
            Node<T>* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

template<typename T>
void BST<T>::clear() {
    while (root != nullptr) {
        remove(root, root->data);
    }
}


#endif //BST_CPP
