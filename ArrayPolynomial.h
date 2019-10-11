#ifndef ARRAYPOLYNOMIAL_H_INCLUDED
#define ARRAYPOLYNOMIAL_H_INCLUDED
#include "PolynomialInterface.h"

class ArrayPolynomial:public PolynomialInterface
{
private:
    double coeff[31];
    unsigned degreeOfPoly;


public:
    ArrayPolynomial();
    bool addTerm( double coefficient , unsigned exponent );
    double evaluate( double x ) const;
    unsigned getDegree() const;
    bool isZero() const;
    void clear();
    void print() const;
};

#include "ArrayPolynomial.cpp"

#endif // ARRAYPOLYNOMIAL_H_INCLUDED
