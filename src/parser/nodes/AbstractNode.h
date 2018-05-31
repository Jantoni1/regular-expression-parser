//
// Created by Kuba on 26.05.2018.
//

#ifndef REGEXP_ABSTRACTNODE_H
#define REGEXP_ABSTRACTNODE_H


#include <map>
#include "../../lexer/Lexer.h"

class AbstractNode {
public:
    AbstractNode()
        : left(nullptr)
        , right(nullptr)
        , nullable(false)
        , first({})
        , last({})
        , follow ({})
    {}
    virtual ~AbstractNode() {
        delete left;
        delete right;
    }

    virtual void setNullable() = 0;

    virtual void setLetters(std::map<char, std::set<int>> &letters) = 0;

    virtual void setFirst() = 0;

    virtual void setLast() = 0;

    virtual void setFollow(std::map<int,std::set<int>> &) = 0;

    AbstractNode *getLeft() const;

    void setLeft(AbstractNode *left);

    AbstractNode *getRight() const;

    void setRight(AbstractNode *right);

    const Lexer::Token &getToken() const;

    void setToken(const Lexer::Token &token);

    int getNumber() const;

    void setNumber(int number);

    const std::set<int> &getFirst() const;

    const std::set<int> &getLast() const;

    void setLast(const std::set<int> &last);

    const std::set<int> &getFollow() const;

    void setFollow(const std::set<int> &follow);

    bool isNullable() const;


protected:

    AbstractNode* left;
    AbstractNode* right;
    Lexer::Token token;
    int number;
    std::set<int> first;
    std::set<int> last;
    std::set<int> follow;
    bool nullable;
};


#endif //REGEXP_ABSTRACTNODE_H
