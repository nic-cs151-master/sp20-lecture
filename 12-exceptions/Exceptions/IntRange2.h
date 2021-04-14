/**
 * @file IntRange.h
 * @author Gabe de la Cruz
 * @brief The IntRange class allows you to create an integer
 *        that must be within a valid range specified in the
 *        class constructor.
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef INTRANGE2_H
#define INTRANGE2_H

#include <iostream>

using std::istream;
using std::ostream;
using std::cout;

class IntRange2
{
    friend ostream& operator<<(ostream& out, const IntRange2& data);
    friend istream& operator>>(istream& in, IntRange2& data);

public:
    // Exception class
    class TooLow { };
    class TooHigh { };

    // Member functions
    IntRange2(int low=-100, int high=100);

private:
    int mValue;  // integer value
    int mLower;  // lower limit of range
    int mUpper;  // upper limit of range
};

#endif