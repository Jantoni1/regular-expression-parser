//
// Created by Kuba on 26.05.2018.
//

#include "SquareBracketNode.h"

SquareBracketNode::SquareBracketNode() : negate(false) {
    token = {']', ']'};
}

bool SquareBracketNode::isNegate() const {
    return negate;
}

void SquareBracketNode::setNegate(bool negate) {
    SquareBracketNode::negate = negate;
}

int SquareBracketNode::set_character_set(std::set<char> &set) {
    if(!negate) {
        character_set = set;
    }
    else {
        for(int i = 0; i < 256; ++i) {
            auto character = static_cast<char>(i);
            if(set.find(character) == set.end()) {
                character_set.insert(character);
            }
        }
    }
}

void SquareBracketNode::setNullable() {
    nullable = false;
}

void SquareBracketNode::setFirst() {
    first.insert(number);
}

void SquareBracketNode::setLast() {
    last.insert(number);
}

void SquareBracketNode::setFollow(std::map<int, std::set<int>> &) {

}

void SquareBracketNode::setLetters(std::map<char, std::set<int>> &letters) {
    for(char element : character_set) {
        letters[element].insert(number);
    }
}

const std::set<char> &SquareBracketNode::getCharacter_set() const {
    return character_set;
}
