#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(double a);
	Complex(double a, double b);
	double getRealPart() const;
	double getImaginaryPart() const;


	Complex(int a, int b);

	Complex add(const Complex& secondComplex) const;
	Complex subtract(const Complex& secondComplex) const;
	Complex multiply(const Complex& secondComplex) const;
	Complex divide(const Complex& secondComplex) const;
	string toString() const;
	double Complex::abs();

	// Function definition for pre operators
	Complex& operator+=(const Complex& secondComplex);
	Complex& operator-=(const Complex& secondComplex);
	Complex& operator*=(const Complex& secondComplex);
	Complex& operator/=(const Complex& secondComplex);

	// Function definition for []
	double& operator[](int index);

	// Function definitions for ++ and -- (pre)
	Complex& operator++();
	Complex& operator--();

	// Function definitions for ++ and -- (post)
	Complex operator++(int dummy);
	Complex operator--(int dummy);

	// Function definition for the + and - unary oparators
	Complex operator+();
	Complex operator-();

	// Define the << and >> operators
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator >> (istream&, Complex&);

private:
	double a;
	double b;

};

// Function definition for comparison operatots
bool operator<(const Complex& r1, const Complex& r2);
bool operator<=(const Complex& r1, const Complex& r2);
bool operator>(const Complex& r1, const Complex& r2);
bool operator>=(const Complex& r1, const Complex& r2);
bool operator==(const Complex& r1, const Complex& r2);
bool operator!=(const Complex& r1, const Complex& r2);

// Function definitions for arithmetic operators
Complex operator+(const Complex& r1, const Complex& r2);
Complex operator-(const Complex& r1, const Complex& r2);
Complex operator*(const Complex& r1, const Complex& r2);
Complex operator/(const Complex& r1, const Complex& r2);

#endif