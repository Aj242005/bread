#include "../bread-lexer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int totalTests = 0;
static int passedTests = 0;

void checkTokens(const string& testName, const string& line, const vector<pair<string,string>>& expected){
    totalTests++;
    try{
        vector<pair<string,string>> actual = lexingTheStringTokens(removeSpacesFromInput(line));
        if(actual == expected){
            cout << "[PASS] " << testName << endl;
            passedTests++;
        } else {
            cout << "[FAIL] " << testName << " -- line: " << line << endl;
            cout << "        expected: ";
            for(auto& p : expected) cout << "{" << p.first << ":" << p.second << "} ";
            cout << endl << "        actual:   ";
            for(auto& p : actual) cout << "{" << p.first << ":" << p.second << "} ";
            cout << endl;
        }
    }
    catch(exception& e){
        cout << "[FAIL] " << testName << " -- line: " << line << " threw unexpectedly: " << e.what() << endl;
    }
}

void checkThrows(const string& testName, const string& line, const string& expectedMessageSubstring){
    totalTests++;
    try{
        auto actual = lexingTheStringTokens(removeSpacesFromInput(line));
        cout << "[FAIL] " << testName << " -- expected an error but got a result for: " << line << endl;
    }
    catch(exception& e){
        string msg = e.what();
        if(msg.find(expectedMessageSubstring) != string::npos){
            cout << "[PASS] " << testName << endl;
            passedTests++;
        } else {
            cout << "[FAIL] " << testName << " -- wrong error message. Got: " << msg << endl;
        }
    }
}

int main(){
    cout << "Running Bread Lexer Test Suite" << endl;
    cout << "================================" << endl;

    // Auto-generated: every keyword/operator/terminator in the tokens map
    // should classify back to itself with the right category. Self-maintaining --
    // grows automatically as you add new tokens to standard-constants-main.h.
    cout << "\n--- Token map coverage (auto-generated from the tokens map) ---" << endl;
    for(auto& entry : getTokens()){
        string symbol = entry.first;
        TokenInfo info = entry.second;
        checkTokens("token: " + symbol, symbol, { {symbol, info.category} });
    }

    cout << "\n--- String / char literals ---" << endl;
    checkTokens("double-quoted single word", "\"hello\"", { {"hello", "String Literal"} });
    checkTokens("single-quoted single word", "'a'", { {"a", "String Literal"} });
    checkTokens("double-quoted MULTI-WORD string", "\"hello world\"", { {"hello world", "String Literal"} });
    checkTokens("single-quoted multi-word string", "'namaste duniya'", { {"namaste duniya", "String Literal"} });
    checkTokens("empty double-quoted string", "\"\"", { {"", "String Literal"} });
    checkThrows("mismatched quotes", "\"hello'", "Error (003)");
    checkThrows("lone double quote", "\"", "Error (003)");
    checkThrows("lone single quote", "'", "Error (003)");

    cout << "\n--- Numbers ---" << endl;
    checkTokens("integer literal", "42", { {"42", "Number"} });
    checkTokens("float literal", "3.14", { {"3.14", "Number"} });
    checkThrows("malformed number (extra dot)", "3.1.4", "Error (004)");

    cout << "\n--- Identifiers ---" << endl;
    checkTokens("simple identifier", "myVar", { {"myVar", "Identifier"} });
    checkTokens("underscore-led identifier", "_temp123", { {"_temp123", "Identifier"} });
    checkThrows("identifier starting with digit", "123abc", "Error (004)");
    checkThrows("garbage symbol", "@@@", "Error (004)");
    checkThrows("stray symbol mix", "#@", "Error (004)");

    cout << "\n--- Full line, multiple tokens ---" << endl;
    checkTokens("var declaration line", "int x = 5 >~",
        { {"int","Keyword"}, {"x","Identifier"}, {"=","Binary Operator"}, {"5","Number"}, {">~","Terminator"} });
    checkTokens("string assignment line (this used to break before the quote-aware splitter)",
        "str name = \"Akshit Jain\" >~",
        { {"str","Keyword"}, {"name","Identifier"}, {"=","Binary Operator"}, {"Akshit Jain","String Literal"}, {">~","Terminator"} });

    cout << "\n================================" << endl;
    cout << passedTests << " / " << totalTests << " tests passed" << endl;

    return (passedTests == totalTests) ? 0 : 1;
}