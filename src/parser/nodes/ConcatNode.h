//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_CONCATNODE_H
#define REGEXP_CONCATNODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class ConcatNode : public AbstractNode {
public:

    explicit ConcatNode()
    {
        token = {'c', 'c'};
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;


};


#endif //REGEXP_CONCATNODE_H
