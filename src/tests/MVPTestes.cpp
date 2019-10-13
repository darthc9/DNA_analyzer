#include "gtest/gtest.h"



// TEST( test_case_name, test_name )


TEST(ExampleTest, Demonstrate_a_simple_test) {
    EXPECT_TRUE(true);
}


/**** Scenario to test / implement:
 *
 *  ADD A NEW SEQUENCE TO DNA_ANALYZER DATABASE:
 *  - CREATE ANALYZER DATABASE
 *  - ADD NEW INTERFACE WITH "NEW COMMAND" TO ANALYZER
 *  - MOCK CLI CALL TO INTERFACE
 *
 */


#include "dna_analyzer_processor.h"

TEST(DNA_Analyzer_Interface, analyzer_instantiation){

    DNAAnalyzerProcessor DNAAP ;  // instantiate a command processor object
}


TEST(DNA_Analyzer_Interface, analyzer_new_command_interface){
    DNAAnalyzerProcessor DNAAP ;  // instantiate a command processor object
    const char *input_c_sequence = "ATACTGCCTGAATAC" ;  // can only have A,C,G,T
    const char *sequence_name    = "test_sequence_1" ;
    DNAAP.new_sequence(input_c_sequence, sequence_name);  // HOW DO YOU TEST THIS FUNCTION?
}

