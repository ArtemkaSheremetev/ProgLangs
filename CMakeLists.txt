cmake_minimum_required(VERSION 3.16)
project(ProgLangLab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Пути к папкам проекта ===

set(PARSER_DIR ${CMAKE_SOURCE_DIR}/parser)
set(VISITOR_DIR ${CMAKE_SOURCE_DIR}/visitor)
set(GRAPH_DIR ${CMAKE_SOURCE_DIR}/calltree)

# === Путь к локальной сборке ANTLR runtime ===

set(ANTLR_RUNTIME_ROOT /home/artem/antlr4)
set(ANTLR_RUNTIME_INCLUDE ${ANTLR_RUNTIME_ROOT}/runtime/src)
set(ANTLR_RUNTIME_LIB ${ANTLR_RUNTIME_ROOT}/dist/libantlr4-runtime.a)

# === Список исходников ===

set(SRC_FILES
${PARSER_DIR}/HelloLexer.cpp
${PARSER_DIR}/HelloParser.cpp
${PARSER_DIR}/HelloBaseVisitor.cpp
${PARSER_DIR}/HelloVisitor.cpp
${VISITOR_DIR}/HelloASTVisitor.cpp
${GRAPH_DIR}/Graph.cpp
${GRAPH_DIR}/CFGBuilder.cpp
main.cpp
)

# === Создание исполняемого файла ===

add_executable(ProgLangLab1 ${SRC_FILES})

# === Пути к заголовкам ===

target_include_directories(ProgLangLab1 PRIVATE
${PARSER_DIR}
${VISITOR_DIR}
${ANTLR_RUNTIME_INCLUDE}
${GRAPH_DIR}
)

# === Линковка с локальной библиотекой ANTLR runtime ===

target_link_libraries(ProgLangLab1 PRIVATE
${ANTLR_RUNTIME_LIB}
pthread
dl
)

# === Опциональные флаги ===

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(ProgLangLab1 PRIVATE -Wall -Wextra -Wpedantic)
endif()
