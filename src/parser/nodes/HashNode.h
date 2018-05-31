//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_HASHNODE_H
#define REGEXP_HASHNODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class HashNode : public AbstractNode {

public:

    HashNode()
    {
        token = {'#', '#'};
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;



};


#endif //REGEXP_HASHNODE_H
