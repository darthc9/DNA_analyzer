#ifndef DNA_ANALYZER_DECORATEDDNASEQ_H
#define DNA_ANALYZER_DECORATEDDNASEQ_H

#include "dna-sequence/DNAsequence.h"

class DNASequence_NameAndID_Decorator : public I_DNASequence {
public:
    DNASequence_NameAndID_Decorator(DNASequence& sequence, const std::string& name_label, size_t numeric_id);
    virtual I_DNASequence &operator=(const I_DNASequence &rhs);

    virtual char operator[](size_t pos) const;

    virtual size_t length() const;

private:
    I_DNASequence& m_DNAseq ;
    std::string    m_namestr;
    size_t         m_ID;



};


inline DNASequence_NameAndID_Decorator::DNASequence_NameAndID_Decorator
(DNASequence& sequence, const std::string& name_label, size_t numeric_id)
: m_DNAseq(sequence), m_namestr(name_label), m_ID(numeric_id)
{

}

I_DNASequence &DNASequence_NameAndID_Decorator::operator=(const I_DNASequence &rhs) {
    return m_DNAseq = rhs;
}

char DNASequence_NameAndID_Decorator::operator[](size_t pos) const {
    return m_DNAseq[pos];
}

size_t DNASequence_NameAndID_Decorator::length() const {
    return m_DNAseq.length();
}


#endif //DNA_ANALYZER_DECORATEDDNASEQ_H
