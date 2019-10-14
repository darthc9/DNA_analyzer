#ifndef DNA_ANALYZER_DNA_ANALYZER_PROCESSOR_H
#define DNA_ANALYZER_DNA_ANALYZER_PROCESSOR_H

// the main class that holds all the processing and data storing functionality:
class DNAAnalyzerProcessor{
public:
    DNAAnalyzerProcessor() {}

    // add a new DNA_sequence to database, name must be provided.
    // function fails (with an exception) if name is already taken or
    // sequence is not a valid DNA representation.
    void new_sequence(const char *sequence, const char *name);
};






inline void DNAAnalyzerProcessor::new_sequence(const char *sequence, const char *name) {
    throw "NOT YET IMPLEMENTED";

    // this method must
    //
    // 2. validate that name is not in database
    // 3. create a DNA_Sequence object (also does validate that sequence is a valid DNA representation)
    // 4. assign it an integer ID
    // 5. store new object in database with name and id and..
    // 6. return the id of the new sequence to the caller. (so they can print it)
}




#endif //DNA_ANALYZER_DNA_ANALYZER_PROCESSOR_H
