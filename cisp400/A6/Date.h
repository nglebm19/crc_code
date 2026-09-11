// Name: Andrew Le
// File: Date.h
// Purpose: This file defines the Date class. The class stores a month,
//          day, and year, validates date values, compares two Date
//          objects, and displays a date in month day, year format.


#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date
{
private:
    int month;
    int day;
    int year;

    bool leapYear(int y) const;
    int daysInMonth(int m, int y) const;
    void setDate(int m, int d, int y);

public:
    // Constructor
    Date(int m = 1, int d = 1, int y = 1900);

    // Equality operator
    bool operator==(const Date& right) const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& output, const Date& d);
};

#endif