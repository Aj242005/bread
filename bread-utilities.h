#ifndef BREAD_UTILITIES_H
#define BREAD_UTILITIES_H

#include "standard-constants-main.h"

using namespace std;


unordered_map<string, string> getTokens(){
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

string getTokenName(string s){
    auto it = tokens.find(s);
    return (it != tokens.end()) ? it->second : "unknown";
}

vector<string> removeSpacesFromInput(string s) {
    vector<string> noSpace;
    stringstream ss(s);
    string buffer;

    while (ss >> buffer) {
        noSpace.push_back(buffer);
    }

    return noSpace;
}

#endif