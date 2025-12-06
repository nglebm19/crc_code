// Your name here (NO NAME, NO POINTS!): Andrew Le

#include <iostream>
#include <string>
using namespace std;

/* Below is a silly class I wrote to aid you in learning how to use pre-existing classes in C++
2019 Matthew W. Phillips */

// Class Definitions Here...DO NOT MODIFY!
class FooClass {
	// Fields
private:
	int x;
	int y;

	// Constructor
public:
	FooClass(int, int);

	// Functions
public:
	int GetX();
	int GetY();
	string GetFooString();
	string IsFooEqual();
	void ChangeFoo(int, int);
};
// End Class Definitions.

int main() {
	// TODO: Do Coding Here...
	FooClass foo(10, 15);

	int xValue = foo.GetX();
	cout << "X: " << xValue << endl;

	int yValue = foo.GetY();
	cout << "Y: " << yValue << endl;

	string fooString = foo.GetFooString();
	cout << fooString << endl;

	string isFooEqual = foo.IsFooEqual();
	cout << "IsFooEqual: " << isFooEqual << endl;

	foo.ChangeFoo(27, 27);
	cout << "=== After Change ===" << endl;

	xValue = foo.GetX();
	cout << "X: " << xValue << endl;

	yValue = foo.GetY();
	cout << "Y: " << yValue << endl;

	fooString = foo.GetFooString();
	cout << fooString << endl;

	isFooEqual = foo.IsFooEqual();
	cout << "IsFooEqual: " << isFooEqual << endl;

	return 0;
	// End Coding
}

//////////////////////////// DO NOT MODIFY BELOW THIS LINE! ///////////////////////////////////////////////////
FooClass::FooClass(int _x, int _y) {
	x = _x;
	y = _y;
}

int FooClass::GetX() {
	return x;
}

int FooClass::GetY() {
	return y;
}

string FooClass::GetFooString() {
	string ret = "Foo x: " + std::to_string(x) + " , Foo y: " + std::to_string(y);
	return ret;
}

string FooClass::IsFooEqual() {
	bool b = (x == y);
	if (b == 0)			return "false";
	else				return "true";
}

void FooClass::ChangeFoo(int NewX, int NewY) {
	x = NewX;
	y = NewY;
}
