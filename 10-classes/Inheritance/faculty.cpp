#include "faculty.h"

Faculty::Faculty(string name, Discipline d) : Person(name)
{
    cout << "Faculty constructur called\n";
    // mName = name;
    mDepartment = d;
    // setDepartment(d);
}

Faculty::~Faculty()
{
    cout << "Faculty destroyed\n";
}

void Faculty::setDepartment(Discipline d)
{
    mDepartment = d;
}

Discipline Faculty::getDepartment() const
{
    return mDepartment;
}