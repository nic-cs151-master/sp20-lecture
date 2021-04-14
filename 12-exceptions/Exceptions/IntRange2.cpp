#include "IntRange2.h"

IntRange2::IntRange2(int low, int high)
{
    mLower = low;
    mUpper = high;
}

ostream& operator<<(ostream& out, const IntRange2& data)
{
    out << data.mValue;
    return out;
}

istream& operator>>(istream& in, IntRange2& data)
{
    in >> data.mValue;
    if (data.mValue < data.mLower)
    {
        throw IntRange2::TooLow();
    }
    else if (data.mValue > data.mUpper)
    {
        throw IntRange2::TooHigh();
    }
    return in;
}