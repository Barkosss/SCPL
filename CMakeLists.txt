cmake_minimum_required(VERSION 3.31.5)
project(scc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(scc
        src/lexer/lexer.cpp
        src/parser/parser.cpp
        src/main.cpp)

set_target_properties(scc PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
