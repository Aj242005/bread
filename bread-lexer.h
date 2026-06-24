#ifndef BREAD_LEXER_H
#define BREAD_LEXER_H

#include "bread-utilities.h"
using namespace std;


vector<pair<string,string>> lexingTheStringTokens(vector<string> rawTokens){
    vector<pair<string,string>> lexerMap;
    for(auto i : rawTokens){
        pair<string,string> token;
        if(findToken(i)){
            token.first = i;
            token.second = getTokenCategory(i);
            lexerMap.push_back(token);
        }
        else{
            try{
                float number = stof(i);
                token.first = i;
                token.second = "Number";
                lexerMap.push_back(token);
            }
            catch(exception &err){
                token.first = i;
                token.second = "Identifier";
                lexerMap.push_back(token);
            }
        }
    }

    return lexerMap;
}


#endif