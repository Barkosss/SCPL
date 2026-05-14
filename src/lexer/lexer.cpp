#include "lexer.h"
#include<sstream>

bool isSpace(const char chr);
bool isNewline(const char chr);
bool isOperator(const char chr);
bool isLetter(const char chr);
bool isDigit(const char chr);
bool isLeftBracket(const char chr);
bool isRightBracket(const char chr);
bool isBracket(const char chr);
bool isSign(const char chr);

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    std::string buffer = "";
    for(char symbol : source) {
        if (isSpace(symbol)) {
            this->pos++;
            continue;
        }

        if (isNewline(symbol)) {
            this->pos = 1;
            this->line++;
            continue;
        }

        if (isLetter(symbol)) {
            buffer.push_back(symbol);
            
        }
    }

    return tokens;
}

bool isSpace(const char chr) {
    return (chr == ' ') || (chr == '\t') ||
           (chr == '\r') || (chr == '\f') ||
           (chr == '\b') || (chr == '\v');
}

bool isNewline(const char chr) {
    return (chr == '\n');
}

bool isOperator(const char chr) {
    return (chr == '+') || (chr == '[') ||
           (chr == '-') || (chr == ']') ||
           (chr == '*') || (chr == '{') ||
           (chr == '/') || (chr == '}') ||
           (chr == '<') || (chr == ',') ||
           (chr == '=') || (chr == '%') ||
           (chr == '>') || (chr == '?') ||
           (chr == '!') || (chr == '|') ||
           (chr == '(') || (chr == '&') ||
           (chr == ')') || (chr == ':') ||
           (chr == ';');
}

bool isLetter(const char chr) {
    return (('a' <= chr) || (chr <= 'z')) || (('A' <= chr) || (chr <= 'Z'));
}

bool isDigit(const char chr) {
    return ('0' <= chr) && (chr <= '9');
}

bool isLeftBracket(const char chr) {
    return (chr == '(') || (chr == '{') || (chr == '[');
}

bool isRightBracket(const char chr) {
    return (chr == ')') || (chr == '}') || (chr == ']');
}

bool isBracket(const char chr) {
    return isLeftBracket(chr) || isRightBracket(chr);
}

bool isSign(const char chr) {
    return (chr == '-') || (chr == '+');
}
