//
// Created by Kuba on 26.05.2018.
//

#include "AsteriskNode.h"

void AsteriskNode::setNullable() {
    right->setNullable();
    nullable = true;
}

void AsteriskNode::setFirst() {
    right->setFirst();
    first = right->getFirst();
}

void AsteriskNode::setLast() {
    right->setLast();
    last = right->getLast();
}

void AsteriskNode::setFollow(std::map<int, std::set<int>> &follow) {
    right->setFollow(follow);
    for(auto element : last) {
        for(auto value : first) {
            follow[element].insert(value);
        }
    }
}

void AsteriskNode::setLetters(std::map<char, std::set<int>> &letters) {
    right->setLetters(letters);
}

