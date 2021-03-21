#ifndef FRCLASS_H
#define FRCLASS_H

#include "aclass.h"

class AClass;

class FrClass
{
public:
    void fSet(AClass& c, int a);
    int fGet(AClass c);
    void someFunction();
};

#endif