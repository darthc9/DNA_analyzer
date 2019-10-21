//
// Created by Fadi on 11/09/2019.
//

#ifndef DNASEQUENCER_DNASEQUENCE_H
#define DNASEQUENCER_DNASEQUENCE_H

#include <cassert>
#include <string>
#include <iostream>
#include "mycstring.h"
#include "nucleotide.h"


class I_DNASequence {
public:
    // not adding constructors to interface

    virtual I_DNASequence& operator=(const I_DNASequence &rhs) = 0;
    virtual char operator[]( size_t pos) const; // TODO: add a non-const version that calls the const implementation.
    virtual size_t length() const;

    // no more functions needed at this point.
};



class DNASequence : public I_DNASequence {
public:

    static const size_t npos = -1;  // not a legal position - (default parameter required for copy ct'or)

    template <class T>
    DNASequence(const T& indexed_input, size_t start_pos = 0 , size_t nucleotide_count = npos);


    virtual ~DNASequence();

    I_DNASequence& operator=(const I_DNASequence &rhs) ;

    size_t length() const;

    char operator[]( size_t pos) const;

    void reverse();  // reverse the sequence
    void convert_to_paired(); // convert this sequence to the paired sequence

private:
    Nucleotide *m_DNA_sequence ;
    size_t      m_len;


private:

    friend std::istream& operator>>(std::istream& is, DNASequence& dnas_obj);

};

template <class T>
inline DNASequence::DNASequence (const T& indexed_input, size_t start_pos, size_t nucleotide_count) {

    if (npos == nucleotide_count) {
        // if no size supplied assume slice is the full length of the sequence
        nucleotide_count = m_len = indexed_input.length() ;
    } else {
        m_len = nucleotide_count ;
    }

    m_DNA_sequence = new Nucleotide[nucleotide_count] ;
    assert(start_pos + nucleotide_count <= indexed_input.length());

    try {
        for (size_t i = start_pos; i < nucleotide_count; ++i) {
            m_DNA_sequence[i] = indexed_input[i];
        }
    }
    catch ( bad_DNA_Sequence_Argument &) {
        delete[] m_DNA_sequence ;
        m_len = 0 ;
        throw ;
    }

}

class PCharInputStream {
public:
    PCharInputStream (const char * input) : m_data(input) {} ;
    virtual char operator[]( size_t pos) const { return  m_data[pos]; };
    virtual size_t length() const  { return strlen(m_data);}
private:
    const char * m_data;
};

// TODO: what about a file stream? can it return a length() or does it need an iterator?



// specialization of constructor template for T = char *
typedef char* pchar;
template <> DNASequence::DNASequence (const pchar& indexed_input, size_t start_pos, size_t nucleotide_count)
: DNASequence(PCharInputStream(indexed_input), start_pos, nucleotide_count)
{
    // delegating constructors is a C++11 feature
    // but I can't find a better solution to get rid of the code duplication.
}


inline DNASequence::~DNASequence()
{
    m_len = 0;
    delete[] m_DNA_sequence ;
    m_DNA_sequence = 0 ;
}


inline size_t DNASequence::length() const {
    return m_len ;
}


inline I_DNASequence& DNASequence::operator=(const I_DNASequence &rhs) {
    if (this != &rhs) {
        delete [] m_DNA_sequence;
        m_len = 0 ;
        m_len = rhs.length();
        m_DNA_sequence = new Nucleotide[m_len] ;
        for (size_t i = 0; i < m_len; ++i) {
            m_DNA_sequence[i] = rhs[i];
        }
    }
    return *this;
}


inline char DNASequence::operator[](size_t pos) const {
    return m_DNA_sequence[pos].getRepr();
}


inline void DNASequence::reverse(){
    size_t end_index = m_len - 1 ;
    size_t start_index = 0 ;

    while (start_index < end_index){
        m_DNA_sequence[start_index++].swap(m_DNA_sequence[end_index--]) ;
    }
}


// convert this sequence to the paired sequence
inline void DNASequence::convert_to_paired(){
    size_t index = 0;
    reverse();
    for (; index < length(); ++index){
        m_DNA_sequence[index].complement() ;
    }
}




inline std::ostream& operator<<(std::ostream& os, const DNASequence& dna_s)
{
    for (size_t i = 0; i < dna_s.length(); ++i) {
        os << dna_s[i] ;
    }
    return os;
}


// assume input starts with the length of the sequence !!!!
inline std::istream& operator>>(std::istream& is, DNASequence& dnas_obj)
{

    // read length of sequence first.
    size_t len = 0;
    if ( ! (is >> len) ) {
        std::cout << "input stream is in a bad state! Aborting!" << std::endl;  // TODO: throw exception
        return is;
    }

    // TODO: append or overwrite? chose the later.
    if (dnas_obj.m_len) {
        dnas_obj.m_len = 0 ;
        delete[] dnas_obj.m_DNA_sequence ;
        dnas_obj.m_DNA_sequence = 0 ; // nullptr
    }


    // read obj from stream
    if (len > 0) {
        size_t nucleo_index = 0 ;
        dnas_obj.m_len = len;
        dnas_obj.m_DNA_sequence = new Nucleotide[len];
        char input_char ;
        while ((is >> input_char) && (nucleo_index < len ) ) {
            if (isspace(input_char)) {
                continue ;
            }

            try {
                dnas_obj.m_DNA_sequence[nucleo_index++] = Nucleotide(input_char);
            } catch ( bad_DNA_Sequence_Argument &e) {
                dnas_obj.m_len = 0 ;
                delete[] dnas_obj.m_DNA_sequence ;
                dnas_obj.m_DNA_sequence = 0 ; // nullptr
                throw ;
            }
        }

    }
    return is;
}


inline bool operator==(const DNASequence &rhs, const DNASequence &lhs) {
    if (rhs.length() != lhs.length()) {
        return false;
    }
    for (size_t i = 0; i < rhs.length(); ++i) {
        if (rhs[i] != lhs[i]) return false;
    }
    return true ;
}

inline bool operator!=(const DNASequence &rhs, const DNASequence &lhs) {
    return !(lhs == rhs) ;
}






#endif //DNASEQUENCER_DNASEQUENCE_H
