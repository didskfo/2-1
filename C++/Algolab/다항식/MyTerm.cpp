#include "myTerm.h"
// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e)
{
}
// copy constructor
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp)
{
}
// overloaded operators
bool operator == (const myTerm& term1, const myTerm& term2)
{
    return (term1.coeff == term2.coeff && term1.exp == term2.exp);
}
// overloaded operators
bool operator != (const myTerm& term1, const myTerm& term2)
{
    return !(term1 == term2);
}
// overloaded operators
bool operator < (const myTerm& term1, const myTerm& term2)
{
    return term1.exp > term2.exp;
}
bool operator <= (const myTerm& term1, const myTerm& term2)
{
    return !(term1 > term2);
}
bool operator > (const myTerm& term1, const myTerm& term2)
{
    return term1.exp < term2.exp;
}
bool operator >= (const myTerm& term1, const myTerm& term2)
{
    return !(term1 < term2);
}
myTerm myTerm::operator - () const
{
    return myTerm(-coeff, exp);
}
// derivative of a term
myTerm myTerm::ddx() const
{
    return myTerm(coeff*exp, exp-1);
}
// output operator
ostream& operator <<(ostream &outStream, const myTerm& term)
{
    if (term.exp == 0) {
        if (term.coeff == 0) {
            return outStream;
        }
        else {
            return outStream << term.coeff;
        }
    }
    if (term.exp == 1) {
        return outStream << term.coeff << "x";
    }
    return outStream << term.coeff << "x^" << term.exp;

//    if (term.coeff == 1)
//        outStream << "x";
//    else if (term.coeff == -1)
//        outStream << "-x";
//    else
//        outStream << term.coeff << "x";
//    if (term.exp == 1)
//        return outStream;
//    else
//        return outStream << "^" << term.exp;
}