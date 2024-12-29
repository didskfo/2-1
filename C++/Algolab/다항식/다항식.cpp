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

#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include <iostream>
#include <list>
#include "vector"
#include "cmath"
#include "algorithm"
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

//#include "myPolynomial.h"
/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned int e) {
    myTerm term(c, e);
    polynomial.push_back(term);
}
myPolynomial::myPolynomial(unsigned numTerm, int* terms) {
    for (int i = 0; i < numTerm; i++) {
        myTerm term(terms[2*i], terms[2*i+1]);
        polynomial.push_back(term);
    }
    sort(polynomial.begin(), polynomial.end());
}
myPolynomial::myPolynomial(const myPolynomial &poly) {
    for (int i = 0; i < poly.polynomial.size(); i++) {
        myTerm term(poly.polynomial[i]);
        polynomial.push_back(term);
    }
    sort(polynomial.begin(), polynomial.end());
}
myPolynomial &myPolynomial::operator=(const myPolynomial &poly) {
    polynomial.clear();
    for (int i = 0; i < poly.polynomial.size(); i++) {
        myTerm term(poly.polynomial[i]);
        polynomial.push_back(term);
    }
    return *this;
}
int myPolynomial::getDegree() const {
    return polynomial[0].exp;
}
unsigned myPolynomial::getNumTerms() const {
    return polynomial.size();
}
myPolynomial myPolynomial::ddx() const {
    if (polynomial.size() == 1) {
        if (polynomial[0].exp != 0) {
            myPolynomial dx(polynomial[0].coeff * polynomial[0].exp, polynomial[0].exp-1);
            return dx;
        } else {
            myPolynomial dx(0, 0);
            return dx;
        }
    }
    int newNumTerms = polynomial.size()-1;
    int terms[newNumTerms*2];
    for (int i = 0; i < newNumTerms; i++) {
        terms[2*i] = polynomial[i].coeff * polynomial[i].exp;
        terms[2*i+1] = polynomial[i].exp - 1;
    }
    myPolynomial dx(newNumTerms, terms);
    return dx;
}
myPolynomial &myPolynomial::operator+=(const myPolynomial &poly) {
    int pos1=0, pos2=0, size1=polynomial.size(), size2=poly.polynomial.size();
    while (pos1 < size1 && pos2 < size2) {
        if (polynomial[pos1] < poly.polynomial[pos2]) pos1++;
        else if (polynomial[pos1] > poly.polynomial[pos2]) polynomial.push_back(poly.polynomial[pos2++]);
        else if (polynomial[pos1].exp == poly.polynomial[pos2].exp) polynomial[pos1++].coeff += poly.polynomial[pos2++].coeff;
    }
    if (pos2 != size2) {
        for (int i=pos2; i<size2; i++) {
            polynomial.push_back(poly.polynomial[i]);
        }
    }
    vector<myTerm>::iterator iter = polynomial.begin();
    while (iter != polynomial.end()) {
        if (!iter->coeff) polynomial.erase(iter);
        else iter++;
    }
    if (polynomial.empty()) {
        myTerm term(0, 0);
        polynomial.push_back(term);
    }
    sort(polynomial.begin(), polynomial.end());
    return *this;
}
myPolynomial &myPolynomial::operator-=(const myPolynomial &poly) {
    // 1, n^1000000000
    int pos1=0, pos2=0, size1=polynomial.size(), size2=poly.polynomial.size();
    while (pos1 < size1 && pos2 < size2) {
        if (polynomial[pos1] < poly.polynomial[pos2]) pos1++;
        else if (polynomial[pos1] > poly.polynomial[pos2]) polynomial.push_back(-poly.polynomial[pos2++]);
        else if (polynomial[pos1].exp == poly.polynomial[pos2].exp) polynomial[pos1++].coeff -= poly.polynomial[pos2++].coeff;
    }
    if (pos2 != size2) {
        for (int i=pos2; i<size2; i++) {
            polynomial.push_back(-poly.polynomial[i]);
        }
    }
    vector<myTerm>::iterator iter = polynomial.begin();
    while (iter != polynomial.end()) {
        if (!iter->coeff) polynomial.erase(iter);
        else iter++;
    }
    if (polynomial.empty()) {
        myTerm term(0, 0);
        polynomial.push_back(term);
    }
    sort(polynomial.begin(), polynomial.end());
    return *this;
}
myPolynomial &myPolynomial::operator*=(const myTerm &term) {
    for (int i=0; i<polynomial.size(); i++) {
        polynomial[i].coeff *= term.coeff;
        polynomial[i].exp += term.exp;
    }
    return *this;
}
myPolynomial &myPolynomial::operator*=(const myPolynomial &poly) {
    myPolynomial res;
    for (int i=0; i<polynomial.size(); i++) {
        myPolynomial _poly(poly);
        _poly *= polynomial[i];
        res += _poly;
    }
    return *this = res;
}
myPolynomial &myPolynomial::operator*=(int size) {
    if (size == 0) {
        polynomial.clear();
        myTerm term(0, 0);
        polynomial.push_back(term);
        return *this;
    }
    for (int i=0; i<polynomial.size(); i++) {
        polynomial[i].coeff *= size;
    }
    return *this;
}

