#ifndef OPCLASS_H
#define OPCLASS_H

#include <iostream>
#include <ostream>
using namespace std;

class OpClass
{
public:
    OpClass();                      // default constructor
    OpClass(int x);                 // programmer-defined constructor
    OpClass(int x, int y, int z);   // programmer-defined constructor
    OpClass(const OpClass &obj);    // copy constructor
    ~OpClass();                     // destructor

    int getX() const;
    int getY() const;
    int getZ() const;

    void setXYZ(int x, int y, int z);

    OpClass& operator=(const OpClass& r);

private:
    int x;
    int y;
    int *z;

    

};

#endif