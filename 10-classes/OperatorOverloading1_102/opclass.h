#ifndef OPCLASS_H
#define OPCLASS_H

#include <iostream>
#include <sstream>
using namespace std;

class OpClass
{
    friend OpClass operator+(const OpClass &left, const OpClass &right);
    friend ostream& operator<<(ostream &out, const OpClass &val);
    friend istream& operator>>(istream &in, OpClass &val);

public:
    OpClass();              // default constructor
    OpClass(int x);         // programmer-defined constructor
    OpClass(int x, int y);  // programmer-defined constructor

    int getX() const;
    int getY() const;

    // OpClass operator+(const OpClass &right);

    string toString() const;

private:
    int x;
    int y;

};

#endif