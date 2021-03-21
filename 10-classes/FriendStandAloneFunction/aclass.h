#ifndef FRIEND_H
#define FRIEND_H

class AClass
{
public:
    int getX() const;
    void setX(int x);

private:
    int x;
    friend void fSet(AClass& c, int a);
};

void fSetOrig(AClass& c, int a);

#endif