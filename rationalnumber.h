#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

// define struct RationalNumber
struct RationalNumber {

    // define nominator as short int
    //( value between -32768 and 32767 on intel i3 - 64 bit)
    signed short int nomi;

    // define denominator as short int
    //( value between -32768 and 32767 on intel i3 - 64 bit)
    signed short int deno;
};

/*
 * define function rnIsValid
 * this function validates wether the the parameter n is a valid rational-number.
 * if not (denominator is zero), return false
 */
bool rnIsValid(RationalNumber n);

/*
 * define function rnIsNaN
 * return true if the parameter is not a valid rational-number
 */
bool rnIsNaN(RationalNumber n);

/*
 * define function rnEqual
 * return true if n1 == n2
 */
bool rnEqual(RationalNumber n1, RationalNumber n2);

/*
 * define function rnLessThan
 * return true if n1 < n2
 */
bool rnLessThan(RationalNumber n1, RationalNumber n2);

/*
 * define function rnAdd
 * return n1 + n2
 */
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2);

/*
 * define function rnSubtract
 * return n1 - n2
 */
RationalNumber rnSubtract(RationalNumber n1,RationalNumber n2);

/*
 * define function rnMultiply
 * return n1 * n2
 */
RationalNumber rnMultiply(RationalNumber n1,RationalNumber n2);

/*
 * define function rnMultiply
 * return n1 / n2
 */
RationalNumber rnDivide(RationalNumber n1,RationalNumber n2);

/* define unction rnNormalize
 * devide nominator and denominator of parameter n with the greatest common	divisor (GCD)
 * use euclidean algorithm to calc the GCD
 */
RationalNumber rnNormalize(RationalNumber n);

/*
 * Define euclidian algorithm
 */
unsigned short int euclid(unsigned short int n1, unsigned short int n2);

#endif // RATIONALNUMBER_H
