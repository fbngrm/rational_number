#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include <rationalnumber.h>

// hidden implementation of RationalNumberArray
struct RationalNumberArray;

// declare type ErrorHandler as function pointer
typedef void (*ErrorHandler)(RationalNumberArray*);

// create a RationalNumberArray with the given size 'capacity'
RationalNumberArray* rnaCreate(unsigned int capacity);

// release the memory of RationalNumberArray 'rna'
void rnaDelete(RationalNumberArray* rna);

// resize the memory allocated for RationalNumberArray 'rna' to 'capacity'
// return RationalNumberArray.size
void rnaResize(RationalNumberArray* rna, unsigned int const capacity);

// return the amount of RationalNumbers in the RationalNumberArray 'rna'
unsigned int rnaSize(const RationalNumberArray* rna);

// return the free memory in the RationalNumberArray 'rna' capacity
unsigned int rnaCapacity(const RationalNumberArray *rna);

// add RationalNumber 'rn' to the RationalNumberArray 'rna', enlarge the RNA if it is neccessary with parameter resize
void rnaAdd(RationalNumberArray* rna, const RationalNumber rn, const unsigned int resize);

// set the element at position 'index' in RationalNumberArray 'rna' to the value of RationalNumber 'rn',
// enlarge the RNA if it is neccessary with resize value and initialize all non-initialized elements with RationalNumber { 0, 1 }
void rnaSet(RationalNumberArray* rna, const RationalNumber rn, const unsigned int index, const unsigned int resize);

// return the element of RationalNumberArray 'rna' at position 'index'
RationalNumber rnaGet(RationalNumberArray *rna, const unsigned int index);

// remove an amount of elements of RationalNumberArray 'rna', begin at position 'start' end at position 'end' (excluded)
// return the amount of deleted elements
void rnaRemove(RationalNumberArray* rna, const unsigned int start, const unsigned int end);

// return the error code of RationalNumberArray 'rna'
// error codes are defined in rnaErrorCodes enum
int rnaError(const RationalNumberArray* rna);

// set a callback function in RationalNumberArray 'rna'
void rnaSetErrorCallback(RationalNumberArray* rna, const ErrorHandler handler);

// error handler function
void catchOutOfMemory(RationalNumberArray* rna);

// error handler function
void catchInvalidIndex(RationalNumberArray* rna);

// error handler function
void catchInvalidArray(RationalNumberArray* rna);

// error handler function
void rnaHandleError(RationalNumberArray *rna);


#endif // RATIONALNUMBERARRAY_H
