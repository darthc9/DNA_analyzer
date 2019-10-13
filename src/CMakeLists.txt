cmake_minimum_required(VERSION 3.12)
project(dna_analyzer)

set(this DNAAnalyzer)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()
add_subdirectory(googletest)

#include_directories(DNAAnalyzer)

set (Headers
        DNAAnalyzer/dnaa_command_parser.h
        )
set(Sources
        DNAAnalyzer/DNAAnalyzer_CLI.cpp
        DNAAnalyzer/dnaa_command_parser.cpp
        DNAAnalyzer/dna_analyzer_processor.cpp DNAAnalyzer/dna_analyzer_processor.h)

add_library(${this} STATIC ${Sources} ${Headers})

add_subdirectory(tests)





