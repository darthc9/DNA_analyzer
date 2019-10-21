#include "gtest/gtest.h"

// test function to check for legal nucleotide character
// this is not TDD - you already have this function!!!!!
#include "dna-sequence/nucleotide.h"
TEST(Simple_DNA_aequence, Nucleotide_isLegalLiteral){
EXPECT_TRUE(Nucleotide::isLegalLiteral('a'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('A'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('c'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('C'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('g'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('G'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('t'));
EXPECT_TRUE(Nucleotide::isLegalLiteral('T'));

EXPECT_FALSE(Nucleotide::isLegalLiteral('x'));
EXPECT_FALSE(Nucleotide::isLegalLiteral('Y'));
EXPECT_FALSE(Nucleotide::isLegalLiteral('z'));
}