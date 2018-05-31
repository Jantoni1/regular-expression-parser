#include "Source.h"
#include <iostream>

Source::Source(const std::string &file) :
        file(file) {
    if (this->file.fail()) {
        std::cerr<<"Nie udalo sie wczytac pliku"<<std::endl;
        exit(-1);
    }
    this->linePosition = this->file.tellg();
}

char Source::getCurrentCharacter() {
    return currentCharacter;
}

void Source::nextCharacter() {
    if (currentCharacter == '\n' ){
        this->lineNumber++;
        this->linePosition = file.tellg();
        this->columnNumber = 0;}
    else
        this->columnNumber++;
    currentCharacter = static_cast<char>(file.get());
    if (this->file.eof())
        currentCharacter = ascii::EOT;
}

const unsigned int &Source::getLineNumber() const {
    return lineNumber;
}

const unsigned int &Source::getColumnNumber() const {
    return columnNumber;
}

const std::streampos& Source::getPosition() const {
    return linePosition;
}

const std::string Source::getLine(const std::streampos& position)
{
    const std::streampos currentPosition = file.tellg();
    std::string line;

    this->file.seekg(position);

    std::getline(file, line);

    this->file.seekg(currentPosition);

    return line;
}

Source::~Source() {
    file.close();
}


