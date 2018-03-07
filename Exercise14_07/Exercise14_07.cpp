/**
* Class: CSCI2490 C++ Programming
* Instructor: Y. Daniel Liang
* Description: Performs a calculation based off of what was given in the book. 
* Due: 10/26/2016
* @author Shaun C. Dobbs
* @version 1.0

* I pledge by honor that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student.

Sign here: Shaun C. Dobbs
*/

#include "stdafx.h"
#include "Complex.h"
#include <cstdlib> //For absolute value function
#include <sstream> 
#include <string>


//Default constructor set to 0 per instructions
Complex::Complex()
{
	a = 0;
	b = 0;
}

//Consttuctor where b is 0 and a is input per instructions
Complex::Complex(double a)
{
	this->a = a;
	this->b = 0;
}

//Constructor for both a and b
Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}

//Return for a (real number)
double Complex::getRealPart() const
{
	return a;
}

//Return for b (imaginary number)
double Complex::getImaginaryPart() const
{
	return b;
}

//Define operator for the >> operator (input stream)
istream& operator >> (istream& in, Complex& complex)
{
	//cout << "Enter real number: ";
	in >> complex.a;

	//cout << "Enter imaginary : ";
	in >> complex.b;
	return in;
}

//Define operator for the << operator (output stream)
ostream& operator<<(ostream& out, const Complex& complex)
{
	stringstream ss;
	string str;

	if (complex.b == 0)
	{
		//out << printf("%4.2d", complex.b);
		ss << printf("%4.2f", complex.b);
		str = ss.str();
		str.erase(str.length() - 1, str.length());
	}
	else
	{
		ss << printf("%4.2f + %4.2fi", complex.a, complex.b);
		str = ss.str();
		str.erase(str.length() - 2, str.length());
		out << str;
		//out << printf("%4.2f + %4.2f", complex.a, complex.b, 'i');
		//out << printf("%4.2f", (complex.a)) + " + " + printf("%4.2f", (complex.b)) + "i";
		//out << to_string(complex.a) + " + " + to_string(complex.b) + "i";
	}
	return out;

	//out << printf("%4.2f", (complex.a));
	//out << to_string(complex.a) + " + " + to_string(complex.b) + "i";
}

//Type conversion from int to double
Complex::Complex(int a, int b)
{
	this->a = a * 1.0;
	this->b = b * 1.0;
}

//Function definitions for "augmented" operators
Complex& Complex::operator+=(const Complex& secondComplex)
{
	*this = add(secondComplex);
	return *this;
}

Complex& Complex::operator-=(const Complex& secondComplex)
{
	*this = subtract(secondComplex);
	return *this;
}

Complex& Complex::operator*=(const Complex& secondComplex)
{
	*this = multiply(secondComplex);
	return *this;
}

Complex& Complex::operator/=(const Complex& secondComplex)
{
	*this = divide(secondComplex);
	return *this;
}

// Function definition for []
double& Complex::operator[](int index)
{
	if (index == 0)
		return a;
	else
		return b;
}

//Function definitions for the post-increment and post-decrement
Complex& Complex::operator++() //Prefix has no arg
{
	a += 1;
	return *this;
}

Complex& Complex::operator--()
{
	a -= 1;
	return *this;
}


//Function definition for postfix ++ and --
Complex Complex::operator++(int dummy) //Postfix has an int dummy arg
{
	Complex temp(a, b);
	a += 1;
	return temp;
}

Complex Complex::operator--(int dummy)
{
	Complex temp(a, b);
	a -= 1;
	return temp;
}

// Function definitions for unary + and - 
Complex Complex::operator+()
{
	return *this;
}

Complex Complex::operator-()
{
	return Complex(-a, b);
}

// Function definition for non member arithmetic member operators(+, -, *, and /)
Complex operator+(const Complex& r1, const Complex& r2)
{
	return r1.add(r2);
}

Complex operator-(const Complex& r1, const Complex& r2)
{
	return r1.subtract(r2);
}

Complex operator*(const Complex& r1, const Complex& r2)
{
	return r1.multiply(r2);
}

Complex operator/(const Complex& r1, const Complex& r2)
{
	return r1.divide(r2);
}

//Function for complex number addition
//Refer to pg 546 in book. Modified to match operations given in ex14_07
Complex Complex::add(const Complex& secondComplex) const
{
	double complex0 = a + secondComplex.a;
	double complex1 = b + secondComplex.b;
	return Complex(complex0, complex1);
}

Complex Complex::subtract(const Complex& secondComplex) const
{
	double complex0 = a - secondComplex.a;
	double complex1 = b - secondComplex.b;
	return Complex(complex0, complex1);
}

Complex Complex::multiply(const Complex& secondComplex) const
{

	double complex0 = (a * secondComplex.a - b * secondComplex.b);
	double complex1 = (b * secondComplex.a + a * secondComplex.b);
	return Complex(complex0, complex1);

}

Complex Complex::divide(const Complex& secondComplex) const
{
	double complex0 = (a * secondComplex.a + b * secondComplex.b) / (secondComplex.a * secondComplex.a + secondComplex.b * secondComplex.b);
	double complex1 = (b * secondComplex.a - a * secondComplex.b) / (secondComplex.a * secondComplex.a + secondComplex.b * secondComplex.b);
	return Complex(complex0, complex1);
}

double Complex::abs()
{
	return  sqrt(a * a + b * b);
}

//TO STRING FUNCTION INSERTED HERE
//toString example in rational program on pg. 547 in cpp book
string Complex::toString() const
{
	//New function in c++ 11
	/*string result = to_string(a);

	if (b != 0)
		result += " + " + to_string(b) + "i";

	return result;*/

	/*stringstream ss;

	ss << a;
	if (b != 0)
		ss << " + " << b << "i";

	return ss.str();*/
	return "";

}
//End of Complex.cpp

//Beginning of ComplexTest.cpp
//Test file given for exercise
int main()
{
	Complex number1;
	cout << "Enter the first complex number: ";
	cin >> number1;

	Complex number2;
	cout << "Enter the second complex number: ";
	cin >> number2;

	

	/*cout << (number1 + number2) << endl;
	cout << (number1 - number2) << endl;
	cout << (number1 * number2) << endl;
	cout << (number1 / number2) << endl;
	printf("%4.1f", number1.abs());
	cout << endl;*/

	cout << "(" << number1 << ")" << " + " << "(" << number2
		<< ") = " << (number1 + number2) << endl;
	cout << "(" << number1 << ")" << " - " << "(" << number2
		<< ") = " << (number1 - number2) << endl;
	cout << "(" << number1 << ")" << " * " << "(" << number2
		<< ") = " << (number1 * number2) << endl;
	cout << "(" << number1 << ")" << " / " << "(" << number2
		<< ") = " << (number1 / number2) << endl;
	cout << "|" << number1 << "|" << " = ";
	printf("%4.1f", number1.abs()); 
	cout << endl;

	number1[0] = 3.4;
	cout << number1++ << endl;
	cout << ++number2 << endl;
	cout << (3 + number2) << endl;
	cout << (number2 += number1) << endl;
	cout << (number2 *= number1) << endl;

	return 0;

}
//End of test ComplexTest.cpp

