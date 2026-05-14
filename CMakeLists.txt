cmake_minimum_required(VERSION 3.31.5)
project(SCPL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(SCPL
        src/lexer/lexer.cpp
        src/main.cpp)

set_target_properties(SCPL PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
