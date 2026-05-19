/**
 * @file ast.h
 * @brief Abstract Syntax Tree nodes for the C compiler.
 */

#include<string>
#include<memory>
#include<vector>

/**
 * @brief Types supported by the compiler.
 */
enum class ASTType {
    VOID,   ///< void type (no value)
    INT,    ///< 32-bit integer
    UINT,   ///< 32-bit unsigned integer
    LONG,   ///< 64-bit integer
    BOOL,   ///< boolean (true/false)
    CHAR    ///< 8-bit character
};

enum class OpType {
    // Binary
    ADD, SUB, MUL, DIV, MOD,
    EQ, NE, LT, GT, LE, GE,
    AND, OR,
    // Unary
    NEG, NOT, DEREF, ADDRESS
};

/**
 * @brief Base class for all AST nodes.
 * 
 * All concrete node types inherit from this class.
 * Virtual destructor ensures proper cleanup of derived nodes.
 */
struct ASTNode {
    virtual ~ASTNode() = default;
};

/**
 * @brief Node representing a numeric literal.
 * 
 * @tparam NumberType The numeric type (int, long, etc.)
 * 
 * @example 42, 3.14, 1000L
 */
template<typename NumberType>
struct NumberNode : ASTNode {
    NumberType value;
};

/**
 * @brief Node representing a string literal.
 * 
 * @example "Hello, World!"
 */
struct StringNode : ASTNode {
    std::string value;
};

/**
 * @brief Node representing a binary operation.
 * 
 * @example a + b, x * y, left - right
 */
struct OperatorNode : ASTNode {
    char op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
};

/**
 * @brief Node representing a variable declaration.
 * 
 * @example int x = 42;
 *          bool flag = true;
 *          char c;
 */
struct VarDeclarationNode : ASTNode {
    ASTType type;
    std::string name;
    std::unique_ptr<ASTNode> initializer;
};

/**
 * @brief Node representing a function definition.
 * 
 * @example int add(int a, int b) { return a + b; }
 */
struct FunctionNode : ASTNode {
    ASTType type;
    std::string name;
    std::unique_ptr<ASTNode> parameters;
    std::unique_ptr<ASTNode> body;
};

/**
 * @brief Node representing the body of a function.
 * 
 * Contains a sequence of statements to be executed.
 */
struct FunctionBodyNode : ASTNode {
    std::vector<std::unique_ptr<ASTNode>> statements;
};

/**
 * @brief Node representing a function parameter.
 * 
 * @example int a, const char* str
 */
struct ParameterNode : ASTNode {
    ASTType type;
    std::string name;
};

/**
 * @brief Node representing a return statement.
 * 
 * @example return 42;
 *          return x + y;
 *          return;        // for void functions
 */
struct ReturnNode : ASTNode {
    std::unique_ptr<ASTNode> value;
};

/**
 * @brief Node representing a function call.
 * 
 * @example add(5, 3);
 *          printf("Hello");
 *          foo(bar(), 42);
 */
struct FunctionCallNode : ASTNode {
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> arguments;
};