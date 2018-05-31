//
// Created by Kuba on 26.05.2018.
//

#include "PipeNode.h"

void PipeNode::setNullable() {
    left->setNullable();
    right->setNullable();
    nullable = left->isNullable() || right->isNullable();
}

void PipeNode::setFirst() {
    left->setFirst();
    right->setFirst();
    first = left->getFirst();
    for(auto element : right->getFirst()) {
        first.insert(element);
    }
}

void PipeNode::setLast() {
    left->setLast();
    right->setLast();
    last = left->getLast();
    for(auto element : right->getLast()) {
        last.insert(element);
    }
}

void PipeNode::setFollow(std::map<int, std::set<int>> &follow) {
    left->setFollow(follow);
    right->setFollow(follow);
}

void PipeNode::setLetters(std::map<char, std::set<int>> &letters) {
    left->setLetters(letters);
    right->setLetters(letters);
}
