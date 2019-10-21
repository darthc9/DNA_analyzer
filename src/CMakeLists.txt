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
        DNAAnalyzer/dna_analyzer_processor.h
        DNAAnalyzer/dna-sequence/nucleotide.h
        DNAAnalyzer/decoratedDNAseq.h)

set(Sources
        DNAAnalyzer/DNAAnalyzer_CLI.cpp
        DNAAnalyzer/dnaa_command_parser.cpp
        DNAAnalyzer/dna_analyzer_processor.cpp
        DNAAnalyzer/dna-sequence/nucleotide.cpp
        DNAAnalyzer/decoratedDNAseq.cpp)

add_library(${this} STATIC ${Sources} ${Headers})

add_subdirectory(tests)





