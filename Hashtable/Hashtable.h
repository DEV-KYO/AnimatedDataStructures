//
// Created by jnmen on 6/9/2024.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashNode.h"

template <typename K, typename V>
class Hashtable {
private:
    HashNode<K, V>** table;
    int capacity;

    int hashFunction(K key);
public:
    Hashtable(int capacity);
    ~Hashtable();

    void insert(K key, V value);
    V get(K key);

};

#include "Hashtable.cpp"

#endif //HASHTABLE_H
