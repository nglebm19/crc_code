// Name: Andrew Le
// File: Complex.cpp
// Purpose: Implements the Complex class including constructor,
//          equality comparison, and output operator.

#include "Complex.h"

// Constructor
// Initializes the real and imaginary parts of the complex number
Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}

// Equality operator
// Returns true if both the real and imaginary parts are equal
bool Complex::operator==(const Complex& right) const
{
    return (real == right.real && imaginary == right.imaginary);
}

// Output operator
// Displays the complex number in the format: a + bi or a - bi
ostream& operator<<(ostream& output, const Complex& c)
{
    if (c.imaginary >= 0)
        output << c.real << " + " << c.imaginary << "i";
    else
        output << c.real << " - " << -c.imaginary << "i";

    return output; // allows chaining with other cout operations
}