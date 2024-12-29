#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
using namespace std;
class myRational
{
public:
    myRational(long num=0, long den=1);
    myRational(const myRational& rat);
    long getNumerator() const;
    long getDenominator() const;
    myRational reciprocal() const;
    myRational operator+(const myRational& number) const;
    myRational operator+(long value) const;
    myRational operator-(const myRational& number) const;
    myRational operator-(long value) const;
    myRational operator*(const myRational& number) const;
    myRational operator*(long value) const;
    myRational operator/(const myRational& number) const;
    myRational operator/(long value) const;
    myRational operator++();
    myRational operator++(int);
    myRational operator--();
    myRational operator--(int);
    myRational operator-();
    myRational& operator=(const myRational& number);
    myRational& operator=(long value);
    myRational& operator+=(const myRational& number);
    myRational& operator+=(long value);
    myRational& operator-=(const myRational& number);
    myRational& operator-=(long value);
    myRational& operator*=(const myRational& number);
    myRational& operator*=(long value);
    myRational& operator/=(const myRational& number);
    myRational& operator/=(long value);
    bool operator==(const myRational& number) const;
    bool operator==(long value) const;
    bool operator!=(const myRational& number) const;
    bool operator!=(long value) const;
    bool operator>(const myRational& number) const;
    bool operator>=(const myRational& number) const;
    bool operator<(const myRational& number) const;
    bool operator<=(const myRational& number) const;
    friend istream &operator>>(istream &inStream, myRational& r);
    friend ostream &operator<<(ostream &outStream, const myRational& r);
    friend myRational operator+(long value, const myRational& number);
    friend myRational operator-(long value, const myRational& number);
    friend myRational operator*(long value, const myRational& number);
    friend myRational operator/(long value, const myRational& number);
private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
    long _den; // denominator
    long _num;
    long gcd(long m, long n); // 최대공약수
    void reduce();
};
#endif

