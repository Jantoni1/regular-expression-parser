
#include <iostream>
#include "Generator.h"
#include <algorithm>


AbstractNode *Generator::getRoot() const {
    return root;
}

void Generator::setRoot(AbstractNode *root) {
    Generator::root = root;
}

void Generator::setNullable() {
    root->setNullable();
}

void Generator::setFirst() {
    root->setFirst();
}

void Generator::setLetters() {
    root->setLetters(letters);
}

void Generator::setLast() {
    root->setLast();
}

void Generator::setFollow() {
    root->setFollow(followTable);

}

void Generator::buildAutomaton() {
    clear();
    while (!toTakeStates.empty()) {
        const std::set<int> &currentState = *toTakeStates.begin();

        for (const auto &letter : letters) { //let = (char, set<int>) -> letter = let.first
            generateState(currentState, letter);
        }

        toTakeStates.erase(*toTakeStates.begin());

    }
    for (const auto &state : currentStates) {

        if (state.find(static_cast<int>(followTable.size())) != state.end()) {
            this->endStates.insert(state);
        }
    }

}

void Generator::generateState(const std::set<int> & currentState, const std::pair<char, std::set<int>> &letter) {
    std::set<int> newState;

    std::set<int> intersection;
    set_intersection(letter.second.begin(), letter.second.end(), currentState.begin(), currentState.end(),
                     std::inserter(intersection, intersection.begin()));

    for (auto number : intersection) {
        newState.insert(followTable[number].begin(), followTable[number].end());
    }

    //in case this is a new state
    if (currentStates.find(newState) == currentStates.end()) {
        toTakeStates.insert(newState);
        currentStates.insert(newState);
    }

    automaton[std::make_pair(currentState, letter.first)] = newState;
    doneStates.insert(currentState);
}

void Generator::clear() {
    initialState = root->getFirst();
    currentStates.clear();
    doneStates.clear();
    toTakeStates.clear();
    currentStates.insert(initialState);
    toTakeStates.insert(initialState);
}
