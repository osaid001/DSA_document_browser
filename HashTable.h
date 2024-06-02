#pragma once

#include "Node.h"
#include <vector>

class HashTable {
private:
    Node** hashTable;
    int currentSize;
    int totalCapacity;
    int primeIndex;
    static const int primes[16];

    void rehash();
    int hash(const string& key);

public:
    HashTable();
    HashTable(int capacity);
    ~HashTable();

    void put(const string& key, int value);
    int get(const string& key);
    int size();
    bool exists(const string& key);
};
