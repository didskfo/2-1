#ifndef _MYTERM_H_
#define _MYTERM_H_
#include <iostream>
using namespace std;
class myPolynomial;
class myTerm
{
public:
    myTerm(int c = 0, unsigned e = 0);
// copy constructor
    myTerm(const myTerm &term);
// overloaded operators
    friend bool operator == (const myTerm& term1, const myTerm& term2);
    friend bool operator < (const myTerm& term1, const myTerm& term2);
    friend bool operator > (const myTerm& term1, const myTerm& term2);
    myTerm operator - () const;
// accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
// mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
// member functions
    myTerm ddx() const; // derivative of a term
// friend functions and classes
    friend ostream& operator <<(ostream &outStream, const myTerm& term);
    friend class myPolynomial;
    friend bool operator==(const myPolynomial&, const myPolynomial&);
    int coeff; // integer coefficient
    unsigned exp; // exponent (non-negative integer)
};
bool operator != (const myTerm& term1, const myTerm& term2);
bool operator >= (const myTerm& term1, const myTerm& term2);
bool operator <= (const myTerm& term1, const myTerm& term2);
#endif