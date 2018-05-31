//
// Created by Kuba on 26.05.2018.
//

#include <set>
#include <map>
#include "AbstractNode.h"
#include "../../lexer/Lexer.h"

AbstractNode *AbstractNode::getLeft() const {
    return left;
}

void AbstractNode::setLeft(AbstractNode *left) {
    AbstractNode::left = left;
}

AbstractNode *AbstractNode::getRight() const {
    return right;
}

void AbstractNode::setRight(AbstractNode *right) {
    AbstractNode::right = right;
}

const Lexer::Token &AbstractNode::getToken() const {
    return token;
}

void AbstractNode::setToken(const Lexer::Token &token) {
    AbstractNode::token = token;
}

int AbstractNode::getNumber() const {
    return number;
}

void AbstractNode::setNumber(int number) {
    AbstractNode::number = number;
}

const std::set<int> &AbstractNode::getFirst() const {
    return first;
}

const std::set<int> &AbstractNode::getLast() const {
    return last;
}

void AbstractNode::setLast(const std::set<int> &last) {
    AbstractNode::last = last;
}

const std::set<int> &AbstractNode::getFollow() const {
    return follow;
}

void AbstractNode::setFollow(const std::set<int> &follow) {
    AbstractNode::follow = follow;
}

bool AbstractNode::isNullable() const {
    return nullable;
}
