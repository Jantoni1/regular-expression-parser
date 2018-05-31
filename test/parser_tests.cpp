
#include "parser_tests.h"
#include <parser/nodes/ConcatNode.h>
#include <parser/nodes/SquareBracketNode.h>
#include "lexer/Lexer.h"
#include "parser/Parser.h"

void print(AbstractNode *node) {
    if(node != nullptr) {
        print(node->getLeft());
        print(node->getRight());
    }
}

BOOST_AUTO_TEST_SUITE(ParserTests)

BOOST_AUTO_TEST_CASE(parseValidString)
        {
                auto *l = new Lexer();
        l->setSource("parser/test1.txt");
        auto *p = new Parser(l);
        auto *n = p->parse();
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getLeft()->getToken().second, 'b');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getRight()->getToken().second, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().second, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().first, 'c');

        BOOST_CHECK_EQUAL(n->getRight()->getToken().first, '#');
        BOOST_CHECK_EQUAL(n->getLeft()->getToken().first, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getToken().second, 'a');
        BOOST_CHECK_EQUAL(n->getToken().first, 'c');

        delete p;
        delete n;

        }

BOOST_AUTO_TEST_CASE(parseValidString2)
        {
                auto *l = new Lexer();
        l->setSource("parser/test2.txt");
        auto *p = new Parser(l);
        auto *n = p->parse();
        //        print(n);
        BOOST_CHECK_EQUAL(n->getToken().first, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getToken().first, ']');
        BOOST_CHECK_EQUAL(n->getRight()->getToken().first, '#');
        BOOST_TEST(dynamic_cast<SquareBracketNode *>(n->getLeft()) != nullptr);
        const auto set = dynamic_cast<SquareBracketNode *>(n->getLeft())->getCharacter_set();
        bool first = set.find('a') != set.end();
        bool second = set.find('b') != set.end();
        bool third = set.find('c') != set.end();
        BOOST_TEST(first);
        BOOST_TEST(second);
        BOOST_TEST(third);
        auto size = set.size();
        BOOST_CHECK_EQUAL(size, 3);
        delete p;
        delete n;

        }

BOOST_AUTO_TEST_CASE(parseValidString3)
{
    auto *l = new Lexer();
    l->setSource("parser/test3.txt");
    auto *p = new Parser(l);
    auto *n = p->parse();
    BOOST_CHECK_EQUAL(n->getRight()->getToken().first, '#');
    BOOST_TEST(dynamic_cast<ConcatNode *>(n) != nullptr);
    BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().second, 'b');
    BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getRight()->getToken().second, 'a');
    BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getToken().first, '*');

    delete p;
    delete n;
}

BOOST_AUTO_TEST_CASE(parseInvalidString)
{
    auto *l = new Lexer();
    l->setSource("parser/test4.txt");
    auto *p = new Parser(l);
    BOOST_CHECK_THROW(p->parse(), ParserException);
    delete p;
}

BOOST_AUTO_TEST_CASE(parseValidString4)
        {
                auto *l = new Lexer();
        l->setSource("parser/test5.txt");
        auto *p = new Parser(l);
        auto *n = p->parse();
        BOOST_CHECK_EQUAL(n->getToken().second, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getToken().second, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getToken().second, 'a');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().second, 'b');
        BOOST_CHECK_EQUAL(n->getRight()->getToken().second, '#');
        delete p;
        delete n;
        }

BOOST_AUTO_TEST_CASE(parseValidString5) {
        auto *l = new Lexer();
        l->setSource("parser/test6.txt");
        auto *p = new Parser(l);
        auto *n = p->parse();
        BOOST_CHECK_EQUAL(n->getRight()->getToken().first, '#');
        BOOST_TEST(dynamic_cast<ConcatNode *>(n) != nullptr);
        BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getToken().first, '.');
        BOOST_CHECK_EQUAL(n->getLeft()->getToken().first, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().first, 'c');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getLeft()->getToken().first, '?');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getLeft()->getRight()->getToken().second, 'k');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getRight()->getToken().first, '+');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getRight()->getRight()->getToken().second, 'c');
        delete p;
        delete n;
}

BOOST_AUTO_TEST_CASE(parseValidString6) {
        auto *l = new Lexer();
        l->setSource("parser/test7.txt");

        auto *p = new Parser(l);

        auto *n = p->parse();

        BOOST_CHECK_EQUAL(n->getLeft()->getToken().first, '|');
        BOOST_CHECK_EQUAL(n->getLeft()->getLeft()->getToken().second, 'a');
        BOOST_CHECK_EQUAL(n->getLeft()->getRight()->getToken().second, 'b');
        delete p;
        delete n;
}


BOOST_AUTO_TEST_SUITE_END()