
#ifndef REGEXP_PATTERN_H
#define REGEXP_PATTERN_H


#include "../generator/Generator.h"
#include "../lexer/Lexer.h"
#include "../parser/Parser.h"

class Pattern {
public:
    explicit Pattern(std::string regex);
    ~Pattern() {
        delete p;
        delete g;
    }
    bool verify(std::string text);

    void buildAutomaton();
private:
    std::string regex;
    Lexer *l;
    Parser *p;
    Generator *g;
};

#endif //REGEXP_PATTERN_H
