#ifndef FRIEND_H
#define FRIEND_H

#include "frclass.h"

class AClass
{
public:
    int getX() const;

private:
    int x;
    friend class FrClass;
};

#endif