#pragma once

#include <string>
using namespace std;

struct WordItem {
    string word;
    int frequency;

    WordItem() : word(""), frequency(0) {}
    WordItem(string word, int frequency) : word(word), frequency(frequency) {}
};
