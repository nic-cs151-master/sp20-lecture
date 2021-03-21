#include "aclass.h"
#include "frclass.h"

void FrClass::fSet(AClass& c, int a)
{
    c.x = a;
}

int FrClass::fGet(AClass c)
{
    return c.x;
}