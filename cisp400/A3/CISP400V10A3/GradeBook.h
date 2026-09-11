// Name: Andrew Le
// GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void initializeData(); // initialize private data members
   void displayMessage() const; // display a welcome message
   void inputGrades(); // input arbitrary number of grades from user
   void displayGradeReport() const;  // display report based on user input
   void displayInputs() const; // display the inputted information
   double calculateGrade() const; // calculate and return GPA
   ~GradeBook(); // destructor
private:
   std::string courseName; // course name for this GradeBook
   char letterGrades[100]; // stores all input characters
   int countGrades[6]; // counts: [A, B, C, D, F, errors]
}; // end class GradeBook