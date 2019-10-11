#ifndef POLYNOMIALINTERFACE_H_INCLUDED
#define POLYNOMIALINTERFACE_H_INCLUDED

class PolynomialInterface
{
    public:

    /** Determines if this is the zero polynomial.
        @return true if polynomial is the constant zero. */
        virtual bool isZero() const = 0;

    /** Determines the degree of the polynomial.
        @return Degree of the polynomial. */
        virtual unsigned getDegree() const = 0;

    /** Adds a new term to the polynomial.
        @post  If successful, a new term is added to the polynomial
            and the degree of the polynomial is updated, if needed.
        @param coefficient The coefficient of the new term.
        @param exponent The exponent of the new term.
        @return  True if addition was successful, or false if not. */
        virtual bool addTerm( double coefficient , unsigned exponent ) = 0;

    /** Resets the polynomial to degree 0.
        @post  Polynomial is set to the zero polynomial. */
        virtual void clear() = 0;

    /** Evaluates the polynomial based on a given value for x.
        @param x The value to evaluate the polynomial with.
        @return The value f(x) of the polynomial. */
        virtual double evaluate( double x ) const = 0;

    /** Display the polynomial in the "traditional" sense.
        @post Display to standard output the non-zero terms of the
            polynomial from highest exponent to the lowest exponent.
            Displays constant polynomials correctly. */
        virtual void print() const = 0;

}; // end PolynomialInterface

#endif // POLYNOMIALINTERFACE_H_INCLUDED
