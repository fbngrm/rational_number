
/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include "rationalnumber.h"
#include "rationalnumberarray.h"


int main()
{

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );
    assert( rnIsNaN(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );
    assert( rnLessThan( n5,n4) );
    assert( !rnLessThan( n3,n5) );
    assert( !rnLessThan( n4,n5) );
    assert( !rnLessThan( nn,nn) );
    assert( !rnLessThan( n0,n0) );
    assert( !rnLessThan( n4,n0) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);
    RationalNumber t5 = rnDivide(nn,n2);

    assert( !rnIsValid(t5) );

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( rnIsNaN(t4) );

    printf("RationalNumber test successful!\n");

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    printf("Performing unit tests for RationalNumberArray...\n\n");

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 1
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 2 - RUDIMENTARY
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // next test
    printf("TESTING PARAMETER: %12u\n", 10);
    rna = rnaCreate(10);
    assert( rnaCapacity(rna) != 0 );
    assert( rnaSize(rna) != 10 );
    assert( rnaCapacity(rna) == 10);
    assert( rnaSize(rna) == 0 );
    assert( ! rnaError(rna) > 0 );
    assert( rnaError(rna) == 0 );
    rnaDelete(rna);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 3 - RUDIMENTARY
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // next test
    printf("TESTING PARAMETER: %12u\n", 100);
    rna = rnaCreate(100);
    assert( rnaCapacity(rna) != 0 );
    assert( rnaSize(rna) != 100 );
    assert( rnaCapacity(rna) == 100);
    assert( rnaSize(rna) == 0 );
    assert( ! rnaError(rna) > 0 );
    assert( rnaError(rna) == 0 );
    rnaDelete(rna);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 4 - RUDIMENTARY
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // next test
    printf("TESTING PARAMETER: %12u\n", 10000);
    rna = rnaCreate(10000);
    assert( rnaCapacity(rna) != 0 );
    assert( rnaSize(rna) != 10000 );
    assert( rnaCapacity(rna) == 10000);
    assert( rnaSize(rna) == 0 );
    assert( ! rnaError(rna) > 0 );
    assert( rnaError(rna) == 0 );
    rnaDelete(rna);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 5 - RUDIMENTARY
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // next test
    printf("TESTING PARAMETER: %12u\n", 1000000);
    rna = rnaCreate(1000000);
    assert( rnaCapacity(rna) != 0 );
    assert( rnaSize(rna) != 1000000 );
    assert( rnaCapacity(rna) == 1000000);
    assert( rnaSize(rna) == 0 );
    assert( ! rnaError(rna) > 0 );
    assert( rnaError(rna) == 0 );
    rnaDelete(rna);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TEST 6 - RUDIMENTARY
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // next test
    printf("TESTING PARAMETER: %12u\n", 10000000);
    rna = r
