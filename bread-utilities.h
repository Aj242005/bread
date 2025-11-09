#ifndef BREAD_UTILITIES_H
#define BREAD_UTILITIES_H

#include "standard-constants-main.h"

using namespace std;


vector<string> getKeywords(){
    return keywords;
}

vector<string> getUnaryOperators(){
    return unary_operators;
}

vector<string> getBinaryOperators(){
    return binary_operators;
}

string getTerminator(){
    return terminator;
}

bool find(vector<string> standard,string s){
    for(auto i : standard){
        if(i == s){
            return 1;
        }
    }
    return 0;
}

bool findKeywords(string s){
    for(auto i : keywords){
        if(i == s){
            return 1;
        }
    }
    return 0;
}

bool findUnaryOperator(string s){
    for(auto i : unary_operators){
        if(i == s){
            return 1;
        }
    }
    return 0;
}

bool findBinaryOperator(string s){
    for(auto i : binary_operators){
        if(i == s){
            return 1;
        }
    }
    return 0;
}

bool findTerminator(string s){
    if( s == terminator){
        return 1;
    }
    return 0;
}


vector<std::string> removeSpacesFromInput(string s) {
    vector<std::string> noSpace;
    stringstream ss(s);
    string buffer;
    
    while (ss >> buffer) { 
        noSpace.push_back(buffer);
    }
    
    return noSpace;
} 

#endif