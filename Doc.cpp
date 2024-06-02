#include "Doc.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;

string removeApostrophe(const string& str) {
    if (str.empty()) return str;
    if (str.front() == '\'') {
        return str.substr(1);
    }
    if (str.back() == '\'') {
        return str.substr(0, str.length() - 1);
    }
    return str;
}

string toLowerCase(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}

Doc::Doc(const string& name, const string& filePath, const unordered_set<string>& stopWords)
    : name(name), filePath(filePath), stopWords(stopWords) {}

void Doc::processFile() {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string word;
    while (file >> word) {
        string newWord;
        for (char c : word) {
            if (isalpha(c) || c == '\'') {
                newWord += c;
            }
        }

        newWord = removeApostrophe(newWord);
        newWord = toLowerCase(newWord);

        if (!newWord.empty() && stopWords.find(newWord) == stopWords.end()) {
            int frequency = hashTable.get(newWord);
            if (frequency == -1) {
                hashTable.put(newWord, 1);
            }
            else {
                hashTable.put(newWord, frequency + 1);
            }
        }
    }

    file.close();
}

int Doc::getWordFrequency(const string& word) {
    return hashTable.get(word);
}

string Doc::getName() const {
    return name;
}
