#ifndef OPCLASS_H
#define OPCLASS_H

#include <ostream>
using namespace std;

class OpClass
{
public:
    OpClass();       // default constructor
    OpClass(int x);  // convert constructor
    
    // OpClass operator+(OpClass right); // as a member function

    int getX() const;

    friend OpClass operator+(const OpClass &left, const OpClass &right); // standalone function (not part of OpClass)

private:
    int x;
};

#endif