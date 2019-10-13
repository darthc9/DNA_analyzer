cmake_minimum_required(VERSION 3.12)
#project(dna_analyzer)

set(this DNAAnalyzerTests)

set(Sources
        MVPTestes.cpp
        )

include_directories(../DNAAnalyzer)

add_executable(${this} ${Sources})

target_link_libraries(${this} PUBLIC
        gtest
        gtest_main
        DNAAnalyzer
        )

add_test(
        NAME ${this}
        COMMAND ${this}
)



