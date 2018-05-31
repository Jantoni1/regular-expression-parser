//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_DOTNODE_H
#define REGEXP_DOTNODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class DotNode : public AbstractNode {
public:
    explicit DotNode(int current_number)
    {
        token = {'.', '.'};
        number = current_number;
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;



private:


};


#endif //REGEXP_DOTNODE_H
