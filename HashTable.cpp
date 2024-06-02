#include "HashTable.h"

const int HashTable::primes[] = { 11, 19, 41, 79, 163, 317, 641, 1279, 2557, 5119, 10243, 20479, 40961, 81919, 163841, 327673 };

HashTable::HashTable() : primeIndex(0), totalCapacity(10), currentSize(0) {
    hashTable = new Node * [totalCapacity];
    for (int i = 0; i < totalCapacity; i++) {
        hashTable[i] = nullptr;
    }
}

HashTable::HashTable(int capacity) : primeIndex(0), totalCapacity(capacity), currentSize(0) {
    hashTable = new Node * [totalCapacity];
    for (int i = 0; i < totalCapacity; i++) {
        hashTable[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < totalCapacity; i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] hashTable;
}

void HashTable::put(const string& key, int value) {
    int index = hash(key);
    Node* newNode = new Node(new WordItem(key, value));
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    currentSize++;

    float loadFactor = (1.0 * currentSize) / totalCapacity;
    if (loadFactor >= 0.75 || totalCapacity < 200000) {
        rehash();
    }
}

int HashTable::get(const string& key) {
    int index = hash(key);
    Node* head = hashTable[index];
    while (head != nullptr) {
        if (head->data->word == key) {
            return head->data->frequency;
        }
        head = head->next;
    }
    return -1; // Key not found
}

int HashTable::size() {
    return currentSize;
}

bool HashTable::exists(const string& key) {
    return get(key) != -1;
}

void HashTable::rehash() {
    int oldCapacity = totalCapacity;
    primeIndex++;
    totalCapacity = primes[primeIndex];
    Node** oldHashTable = hashTable;

    hashTable = new Node * [totalCapacity];
    for (int i = 0; i < totalCapacity; i++) {
        hashTable[i] = nullptr;
    }

    currentSize = 0;

    for (int i = 0; i < oldCapacity; i++) {
        Node* oldNode = oldHashTable[i];
        while (oldNode != nullptr) {
            put(oldNode->data->word, oldNode->data->frequency);
            Node* toDelete = oldNode;
            oldNode = oldNode->next;
            delete toDelete->data;
            delete toDelete;
        }
    }

    delete[] oldHashTable;
}

int HashTable::hash(const string& key) {
    int sum = 0;
    for (char ch : key) {
        sum += ch;
    }
    return sum % totalCapacity;
}
