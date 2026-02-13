// Name: Andrew Le
// Assignment Number: A1
// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string, std::string); // constructor initialize courseName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message
   void setInstructorName(std::string); // set instructor name
   std::string getInstructorName() const; // get instructor name
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName; // instructor name for this GradeBook
}; // end class GradeBook  


