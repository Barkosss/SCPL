#pragma once

#include<vector>
#include<string>

/**
 * @brief Types of tokens recognized by the lexer.
 */
enum class TokenType {
    // Operators
    PLUS,        ///< '+'
    MINUS,       ///< '-'
    STAR,        ///< '*'
    SLASH,       ///< '/'
    BACKSLASH,   ///< '\'
    PERCENT,     ///< '%'
    ASSIGN,      ///< '='
    
    // Punctuation
    COMMA,       ///< ','
    SEMICOLON,   ///< ';'
    LPAREN,      ///< '('
    RPAREN,      ///< ')'
    LBRACE,      ///< '{'
    RBRACE,      ///< '}'
    COLON,       ///< ':'
    DOUBLE_QUOTE,///< '"'
    QUOTE,       ///< '\''
    AMPERSAND,   ///< '&'
    
    // Values
    NUMBER,      ///< Integer literal (e.g., 42)
    IDENTIFIER,  ///< Variable/function name (e.g., x, main)
    
    // Keywords
    KEYWORD_VOID,    ///< 'void'
    KEYWORD_INT,     ///< 'int'
    KEYWORD_UINT,    ///< 'uint'
    KEYWORD_LONG,    ///< 'long'
    KEYWORD_BOOL,    ///< 'bool'
    KEYWORD_CHAR,    ///< 'char'
    KEYWORD_IF,      ///< 'if'
    KEYWORD_ELSE,    ///< 'else'
    KEYWORD_SWITCH,  ///< 'switch'
    KEYWORD_CASE,    ///< 'case'
    KEYWORD_BREAK,   ///< 'break'
    KEYWORD_RETURN,  ///< 'return'
    
    ERROR,           ///< Invalid token
    END_OF_FILE      ///< End of input
};

/**
 * @brief Represents a single token from the source code.
 */
struct Token {
    TokenType type;      ///< Type of the token
    std::string value;   ///< Lexical value as string
    int line;            ///< Source line number (1-based)
    int column;          ///< Source column number (1-based)
};

/**
 * @brief Lexer class that converts source code into a stream of tokens.
 */
class Lexer {
private:
    std::string source;  ///< Source code string
    int pos;             ///< Current position in source (0-indexed)
    int line;            ///< Current line number (1-indexed)
    int col;             ///< Current column number (1-indexed)
    
    /**
     * @brief Reads a number token from the current position.
     * @return Token The NUMBER token.
     */
    Token readNumber();
    
    /**
     * @brief Reads an identifier or keyword from the current position.
     * @return Token KEYWORD_* or IDENTIFIER token.
     */
    Token readIdentifier();
    
    /**
     * @brief Reads an operator or punctuation token.
     * @return Token The corresponding operator token.
     */
    Token readOperator();
    
    /**
     * @brief Returns the current character without advancing.
     * @return char Current character, or '\0' if at end.
     */
    char currentChar();
    
    /**
     * @brief Advances to the next character, tracking line/column.
     */
    void advance();
    
    /**
     * @brief Skips whitespace characters (space, tab, newline, etc.).
     */
    void skipSpace();

public:
     /**
     * @brief Constructs a Lexer with the given source code.
     * @param source The source code string to tokenize.
     */
    Lexer(const std::string& source);
    
    /**
     * @brief Tokenizes the entire source code.
     * @return std::vector<Token> A vector containing all recognized tokens.
     */
    std::vector<Token> tokenize();
};