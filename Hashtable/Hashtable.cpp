//
// Created by jnmen on 6/9/2024.
//

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "Hashtable.h"

template <typename T>
Hashtable<T>::Hashtable(int capacity) {
    this->capacity = capacity;
    table = new std::vector<T>[capacity];
}

template <typename T>
Hashtable<T>::~Hashtable() {
    delete[] table;
}

template <typename T>
int Hashtable<T>::hash(T key) {
    return key % capacity;
}

template <typename T>
void Hashtable<T>::insert(T key) {
    int index = hash(key);
    table[index].push_back(key);
}

template <typename T>
void Hashtable<T>::remove(T key) {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == key) {
            table[index].erase(table[index].begin() + i);
            return;
        }
    }
}

template <typename T>
bool Hashtable<T>::search(T key) {
    int index = hash(key);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == key) {
            return true;
        }
    }
    return false;
}

template <typename T>
void Hashtable<T>::clear() {
    for (int i = 0; i < capacity; i++) {
        table[i].clear();
    }
}


#endif //HASHTABLE_CPP