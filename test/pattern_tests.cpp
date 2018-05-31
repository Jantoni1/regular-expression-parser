

#include <pattern/Pattern.h>
#include "pattern_tests.h"

BOOST_AUTO_TEST_SUITE(pattern_test)
    BOOST_AUTO_TEST_CASE(verify1) {
        Pattern pattern("parser/test1.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), false);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), false);
        BOOST_CHECK_EQUAL(pattern.verify("abc"), true);
        BOOST_CHECK_EQUAL(pattern.verify("abcd"), false);

    }
    BOOST_AUTO_TEST_CASE(verify2) {
        Pattern pattern("parser/test2.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), true);
        BOOST_CHECK_EQUAL(pattern.verify("b"), true);
        BOOST_CHECK_EQUAL(pattern.verify("c"), true);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), false);
        BOOST_CHECK_EQUAL(pattern.verify("1"), false);
        BOOST_CHECK_EQUAL(pattern.verify("d"), false);
        BOOST_CHECK_EQUAL(pattern.verify("aa"), false);
    }
    BOOST_AUTO_TEST_CASE(verify3) {
        Pattern pattern("parser/test3.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), false);
        BOOST_CHECK_EQUAL(pattern.verify("aa"), false);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), true);
        BOOST_CHECK_EQUAL(pattern.verify("b"), true);
        BOOST_CHECK_EQUAL(pattern.verify("aab"), true);
        BOOST_CHECK_EQUAL(pattern.verify("aaaab"), true);
        BOOST_CHECK_EQUAL(pattern.verify("aaaa"), false);
        BOOST_CHECK_EQUAL(pattern.verify("aba"), false);
    }
    BOOST_AUTO_TEST_CASE(verify4) {
        Pattern pattern("parser/test4.txt");
        BOOST_CHECK_THROW(pattern.buildAutomaton(), ParserException);
    }
    BOOST_AUTO_TEST_CASE(verify5) {
        Pattern pattern("parser/test5.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), false);
        BOOST_CHECK_EQUAL(pattern.verify("abcc"), false);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), true);

    }
    BOOST_AUTO_TEST_CASE(verify6) {
        Pattern pattern("parser/test6.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("ac"), true);
        BOOST_CHECK_EQUAL(pattern.verify("bkc"), true);
        BOOST_CHECK_EQUAL(pattern.verify("cccccc"), true);
        BOOST_CHECK_EQUAL(pattern.verify("1c"), true);
        BOOST_CHECK_EQUAL(pattern.verify("k"), false);
        BOOST_CHECK_EQUAL(pattern.verify("ca"), false);
    }
    BOOST_AUTO_TEST_CASE(verify7) {
        Pattern pattern("parser/test7.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), true);
        BOOST_CHECK_EQUAL(pattern.verify("b"), true);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), false);
        BOOST_CHECK_EQUAL(pattern.verify("c"), false);
    }
    BOOST_AUTO_TEST_CASE(verify8) {
        Pattern pattern("parser/test8.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), true);
        BOOST_CHECK_EQUAL(pattern.verify(""), true);
        BOOST_CHECK_EQUAL(pattern.verify("b"), true);
        BOOST_CHECK_EQUAL(pattern.verify("aaaaaaab"), true);
        BOOST_CHECK_EQUAL(pattern.verify("aaaaaa"), true);
        BOOST_CHECK_EQUAL(pattern.verify("bb"), false);
        BOOST_CHECK_EQUAL(pattern.verify("ac"), false);

    }
    BOOST_AUTO_TEST_CASE(verify9) {
        Pattern pattern("parser/test9.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("aaaaaaaaaaaaaa"), true);
        BOOST_CHECK_EQUAL(pattern.verify(""), true);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), false);
        BOOST_CHECK_EQUAL(pattern.verify("abb"), false);
        BOOST_CHECK_EQUAL(pattern.verify("a"), true);
    }

    BOOST_AUTO_TEST_CASE(verify10) {
        Pattern pattern("parser/test10.txt");
        pattern.buildAutomaton();
        BOOST_CHECK_EQUAL(pattern.verify("a"), true);
        BOOST_CHECK_EQUAL(pattern.verify(""), true);
        BOOST_CHECK_EQUAL(pattern.verify("ab"), false);
        BOOST_CHECK_EQUAL(pattern.verify("abb"), false);
        BOOST_CHECK_EQUAL(pattern.verify("b"), true);
    }
BOOST_AUTO_TEST_SUITE_END()