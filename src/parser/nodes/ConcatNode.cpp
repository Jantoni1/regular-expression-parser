//
// Created by Kuba on 26.05.2018.
//

#include <iostream>
#include "ConcatNode.h"

void ConcatNode::setNullable() {
    left->setNullable();
    right->setNullable();
    nullable =  left->isNullable() && right->isNullable();
}

void ConcatNode::setFirst() {
    left->setFirst();
    right->setFirst();
    first = left->getFirst();
    if(left->isNullable()) {
        const auto &set  = right->getFirst();
        for(auto element : set) {
            first.insert(element);
        }
    }
}

void ConcatNode::setLast() {
    left->setLast();
    right->setLast();

    last = right->getLast();
    if(right->isNullable()) {
        for(auto element : left->getLast()) {
            last.insert(element);
        }
    }
}

void ConcatNode::setFollow(std::map<int, std::set<int>> &follow) {
    left->setFollow(follow);
    right->setFollow(follow);
    for(auto element : left->getLast()) {
        for(auto value : right->getFirst()) {
            follow[element].insert(value);
        }
    }
}

void ConcatNode::setLetters(std::map<char, std::set<int>> &letters) {
    left->setLetters(letters);
    right->setLetters(letters);
}
