#ifndef FACULTY_H
#define FACULTY_H

#include "person.h"
using namespace std;

class Faculty : public Person
{
public:
    Faculty(string name, Discipline d);
    virtual ~Faculty();
    
    void setDepartment(Discipline d);
    Discipline getDepartment() const;

private:
    Discipline mDepartment;
};

#endif