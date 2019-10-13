//
// Created by Fadi on 14/09/2019.
//

#ifndef DNASEQUENCER_NUCLEOTIDE_H
#define DNASEQUENCER_NUCLEOTIDE_H

#include <stdexcept>
#include <string>
#include <cctype>

class bad_DNA_Seqeunce_Argument: public std::invalid_argument {
public:
    bad_DNA_Seqeunce_Argument(const std::string& msg): std::invalid_argument(msg) {}
    // TODO: TDB
};



// basic building block of a DNA sequence:
class Nucleotide {
public:
    typedef unsigned char dnal_t;
    typedef char reg_t;

    // legal DNA literals in a DNA sequence consist of:
    static const dnal_t DNA_A = 0 ;
    static const dnal_t DNA_C = 1 ;
    static const dnal_t DNA_G = 2 ;
    static const dnal_t DNA_T = 3 ;
    // to translate above enumeration to printable chars:
    static const char BITS[];
    static const short LUNM;   // number of different DNA literals. (4)

public:
    static bool isLegalLiteral(char dna_l);

public:
    Nucleotide(char literal = 'A');
    char getRepr() const; // returns the char representation
    void swap(Nucleotide &other); // to facilitate dna_sequence::reverse()

    void complement();            // translate this Nucleotide to the complementary Nucleotide in the sequence.
                                  // using this instead of assigning value with copy c'tor or with the missing assignment operator.

private:
    reg_t m_DNA_literal;
};


inline bool Nucleotide::isLegalLiteral(char dna_l){
    char upper_l = static_cast<char>(toupper(dna_l));  //TODO: implement your own toupper()
    for (short i = 0 ; i < LUNM ; ++i) {
        if (upper_l == BITS[i]) return true;
    }
    return false;
}

inline Nucleotide::Nucleotide(char literal ){
    m_DNA_literal = static_cast<char>(toupper(literal));  //TODO: implement your own toupper()
    if (!isLegalLiteral(m_DNA_literal)) {
        throw bad_DNA_Seqeunce_Argument(std::string("invalid Nucleotide literal: ") + m_DNA_literal);
    }
}

// returns the char representation
inline char Nucleotide::getRepr() const {
    return m_DNA_literal ;
}

inline void Nucleotide::swap(Nucleotide &other){
    reg_t temp_c = m_DNA_literal ;
    m_DNA_literal = other.m_DNA_literal ;
    other.m_DNA_literal = temp_c ;
}


inline void  Nucleotide::complement(){
    switch(m_DNA_literal) {
        case 'a':
        case 'A':
            m_DNA_literal = 'T';
            break;
        case 'c':
        case 'C':
            m_DNA_literal = 'G' ;
            break ;
        case 'G':
        case 'g':
            m_DNA_literal = 'C' ;
            break;
        case 'T':
        case 't':
            m_DNA_literal = 'A' ;
            break;
    }

}


inline bool operator==(const Nucleotide &rhs, const Nucleotide &lhs) {
    return rhs.getRepr() == lhs.getRepr() ;
}



#endif //DNASEQUENCER_NUCLEOTIDE_H
