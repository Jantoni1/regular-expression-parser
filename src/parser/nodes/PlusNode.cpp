//
// Created by Kuba on 26.05.2018.
//

#include "PlusNode.h"

void PlusNode::setNullable() {
    right->setNullable();
    nullable = right->isNullable();
}

void PlusNode::setFirst() {
    right->setFirst();
    first = right->getFirst();
}

void PlusNode::setLast() {
    right->setLast();
    last = right->getLast();
}

void PlusNode::setFollow(std::map<int, std::set<int>> &follow) {
    for(auto element : last) {
        for(auto value : first) {
            follow[element].insert(value);
        }
    }
}

void PlusNode::setLetters(std::map<char, std::set<int>> &letters) {
    right->setLetters(letters);
}
