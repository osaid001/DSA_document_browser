#pragma once

#include "HashTable.h"
#include <unordered_set>
#include <string>

using namespace std;

class Doc {
private:
    string name;
    string filePath;
    unordered_set<string> stopWords;

public:
    HashTable hashTable;

    Doc(const string& name, const string& filePath, const unordered_set<string>& stopWords);

    void processFile();
    int getWordFrequency(const string& word);
    string getName() const;
};
