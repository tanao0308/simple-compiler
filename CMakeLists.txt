cmake_minimum_required(VERSION 3.16)
project(simple_compiler LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# bison
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/sc.tab.hpp ${CMAKE_BINARY_DIR}/sc.tab.cpp
    COMMAND bison -d ${CMAKE_SOURCE_DIR}/parser/sc.ypp
    DEPENDS ${CMAKE_SOURCE_DIR}/parser/sc.ypp
)

# flex
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/sc.yy.cpp
    COMMAND flex -o sc.yy.cpp ${CMAKE_SOURCE_DIR}/parser/sc.l
    DEPENDS ${CMAKE_SOURCE_DIR}/parser/sc.l
)

# 动态匹配收集文件。GLOB_RECURSE表示递归收集，AST_SOURCES表示收集到的文件集合的名字
file(GLOB_RECURSE AST_SOURCES
    src/*.cpp
)

# 静态收集文件。将所有源文件装入SOURCES
set(SOURCES
    main.cpp
    ${AST_SOURCES} # ast源码
    ${CMAKE_BINARY_DIR}/sc.tab.cpp # bison源码
    ${CMAKE_BINARY_DIR}/sc.yy.cpp # flex源码
)

# 创建可执行文件
add_executable(sc ${SOURCES})

# target_include_directories() 用于指定编译器在寻找头文件（#include 指令）时应该搜索哪些目录
target_include_directories(sc PRIVATE # PRIVATE - 仅当前目标使用
    ${CMAKE_SOURCE_DIR}/include # CMAKE_SOURCE_DIR 是 CMake 内置变量，指向顶级 CMakeLists.txt 所在的目录（项目根目录）
    ${CMAKE_BINARY_DIR} # CMAKE_BINARY_DIR 是构建目录，通常是通过 cmake -B build 指定的目录
)

# 确认 Cmake 根目录位置
# message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")

# Warnings
target_compile_options(sc PRIVATE
    -Wall -Wextra
)
