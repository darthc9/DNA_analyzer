//
// Created by Fadi on 12/09/2019.
//

#include "test_dna_sequence.h"
#include "DNAsequence.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>  // TODO: replace with Gtest.


int test_dnas_copy_ctr();
int test_dnas_output_tocout() ;
int test_dnas_at_operator() ;
int test_dnas_read_from_input_stream();
int test_dnas_reverse() ;
int test_convert_to_paired() ;

int test_dna_sequencer()
{
    test_dnas_copy_ctr() ;
    test_dnas_output_tocout() ;
    test_dnas_at_operator() ;
    test_dnas_read_from_input_stream();
    test_dnas_reverse() ;
    test_convert_to_paired();

    std::cout << "All tests passed! you are awesome!" << std::endl;
    return 0;
}


int test_convert_to_paired() {
    const char *TEST_INPUT_STR = "GTGC";
    const char *PAIR_INPUT_STR = "GCAC";  // reverse
    {
        DNASequence dnas1(TEST_INPUT_STR);
        std::cout << dnas1 ;
        DNASequence dnas2(PAIR_INPUT_STR);
        dnas1.convert_to_paired() ;
        std::cout << " is paired to " << dnas1 << std::endl;

        assert(dnas1 == dnas2);
    }

    return 0;

}


int test_dnas_reverse() {
    const char *TEST_INPUT_STR = "TAATGCCCGGTTTATGCGTCGAAA";
    const char *REVR_INPUT_STR = "AAAGCTGCGTATTTGGCCCGTAAT";  // reverse
    {
        DNASequence dnas1(TEST_INPUT_STR);
        DNASequence dnas2(REVR_INPUT_STR);
        dnas1.reverse() ;
        assert(dnas1 == dnas2);
    }

    return 0;
}


int test_dnas_read_from_input_stream()
{
    std::istringstream s_stream1;
    // assuming size is supplied to reader function, here is a seqeunce of size 24:
    std::string string_t = "24 \nTAATGCCCGGTTTATGCGTCGAAA";
    s_stream1.str(string_t);
    DNASequence seq("");  // empty sequence possible?
    s_stream1 >> seq ;


    std::ostringstream ss_out;
    ss_out << seq ;
    std::cout << "read from inputstream:" << ss_out.str().c_str() << std::endl;
    assert ( 0 == strcmp("TAATGCCCGGTTTATGCGTCGAAA", ss_out.str().c_str())  ) ;
    return 0;
}


int test_dnas_copy_ctr()
{
    const char *TEST_INPUT_STR = "TAATGCCCGGTTTATGCGTCGAAA" ;
    const std::string dna_strn(TEST_INPUT_STR) ;
    {
        std::string output;

        DNASequence dnas1 = TEST_INPUT_STR;
        DNASequence dnas2(TEST_INPUT_STR);
        DNASequence dnas3(dnas2);
        dnas2 = dnas3;
        dnas2 = TEST_INPUT_STR ;

        std::ostringstream ss_out;
        ss_out << dnas3 ;
        assert ( 0 == strcmp(TEST_INPUT_STR, ss_out.str().c_str())  ) ;
        assert( dnas1 == dnas2) ;
    }


    // test slicing
    {
        std::string output;

        DNASequence dnas1 = TEST_INPUT_STR;
        // TAA.TGCCC.GGTTTATGCGTCGAAA
        DNASequence dnas2(dnas1, 3, 5 );

        std::ostringstream ss_out;
        ss_out << dnas2 ;
        assert ( 0 == strcmp("TGCCC", ss_out.str().c_str())  ) ;
    }


    return 0;
}



int test_dnas_output_tocout() {

    const char *TEST_INPUT_STR = "TAATGCCCGGTTTATGCGTCGAAA";

    {
        DNASequence dnas1 = TEST_INPUT_STR;
        std::cout << "the test DNA string is: " << dnas1 << std::endl;
    }

    return 0;
}



int test_dnas_at_operator() {

    const char *TEST_INPUT_STR = "TAATGCCCGGTTTATGCGTCGAAA";

    std::cout << "\nTesting op[] .." << std::endl ;
    {
        DNASequence dnas1 = TEST_INPUT_STR;
        int i = 0 ;
        while(TEST_INPUT_STR[i]) {
            assert(TEST_INPUT_STR[i] == dnas1[i]) ;
            ++i;
        }

    }

    return 0;
}
