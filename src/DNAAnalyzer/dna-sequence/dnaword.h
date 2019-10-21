//
// Created by Fadi on 14/09/2019.
//

#ifndef DNASEQUENCER_DNAWORD_H
#define DNASEQUENCER_DNAWORD_H


#if 0
// Translate DNA char literal to2bits representation:
inline unsigned char DNA_char_to2bit(char DNA_Literal){

    switch (DNA_Literal){
        case 'A':
        case 'a':
            return DNA_A ;
        case 'C':
        case 'c':
            return DNA_C ;
        case 'G':
        case 'g':
            return DNA_G ;
        case 'T':
        case 't':
            return DNA_T ;
        default:
            throw bad_DNA_Seqeunce_Argument("invalid DNA literal encountered") ;
    }

}


typedef unsigned char dnar_t;

// Translate 2bit register to DNA char literal:
inline char dnas_twobits2char(dnar_t twobit_register){
    assert(twobit_register < 4 );
    return BITS[twobit_register];
}


inline dnar_t shift_2_left(dnar_t reg){
    return static_cast<dnar_t>(reg << 2) ;
}

// compress four 2-bit registers into a single one byte register:
inline dnar_t compress_2bit_registers(dnar_t first, dnar_t second, dnar_t third, dnar_t fourth){
    dnar_t byte_register = 0 ;
    byte_register |= first ;
    byte_register = shift_2_left(byte_register);
    byte_register |= second ;
    byte_register = shift_2_left(byte_register);
    byte_register |= third ;
    byte_register = shift_2_left(byte_register);
    byte_register |= fourth ;
    return byte_register ;
}

#endif


#endif //DNASEQUENCER_DNAWORD_H
