//
// Created by Kuba on 26.05.2018.
//

#include "HashNode.h"

void HashNode::setNullable() {
    nullable = false;
}

void HashNode::setFirst() {
    first.insert(number);
}

void HashNode::setLast() {
    last.insert(number);
}

void HashNode::setFollow(std::map<int, std::set<int>> &follow) {
    follow[static_cast<int>('#')] = {};
}

void HashNode::setLetters(std::map<char, std::set<int>> &letters) {

}
