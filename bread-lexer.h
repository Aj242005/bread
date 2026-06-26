#ifndef BREAD_LEXER_H
#define BREAD_LEXER_H

#include "bread-utilities.h"
#include "custom-exceptions.h"
using namespace std;

vector<pair<string, string>> lexingTheStringTokens(vector<string> rawTokens, int lineNumber = -1)
{
    string lineInfo = (lineNumber >= 0) ? (" (line " + to_string(lineNumber) + ")") : "";
    vector<pair<string, string>> lexerMap;
    for (auto i : rawTokens)
    {
        pair<string, string> token;
        if ((i.length() >= 2 && i[0] == '"' && i[i.length() - 1] == '"') || (i.length() >= 2 && i[0] == '\'' && i[i.length() - 1] == '\''))
        {
            token.first = i.substr(1, i.length() - 2);
            token.second = "String Literal";
        }
        else if (i[0] == '"' || i[0] == '\'' || i[i.length() - 1] == '"' || i[i.length() - 1] == '\'')
        {
            throw SyntaxError("Error (003) : Not a valid String Literal, incomplete '\"', it must be used in pairs" + lineInfo);
        }
        else if (findToken(i))
        {
            token.first = i;
            token.second = getTokenCategory(i);
        }
        else
        {
            size_t pos = 0;
            bool isValidNumber = false;

            try
            {
                stof(i, &pos);
                isValidNumber = (pos == i.length()); // reject partial parses like "3.1.4"
            }
            catch (exception &err)
            {
                isValidNumber = false;
            }

            if (isValidNumber)
            {
                token.first = i;
                token.second = "Number";
            }
            else
            {
                bool isValidIdentifier = !i.empty() &&
                                         (isalpha(static_cast<unsigned char>(i[0])) || i[0] == '_');

                for (size_t k = 1; k < i.length() && isValidIdentifier; k++)
                {
                    if (!(isalnum(static_cast<unsigned char>(i[k])) || i[k] == '_'))
                    {
                        isValidIdentifier = false;
                    }
                }

                if (isValidIdentifier)
                {
                    token.first = i;
                    token.second = "Identifier";
                }
                else
                {
                    throw SyntaxError("Error (004) : '" + i + "' is not a valid number or identifier" + lineInfo);
                }
            }
        }
        lexerMap.push_back(token);
    }

    return lexerMap;
}

#endif