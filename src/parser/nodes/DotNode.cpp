//
// Created by Kuba on 26.05.2018.
//

#include "DotNode.h"

void DotNode::setNullable() {
    nullable = false;
}

void DotNode::setFirst() {
    first.insert(number);
}

void DotNode::setLast() {
    last.insert(number);
}

void DotNode::setFollow(std::map<int, std::set<int>> &follow) {
}

void DotNode::setLetters(std::map<char, std::set<int>> &letters) {
    for(int i = 0; i < 256; ++i) {
        letters[static_cast<char>(i)].insert(number);
    }
}
