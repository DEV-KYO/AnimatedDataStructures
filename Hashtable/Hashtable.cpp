//
// Created by jnmen on 6/9/2024.
//

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "Hashtable.h"

template<typename K, typename V>
Hashtable<K, V>::Hashtable(int capacity) {
    this->capacity = capacity;
    table = new HashNode<K, V>*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

template<typename K, typename V>
Hashtable<K, V>::~Hashtable() {
    for (int i = 0; i < capacity; i++) {
        HashNode<K, V>* entry = table[i];
        while (entry != nullptr) {
            HashNode<K, V>* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

template<typename K, typename V>
int Hashtable<K, V>::hashFunction(K key) {
    return key % capacity;
}

template<typename K, typename V>
void Hashtable<K, V>::insert(K key, V value) {
    int index = hashFunction(key);
    HashNode<K, V>* entry = table[index];
    if (entry == nullptr) {
        table[index] = new HashNode<K, V>(key, value);
    } else {
        while (entry->next != nullptr) {
            entry = entry->next;
        }
        entry->next = new HashNode<K, V>(key, value);
    }
}

template<typename K, typename V>
V Hashtable<K, V>::get(K key) {
    int index = hashFunction(key);
    HashNode<K, V>* entry = table[index];
    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return 0;
}


#endif //HASHTABLE_CPP