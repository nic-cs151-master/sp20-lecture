#include "opclass.h"

OpClass::OpClass()
{
    this->x = 0;
    this->y = 0;
}

OpClass::OpClass(int x)
{
    cout << "Convert constructor called\n";
    this->x = x;
    this->y = x;
}

OpClass::OpClass(int x, int y)
{
    this->x = x;
    this->y = y;
}

int OpClass::getX() const
{
    return x;
}

int OpClass::getY() const
{
    return y;
}

// OpClass OpClass::operator+(const OpClass &right)
// {
//     cout << "Operator+ triggered\n";
//     OpClass result;
//     result.x = this->x + right.x;
//     result.y = this->y + right.y;
//     return result;
// }

string OpClass::toString() const
{
    ostringstream ostr;
    ostr << "(" << x << ", " << y << ")";
    return ostr.str();
}

OpClass operator+(const OpClass &left, const OpClass &right)
{
    cout << "Friend Operator+ triggered\n";
    OpClass result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;
    return result;
}

ostream& operator<<(ostream &out, const OpClass &val)
{
    out << "(" << val.x << ", " << val.y << ")";
    return out;
}


istream& operator>>(istream &in, OpClass &val)
{
    while (1)
    {
        in >> val.x >> val.y;
        if (val.x >= 0 && val.x <= 10 && val.y >= 0 && val.y <= 10)
        {
            break;
        }
    }
    return in;
}