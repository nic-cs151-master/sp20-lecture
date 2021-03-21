#include "person.h"

Person::Person()
{
    cout << "Person constructor called\n";
    mName = "";
    mAge = 0;
}

Person::Person(const string &name, int age)
{
    cout << "Person constructor called\n";
    setName(name);
    setAge(age);
}

Person::Person(const string &name)
{
    cout << "Person constructor called\n";
    setName(name);
    setAge(0);
}

Person::~Person()
{
    cout << "Person destroyed\n";
}

void Person::setName(const string &name)
{
    mName = name;
}

string Person::getName() const
{
    return mName;
}

void Person::setAge(int age)
{
    mAge = age;
}

int Person::getAge() const
{
    return mAge;
}