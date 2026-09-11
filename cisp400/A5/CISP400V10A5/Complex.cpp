// Name: Andrew Le
// Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
   : real(realPart),
      imaginary(imaginaryPart)
{
   // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+(const Complex &operand2) const
{
   return Complex(real + operand2.real,
                  imaginary + operand2.imaginary);
} // end function operator+

// subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
   return Complex(real - operand2.real,
                  imaginary - operand2.imaginary);
} // end function operator-

// multiplication operator
// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex &operand2) const
{
   return Complex(real * operand2.real - imaginary * operand2.imaginary,
                  real * operand2.imaginary + imaginary * operand2.real);
} // end function operator*

// division operator
// (a + bi) / (c + di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i
// If denominator is zero, prints "infinite" and returns (0, 0)
Complex Complex::operator/(const Complex &operand2) const
{
   double denominator = operand2.real * operand2.real + operand2.imaginary * operand2.imaginary;

   if (denominator == 0.0)
   {
      cout << "infinite";
      return Complex(0.0, 0.0);
   } // end if

   return Complex(
       (real * operand2.real + imaginary * operand2.imaginary) / denominator,
       (imaginary * operand2.real - real * operand2.imaginary) / denominator);
} // end function operator/

// equality operator
// uses epsilon to handle floating point precision errors
bool Complex::operator==(const Complex &operand2) const
{
   // Define a small epsilon value for floating point comparison
   const double epsilon = 1e-9;
   return (fabs(real - operand2.real) < epsilon &&
         fabs(imaginary - operand2.imaginary) < epsilon);
} // end function operator==

// inequality operator
bool Complex::operator!=(const Complex &operand2) const
{
   return !(*this == operand2);
} // end function operator!=

// assignment operator
Complex &Complex::operator=(const Complex &right)
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;
} // end function operator=

// overloaded stream insertion operator <<
// displays Complex object in the form: ( a,  b)
ostream &operator<<(ostream &output, const Complex &c)
{
   output << "( " << c.real << ",  " << c.imaginary << ")";
   return output;
} // end function operator<<

// overloaded stream extraction operator >>
// prompts user and reads real and imaginary parts
// expects input in the form: (a, b)
istream &operator>>(istream &input, Complex &c)
{
   cout << "Enter a complex number in the form: (a, b) for Complex object k." << endl;
   cout << "(Performing >> operator overloading.)" << endl;
   cout << "? ";
   char ch; // used to read and discard '(', ',', ')'
   input >> ch >> c.real >> ch >> c.imaginary >> ch;
   return input;
} // end function operator>>

// display a Complex object in the form: (a, b)
void Complex::print() const
{
   cout << '(' << real << ", " << imaginary << ')';
} // end function print