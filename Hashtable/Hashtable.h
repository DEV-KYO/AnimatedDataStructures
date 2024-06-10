//
// Created by jnmen on 6/9/2024.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>

template <typename T>
class Hashtable {
private:
    std::vector<T>* table;
    int capacity;

    int hash(T key);

public:
    Hashtable(int capacity);
    ~Hashtable();
    void insert(T key);
    void remove(T key);
    bool search(T key);
    void clear();

    // Getters
    int getCapacity() { return capacity; }
    std::vector<T>* getTable() { return table; }

};
#include "Hashtable.cpp"

#endif //HASHTABLE_H
