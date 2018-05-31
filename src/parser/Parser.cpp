#include "Parser.h"
#include "../lexer/Lexer.h"
#include "nodes/AbstractNode.h"
#include "nodes/HashNode.h"
#include "nodes/AsteriskNode.h"
#include "nodes/ConcatNode.h"
#include "nodes/PlusNode.h"
#include "nodes/QuestionMarkNode.h"
#include "nodes/DotNode.h"
#include "nodes/SquareBracketNode.h"
#include "ParserException.h"
#include "nodes/CharacterNode.h"
#include "nodes/PipeNode.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>

const static std::vector<std::string> reason_description =
        {
                "Parser found single escape mark as the last character of input."
                , "First and last character of interval do not create an actual interval e.g a-z or 0-9."
                , "An unexpected token."
                , "No closing bracket found."
                , "Found an empty interval."
        };

Parser::Parser(Lexer *l)
{
    lexer = l;
}

AbstractNode* Parser::parse()
{
    advance();
        Parser::ParseResult root = S();
        if (root.first == Success && currentToken.first == 'E')
        {
            auto hash = std::unique_ptr<HashNode>(new HashNode());
            hash->setNumber(++number);
            ParseResult res = { Success, std::move(hash) };
            return concDot(std::move(root), std::move(res)).second.release();
        }
        else
            throw getParserException(Reason::UNEXPECTED_TOKEN);
}

Parser::ParseResult Parser::S()
{
    ParseResult prA = A();
    ParseResult prSprime = Sprime();
    return concPipe(std::move(prA), std::move(prSprime));
}

Parser::ParseResult Parser::Sprime()
{
    if (currentToken.first == '|')
    {
        advance();
        Parser::ParseResult prA = A();
        Parser::ParseResult prSprime = Sprime();

        if (prA.first == Success && prSprime.first == Success) //check bcos if failure, return success (eps)
        {
            return concPipe(std::move(prA), std::move(prSprime));
        }

    }
    return { Success, nullptr };
}

Parser::ParseResult Parser::A()
{
    ParseResult prB = B();
    ParseResult prAprime = Aprime();
    return concDot(std::move(prB), std::move(prAprime));
}

Parser::ParseResult Parser::Aprime()
{
    Parser::ParseResult prB = B();
    if (prB.first == Success) {
        Parser::ParseResult prAprime = Aprime();
        return concDot(std::move(prB), std::move(prAprime));
    }
    return { Success, nullptr };
}

Parser::ParseResult Parser::B()
{
    ParseResult prC = C();
    if (currentToken.first == '+') {
        advance();
        return concPlus(std::move(prC));
    }
    else if (currentToken.first == '?') {
        advance();
        return concQuestionMark(std::move(prC));
    }
    return prC;
}

Parser::ParseResult Parser::C()
{
    ParseResult prD = D();
    if (currentToken.first == '*') {
        advance();
        return concStar(std::move(prD));
    }
    return prD;
}

Parser::ParseResult Parser::D()
{
    switch (currentToken.first) {
        case '(':
        {
            advance();
            ParseResult prS = S();
            if (prS.first == Success && currentToken.first == ')')
            {
                advance();
                return prS;
            }
            else
            {
                throw getParserException(Reason::NO_PARENTHESIS);
            }
        }
        case '.': {
            auto node = std::unique_ptr<DotNode>(new DotNode(++number));
            advance();
            return { Success, std::move(node) };
        }
        case '[': {
            advance();
            auto squareBracket = std::unique_ptr<SquareBracketNode>(new SquareBracketNode()) ;
            // auto squareBracketNode = std::unique_ptr<AbstractNode>(SquareBracketNode());
            if (currentToken.first == '^') {
                squareBracket->setNegate(true);
                // dynamic_cast<SquareBracketNode*>(squareBracketNode.get())->setNegate(true);
                advance();
            }
            std::set<char> set;
            int current_number = number;
            if (!E(set)) {
                throw getParserException(Reason::EMPTY_INTERVAL);
            }
            if (currentToken.first == ']') {
                advance();
                squareBracket->set_character_set(set);
                squareBracket->setNumber(current_number);
                number = current_number;
                return { Success, std::move(squareBracket) };
            }
            else {
                //throw exception
                throw getParserException(Reason::NO_PARENTHESIS);
            }
        }
        case 'a': {
            auto node = std::unique_ptr<CharacterNode>(new CharacterNode());
            node->setToken(currentToken);
            node->setNumber(number);
            advance();
            return { Success, std::move(node) };
        }
        default:
            return { Failure, nullptr };
    }

}

