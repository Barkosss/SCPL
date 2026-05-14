#include<iostream>
#include<fstream>
#include<string>
// #include "ast.h"
#include "./lexer/lexer.h"
// #include "./parser/parser.h"
// #include "./codegen_c/codegen_c.h"

const char *TokenTypeNames[] = {"PLUS",       "MINUS",      "STAR", "SLASH",
                                "IDENTIFIER", "IF",         "ELSE", "SWITCH",
                                "CASE",       "END_OF_FILE"};

std::ostream &operator<<(std::ostream &os, TokenType type) {
  os << TokenTypeNames[static_cast<int>(type)];
  return os;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: scc <file.scpl>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::cout << source << std::endl;
    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    for (Token token : tokens) {
        std::cout << "TokenType: " << token.type << std::endl;
        std::cout << "TokenType: " << token.value << std::endl;
        std::cout << "=========================" << std::endl;
    }

    // Parser parser(tokens);
    // auto ast = parser.parse();

    // CodeGenC codegen;
    std::string c_code = ""; // codegen.generate(ast.get());

    // std::ofstream out("out.o");
    // out << c_code;
    // out.close();

    // system("nasm -f elf64 out.s -o out.o");
    // system("ld out.o -o program");

    return 0;
}