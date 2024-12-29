#include "myPolynomial.h"
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
