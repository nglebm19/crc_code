// V10A3.cpp
// Creating a GradeBook object and calling its member functions.
#include "GradeBook.h" // include definition of class GradeBook

int main()
{
   // create GradeBook object
   GradeBook myGradeBook( "CISP400 Object Oriented programming" );

   myGradeBook.displayMessage(); // display welcome message
   myGradeBook.inputGrades(); // read grades from user
   myGradeBook.displayGradeReport(); // display report based on grades
   system("PAUSE");
} // end main
