#ifndef PROJEKT_SOURCE_H
#define PROJEKT_SOURCE_H

#include <fstream>
#include <string>
namespace ascii { static const char EOT(0x04); }

class Source {
public:
    Source(const std::string &file);
    ~Source();

    char getCurrentCharacter();

    void nextCharacter();

    const unsigned int &getLineNumber() const;

    const unsigned int &getColumnNumber() const;

    const std::streampos &getPosition() const;

    const std::string getLine(const std::streampos& position);

private:
    std::ifstream file;
    unsigned int lineNumber = 1;
    unsigned int columnNumber = 0;
    std::streampos linePosition;
    char currentCharacter;
};


#endif //PROJEKT_SOURCE_H
