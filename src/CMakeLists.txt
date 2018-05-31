add_library(Lexer lexer/Lexer.h lexer/Lexer.cpp parser/ParserException.cpp parser/ParserException.h lexer/Source.h lexer/Source.cpp generator/Generator.cpp generator/Generator.h)
add_library(Parser parser/Parser.h parser/Parser.cpp parser/nodes/AbstractNode.cpp parser/nodes/AbstractNode.h parser/nodes/PlusNode.cpp parser/nodes/PlusNode.h parser/nodes/DotNode.cpp parser/nodes/DotNode.h parser/nodes/QuestionMarkNode.cpp parser/nodes/QuestionMarkNode.h parser/nodes/SquareBracketNode.cpp parser/nodes/SquareBracketNode.h parser/nodes/AsteriskNode.cpp parser/nodes/AsteriskNode.h parser/nodes/PipeNode.cpp parser/nodes/PipeNode.h parser/nodes/ConcatNode.cpp parser/nodes/ConcatNode.h parser/nodes/HashNode.cpp parser/nodes/HashNode.h parser/nodes/CharacterNode.cpp parser/nodes/CharacterNode.h pattern/Pattern.cpp pattern/Pattern.h)
add_executable(Regexp main.cpp )
target_link_libraries(Parser Lexer)
target_link_libraries(Regexp Parser)

set_property(TARGET Regexp PROPERTY CXX_STANDARD 11)
set_property(TARGET Lexer PROPERTY CXX_STANDARD 11)
set_property(TARGET Parser PROPERTY CXX_STANDARD 11)