//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_SQUAREBRACKETNODE_H
#define REGEXP_SQUAREBRACKETNODE_H


#include <unordered_map>
#include <vector>
#include <set>
#include <map>
#include "AbstractNode.h"

class SquareBracketNode : public AbstractNode {
public:
    SquareBracketNode();

    bool isNegate() const;

    void setNegate(bool negate);

    int set_character_set(std::set<char> &set);

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;

    const std::set<char> &getCharacter_set() const;

private:
    bool negate;
    std::set<char> character_set;
};


#endif //REGEXP_SQUAREBRACKETNODE_H
