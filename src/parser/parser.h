/**
 * @file parser.h
 * @brief Syntactic analyzer for the C compiler.
 */

#pragma once

#include<vector>
#include<memory>
#include "../lexer/lexer.h"
#include "../ast/ast.h"

/**
 * @class Parser
 * @brief Parses a token stream into an Abstract Syntax Tree (AST).
 * 
 * Implements a recursive-descent parser for a subset of C.
 * Expects tokens from the lexer and builds an AST for further processing.
 */
class Parser {
    std::vector<Token> tokens;  ///< Input token stream
    int currentPos;             ///< Current position in the token stream

    /**
     * @brief Parses a single statement.
     * @return std::unique_ptr<ASTNode> The statement node, or nullptr on error.
     */
    std::unique_ptr<ASTNode> parse_statement();
    
    /**
     * @brief Parses a variable declaration.
     * @return std::unique_ptr<ASTNode> The declaration node, or nullptr on error.
     */
    std::unique_ptr<ASTNode> parse_declaration();
    
    /**
     * @brief Parses an expression (lowest precedence: +, -).
     * @return std::unique_ptr<ASTNode> The expression node, or nullptr on error.
     */
    std::unique_ptr<ASTNode> parse_expression();
    
    /**
     * @brief Parses a term (medium precedence: *, /).
     * @return std::unique_ptr<ASTNode> The term node, or nullptr on error.
     */
    std::unique_ptr<ASTNode> parse_term();
    
    /**
     * @brief Parses a factor (highest precedence: numbers, parentheses, variables).
     * @return std::unique_ptr<ASTNode> The factor node, or nullptr on error.
     */
    std::unique_ptr<ASTNode> parse_factor();

    /**
     * @brief Returns the current token without consuming it.
     * @return Token The token at the current position.
     */
    Token peek() const;
    
    /**
     * @brief Returns the previously consumed token.
     * @return Token The token before the current position.
     */
    Token previous() const;

    /**
     * @brief Consumes and returns the current token, advancing the position.
     * @return Token The consumed token.
     */
    Token consume();
    
    /**
     * @brief Checks if the current token matches the expected type.
     * If it matches, consumes it and returns true.
     * @param type The expected token type.
     * @return true If the token matched and was consumed.
     * @return false If the token did not match.
     */
    bool match(TokenType type);
    
    /**
     * @brief Checks the current token type without consuming it.
     * @param type The token type to check against.
     * @return true If the current token matches the type.
     * @return false Otherwise.
     */
    bool check(TokenType type);

    /**
     * @brief Reports a syntax error with location information.
     * @param message The error message to display.
     */
    void error(const std::string& message);
    
    /**
     * @brief Synchronizes the parser after an error.
     * Skips tokens until a statement boundary (semicolon or keyword) is found.
     */
    void synchronize();

public:
    /**
     * @brief Constructs a Parser with the given token list.
     * @param tokens Vector of tokens to parse.
     */
    Parser(const std::vector<Token>& tokens);

    /**
     * @brief Parses the entire token stream into an AST.
     * @return std::unique_ptr<ASTNode> The root node of the AST, or nullptr on failure.
     */
    std::unique_ptr<ASTNode> parse();
};