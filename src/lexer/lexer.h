#pragma once

#include<vector>
#include<string>

enum class TokenType {
    PLUS, MINUS, STAR, SLASH,
    NUMBER,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
    std::string source;
    int pos;
    int line;

public:
    Lexer(const std::string &source) : source(source), pos(0), line(1) {}
    std::vector<Token> tokenize();
};