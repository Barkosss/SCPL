# SCC - Simple C Compiler

SCC is a minimal C compiler written from scratch in C++ for educational purposes. The project aims to explore the internals of compilers: from lexical analysis to code generation.

## Features (Current & Planned)

### Implemented
- [x] Lexical analysis (tokenization)
- [x] Basic parser (recursive descent)
- [x] AST (Abstract Syntax Tree)
- [x] Type support: `int`, `uint`, `long`, `bool`, `char`

### Planned
- [ ] Code generation (x86-64 / bytecode)
- [ ] Pointer support (`*`, `&`)
- [ ] Control flow (`if`, `while`, `for`)
- [ ] Functions with return values
- [ ] Preprocessor (`#include`, `#define`)
- [ ] C++ mode (flag `-x`)

## Build & Installation

### Requirements
- C++20 compiler (g++/clang++)
- CMake (3.10+)
- Make

### Build

```bash
git clone https://github.com/Barkosss/scc.git
cd scc
mkdir build && cd build
cmake ..
make
```

After building, the `scc` executable will be in the `build/` directory.

## Usage

```bash
# Compile a C file
./scc program.c

# Compile with output name
./scc program.c -o myprogram

# Run the compiled program
./myprogram
```

### Flags (WIP)

| Command                      | Flag                 |
| ---------------------------- | -------------------- |
| `scc file.c`                 | Compile as C         |
| `scc -x file.cpp`            | Compile as C++       |

## Example

**Input `test.c`:**
```c
int main() {
    int x = 42;
    int y = x + 8;
    return y;
}
```

**Compile and run:**
```bash
./scc test.c -o test
./test
echo $?  # Outputs: 50
```

### Compilation Pipeline

```
Source Code -> Lexer -> Tokens -> Parser -> AST -> Code Generator -> Executable
```

## Project Goals

1. **Educational** — Understand how compilers work under the hood
2. **Practical** — Gain low-level programming experience in C++
3. **Portfolio** — Build a strong project for a C++ developer resume

## License

MIT License - freely use, modify, and distribute.

## Author

Andrey Baryshev
