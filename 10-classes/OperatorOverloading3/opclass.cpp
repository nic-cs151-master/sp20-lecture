#include "opclass.h"

OpClass::OpClass()
{
    x = 0;
}

OpClass::OpClass(int x)
{
    this->x = x;
}


int OpClass::getX() const
{
    return x;
}

// OpClass OpClass::operator+(OpClass right)
// {
//     OpClass result;
//     result.x = this->x + right.x;
//     return result;
// }

OpClass operator+(const OpClass &left, const OpClass &right)
{
    return OpClass(left.x + right.x);
}