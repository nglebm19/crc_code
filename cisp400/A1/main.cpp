#include <iostream>
using namespace std;

int main() {
  int number = 7;
  cout << (number == 7 ? "correct" : "incorrect") << endl;
  number == 7 ? cout << "correct" : cout << "incorrect";
  return 0;
}