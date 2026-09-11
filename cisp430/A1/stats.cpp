// Name: Andrew Le
// File: stats.cpp
// Assignment: A1 - CISP 430
// Purpose: Implements the statistician class (see stats.h) which
//          tracks length, sum, mean, minimum, and maximum of a
//          sequence of real numbers.

#include "stats.h"
#include <cassert>
using namespace std;

namespace CISP430_A1
{
    // Constructor: Initialize an empty object
    statistician::statistician( )
    {
        count = 0;
        total = 0;
        // tiniest/largest not set here, no numbers yet
    }
    // Process the next number in the sequence 
    void statistician::next(double r)
    {
        if (count == 0)
        {
            tiniest = r;
            largest = r;
        }
        else
        {
            if (r < tiniest)
                tiniest = r;
            if (r > largest)
                largest = r;
        }
        total += r;
        count++;
    }

    // Reset the sequence back to empty
    void statistician::reset( )
    {
        count = 0;
        total = 0;
    }

    // Calculate mean of the sequence
    double statistician::mean( ) const
    {
        assert(length( ) > 0);
        return total / count;
    }

    // Get the smallest number of the sequence
    double statistician::minimum( ) const
    {
        assert(length( ) > 0);
        return tiniest;
    }

    // Get the largest number of the sequence
    double statistician::maximum( ) const
    {
        assert(length( ) > 0);
        return largest;
    }

    // Overload + operator to combine 2 statistician
    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician result;

        result.count = s1.count + s2.count;
        result.total = s1.total + s2.total;

        if (s1.count == 0)
        {
            result.tiniest = s2.tiniest;
            result.largest = s2.largest;
        }
        else if (s2.count == 0)
        {
            result.tiniest = s1.tiniest;
            result.largest = s1.largest;
        }
        else
        {
            result.tiniest = (s1.tiniest < s2.tiniest) ? s1.tiniest : s2.tiniest;
            result.largest = (s1.largest > s2.largest) ? s1.largest : s2.largest;
        }

        return result;
    }

    // Overload * operator to multifly a number to a statistician
    statistician operator *(double scale, const statistician& s)
    {
        statistician result;

        result.count = s.count;
        result.total = s.total * scale;

        if (s.count > 0)
        {
            if (scale >= 0)
            {
                result.tiniest = s.tiniest * scale;
                result.largest = s.largest * scale;
            }
            else
            {
                // negative scale flips min and max
                result.tiniest = s.largest * scale;
                result.largest = s.tiniest * scale;
            }
        }

        return result;
    }

    // Overload == operator to compare 2 statisticians
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if (s1.length( ) != s2.length( ))
            return false;

        if (s1.length( ) == 0)
            return true;

        return (
            (s1.sum( )     == s2.sum( ))     &&
            (s1.mean( )    == s2.mean( ))    &&
            (s1.minimum( ) == s2.minimum( )) &&
            (s1.maximum( ) == s2.maximum( ))
        );
    }
}