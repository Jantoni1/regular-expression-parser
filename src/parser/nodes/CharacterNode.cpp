//
// Created by Kuba on 26.05.2018.
//

#include <utility>
#include "CharacterNode.h"

void CharacterNode::setNullable() {
    nullable = false;
}

void CharacterNode::setFirst() {
    first.insert(number);
}

void CharacterNode::setLast() {
    last.insert(number);
}

void CharacterNode::setFollow(std::map<int, std::set<int>> &) {

}

void CharacterNode::setLetters(std::map<char, std::set<int>> &letters) {
    letters[token.second].insert(number);
}
