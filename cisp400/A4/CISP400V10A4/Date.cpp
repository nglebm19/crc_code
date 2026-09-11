// Name: Andrew Le
// Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr, Time t)
    : time(t) // initialize composed Time object
{
   if (mn > 0 && mn <= monthsPerYear) // validate the month
      month = mn;
   else
      throw invalid_argument("month must be 1-12");

   year = yr;          // could validate yr
   day = checkDay(dy); // validate the day

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date ";
   print();
   cout << endl;
} // end Date constructor

// print Date object in form month/day/year standard universal
void Date::print() const
{
   cout << month << '/' << day << '/' << year << "\t\t";
   time.printStandard();
   cout << "\t";
   time.printUniversal();
} // end function print

// output Date object to show when its destructor is called
Date::~Date()
{
   cout << "Date object destructor is called" << endl;
   print();
   cout << endl;
} // end ~Date destructor

// increase the date by one day, adjusting month and year as needed
void Date::increaseADay()
{
   static const array<int, monthsPerYear + 1> daysPerMonth =
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   int maxDay = daysPerMonth[month];
   if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
      maxDay = 29;

   ++day;
   if (day > static_cast<unsigned int>(maxDay))
   {
      cout << "day (" << day << ") set to 1." << endl;
      day = 1;
      ++month;
      if (month > monthsPerYear)
      {
         month = 1;
         ++year;
      } // end if month overflow
   } // end if day overflow
} // end function increaseADay

// increment time by one second; roll over into next minute/hour/day as needed
void Date::tick()
{
   unsigned int s = time.getSecond();
   unsigned int m = time.getMinute();
   unsigned int h = time.getHour();

   ++s;
   if (s >= 60)
   {
      s = 0;
      ++m;
      if (m >= 60)
      {
         m = 0;
         ++h;
         if (h >= 24)
         {
            h = 0;
            increaseADay(); // roll over into the next day
         } // end if hour overflow
      } // end if minute overflow
   } // end if second overflow

   time.setTime(h, m, s);
} // end function tick

// utility function to confirm proper day value based on
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
   static const array<int, monthsPerYear + 1> daysPerMonth =
       {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   // determine whether testDay is valid for specified month
   if (testDay > 0 && testDay <= daysPerMonth[month])
      return testDay;

   // February 29 check for leap year
   if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
      return testDay;

   throw invalid_argument("Invalid day for current month and year");
} // end function checkDay