//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_ASTERISKNODE_H
#define REGEXP_ASTERISKNODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class AsteriskNode : public AbstractNode {
public:
    explicit AsteriskNode()
    {
        token = {'*', '*'};
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;


};


#endif //REGEXP_ASTERISKNODE_H
