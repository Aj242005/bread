#ifndef BREAD_UTILITIES_H
#define BREAD_UTILITIES_H

#include "standard-constants-main.h"

using namespace std;


unordered_map<string, TokenInfo> getTokens(){
    return tokens;
}

string getTerminator(){
    return terminator;
}

// Does symbol s exist as a token at all?
bool findToken(string s){
    return tokens.find(s) != tokens.end();
}

bool findTerminator(string s){
    return s == terminator;
}

// e.g. getTokenName("<") -> "less than"
string getTokenName(string s){
    auto it = tokens.find(s);
    return (it != tokens.end()) ? it->second.name : "unknown";
}

// e.g. getTokenCategory("<") -> "Binary Operator"
string getTokenCategory(string s){
    auto it = tokens.find(s);
    return (it != tokens.end()) ? it->second.category : "unknown";
}

vector<string> removeSpacesFromInput(string s) {
    vector<string> noSpace;
    string buffer;
    bool insideQuotes = false;
    char quoteChar = '\0';

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];

        if (insideQuotes) {
            buffer += c;
            if (c == quoteChar) {            // found the matching closing quote
                noSpace.push_back(buffer);   // the whole quoted span is one token
                buffer.clear();
                insideQuotes = false;
            }
        }
        else if (c == '"' || c == '\'') {
            if (!buffer.empty()) {           // flush whatever came before the quote
                noSpace.push_back(buffer);
                buffer.clear();
            }
            insideQuotes = true;
            quoteChar = c;
            buffer += c;
        }
        else if (isspace(static_cast<unsigned char>(c))) {
            if (!buffer.empty()) {
                noSpace.push_back(buffer);
                buffer.clear();
            }
        }
        else {
            buffer += c;
        }
    }

    if (!buffer.empty()) {       // leftover token at end of line (or unterminated quote)
        noSpace.push_back(buffer);
    }

    return noSpace;
}

#endif