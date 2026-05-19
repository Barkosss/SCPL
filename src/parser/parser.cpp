#include "parser.h"

#include <iostream>

/**
 * @brief Constructs a Parser with the given token list.
 * @param tokens Vector of tokens to parse.
 */
Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens), currentPos(0) {}

/**
 * @brief Parses the entire token stream into an AST.
 * @return std::unique_ptr<ASTNode> The root node of the AST, or nullptr on failure.
 */
std::unique_ptr<ASTNode> Parser::parse() {
    std::unique_ptr<ASTNode> statement;

    for (Token token : tokens) {
        
    }
}

/**
 * @brief Parses a single statement.
 * @return std::unique_ptr<ASTNode> The statement node, or nullptr on error.
 */
std::unique_ptr<ASTNode> Parser::parse_statement() {

}

/**
 * @brief Parses a variable declaration.
 * @return std::unique_ptr<ASTNode> The declaration node, or nullptr on error.
 */
std::unique_ptr<ASTNode> Parser::parse_declaration() {
    
}

/**
 * @brief Parses an expression (lowest precedence: +, -).
 * @return std::unique_ptr<ASTNode> The expression node, or nullptr on error.
 */
std::unique_ptr<ASTNode> Parser::parse_expression() {
    
}

/**
 * @brief Parses a term (medium precedence: *, /).
 * @return std::unique_ptr<ASTNode> The term node, or nullptr on error.
 */
std::unique_ptr<ASTNode> Parser::parse_term() {
    
}

/**
 * @brief Parses a factor (highest precedence: numbers, parentheses, variables).
 * @return std::unique_ptr<ASTNode> The factor node, or nullptr on error.
 */
std::unique_ptr<ASTNode> Parser::parse_factor() {
    
}

/**
 * @brief Returns the current token without consuming it.
 * @return Token The token at the current position.
 */
Token Parser::peek() const { return tokens[currentPos]; }

/**
 * @brief Returns the previously consumed token.
 * @return Token The token before the current position.
 */
Token Parser::previous() const {
    if (currentPos - 1 >= 0 && currentPos - 1 < tokens.size()) {
        return tokens[currentPos - 1];
    }
    return Token{TokenType::END_OF_FILE, "", 0, 0};
}

/**
 * @brief Consumes and returns the current token, advancing the position.
 * @return Token The consumed token.
 */
Token Parser::consume() { return tokens[currentPos++]; }

/**
 * @brief Checks if the current token matches the expected type.
 * If it matches, consumes it and returns true.
 * @param type The expected token type.
 * @return true If the token matched and was consumed.
 * @return false If the token did not match.
 */
bool Parser::match(TokenType type) {
    if (peek().type == type) {
        consume();
        return true;
    }

    return false;
}

/**
 * @brief Checks the current token type without consuming it.
 * @param type The token type to check against.
 * @return true If the current token matches the type.
 * @return false Otherwise.
 */
bool Parser::check(TokenType type) { return peek().type == type; }

/**
 * @brief Reports a syntax error with location information.
 * @param message The error message to display.
 */
void Parser::error(const std::string &message) {
    Token token = peek();
    std::cerr << "Ошибка на строке " << token.line << ", колонке " << token.column
                        << ": " << message << std::endl;
}

/**
 * @brief Synchronizes the parser after an error.
 * Skips tokens until a statement boundary (semicolon or keyword) is found.
 */
void Parser::synchronize() {
    while (peek().type != TokenType::END_OF_FILE) {
        if (previous().type == TokenType::SEMICOLON)
            return;

        switch (peek().type) {
            case TokenType::KEYWORD_INT:
            case TokenType::KEYWORD_RETURN:
            case TokenType::IDENTIFIER:
                return;
            default:
                consume();
        }
    }
}