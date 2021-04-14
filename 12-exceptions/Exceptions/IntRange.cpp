#include "IntRange.h"

IntRange::IntRange(int low, int high)
{
    mLower = low;
    mUpper = high;
}

ostream& operator<<(ostream& out, const IntRange& data)
{
    out << data.mValue;
    return out;
}

istream& operator>>(istream& in, IntRange& data)
{
    in >> data.mValue;
    if (data.mValue < data.mLower || data.mValue > data.mUpper)
    {
        throw IntRange::OutOfRange();
    }
    return in;
}