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


vector<string> removeSpacesFromInput(string s){
    vector<string> noSpace;
    string buffer = "";
    for(auto i : s){
        if(i != ' '){
            string insitu = "";
            insitu +=i;
            if(findUnaryOperator(insitu) || findBinaryOperator(insitu)){
                if(buffer.length()){
                    noSpace.push_back(buffer);
                }
            }
            else{
                buffer += i;
            }
        }
        else{
            if(buffer.length()){
                noSpace.push_back(buffer);
            }
            buffer = "";
        }
    }
    if(buffer.length()){
        noSpace.push_back(buffer);
    }
    return noSpace;
} 

#endif