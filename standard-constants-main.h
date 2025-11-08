#ifndef STANDARD_CONSTANTS_MAIN_H
#define STANDARD_CONSTANTS_MAIN_H

#include "dependencies.h"

using namespace std;

const vector<string> keywords = { 
    "int", // 32 bit integer
    "float", // 32 bit decimanl number 
    "double", //64 bit decimal number
    "bool", // boolean type variable
    "char", // individual character
    "String", // the standard sequence of characters
    "Large", // long for c++
    "if", // conditional statements if
    "else", // conditional statements else
    "elseIf", // conditional statements else if and also popularly used as elif in language like python
    "inline",
    "switch",
    "case",
    "default",
    "for",
    "while",
    "do",
    "break",
    "continue",
    "new",
    "true",
    "false",
    "class",
    "group",
    "public",
    "private",
    "protected",
    "try",
    "catch",
    "except",
    "const", // for constant values of a variable but also allows mutable values of the containers
    "rigid", // this also assignes the constant values to the variables but this doesn't allow the containers to be mutable
    "return",
    "auto",
    "and",
    "or",
    "xor",
    "sizeOf",
    "extend",
    "undenfinied",
    "null",
    "about_author"
};

const vector<string> unary_operators = {
    "--",
    "++",
    "!",
    "~",
    "$", // find the set bits in the number
    "ascii",
    "anti_ascii"
};

const vector<string> binary_operators = {
    "+",
    "-",
    "*",
    "/",
    "//",
    "%",
    "==",
    "!=",
    "<",
    ">",
    "<=",
    ">=",
    "&&",
    "||",
    "&",
    "|",
    "^",
    ">>",
    "<<",
    "=",
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "&=",
    "|=",
    "^=",
    "<<=",
    ">>=",
    "?",
    ":",
    ".",
    "->",
    "(",
    ")",
    "()",
    "{}",
    "{",
    "}",
    "[",
    "]",
    "[]"
};

const string terminator = "/~";

#endif
