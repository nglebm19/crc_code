// Name: Andrew Le

#include <iostream>
#include <string>
using namespace std;

#include <cmath>
void something(int a, int& b) {
  int c;
  c = a + 2;
  a = a*3;
  b=c+a;
}

int main()
{
  int r, s, t;
  r = 1;
  s = 2;
  t = 3;
  something(t, s);
  cout << r << " " << s << " " << t << "\n";
}