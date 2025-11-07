#ifndef BREAD_UTILITIES_H
#define BREAD_UTILITIES_H

#include <standard-constants-main.h>

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

char getTerminator(){
    return terminator;
}

vector<string> removeSpacesFromInput(string s){
    vector<string> noSpace;
    string buffer = "";
    for(auto i : s){
        if(i != ' '){
            buffer += i;
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