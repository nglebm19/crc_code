// Name: Andrew Le
// File: Complex.h
// Purpose: Defines the Complex class which represents a complex number
//          with real and imaginary parts. The class overloads == and << operators.

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
private:
    double real;        // real part of the complex number
    double imaginary;   // imaginary part of the complex number

public:
    // Constructor
    // Initializes the real and imaginary parts
    Complex(double r = 0, double i = 0);

    // Equality operator
    // Returns true if both the real and imaginary parts are equal
    bool operator==(const Complex& right) const;

    // Output operator
    // Displays the complex number in the format: a + bi or a - bi
    friend ostream& operator<<(ostream& output, const Complex& c);
};

#endif