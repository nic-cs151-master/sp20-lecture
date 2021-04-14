#include "employee.h"


Employee::Employee(string n, double s)
{
    cout << "Employee created\n";
    mName = new string;
    *mName = n;
    mSalary = new double;
    *mSalary = s;
}

Employee::~Employee()
{
    cout << "Employee destroyed\n";
}

void Employee::setName(string data)
{
    *mName = data;
}

void Employee::setSalary(double data)
{
    *mSalary = data;
}

string Employee::getName() const
{
    return *mName;
}

double Employee::getSalary() const
{
    return *mSalary;
}
