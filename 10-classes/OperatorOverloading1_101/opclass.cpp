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

string OpClass::toString() const
{
    // (x, y)
    ostringstream ostr;
    ostr << "(" << this->x << ", " << this->y << ")";
    return ostr.str();
}

// OpClass OpClass::operator+(const OpClass &right)
// {
//     cout << "Member function called\n";
//     OpClass result;
//     result.x = this->x + right.x;
//     result.y = this->y + right.y;
//     return result;
// }

OpClass operator+(const OpClass &left, const OpClass &right)
{
    cout << "Friend function called\n";
    OpClass result;
    result.x = left.x + right.x;
    result.y = left.x + right.y;
    return result;
}

ostream& operator<<(ostream &out, const OpClass &obj)
{
    out << "(" << obj.x << ", " << obj.y << ")";
    return out;
}

istream& operator>>(istream &in, OpClass &obj)
{
    in >> obj.x >> obj.y;
    return in;
}