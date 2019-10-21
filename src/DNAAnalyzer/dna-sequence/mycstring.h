//
// Created by fadi on 9/7/19.
//

#ifndef C_CLASS_STRING_DARTHC9_MYCSTRING_H
#define C_CLASS_STRING_DARTHC9_MYCSTRING_H

template<typename T>
inline const T& getMin(const T& a, const T&b) {
    return (a < b)? a:b;
}

inline int strcmp(const char *first,const char *second){
    while(*first && *second && *first == *second){
        ++first;
        ++second;
    }
    return *first - *second ;
}

// Copies the first num characters of source to destination.
// If the end of the source C string (which is signaled by a null-character) is found before num
// characters have been copied, destination is padded with zeros
// until a total of num characters have been written to it.
inline char *strncpy(char *dest, const char *source, unsigned long n){
    while (n && *source){
        *dest = *source ;
        ++dest;
        ++source;
        --n;
    }

    if (!*source) {
        *dest = '\0' ;
    }

    while (n--) {
       *dest++ = 0;
    }

    return dest;
}

inline unsigned long strlen(const char *cstr) {
    unsigned long chrCount = 0;
    while (*cstr++) ++chrCount;
    return chrCount;
}

// helper function to copy C string. will perform deep copy -
// it will allocate new memory according to given length and copy source string to it.
// c_str_source - the string to be copied to the new location
// start_pos    - 0 to start copying from the start of c_str_source
// chr_count    - the length of the string (function will not check or calculate it.)
inline char *deep_str_copy(const char *c_str_source, unsigned long start_pos, unsigned long chr_count){
    char *new_cstr = new char[chr_count + 1];
    strncpy(new_cstr, c_str_source + start_pos, chr_count);
    return new_cstr;
}



#endif //C_CLASS_STRING_DARTHC9_MYCSTRING_H
