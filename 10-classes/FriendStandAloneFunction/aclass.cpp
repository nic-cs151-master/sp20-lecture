#include "aclass.h"

int AClass::getX() const
{
    return this->x;
}

void AClass::setX(int x)
{
    this->x = x;
}

void fSetOrig(AClass& c, int a)
{
    c.setX(a);
}

void fSet(AClass& c, int a)
{
    c.x = a;
}
