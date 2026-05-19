/**
 * @file lexer.cpp
 * @brief Implementation of the Lexer class.
 */

#include "lexer.h"
#include<iostream>
#include<sstream>


/**
 * @brief Constructs a Lexer with the given source code.
 * @param source The source code string to tokenize.
 */
Lexer::Lexer(const std::string& source) : source(source), pos(0), line(1), col(1) {}

/**
 * @brief Tokenizes the entire source code.
 * @return std::vector<Token> A vector containing all recognized tokens.
 */
std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (pos < source.length()) {
        char chr = currentChar();
        std::cout << "Char: " << chr << std::endl;

        if (isspace(chr)) {
            skipSpace();
            continue;
        }

        if (isdigit(chr)) {
            tokens.push_back(readNumber());
            continue;
        }

        if (isalpha(chr) || chr == '_') {
            tokens.push_back(readIdentifier());
            continue;
        }

        tokens.push_back(readOperator());
    }

    return tokens;
}

/**
 * @brief Reads a number token from the current position.
 * @return Token The NUMBER token.
 */
Token Lexer::readNumber() {
    int start_line = line;
    int start_col = col;
    std::string value;
    
    while(pos < source.length() && isdigit(currentChar())) {
        value += currentChar();
        advance();
    }

    return Token{TokenType::NUMBER, value, start_line, start_col};
}

/**
 * @brief Reads an identifier or keyword from the current position.
 * @return Token KEYWORD_* or IDENTIFIER token.
 */
Token Lexer::readIdentifier()
{
    int start_line = line;
    int start_col = col;
    std::string value;

    while (pos < source.length() && (isalnum(currentChar()) || currentChar() == '_'))
    {
        value += currentChar();
        advance();
    }

    if (value == "int")
        return Token{TokenType::KEYWORD_INT, value, start_line, start_col};
    if (value == "uint")
        return Token{TokenType::KEYWORD_UINT, value, start_line, start_col};
    if (value == "long")
        return Token{TokenType::KEYWORD_LONG, value, start_line, start_col};
    if (value == "bool")
        return Token{TokenType::KEYWORD_BOOL, value, start_line, start_col};
    if (value == "char")
        return Token{TokenType::KEYWORD_CHAR, value, start_line, start_col};
    if (value == "if")
        return Token{TokenType::KEYWORD_IF, value, start_line, start_col};
    if (value == "else")
        return Token{TokenType::KEYWORD_ELSE, value, start_line, start_col};
    if (value == "switch")
        return Token{TokenType::KEYWORD_SWITCH, value, start_line, start_col};
    if (value == "case")
        return Token{TokenType::KEYWORD_CASE, value, start_line, start_col};
    if (value == "break")
        return Token{TokenType::KEYWORD_BREAK, value, start_line, start_col};
    if (value == "return")
        return Token{TokenType::KEYWORD_RETURN, value, start_line, start_col};

    return Token{TokenType::IDENTIFIER, value, start_line, start_col};
}

/**
 * @brief Reads an operator or punctuation token.
 * @return Token The corresponding operator token.
 */
Token Lexer::readOperator()
{
    int start_line = line;
    int start_col = col;
    char chr = currentChar();
    std::string value(1, chr);
    advance();

    switch (chr) {
        case '+':
            return Token{TokenType::PLUS, value, start_line, start_col};
        case '-':
            return Token{TokenType::MINUS, value, start_line, start_col};
        case '*':
            return Token{TokenType::STAR, value, start_line, start_col};
        case '/':
            return Token{TokenType::SLASH, value, start_line, start_col};
        case '\\':
            return Token{TokenType::BACKSLASH, value, start_line, start_col};
        case '%':
            return Token{TokenType::PERCENT, value, start_line, start_col};
        case '=':
            return Token{TokenType::ASSIGN, value, start_line, start_col};
        case ',':
            return Token{TokenType::COMMA, value, start_line, start_col};
        case ';':
            return Token{TokenType::SEMICOLON, value, start_line, start_col};
        case '(':
            return Token{TokenType::LPAREN, value, start_line, start_col};
        case ')':
            return Token{TokenType::RPAREN, value, start_line, start_col};
        case '{':
            return Token{TokenType::LBRACE, value, start_line, start_col};
        case '}':
            return Token{TokenType::RBRACE, value, start_line, start_col};
        case ':':
            return Token{TokenType::COLON, value, start_line, start_col};
        case '"':
            return Token{TokenType::DOUBLE_QUOTE, value, start_line, start_col};
        case '\'':
            return Token{TokenType::QUOTE, value, start_line, start_col};
        case '&':
            return Token{TokenType::AMPERSAND, value, start_line, start_col};
        default:
            std::cerr << "Unknown operator: " << chr << " at line " << line << std::endl;
            return Token{TokenType::ERROR, value, start_line, start_col};
    }
}

/**
 * @brief Returns the current character without advancing.
 * @return char Current character, or '\0' if at end.
 */
char Lexer::currentChar() {
    if (pos >= source.length()) return '\0';
    return source[pos];
}

/**
 * @brief Advances to the next character, tracking line/column.
 */
void Lexer::advance() {
    if (currentChar() == '\n') {
        line++;
        col = 1;
    } else {
        col++;
    }
    pos++;
}

/**
 * @brief Skips whitespace characters (space, tab, newline, etc.).
 */
void Lexer::skipSpace() {
    while (pos < source.length() && isspace(currentChar())) {
        advance();
    }
}