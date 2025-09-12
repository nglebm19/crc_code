#include <iostream>
using namespace std;

int main()
{
  // Step 1: Declare and initialize variables
  int score1 = 92;
  int score2 = 83;
  int score3 = 67;

  // Step 2: Calculate the average
  double average = (score1 + score2 + score3) / 3.0;

  // Step 3: Determine the grade
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

  // Step 4: Output the grade
  cout << "Avg. Grade: " << grade << endl;

  return 0;
}
