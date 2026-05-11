#include<vector>
#include "../lexer/lexer.h"

class Parser {

public:
    Parser(const std::vector<Token> &source) {}
    auto parse();
};