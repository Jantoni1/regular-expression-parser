#include "Lexer.h"
#include "../parser/ParserException.h"
#include "../parser/Parser.h"
#include <iostream>

Lexer::Token Lexer::getToken()
{
    source->nextCharacter();
    char character = source->getCurrentCharacter();
    switch(character) {
        case ascii::EOT:
            return {'E', 'E'};
        case '\\':
            source->nextCharacter();
            if(source->getCurrentCharacter() == ascii::EOT) {
                throw ParserException(getLine(), getLineNumber(), getColumnNumber(),
                                      "Parser found single escape mark as the last character of input.");
            }
            else {
                character = source->getCurrentCharacter();
                return {'a', character};
            }
        case '(':
            return {'(', '('};
        case ')':
            return {')', ')'};
        case '+':
            return {'+', '+'};
        case '*':
            return {'*', '*'};
        case '|':
            return {'|', '|'};
        case '[':
            return {'[', '['};
        case ']':
            return {']', ']'};
        case '-':
            return {'-', '-'};
        case '?':
            return {'?', '?'};
        case '.':
            return {'.', '.'};
        case '^':
            return {'^', '^'};
        default:
            return {'a', character};
    }
}

const unsigned int &Lexer::getLineNumber() const {
    return source->getLineNumber();
}

const unsigned int &Lexer::getColumnNumber() const {
    return source->getColumnNumber();
}

const std::streampos &Lexer::getPosition() const {
    return source->getPosition();
}

const std::string Lexer::getLine() {
    return source->getLine(getPosition());
}

Lexer::~Lexer() {
    delete source;
}

void Lexer::setSource(std::string source) {
    delete this->source;
    this->source = new Source(source);
//    this->source->nextCharacter();
}

