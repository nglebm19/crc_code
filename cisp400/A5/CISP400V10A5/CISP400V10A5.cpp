// Name: Andrew Le
// CISP400V10A5.cpp
// Purpose: Driver program to test the Complex class with all overloaded
//          operators: >>, <<, +, -, *, /, ==, !=, and =
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
     // Instantiate 6 Complex objects
     Complex x;
     Complex y(4.3, 8.2);
     Complex z(3.3, 1.1);
     Complex k;
     Complex l;
     Complex m(0, 0.1);

     // Use >> operator to read k from user input
     cin >> k;

     // Display all objects using << operator
     cout << "\nThe existing Complex objects are:\n";
     cout << "(Performing << operator overloading.)\n";
     cout << "x: " << x << "\ny: " << y << "\nz: " << z
          << "\nk: " << k << "\nl: " << l << "\nm: " << m << '\n';

     // Demonstrate + and = operators
     cout << "\nPerforming +, = and << operators overloading.\n";
     x = y + z;
     cout << "x = y + z:\n"
          << x << " = " << y << " + " << z << '\n';

     // Demonstrate - and = operators
     cout << "\nPerforming -, = and << operators overloading.\n";
     x = y - z;
     cout << "x = y - z:\n"
          << x << " = " << y << " - " << z << '\n';

     // Demonstrate * and = operators
     cout << "\nPerforming *, = and << operators overloading.\n";
     x = y * z;
     cout << "x = y * z:\n"
          << x << " = " << y << " * " << z << '\n';

     // Demonstrate / and = operators (normal division)
     cout << "\nPerforming /, = and << operators overloading.\n";
     x = y / z;
     cout << "x = y / z:\n"
          << x << " = " << y << " / " << z << '\n';

     // Demonstrate / with divide-by-zero (l is (0, 0))
     cout << "\nPerforming /, = and << operators overloading with divisor is " << l << ".\n";
     cout << "x = y / l:\n";
     x = y / l;
     cout << " = " << y << " / " << l << '\n';

     // Demonstrate / with near-zero divisor m(0, 0.1)
     cout << "\nPerforming /, = and << operators overloading with divisor is " << m << ".\n";
     x = y / m;
     cout << "x = y / m:\n"
          << x << " = " << y << " / " << m << '\n';

     // Demonstrate != operator
     cout << "\nPerforming != and << operators overloading.\n";
     cout << "check x != k\n";
     if (x != k) {
          cout << x << " != " << k << '\n';
     }

     // Demonstrate = and == operators
     cout << "\nPerforming =, == and << operators overloading.\n";
     cout << "assign k to x by using x=k statement.\n";
     x = k;
     cout << "check x == k\n";
     if (x == k)
          cout << x << " == " << k << '\n';

     return 0;
} // end main