myPolynomial operator+(const myPolynomial &poly1, const myPolynomial &poly2) {
    myPolynomial poly(poly1);
    return poly += poly2;
}
myPolynomial operator-(const myPolynomial &poly1, const myPolynomial &poly2) {
    myPolynomial poly(poly1);
    return poly -= poly2;
}
myPolynomial operator*(const myPolynomial &poly1, const myTerm &term) {
    myPolynomial poly(poly1);
    return poly *= term;
}
myPolynomial operator*(const myTerm &term, const myPolynomial &poly1) {
    myPolynomial poly(poly1);
    return poly *= term;
}
myPolynomial operator*(const myPolynomial &poly1, const myPolynomial &poly2) {
    myPolynomial poly(poly1);
    return poly *= poly2;
}
myPolynomial operator*(const myPolynomial &poly1, int size) {
    myPolynomial poly(poly1);
    return poly *= size;
}
myPolynomial operator*(int size, const myPolynomial &poly1) {
    myPolynomial poly(poly1);
    return poly *= size;
}

long myPolynomial::operator()(int x) const {
    long res = 0;
    for (int i=0; i<polynomial.size(); i++) {
        res += polynomial[i].coeff * pow(x, polynomial[i].exp);
    }
    return res;
}

myPolynomial myPolynomial::operator-() const {
    int num_terms = polynomial.size();
    int terms[(num_terms)*2];
    for (int i=0; i<num_terms; i++) {
        terms[2*i] = -polynomial[i].coeff;
        terms[2*i+1] = polynomial[i].exp;
    }
    myPolynomial poly(num_terms, terms);
    return poly;
}

bool operator==(const myPolynomial &poly1, const myPolynomial &poly2) {
    if (poly1.polynomial[0] != poly2.polynomial[0]) return false;
    if (poly1.polynomial.size() != poly2.polynomial.size()) return false;
    for (int i=0; i<poly1.polynomial.size(); i++) {
        if (poly1.polynomial[i].coeff != poly2.polynomial[i].coeff) {
            return false;
        }
    }
    return true;
}
bool operator!=(const myPolynomial &poly1, const myPolynomial &poly2) {
    return !(poly1 == poly2);
}

ostream &operator<<(ostream &outstream, const myPolynomial &poly) {
    for (int i=0; i<poly.polynomial.size(); i++) {
        myTerm term = poly.polynomial[i];
        if (i && term.coeff > 0) cout << "+";
        if (term.exp > 1) {
            if (term.coeff != 1 && term.coeff != -1) {
                outstream << poly.polynomial[i].coeff << "x^" << poly.polynomial[i].exp;
            }
            else if (term.coeff == 1) {
                outstream << "x^" << poly.polynomial[i].exp;
            }
            else if (term.coeff == -1) {
                outstream << "-x^" << poly.polynomial[i].exp;
            }
        }
        else if (poly.polynomial[i].exp == 1) {
            if (term.coeff != 1 && term.coeff != -1) {
                outstream << poly.polynomial[i].coeff << "x";
            }
            else if (term.coeff == 1) {
                outstream << 'x';
            }
            else if (term.coeff == -1) {
                outstream << "-x";
            }
        }
        else if (poly.polynomial[i].exp == 0) {
            outstream << poly.polynomial[i].coeff;
        }
    }
    return outstream;
}

const myPolynomial myPolynomial::ZERO(0, 0);
const myPolynomial myPolynomial::ONE(1, 0);
const myPolynomial myPolynomial::X(1, 1);

//#include "myPolynomial.h"
#include <fstream>
#include <cstdlib>
using namespace std;

void testSimpleCase();
void testDataFromFile();

int main() {
    testSimpleCase();
    testDataFromFile();
    return 0;
}

void testSimpleCase() {
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);
    // test constructor
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;
    // test copy constructor
    cout << p9 << endl;
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3*myPolynomial::ZERO << endl;
    cout << 3*myPolynomial::ONE << endl;
    cout << myPolynomial::X*3 << endl;
    cout << 3*p4 << " " << p4*3 << endl;
    cout << 0*p5 << " " << p5*5 << endl;
    // test binary operator +
    cout << p4 + p5 << endl;
    // test binary operator -
    cout << p6 - p7 << endl;
    // test binary operator *
    cout << p8 * p9 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
    // int t;
    // cin >> t;
}

void testDataFromFile() {
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++) {
        int numTerms, terms[100];
        /* read first polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++) {
            cin >> terms[2*j] >> terms[2*j+1];
        }
        myPolynomial p1(numTerms, terms);
        /* read second polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++) {
            cin >> terms[2*j] >> terms[2*j+1];
        }
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;    // -x^1000000000 + 1
        p5 *= p4;    // -x^1000000001 + x
        p5 *= 2;     // -2x^1000000001 + 2x
        cout << p5 << endl;
    }
}

