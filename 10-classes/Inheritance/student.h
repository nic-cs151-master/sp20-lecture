#ifndef STUDENT_H
#define STUDENT_H

#include "faculty.h"
#include "person.h"

class Student : public Person
{
public:
    Student(string name, int age, Discipline d, Faculty *f);
    virtual ~Student();
    void setMajor(Discipline d);
    Discipline getMajor() const;
    void setAdvisor(Faculty *f);
    Faculty getAdvisor();

private:
    Discipline mMajor;
    Faculty *mAdvisor; // Aggregation
};

#endif