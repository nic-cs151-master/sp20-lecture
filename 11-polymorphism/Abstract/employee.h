#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using std::cout;
using std::string;

class Employee
{
public:
    Employee(string n="", double s=0.);
    virtual ~Employee();
    void setName(string data);
    void setSalary(double data);
    string getName() const;
    double getSalary() const;

    // abstract function / pure virtual function
    virtual string toString() const = 0;

protected:
    string *mName;
    double *mSalary;
};

#endif