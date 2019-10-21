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
    DNAAP.new_sequence(input_c_sequence, sequence_name);
}



// given a DNA_Sequence object (with name and ID) store it in database

// given a name and a sequence of chars create a DNA_Sequence object:
#include "dna-sequence/DNAsequence.h"
#include "decoratedDNAseq.h"
TEST(DNA_Analyzer_functionality, instantiate_dna_sequence_object)
{
    // move these into a fixture:
    size_t      dnas_test_ID   = 1 ;
    const char *dnas_test_name = "dna_sequence_test_name" ;
    const char *input_sequence = "ATACTGCCTGAATAC" ;            // this is a valid sequence - no exception.

    DNASequence dna_sequence(input_sequence);
    DNASequence_NameAndID_Decorator DNA_Analyzer_Decorated_Data_object ( dna_sequence, dnas_test_name, dnas_test_ID );
}
