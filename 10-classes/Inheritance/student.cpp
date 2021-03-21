#include "student.h"

Student::Student(string name, int age, Discipline d, Faculty *f) 
    : Person(name, age)
{
    cout << "Student created\n";
    // mName = name;
    // setAge(age);
    mMajor = d;
    mAdvisor = f;
}

Student::~Student()
{
    cout << "Student destroyed\n";
}

void Student::setMajor(Discipline d)
{
    mMajor = d;
}

Discipline Student::getMajor() const
{
    return mMajor;
}

void Student::setAdvisor(Faculty *f)
{
    mAdvisor = f;
}

Faculty Student::getAdvisor()
{
    return *mAdvisor;
}
