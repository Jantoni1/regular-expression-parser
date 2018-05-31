#ifndef REGULAR_EXPRESSION_LIBRARY_LEXER_H
#define REGULAR_EXPRESSION_LIBRARY_LEXER_H


#include <string>
#include <set>
#include "Source.h"
#include "../parser/ParserException.h"


class Lexer {

public:
    Lexer() : source(nullptr) {}
    ~Lexer();
    using Token = std::pair<char, char>; // type, value
    Token getToken();

    void setSource(std::string source);

    const unsigned int &getLineNumber() const;

    const unsigned int &getColumnNumber() const;

    const std::streampos &getPosition() const;

    const std::string getLine();

private:
    Source* source;
};




#endif //REGULAR_EXPRESSION_LIBRARY_LEXER_H
