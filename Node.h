#pragma once

#include "WordItem.h"

struct Node {
    WordItem* data;
    Node* next;

    Node(WordItem* data) : data(data), next(nullptr) {}
    ~Node() { delete data; }
};
