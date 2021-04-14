#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Person
{
    friend ostream& operator<<(ostream& out, const Person& data);

public:
    Person(string name="", int age=0);
    ~Person();

private:
    string mName;
    int mAge;
};

#endif