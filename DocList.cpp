#include "DocList.h"
#include "Utils.h"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
namespace fs = std::filesystem;

DocList::DocList() : stopWords({ "i", "am", "is", "for", "the", "a", "an", "and", "or", "but" }) {}

void DocList::addDocument(Doc d) {
    docList.push_back(d);
}

Doc* DocList::getDoc(const string& docName) {
    for (auto& doc : docList) {
        if (doc.getName() == docName) {
            return &doc;
        }
    }
    return nullptr;
}

void DocList::loadDocuments(const string& directoryPath) {
    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                string filePath = entry.path().string();
                string fileName = entry.path().filename().string();
                Doc doc(fileName, filePath, stopWords);
                doc.processFile();
                addDocument(doc);
            }
        }
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "General error: " << e.what() << endl;
    }
}

vector<pair<string, int>> DocList::searchDocuments(const string& query) {
    vector<pair<string, int>> results;
    istringstream queryStream(query);
    string word;
    vector<string> queryWords;
    bool isAnd = false, isOr = false;

    while (queryStream >> word) {
        if (word == "AND") {
            isAnd = true;
        }
        else if (word == "OR") {
            isOr = true;
        }
        else {
            queryWords.push_back(toLowerCasee(word));
        }
    }

    for (auto& doc : docList) {
        int frequencySum = 0;
        bool foundAll = true;

        for (const auto& qWord : queryWords) {
            int frequency = doc.getWordFrequency(qWord);
            if (frequency > 0) {
                frequencySum += frequency;
            }
            else {
                foundAll = false;
            }
        }

        if ((isAnd && foundAll) || (!isAnd && !isOr && frequencySum > 0) || (isOr && frequencySum > 0)) {
            results.emplace_back(doc.getName(), frequencySum);
        }
    }

    sort(results.begin(), results.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return b.second < a.second;
        });

    return results;
}
