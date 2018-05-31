

#ifndef REGEXP_GENERATOR_H
#define REGEXP_GENERATOR_H


#include <set>
#include <map>
#include "../parser/nodes/AbstractNode.h"

class Generator {


public:
    Generator()
            : root(nullptr)
    {}

    ~Generator()
    {
        delete root;
    }

    AbstractNode *getRoot() const;

    void setRoot(AbstractNode *root);

    void setNullable();

    void setLetters();

    void setFirst();

    void setLast();

    void setFollow();

    void buildAutomaton();

    std::set<int> initialState;
    std::map<std::pair<std::set<int>, char>, std::set<int>> automaton;
    std::set<std::set<int>> endStates;

    void generateState(const std::set<int> & currentState, const std::pair<char, std::set<int>> &letter);

private:

    void clear();

    AbstractNode *root;
    std::map<int, std::set<int>> followTable;
    std::map<char, std::set<int>> letters;
    std::set<std::set<int>> currentStates;
    unsigned long long int allOperations = 0;

    std::set<std::set<int>> doneStates;
    std::set<std::set<int>> toTakeStates;

};


#endif //REGEXP_GENERATOR_H
