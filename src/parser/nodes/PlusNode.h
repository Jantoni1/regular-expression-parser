//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_PLUSNODE_H
#define REGEXP_PLUSNODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class PlusNode : public AbstractNode {
public:
    PlusNode()
    {
        token = {'+', '+'};
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;



};


#endif //REGEXP_PLUSNODE_H
