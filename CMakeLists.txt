cmake_minimum_required(VERSION 3.16)
project(ProgLang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PARSER_DIR ${CMAKE_SOURCE_DIR}/parser)
set(VISITOR_DIR ${CMAKE_SOURCE_DIR}/visitor)
set(GRAPH_DIR ${CMAKE_SOURCE_DIR}/calltree)
set(ASM_DIR ${CMAKE_SOURCE_DIR}/lab3)


set(ANTLR_RUNTIME_ROOT /home/artem/antlr4)
set(ANTLR_RUNTIME_INCLUDE ${ANTLR_RUNTIME_ROOT}/runtime/src)
set(ANTLR_RUNTIME_LIB ${ANTLR_RUNTIME_ROOT}/dist/libantlr4-runtime.a)


set(SRC_FILES
${PARSER_DIR}/HelloLexer.cpp
${PARSER_DIR}/HelloParser.cpp
${PARSER_DIR}/HelloBaseVisitor.cpp
${PARSER_DIR}/HelloVisitor.cpp
${VISITOR_DIR}/HelloASTVisitor.cpp
${GRAPH_DIR}/Graph.cpp
${GRAPH_DIR}/CFGBuilder.cpp
${GRAPH_DIR}/CFGBuilder.cpp
${ASM_DIR}/Reg32CodeGenModule.cpp
main.cpp
)

add_executable(ProgLang ${SRC_FILES})

target_include_directories(ProgLang PRIVATE
${PARSER_DIR}
${VISITOR_DIR}
${ANTLR_RUNTIME_INCLUDE}
${GRAPH_DIR}
${ASM_DIR}
)

target_link_libraries(ProgLang PRIVATE
${ANTLR_RUNTIME_LIB}
pthread
dl
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(ProgLang PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_program(DOT_EXECUTABLE dot)

if(DOT_EXECUTABLE)
    if(EXISTS ${CMAKE_SOURCE_DIR}/dot_to_png.sh)

        file(COPY ${CMAKE_SOURCE_DIR}/dot_to_png.sh
             DESTINATION ${CMAKE_BINARY_DIR}
             FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)
        
        add_custom_command(TARGET ProgLangLab1 POST_BUILD
            COMMAND bash ${CMAKE_BINARY_DIR}/dot_to_png.sh
            COMMENT "Converting DOT files to PNG"
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
    else()
        message(WARNING "dot_to_png.sh not found in ${CMAKE_SOURCE_DIR}")
    endif()
else()
    message(WARNING "Graphviz dot not found. Install with: sudo apt install graphviz")
endif()
