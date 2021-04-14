#include "IntRange3.h"

IntRange3::IntRange3(int low, int high)
{
    mLower = low;
    mUpper = high;
}

IntRange3::OutOfRange::OutOfRange(int i)
{
    mWhat = i;
}

int IntRange3::OutOfRange::what() const
{
    return mWhat;
}

ostream& operator<<(ostream& out, const IntRange3& data)
{
    out << data.mValue;
    return out;
}

istream& operator>>(istream& in, IntRange3& data)
{
    in >> data.mValue;
    if (data.mValue < data.mLower || data.mValue > data.mUpper)
    {
        throw IntRange3::OutOfRange(data.mValue);
    }
    return in;
}