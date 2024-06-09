//
// Created by jnmen on 6/9/2024.
//

#ifndef AVL_CPP
#define AVL_CPP
#include "AVL.h"

template <typename T>
AVL<T>::AVL() : root(nullptr), size(0) {}

template <typename T>
void AVL<T>::inOrder(Node<T>* node, void(*f)(T&param)) {
    if (node == nullptr) return;
    inOrder(node->left, f);
    f(node->data);
    inOrder(node->right, f);
}

template <typename T>
void AVL<T>::preOrder(Node<T>* node, void(*f)(T&param)) {
    if (node == nullptr) return;
    f(node->data);
    preOrder(node->left, f);
    preOrder(node->right, f);
}

template <typename T>
void AVL<T>::postOrder(Node<T>* node, void(*f)(T&param)) {
    if (node == nullptr) return;
    postOrder(node->left, f);
    postOrder(node->right, f);
    f(node->data);
}

template<typename T>
void AVL<T>::insert(Node<T>*& node, T data) {
    // 1. Perform the normal BST insertion
    if (node == nullptr) {
        node = new Node<T>(data);
        size++;
        return;
    }

    if (data < node->data) {
        insert(node->left, data);
    } else if (data > node->data) {
        insert(node->right, data);
    } else { // Equal datas are not allowed in BST
        return;
    }

    // 2. Update height of this ancestor node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // 4. Left Left Case
    if (balance > 1 && data < node->left->data) {
        rightRotate(node);
        return;
    }

    // 5. Right Right Case
    if (balance < -1 && data > node->right->data) {
        leftRotate(node);
        return;
    }

    // 6. Left Right Case
    if (balance > 1 && data > node->left->data) {
        leftRotate(node->left);
        rightRotate(node);
        return;
    }

    // 7. Right Left Case
    if (balance < -1 && data < node->right->data) {
        rightRotate(node->right);
        leftRotate(node);
        return;
    }
}

template<typename T>
void AVL<T>::leftRotate(Node<T>*& node) {
    Node<T>* y = node->right;
    Node<T>* T2 = y->left;

    // Perform rotation
    y->left = node;
    node->right = T2;

    // Update heights
    node->height = 1 + std::max(height(node->left), height(node->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    // Return new root
    node = y;
}

template<typename T>
void AVL<T>::rightRotate(Node<T>*& node) {
    Node<T>* y = node->left;
    Node<T>* T2 = y->right;

    // Perform rotation
    y->right = node;
    node->left = T2;

    // Update heights
    node->height = 1 + std::max(height(node->left), height(node->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    // Return new root
    node = y;
}

template<typename T>
int AVL<T>::height(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template<typename T>
int AVL<T>::getBalance(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template<typename T>
void AVL<T>::balance(Node<T>*& node) {
    // Get the balance factor
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0) {
        rightRotate(node);
        return;
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0) {
        leftRotate(node);
        return;
    }

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        leftRotate(node->left);
        rightRotate(node);
        return;
    }

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        rightRotate(node->right);
        leftRotate(node);
        return;
    }
}

template <typename T>
void AVL<T>::remove(Node<T>*& node, T data) {
    if (node == nullptr) return;

    if (data < node->data) {
        remove(node->left, data);
    } else if (data > node->data) {
        remove(node->right, data);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            size--;
        } else if (node->left == nullptr) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
            size--;
        } else if (node->right == nullptr) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
            size--;
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

template <typename T>
void AVL<T>::inOrder(void(*f)(T&param)) {
    inOrder(root, f);
}

template <typename T>
void AVL<T>::preOrder(void(*f)(T&param)) {
    preOrder(root, f);
}

template <typename T>
void AVL<T>::postOrder(void(*f)(T&param)) {
    postOrder(root, f);
}

template <typename T>
void AVL<T>::insert(T data) {
    insert(root, data);
}

template <typename T>
void AVL<T>::remove(T data) {
    remove(root, data);
}

template <typename T>
void AVL<T>::breadthOrder(void(*f)(T&param)) {
    std::queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        Node<T>* node = q.front();
        q.pop();

        f(node->data);

        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

template <typename T>
void AVL<T>::depthOrder(void(*f)(T&param)) {
    std::stack<Node<T>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<T>* node = s.top();
        s.pop();

        f(node->data);

        if (node->right != nullptr) {
            s.push(node->right);
        }

        if (node->left != nullptr) {
            s.push(node->left);
        }
    }
}

template <typename T>
void AVL<T>::clear() {
    while (root != nullptr) {
        remove(root, root->data);
    }
}

template <typename T>
Node<T>* AVL<T>::getRoot() const {
    return root;
}

template <typename T>
int AVL<T>::getSize() const {
    return size;
}

template <typename T>
bool AVL<T>::empty() const {
    return size == 0;
}

#endif //AVL_CPP