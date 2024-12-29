#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include <iostream>
#include <list>
#include "vector"
#include "cmath"
#include "algorithm"
#include "MyTerm.h"
using namespace std;
class myPolynomial
{
private:
    vector<myTerm> polynomial;
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(unsigned, int *);
// copy constructor
    myPolynomial(const myPolynomial &poly);
// overloaded operators
    friend bool operator == (const myPolynomial &, const myPolynomial &);
    myPolynomial& operator=(const myPolynomial &);
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myTerm&);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;

    long operator() (int x) const; // evaluate the polynomial
    int getDegree() const; // get a degree of the polynomial
    unsigned getNumTerms() const; // number of terms in the polynomial
//    void setCoeff(int c);
    myPolynomial ddx() const; // derivative of a polynomial
// friend operators and functions
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x
private:
    int degree; // maximum expnent
    int numTerm;
    myTerm m_Term[100];
    /********************* add your code here ********************************/
};
myPolynomial operator +(const myPolynomial&, const myPolynomial&);
myPolynomial operator -(const myPolynomial&, const myPolynomial&);
myPolynomial operator *(const myPolynomial&, const myTerm&);
myPolynomial operator *(const myTerm&, const myPolynomial&);
myPolynomial operator *(const myPolynomial&, const myPolynomial&);
myPolynomial operator *(const myPolynomial&, int);
myPolynomial operator *(int, const myPolynomial&);
bool operator !=(const myPolynomial&, const myPolynomial&);
#endif _MYPOLYNOMIAL_H_