#pragma once

#include<vector>
#include<string>

enum class TokenType {
    PLUS, MINUS, START, SLASH,
    NUMBER
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
    Lexer(const std::string& source) : source(source) {}
    std::vector<Token> tokenize();
};