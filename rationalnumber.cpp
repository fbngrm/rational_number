#include <rationalnumber.h>
#include <math.h>

// implement function rnIsValid
bool rnIsValid(RationalNumber n){
    return n.deno != 0;
}

// implement function rnIsNaN
bool rnIsNaN(RationalNumber n){
    return n.deno == 0;
}

// implement function rnEqual
bool rnEqual(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) return false;

    signed int a1 = n1.nomi * n2.deno;
    signed int b1 = n1.deno * n2.deno;

    signed int a2 = n2.nomi * n1.deno;
    signed int b2 = n2.deno * n1.deno;

    return (a1 == a2 && b1 == b2);
}

// implement function rnLessThan
bool rnLessThan(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) return false;
    return (n1.nomi * n2.deno) * (n1.deno * n2.deno) < (n2.nomi * n1.deno) * (n2.deno * n1.deno);
}

// implementfunction rnAdd
RationalNumber rnAdd(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) {
        RationalNumber nan = {0, 0};
        return nan;
    }

    signed short int nomi = (n1.nomi * n2.deno) + (n2.nomi * n1.deno);
    signed short int deno = n1.deno * n2.deno;

    RationalNumber n = { nomi, deno };
    return rnNormalize(n);
}

// implementfunction rnSubtract
RationalNumber rnSubtract(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) {
        RationalNumber nan = {0, 0};
        return nan;
    }

    signed short int nomi = (n1.nomi * n2.deno) - (n2.nomi * n1.deno);
    signed short int deno = n1.deno * n2.deno;

    RationalNumber n = { nomi, deno };
    return rnNormalize(n);
}

// implementfunction rnMultiply
RationalNumber rnMultiply(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) {
        RationalNumber nan = {0, 0};
        return nan;
    }

    signed short int nomi = n1.nomi * n2.nomi;
    signed short int deno = n1.deno * n2.deno;

    RationalNumber n = { nomi, deno };
    return rnNormalize(n);
}

// implementfunction rnDivide
RationalNumber rnDivide(RationalNumber n1, RationalNumber n2){
    if (rnIsNaN(n1) || rnIsNaN(n2)) {
        RationalNumber nan = {0, 0};
        return nan;
    }

    signed short int nomi = n1.nomi * n2.deno;
    signed short int deno = n1.deno * n2.nomi;

    RationalNumber n = { nomi, deno };
    return rnNormalize(n);
}

RationalNumber rnNormalize(RationalNumber n){
    // get gdc
    unsigned short int gcd = euclid(n.nomi, n.deno);
    // normalize with gdc
    RationalNumber res = { n.nomi/gcd, n.deno/gcd };
    return res;
}

// implementation of the euclidian algorithm to calculate the greatest common divisor
unsigned short int euclid(unsigned short int n1, unsigned short int n2) {
    if (n1 < n2) {
        unsigned short int t = n1;
        n1 = n2;
        n2 = t;
    }
    if (n2 == 0) {
        return n1;
    }
    // recursion
    return euclid(n2, n1 % n2);
}


