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
#ifndef INTRANGE3_H
#define INTRANGE3_H

#include <iostream>

using std::istream;
using std::ostream;
using std::cout;

class IntRange3
{
    friend ostream& operator<<(ostream& out, const IntRange3& data);
    friend istream& operator>>(istream& in, IntRange3& data);

public:
    // Exception class
    class OutOfRange 
    { 
    public:
        OutOfRange(int i);
        int what() const;
    private:
        int mWhat;
    }; // Empty class declaration

    // Member functions
    IntRange3(int low=-100, int high=100);

private:
    int mValue;  // integer value
    int mLower;  // lower limit of range
    int mUpper;  // upper limit of range
};

#endif