// GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name, string instructor)
   : courseName( name ), instructorName( instructor ) // member initializer to initialize courseName
{                                                                      
   // empty body
   cout << "*Create a GradeBook Objects*" << endl;
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// set instructor name
void GradeBook::setInstructorName(string name) 
{
   instructorName = name;
} // end function setInstructorName

// get instructor name
string GradeBook::getInstructorName() const 
{
   return instructorName;
} // end function getInstructorName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
   cout << "Welcome to the grade book for\n" << getCourseName() 
      << "!" << endl;
   cout << "This course is presented by: " << getInstructorName() << endl;
} // end function displayMessage


