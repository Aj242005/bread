#ifndef BREAD_LEXER_H
#define BREAD_LEXER_H

#include "bread-utilities.h"
using namespace std;


vector<pair<string,string>> lexingTheStringTokens(vector<string> tokens){
    vector<pair<string,string>> lexerMap;
    for(auto i : tokens){
        pair<string,string> token;
        if(findKeywords(i)){
            token.first = i;
            token.second = "Keyword";
            lexerMap.push_back(token);
        }
        else if(findBinaryOperator(i)){
            token.first = i;
            token.second = "Binary Operator";
            lexerMap.push_back(token);
        }
        else if(findUnaryOperator(i)){
            token.first = i;
            token.second = "Unary Operator";
            lexerMap.push_back(token);
        }
        else if(findTerminator(i)){
            token.first = i;
            token.second = "Terminator";
            lexerMap.push_back(token);
        }
        else{
            try{
                float number = stof(i);
                token.first = i;
                token.second = "Number";
                lexerMap.push_back(token);
            }
            catch(exception err){
                token.first = i;
                token.second = "Identifier";
                lexerMap.push_back(token);
            }
        }
    }

    return lexerMap;
}


#endif