#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include "dependencies.h"
using namespace std;

class IncorrectExecutionError : public exception {
    
    private :
        string errText;
    public:
        IncorrectExecutionError( string message ) : errText(message) {}

        const char* what() const noexcept override{
            return errText.c_str();
        }
};

class SyntaxError : public exception {
    private:
        string errText;
    public:
        SyntaxError( string msg ) : errText(msg) {}

        const char* what() const noexcept override{
            return errText.c_str();
        }
};





#endif