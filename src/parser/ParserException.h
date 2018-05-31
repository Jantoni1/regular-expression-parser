#ifndef REGEXP_PARSEREXCEPTION_H
#define REGEXP_PARSEREXCEPTION_H


#include <exception>
#include <string>


enum Reason {SINGLE_ESCAPE = 0, INCORRECT_INTERVAL = 1, UNEXPECTED_TOKEN = 2, NO_PARENTHESIS = 3, EMPTY_INTERVAL = 4};


class ParserException : public std::exception {

public:
    ParserException(std::string line, int row, int column, std::string reason);
    const char* what()
    {
        return "Fatal error during parsing. Given input is incorrect.";
    }



    std::string line;
    int row;
    int column;
    std::string reason;
};


#endif //REGEXP_PARSEREXCEPTION_H
