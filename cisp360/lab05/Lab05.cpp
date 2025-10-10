// Your name here (NO NAME, NO CREDIT): Andrew Le

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int Max(int x1, int x2, int x3, int x4);
int DoubleNum(int value, int n);
bool IsOdd(int number);

string BoolConvert(bool val); // I wrote this as a helper method. DON'T DELETE!

int main() {
    // TESTS! DO NOT MODIFY!
    int m = Max(1, 2, 4, 3);
    cout << "The largest number of the group 1, 2, 4, 3 is: " << m << endl;
    int dn = DoubleNum(3, 3);
    cout << "The doubleNum result for 3, 3 is: " << dn << endl;
    bool b1 = IsOdd(16);
    bool b2 = IsOdd(7);
    cout << "The isOdd result for 16 is: " << BoolConvert(b1) << endl;
    cout << "The isOdd result for 7 is: " << BoolConvert(b2) << endl;
    // END OF TESTS! (Code below in the function bodies!)
}

int Max(int x1, int x2, int x3, int x4) {
	// TODO: Complete the  function to return the largest value below...
	int maxVal = x1;
	if (x2 > maxVal) maxVal = x2;
	if (x3 > maxVal) maxVal = x3;
	if (x4 > maxVal) maxVal = x4;
	return maxVal;
}

int DoubleNum(int value, int n) {
	// TODO: Complete the function to return the result below...
	for (int i = 0; i < n; i++) {
		value *= 2;
	}
	return value;

}

bool IsOdd(int number) {
	// TODO: Complete the function to return whether the number in the parameter is odd (true = 1) or even (false = 0) below...
	return (number % 2 != 0);
}

/* This is a helper method for my tests. DO NOT MODIFY! */
string BoolConvert(bool val) {
    if (val == 0)               return "false";
    return "true";
}