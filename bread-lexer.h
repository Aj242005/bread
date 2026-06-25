#ifndef BREAD_LEXER_H
#define BREAD_LEXER_H

#include "bread-utilities.h"
using namespace std;


vector<pair<string,string>> lexingTheStringTokens(vector<string> rawTokens){
    vector<pair<string,string>> lexerMap;
    for(auto i : rawTokens){
        pair<string,string> token;
        if (i.length() >= 2 && i[0] == '"' && i[i.length() - 1] == '"') {
            token.first = i.substr(1, i.length() - 2);
            token.second = "String Literal";
        }
        else if(i[0] == '"'){
            cout<<""<<endl;
            throw runtime_error("Error (003) : Not a valid String Literal, incomplete '\"', it must be used in pairs");
        }
        else if(findToken(i)){
            token.first = i;
            token.second = getTokenCategory(i);
        }
        else{
            try{
                float number = stof(i);
                token.first = i;
                token.second = "Number";
            }
            catch(exception &err){
                token.first = i;
                token.second = "Identifier";
            }
        }
        lexerMap.push_back(token);
    }

    return lexerMap;
}


#endif