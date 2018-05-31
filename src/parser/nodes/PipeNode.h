//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_PIPENODE_H
#define REGEXP_PIPENODE_H

#include <set>
#include <map>
#include "AbstractNode.h"

class PipeNode : public AbstractNode {
public:
    PipeNode() {
        token = {'|', '|'};
    };

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;


};


#endif //REGEXP_PIPENODE_H
