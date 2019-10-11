#include "ArrayPolynomial.h"
#include <iostream>
#include<cmath>

using namespace std;
//constructor for initializing private data members
ArrayPolynomial::ArrayPolynomial()
{
  for(unsigned i=0;i<=31;i++)
    coeff[i]=0;
  degreeOfPoly=0;

}

/** Adds a new term to the polynomial.
        @post  If successful, a new term is added to the polynomial
            and the degree of the polynomial is updated, if needed.
        @param coefficient The coefficient of the new term.
        @param exponent The exponent of the new term.
        @return  True if addition was successful, or false if not. */
		
bool ArrayPolynomial:: addTerm ( double coefficient , unsigned exponent )
{
    if(degreeOfPoly>=31)
      return false;
    coeff[exponent]=coefficient;
    degreeOfPoly++;
    return true;
}



/** Evaluates the polynomial based on a given value for x.
        @param x The value to evaluate the polynomial with.
        @return The value f(x) of the polynomial. */
		
double ArrayPolynomial::evaluate( double x ) const
{
    double sum=0;
    for(unsigned i=1;i<getDegree();i++)
    {
      sum=sum+((coeff[i])*(pow(x,i)));

    }
    sum = sum + coeff[0];
    return sum;
}


 /** Determines the degree of the polynomial.
        @return Degree of the polynomial. */

unsigned ArrayPolynomial::getDegree() const
{

    return degreeOfPoly;

}

/** Determines if this is the zero polynomial.
        @return true if polynomial is the constant zero. */
		
bool ArrayPolynomial::isZero() const
{
    if(getDegree()==0 && coeff[0]==0)
    return true;
    else
        return false;
}

/** Resets the polynomial to degree 0.
        @post  Polynomial is set to the zero polynomial. */
		
void ArrayPolynomial::clear()
{

    for(unsigned i=0;i<=31;i++)
    coeff[i]=0;
    degreeOfPoly=0;
}



/** Display the polynomial in the "traditional" sense.
        @post Display to standard output the non-zero terms of the
            polynomial from highest exponent to the lowest exponent.
            Displays constant polynomials correctly. */
			
void ArrayPolynomial::print() const
{
    for(unsigned a=0; a<=getDegree();a++)
    {
        if(a==getDegree())
            std::cout << "(" << coeff[a] << ", " << a << ")";
        else
        std::cout << "(" << coeff[a] << ", " << a << ") + ";
    }
    std::cout << std::endl;
}
