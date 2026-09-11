// Name: Andrew Le
// Complex.h
// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
   // overloaded stream insertion operator (output)
   friend std::ostream &operator<<(std::ostream &, const Complex &);
   // overloaded stream extraction operator (input)
   friend std::istream &operator>>(std::istream &, Complex &);

public:
   explicit Complex(double = 0.0, double = 0.0); // constructor
   Complex operator+(const Complex &) const;     // addition
   Complex operator-(const Complex &) const;     // subtraction
   Complex operator*(const Complex &) const;     // multiplication
   Complex operator/(const Complex &) const;     // division
   bool operator==(const Complex &) const;       // equality
   bool operator!=(const Complex &) const;       // inequality
   Complex &operator=(const Complex &);          // assignment
   void print() const;                           // output
private:
   double real;      // real part
   double imaginary; // imaginary part
}; // end class Complex

#endif
