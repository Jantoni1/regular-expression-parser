

#include <parser/nodes/AbstractNode.h>
#include <parser/Parser.h>
#include <generator/Generator.h>
#include "generator_tests.h"

void printNullable(AbstractNode *node) {
    if(node != nullptr) {
        printNullable(node->getLeft());
        printNullable(node->getRight());
    }
}


AbstractNode* generateNode(std::string file) {
    auto *l = new Lexer();
    l->setSource(std::move(file));
    Parser p(l);
    auto *n = p.parse();
    return n;
}



BOOST_AUTO_TEST_SUITE(generator_suite)

    BOOST_AUTO_TEST_SUITE(set_nullable_suite)

        BOOST_AUTO_TEST_CASE(check_nullable_1) {


            auto root = generateNode("parser/test1.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getLeft()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->getLeft()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->getRight()->isNullable(), false);

        }

        BOOST_AUTO_TEST_CASE(check_nullable_2) {
            auto root = generateNode("parser/test2.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), false);

        }

        BOOST_AUTO_TEST_CASE(check_nullable_3) {
            auto root = generateNode("parser/test3.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getLeft()->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getLeft()->isNullable(), true);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), false);

        }

        BOOST_AUTO_TEST_CASE(check_nullable_4)
        {
            auto root = generateNode("parser/test6.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->getLeft()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->isNullable(), false);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->getLeft()->isNullable(), true);
            BOOST_CHECK_EQUAL(root->getLeft()->getRight()->getRight()->isNullable(), false);

        }

        BOOST_AUTO_TEST_CASE(check_nullable_5)
        {
            auto root = generateNode("parser/test8.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), true);


        }

        BOOST_AUTO_TEST_CASE(check_nullable_6)
        {
            auto root = generateNode("parser/test7.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), false);
        }

        BOOST_AUTO_TEST_CASE(check_nullable_7)
        {
            auto root = generateNode("parser/test9.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), true);

        }

        BOOST_AUTO_TEST_CASE(check_nullable_8)
        {
            auto root = generateNode("parser/test10.txt");
            Generator generator;
            generator.setRoot(root);
            generator.setNullable();
            BOOST_CHECK_EQUAL(root->getLeft()->isNullable(), true);


        }



    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(set_first_suite)

        AbstractNode* setFirst(std::string path)
        {
            auto root = generateNode(std::move(path));
            Generator generator;
            generator.setRoot(root);
            generator.setFirst();
            generator.setRoot(nullptr);
            return root;
        }

        BOOST_AUTO_TEST_CASE(set_first_1)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getLeft()->getLeft()->getFirst();
            bool result1 = set.find(1) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;


        }

        BOOST_AUTO_TEST_CASE(set_first_2)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getLeft()->getFirst();
            bool result1 = set.find(1) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;

        }

        BOOST_AUTO_TEST_CASE(set_first_3)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getFirst();
            bool result1 = set.find(1) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;

        }

        BOOST_AUTO_TEST_CASE(set_first_4)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getFirst();
            bool result1 = set.find(2) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;

        }

        BOOST_AUTO_TEST_CASE(set_first_5)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getLeft()->getFirst();
            bool result1 = set.find(2) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;

        }

        BOOST_AUTO_TEST_CASE(set_first_6)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getRight()->getFirst();
            bool result1 = set.find(4) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_first_7)
        {
            auto root = setFirst("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getRight()->getFirst();
            bool result1 = set.find(3) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;


        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(set_last_test_suite)

        AbstractNode* setLast(std::string path)
        {
            auto root = generateNode(std::move(path));
            Generator generator;
            generator.setRoot(root);
            generator.setFirst();
            generator.setLast();
            generator.setRoot(nullptr);
            return root;
        }
        BOOST_AUTO_TEST_CASE(set_last_1)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLeft()->getLeft()->getLast();
            bool result1 = set.find(1) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_last_2)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getLeft()->getLast();
            bool result1 = set.find(2) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_last_3)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getRight()->getLast();
            bool result1 = set.find(3) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }
        BOOST_AUTO_TEST_CASE(set_last_4)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLeft()->getRight()->getLast();
            bool result1 = set.find(3) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_last_5)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLeft()->getLast();
            bool result1 = set.find(3) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_last_6)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getRight()->getLast();
            bool result1 = set.find(4) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }

        BOOST_AUTO_TEST_CASE(set_last_7)
        {
            auto root = setLast("parser/test1.txt");
            auto set = root->getLast();
            bool result1 = set.find(4) != set.end();
            BOOST_CHECK_EQUAL(result1, true);
            BOOST_CHECK_EQUAL(set.size(), 1);
            delete root;
        }
    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

