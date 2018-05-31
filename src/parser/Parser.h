#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <set>
#include <vector>
#include "../lexer/Lexer.h"
#include "nodes/AbstractNode.h"
#include <memory>
#include <functional>

class Parser {

public:

	explicit Parser(Lexer*);
	~Parser()
	{
		delete lexer;
	}
	AbstractNode* parse();



	using ParseResult = std::pair<int, std::unique_ptr<AbstractNode>>; // type, value
	const int Success = 1;
	const int Failure = 0;



private:
	ParseResult S();
	ParseResult Sprime();
	ParseResult A();
	ParseResult Aprime();
	ParseResult B();
	ParseResult C();
	ParseResult D();
	bool E(std::set<char> &);
	bool F(std::set<char> &);

	bool isIntervalCorrect(char a, char b);

	void advance();
	ParseResult concPipe(ParseResult pr1, ParseResult pr2);
	ParseResult concDot(ParseResult pr1, ParseResult pr2);
	ParseResult concStar(ParseResult pr1);
	ParseResult concPlus(ParseResult pr1);
	ParseResult concQuestionMark(ParseResult pr1);

	ParserException getParserException(Reason reason) const;

	int number = 0; // this is a number to set in struct

	Lexer *lexer;
	Lexer::Token currentToken;
};


#endif //PARSER_H_