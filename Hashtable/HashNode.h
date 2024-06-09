//
// Created by jnmen on 6/9/2024.
//

#ifndef HASHNODE_H
#define HASHNODE_H

template<typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode<K, V>* next;

    HashNode(): key(0), value(0), next(nullptr) {}
    HashNode(K key, V value): key(key), value(value), next(nullptr) {}
};

#endif //HASHNODE_H
