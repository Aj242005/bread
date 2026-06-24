#ifndef STANDARD_CONSTANTS_MAIN_H
#define STANDARD_CONSTANTS_MAIN_H

#include "dependencies.h"
#include <unordered_map>
using namespace std;

const unordered_map<string, string> tokens = {

    // ---- keywords ----
    {"int", "32 bit integer"},
    {"float", "32 bit decimal number"},
    {"double", "64 bit decimal number"},
    {"bool", "boolean type variable"},
    {"char", "individual character"},
    {"String", "sequence of characters"},
    {"Large", "long integer type"},
    {"if", "conditional if"},
    {"else", "conditional else"},
    {"elseIf", "conditional else if"},
    {"inline", "inline specifier"},
    {"switch", "switch statement"},
    {"case", "switch case label"},
    {"default", "default case label"},
    {"for", "for loop"},
    {"while", "while loop"},
    {"do", "do-while loop"},
    {"break", "break statement"},
    {"continue", "continue statement"},
    {"new", "object instantiation"},
    {"true", "boolean true literal"},
    {"false", "boolean false literal"},
    {"class", "class declaration"},
    {"group", "grouping construct"},
    {"public", "public access specifier"},
    {"private", "private access specifier"},
    {"protected", "protected access specifier"},
    {"try", "try block"},
    {"catch", "catch block"},
    {"except", "exception block"},
    {"const", "constant declaration"},
    {"rigid", "immutable constant declaration"},
    {"return", "return statement"},
    {"auto", "automatic type inference"},
    {"and", "logical and keyword"},
    {"or", "logical or keyword"},
    {"xor", "logical xor keyword"},
    {"sizeOf", "size of operator"},
    {"extend", "inheritance keyword"},
    {"undenfinied", "undefined value"},
    {"null", "null value"},
    {"about_author", "author metadata keyword"},

    // ---- unary operators ----
    {"--", "decrement"},
    {"++", "increment"},
    {"!", "logical not"},
    {"~", "bitwise not"},
    {"$", "set bit counter"},
    {"ascii", "ascii conversion"},
    {"anti_ascii", "anti ascii conversion"},

    // ---- binary operators ----
    {"+", "plus"},
    {"-", "minus"},
    {"*", "multiply"},
    {"/", "divide"},
    {"//", "integer divide"},
    {"%", "modulus"},
    {"==", "equal to"},
    {"!=", "not equal to"},
    {"<", "less than"},
    {">", "greater than"},
    {"<=", "less than equal to"},
    {">=", "greater than equal to"},
    {"&&", "logical and"},
    {"||", "logical or"},
    {"&", "bitwise and"},
    {"|", "bitwise or"},
    {"^", "bitwise xor"},
    {">>", "right shift"},
    {"<<", "left shift"},
    {"=", "assignment"},
    {"+=", "plus equal"},
    {"-=", "minus equal"},
    {"*=", "multiply equal"},
    {"/=", "divide equal"},
    {"%=", "modulus equal"},
    {"&=", "bitwise and equal"},
    {"|=", "bitwise or equal"},
    {"^=", "bitwise xor equal"},
    {"<<=", "left shift equal"},
    {">>=", "right shift equal"},
    {"?", "ternary question"},
    {":", "ternary colon"},
    {".", "dot member access"},
    {"->", "arrow member access"},
    {"(", "open parenthesis"},
    {")", "close parenthesis"},
    {"()", "empty parenthesis"},
    {"{}", "empty braces"},
    {"{", "open brace"},
    {"}", "close brace"},
    {"[", "open bracket"},
    {"]", "close bracket"},
    {"[]", "empty bracket"},

    // ---- terminator ----
    {">~", "statement terminator"}
};

// Kept as a plain constant too, since end-of-statement checks are common
// enough to want a direct comparison instead of a map lookup.
const string terminator = ">~";

#endif