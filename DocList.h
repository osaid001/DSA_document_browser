#pragma once

#include "Doc.h"
#include <list>
#include <unordered_set>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class DocList {
private:
    list<Doc> docList;
    unordered_set<string> stopWords;

public:
    DocList();
    void addDocument(Doc d);
    Doc* getDoc(const string& docName);
    void loadDocuments(const string& directoryPath);
    vector<pair<string, int>> searchDocuments(const string& query);
};
