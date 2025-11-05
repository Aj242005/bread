#ifndef BREAD_UTILITIES_H
#define BREAD_UTILITIES_H

#include <standard-constants-main.h>
#include <string>
#include <string.h>

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


#endif