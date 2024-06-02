#include "Utils.h"
#include <cctype>

string removeApostrophee(const string& str) {
    if (str.empty()) return str;
    if (str.front() == '\'') {
        return str.substr(1);
    }
    if (str.back() == '\'') {
        return str.substr(0, str.length() - 1);
    }
    return str;
}

string toLowerCasee(const string& str) {
    string result;
    for (char ch : str) {
        result += tolower(ch);
    }
    return result;
}
