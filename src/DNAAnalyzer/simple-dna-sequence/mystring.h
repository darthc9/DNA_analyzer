//
// Created by Fadi on 05/09/2019.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

#include <ostream>
#include <exception>
#include "mycstring.h"

namespace my_string
{
typedef unsigned long size_t;


class string {
public:
    static const size_t npos = -1;  // not a legal position - (default parameter needed)
    string(const char *c_str = ""): m_len(strlen(c_str)) {
        m_cstr = deep_str_copy(c_str, 0, m_len);
        m_cstr[m_len] = '\0';
    }

    string(string const& other, size_t start_pos = 0, size_t chr_count = npos)
    {
        // TODO: error/boundary checking.
        if (npos == chr_count){
            chr_count = m_len = other.m_len ;
        } else {
            m_len = chr_count;
        }
        m_cstr =  deep_str_copy(other.m_cstr, start_pos,chr_count);
        m_cstr[m_len] = '\0' ; // make sure it is null terminated
    }


    ~string() {
        delete[] m_cstr;
        m_cstr = 0 ;       // is this really needed?
    }

    bool empty() const { return m_len == 0 ;}
    size_t length() const { return m_len ; }
    const char *get_c_str() const { return m_cstr; }

    string& operator=(const string &rhs) {
        if (this != &rhs) {
            delete [] m_cstr;
            m_len = 0 ;
            m_cstr = deep_str_copy(rhs.get_c_str(),0, rhs.length());
            m_len = rhs.length() ;
        }
        return *this;
    }

    const char& operator[]( size_t pos) const { return m_cstr[pos]; }
    const char& at( size_t pos) const {  // TODO: declare specific exception type? how?
        if (pos > m_len) {
            throw(err_out_of_bounds()) ;
        }
        return m_cstr[pos];
    }

    string& operator+=(const string& other_str){
        size_t new_str_len = m_len + other_str.m_len;
        char *new_cstr = deep_str_copy(m_cstr,0,new_str_len) ;
        strncpy(new_cstr + m_len, other_str.m_cstr, other_str.m_len);
        delete[] m_cstr ;
        m_cstr = new_cstr ;
        m_len  = new_str_len;
        return *this;
    }


private:
    size_t m_len;
    char * m_cstr;

public:
    // exception objects definitions:
    class err_out_of_bounds: public std::invalid_argument{
    public:
        const char * what () const throw () {
        return "out of bounds string exception";
        }
        explicit err_out_of_bounds(const char* message="out of bounds string operand"):
            invalid_argument(message)
        {}
    };
};


inline std::ostream& operator<<(std::ostream& os, const string& str){
    os << str.get_c_str() ;
    return os;
}

inline bool operator==(const string &rhs, const string &lhs) {
    return 0 == strcmp(rhs.get_c_str(), lhs.get_c_str()) ;
}

inline bool operator!=(const string &rhs, const string &lhs)  {
    return !(rhs == lhs) ;
}

inline bool operator<(const string &rhs, const string &lhs) {
    return strcmp(rhs.get_c_str(), lhs.get_c_str()) < 0 ;
}

inline bool operator>(const string &rhs, const string &lhs) {
    return lhs < rhs ;
}

inline bool operator<=(const string &rhs, const string &lhs) {
    return strcmp(rhs.get_c_str(), lhs.get_c_str()) <= 0 ;
}

inline bool operator>=(const string &rhs, const string &lhs) {
    return lhs <= rhs ;
}



} //my_string namespace


#endif //MYSTRING_MYSTRING_H
