

#include <iostream>
#include "Pattern.h"



Pattern::Pattern(std::string regex) {
    l = new Lexer();
    l->setSource(std::move(regex));
    p = new Parser(l);
    g = new Generator();
}

bool Pattern::verify(std::string text) {

    auto current_it = text.begin();
    auto currentState = g->initialState;

    while(current_it != text.end() && !currentState.empty()) {
        currentState = g->automaton[std::make_pair(currentState, *current_it++)];
    }

    return g->endStates.find(currentState) != g->endStates.end(); //check if can end now
}

void Pattern::buildAutomaton() {
    auto n = p->parse();
    g->setRoot(n);
    g->setNullable();
    g->setFirst();
    g->setLast();
    g->setFollow();
    g->setLetters();
    g->buildAutomaton();

}
