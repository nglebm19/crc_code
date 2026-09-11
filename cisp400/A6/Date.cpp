// Name: Andrew Le
// File: Date.cpp
// Purpose: This file implements the Date class functions. It validates
//          month, day, and year values, compares Date objects, and
//          overloads the output operator to display dates in a readable
//          format.

#include "Date.h"
#include <string>

using namespace std;

// Constructor
// Initializes the Date object by calling setDate to validate the values
Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

// Check whether a year is a leap year
bool Date::leapYear(int y) const
{
    return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
}

// Returns the number of days in the specified month
int Date::daysInMonth(int m, int y) const
{
    switch (m)
    {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (leapYear(y))
            return 29; // February in leap year
        else
            return 28; // February in normal year
    default:
        return 31; // default fallback (should not normally occur)
    }
}

// Validates and assigns the month, day, and year values
// Invalid months are clamped to the range 1–12
// Invalid days are set to 1
void Date::setDate(int m, int d, int y)
{
    year = y;

    // Fix invalid month
    if (m < 1)
        month = 1;
    else if (m > 12)
        month = 12;
    else
        month = m;

    // Fix invalid day
    if (d < 1 || d > daysInMonth(month, year))
        day = 1;
    else
        day = d;
}

// Overloaded equality operator
// Returns true if two Date objects contain the same month, day, and year
bool Date::operator==(const Date& right) const
{
    return (month == right.month &&
            day == right.day &&
            year == right.year);
}

// Overloaded output operator
// Displays the date in the format: Month day, year
ostream& operator<<(ostream& output, const Date& d)
{
    static string monthName[13] = { "", "January", "February", "March",
                                    "April", "May", "June", "July",
                                    "August", "September", "October",
                                    "November", "December" };

    output << monthName[d.month] << " "
           << d.day << ", "
           << d.year;

    return output; // allows chaining of output operations
}