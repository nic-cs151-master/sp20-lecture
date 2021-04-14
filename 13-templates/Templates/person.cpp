#include "person.h"

Person::Person(string name, int age)
{
    mName = name;
    mAge = age;
}

Person::~Person() {}

ostream& operator<<(ostream& out, const Person& data)
{
    out << data.mName << ' ' << data.mAge;
    return out;
}