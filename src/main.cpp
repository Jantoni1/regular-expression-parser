#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "pattern/Pattern.h"




void showContent(std::string &path) {
    std::ifstream str(path);
    if(!str.is_open()) {
        throw std::runtime_error("Could not open file" + path);
    }
    std::string line;
    while(getline(str, line)) {
        std::cout<<line<<std::endl;
    }
    str.close();
}


void printOutput(bool result) {
    if(result) {
        std::cout<<"PASUJE"<<std::endl;
    }
    else {
        std::cout<<"NIE PASUJE" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    try {
        std::string path;
        if(argc == 2) {
            path = argv[1];
        }
        else {
            throw std::runtime_error("Usage: program <regexp_filename> ");
        }
        std::cout<<"Given regular expression: "<<std::endl;
        showContent(path);
        Pattern pattern(path);
        pattern.buildAutomaton();
        std::cout<< "Input a string to verify:"<<std::endl;
        while(path != "\\q") {
            std::cin>>path;
            printOutput(pattern.verify(path));
        }
    }
    catch(ParserException &e) {
        std::cout<<e.line << std::endl;
        for(int i = 0; i < e.column; ++i) {
            std::cout<<" ";
        }
        std::cout<<"^"<<std::endl;
        std::cout<<e.reason<<std::endl;
    }
    catch(std::runtime_error &e) {
        std::cout<<e.what()<<std::endl;
    }
    catch(...) {

    }
    return 0;
}