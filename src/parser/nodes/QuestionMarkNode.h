//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_QUESTIONMARKNODE_H
#define REGEXP_QUESTIONMARKNODE_H


#include "AbstractNode.h"
#include <set>
#include <map>

class QuestionMarkNode : public AbstractNode {
public:
    QuestionMarkNode()
    {
        token = {'?', '?'};
    }

    void setNullable() override;

    void setFirst() override;

    void setLast() override;

    void setFollow(std::map<int,std::set<int>> &) override;

    void setLetters(std::map<char, std::set<int>> &letters) override;


};


#endif //REGEXP_QUESTIONMARKNODE_H
