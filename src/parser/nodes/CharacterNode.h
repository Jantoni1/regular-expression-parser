//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_FAILURENODE_H
#define REGEXP_FAILURENODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class CharacterNode : public AbstractNode {
public:
    CharacterNode() = default;
    ~CharacterNode() override = default;

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;


};


#endif //REGEXP_FAILURENODE_H
