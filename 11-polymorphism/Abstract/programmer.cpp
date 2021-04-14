#include "programmer.h"

Programmer::Programmer(string name, double salary, bool busPass)
    : Employee(name, salary), mBusPass(busPass)
{
    cout << "Programmer created\n";
}

Programmer::~Programmer()
{
    cout << "Programmer destroyed\n";
}

string Programmer::toString() const
{
    ostringstream ostr;

    ostr << "Name: " << *mName << '\n' 
         << "Salary: " << *mSalary << '\n'
         << "Has Bus Pass: " << mBusPass << '\n';
    
    return ostr.str();
}