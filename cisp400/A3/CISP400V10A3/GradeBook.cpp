// Name: Andrew Le
// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook(string name)
{
  cout << "\nThe Grade Book Constructor is called" << endl;
  initializeData();
  setCourseName(name);

  cout << "\nThe Grade Book, " << getCourseName() << ", contains" << endl;
  displayGradeReport();
  cout << "\n*****The end of Grade Book Constructor.*****\n"
      << endl;
} // end GradeBook constructor

// destructor cleans up memory and displays message
GradeBook::~GradeBook()
{
  cout << "\nDestructor is called" << endl;
  courseName = "";
  initializeData();
} // end GradeBook destructor

// function to set the course name; limits name to 30 or fewer characters
void GradeBook::setCourseName(string name)
{
  if (name.size() <= 30)
    courseName = name;
  else
  {
    courseName = name.substr(0, 30);
    cerr << "Name \"" << name << "\" exceeds maximum length (30).\n"
        << "Limiting courseName to first 30 characters.\n"
        << endl;
  }
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
  return courseName;
} // end function getCourseName

// initialize private data members to default values
void GradeBook::initializeData()
{
  for (int i = 0; i < 100; i++)
    letterGrades[i] = '\0';

  // countGrades[0]=A, [1]=B, [2]=C, [3]=D, [4]=F, [5]=errors
  for (int i = 0; i < 6; i++)
    countGrades[i] = 0;
} // end function initializeData

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
  cout << "\tWelcome to the grade book for\n\t" << getCourseName() << "!\n"
      << endl;
}// end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades()
{
  int grade;
  int totalInputs = 0;
  for (int i = 0; i < 6; i++)
    totalInputs += countGrades[i];

  cout << "\tEnter letter grades." << endl
      << "\t-->\tOr Enter the EOF character to end input." << endl
      << "\t(Use Ctl + D, or Ctl + Z)" << endl;

  // loop until user types end-of-file key sequence
  while (totalInputs < 100 && (grade = cin.get()) != EOF)
  {
    switch (grade)
    {
    case 'A':                          // grade was uppercase A
    case 'a':                          // or lowercase a
      letterGrades[totalInputs] = 'A'; // store as uppercase
      countGrades[0]++;                // increment A count
      totalInputs++;
      break; // necessary to exit switch

    case 'B':                          // grade was uppercase B
    case 'b':                          // or lowercase b
      letterGrades[totalInputs] = 'B'; // store as uppercase
      countGrades[1]++;                // increment B count
      totalInputs++;
      break; // exit switch

    case 'C':                          // grade was uppercase C
    case 'c':                          // or lowercase c
      letterGrades[totalInputs] = 'C'; // store as uppercase
      countGrades[2]++;                // increment C count
      totalInputs++;
      break; // exit switch

    case 'D':                          // grade was uppercase D
    case 'd':                          // or lowercase d
      letterGrades[totalInputs] = 'D'; // store as uppercase
      countGrades[3]++;                // increment D count
      totalInputs++;
      break; // exit switch

    case 'F':                          // grade was uppercase F
    case 'f':                          // or lowercase f
      letterGrades[totalInputs] = 'F'; // store as uppercase
      countGrades[4]++;                // increment F count
      totalInputs++;
      break; // exit switch

    case '\n': // ignore newlines,
    case '\t': // tabs,
    case ' ':  // and spaces in input
      break;   // exit switch

    default: // catch all other characters
      letterGrades[totalInputs] = static_cast<char>(grade); // store as-is
      countGrades[5]++;
      totalInputs++;
      cout << "\n\tXXXX An incorrect letter grade entered.  XXXX" << endl;
      cout << "\t \"" << static_cast<char>(grade) << "\" is not a proper letter grade.\n";
      break;
    } // end switch

    // re-prompt after each input (if not EOF)
    if (grade != '\n' && grade != '\t' && grade != ' ')
    {
      cout << "\n\tEnter letter grades." << endl;
      cout << "\t-->\tOr Enter the EOF character to end input." << endl;
      cout << "\t(Use Ctl + D, or Ctl + Z)" << endl;
    }
  } // end while

} // end function inputGrades

// display all inputted data in [index] -> grade format, 4 per row
void GradeBook::displayInputs() const
{
  // calculate total inputs from countGrades
  int totalInputs = 0;
  for (int i = 0; i < 6; i++)
    totalInputs += countGrades[i];

  cout << "\nThe data entered is listed at the following:" << endl;

  for (int i = 0; i < totalInputs; i++)
  {
    cout << "[" << i << "] -> " << letterGrades[i] << "\t";

    if ((i + 1) % 4 == 0) // 4 per row
      cout << endl;
  }
  if (totalInputs % 4 != 0)
    cout << endl;
} // end function displayInputs

// calculate and return GPA (Grade Point Average)
double GradeBook::calculateGrade() const
{
  int totalValidGrades = countGrades[0] + countGrades[1] +
                        countGrades[2] + countGrades[3] + countGrades[4];

  if (totalValidGrades == 0)
    return 0.0;

  // A=4, B=3, C=2, D=1, F=0
  double totalPoints = (countGrades[0] * 4.0) +
                       (countGrades[1] * 3.0) +
                       (countGrades[2] * 2.0) +
                       (countGrades[3] * 1.0) +
                       (countGrades[4] * 0.0);

  return totalPoints / totalValidGrades;
} // end function calculateGrade

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
  // calculate totals
  int totalInputs = 0;
  for (int i = 0; i < 6; i++)
    totalInputs += countGrades[i];
  int totalValidGrades = countGrades[0] + countGrades[1] +
                        countGrades[2] + countGrades[3] + countGrades[4];

  // output summary of results
  cout << "\nThe total number of data entered is " << totalInputs << endl;
  cout << "The total number of students receive grades is "
      << totalValidGrades << endl;

  cout << "Number of students who received each letter grade:"
       << "\nA:\t" << countGrades[0]     // display number of A grades
       << "\nB:\t" << countGrades[1]     // display number of B grades
       << "\nC:\t" << countGrades[2]     // display number of C grades
       << "\nD:\t" << countGrades[3]     // display number of D grades
       << "\nF:\t" << countGrades[4]     // display number of F grades
       << "\nError:\t" << countGrades[5] // display number of errors
      << endl;

  cout << "\nThe class average is: " << fixed << setprecision(1)
      << calculateGrade() << endl;
} // end function displayGradeReport