//#include "MyRational.h"
using namespace std;
myRational::myRational(long num, long den):_num(num), _den(den) {
    reduce();
}
myRational::myRational(const myRational &rat) {
    _num = rat._num;
    _den = rat._den;
}
long myRational::getNumerator() const {
    return _num;
}
long myRational::getDenominator() const {
    return _den;
}
ostream &operator <<(ostream &outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}
myRational myRational::reciprocal() const {
    return myRational( _den, _num);
}
myRational myRational::operator+(const myRational &number) const {
    long new_den = _den * number._den;
    long new_num = _num * number._den + number._num * _den;
    return myRational(new_num, new_den);
}
myRational myRational::operator+(long value) const {
    return (*this) + myRational(value, 1);
}
myRational myRational::operator-(const myRational &number) const {
    long new_den = _den * number._den;
    long new_num = _num * number._den - number._num * _den;
    return myRational(new_num,new_den);
}
myRational myRational::operator-(long value) const {
    return (*this) - myRational(value, 1);
}
myRational myRational::operator*(const myRational &number) const {
    long new_den = _den * number._den;
    long new_num = _num * number._num;
    return myRational(new_num, new_den);
}
myRational myRational::operator*(long value) const {
    return (*this) * myRational(value, 1);
}
myRational myRational::operator/(const myRational &number) const {
    if (number._num == 0) {
        return myRational();
    }
    myRational tmp = number.reciprocal();
    long new_den = _den * tmp._den;
    long new_num = _num * tmp._num;
    return myRational(new_num, new_den);
}
myRational myRational::operator/(long value) const {
    return (*this) / myRational(value, 1);
}
myRational myRational::operator++() {
    _num += _den;
    myRational tmp(_num, _den);
    return tmp;
}
myRational myRational::operator++(int) {
    myRational ret(_num, _den);
    _num += _den;
    return ret;
}
myRational myRational::operator--() {
    _num -= _den;
    myRational ret(_num, _den);
    return ret;
}
myRational myRational::operator--(int) {
    myRational ret(_num, _den);
    _num -= _den;
    return ret;
}
myRational myRational::operator-() {
    return myRational(-_num, _den);
}
myRational& myRational::operator=(const myRational &number) {
    this->_den = number._den;
    this->_num = number._num;
    return *this;
}
myRational& myRational::operator=(long value) {
    _den = 1;
    _num = value;
    return *this;
}
myRational& myRational::operator +=(const myRational &number) {
//    long new_den = _den * number._den;
//    long new_num = _num*number._den + number._num*_den;
//    this->_den = new_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    reduce();
//    return *this;
//    long den = this->_den;
//    long num = this->_num;
//    this->_den = den * number._den;
//    this->_num = (num * number._den) + (number._num * _den);
//    reduce();
//    return *this;
    _num = _num * number._den + number._num * _den;
    _den *= number._den;
    reduce();
    return *this;
}
myRational& myRational::operator +=(long value) {
//    long new_num = _num + value*_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    *this += myRational(value, 1);
    return *this;
}
myRational& myRational::operator -=(const myRational &number) {
//    long new_den = _den * number._den;
//    long new_num = _num*number._den - number._num*_den;
//    this->_den = new_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    long num = this->_num;
    long den = this->_den;
    this->_num = (num * number._den) - (number._num * _den);
    this->_den = den * number._den;
    reduce();
    return *this;
}
myRational& myRational::operator -=(long value) {
//    long new_num = _num - value*_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    *this -= myRational(value, 1);
    return *this;
}
myRational& myRational::operator *=(const myRational &number) {
//    long new_den = _den * number._den;
//    long new_num = _num * number._num;
//    this->_den = new_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    long num = this->_num;
    long den = this->_den;
    this->_num = num * number._num;
    this->_den = den * number._den;
    reduce();
    return *this;
}
myRational& myRational::operator *=(long value) {
//    long new_num = _num * value;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    *this *= myRational(value, 1);
    return *this;
}
myRational& myRational::operator /=(const myRational &number) {
//    if (number._num == 0) {
//        this->_den = 1;
//        this->_num = 0;
//        return *this;
//    }
//    long new_den = _den * number._num;
//    long new_num = _num * number._den;
//    this->_den = new_den;
//    this->_num = new_num;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    if (number._num == 0){
        this->_num = 0;
        this->_den = 1;
        return *this;
    }
    long num = this->_num;
    long den = this->_den;
    myRational tmp(number.reciprocal());
    this->_num = num * tmp._num;
    this->_den = den * tmp._den;
    reduce();
    return *this;
}
myRational& myRational::operator/=(long value) {
//    if (value == 0) {
//        this->_den = 1;
//        this->_num = 0;
//        return *this;
//    }
//    long new_den = _den * value;
//    this->_den = new_den;
//    this->_den = _den/ gcd(_den, _num);
//    this->_num = _num/ gcd(_den, _num);
//    return *this;
    *this /= myRational(value, 1);
    return *this;

}
bool myRational::operator==(const myRational &number) const {
    return (_den == number._den) && (_num == number._num);
}
//bool myRational::operator==(long value) const {
//    return (_den == 1) && (_num == value);
//}
bool myRational::operator!=(const myRational &number) const {
    return !operator==(number);
}
//bool myRational::operator!=(long value) const {
//    return (_den != 1) || (_num != value);
//}
bool myRational::operator>(const myRational &number) const {
    return (_num * number._den) > (number._num * _den);
}
//bool myRational::operator>(long value) const {
//    return (_num / _den) > value;
//}
bool myRational::operator>=(const myRational &number) const {
    return (_num * number._den) >= (number._num * _den);
}
//bool myRational::operator>=(long value) const {
//    return (_num / _den) >= value;
//}
bool myRational::operator<(const myRational &number) const {
    return (_num * number._den) < (number._num * _den);
}
//bool myRational::operator<(long value) const {
//    return (_num / _den) < value;
//}
bool myRational::operator<=(const myRational &number) const {
    return (_num * number._den) <= (number._num * _den);
}
//bool myRational::operator<=(long value) const {
//    return (_num / _den) <= value;
//}
myRational operator+(long value, const myRational& number){
//    long new_num = number._num + value*number._den;
//    return myRational(new_num, number._den);
    return number + value;
}
myRational operator-(long value, const myRational& number){
//    long new_num = value*number._den - number._num;
//    return myRational(new_num, number._den);
    myRational tmp(number);
    return -tmp + value;
}
myRational operator*(long value, const myRational& number){
//    long new_num = number._num * value;
//    return myRational(new_num, number._den);
    return number * value;
}
myRational operator/(long value, const myRational& number){
//    if (value == 0) {
//        return myRational(0, 1);
//    }
//    if (number._num == 0) {
//        return myRational(0, 1);
//    }
//    long new_num = value * number._den;
//    return myRational(new_num, number._num);
    myRational tmp(number.reciprocal());
    return tmp * value;
}


#include <fstream>
#include <cstdlib>
#include "vector"
#include "algorithm"
//#include "MyRational.h"
using namespace std;
void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
         << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators
    cout << frac1 * frac2 << " "
         << frac1 + frac3 << " "
         << frac2 - frac1 << " "
         << frac3 / frac2 << endl;
    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
         << ((frac1 <= frac2) ? 1 : 0) << " "
         << ((frac1 > frac2) ? 1 : 0) << " "
         << ((frac1 >= frac2) ? 1 : 0) << " "
         << ((frac1 == frac2) ? 1 : 0) << " "
         << ((frac1 != frac2) ? 1 : 0) << " "
         << ((frac2 < frac3) ? 1 : 0) << " "
         << ((frac2 <= frac3) ? 1 : 0) << " "
         << ((frac2 > frac3) ? 1 : 0) << " "
         << ((frac2 >= frac3) ? 1 : 0) << " "
         << ((frac2 == frac3) ? 1 : 0) << " "
         << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
         << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for (int i=0; i<numTestCases; i++){
        int testCase;
        inStream >> testCase;
        vector<myRational> v;
        for(int j=0; j<testCase; j++){
            int a, b;
            inStream >> a >> b;
            v.push_back(myRational(a,b));
        }
        sort(v.begin(), v.end());
        for(int j=0; j<v.size(); j++){
            cout << v[j] << " ";
        }
        cout << endl;
    }
    inStream.close();
}