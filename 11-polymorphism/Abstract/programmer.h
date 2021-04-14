#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "employee.h"
#include <string>
#include <iostream>
#include <sstream>

using std::ostringstream;
using std::string;
using std::cout;

class Programmer : public Employee
{
public:
    Programmer(string name, double salary, bool busPass);
    virtual ~Programmer();
    virtual string toString() const;

private:
    bool mBusPass;

};

#endif