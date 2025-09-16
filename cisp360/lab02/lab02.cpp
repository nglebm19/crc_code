#include <iostream>
using namespace std;

int main()
{
  int score1 = 92;
  int score2 = 83;
  int score3 = 67;

  double average = (score1 + score2 + score3) / 3.0;
  cout << "Avg. Score: " << average << endl;

  char grade;
  if (average >= 90)
  {
    grade = 'A';
  }
  else if (average >= 80)
  {
    grade = 'B';
  }
  else if (average >= 70)
  {
    grade = 'C';
  }
  else if (average >= 60)
  {
    grade = 'D';
  }
  else
  {
    grade = 'F';
  }

  cout << "Avg. Grade: " << grade << endl;

  return 0;
}