bool Parser::E(std::set<char> & set) {
    if (F(set)) {
        while (F(set));
        return true;
    }
    return false;
}

bool Parser::F(std::set<char> &set) {
    if (currentToken.first == 'a') {
        auto range_beginning = currentToken.second;
        advance();
        switch (currentToken.first) {
            case 'a':
            case ']': {
                set.insert(range_beginning);
                return true;
            }
            case '-': {
                advance();
                if (currentToken.first == 'a'
                    && isIntervalCorrect(range_beginning, currentToken.second)) {
                    for (auto iter = static_cast<int>(range_beginning); iter <= static_cast<int>(currentToken.second); iter++) {
                        set.insert(static_cast<char>(iter));
                    }
                    return true;
                }
                else {
                    if (currentToken.first != 'a') {
                        throw getParserException(Reason::UNEXPECTED_TOKEN);
                    }
                    else throw getParserException(Reason::INCORRECT_INTERVAL);
                }
            }
            default: {
                throw getParserException(Reason::UNEXPECTED_TOKEN);
            }
        }
    }
    else if (currentToken.first == ']') {
        return false;
    }
    else {
        throw getParserException(Reason::UNEXPECTED_TOKEN);
    }
}

void Parser::advance()
{
    currentToken = lexer->getToken();
    if (currentToken.first == 'a') number++;
}

Parser::ParseResult Parser::concPipe(Parser::ParseResult pr1, Parser::ParseResult pr2)
{
    if (pr1.first * pr2.first == Failure)
    {
        return { Failure, nullptr };
    }
    else
    {//both Success
        auto node = std::unique_ptr<PipeNode>(new PipeNode());
        if (pr2.second != nullptr)
        {
            node->setRight(pr2.second.release());
            node->setLeft(pr1.second.release());
        }
        else
        {
            return pr1;
        }
        return { Success, std::move(node) };
    }
}

Parser::ParseResult Parser::concDot(Parser::ParseResult pr1, Parser::ParseResult pr2)
{
    if (pr1.first * pr2.first == Failure)
    {
        return { Failure, nullptr };
    }
    else
    {//both Success
        auto node = std::unique_ptr<ConcatNode>(new ConcatNode());
        if (pr2.second != nullptr)
        {
            node->setRight(std::move(pr2.second.release()));
            node->setLeft(std::move(pr1.second.release()));
        }
        else
        {
            return pr1;
        }
        return {Success, std::move(node)};
    }
}

Parser::ParseResult Parser::concPlus(Parser::ParseResult pr1)
{
    if (pr1.first == Failure || pr1.second == nullptr)
    {
        return { Failure, nullptr };
    }
    else
    {
        auto plusNode = std::unique_ptr<PlusNode>(new PlusNode());
        plusNode->setRight(pr1.second.release());
        return { Success, std::move(plusNode) };
    }
}

Parser::ParseResult Parser::concStar(Parser::ParseResult pr1)
{
    if (pr1.first == Failure || pr1.second == nullptr)
    {
        return { Failure, nullptr };
    }
    else
    {
        auto starNode = std::unique_ptr<AsteriskNode>(new AsteriskNode());
        starNode->setRight(pr1.second.release());
        return { Success, std::move(starNode) };
    }
}

bool Parser::isIntervalCorrect(char a, char b) {
    return ((isalpha(a) && isalpha(b)) || (isdigit(a) && isdigit(b))) && a < b;
}

ParserException Parser::getParserException(Reason reason) const {
    //    std::cout<<currentToken.second << " " << lexer->getColumnNumber() << std::endl;
    return ParserException(lexer->getLine(), lexer->getLineNumber(), lexer->getColumnNumber() - 1, reason_description[reason]);
}

Parser::ParseResult Parser::concQuestionMark(Parser::ParseResult pr1) {
    if (pr1.first == Failure || pr1.second == nullptr)
    {
        return { Failure, nullptr };
    }
    else
    {
        auto questionMarkNode = std::unique_ptr<QuestionMarkNode>(new QuestionMarkNode());
        questionMarkNode->setRight(pr1.second.release());
        return { Success, std::move(questionMarkNode) };
    }
}

