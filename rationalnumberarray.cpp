#include <stdlib.h>
#include <stdio.h>
#include "rationalnumberarray.h"
#include "rationalnumber.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// RATIONAL-NUMBER-ARRAY DECLARATIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct RationalNumberArray {

    // poninter to an array of RationalNumbers
    RationalNumber* data;
    // amount of elements in the array
    unsigned int size;
    // allocated memory
    unsigned int capacity;
    // error state
    unsigned int error_state;
    // error callback function
    ErrorHandler error_handler;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum Errors {
    VALID,
    INVALID_ARRAY_OBJECT,
    INVALID_INDEX,
    OUT_OF_MEMORY
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// RATIONAL-NUMBER-ARRAY CONSTRUCTOR
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// create a RationalNumberArray with the given size 'capacity'
RationalNumberArray* rnaCreate( unsigned int capacity){

    // allaocate memory on the heap for RationalNumberArray
    RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));
    // allaocate memory on the heap for RationalNumbers
    RationalNumber* data = (RationalNumber*) malloc(capacity * sizeof(RationalNumber));

    if(!data || ! rna){
        rna->data = 0;
        rna->capacity = 0;
        rna->size = 0;
        rna->error_state = OUT_OF_MEMORY;
        rna->error_handler = NULL;
    } else {
        rna->data = data;
        rna->capacity = capacity;
        rna->size = 0;
        rna->error_state = VALID;
        rna->error_handler = NULL;
    }
    return rna;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// RATIONAL-NUMBER-ARRAY OPERATIONS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// release the memory of RationalNumberArray 'rna'
void rnaDelete(RationalNumberArray* rna){
    free(rna);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// resize the memory allocated for RationalNumberArray 'rna' to 'capacity'
void rnaResize(RationalNumberArray* rna, const unsigned int capacity){
    // allocate memory
    RationalNumber* newdata = (RationalNumber*) realloc (rna->data, capacity * sizeof(RationalNumber));

    // validate newdata
    if(!newdata){
        rna->error_state = OUT_OF_MEMORY;
    } else {
        // resize
        rna->data = newdata;
        rna->capacity = capacity;
        rna->size = capacity > rna->size ? rna->size : capacity;
        rna->error_state = VALID;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// return the amount of RationalNumbers in the RationalNumberArray 'rna'
unsigned int rnaSize(const RationalNumberArray *rna){
    // validate param rna
    return (!rna) ? 0 : rna->size;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// return the capacity of RationalNumberArray 'rna' capacity
unsigned int rnaCapacity(const RationalNumberArray* rna){
    // validate param rna
    return (!rna) ? 0 : rna->capacity;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// add RationalNumber 'rn' to the RationalNumberArray 'rna', enlarge the RNA if it is neccessary
void rnaAdd(RationalNumberArray* rna, const RationalNumber rn, const unsigned int resize){
    // resize if neccessary
    if(rna->capacity == rna->size){
        // if resize parameter is 0 return with error - invalid index
        if(resize == 0){
            rna->error_state = INVALID_INDEX;
        } else {
            rnaResize(rna, rna->capacity + resize);
        }
    }
    if(rna->capacity > rna->size){
        rna->data[rna->size] = rn;
        rna->size++;
        rna->error_state = VALID;
    } else {
        // resize failed
        rna->error_state = OUT_OF_MEMORY;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// set the element at position 'index' in RationalNumberArray 'rna' to the value of RationalNumber 'rn',
// enlarge the RNA if it is neccessary and initialize all non-initialized elements with RationalNumber { 0, 1 }
void rnaSet(RationalNumberArray* rna, const RationalNumber rn, const unsigned int index, const unsigned int resize){
    // resize if neccessery
    if(index >= rna->capacity){
        // resize
        rnaResize(rna, index + resize);

        // fill with RN { 0, 1 } and increment size
        // NOTE: only elements with position < index of 'rn' are initialized by {0, 1} !!
        for(unsigned int i=rna->size; i<index; i++){
            RationalNumber rn0 = { 0, 1 };
            rna->data[i] = rn0;
            rna->size++;
        }
        // set 'rn' at position 'index' in 'rna', increment size
        rna->data[index] = rn;
        rna->size++;
    } else {
        // set 'rn' at position 'index' in 'rna'
        rna->data[index] = rn;
        rna->error_state = VALID;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// return the element of RationalNumberArray 'rna' at position 'index'
RationalNumber rnaGet(RationalNumberArray *rna, const unsigned int index){
    if(index >= rna->capacity || index >= rna->size){
        RationalNumber r = {
            0, 1
        };
        rna->error_state = INVALID_INDEX;
        return r;
    }
    rna->error_state = VALID;
    return rna->data[index];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// remove an amount of elements of RationalNumberArray 'rna', begin at position 'start'(included) end at position 'end' (excluded)
void rnaRemove(RationalNumberArray* rna, const unsigned int start, const unsigned int end){
    unsigned int new_index = start;
    unsigned int index     = end;
    for (;index < rna->capacity; index++){
        rna->data[new_index++] = rna->data[index];
    }
    rnaResize(rna, rna->capacity - (end - start));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ERROR HANDLING
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// return the error code of RationalNumberArray 'rna'
// error codes are defined in Errors enum
int rnaError(const RationalNumberArray *rna){
    return rna->error_state;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// error handler function
void catchOutOfMemory(RationalNumberArray* rna){
    printf("out of memory!\n");
    // to do:
    // appropriate error handling
    rna->error_state = VALID;
    printf("error adjusted!\n\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// error handler function
void catchInvalidIndex(RationalNumberArray* rna){
    printf("invalid index!\n");
    // to do:
    // appropriate error handling
    rna->error_state = VALID;
    printf("error adjusted!\n\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// error handler function
void catchInvalidArray(RationalNumberArray* rna){
    printf("invalid array!\n");
    // to do:
    // appropriate error handling
    rna->error_state = VALID;
    printf("error adjusted!\n\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// error handler function
void rnaHandleError(RationalNumberArray* rna){
    if(rna->error_state != 0){
        rna->error_handler(rna);
    } else {
        printf("no errors occured!\n\n");
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// set a callback function in RationalNumberArray 'rna'
void rnaSetErrorCallback(RationalNumberArray* rna, const ErrorHandler handler){
    rna->error_handler = handler;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

