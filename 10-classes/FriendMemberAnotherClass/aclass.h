#ifndef FRIEND_H
#define FRIEND_H

#include "otherclass.h"

class AClass
{
public:
    int getX() const;
    
private:
    int x;
    friend void OtherClass::fSet(AClass& c, int a);
};

#endif