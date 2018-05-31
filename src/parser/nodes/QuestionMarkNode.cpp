//
// Created by Kuba on 26.05.2018.
//

#include "QuestionMarkNode.h"

void QuestionMarkNode::setNullable() {
    right->setNullable();
    nullable = true;
}

void QuestionMarkNode::setFirst() {
    right->setFirst();
    first = right->getFirst();
}

void QuestionMarkNode::setLast() {
    right->setLast();
    last = right->getLast();
}

void QuestionMarkNode::setFollow(std::map<int, std::set<int>> &follow) {
    right->setFollow(follow);
}

void QuestionMarkNode::setLetters(std::map<char, std::set<int>> &letters) {
    right->setLetters(letters);
}
