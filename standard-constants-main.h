#ifndef STANDARD_CONSTANTS_MAIN_H
#define STANDARD_CONSTANTS_MAIN_H

#include "dependencies.h"
#include <unordered_map>

using namespace std;

// Every token's info: which category it belongs to, and its human readable name.
struct TokenInfo {
    string category; // "Keyword", "Unary Operator", "Binary Operator", "Terminator"
    string name;      // e.g. "less than"
};

// Single map for the whole language: symbol -> { category, name }.
const unordered_map<string, TokenInfo> tokens = {

    // ---- keywords ----
    {"int", {"Keyword", "32 bit integer"}},
    {"float", {"Keyword", "32 bit decimal number"}},
    {"double", {"Keyword", "64 bit decimal number"}},
    {"bool", {"Keyword", "boolean type variable"}},
    {"char", {"Keyword", "individual character"}},
    {"str", {"Keyword", "sequence of characters"}},
    {"Large", {"Keyword", "long integer type"}},
    {"if", {"Keyword", "conditional if"}},
    {"else", {"Keyword", "conditional else"}},
    {"elseIf", {"Keyword", "conditional else if"}},
    {"inline", {"Keyword", "inline specifier"}},
    {"switch", {"Keyword", "switch statement"}},
    {"case", {"Keyword", "switch case label"}},
    {"default", {"Keyword", "default case label"}},
    {"for", {"Keyword", "for loop"}},
    {"while", {"Keyword", "while loop"}},
    {"do", {"Keyword", "do-while loop"}},
    {"break", {"Keyword", "break statement"}},
    {"continue", {"Keyword", "continue statement"}},
    {"new", {"Keyword", "object instantiation"}},
    {"true", {"Keyword", "boolean true literal"}},
    {"false", {"Keyword", "boolean false literal"}},
    {"class", {"Keyword", "class declaration"}},
    {"group", {"Keyword", "grouping construct"}},
    {"public", {"Keyword", "public access specifier"}},
    {"private", {"Keyword", "private access specifier"}},
    {"protected", {"Keyword", "protected access specifier"}},
    {"try", {"Keyword", "try block"}},
    {"catch", {"Keyword", "catch block"}},
    {"except", {"Keyword", "exception block"}},
    {"const", {"Keyword", "constant declaration"}},
    {"rigid", {"Keyword", "immutable constant declaration"}},
    {"return", {"Keyword", "return statement"}},
    {"auto", {"Keyword", "automatic type inference"}},
    {"and", {"Keyword", "logical and keyword"}},
    {"or", {"Keyword", "logical or keyword"}},
    {"xor", {"Keyword", "logical xor keyword"}},
    {"sizeOf", {"Keyword", "size of operator"}},
    {"extend", {"Keyword", "inheritance keyword"}},
    {"undenfinied", {"Keyword", "undefined value"}},
    {"null", {"Keyword", "null value"}},
    {"about_author", {"Keyword", "author metadata keyword"}},
    {"String Literal",{"Literal", "String token"}},
    // ---- unary operators ----
    {"--", {"Unary Operator", "decrement"}},
    {"++", {"Unary Operator", "increment"}},
    {"!", {"Unary Operator", "logical not"}},
    {"~", {"Unary Operator", "bitwise not"}},
    {"$", {"Unary Operator", "set bit counter"}},
    {"ascii", {"Unary Operator", "ascii conversion"}},
    {"anti_ascii", {"Unary Operator", "anti ascii conversion"}},

    // ---- binary operators ----
    {"+", {"Binary Operator", "plus"}},
    {"-", {"Binary Operator", "minus"}},
    {"*", {"Binary Operator", "multiply"}},
    {"/", {"Binary Operator", "divide"}},
    {"//", {"Binary Operator", "integer divide"}},
    {"%", {"Binary Operator", "modulus"}},
    {"==", {"Binary Operator", "equal to"}},
    {"!=", {"Binary Operator", "not equal to"}},
    {"<", {"Binary Operator", "less than"}},
    {">", {"Binary Operator", "greater than"}},
    {"<=", {"Binary Operator", "less than equal to"}},
    {">=", {"Binary Operator", "greater than equal to"}},
    {"&&", {"Binary Operator", "logical and"}},
    {"||", {"Binary Operator", "logical or"}},
    {"&", {"Binary Operator", "bitwise and"}},
    {"|", {"Binary Operator", "bitwise or"}},
    {"^", {"Binary Operator", "bitwise xor"}},
    {">>", {"Binary Operator", "right shift"}},
    {"<<", {"Binary Operator", "left shift"}},
    {"=", {"Binary Operator", "assignment"}},
    {"+=", {"Binary Operator", "plus equal"}},
    {"-=", {"Binary Operator", "minus equal"}},
    {"*=", {"Binary Operator", "multiply equal"}},
    {"/=", {"Binary Operator", "divide equal"}},
    {"%=", {"Binary Operator", "modulus equal"}},
    {"&=", {"Binary Operator", "bitwise and equal"}},
    {"|=", {"Binary Operator", "bitwise or equal"}},
    {"^=", {"Binary Operator", "bitwise xor equal"}},
    {"<<=", {"Binary Operator", "left shift equal"}},
    {">>=", {"Binary Operator", "right shift equal"}},
    {"?", {"Binary Operator", "ternary question"}},
    {":", {"Binary Operator", "ternary colon"}},
    {".", {"Binary Operator", "dot member access"}},
    {"->", {"Binary Operator", "arrow member access"}},
    {"(", {"Binary Operator", "open parenthesis"}},
    {")", {"Binary Operator", "close parenthesis"}},
    {"()", {"Binary Operator", "empty parenthesis"}},
    {"{}", {"Binary Operator", "empty braces"}},
    {"{", {"Binary Operator", "open brace"}},
    {"}", {"Binary Operator", "close brace"}},
    {"[", {"Binary Operator", "open bracket"}},
    {"]", {"Binary Operator", "close bracket"}},
    {"[]", {"Binary Operator", "empty bracket"}},

    // ---- terminator ----
    {">~", {"Terminator", "statement terminator"}},
    {"#",{"Comment","Comment starter"}}
};

// Kept as a plain constant too, for direct end-of-statement comparisons
// without a map lookup.
const string terminator = ">~";

#endif