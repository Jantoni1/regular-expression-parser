#include "ParserException.h"

ParserException::ParserException(std::string line, int row, int column, std::string reason) {
    this->reason = reason;
    this->line = std::move(line);
    this->row = row;
    this->column = column;
}
