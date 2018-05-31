
#include "lexer_tests.h"
#include "lexer/Lexer.h"
#include "stdexcept"


#include <parser/nodes/AbstractNode.h>
#include <parser/Parser.h>
#include <generator/Generator.h>

#include <parser/nodes/ConcatNode.h>
#include <parser/nodes/SquareBracketNode.h>

bool check() {
    return true;
}

BOOST_AUTO_TEST_SUITE(LexerTests)

    BOOST_AUTO_TEST_CASE(lexer_return_char_T_of_type_a)
    {

        std::string s = "TKOM";
        Lexer lex;
        lex.setSource("lexer/test1.txt");

        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'a');
        BOOST_CHECK_EQUAL(result,'T');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_char_plus)
    {
        std::string s = "\\+";
        Lexer lex;
        lex.setSource("lexer/test2.txt");

        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'a');
        BOOST_CHECK_EQUAL(result,'+');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_char_escape)
    {
        std::string s = "\\\\";
        Lexer lex;
        lex.setSource("lexer/test3.txt");
        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'a');
        BOOST_CHECK_EQUAL(result,'\\');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_char_dot)
    {
        std::string s = "a.b";
        Lexer lex;
        lex.setSource("lexer/test4.txt");
        lex.getToken();
        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'.');
        BOOST_CHECK_EQUAL(result,'.');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_end)
    {
        std::string s = "a";
        Lexer lex;
        lex.setSource("lexer/test5.txt");
        lex.getToken();
        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'E');
        BOOST_CHECK_EQUAL(result,'E');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_error)
    {
        std::string s = "a\\b";
        Lexer lex;
        lex.setSource("lexer/test6.txt");
        lex.getToken();
        Lexer::Token t = lex.getToken();
        char type = t.first;
        char result = t.second;

        BOOST_CHECK_EQUAL(type,'a');
        BOOST_CHECK_EQUAL(result,'b');
    }

    BOOST_AUTO_TEST_CASE(lexer_return_invalid_end)
    {

        std::string s = "\\";
        Lexer lex;
        lex.setSource("lexer/test7.txt");
        BOOST_CHECK_THROW(lex.getToken(), ParserException);
    }

BOOST_AUTO_TEST_SUITE_END()

