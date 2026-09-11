// Name: Andrew Le
// File: CISP400V10A6.cpp
// Purpose: This program demonstrates the use of template functions to compare values of different types, 
//         including integers, characters, doubles, complex numbers, strings, and dates. It uses the 
//         overloaded operators in the Complex and Date classes to perform comparisons and display results.

#include <iostream>
#include <string>
#include "Complex.h"
#include "Date.h"
using namespace std;

// Template function that compares two values of the same type
// Returns true if the values are equal and false otherwise
template <typename T>
bool isEqualTo(T a, T b)
{
    return a == b;
}
// Template function that compares two values of the same type
// Returns true if the values are equal and false otherwise

template <typename T>
void displayResult(const string& label, const T& a, const T& b)
{
    cout << label << a << " and " << b << " are ";

    if (!isEqualTo(a, b))
        cout << "\"NOT\" ";

    cout << "equal" << endl;
}

int main()
{
    // Integer tests
    cout << "***  Integers Tests  ***" << endl;
    displayResult("Integers: ", 1, 1);
    displayResult("Integers: ", 2, 4);
    displayResult("Integers: ", -1, 1);
    displayResult("Integers: ", -1, -1);
    cout << endl;

    // Character tests
    cout << "***  Chars Tests  ***" << endl;
    displayResult("Characters: ", 'a', 'a');
    displayResult("Characters: ", 'a', 'c');
    displayResult("Characters: ", 'c', 'a');
    displayResult("Characters: ", 'c', 'c');
    cout << endl;

    // Double tests
    cout << "***  Double Tests  ***" << endl;
    displayResult("Double numbers: ", 2.2, 2.2);
    displayResult("Double numbers: ", 2.2, 2.3);
    displayResult("Double numbers: ", -2.2, 2.2);
    displayResult("Double numbers: ", -2.2, -2.2);
    cout << endl;

    // Complex tests
    // Uses the overloaded == and << operators in the Complex class
    cout << "***  Complex Tests  ***" << endl;
    displayResult("Class objects: ", Complex(10, 5), Complex(10, 5));
    displayResult("Class objects: ", Complex(10, 5), Complex(10, 54));
    displayResult("Class objects: ", Complex(10, -5), Complex(10, 5));
    displayResult("Class objects: ", Complex(-10, -5), Complex(-10, -5));
    cout << endl;

    // String tests
    cout << "***  string Tests  ***" << endl;
    displayResult("String objects: ", string("abcdefg"), string("abcdefg"));
    displayResult("String objects: ", string("abcdefg"), string("abcdefh"));
    displayResult("String objects: ", string("-abcdefg"), string("abcdefg"));
    displayResult("String objects: ", string("-abcdefg"), string("-abcdefg"));
    cout << endl;

    // Date tests
    // Uses Date class validation and overloaded operators
    cout << "***  Date Tests  ***" << endl;
    displayResult("Date objects: ", Date(2, 31, 2017), Date(2, 31, 2017));
    displayResult("Date objects: ", Date(2, 13, 2017), Date(2, 14, 2017));
    displayResult("Date objects: ", Date(-2, 13, 2017), Date(2, 13, 2017));
    displayResult("Date objects: ", Date(-2, 13, 2017), Date(-2, 13, 2017));

    return 0;
}