# C++ DNA Sequence.


### Changelist (Done):

added reverse() and convert_to_paired()

add reading from input stream

added copy constructor for slicing

<br><br><hr />
### TODO:
add googletest

maybe add getSlice(start,end)? but what should it return? 
want to avoid gratuitous calls to copy constructors.

boundary check slicing


add reading from file (extends input stream)
+ can sequence size at the end of the file
+ maybe OS can supply file size (and hence sequence size estimate)
+ have function throw exception on failure
+ should free allocated array on failure.
+ what happens to old array when reading into it? deleted?

    



find() -- subsequence within a sequence

find() -- improve complexity.

count() -- number of occurrences of sub sequence

findall() -- should return a list

find_consensus() -- start-codon up to an end-codon


Advanced:
- compress sequence to 2 bits per literal (overload [])
- add iterators (reverse iterator as well)
- use chars A,C,G,T instead of enum for op[] return value